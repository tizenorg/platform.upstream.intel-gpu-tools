/*
 * Copyright © 2011 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *	Chris Wilson <chris@chris-wilson.co.uk>
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "intel_gpu_tools.h"

/* XXX PCH only today */

static uint32_t reg_read(uint32_t reg)
{
	return *(volatile uint32_t *)((volatile char*)mmio + reg);
}

static void reg_write(uint32_t reg, uint32_t val)
{
	*(volatile uint32_t *)((volatile char*)mmio + reg) = val;
}

int main(int argc, char** argv)
{
	uint32_t current, max;

	intel_get_mmio(intel_get_pci_device());

	current = reg_read(BLC_PWM_CPU_CTL) & BACKLIGHT_DUTY_CYCLE_MASK;
	max = reg_read(BLC_PWM_PCH_CTL2) >> 16;

	printf ("current backlight value: %d%%\n", current * 100 / max);

	if (argc > 1) {
		uint32_t v = atoi (argv[1]) * max / 100;
		if (v > max)
			v = max;
		reg_write(BLC_PWM_CPU_CTL,
			  (reg_read(BLC_PWM_CPU_CTL) &~ BACKLIGHT_DUTY_CYCLE_MASK) | v);
		(void) reg_read(BLC_PWM_CPU_CTL);
		printf ("set backlight to %d%%\n", v * 100 / max);
	}

	return 0;
}
