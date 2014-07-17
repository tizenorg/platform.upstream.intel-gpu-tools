/*
 * Copyright © 2008 Intel Corporation
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
 *    Eric Anholt <eric@anholt.net>
 *    Ben Widawsky <ben@bwidawsk.net>
 *
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#include <assert.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "intel_io.h"
#include "igt_debugfs.h"
#include "intel_chipset.h"

/**
 * SECTION:intel_io
 * @short_description: Register access and sideband I/O libraray
 * @title: intel io
 * @include: intel_io.h
 *
 * This library provides register I/O helpers in both a basic version and a more
 * fancy version which also handles forcewak and can optionally check registers
 * against a white-list. All register function are compatible. Hence the same
 * code can be used to decode registers with either of them, or also from a dump
 * file using intel_mmio_use_dump_file().
 *
 * Futhermore this library also provides helper functions for accessing the
 * various sideband interfaces found on Valleyview/Baytrail based platforms.
 */

#define FAKEKEY 0x2468ace0

/**
 * mmio:
 *
 * Pointer to the register range. It is not recommended to use this directly.
 */
void *mmio;

static struct _mmio_data {
	int inited;
	bool safe;
	uint32_t i915_devid;
	struct intel_register_map map;
	int key;
} mmio_data;

/**
 * intel_mmio_use_dump_file:
 * @file: name of the register dump file to open
 *
 * Sets up #mmio to point at the data contained in @file. This allows the same
 * code to get reused for dumping and decoding from running hardwared as from
 * register dumps.
 */
void
intel_mmio_use_dump_file(char *file)
{
	int fd;
	struct stat st;

	fd = open(file, O_RDWR);
	if (fd == -1) {
		    fprintf(stderr, "Couldn't open %s: %s\n", file,
			    strerror(errno));
		    exit(1);
	}
	fstat(fd, &st);
	mmio = mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (mmio == MAP_FAILED) {
		    fprintf(stderr, "Couldn't mmap %s: %s\n", file,
			    strerror(errno));
		    exit(1);
	}
	close(fd);
}

/**
 * intel_mmio_use_pci_bar:
 * @pci_dev: intel gracphis pci device
 *
 * Sets up #mmio to point at the data contained in @file. This allows the same
 * code to get reused for dumping and decoding from running hardwared as from
 * register dumps.
 *
 * @pci_dev can be obtained from intel_get_pci_device().
 */
void
intel_mmio_use_pci_bar(struct pci_device *pci_dev)
{
	uint32_t devid, gen;
	int mmio_bar, mmio_size;
	int error;

	devid = pci_dev->device_id;
	if (IS_GEN2(devid))
		mmio_bar = 1;
	else
		mmio_bar = 0;

	gen = intel_gen(devid);
	if (gen < 3)
		mmio_size = 512*1024;
	else if (gen < 5)
		mmio_size = 512*1024;
	else
		mmio_size = 2*1024*1024;

	error = pci_device_map_range (pci_dev,
				      pci_dev->regions[mmio_bar].base_addr,
				      mmio_size,
				      PCI_DEV_MAP_FLAG_WRITABLE,
				      &mmio);

	if (error != 0) {
		fprintf(stderr, "Couldn't map MMIO region: %s\n",
			strerror(error));
		exit(1);
	}
}

static void
release_forcewake_lock(int fd)
{
	close(fd);
}

/**
 * intel_register_access_init:
 * @pci_dev: intel gracphis pci device
 * @safe: use safe register access tables
 *
 * This initializes the new register access library, which supports forcewake
 * handling and also allows register access to be checked with an explicit
 * whitelist.
 *
 * It also initializes #mmio like intel_mmio_use_pci_bar().
 *
 * @pci_dev can be obtained from intel_get_pci_device().
 */
int
intel_register_access_init(struct pci_device *pci_dev, int safe)
{
	int ret;

	/* after old API is deprecated, remove this */
	if (mmio == NULL)
		intel_mmio_use_pci_bar(pci_dev);

	assert(mmio != NULL);

	if (mmio_data.inited)
		return -1;

	mmio_data.safe = (safe != 0 &&
			intel_gen(pci_dev->device_id) >= 4) ? true : false;
	mmio_data.i915_devid = pci_dev->device_id;
	if (mmio_data.safe)
		mmio_data.map = intel_get_register_map(mmio_data.i915_devid);

	/* Find where the forcewake lock is. Forcewake doesn't exist
	 * gen < 6, but the debugfs should do the right things for us.
	 */
	ret = igt_open_forcewake_handle();
	if (ret == -1)
		mmio_data.key = FAKEKEY;
	else
		mmio_data.key = ret;

	mmio_data.inited++;
	return 0;
}

static int
intel_register_access_needs_wake(void)
{
	return mmio_data.key != FAKEKEY;
}

/**
 * intel_register_access_needs_fakewake:
 *
 * Returns:
 * Non-zero when forcewake initialization failed.
 */
int intel_register_access_needs_fakewake(void)
{
	return mmio_data.key == FAKEKEY;
}

/**
 * intel_register_access_fini:
 *
 * Clean up the register access helper initialized with
 * intel_register_access_init().
 */
void
intel_register_access_fini(void)
{
	if (mmio_data.key && intel_register_access_needs_wake())
		release_forcewake_lock(mmio_data.key);
	mmio_data.inited--;
}

/**
 * intel_register_read:
 * @reg: register offset
 *
 * 32-bit read of the register at @offset. This function only works when the new
 * register access helper is initialized with intel_register_access_init().
 *
 * Compared to INREG() it can do optional checking with the register access
 * white lists.
 *
 * Returns:
 * The value read from the register.
 */
uint32_t
intel_register_read(uint32_t reg)
{
	struct intel_register_range *range;
	uint32_t ret;

	assert(mmio_data.inited);

	if (intel_gen(mmio_data.i915_devid) >= 6)
		assert(mmio_data.key != -1);

	if (!mmio_data.safe)
		goto read_out;

	range = intel_get_register_range(mmio_data.map,
					 reg,
					 INTEL_RANGE_READ);

	if(!range) {
		fprintf(stderr, "Register read blocked for safety "
			"(*0x%08x)\n", reg);
		ret = 0xffffffff;
		goto out;
	}

read_out:
	ret = *(volatile uint32_t *)((volatile char *)mmio + reg);
out:
	return ret;
}

/**
 * intel_register_write:
 * @reg: register offset
 * @val: value to write
 *
 * 32-bit write to the register at @offset. This function only works when the new
 * register access helper is initialized with intel_register_access_init().
 *
 * Compared to OUTRET() it can do optional checking with the register access
 * white lists.
 */
void
intel_register_write(uint32_t reg, uint32_t val)
{
	struct intel_register_range *range;

	assert(mmio_data.inited);

	if (intel_gen(mmio_data.i915_devid) >= 6)
		assert(mmio_data.key != -1);

	if (!mmio_data.safe)
		goto write_out;

	range = intel_get_register_range(mmio_data.map,
					 reg,
					 INTEL_RANGE_WRITE);

	if (!range) {
		fprintf(stderr, "Register write blocked for safety "
			"(*0x%08x = 0x%x)\n", reg, val);
	}

write_out:
	*(volatile uint32_t *)((volatile char *)mmio + reg) = val;
}


/**
 * INREG:
 * @reg: register offset
 *
 * 32-bit read of the register at @offset. This function only works when the new
 * register access helper is initialized with intel_register_access_init().
 *
 * This function directly accesses the #mmio without safety checks.
 *
 * Returns:
 * The value read from the register.
 */
uint32_t INREG(uint32_t reg)
{
	return *(volatile uint32_t *)((volatile char *)mmio + reg);
}

/**
 * OUTRET:
 * @reg: register offset
 * @val: value to write
 *
 * 32-bit write to the register at @offset. This function only works when the new
 * register access helper is initialized with intel_register_access_init().
 *
 * This function directly accesses the #mmio without safety checks.
 */
void OUTREG(uint32_t reg, uint32_t val)
{
	*(volatile uint32_t *)((volatile char *)mmio + reg) = val;
}
