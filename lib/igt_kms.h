/*
 * Copyright © 2013 Intel Corporation
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
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 * 	Daniel Vetter <daniel.vetter@ffwll.ch>
 * 	Damien Lespiau <damien.lespiau@intel.com>
 */

#ifndef __IGT_KMS_H__
#define __IGT_KMS_H__

#include <stdbool.h>
#include <stdint.h>

#include <xf86drmMode.h>

enum pipe {
        PIPE_A = 0,
        PIPE_B,
        PIPE_C,
        I915_MAX_PIPES
};
#define pipe_name(p) ((p) + 'A')

/* We namespace this enum to not conflict with the Android i915_drm.h */
enum igt_plane {
        IGT_PLANE_1 = 0,
        IGT_PLANE_PRIMARY = IGT_PLANE_1,
        IGT_PLANE_2,
        IGT_PLANE_3,
        IGT_PLANE_CURSOR,
};

const char *plane_name(enum igt_plane p);

#define sprite_name(p, s) ((p) * dev_priv->num_plane + (s) + 'A')

enum port {
        PORT_A = 0,
        PORT_B,
        PORT_C,
        PORT_D,
        PORT_E,
        I915_MAX_PORTS
};
#define port_name(p) ((p) + 'A')

#include "igt_fb.h"

struct kmstest_connector_config {
	drmModeCrtc *crtc;
	drmModeConnector *connector;
	drmModeEncoder *encoder;
	drmModeModeInfo default_mode;
	int crtc_idx;
	int pipe;
};

int kmstest_get_connector_default_mode(int drm_fd, drmModeConnector *connector,
				      drmModeModeInfo *mode);
int kmstest_get_connector_config(int drm_fd, uint32_t connector_id,
				 unsigned long crtc_idx_mask,
				 struct kmstest_connector_config *config);
void kmstest_free_connector_config(struct kmstest_connector_config *config);

void kmstest_dump_mode(drmModeModeInfo *mode);
int kmstest_get_pipe_from_crtc_id(int fd, int crtc_id);
const char *kmstest_pipe_str(int pipe);
const char *kmstest_encoder_type_str(int type);
const char *kmstest_connector_status_str(int type);
const char *kmstest_connector_type_str(int type);
void kmstest_set_connector_dpms(int fd, drmModeConnector *connector, int mode);

/*
 * A small modeset API
 */

typedef struct igt_display igt_display_t;
typedef struct igt_pipe igt_pipe_t;
typedef uint32_t igt_fixed_t;			/* 16.16 fixed point */

typedef struct {
	igt_pipe_t *pipe;
	int index;
	unsigned int is_primary       : 1;
	unsigned int is_cursor        : 1;
	unsigned int fb_changed       : 1;
	unsigned int position_changed : 1;
	/*
	 * drm_plane can be NULL for primary and cursor planes (when not
	 * using the atomic modeset API)
	 */
	drmModePlane *drm_plane;
	struct igt_fb *fb;
	/* position within pipe_src_w x pipe_src_h */
	int crtc_x, crtc_y;
} igt_plane_t;

struct igt_pipe {
	igt_display_t *display;
	enum pipe pipe;
	unsigned int need_set_crtc        : 1;
	unsigned int need_set_cursor      : 1;
	unsigned int need_wait_for_vblank : 1;
#define IGT_MAX_PLANES	4
	int n_planes;
	igt_plane_t planes[IGT_MAX_PLANES];
};

typedef struct {
	igt_display_t *display;
	uint32_t id;					/* KMS id */
	struct kmstest_connector_config config;
	char *name;
	bool valid;
	unsigned long pending_crtc_idx_mask;
} igt_output_t;

struct igt_display {
	int drm_fd;
	int log_shift;
	int n_pipes;
	int n_outputs;
	unsigned long pipes_in_use;
	igt_output_t *outputs;
	igt_pipe_t pipes[I915_MAX_PIPES];
};

/* set vt into graphics mode, required to prevent fbcon from interfering */
void igt_set_vt_graphics_mode(void);

void igt_display_init(igt_display_t *display, int drm_fd);
void igt_display_fini(igt_display_t *display);
int  igt_display_commit(igt_display_t *display);
int  igt_display_get_n_pipes(igt_display_t *display);

const char *igt_output_name(igt_output_t *output);
drmModeModeInfo *igt_output_get_mode(igt_output_t *output);
void igt_output_set_pipe(igt_output_t *output, enum pipe pipe);
igt_plane_t *igt_output_get_plane(igt_output_t *output, enum igt_plane plane);

void igt_plane_set_fb(igt_plane_t *plane, struct igt_fb *fb);
void igt_plane_set_position(igt_plane_t *plane, int x, int y);

void igt_wait_for_vblank(int drm_fd, enum pipe pipe);

#define for_each_connected_output(display, output)		\
	for (int i__ = 0;  i__ < (display)->n_outputs; i__++)	\
		if ((output = &(display)->outputs[i__]), output->valid)

/*
 * Can be used with igt_output_set_pipe() to mean we don't care about the pipe
 * that should drive this output
 */
#define PIPE_ANY	(-1)

#define IGT_FIXED(i,f)	((i) << 16 | (f))

#endif /* __IGT_KMS_H__ */

