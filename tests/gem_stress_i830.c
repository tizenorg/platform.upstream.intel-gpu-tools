#include "i830_reg.h"
#include "gem_stress.h"

#define TB0C_LAST_STAGE	(1 << 31)
#define TB0C_RESULT_SCALE_1X		(0 << 29)
#define TB0C_RESULT_SCALE_2X		(1 << 29)
#define TB0C_RESULT_SCALE_4X		(2 << 29)
#define TB0C_OP_MODULE			(3 << 25)
#define TB0C_OUTPUT_WRITE_CURRENT	(0 << 24)
#define TB0C_OUTPUT_WRITE_ACCUM		(1 << 24)
#define TB0C_ARG3_REPLICATE_ALPHA 	(1<<23)
#define TB0C_ARG3_INVERT		(1<<22)
#define TB0C_ARG3_SEL_XXX
#define TB0C_ARG2_REPLICATE_ALPHA 	(1<<17)
#define TB0C_ARG2_INVERT		(1<<16)
#define TB0C_ARG2_SEL_ONE		(0 << 12)
#define TB0C_ARG2_SEL_FACTOR		(1 << 12)
#define TB0C_ARG2_SEL_TEXEL0		(6 << 12)
#define TB0C_ARG2_SEL_TEXEL1		(7 << 12)
#define TB0C_ARG2_SEL_TEXEL2		(8 << 12)
#define TB0C_ARG2_SEL_TEXEL3		(9 << 12)
#define TB0C_ARG1_REPLICATE_ALPHA 	(1<<11)
#define TB0C_ARG1_INVERT		(1<<10)
#define TB0C_ARG1_SEL_ONE		(0 << 6)
#define TB0C_ARG1_SEL_TEXEL0		(6 << 6)
#define TB0C_ARG1_SEL_TEXEL1		(7 << 6)
#define TB0C_ARG1_SEL_TEXEL2		(8 << 6)
#define TB0C_ARG1_SEL_TEXEL3		(9 << 6)
#define TB0C_ARG0_REPLICATE_ALPHA 	(1<<5)
#define TB0C_ARG0_SEL_XXX

#define TB0A_CTR_STAGE_ENABLE 		(1<<31)
#define TB0A_RESULT_SCALE_1X		(0 << 29)
#define TB0A_RESULT_SCALE_2X		(1 << 29)
#define TB0A_RESULT_SCALE_4X		(2 << 29)
#define TB0A_OP_MODULE			(3 << 25)
#define TB0A_OUTPUT_WRITE_CURRENT	(0<<24)
#define TB0A_OUTPUT_WRITE_ACCUM		(1<<24)
#define TB0A_CTR_STAGE_SEL_BITS_XXX
#define TB0A_ARG3_SEL_XXX
#define TB0A_ARG3_INVERT		(1<<17)
#define TB0A_ARG2_INVERT		(1<<16)
#define TB0A_ARG2_SEL_ONE		(0 << 12)
#define TB0A_ARG2_SEL_TEXEL0		(6 << 12)
#define TB0A_ARG2_SEL_TEXEL1		(7 << 12)
#define TB0A_ARG2_SEL_TEXEL2		(8 << 12)
#define TB0A_ARG2_SEL_TEXEL3		(9 << 12)
#define TB0A_ARG1_INVERT		(1<<10)
#define TB0A_ARG1_SEL_ONE		(0 << 6)
#define TB0A_ARG1_SEL_TEXEL0		(6 << 6)
#define TB0A_ARG1_SEL_TEXEL1		(7 << 6)
#define TB0A_ARG1_SEL_TEXEL2		(8 << 6)
#define TB0A_ARG1_SEL_TEXEL3		(9 << 6)

void gen2_render_copyfunc(struct scratch_buf *src, unsigned src_x, unsigned src_y,
			  struct scratch_buf *dst, unsigned dst_x, unsigned dst_y,
			  unsigned logical_tile_no)
{
	static unsigned keep_gpu_busy_counter = 0;

	/* check both edges of the fence usage */
	if (keep_gpu_busy_counter & 1)
		keep_gpu_busy();

	/* invariant state */
	{
		OUT_BATCH(_3DSTATE_MAP_CUBE | MAP_UNIT(0));
		OUT_BATCH(_3DSTATE_MAP_CUBE | MAP_UNIT(1));
		OUT_BATCH(_3DSTATE_MAP_CUBE | MAP_UNIT(2));
		OUT_BATCH(_3DSTATE_MAP_CUBE | MAP_UNIT(3));

		OUT_BATCH(_3DSTATE_DFLT_DIFFUSE_CMD);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_DFLT_SPEC_CMD);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_DFLT_Z_CMD);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_FOG_MODE_CMD);
		OUT_BATCH(FOGFUNC_ENABLE |
			  FOG_LINEAR_CONST | FOGSRC_INDEX_Z | ENABLE_FOG_DENSITY);
		OUT_BATCH(0);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_MAP_TEX_STREAM_CMD |
			  MAP_UNIT(0) |
			  DISABLE_TEX_STREAM_BUMP |
			  ENABLE_TEX_STREAM_COORD_SET |
			  TEX_STREAM_COORD_SET(0) |
			  ENABLE_TEX_STREAM_MAP_IDX | TEX_STREAM_MAP_IDX(0));
		OUT_BATCH(_3DSTATE_MAP_TEX_STREAM_CMD |
			  MAP_UNIT(1) |
			  DISABLE_TEX_STREAM_BUMP |
			  ENABLE_TEX_STREAM_COORD_SET |
			  TEX_STREAM_COORD_SET(1) |
			  ENABLE_TEX_STREAM_MAP_IDX | TEX_STREAM_MAP_IDX(1));
		OUT_BATCH(_3DSTATE_MAP_TEX_STREAM_CMD |
			  MAP_UNIT(2) |
			  DISABLE_TEX_STREAM_BUMP |
			  ENABLE_TEX_STREAM_COORD_SET |
			  TEX_STREAM_COORD_SET(2) |
			  ENABLE_TEX_STREAM_MAP_IDX | TEX_STREAM_MAP_IDX(2));
		OUT_BATCH(_3DSTATE_MAP_TEX_STREAM_CMD |
			  MAP_UNIT(3) |
			  DISABLE_TEX_STREAM_BUMP |
			  ENABLE_TEX_STREAM_COORD_SET |
			  TEX_STREAM_COORD_SET(3) |
			  ENABLE_TEX_STREAM_MAP_IDX | TEX_STREAM_MAP_IDX(3));

		OUT_BATCH(_3DSTATE_MAP_COORD_TRANSFORM);
		OUT_BATCH(DISABLE_TEX_TRANSFORM | TEXTURE_SET(0));
		OUT_BATCH(_3DSTATE_MAP_COORD_TRANSFORM);
		OUT_BATCH(DISABLE_TEX_TRANSFORM | TEXTURE_SET(1));
		OUT_BATCH(_3DSTATE_MAP_COORD_TRANSFORM);
		OUT_BATCH(DISABLE_TEX_TRANSFORM | TEXTURE_SET(2));
		OUT_BATCH(_3DSTATE_MAP_COORD_TRANSFORM);
		OUT_BATCH(DISABLE_TEX_TRANSFORM | TEXTURE_SET(3));

		OUT_BATCH(_3DSTATE_RASTER_RULES_CMD |
			  ENABLE_POINT_RASTER_RULE |
			  OGL_POINT_RASTER_RULE |
			  ENABLE_LINE_STRIP_PROVOKE_VRTX |
			  ENABLE_TRI_FAN_PROVOKE_VRTX |
			  ENABLE_TRI_STRIP_PROVOKE_VRTX |
			  LINE_STRIP_PROVOKE_VRTX(1) |
			  TRI_FAN_PROVOKE_VRTX(2) | TRI_STRIP_PROVOKE_VRTX(2));

		OUT_BATCH(_3DSTATE_SCISSOR_ENABLE_CMD | DISABLE_SCISSOR_RECT);

		OUT_BATCH(_3DSTATE_SCISSOR_RECT_0_CMD);
		OUT_BATCH(0);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_VERTEX_TRANSFORM);
		OUT_BATCH(DISABLE_VIEWPORT_TRANSFORM | DISABLE_PERSPECTIVE_DIVIDE);

		OUT_BATCH(_3DSTATE_W_STATE_CMD);
		OUT_BATCH(MAGIC_W_STATE_DWORD1);
		OUT_BATCH(0x3f800000 /* 1.0 in IEEE float */ );

		OUT_BATCH(_3DSTATE_COLOR_FACTOR_CMD);
		OUT_BATCH(0x80808080);	/* .5 required in alpha for GL_DOT3_RGBA_EXT */

		OUT_BATCH(_3DSTATE_MAP_COORD_SETBIND_CMD);
		OUT_BATCH(TEXBIND_SET3(TEXCOORDSRC_VTXSET_3) |
			  TEXBIND_SET2(TEXCOORDSRC_VTXSET_2) |
			  TEXBIND_SET1(TEXCOORDSRC_VTXSET_1) |
			  TEXBIND_SET0(TEXCOORDSRC_VTXSET_0));

		/* copy from mesa */
		OUT_BATCH(_3DSTATE_FOG_COLOR_CMD |
			  FOG_COLOR_RED(0) | FOG_COLOR_GREEN(0) | FOG_COLOR_BLUE(0));

		OUT_BATCH(_3DSTATE_CONST_BLEND_COLOR_CMD);
		OUT_BATCH(0);

		OUT_BATCH(_3DSTATE_MODES_1_CMD |
			  ENABLE_COLR_BLND_FUNC |
			  BLENDFUNC_ADD |
			  ENABLE_SRC_BLND_FACTOR |
			  SRC_BLND_FACT(BLENDFACTOR_ONE) |
			  ENABLE_DST_BLND_FACTOR | DST_BLND_FACT(BLENDFACTOR_ZERO));
		OUT_BATCH(_3DSTATE_MODES_2_CMD | ENABLE_GLOBAL_DEPTH_BIAS | GLOBAL_DEPTH_BIAS(0) | ENABLE_ALPHA_TEST_FUNC | ALPHA_TEST_FUNC(0) |	/* always */
			  ALPHA_REF_VALUE(0));
		OUT_BATCH(_3DSTATE_MODES_3_CMD |
			  ENABLE_DEPTH_TEST_FUNC |
			  DEPTH_TEST_FUNC(0x2) |	/* COMPAREFUNC_LESS */
			  ENABLE_ALPHA_SHADE_MODE |
			  ALPHA_SHADE_MODE(SHADE_MODE_LINEAR) |
			  ENABLE_FOG_SHADE_MODE |
			  FOG_SHADE_MODE(SHADE_MODE_LINEAR) |
			  ENABLE_SPEC_SHADE_MODE |
			  SPEC_SHADE_MODE(SHADE_MODE_LINEAR) |
			  ENABLE_COLOR_SHADE_MODE |
			  COLOR_SHADE_MODE(SHADE_MODE_LINEAR) |
			  ENABLE_CULL_MODE | CULLMODE_NONE);

		OUT_BATCH(_3DSTATE_MODES_4_CMD |
			  ENABLE_LOGIC_OP_FUNC |
			  LOGIC_OP_FUNC(LOGICOP_COPY) |
			  ENABLE_STENCIL_TEST_MASK |
			  STENCIL_TEST_MASK(0xff) |
			  ENABLE_STENCIL_WRITE_MASK | STENCIL_WRITE_MASK(0xff));

		OUT_BATCH(_3DSTATE_STENCIL_TEST_CMD |
			  ENABLE_STENCIL_PARMS |
			  STENCIL_FAIL_OP(0) |	/* STENCILOP_KEEP */
			  STENCIL_PASS_DEPTH_FAIL_OP(0) |	/* STENCILOP_KEEP */
			  STENCIL_PASS_DEPTH_PASS_OP(0) |	/* STENCILOP_KEEP */
			  ENABLE_STENCIL_TEST_FUNC |
			  STENCIL_TEST_FUNC(0) |	/* COMPAREFUNC_ALWAYS */
			  ENABLE_STENCIL_REF_VALUE |
			  STENCIL_REF_VALUE(0));

		OUT_BATCH(_3DSTATE_MODES_5_CMD |
			  FLUSH_TEXTURE_CACHE |
			  ENABLE_SPRITE_POINT_TEX | SPRITE_POINT_TEX_OFF |
			  ENABLE_FIXED_LINE_WIDTH | FIXED_LINE_WIDTH(0x2) | /* 1.0 */
			  ENABLE_FIXED_POINT_WIDTH | FIXED_POINT_WIDTH(1));

		OUT_BATCH(_3DSTATE_STIPPLE);

		/* Set default blend state */
		OUT_BATCH(_3DSTATE_MAP_BLEND_OP_CMD(0) |
			  TEXPIPE_COLOR |
			  ENABLE_TEXOUTPUT_WRT_SEL |
			  TEXOP_OUTPUT_CURRENT |
			  DISABLE_TEX_CNTRL_STAGE |
			  TEXOP_SCALE_1X |
			  TEXOP_MODIFY_PARMS | TEXOP_LAST_STAGE | TEXBLENDOP_ARG1);
		OUT_BATCH(_3DSTATE_MAP_BLEND_OP_CMD(0) |
			  TEXPIPE_ALPHA |
			  ENABLE_TEXOUTPUT_WRT_SEL |
			  TEXOP_OUTPUT_CURRENT |
			  TEXOP_SCALE_1X | TEXOP_MODIFY_PARMS | TEXBLENDOP_ARG1);
		OUT_BATCH(_3DSTATE_MAP_BLEND_ARG_CMD(0) |
			  TEXPIPE_COLOR |
			  TEXBLEND_ARG1 |
			  TEXBLENDARG_MODIFY_PARMS | TEXBLENDARG_DIFFUSE);
		OUT_BATCH(_3DSTATE_MAP_BLEND_ARG_CMD(0) |
			  TEXPIPE_ALPHA |
			  TEXBLEND_ARG1 |
			  TEXBLENDARG_MODIFY_PARMS | TEXBLENDARG_DIFFUSE);

		OUT_BATCH(_3DSTATE_AA_CMD |
			  AA_LINE_ECAAR_WIDTH_ENABLE |
			  AA_LINE_ECAAR_WIDTH_1_0 |
			  AA_LINE_REGION_WIDTH_ENABLE |
			  AA_LINE_REGION_WIDTH_1_0 | AA_LINE_DISABLE);
	}

	/* render target state */
	{
		uint32_t tiling_bits = 0;
		if (dst->tiling != I915_TILING_NONE)
			tiling_bits = BUF_3D_TILED_SURFACE;
		if (dst->tiling == I915_TILING_Y)
			tiling_bits |= BUF_3D_TILE_WALK_Y;

		OUT_BATCH(_3DSTATE_BUF_INFO_CMD);
		OUT_BATCH(BUF_3D_ID_COLOR_BACK | tiling_bits |
			  BUF_3D_PITCH(dst->stride));
		OUT_RELOC(dst->bo, I915_GEM_DOMAIN_RENDER, I915_GEM_DOMAIN_RENDER, 0);

		OUT_BATCH(_3DSTATE_DST_BUF_VARS_CMD);
		OUT_BATCH(COLR_BUF_ARGB8888 |
			  DSTORG_HORT_BIAS(0x8) |
			  DSTORG_VERT_BIAS(0x8));

		OUT_BATCH(_3DSTATE_DRAW_RECT_CMD);
		OUT_BATCH(0);
		OUT_BATCH(0);		/* ymin, xmin */
		OUT_BATCH(DRAW_YMAX(buf_height(dst) - 1) |
			  DRAW_XMAX(buf_width(dst) - 1));
		OUT_BATCH(0);		/* yorig, xorig */
	}

	/* dynamic state */
	{
		OUT_BATCH(_3DSTATE_LOAD_STATE_IMMEDIATE_1 |
			  I1_LOAD_S(2) | I1_LOAD_S(3) | I1_LOAD_S(8) | 2);
		OUT_BATCH(1);		/* number of coordinate sets */
		OUT_BATCH(S3_CULLMODE_NONE | S3_VERTEXHAS_XY);
		OUT_BATCH(S8_ENABLE_COLOR_BLEND | S8_BLENDFUNC_ADD |
			  BLENDFACTOR_ONE << S8_SRC_BLEND_FACTOR_SHIFT |
			  BLENDFACTOR_ZERO << S8_DST_BLEND_FACTOR_SHIFT |
			  S8_ENABLE_COLOR_BUFFER_WRITE);

		OUT_BATCH(_3DSTATE_INDPT_ALPHA_BLEND_CMD | DISABLE_INDPT_ALPHA_BLEND);

		OUT_BATCH(_3DSTATE_LOAD_STATE_IMMEDIATE_2 |
			  LOAD_TEXTURE_BLEND_STAGE(0) | 1);
		OUT_BATCH(TB0C_LAST_STAGE | TB0C_RESULT_SCALE_1X | TB0C_OP_MODULE |
			  TB0C_OUTPUT_WRITE_CURRENT | TB0C_ARG1_SEL_TEXEL0 |
			  TB0C_ARG2_SEL_ONE);
		OUT_BATCH(TB0A_RESULT_SCALE_1X | TB0A_OP_MODULE |
			  TB0A_OUTPUT_WRITE_CURRENT | TB0A_ARG1_SEL_TEXEL0 |
			  TB0A_ARG2_SEL_ONE);

		OUT_BATCH(_3DSTATE_ENABLES_1_CMD | DISABLE_LOGIC_OP |
			  DISABLE_STENCIL_TEST | DISABLE_DEPTH_BIAS |
			  DISABLE_SPEC_ADD | DISABLE_FOG | DISABLE_ALPHA_TEST |
			  ENABLE_COLOR_BLEND | DISABLE_DEPTH_TEST);
		/* We have to explicitly say we don't want write disabled */
		OUT_BATCH(_3DSTATE_ENABLES_2_CMD | ENABLE_COLOR_MASK |
			  DISABLE_STENCIL_WRITE | ENABLE_TEX_CACHE |
			  DISABLE_DITHER | ENABLE_COLOR_WRITE | DISABLE_DEPTH_WRITE);

		OUT_BATCH(_3DSTATE_VERTEX_FORMAT_2_CMD |
			  TEXCOORDFMT_2D << 0);
	}

	/* sampler state */
	{
		uint32_t tiling_bits = 0;
		if (src->tiling != I915_TILING_NONE)
			tiling_bits = TM0S1_TILED_SURFACE;
		if (src->tiling == I915_TILING_Y)
			tiling_bits |= TM0S1_TILE_WALK;

		OUT_BATCH(_3DSTATE_LOAD_STATE_IMMEDIATE_2 |
			  LOAD_TEXTURE_MAP(0) | 4);
		OUT_RELOC(src->bo, I915_GEM_DOMAIN_SAMPLER, 0, 0);
		OUT_BATCH((buf_height(src) - 1) << TM0S1_HEIGHT_SHIFT |
			  (buf_width(src) - 1) << TM0S1_WIDTH_SHIFT |
			  MAPSURF_32BIT | MT_32BIT_ARGB8888 | tiling_bits);
		OUT_BATCH((src->stride / 4 - 1) << TM0S2_PITCH_SHIFT | TM0S2_MAP_2D);
		OUT_BATCH(FILTER_NEAREST << TM0S3_MAG_FILTER_SHIFT |
			  FILTER_NEAREST << TM0S3_MIN_FILTER_SHIFT |
			  MIPFILTER_NONE << TM0S3_MIP_FILTER_SHIFT);
		OUT_BATCH(0);	/* default color */
		OUT_BATCH(_3DSTATE_MAP_COORD_SET_CMD | TEXCOORD_SET(0) |
			  ENABLE_TEXCOORD_PARAMS | TEXCOORDS_ARE_NORMAL |
			  TEXCOORDTYPE_CARTESIAN |
			  ENABLE_ADDR_V_CNTL | TEXCOORD_ADDR_V_MODE(TEXCOORDMODE_CLAMP_BORDER) |
			  ENABLE_ADDR_U_CNTL | TEXCOORD_ADDR_U_MODE(TEXCOORDMODE_CLAMP_BORDER));
		/* map texel stream */
		OUT_BATCH(_3DSTATE_MAP_COORD_SETBIND_CMD);
		OUT_BATCH(TEXBIND_SET0(TEXCOORDSRC_VTXSET_0) |
			  TEXBIND_SET1(TEXCOORDSRC_KEEP) |
			  TEXBIND_SET2(TEXCOORDSRC_KEEP) |
			  TEXBIND_SET3(TEXCOORDSRC_KEEP));
		OUT_BATCH(_3DSTATE_MAP_TEX_STREAM_CMD | (0 << 16) |
			  DISABLE_TEX_STREAM_BUMP |
			  ENABLE_TEX_STREAM_COORD_SET |
			  TEX_STREAM_COORD_SET(0) |
			  ENABLE_TEX_STREAM_MAP_IDX | TEX_STREAM_MAP_IDX(0));
	}

	OUT_BATCH(PRIM3D_INLINE | PRIM3D_RECTLIST | (3*4 -1));
	emit_vertex(dst_x + options.tile_size);
	emit_vertex(dst_y + options.tile_size);
	emit_vertex_normalized(src_x + options.tile_size, buf_width(src));
	emit_vertex_normalized(src_y + options.tile_size, buf_height(src));

	emit_vertex(dst_x);
	emit_vertex(dst_y + options.tile_size);
	emit_vertex_normalized(src_x, buf_width(src));
	emit_vertex_normalized(src_y + options.tile_size, buf_height(src));

	emit_vertex(dst_x);
	emit_vertex(dst_y);
	emit_vertex_normalized(src_x, buf_width(src));
	emit_vertex_normalized(src_y, buf_height(src));

	if (!(keep_gpu_busy_counter & 1))
		keep_gpu_busy();

	keep_gpu_busy_counter++;

	intel_batchbuffer_flush(batch);
}
