/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "gram.y"

/*
 * Copyright © 2006 Intel Corporation
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
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Eric Anholt <eric@anholt.net>
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include "gen4asm.h"
#include "brw_eu.h"
#include "gen8_instruction.h"

#define DEFAULT_EXECSIZE (ffs(program_defaults.execute_size) - 1)
#define DEFAULT_DSTREGION -1

#define SWIZZLE(reg) (reg.dw1.bits.swizzle)

#define GEN(i)	(&(i)->insn.gen)
#define GEN8(i)	(&(i)->insn.gen8)

#define YYLTYPE YYLTYPE
typedef struct YYLTYPE
{
 int first_line;
 int first_column;
 int last_line;
 int last_column;
} YYLTYPE;

extern int need_export;
static struct src_operand src_null_reg =
{
    .reg.file = BRW_ARCHITECTURE_REGISTER_FILE,
    .reg.nr = BRW_ARF_NULL,
    .reg.type = BRW_REGISTER_TYPE_UD,
};
static struct brw_reg dst_null_reg =
{
    .file = BRW_ARCHITECTURE_REGISTER_FILE,
    .nr = BRW_ARF_NULL,
};
static struct brw_reg ip_dst =
{
    .file = BRW_ARCHITECTURE_REGISTER_FILE,
    .nr = BRW_ARF_IP,
    .type = BRW_REGISTER_TYPE_UD,
    .address_mode = BRW_ADDRESS_DIRECT,
    .hstride = 1,
    .dw1.bits.writemask = BRW_WRITEMASK_XYZW,
};
static struct src_operand ip_src =
{
    .reg.file = BRW_ARCHITECTURE_REGISTER_FILE,
    .reg.nr = BRW_ARF_IP,
    .reg.type = BRW_REGISTER_TYPE_UD,
    .reg.address_mode = BRW_ADDRESS_DIRECT,
    .reg.dw1.bits.swizzle = BRW_SWIZZLE_NOOP,
};

static int get_type_size(unsigned type);
static void set_instruction_opcode(struct brw_program_instruction *instr,
				   unsigned opcode);
static int set_instruction_dest(struct brw_program_instruction *instr,
				struct brw_reg *dest);
static int set_instruction_src0(struct brw_program_instruction *instr,
				struct src_operand *src,
				YYLTYPE *location);
static int set_instruction_src1(struct brw_program_instruction *instr,
				struct src_operand *src,
				YYLTYPE *location);
static int set_instruction_dest_three_src(struct brw_program_instruction *instr,
					  struct brw_reg *dest);
static int set_instruction_src0_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src);
static int set_instruction_src1_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src);
static int set_instruction_src2_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src);
static void set_instruction_saturate(struct brw_program_instruction *instr,
				     int saturate);
static void set_instruction_options(struct brw_program_instruction *instr,
				    struct options options);
static void set_instruction_predicate(struct brw_program_instruction *instr,
				      struct predicate *p);
static void set_instruction_pred_cond(struct brw_program_instruction *instr,
				      struct predicate *p,
				      struct condition *c,
				      YYLTYPE *location);
static void set_direct_dst_operand(struct brw_reg *dst, struct brw_reg *reg,
				   int type);
static void set_direct_src_operand(struct src_operand *src, struct brw_reg *reg,
				   int type);

void set_branch_two_offsets(struct brw_program_instruction *insn, int jip_offset, int uip_offset);
void set_branch_one_offset(struct brw_program_instruction *insn, int jip_offset);

enum message_level {
    WARN,
    ERROR,
};

static void message(enum message_level level, YYLTYPE *location,
		    const char *fmt, ...)
{
    static const char *level_str[] = { "warning", "error" };
    va_list args;

    if (location)
	fprintf(stderr, "%s:%d:%d: %s: ", input_filename, location->first_line,
		location->first_column, level_str[level]);
    else
	fprintf(stderr, "%s:%s: ", input_filename, level_str[level]);

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

#define warn(flag, l, fmt, ...)					\
    do {							\
	if (warning_flags & WARN_ ## flag)			\
	    message(WARN, l, fmt, ## __VA_ARGS__);	\
    } while(0)

#define error(l, fmt, ...)			\
    do {					\
	message(ERROR, l, fmt, ## __VA_ARGS__);	\
    } while(0)

/* like strcmp, but handles NULL pointers */
static bool strcmp0(const char *s1, const char* s2)
{
    if (!s1)
	return -(s1 != s2);
    if (!s2)
	return s1 != s2;
    return strcmp (s1, s2);
}

static bool region_equal(struct region *r1, struct region *r2)
{
    return memcmp(r1, r2, sizeof(struct region)) == 0;
}

static bool reg_equal(struct brw_reg *r1, struct brw_reg *r2)
{
    return memcmp(r1, r2, sizeof(struct brw_reg)) == 0;
}

static bool declared_register_equal(struct declared_register *r1,
				     struct declared_register *r2)
{
    if (strcmp0(r1->name, r2->name) != 0)
	return false;

    if (!reg_equal(&r1->reg, &r2->reg))
	return false;

    if (!region_equal(&r1->src_region, &r2->src_region))
	return false;

    if (r1->element_size != r2->element_size ||
        r1->dst_region != r2->dst_region)
	return false;

    return true;
}

static void brw_program_init(struct brw_program *p)
{
   memset(p, 0, sizeof(struct brw_program));
}

static void brw_program_append_entry(struct brw_program *p,
				     struct brw_program_instruction *entry)
{
    entry->next = NULL;
    if (p->last)
	p->last->next = entry;
    else
	p->first = entry;
    p->last = entry;
}

static void
brw_program_add_instruction(struct brw_program *p,
			    struct brw_program_instruction *instruction)
{
    struct brw_program_instruction *list_entry;

    list_entry = calloc(sizeof(struct brw_program_instruction), 1);
    list_entry->type = GEN4ASM_INSTRUCTION_GEN;
    list_entry->insn.gen = instruction->insn.gen;
    brw_program_append_entry(p, list_entry);
}

static void
brw_program_add_relocatable(struct brw_program *p,
			    struct brw_program_instruction *instruction)
{
    struct brw_program_instruction *list_entry;

    list_entry = calloc(sizeof(struct brw_program_instruction), 1);
    list_entry->type = GEN4ASM_INSTRUCTION_GEN_RELOCATABLE;
    list_entry->insn.gen = instruction->insn.gen;
    list_entry->reloc = instruction->reloc;
    brw_program_append_entry(p, list_entry);
}

static void brw_program_add_label(struct brw_program *p, const char *label)
{
    struct brw_program_instruction *list_entry;

    list_entry = calloc(sizeof(struct brw_program_instruction), 1);
    list_entry->type = GEN4ASM_INSTRUCTION_LABEL;
    list_entry->insn.label.name = strdup(label);
    brw_program_append_entry(p, list_entry);
}

static int resolve_dst_region(struct declared_register *reference, int region)
{
    int resolved = region;

    if (resolved == DEFAULT_DSTREGION) {
	if (reference)
	    resolved = reference->dst_region;
        else
            resolved = 1;
    }

    assert(resolved == 1 || resolved == 2 || resolved == 3);
    return resolved;
}

static inline int access_mode(struct brw_program_instruction *insn)
{
    if (IS_GENp(8))
	return gen8_access_mode(GEN8(insn));
    else
	return GEN(insn)->header.access_mode;
}

static inline int exec_size(struct brw_program_instruction *insn)
{
    if (IS_GENp(8))
	return gen8_exec_size(GEN8(insn));
    else
	return GEN(insn)->header.execution_size;
}

static void set_execsize(struct brw_program_instruction *insn, int execsize)
{
    if (IS_GENp(8))
	gen8_set_exec_size(GEN8(insn), execsize);
    else
	GEN(insn)->header.execution_size = execsize;
}

static bool validate_dst_reg(struct brw_program_instruction *insn, struct brw_reg *reg)
{

    if (reg->address_mode == BRW_ADDRESS_DIRECT &&
	access_mode(insn) == BRW_ALIGN_1 &&
	reg->dw1.bits.writemask != 0 &&
	reg->dw1.bits.writemask != BRW_WRITEMASK_XYZW)
    {
	fprintf(stderr, "error: write mask set in align1 instruction\n");
	return false;
    }

    if (reg->address_mode == BRW_ADDRESS_REGISTER_INDIRECT_REGISTER &&
	access_mode(insn) == BRW_ALIGN_16) {
	fprintf(stderr, "error: indirect Dst addr mode in align16 instruction\n");
	return false;
    }

    return true;
}

static bool validate_src_reg(struct brw_program_instruction *insn,
			     struct brw_reg reg,
			     YYLTYPE *location)
{
    int hstride_for_reg[] = {0, 1, 2, 4};
    int vstride_for_reg[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};
    int width_for_reg[] = {1, 2, 4, 8, 16};
    int execsize_for_reg[] = {1, 2, 4, 8, 16, 32};
    int width, hstride, vstride, execsize;

    if (reg.file == BRW_IMMEDIATE_VALUE)
	return true;

    if (access_mode(insn) == BRW_ALIGN_1 &&
	SWIZZLE(reg) && SWIZZLE(reg) != BRW_SWIZZLE_NOOP)
    {
	error(location, "swizzle bits set in align1 instruction\n");
	return false;
    }

    if (reg.address_mode == BRW_ADDRESS_REGISTER_INDIRECT_REGISTER &&
	access_mode(insn) == BRW_ALIGN_16) {
	fprintf(stderr, "error: indirect Source addr mode in align16 instruction\n");
	return false;
    }

    assert(reg.hstride >= 0 && reg.hstride < ARRAY_SIZE(hstride_for_reg));
    hstride = hstride_for_reg[reg.hstride];

    if (reg.vstride == 0xf) {
	vstride = -1;
    } else {
	assert(reg.vstride >= 0 && reg.vstride < ARRAY_SIZE(vstride_for_reg));
	vstride = vstride_for_reg[reg.vstride];
    }

    assert(reg.width >= 0 && reg.width < ARRAY_SIZE(width_for_reg));
    width = width_for_reg[reg.width];

    assert(exec_size(insn) >= 0 &&
	   exec_size(insn) < ARRAY_SIZE(execsize_for_reg));
    execsize = execsize_for_reg[exec_size(insn)];

    /* Register Region Restrictions */

    /* B. If ExecSize = Width and HorzStride ≠ 0, VertStride must be set to
     * Width * HorzStride. */
    if (execsize == width && hstride != 0) {
	if (vstride != -1 && vstride != width * hstride)
	    warn(ALL, location, "execution size == width and hstride != 0 but "
		 "vstride is not width * hstride\n");
    }

    /* D. If Width = 1, HorzStride must be 0 regardless of the values of
     * ExecSize and VertStride.
     *
     * FIXME: In "advanced mode" hstride is set to 1, this is probably a bug
     * to fix, but it changes the generated opcodes and thus needs validation.
     */
    if (width == 1 && hstride != 0)
	warn(ALL, location, "region width is 1 but horizontal stride is %d "
	     " (should be 0)\n", hstride);

    /* E. If ExecSize = Width = 1, both VertStride and HorzStride must be 0.
     * This defines a scalar. */
    if (execsize == 1 && width == 1) {
        if (hstride != 0)
	    warn(ALL, location, "execution size and region width are 1 but "
		 "horizontal stride is %d (should be 0)\n", hstride);
        if (vstride != 0)
	    warn(ALL, location, "execution size and region width are 1 but "
		 "vertical stride is %d (should be 0)\n", vstride);
    }

    return true;
}

static int get_subreg_address(unsigned regfile, unsigned type, unsigned subreg, unsigned address_mode)
{
    int unit_size = 1;

    assert(address_mode == BRW_ADDRESS_DIRECT);
    assert(regfile != BRW_IMMEDIATE_VALUE);

    if (advanced_flag)
	unit_size = get_type_size(type);

    return subreg * unit_size;
}

/* only used in indirect address mode.
 * input: sub-register number of an address register
 * output: the value of AddrSubRegNum in the instruction binary code
 *
 * input  output(advanced_flag==0)  output(advanced_flag==1)
 *  a0.0             0                         0
 *  a0.1        invalid input                  1
 *  a0.2             1                         2
 *  a0.3        invalid input                  3
 *  a0.4             2                         4
 *  a0.5        invalid input                  5
 *  a0.6             3                         6
 *  a0.7        invalid input                  7
 *  a0.8             4                  invalid input
 *  a0.10            5                  invalid input
 *  a0.12            6                  invalid input
 *  a0.14            7                  invalid input
 */
static int get_indirect_subreg_address(unsigned subreg)
{
    return advanced_flag == 0 ? subreg / 2 : subreg;
}

static void resolve_subnr(struct brw_reg *reg)
{
   if (reg->file == BRW_IMMEDIATE_VALUE)
	return;

   if (reg->address_mode == BRW_ADDRESS_DIRECT)
	reg->subnr = get_subreg_address(reg->file, reg->type, reg->subnr,
					reg->address_mode);
   else
        reg->subnr = get_indirect_subreg_address(reg->subnr);
}



/* Line 371 of yacc.c  */
#line 501 "gram.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_GRAM_H_INCLUDED
# define YY_YY_GRAM_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COLON = 258,
     SEMICOLON = 259,
     LPAREN = 260,
     RPAREN = 261,
     LANGLE = 262,
     RANGLE = 263,
     LCURLY = 264,
     RCURLY = 265,
     LSQUARE = 266,
     RSQUARE = 267,
     COMMA = 268,
     EQ = 269,
     ABS = 270,
     DOT = 271,
     PLUS = 272,
     MINUS = 273,
     MULTIPLY = 274,
     DIVIDE = 275,
     TYPE_UD = 276,
     TYPE_D = 277,
     TYPE_UW = 278,
     TYPE_W = 279,
     TYPE_UB = 280,
     TYPE_B = 281,
     TYPE_VF = 282,
     TYPE_HF = 283,
     TYPE_V = 284,
     TYPE_F = 285,
     ALIGN1 = 286,
     ALIGN16 = 287,
     SECHALF = 288,
     COMPR = 289,
     SWITCH = 290,
     ATOMIC = 291,
     NODDCHK = 292,
     NODDCLR = 293,
     MASK_DISABLE = 294,
     BREAKPOINT = 295,
     ACCWRCTRL = 296,
     EOT = 297,
     SEQ = 298,
     ANY2H = 299,
     ALL2H = 300,
     ANY4H = 301,
     ALL4H = 302,
     ANY8H = 303,
     ALL8H = 304,
     ANY16H = 305,
     ALL16H = 306,
     ANYV = 307,
     ALLV = 308,
     ZERO = 309,
     EQUAL = 310,
     NOT_ZERO = 311,
     NOT_EQUAL = 312,
     GREATER = 313,
     GREATER_EQUAL = 314,
     LESS = 315,
     LESS_EQUAL = 316,
     ROUND_INCREMENT = 317,
     OVERFLOW = 318,
     UNORDERED = 319,
     GENREG = 320,
     MSGREG = 321,
     ADDRESSREG = 322,
     ACCREG = 323,
     FLAGREG = 324,
     MASKREG = 325,
     AMASK = 326,
     IMASK = 327,
     LMASK = 328,
     CMASK = 329,
     MASKSTACKREG = 330,
     LMS = 331,
     IMS = 332,
     MASKSTACKDEPTHREG = 333,
     IMSD = 334,
     LMSD = 335,
     NOTIFYREG = 336,
     STATEREG = 337,
     CONTROLREG = 338,
     IPREG = 339,
     GENREGFILE = 340,
     MSGREGFILE = 341,
     MOV = 342,
     FRC = 343,
     RNDU = 344,
     RNDD = 345,
     RNDE = 346,
     RNDZ = 347,
     NOT = 348,
     LZD = 349,
     MUL = 350,
     MAC = 351,
     MACH = 352,
     LINE = 353,
     SAD2 = 354,
     SADA2 = 355,
     DP4 = 356,
     DPH = 357,
     DP3 = 358,
     DP2 = 359,
     AVG = 360,
     ADD = 361,
     SEL = 362,
     AND = 363,
     OR = 364,
     XOR = 365,
     SHR = 366,
     SHL = 367,
     ASR = 368,
     CMP = 369,
     CMPN = 370,
     PLN = 371,
     ADDC = 372,
     BFI1 = 373,
     BFREV = 374,
     CBIT = 375,
     F16TO32 = 376,
     F32TO16 = 377,
     FBH = 378,
     FBL = 379,
     SEND = 380,
     SENDC = 381,
     NOP = 382,
     JMPI = 383,
     IF = 384,
     IFF = 385,
     WHILE = 386,
     ELSE = 387,
     BREAK = 388,
     CONT = 389,
     HALT = 390,
     MSAVE = 391,
     PUSH = 392,
     MREST = 393,
     POP = 394,
     WAIT = 395,
     DO = 396,
     ENDIF = 397,
     ILLEGAL = 398,
     MATH_INST = 399,
     MAD = 400,
     LRP = 401,
     BFE = 402,
     BFI2 = 403,
     SUBB = 404,
     CALL = 405,
     RET = 406,
     BRD = 407,
     BRC = 408,
     NULL_TOKEN = 409,
     MATH = 410,
     SAMPLER = 411,
     GATEWAY = 412,
     READ = 413,
     WRITE = 414,
     URB = 415,
     THREAD_SPAWNER = 416,
     VME = 417,
     DATA_PORT = 418,
     CRE = 419,
     MSGLEN = 420,
     RETURNLEN = 421,
     ALLOCATE = 422,
     USED = 423,
     COMPLETE = 424,
     TRANSPOSE = 425,
     INTERLEAVE = 426,
     SATURATE = 427,
     INTEGER = 428,
     STRING = 429,
     NUMBER = 430,
     INV = 431,
     LOG = 432,
     EXP = 433,
     SQRT = 434,
     RSQ = 435,
     POW = 436,
     SIN = 437,
     COS = 438,
     SINCOS = 439,
     INTDIV = 440,
     INTMOD = 441,
     INTDIVMOD = 442,
     SIGNED = 443,
     SCALAR = 444,
     X = 445,
     Y = 446,
     Z = 447,
     W = 448,
     KERNEL_PRAGMA = 449,
     END_KERNEL_PRAGMA = 450,
     CODE_PRAGMA = 451,
     END_CODE_PRAGMA = 452,
     REG_COUNT_PAYLOAD_PRAGMA = 453,
     REG_COUNT_TOTAL_PRAGMA = 454,
     DECLARE_PRAGMA = 455,
     BASE = 456,
     ELEMENTSIZE = 457,
     SRCREGION = 458,
     DSTREGION = 459,
     TYPE = 460,
     DEFAULT_EXEC_SIZE_PRAGMA = 461,
     DEFAULT_REG_TYPE_PRAGMA = 462,
     SUBREGNUM = 463,
     SNDOPR = 464,
     UMINUS = 465,
     STR_SYMBOL_REG = 466,
     EMPTEXECSIZE = 467
   };
#endif
/* Tokens.  */
#define COLON 258
#define SEMICOLON 259
#define LPAREN 260
#define RPAREN 261
#define LANGLE 262
#define RANGLE 263
#define LCURLY 264
#define RCURLY 265
#define LSQUARE 266
#define RSQUARE 267
#define COMMA 268
#define EQ 269
#define ABS 270
#define DOT 271
#define PLUS 272
#define MINUS 273
#define MULTIPLY 274
#define DIVIDE 275
#define TYPE_UD 276
#define TYPE_D 277
#define TYPE_UW 278
#define TYPE_W 279
#define TYPE_UB 280
#define TYPE_B 281
#define TYPE_VF 282
#define TYPE_HF 283
#define TYPE_V 284
#define TYPE_F 285
#define ALIGN1 286
#define ALIGN16 287
#define SECHALF 288
#define COMPR 289
#define SWITCH 290
#define ATOMIC 291
#define NODDCHK 292
#define NODDCLR 293
#define MASK_DISABLE 294
#define BREAKPOINT 295
#define ACCWRCTRL 296
#define EOT 297
#define SEQ 298
#define ANY2H 299
#define ALL2H 300
#define ANY4H 301
#define ALL4H 302
#define ANY8H 303
#define ALL8H 304
#define ANY16H 305
#define ALL16H 306
#define ANYV 307
#define ALLV 308
#define ZERO 309
#define EQUAL 310
#define NOT_ZERO 311
#define NOT_EQUAL 312
#define GREATER 313
#define GREATER_EQUAL 314
#define LESS 315
#define LESS_EQUAL 316
#define ROUND_INCREMENT 317
#define OVERFLOW 318
#define UNORDERED 319
#define GENREG 320
#define MSGREG 321
#define ADDRESSREG 322
#define ACCREG 323
#define FLAGREG 324
#define MASKREG 325
#define AMASK 326
#define IMASK 327
#define LMASK 328
#define CMASK 329
#define MASKSTACKREG 330
#define LMS 331
#define IMS 332
#define MASKSTACKDEPTHREG 333
#define IMSD 334
#define LMSD 335
#define NOTIFYREG 336
#define STATEREG 337
#define CONTROLREG 338
#define IPREG 339
#define GENREGFILE 340
#define MSGREGFILE 341
#define MOV 342
#define FRC 343
#define RNDU 344
#define RNDD 345
#define RNDE 346
#define RNDZ 347
#define NOT 348
#define LZD 349
#define MUL 350
#define MAC 351
#define MACH 352
#define LINE 353
#define SAD2 354
#define SADA2 355
#define DP4 356
#define DPH 357
#define DP3 358
#define DP2 359
#define AVG 360
#define ADD 361
#define SEL 362
#define AND 363
#define OR 364
#define XOR 365
#define SHR 366
#define SHL 367
#define ASR 368
#define CMP 369
#define CMPN 370
#define PLN 371
#define ADDC 372
#define BFI1 373
#define BFREV 374
#define CBIT 375
#define F16TO32 376
#define F32TO16 377
#define FBH 378
#define FBL 379
#define SEND 380
#define SENDC 381
#define NOP 382
#define JMPI 383
#define IF 384
#define IFF 385
#define WHILE 386
#define ELSE 387
#define BREAK 388
#define CONT 389
#define HALT 390
#define MSAVE 391
#define PUSH 392
#define MREST 393
#define POP 394
#define WAIT 395
#define DO 396
#define ENDIF 397
#define ILLEGAL 398
#define MATH_INST 399
#define MAD 400
#define LRP 401
#define BFE 402
#define BFI2 403
#define SUBB 404
#define CALL 405
#define RET 406
#define BRD 407
#define BRC 408
#define NULL_TOKEN 409
#define MATH 410
#define SAMPLER 411
#define GATEWAY 412
#define READ 413
#define WRITE 414
#define URB 415
#define THREAD_SPAWNER 416
#define VME 417
#define DATA_PORT 418
#define CRE 419
#define MSGLEN 420
#define RETURNLEN 421
#define ALLOCATE 422
#define USED 423
#define COMPLETE 424
#define TRANSPOSE 425
#define INTERLEAVE 426
#define SATURATE 427
#define INTEGER 428
#define STRING 429
#define NUMBER 430
#define INV 431
#define LOG 432
#define EXP 433
#define SQRT 434
#define RSQ 435
#define POW 436
#define SIN 437
#define COS 438
#define SINCOS 439
#define INTDIV 440
#define INTMOD 441
#define INTDIVMOD 442
#define SIGNED 443
#define SCALAR 444
#define X 445
#define Y 446
#define Z 447
#define W 448
#define KERNEL_PRAGMA 449
#define END_KERNEL_PRAGMA 450
#define CODE_PRAGMA 451
#define END_CODE_PRAGMA 452
#define REG_COUNT_PAYLOAD_PRAGMA 453
#define REG_COUNT_TOTAL_PRAGMA 454
#define DECLARE_PRAGMA 455
#define BASE 456
#define ELEMENTSIZE 457
#define SRCREGION 458
#define DSTREGION 459
#define TYPE 460
#define DEFAULT_EXEC_SIZE_PRAGMA 461
#define DEFAULT_REG_TYPE_PRAGMA 462
#define SUBREGNUM 463
#define SNDOPR 464
#define UMINUS 465
#define STR_SYMBOL_REG 466
#define EMPTEXECSIZE 467



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 437 "gram.y"

	char *string;
	int integer;
	double number;
	struct brw_program_instruction instruction;
	struct brw_program program;
	struct region region;
	struct regtype regtype;
	struct brw_reg reg;
	struct condition condition;
	struct predicate predicate;
	struct options options;
	struct declared_register symbol_reg;
	imm32_t imm32;

	struct src_operand src_operand;


/* Line 387 of yacc.c  */
#line 987 "gram.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GRAM_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 1028 "gram.c"
/* Unqualified %code blocks.  */
/* Line 391 of yacc.c  */
#line 570 "gram.y"


#undef error
#define error(l, fmt, ...)			\
    do {					\
	message(ERROR, l, fmt, ## __VA_ARGS__);	\
	YYERROR;				\
    } while(0)

static void add_option(struct options *options, int option)
{
    switch (option) {
    case ALIGN1:
	options->access_mode = BRW_ALIGN_1;
	break;
    case ALIGN16:
	options->access_mode = BRW_ALIGN_16;
	break;
    case SECHALF:
	options->compression_control |= BRW_COMPRESSION_2NDHALF;
	break;
    case COMPR:
	if (!IS_GENp(6))
	    options->compression_control |= BRW_COMPRESSION_COMPRESSED;
	break;
    case SWITCH:
	options->thread_control |= BRW_THREAD_SWITCH;
	break;
    case ATOMIC:
	options->thread_control |= BRW_THREAD_ATOMIC;
	break;
    case NODDCHK:
	options->dependency_control |= BRW_DEPENDENCY_NOTCHECKED;
	break;
    case NODDCLR:
	options->dependency_control |= BRW_DEPENDENCY_NOTCLEARED;
	break;
    case MASK_DISABLE:
	options->mask_control = BRW_MASK_DISABLE;
	break;
    case BREAKPOINT:
	options->debug_control = BRW_DEBUG_BREAKPOINT;
	break;
    case ACCWRCTRL:
	options->acc_wr_control = BRW_ACCUMULATOR_WRITE_ENABLE;
	break;
    case EOT:
	options->end_of_thread = 1;
	break;
    }
}



/* Line 391 of yacc.c  */
#line 1087 "gram.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1040

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  213
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  359
/* YYNRULES -- Number of states.  */
#define YYNSTATES  620

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   467

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    18,    22,    26,
      29,    33,    35,    38,    42,    46,    47,    51,    52,    56,
      60,    68,    71,    74,    77,    80,    82,    84,    86,    88,
      90,    93,    97,   100,   104,   107,   110,   113,   115,   117,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   158,   163,   168,
     174,   180,   182,   189,   195,   202,   209,   216,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   245,   247,
     249,   251,   253,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   297,   299,   301,   303,
     305,   307,   309,   311,   313,   315,   317,   319,   321,   323,
     325,   327,   329,   331,   342,   344,   346,   359,   368,   377,
     386,   395,   405,   415,   417,   422,   431,   438,   440,   442,
     446,   448,   450,   452,   454,   463,   469,   471,   482,   493,
     506,   513,   522,   533,   540,   555,   557,   558,   560,   561,
     563,   564,   566,   568,   569,   571,   573,   575,   577,   579,
     581,   583,   585,   587,   589,   591,   593,   595,   597,   598,
     600,   601,   603,   605,   607,   610,   615,   619,   621,   623,
     625,   629,   631,   633,   635,   637,   639,   641,   646,   653,
     655,   657,   659,   661,   663,   665,   667,   669,   671,   673,
     675,   678,   680,   684,   688,   690,   692,   694,   696,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   722,   726,
     733,   735,   742,   746,   748,   749,   751,   754,   755,   758,
     763,   766,   771,   774,   777,   780,   783,   785,   787,   789,
     791,   793,   796,   798,   800,   802,   805,   808,   811,   814,
     816,   818,   820,   822,   824,   828,   830,   834,   835,   839,
     840,   844,   852,   860,   866,   868,   870,   871,   873,   875,
     877,   879,   881,   883,   885,   886,   888,   890,   892,   894,
     896,   898,   900,   901,   904,   910,   912,   914,   916,   918,
     919,   925,   926,   928,   929,   931,   932,   934,   935,   937,
     939,   941,   942,   948,   949,   951,   953,   954,   957,   960,
     963,   966,   968,   970,   972,   974,   976,   978,   980,   982,
     984,   986,   987,   989,   990,   992,   993,   997,   998,  1000,
    1002,  1006,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1027,  1029,  1030,  1034,  1038,  1041,  1042,  1044,
    1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     216,     0,    -1,   173,    -1,    18,   173,    -1,   173,    -1,
     215,    17,   215,    -1,   215,    18,   215,    -1,   215,    19,
     215,    -1,   215,    20,   215,    -1,    18,   215,    -1,     5,
     215,     6,    -1,   229,    -1,   174,     3,    -1,   201,    14,
     271,    -1,   202,    14,   215,    -1,    -1,   203,    14,   305,
      -1,    -1,   204,    14,   304,    -1,   205,    14,   308,    -1,
     200,   174,   218,   219,   220,   221,   222,    -1,   199,   215,
      -1,   198,   215,    -1,   206,   215,    -1,   207,   308,    -1,
     224,    -1,   225,    -1,   226,    -1,   227,    -1,   223,    -1,
     229,   228,    -1,   229,   230,     4,    -1,   230,     4,    -1,
     229,   231,     4,    -1,   231,     4,    -1,   229,     4,    -1,
     229,   217,    -1,   217,    -1,   228,    -1,   229,     1,     4,
      -1,   237,    -1,   239,    -1,   241,    -1,   244,    -1,   246,
      -1,   252,    -1,   249,    -1,   253,    -1,   232,    -1,   233,
      -1,   234,    -1,   235,    -1,   236,    -1,   248,    -1,   250,
      -1,   142,    -1,   142,   323,   302,   327,    -1,   132,   323,
     302,   327,    -1,   318,   129,   323,   302,    -1,   318,   129,
     323,   302,   302,    -1,   318,   131,   323,   302,   327,    -1,
     141,    -1,   318,   135,   323,   302,   302,   327,    -1,   318,
     152,   323,   302,   327,    -1,   318,   153,   323,   302,   302,
     327,    -1,   318,   150,   323,   265,   302,   327,    -1,   318,
     151,   323,   267,   280,   327,    -1,   318,   238,   325,   324,
     323,   265,   272,   327,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,
      -1,   124,    -1,   318,   240,   325,   324,   323,   265,   280,
     274,   327,    -1,    95,    -1,    96,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,
      -1,   104,    -1,   116,    -1,   118,    -1,   318,   242,   325,
     324,   323,   265,   273,   274,   327,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,   117,
      -1,   149,    -1,   145,    -1,   146,    -1,   147,    -1,   148,
      -1,   318,   243,   325,   324,   323,   265,   280,   280,   280,
     327,    -1,   125,    -1,   126,    -1,   318,   245,   323,   215,
     255,   254,   256,   165,   215,   166,   215,   327,    -1,   318,
     245,   323,   265,   279,   254,   281,   327,    -1,   318,   245,
     323,   265,   279,   254,   275,   327,    -1,   318,   245,   323,
     265,   279,   247,   275,   327,    -1,   318,   245,   323,   265,
     279,   247,   281,   327,    -1,   318,   245,   323,   265,   279,
     254,   247,   275,   327,    -1,   318,   245,   323,   265,   279,
     254,   215,   281,   327,    -1,   215,    -1,   318,   128,   323,
     303,    -1,   318,   144,   323,   265,   280,   274,   262,   327,
      -1,   318,   251,   323,   302,   302,   327,    -1,   133,    -1,
     134,    -1,   318,   140,   297,    -1,   127,    -1,   281,    -1,
     265,    -1,   154,    -1,   156,     5,   173,    13,   173,    13,
     261,     6,    -1,   155,   262,   324,   263,   264,    -1,   157,
      -1,   158,     5,   173,    13,   173,    13,   173,    13,   173,
       6,    -1,   159,     5,   173,    13,   173,    13,   173,    13,
     173,     6,    -1,   159,     5,   173,    13,   173,    13,   173,
      13,   173,    13,   173,     6,    -1,   160,   173,   260,   257,
     258,   259,    -1,   161,     5,   173,    13,   173,    13,   173,
       6,    -1,   162,     5,   173,    13,   173,    13,   173,    13,
     173,     6,    -1,   164,     5,   173,    13,   173,     6,    -1,
     163,     5,   173,    13,   173,    13,   173,    13,   173,    13,
     173,    13,   173,     6,    -1,   167,    -1,    -1,   168,    -1,
      -1,   169,    -1,    -1,   170,    -1,   171,    -1,    -1,    30,
      -1,    21,    -1,    22,    -1,   176,    -1,   177,    -1,   178,
      -1,   179,    -1,   181,    -1,   182,    -1,   183,    -1,   184,
      -1,   185,    -1,   186,    -1,   187,    -1,    -1,   188,    -1,
      -1,   189,    -1,   266,    -1,   267,    -1,   269,   304,    -1,
     271,   304,   312,   308,    -1,   268,   304,   308,    -1,   295,
      -1,   299,    -1,   300,    -1,   301,   304,   308,    -1,   291,
      -1,   292,    -1,   290,    -1,   293,    -1,   174,    -1,   270,
      -1,   174,     5,   215,     6,    -1,   174,     5,   215,    13,
     215,     6,    -1,   286,    -1,   288,    -1,   287,    -1,   289,
      -1,   273,    -1,   275,    -1,   276,    -1,   282,    -1,   281,
      -1,   282,    -1,   275,    -1,   317,   309,    -1,   281,    -1,
     291,   305,   308,    -1,   278,   305,   308,    -1,   295,    -1,
     299,    -1,   297,    -1,   300,    -1,   301,   305,   308,    -1,
     292,    -1,   290,    -1,   293,    -1,   269,    -1,   286,    -1,
     288,    -1,   281,    -1,   282,    -1,   321,   322,   269,   305,
     308,    -1,   298,   305,   308,    -1,   321,   322,   286,   305,
     310,   308,    -1,   277,    -1,   321,   322,   287,   307,   308,
     310,    -1,   290,    13,   284,    -1,   290,    -1,    -1,   215,
      -1,    16,   215,    -1,    -1,    65,   285,    -1,    85,    11,
     283,    12,    -1,    66,   285,    -1,    86,    11,   283,    12,
      -1,    67,   285,    -1,    68,   285,    -1,    69,   285,    -1,
      70,   285,    -1,   294,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    75,   285,    -1,   296,    -1,    77,    -1,
      76,    -1,    81,   308,    -1,    82,   285,    -1,    83,   285,
      -1,    84,   308,    -1,   154,    -1,   214,    -1,   174,    -1,
     174,    -1,   215,    -1,   286,   305,   308,    -1,   270,    -1,
     287,   307,   308,    -1,    -1,     7,   215,     8,    -1,    -1,
       7,   215,     8,    -1,     7,   215,    13,   215,    13,   215,
       8,    -1,     7,   215,     4,   215,    13,   215,     8,    -1,
       7,   215,    13,   215,     8,    -1,   305,    -1,   306,    -1,
      -1,    30,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    -1,    30,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    29,    -1,    27,    -1,
      -1,    16,   311,    -1,    16,   311,   311,   311,   311,    -1,
     190,    -1,   191,    -1,   192,    -1,   193,    -1,    -1,    16,
     313,   314,   315,   316,    -1,    -1,   190,    -1,    -1,   191,
      -1,    -1,   192,    -1,    -1,   193,    -1,   215,    -1,   175,
      -1,    -1,     5,   319,   292,   320,     6,    -1,    -1,    17,
      -1,    18,    -1,    -1,    16,   190,    -1,    16,   191,    -1,
      16,   192,    -1,    16,   193,    -1,    52,    -1,    53,    -1,
      44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    -1,    18,    -1,    -1,
      15,    -1,    -1,     5,   215,     6,    -1,    -1,   172,    -1,
     326,    -1,   326,    16,   292,    -1,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    -1,
       9,   328,    10,    -1,   328,    13,   329,    -1,   328,   329,
      -1,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    41,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   625,   625,   626,   629,   630,   631,   632,   633,   634,
     635,   638,   645,   648,   653,   659,   666,   672,   675,   680,
     685,   710,   712,   715,   720,   725,   726,   727,   728,   729,
     732,   736,   741,   746,   751,   756,   760,   765,   770,   775,
     783,   784,   785,   786,   787,   788,   789,   790,   794,   795,
     796,   797,   798,   799,   800,   803,   815,   827,   853,   876,
     893,   925,   932,   949,   964,   985,  1021,  1043,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,  1064,  1064,
    1064,  1064,  1069,  1092,  1092,  1092,  1092,  1092,  1092,  1092,
    1092,  1092,  1092,  1092,  1092,  1097,  1120,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1123,
    1123,  1123,  1123,  1127,  1150,  1150,  1153,  1228,  1249,  1273,
    1319,  1366,  1395,  1421,  1427,  1452,  1474,  1488,  1488,  1496,
    1513,  1520,  1523,  1526,  1538,  1579,  1600,  1609,  1650,  1711,
    1768,  1792,  1820,  1840,  1860,  1912,  1913,  1916,  1917,  1920,
    1921,  1924,  1925,  1926,  1930,  1931,  1932,  1935,  1935,  1935,
    1935,  1935,  1935,  1935,  1935,  1935,  1936,  1936,  1939,  1940,
    1943,  1944,  1949,  1949,  1952,  1957,  1972,  1978,  1984,  1990,
    1996,  2004,  2004,  2004,  2004,  2007,  2017,  2023,  2034,  2057,
    2062,  2067,  2072,  2080,  2080,  2083,  2083,  2086,  2086,  2086,
    2089,  2150,  2151,  2162,  2176,  2180,  2188,  2192,  2196,  2207,
    2207,  2207,  2210,  2217,  2217,  2220,  2220,  2223,  2247,  2265,
    2281,  2285,  2306,  2314,  2325,  2326,  2331,  2335,  2342,  2351,
    2360,  2369,  2378,  2390,  2401,  2418,  2428,  2437,  2437,  2437,
    2437,  2440,  2449,  2458,  2458,  2484,  2520,  2535,  2549,  2558,
    2569,  2579,  2589,  2596,  2603,  2611,  2623,  2639,  2642,  2655,
    2663,  2671,  2678,  2691,  2700,  2700,  2709,  2710,  2711,  2712,
    2713,  2714,  2715,  2716,  2720,  2724,  2725,  2726,  2727,  2728,
    2729,  2730,  2738,  2741,  2745,  2751,  2751,  2751,  2751,  2759,
    2762,  2768,  2769,  2772,  2773,  2776,  2777,  2780,  2781,  2785,
    2786,  2791,  2797,  2806,  2807,  2808,  2811,  2812,  2813,  2814,
    2815,  2816,  2817,  2818,  2819,  2820,  2821,  2822,  2823,  2824,
    2825,  2828,  2829,  2832,  2833,  2836,  2840,  2853,  2854,  2856,
    2862,  2869,  2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,
    2878,  2879,  2880,  2885,  2886,  2890,  2895,  2901,  2906,  2907,
    2908,  2909,  2910,  2911,  2912,  2913,  2914,  2915,  2916,  2917
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "LANGLE", "RANGLE", "LCURLY", "RCURLY", "LSQUARE", "RSQUARE", "COMMA",
  "EQ", "ABS", "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "TYPE_UD",
  "TYPE_D", "TYPE_UW", "TYPE_W", "TYPE_UB", "TYPE_B", "TYPE_VF", "TYPE_HF",
  "TYPE_V", "TYPE_F", "ALIGN1", "ALIGN16", "SECHALF", "COMPR", "SWITCH",
  "ATOMIC", "NODDCHK", "NODDCLR", "MASK_DISABLE", "BREAKPOINT",
  "ACCWRCTRL", "EOT", "SEQ", "ANY2H", "ALL2H", "ANY4H", "ALL4H", "ANY8H",
  "ALL8H", "ANY16H", "ALL16H", "ANYV", "ALLV", "ZERO", "EQUAL", "NOT_ZERO",
  "NOT_EQUAL", "GREATER", "GREATER_EQUAL", "LESS", "LESS_EQUAL",
  "ROUND_INCREMENT", "OVERFLOW", "UNORDERED", "GENREG", "MSGREG",
  "ADDRESSREG", "ACCREG", "FLAGREG", "MASKREG", "AMASK", "IMASK", "LMASK",
  "CMASK", "MASKSTACKREG", "LMS", "IMS", "MASKSTACKDEPTHREG", "IMSD",
  "LMSD", "NOTIFYREG", "STATEREG", "CONTROLREG", "IPREG", "GENREGFILE",
  "MSGREGFILE", "MOV", "FRC", "RNDU", "RNDD", "RNDE", "RNDZ", "NOT", "LZD",
  "MUL", "MAC", "MACH", "LINE", "SAD2", "SADA2", "DP4", "DPH", "DP3",
  "DP2", "AVG", "ADD", "SEL", "AND", "OR", "XOR", "SHR", "SHL", "ASR",
  "CMP", "CMPN", "PLN", "ADDC", "BFI1", "BFREV", "CBIT", "F16TO32",
  "F32TO16", "FBH", "FBL", "SEND", "SENDC", "NOP", "JMPI", "IF", "IFF",
  "WHILE", "ELSE", "BREAK", "CONT", "HALT", "MSAVE", "PUSH", "MREST",
  "POP", "WAIT", "DO", "ENDIF", "ILLEGAL", "MATH_INST", "MAD", "LRP",
  "BFE", "BFI2", "SUBB", "CALL", "RET", "BRD", "BRC", "NULL_TOKEN", "MATH",
  "SAMPLER", "GATEWAY", "READ", "WRITE", "URB", "THREAD_SPAWNER", "VME",
  "DATA_PORT", "CRE", "MSGLEN", "RETURNLEN", "ALLOCATE", "USED",
  "COMPLETE", "TRANSPOSE", "INTERLEAVE", "SATURATE", "INTEGER", "STRING",
  "NUMBER", "INV", "LOG", "EXP", "SQRT", "RSQ", "POW", "SIN", "COS",
  "SINCOS", "INTDIV", "INTMOD", "INTDIVMOD", "SIGNED", "SCALAR", "X", "Y",
  "Z", "W", "KERNEL_PRAGMA", "END_KERNEL_PRAGMA", "CODE_PRAGMA",
  "END_CODE_PRAGMA", "REG_COUNT_PAYLOAD_PRAGMA", "REG_COUNT_TOTAL_PRAGMA",
  "DECLARE_PRAGMA", "BASE", "ELEMENTSIZE", "SRCREGION", "DSTREGION",
  "TYPE", "DEFAULT_EXEC_SIZE_PRAGMA", "DEFAULT_REG_TYPE_PRAGMA",
  "SUBREGNUM", "SNDOPR", "UMINUS", "STR_SYMBOL_REG", "EMPTEXECSIZE",
  "$accept", "simple_int", "exp", "ROOT", "label", "declare_base",
  "declare_elementsize", "declare_srcregion", "declare_dstregion",
  "declare_type", "declare_pragma", "reg_count_total_pragma",
  "reg_count_payload_pragma", "default_exec_size_pragma",
  "default_reg_type_pragma", "pragma", "instrseq", "instruction",
  "relocatableinstruction", "ifelseinstruction", "loopinstruction",
  "haltinstruction", "multibranchinstruction", "subroutineinstruction",
  "unaryinstruction", "unaryop", "binaryinstruction", "binaryop",
  "binaryaccinstruction", "binaryaccop", "trinaryop", "trinaryinstruction",
  "sendop", "sendinstruction", "sndopr", "jumpinstruction",
  "mathinstruction", "breakinstruction", "breakop", "syncinstruction",
  "nopinstruction", "payload", "post_dst", "msgtarget", "urb_allocate",
  "urb_used", "urb_complete", "urb_swizzle", "sampler_datatype",
  "math_function", "math_signed", "math_scalar", "dst", "dstoperand",
  "dstoperandex", "dstoperandex_typed", "symbol_reg", "symbol_reg_p",
  "dstreg", "srcaccimm", "srcacc", "srcimm", "imm32reg",
  "directsrcaccoperand", "srcarchoperandex", "srcarchoperandex_typed",
  "sendleadreg", "src", "directsrcoperand", "indirectsrcoperand",
  "addrparam", "immaddroffset", "subregnum", "directgenreg",
  "indirectgenreg", "directmsgreg", "indirectmsgreg", "addrreg", "accreg",
  "flagreg", "maskreg", "mask_subreg", "maskstackreg", "maskstack_subreg",
  "notifyreg", "statereg", "controlreg", "ipreg", "nullreg",
  "relativelocation", "relativelocation2", "dstregion", "region",
  "region_wh", "indirectregion", "regtype", "srcimmtype", "swizzle",
  "chansel", "writemask", "writemask_x", "writemask_y", "writemask_z",
  "writemask_w", "imm32", "predicate", "predstate", "predctrl", "negate",
  "abs", "execsize", "saturate", "conditionalmodifier", "condition",
  "instoptions", "instoption_list", "instoption", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   213,   214,   214,   215,   215,   215,   215,   215,   215,
     215,   216,   217,   218,   219,   220,   220,   221,   221,   222,
     223,   224,   225,   226,   227,   228,   228,   228,   228,   228,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     230,   230,   230,   230,   230,   230,   230,   230,   231,   231,
     231,   231,   231,   231,   231,   232,   232,   232,   232,   232,
     233,   233,   234,   235,   235,   236,   236,   237,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   239,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   243,
     243,   243,   243,   244,   245,   245,   246,   246,   246,   246,
     246,   246,   246,   247,   248,   249,   250,   251,   251,   252,
     253,   254,   255,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   260,   261,   261,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     264,   264,   265,   265,   266,   266,   267,   267,   267,   267,
     267,   268,   268,   268,   268,   269,   269,   270,   270,   271,
     271,   271,   271,   272,   272,   273,   273,   274,   274,   274,
     275,   276,   276,   277,   277,   277,   277,   277,   277,   278,
     278,   278,   279,   279,   279,   280,   280,   281,   281,   281,
     281,   282,   283,   283,   284,   284,   285,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   293,   294,   294,   294,
     294,   295,   295,   296,   296,   297,   298,   299,   300,   301,
     302,   302,   303,   303,   303,   303,   303,   304,   304,   305,
     305,   305,   305,   306,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   310,   310,   310,   311,   311,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   315,   316,   316,   317,
     317,   318,   318,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   321,   321,   322,   322,   323,   323,   324,   324,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   327,   327,   328,   328,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     3,     3,     3,     2,
       3,     1,     2,     3,     3,     0,     3,     0,     3,     3,
       7,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     3,     2,     3,     2,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     5,
       5,     1,     6,     5,     6,     6,     6,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     9,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,    10,     1,     1,    12,     8,     8,     8,
       8,     9,     9,     1,     4,     8,     6,     1,     1,     3,
       1,     1,     1,     1,     8,     5,     1,    10,    10,    12,
       6,     8,    10,     6,    14,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     1,     1,     2,     4,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     6,
       1,     6,     3,     1,     0,     1,     2,     0,     2,     4,
       2,     4,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     3,     1,     3,     0,     3,     0,
       3,     7,     7,     5,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     5,     1,     1,     1,     1,     0,
       5,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     0,     5,     0,     1,     1,     0,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     0,     3,     0,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     301,   303,   130,   325,    61,   325,     0,     0,     0,     0,
       0,   266,     0,    37,    29,    25,    26,    27,    28,    38,
       0,     0,     0,    48,    49,    50,    51,    52,    40,    41,
      42,    43,    44,    53,    46,    54,    45,    47,     0,   304,
     305,     0,     0,     0,     0,    12,     0,     0,     4,    22,
      21,     0,    23,   268,   269,   270,   271,   272,   273,   267,
      24,     1,     0,    35,    36,    30,     0,     0,    32,    34,
      68,    69,    70,    71,    72,    73,    74,    75,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    93,
     107,    94,    76,    77,    78,    79,    80,    81,   114,   115,
     325,   325,   325,   127,   128,   325,     0,   325,   109,   110,
     111,   112,   108,   325,   325,   325,   325,   331,   331,   331,
     331,   325,   325,   227,   306,     0,     0,     2,   251,   250,
     343,   343,     0,     9,     0,     0,     0,     0,     0,     0,
      39,    31,    33,     0,     0,     0,     0,   266,   129,     0,
       0,     0,     0,     0,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   327,   329,   327,   327,   327,
       0,     0,     0,   234,     0,   313,   314,   315,   316,   317,
     318,   319,   320,   311,   312,     0,   326,     3,   347,    57,
      56,    10,     5,     6,     7,     8,     0,     0,    15,   227,
       0,   252,   253,   255,   259,   259,   124,    58,   343,     0,
     245,   227,   227,   227,   227,   237,   238,   239,   240,   227,
     244,   243,   227,   266,     0,   249,   185,   321,   172,   173,
     257,   257,   186,   257,   189,   191,   190,   192,   183,   181,
     182,   184,   236,   177,   242,   178,   179,   257,     0,   321,
     343,     0,   328,   325,     0,   325,   325,   325,     0,     0,
       0,   226,   307,   308,   309,   310,   302,     0,    13,     0,
       0,    17,   228,     0,     0,     0,   266,     0,   264,   265,
     266,    59,    60,   343,   230,   232,   233,   235,   241,   247,
     248,     0,   322,   227,   220,   259,   321,   215,   216,   210,
     209,   211,   204,   206,   259,   205,   207,   259,   323,     0,
     266,   174,   289,   266,   343,   343,    63,   343,     0,   330,
       0,     0,     0,   321,   132,   212,   321,   213,   214,   343,
     344,     0,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   346,    14,   259,     0,     0,     0,
     223,     0,     0,   254,     0,   256,    62,     0,   246,   266,
     322,   300,   299,     0,   199,   197,   198,   274,   266,   266,
     324,     0,     0,   176,   291,   266,   180,    65,    66,    64,
     321,   321,   321,   321,     0,   131,   323,   123,   321,   321,
     126,   345,    16,   257,     0,    20,   229,   224,   187,     0,
       0,   260,     0,     0,   231,   203,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   343,   276,   277,
     278,   279,   281,   280,   275,   200,   218,   208,   259,   259,
     259,   258,   292,   293,   175,   343,   193,   194,   195,   201,
     196,   259,   321,   321,   321,   133,     0,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   343,   343,
     299,     0,   343,   343,    18,   266,   225,   222,     0,     0,
       0,     0,   125,   266,   282,   266,   294,   295,    67,   266,
     343,   343,   321,   327,     0,     0,     0,   153,     0,     0,
       0,     0,     0,   119,   120,   322,   343,   343,   118,   117,
      19,   188,     0,     0,   263,   217,     0,   266,   282,   296,
     297,   202,    82,    95,   343,   168,     0,     0,     0,   151,
     152,   146,     0,     0,     0,     0,     0,   122,   121,     0,
       0,   285,   286,   287,   288,   283,   219,   221,   298,   290,
     113,   169,   170,     0,     0,     0,   145,   148,     0,     0,
       0,     0,     0,   262,   261,     0,   171,   135,     0,     0,
       0,   147,   150,     0,     0,     0,     0,   343,     0,     0,
       0,     0,   149,   140,     0,     0,     0,   143,   116,   284,
     155,   156,   154,     0,     0,     0,     0,     0,     0,   134,
       0,     0,   141,     0,     0,     0,     0,     0,     0,   137,
     138,     0,   142,     0,     0,     0,   139,     0,     0,   144
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   139,   372,    12,    13,   149,   208,   281,   358,   405,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   127,    29,   128,    30,   129,
     130,    31,   131,    32,   398,    33,    34,    35,   132,    36,
      37,   394,   333,   466,   557,   572,   583,   531,   593,   427,
     552,   567,   237,   238,   239,   240,   241,   242,   243,   445,
     446,   373,   374,   448,   304,   305,   336,   306,   307,   308,
     359,   477,   183,   244,   245,   246,   247,   309,   249,   310,
     311,   252,   312,   254,   313,   314,   315,   316,   317,   140,
     216,   320,   288,   289,   290,    60,   435,   517,   545,   385,
     443,   487,   520,   549,   377,    38,    41,   195,   318,   381,
      43,   263,   175,   176,   199,   277,   354
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -505
static const yytype_int16 yypact[] =
{
      51,    12,  -505,    17,  -505,    33,    57,    40,    40,  -131,
      40,   445,    52,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
     425,    60,    65,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,   887,  -505,
    -505,     3,    40,    53,    53,  -505,    40,    40,  -505,   419,
     419,  -126,   419,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,    76,  -505,  -505,  -505,   110,   112,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
      17,    17,    17,  -505,  -505,    17,    36,    17,  -505,  -505,
    -505,  -505,  -505,    17,    17,    17,    17,   870,   870,   870,
     870,    17,    17,   105,   412,   286,   -51,  -505,  -505,  -505,
     124,   124,   354,  -505,    40,    40,    40,    40,   120,   -66,
    -505,  -505,  -505,   242,    53,    53,    53,   445,  -505,   799,
     799,   667,    53,    53,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,   -30,   128,   -30,   -30,   -30,
     612,    53,    40,  -505,   395,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,   139,  -505,  -505,  -505,  -505,
    -505,  -505,    67,    67,  -505,  -505,    -3,   134,   -53,   105,
     140,   150,   419,  -505,   152,   155,  -505,    53,   124,    53,
    -505,   105,   105,   105,   105,  -505,  -505,  -505,  -505,   105,
    -505,  -505,   105,   445,   159,  -505,   150,   769,  -505,  -505,
     165,   165,  -505,   165,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,   165,    53,   769,
     124,    53,  -505,    17,     3,    17,    17,    17,   707,   -42,
      53,    85,  -505,  -505,  -505,  -505,  -505,   867,  -505,    40,
     160,   -38,  -505,   136,    40,    40,   445,    40,  -505,  -505,
     445,  -505,  -505,   124,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,   136,  -505,   105,  -505,   152,   592,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,   152,  -505,  -505,   152,   162,    40,
     445,  -505,   179,   445,   124,   124,  -505,   124,   799,  -505,
     799,   799,   799,   769,  -505,  -505,   635,  -505,  -505,   124,
    -505,   763,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,   419,   152,   197,    14,   216,
     225,    71,   306,  -505,   348,  -505,  -505,   236,  -505,   445,
      40,  -505,   419,   734,  -505,  -505,  -505,   591,   445,   445,
    -505,   -54,   415,  -505,    63,   445,  -505,  -505,  -505,  -505,
     409,   769,   742,   769,   781,  -505,   162,   419,   592,   592,
    -505,  -505,  -505,   165,   240,  -505,  -505,    40,  -505,    40,
      40,  -505,    40,    40,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,   124,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,   152,   152,
     155,  -505,  -505,    64,  -505,   124,  -505,  -505,  -505,  -505,
    -505,   152,   592,   592,   769,  -505,   734,   257,  -505,   261,
     271,   106,   281,   282,   284,   288,   126,   -49,   124,   124,
     574,     7,   124,   124,  -505,   445,   419,  -505,   377,   400,
     483,   391,  -505,   445,   279,   445,  -505,   104,  -505,   445,
     124,   124,   769,   -30,   125,   138,   142,   -63,   143,   145,
     169,   170,    40,  -505,  -505,    40,   124,   124,  -505,  -505,
    -505,  -505,    40,    40,  -505,  -505,   410,   445,   279,  -505,
     116,  -505,  -505,  -505,   124,   157,   300,   320,   325,  -505,
    -505,   182,   342,   344,   345,   346,     1,  -505,  -505,   491,
     587,  -505,  -505,  -505,  -505,   410,  -505,  -505,  -505,  -505,
    -505,  -505,   175,   202,   203,   205,  -505,   217,   211,   213,
     215,   218,    40,  -505,  -505,   410,  -505,  -505,   376,   380,
     385,  -505,   232,   394,   399,   408,   418,   226,   410,     6,
     258,   268,  -505,  -505,   270,   274,   275,  -505,  -505,  -505,
    -505,  -505,  -505,   443,   438,   442,   466,   460,   461,  -505,
     314,   315,  -505,   316,   321,   498,    20,   501,   484,  -505,
    -505,   388,  -505,   389,   558,   555,  -505,   407,   575,  -505
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -505,  -505,    -7,  -505,   563,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,  -505,   570,  -505,   576,   578,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,
    -505,  -505,  -505,  -505,   209,  -505,  -505,  -505,  -505,  -505,
    -505,   273,  -505,  -505,  -505,  -505,  -505,  -505,  -505,   163,
    -505,  -505,    16,  -505,   450,  -505,  -255,   463,   416,  -505,
     234,  -341,  -344,  -505,  -505,  -505,  -505,  -250,  -289,  -221,
     326,  -505,  -156,  -145,  -140,   359,  -505,   -67,  -333,   -31,
    -110,  -505,   -61,  -505,   513,  -505,    49,   114,   122,    -2,
    -505,  -209,  -199,  -505,   193,  -155,  -505,   117,  -504,  -505,
    -505,  -505,  -505,  -505,  -505,  -505,  -505,  -505,   -48,   238,
      74,  -172,   -33,  -505,  -137,  -505,   295
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -322
static const yytype_int16 yytable[] =
{
      49,    50,   220,    52,   200,   265,   266,   267,   214,   325,
     134,   209,    46,   215,   335,   286,   209,   375,   144,   145,
     146,   147,    42,   209,   221,    47,   610,   590,   591,    39,
      40,   210,   321,   611,   322,   135,   592,   -55,    42,   142,
     143,   565,   141,    51,   395,    46,   447,   395,   323,   251,
     251,   251,    61,   282,   468,   472,     1,   451,    47,   451,
      45,   578,   209,   221,    68,   294,   295,   296,   297,    69,
     251,   136,   133,   298,   589,   148,   299,   408,   300,    44,
     150,   292,   210,   234,   409,   376,   146,   147,   144,   145,
     146,   147,   248,   248,   248,   177,   178,   179,   253,   253,
     253,   449,   144,   449,   146,   147,   369,   529,   530,   469,
     473,   490,   491,   248,   151,   378,   152,   157,   379,   253,
     236,   182,   197,   326,   337,   236,   438,   507,   250,   250,
     250,   363,   236,   198,   206,   365,   207,   202,   203,   204,
     205,   452,   262,   454,   264,   276,   212,   368,   279,   250,
     280,   283,   217,   218,   219,   284,   366,   402,   251,   285,
     260,   261,   287,   375,   375,   383,   357,   562,   386,   450,
     301,   450,   319,   268,   356,   271,   258,   380,     2,   270,
      48,   506,   371,     3,   153,   154,   155,   387,   388,   156,
     389,   159,     4,     5,   474,   384,   269,   160,   161,   162,
     163,   248,   400,   222,   492,   180,   181,   253,   255,   255,
     255,   403,   438,    48,   415,   291,   360,   293,   251,   404,
     251,   251,   251,   436,   437,     6,   137,   138,   406,   255,
     444,   376,   376,   329,   360,   198,   439,   250,   407,   483,
     484,   440,   524,   144,   145,   146,   147,    46,   414,     7,
       8,     9,   489,   442,   475,   486,   324,    10,    11,   327,
      47,   248,   494,   248,   248,   248,   495,   253,   339,   253,
     253,   253,   355,   256,   256,   256,   496,   361,   362,   497,
     364,   257,   257,   257,   334,   396,   498,   499,   396,   500,
     482,   502,   196,   501,   256,   516,   519,   250,   526,   250,
     250,   250,   257,   144,   145,   146,   147,   209,   488,   548,
     410,   527,   382,   553,   411,   528,   532,   255,   533,   412,
     510,   525,   439,   144,   145,   146,   147,   210,   515,   397,
     518,   503,   504,   554,   521,   508,   509,   328,   555,   330,
     331,   332,   534,   535,   390,   551,   391,   392,   393,   556,
     396,   396,   410,   522,   523,   558,   411,   559,   560,   561,
     201,   413,   546,   143,   566,   144,   145,   146,   147,   537,
     538,   144,   145,   146,   147,   568,   569,   255,   570,   255,
     255,   255,   256,   511,   573,   571,   574,   550,   575,   579,
     257,   576,   470,   580,   144,   145,   146,   147,   581,   514,
     476,   582,   478,   479,   513,   480,   481,   584,   144,   145,
     146,   147,   585,   512,    46,    48,   211,   144,   145,   146,
     147,   586,   396,   441,   587,   -11,    62,   370,   184,    63,
       1,   594,   144,   145,   146,   147,   144,   145,   146,   147,
     588,   595,   256,   596,   256,   256,   256,   597,   598,   599,
     257,   600,   257,   257,   257,   601,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    53,    54,    55,    56,
      57,    58,   602,   603,   604,    59,   222,   223,   133,   224,
     225,   226,   227,   228,   229,   230,   231,   605,   606,   607,
     157,   303,   232,   233,   608,   536,   513,   613,   203,   563,
     144,   145,   146,   147,   609,   539,   540,   612,   144,   145,
     146,   147,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,     2,  -301,  -301,   577,  -301,     3,  -301,  -301,
    -301,   614,   615,   235,   616,  -301,     4,     5,   617,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -123,
     618,   619,    48,    64,   371,   272,   273,   274,   275,  -321,
      65,   144,   505,   146,   147,   564,    66,    46,    67,     6,
     541,   542,   543,   544,   144,   145,   146,   147,   471,   399,
     370,   259,   428,   429,   430,   431,   213,    46,   432,   493,
     433,   434,   278,     7,     8,     9,   453,   367,   338,   158,
      47,    10,    11,   485,   467,   547,   401,     0,     0,  -321,
      46,   222,     0,   133,   224,   225,   226,   227,   228,   229,
     230,   231,     0,   370,     0,   157,   303,   232,   233,   222,
       0,   133,   224,   225,   226,   227,   228,   229,   230,   231,
       0,     0,     0,   157,   303,   232,   233,   209,   221,   222,
     223,   133,   224,   225,   226,   227,   228,   229,   230,   231,
       0,     0,     0,     0,     0,   232,   233,   210,   234,     0,
       0,     0,   222,     0,   133,   224,   225,   226,   227,   228,
     229,   230,   231,     0,     0,     0,   157,   303,   232,   233,
       0,     0,     0,     0,   144,   145,   146,   147,   235,     0,
       0,     0,     0,     0,   222,   223,   133,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   235,  -123,  -321,  -123,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,     0,     0,    48,   235,   371,     0,     0,
       0,     0,   209,   221,   222,   223,   133,   224,   225,   226,
     227,   228,   229,   230,   231,    48,   236,   302,     0,   235,
     232,   233,   210,   234,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,     0,     0,    48,   222,
     223,   133,   224,   225,   226,   227,   228,   229,   230,   231,
       0,   235,     0,   157,   303,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,   133,   224,
     225,   226,   227,   228,   229,   230,   231,     0,     0,     0,
     157,   303,   232,   233,     0,     0,     0,     0,     0,     0,
       0,   235,     0,     0,   209,   221,   222,   223,   133,   224,
     225,   226,   227,   228,   229,   230,   231,   340,     0,     0,
     341,   236,   232,   233,   210,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     416,   417,   418,   419,     0,   420,   421,   422,   423,   424,
     425,   426,     0,   235,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,     0,   112,     0,
     113,   114,   115,     0,     0,     0,     0,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-505)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       7,     8,   157,    10,   141,   177,   178,   179,   153,   259,
      41,    65,     5,   153,   269,   214,    65,   306,    17,    18,
      19,    20,     5,    65,    66,    18,     6,    21,    22,    17,
      18,    85,   241,    13,   243,    42,    30,     4,     5,    46,
      47,   545,    44,   174,   333,     5,   390,   336,   257,   159,
     160,   161,     0,   209,   398,   399,     5,   390,    18,   392,
       3,   565,    65,    66,     4,   221,   222,   223,   224,     4,
     180,    18,    69,   229,   578,   201,   232,     6,   233,     5,
       4,   218,    85,    86,    13,   306,    19,    20,    17,    18,
      19,    20,   159,   160,   161,   128,   129,   130,   159,   160,
     161,   390,    17,   392,    19,    20,   305,   170,   171,   398,
     399,   452,   453,   180,     4,   314,     4,    81,   317,   180,
     174,    16,   173,   260,   269,   174,   381,   471,   159,   160,
     161,   286,   174,     9,    14,   290,   202,   144,   145,   146,
     147,   391,   172,   393,    16,     6,   153,   303,    14,   180,
     203,    11,   154,   155,   156,     5,   293,   356,   268,     7,
     162,   163,     7,   452,   453,   320,   204,   166,   323,   390,
      11,   392,     7,   180,    14,   182,   160,    15,   127,   181,
     173,   470,   175,   132,   110,   111,   112,   324,   325,   115,
     327,   117,   141,   142,   403,    16,   180,   123,   124,   125,
     126,   268,   339,    67,   454,   131,   132,   268,   159,   160,
     161,    14,   467,   173,   369,   217,   283,   219,   328,   205,
     330,   331,   332,   378,   379,   174,   173,   174,    12,   180,
     385,   452,   453,   264,   301,     9,   381,   268,    13,   438,
     439,   381,   492,    17,    18,    19,    20,     5,    12,   198,
     199,   200,   451,   190,    14,   191,   258,   206,   207,   261,
      18,   328,     5,   330,   331,   332,     5,   328,   270,   330,
     331,   332,   279,   159,   160,   161,     5,   284,   285,   173,
     287,   159,   160,   161,   268,   333,     5,     5,   336,     5,
     427,   165,     6,     5,   180,    16,   192,   328,   173,   330,
     331,   332,   180,    17,    18,    19,    20,    65,   445,   193,
       4,   173,   319,    13,     8,   173,   173,   268,   173,    13,
     475,   493,   467,    17,    18,    19,    20,    85,   483,   336,
     485,   468,   469,    13,   489,   472,   473,   263,    13,   265,
     266,   267,   173,   173,   328,   188,   330,   331,   332,   167,
     398,   399,     4,   490,   491,    13,     8,    13,    13,    13,
       6,    13,   517,   370,   189,    17,    18,    19,    20,   506,
     507,    17,    18,    19,    20,   173,   173,   328,   173,   330,
     331,   332,   268,     6,   173,   168,   173,   524,   173,    13,
     268,   173,   399,    13,    17,    18,    19,    20,    13,     8,
     407,   169,   409,   410,    13,   412,   413,    13,    17,    18,
      19,    20,    13,    13,     5,   173,   174,    17,    18,    19,
      20,    13,   470,     8,     6,     0,     1,    18,    16,     4,
       5,   173,    17,    18,    19,    20,    17,    18,    19,    20,
     577,   173,   328,   173,   330,   331,   332,   173,   173,     6,
     328,    13,   330,   331,   332,    13,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    21,    22,    23,    24,
      25,    26,     6,    13,    13,    30,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   173,   173,   173,
      81,    82,    83,    84,   173,   502,    13,    13,   505,     8,
      17,    18,    19,    20,     6,   512,   513,     6,    17,    18,
      19,    20,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   562,   131,   132,   133,   134,
     135,   173,   173,   154,     6,   140,   141,   142,    13,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     5,
     173,     6,   173,    20,   175,   190,   191,   192,   193,    15,
      20,    17,    18,    19,    20,     8,    20,     5,    20,   174,
     190,   191,   192,   193,    17,    18,    19,    20,   399,   336,
      18,   161,    21,    22,    23,    24,   153,     5,    27,   456,
      29,    30,   206,   198,   199,   200,   392,   301,   269,   116,
      18,   206,   207,   440,   396,   518,   341,    -1,    -1,    65,
       5,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    18,    -1,    81,    82,    83,    84,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    81,    82,    83,    84,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,   154,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   154,   173,   174,   175,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,   173,   154,   175,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   173,   174,    18,    -1,   154,
      83,    84,    85,    86,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,   173,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   154,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    10,    -1,    -1,
      13,   174,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,    -1,   154,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,    -1,   131,    -1,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,   127,   132,   141,   142,   174,   198,   199,   200,
     206,   207,   216,   217,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   239,
     241,   244,   246,   248,   249,   250,   252,   253,   318,    17,
      18,   319,     5,   323,   323,     3,     5,    18,   173,   215,
     215,   174,   215,    21,    22,    23,    24,    25,    26,    30,
     308,     0,     1,     4,   217,   228,   230,   231,     4,     4,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     128,   129,   131,   133,   134,   135,   140,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   238,   240,   242,
     243,   245,   251,    69,   292,   215,    18,   173,   174,   214,
     302,   302,   215,   215,    17,    18,    19,    20,   201,   218,
       4,     4,     4,   323,   323,   323,   323,    81,   297,   323,
     323,   323,   323,   323,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   325,   326,   325,   325,   325,
     323,   323,    16,   285,    16,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   320,     6,   173,     9,   327,
     327,     6,   215,   215,   215,   215,    14,   202,   219,    65,
      85,   174,   215,   270,   286,   287,   303,   302,   302,   302,
     308,    66,    67,    68,    70,    71,    72,    73,    74,    75,
      76,    77,    83,    84,    86,   154,   174,   265,   266,   267,
     268,   269,   270,   271,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   299,   300,   301,   265,   267,
     302,   302,   172,   324,    16,   324,   324,   324,   215,   265,
     302,   215,   190,   191,   192,   193,     6,   328,   271,    14,
     203,   220,   285,    11,     5,     7,   305,     7,   305,   306,
     307,   302,   327,   302,   285,   285,   285,   285,   285,   285,
     308,    11,    18,    82,   277,   278,   280,   281,   282,   290,
     292,   293,   295,   297,   298,   299,   300,   301,   321,     7,
     304,   304,   304,   304,   302,   280,   327,   302,   323,   292,
     323,   323,   323,   255,   265,   269,   279,   286,   288,   302,
      10,    13,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   329,   215,    14,   204,   221,   283,
     290,   215,   215,   308,   215,   308,   327,   283,   285,   305,
      18,   175,   215,   274,   275,   281,   282,   317,   305,   305,
      15,   322,   215,   308,    16,   312,   308,   327,   327,   327,
     265,   265,   265,   265,   254,   281,   321,   215,   247,   254,
     327,   329,   305,    14,   205,   222,    12,    13,     6,    13,
       4,     8,    13,    13,    12,   308,   176,   177,   178,   179,
     181,   182,   183,   184,   185,   186,   187,   262,    21,    22,
      23,    24,    27,    29,    30,   309,   308,   308,   269,   286,
     287,     8,   190,   313,   308,   272,   273,   275,   276,   281,
     282,   291,   280,   273,   280,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   256,   322,   275,   281,
     215,   247,   275,   281,   304,    14,   215,   284,   215,   215,
     215,   215,   327,   305,   305,   307,   191,   314,   327,   305,
     274,   274,   280,   262,     5,     5,     5,   173,     5,     5,
       5,     5,   165,   327,   327,    18,   281,   275,   327,   327,
     308,     6,    13,    13,     8,   308,    16,   310,   308,   192,
     315,   308,   327,   327,   280,   324,   173,   173,   173,   170,
     171,   260,   173,   173,   173,   173,   215,   327,   327,   215,
     215,   190,   191,   192,   193,   311,   308,   310,   193,   316,
     327,   188,   263,    13,    13,    13,   167,   257,    13,    13,
      13,    13,   166,     8,     8,   311,   189,   264,   173,   173,
     173,   168,   258,   173,   173,   173,   173,   215,   311,    13,
      13,    13,   169,   259,    13,    13,    13,     6,   327,   311,
      21,    22,    30,   261,   173,   173,   173,   173,   173,     6,
      13,    13,     6,    13,    13,   173,   173,   173,   173,     6,
       6,    13,     6,    13,   173,   173,     6,    13,   173,     6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 625 "gram.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 626 "gram.y"
    { (yyval.integer) = -(yyvsp[(2) - (2)].integer);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 629 "gram.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 630 "gram.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) + (yyvsp[(3) - (3)].integer); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 631 "gram.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) - (yyvsp[(3) - (3)].integer); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 632 "gram.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) * (yyvsp[(3) - (3)].integer); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 633 "gram.y"
    { if ((yyvsp[(3) - (3)].integer)) (yyval.integer) = (yyvsp[(1) - (3)].integer) / (yyvsp[(3) - (3)].integer); else YYERROR;}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 634 "gram.y"
    { (yyval.integer) = -(yyvsp[(2) - (2)].integer);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 635 "gram.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 639 "gram.y"
    {
		  compiled_program = (yyvsp[(1) - (1)].program);
		}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 649 "gram.y"
    {
		   (yyval.reg) = (yyvsp[(3) - (3)].reg);
	       	}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 654 "gram.y"
    {
		   (yyval.integer) = (yyvsp[(3) - (3)].integer);
		}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 659 "gram.y"
    {
		  /* XXX is this default correct?*/
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = ffs(0);
		  (yyval.region).width = BRW_WIDTH_1;
		  (yyval.region).horiz_stride = ffs(0);
		}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 667 "gram.y"
    {
		    (yyval.region) = (yyvsp[(3) - (3)].region);
		}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 672 "gram.y"
    {
		    (yyval.integer) = 1;
		}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 676 "gram.y"
    {
		    (yyval.integer) = (yyvsp[(3) - (3)].integer);
		}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 681 "gram.y"
    {
		    (yyval.integer) = (yyvsp[(3) - (3)].regtype).type;
		}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 686 "gram.y"
    {
		    struct declared_register reg, *found, *new_reg;

		    reg.name = (yyvsp[(2) - (7)].string);
		    reg.reg = (yyvsp[(3) - (7)].reg);
		    reg.element_size = (yyvsp[(4) - (7)].integer);
		    reg.src_region = (yyvsp[(5) - (7)].region);
		    reg.dst_region = (yyvsp[(6) - (7)].integer);
		    reg.reg.type = (yyvsp[(7) - (7)].integer);

		    found = find_register((yyvsp[(2) - (7)].string));
		    if (found) {
		        if (!declared_register_equal(&reg, found))
			    error(&(yylsp[(1) - (7)]), "%s already defined and definitions "
				  "don't agree\n", (yyvsp[(2) - (7)].string));
			free((yyvsp[(2) - (7)].string)); // $2 has been malloc'ed by strdup
		    } else {
			new_reg = malloc(sizeof(struct declared_register));
			*new_reg = reg;
			insert_register(new_reg);
		    }
		}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 716 "gram.y"
    {
				    program_defaults.execute_size = (yyvsp[(2) - (2)].integer);
				}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 721 "gram.y"
    {
				    program_defaults.register_type = (yyvsp[(2) - (2)].regtype).type;
				}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 733 "gram.y"
    {
		    (yyval.program) = (yyvsp[(1) - (2)].program);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 737 "gram.y"
    {
		  brw_program_add_instruction(&(yyvsp[(1) - (3)].program), &(yyvsp[(2) - (3)].instruction));
		  (yyval.program) = (yyvsp[(1) - (3)].program);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 742 "gram.y"
    {
		  brw_program_init(&(yyval.program));
		  brw_program_add_instruction(&(yyval.program), &(yyvsp[(1) - (2)].instruction));
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 747 "gram.y"
    {
		  brw_program_add_relocatable(&(yyvsp[(1) - (3)].program), &(yyvsp[(2) - (3)].instruction));
		  (yyval.program) = (yyvsp[(1) - (3)].program);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 752 "gram.y"
    {
		  brw_program_init(&(yyval.program));
		  brw_program_add_relocatable(&(yyval.program), &(yyvsp[(1) - (2)].instruction));
		}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 757 "gram.y"
    {
		    (yyval.program) = (yyvsp[(1) - (2)].program);
		}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 761 "gram.y"
    {
		  brw_program_add_label(&(yyvsp[(1) - (2)].program), (yyvsp[(2) - (2)].string));
		  (yyval.program) = (yyvsp[(1) - (2)].program);
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 766 "gram.y"
    {
		  brw_program_init(&(yyval.program));
		  brw_program_add_label(&(yyval.program), (yyvsp[(1) - (1)].string));
		}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 771 "gram.y"
    {
		  (yyval.program).first = NULL;
		  (yyval.program).last = NULL;
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 775 "gram.y"
    {
		  (yyval.program) = (yyvsp[(1) - (3)].program);
		}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 804 "gram.y"
    {
		  // for Gen4 
		  if(IS_GENp(6)) // For gen6+.
		    error(&(yylsp[(1) - (1)]), "should be 'ENDIF execsize relativelocation'\n");
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (1)].integer));
		  GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		  GEN(&(yyval.instruction))->bits1.da1.dest_horiz_stride = 1;
		  GEN(&(yyval.instruction))->bits1.da1.src1_reg_file = BRW_ARCHITECTURE_REGISTER_FILE;
		  GEN(&(yyval.instruction))->bits1.da1.src1_reg_type = BRW_REGISTER_TYPE_UD;
		}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 816 "gram.y"
    {
		  // for Gen6+
		  /* Gen6, Gen7 bspec: predication is prohibited */
		  if(!IS_GENp(6)) // for gen6-
		    error(&(yylsp[(1) - (4)]), "ENDIF Syntax error: should be 'ENDIF'\n");
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (4)].integer));
		  set_execsize(&(yyval.instruction), (yyvsp[(2) - (4)].integer));
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(3) - (4)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(3) - (4)].src_operand).imm32;
		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 828 "gram.y"
    {
		  if(!IS_GENp(6)) {
		    // for Gen4, Gen5. gen_level < 60
		    /* Set the istack pop count, which must always be 1. */
		    (yyvsp[(3) - (4)].src_operand).imm32 |= (1 << 16);

		    memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		    set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (4)].integer));
		    GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		    ip_dst.width = (yyvsp[(2) - (4)].integer);
		    set_instruction_dest(&(yyval.instruction), &ip_dst);
		    set_instruction_src0(&(yyval.instruction), &ip_src, NULL);
		    set_instruction_src1(&(yyval.instruction), &(yyvsp[(3) - (4)].src_operand), NULL);
		    (yyval.instruction).reloc.first_reloc_target = (yyvsp[(3) - (4)].src_operand).reloc_target;
		    (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(3) - (4)].src_operand).imm32;
		  } else if(IS_GENp(6)) {
		    memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		    set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (4)].integer));
		    set_execsize(&(yyval.instruction), (yyvsp[(2) - (4)].integer));
		    (yyval.instruction).reloc.first_reloc_target = (yyvsp[(3) - (4)].src_operand).reloc_target;
		    (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(3) - (4)].src_operand).imm32;
		  } else {
		    error(&(yylsp[(1) - (4)]), "'ELSE' instruction is not implemented.\n");
		  }
		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 854 "gram.y"
    {
		  /* The branch instructions require that the IP register
		   * be the destination and first source operand, while the
		   * offset is the second source operand.  The offset is added
		   * to the pre-incremented IP.
		   */
		  if(IS_GENp(7)) /* Error in Gen7+. */
		    error(&(yylsp[(2) - (4)]), "IF should be 'IF execsize JIP UIP'\n");

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (4)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (4)].integer));
		  if(!IS_GENp(6)) {
		    GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		    ip_dst.width = (yyvsp[(3) - (4)].integer);
		    set_instruction_dest(&(yyval.instruction), &ip_dst);
		    set_instruction_src0(&(yyval.instruction), &ip_src, NULL);
		    set_instruction_src1(&(yyval.instruction), &(yyvsp[(4) - (4)].src_operand), NULL);
		  }
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (4)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (4)].src_operand).imm32;
		}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 877 "gram.y"
    {
		  /* for Gen7+ */
		  if(!IS_GENp(7))
		    error(&(yylsp[(2) - (5)]), "IF should be 'IF execsize relativelocation'\n");

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (5)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (5)].integer));
		  set_execsize(&(yyval.instruction), (yyvsp[(3) - (5)].integer));
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (5)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (5)].src_operand).imm32;
		  (yyval.instruction).reloc.second_reloc_target = (yyvsp[(5) - (5)].src_operand).reloc_target;
		  (yyval.instruction).reloc.second_reloc_offset = (yyvsp[(5) - (5)].src_operand).imm32;
		}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 894 "gram.y"
    {
		  if(!IS_GENp(6)) {
		    /* The branch instructions require that the IP register
		     * be the destination and first source operand, while the
		     * offset is the second source operand.  The offset is added
		     * to the pre-incremented IP.
		     */
		    ip_dst.width = (yyvsp[(3) - (5)].integer);
		    set_instruction_dest(&(yyval.instruction), &ip_dst);
		    memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		    set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (5)].predicate));
		    set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (5)].integer));
		    GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		    set_instruction_src0(&(yyval.instruction), &ip_src, NULL);
		    set_instruction_src1(&(yyval.instruction), &(yyvsp[(4) - (5)].src_operand), NULL);
		    (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (5)].src_operand).reloc_target;
		    (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (5)].src_operand).imm32;
		  } else if (IS_GENp(6)) {
		    /* Gen6 spec:
		         dest must have the same element size as src0.
		         dest horizontal stride must be 1. */
		    memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		    set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (5)].predicate));
		    set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (5)].integer));
		    set_execsize(&(yyval.instruction), (yyvsp[(3) - (5)].integer));
		    (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (5)].src_operand).reloc_target;
		    (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (5)].src_operand).imm32;
		  } else {
		    error(&(yylsp[(2) - (5)]), "'WHILE' instruction is not implemented!\n");
		  }
		}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 926 "gram.y"
    {
		  // deprecated
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (1)].integer));
		}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 933 "gram.y"
    {
		  // for Gen6, Gen7
		  /* Gen6, Gen7 bspec: dst and src0 must be the null reg. */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (6)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (6)].integer));
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (6)].src_operand).imm32;
		  (yyval.instruction).reloc.second_reloc_target = (yyvsp[(5) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.second_reloc_offset = (yyvsp[(5) - (6)].src_operand).imm32;
		  dst_null_reg.width = (yyvsp[(3) - (6)].integer);
		  set_instruction_dest(&(yyval.instruction), &dst_null_reg);
		  set_instruction_src0(&(yyval.instruction), &src_null_reg, NULL);
		}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 950 "gram.y"
    {
		  /* Gen7 bspec: dest must be null. use Switch option */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (5)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (5)].integer));
		  if (IS_GENp(8))
                      gen8_set_thread_control(GEN8(&(yyval.instruction)), gen8_thread_control(GEN8(&(yyval.instruction))) | BRW_THREAD_SWITCH);
		  else
                      GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (5)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (5)].src_operand).imm32;
		  dst_null_reg.width = (yyvsp[(3) - (5)].integer);
		  set_instruction_dest(&(yyval.instruction), &dst_null_reg);
		}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 965 "gram.y"
    {
		  /* Gen7 bspec: dest must be null. src0 must be null. use Switch option */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (6)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (6)].integer));
		  if (IS_GENp(8))
                      gen8_set_thread_control(GEN8(&(yyval.instruction)), gen8_thread_control(GEN8(&(yyval.instruction))) | BRW_THREAD_SWITCH);
		  else
                      GEN(&(yyval.instruction))->header.thread_control |= BRW_THREAD_SWITCH;
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (6)].src_operand).imm32;
		  (yyval.instruction).reloc.second_reloc_target = (yyvsp[(5) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.second_reloc_offset = (yyvsp[(5) - (6)].src_operand).imm32;
		  dst_null_reg.width = (yyvsp[(3) - (6)].integer);
		  set_instruction_dest(&(yyval.instruction), &dst_null_reg);
		  set_instruction_src0(&(yyval.instruction), &src_null_reg, NULL);
		}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 986 "gram.y"
    {
		  /*
		    Gen6 bspec:
		       source, dest type should be DWORD.
		       dest must be QWord aligned.
		       source0 region control must be <2,2,1>.
		       execution size must be 2.
		       QtrCtrl is prohibited.
		       JIP is an immediate operand, must be of type W.
		    Gen7 bspec:
		       source, dest type should be DWORD.
		       dest must be QWord aligned.
		       source0 region control must be <2,2,1>.
		       execution size must be 2.
		   */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (6)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (6)].integer));

		  (yyvsp[(4) - (6)].reg).type = BRW_REGISTER_TYPE_D; /* dest type should be DWORD */
		  (yyvsp[(4) - (6)].reg).width = BRW_WIDTH_2; /* execution size must be 2. */
		  set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (6)].reg));

		  struct src_operand src0;
		  memset(&src0, 0, sizeof(src0));
		  src0.reg.type = BRW_REGISTER_TYPE_D; /* source type should be DWORD */
		  /* source0 region control must be <2,2,1>. */
		  src0.reg.hstride = 1; /*encoded 1*/
		  src0.reg.width = BRW_WIDTH_2;
		  src0.reg.vstride = 2; /*encoded 2*/
		  set_instruction_src0(&(yyval.instruction), &src0, NULL);

		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(5) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(5) - (6)].src_operand).imm32;
		}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1022 "gram.y"
    {
		  /*
		     Gen6, 7:
		       source cannot be accumulator.
		       dest must be null.
		       src0 region control must be <2,2,1> (not specified clearly. should be same as CALL)
		   */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (6)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (6)].integer));
		  dst_null_reg.width = BRW_WIDTH_2; /* execution size of RET should be 2 */
		  set_instruction_dest(&(yyval.instruction), &dst_null_reg);
		  (yyvsp[(5) - (6)].src_operand).reg.type = BRW_REGISTER_TYPE_D;
		  (yyvsp[(5) - (6)].src_operand).reg.hstride = 1; /*encoded 1*/
		  (yyvsp[(5) - (6)].src_operand).reg.width = BRW_WIDTH_2;
		  (yyvsp[(5) - (6)].src_operand).reg.vstride = 2; /*encoded 2*/
		  set_instruction_src0(&(yyval.instruction), &(yyvsp[(5) - (6)].src_operand), NULL);
		}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1045 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));
		  set_instruction_saturate(&(yyval.instruction), (yyvsp[(4) - (8)].integer));
		  (yyvsp[(6) - (8)].reg).width = (yyvsp[(5) - (8)].integer);
		  set_instruction_options(&(yyval.instruction), (yyvsp[(8) - (8)].options));
		  set_instruction_pred_cond(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate), &(yyvsp[(3) - (8)].condition), &(yylsp[(3) - (8)]));
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(6) - (8)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(7) - (8)].src_operand), &(yylsp[(7) - (8)])) != 0)
		    YYERROR;

		  if (!IS_GENp(6) && 
				get_type_size(GEN(&(yyval.instruction))->bits1.da1.dest_reg_type) * (1 << (yyvsp[(6) - (8)].reg).width) == 64)
		    GEN(&(yyval.instruction))->header.compression_control = BRW_COMPRESSION_COMPRESSED;
		}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 1071 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (9)].integer));
		  set_instruction_saturate(&(yyval.instruction), (yyvsp[(4) - (9)].integer));
		  set_instruction_options(&(yyval.instruction), (yyvsp[(9) - (9)].options));
		  set_instruction_pred_cond(&(yyval.instruction), &(yyvsp[(1) - (9)].predicate), &(yyvsp[(3) - (9)].condition), &(yylsp[(3) - (9)]));
		  (yyvsp[(6) - (9)].reg).width = (yyvsp[(5) - (9)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(6) - (9)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(7) - (9)].src_operand), &(yylsp[(7) - (9)])) != 0)
		    YYERROR;
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(8) - (9)].src_operand), &(yylsp[(8) - (9)])) != 0)
		    YYERROR;

		  if (!IS_GENp(6) && 
				get_type_size(GEN(&(yyval.instruction))->bits1.da1.dest_reg_type) * (1 << (yyvsp[(6) - (9)].reg).width) == 64)
		    GEN(&(yyval.instruction))->header.compression_control = BRW_COMPRESSION_COMPRESSED;
		}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1099 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (9)].integer));
		  set_instruction_saturate(&(yyval.instruction), (yyvsp[(4) - (9)].integer));
		  (yyvsp[(6) - (9)].reg).width = (yyvsp[(5) - (9)].integer);
		  set_instruction_options(&(yyval.instruction), (yyvsp[(9) - (9)].options));
		  set_instruction_pred_cond(&(yyval.instruction), &(yyvsp[(1) - (9)].predicate), &(yyvsp[(3) - (9)].condition), &(yylsp[(3) - (9)]));
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(6) - (9)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(7) - (9)].src_operand), &(yylsp[(7) - (9)])) != 0)
		    YYERROR;
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(8) - (9)].src_operand), &(yylsp[(8) - (9)])) != 0)
		    YYERROR;

		  if (!IS_GENp(6) && 
				get_type_size(GEN(&(yyval.instruction))->bits1.da1.dest_reg_type) * (1 << (yyvsp[(6) - (9)].reg).width) == 64)
		    GEN(&(yyval.instruction))->header.compression_control = BRW_COMPRESSION_COMPRESSED;
		}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1129 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));

		  set_instruction_pred_cond(&(yyval.instruction), &(yyvsp[(1) - (10)].predicate), &(yyvsp[(3) - (10)].condition), &(yylsp[(3) - (10)]));

		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (10)].integer));
		  set_instruction_saturate(&(yyval.instruction), (yyvsp[(4) - (10)].integer));

		  (yyvsp[(6) - (10)].reg).width = (yyvsp[(5) - (10)].integer);
		  if (set_instruction_dest_three_src(&(yyval.instruction), &(yyvsp[(6) - (10)].reg)))
		    YYERROR;
		  if (set_instruction_src0_three_src(&(yyval.instruction), &(yyvsp[(7) - (10)].src_operand)))
		    YYERROR;
		  if (set_instruction_src1_three_src(&(yyval.instruction), &(yyvsp[(8) - (10)].src_operand)))
		    YYERROR;
		  if (set_instruction_src2_three_src(&(yyval.instruction), &(yyvsp[(9) - (10)].src_operand)))
		    YYERROR;
		  set_instruction_options(&(yyval.instruction), (yyvsp[(10) - (10)].options));
}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1155 "gram.y"
    {
		  /* Send instructions are messy.  The first argument is the
		   * post destination -- the grf register that the response
		   * starts from.  The second argument is the current
		   * destination, which is the start of the message arguments
		   * to the shared function, and where src0 payload is loaded
		   * to if not null.  The payload is typically based on the
		   * grf 0 thread payload of your current thread, and is
		   * implicitly loaded if non-null.
		   */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (12)].integer));
		  (yyvsp[(5) - (12)].reg).width = (yyvsp[(3) - (12)].integer);
		  GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(4) - (12)].integer); /* msg reg index */
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (12)].predicate));
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(5) - (12)].reg)) != 0)
		    YYERROR;

		  if (IS_GENp(6)) {
                      struct src_operand src0;

                      memset(&src0, 0, sizeof(src0));
                      src0.reg.address_mode = BRW_ADDRESS_DIRECT;

                      if (IS_GENp(7))
                          src0.reg.file = BRW_GENERAL_REGISTER_FILE;
                      else
                          src0.reg.file = BRW_MESSAGE_REGISTER_FILE;

                      src0.reg.type = BRW_REGISTER_TYPE_D;
                      src0.reg.nr = (yyvsp[(4) - (12)].integer);
                      src0.reg.subnr = 0;
                      set_instruction_src0(&(yyval.instruction), &src0, NULL);
		  } else {
                      if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(6) - (12)].src_operand), &(yylsp[(6) - (12)])) != 0)
                          YYERROR;
		  }

		  if (IS_GENp(8)) {
		      gen8_set_src1_reg_file(GEN8(&(yyval.instruction)), BRW_IMMEDIATE_VALUE);
		      gen8_set_src1_reg_type(GEN8(&(yyval.instruction)), BRW_REGISTER_TYPE_D);
		  } else {
		      GEN(&(yyval.instruction))->bits1.da1.src1_reg_file = BRW_IMMEDIATE_VALUE;
		      GEN(&(yyval.instruction))->bits1.da1.src1_reg_type = BRW_REGISTER_TYPE_D;
		  }

		  if (IS_GENp(8)) {
		      GEN8(&(yyval.instruction))->data[3] = GEN8(&(yyvsp[(7) - (12)].instruction))->data[3];
		      gen8_set_sfid(GEN8(&(yyval.instruction)), gen8_sfid(GEN8(&(yyvsp[(7) - (12)].instruction))));
		      gen8_set_mlen(GEN8(&(yyval.instruction)), (yyvsp[(9) - (12)].integer));
		      gen8_set_rlen(GEN8(&(yyval.instruction)), (yyvsp[(11) - (12)].integer));
		      gen8_set_eot(GEN8(&(yyval.instruction)), (yyvsp[(12) - (12)].options).end_of_thread);
		  } else if (IS_GENp(5)) {
                      if (IS_GENp(6)) {
                          GEN(&(yyval.instruction))->header.destreg__conditionalmod = GEN(&(yyvsp[(7) - (12)].instruction))->bits2.send_gen5.sfid;
                      } else {
                          GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(4) - (12)].integer); /* msg reg index */
                          GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN(&(yyvsp[(7) - (12)].instruction))->bits2.send_gen5.sfid;
                          GEN(&(yyval.instruction))->bits2.send_gen5.end_of_thread = (yyvsp[(12) - (12)].options).end_of_thread;
                      }

                      GEN(&(yyval.instruction))->bits3.generic_gen5 = GEN(&(yyvsp[(7) - (12)].instruction))->bits3.generic_gen5;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.msg_length = (yyvsp[(9) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.generic_gen5.response_length = (yyvsp[(11) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.generic_gen5.end_of_thread = (yyvsp[(12) - (12)].options).end_of_thread;
		  } else {
                      GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(4) - (12)].integer); /* msg reg index */
                      GEN(&(yyval.instruction))->bits3.generic = GEN(&(yyvsp[(7) - (12)].instruction))->bits3.generic;
                      GEN(&(yyval.instruction))->bits3.generic.msg_length = (yyvsp[(9) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.generic.response_length = (yyvsp[(11) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.generic.end_of_thread = (yyvsp[(12) - (12)].options).end_of_thread;
		  }
		}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1229 "gram.y"
    {
		  if (IS_GENp(6))
                      error(&(yylsp[(2) - (8)]), "invalid syntax for send on gen6+\n");

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));
		  GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(5) - (8)].reg).nr; /* msg reg index */

		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate));

		  (yyvsp[(4) - (8)].reg).width = (yyvsp[(3) - (8)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (8)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(6) - (8)].src_operand), &(yylsp[(6) - (8)])) != 0)
		    YYERROR;
		  /* XXX is this correct? */
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(7) - (8)].src_operand), &(yylsp[(7) - (8)])) != 0)
		    YYERROR;

		  }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1250 "gram.y"
    {
		  if (IS_GENp(6))
                      error(&(yylsp[(2) - (8)]), "invalid syntax for send on gen6+\n");

		  if ((yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_UD &&
		      (yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_D &&
		      (yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_V) {
		    error (&(yylsp[(7) - (8)]), "non-int D/UD/V representation: %d,"
			   "type=%d\n", (yyvsp[(7) - (8)].src_operand).reg.dw1.ud, (yyvsp[(7) - (8)].src_operand).reg.type);
		  }
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));
		  GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(5) - (8)].reg).nr; /* msg reg index */

		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate));
		  (yyvsp[(4) - (8)].reg).width = (yyvsp[(3) - (8)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (8)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(6) - (8)].src_operand), &(yylsp[(6) - (8)])) != 0)
		    YYERROR;
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(7) - (8)].src_operand), &(yylsp[(7) - (8)])) != 0)
		    YYERROR;
                }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1274 "gram.y"
    {
		  struct src_operand src0;

		  if (!IS_GENp(6))
                      error(&(yylsp[(2) - (8)]), "invalid syntax for send on gen6+\n");

		  if ((yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_UD &&
                      (yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_D &&
                      (yyvsp[(7) - (8)].src_operand).reg.type != BRW_REGISTER_TYPE_V) {
                      error(&(yylsp[(7) - (8)]),"non-int D/UD/V representation: %d,"
			    "type=%d\n", (yyvsp[(7) - (8)].src_operand).reg.dw1.ud, (yyvsp[(7) - (8)].src_operand).reg.type);
		  }

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate));

		  (yyvsp[(4) - (8)].reg).width = (yyvsp[(3) - (8)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (8)].reg)) != 0)
                      YYERROR;

                  memset(&src0, 0, sizeof(src0));
                  src0.reg.address_mode = BRW_ADDRESS_DIRECT;

                  if (IS_GENp(7)) {
                      src0.reg.file = BRW_GENERAL_REGISTER_FILE;
                      src0.reg.type = BRW_REGISTER_TYPE_UB;
                  } else {
                      src0.reg.file = BRW_MESSAGE_REGISTER_FILE;
                      src0.reg.type = BRW_REGISTER_TYPE_D;
                  }

                  src0.reg.nr = (yyvsp[(5) - (8)].reg).nr;
                  src0.reg.subnr = 0;
                  set_instruction_src0(&(yyval.instruction), &src0, NULL);
		  set_instruction_src1(&(yyval.instruction), &(yyvsp[(7) - (8)].src_operand), NULL);

                  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), (yyvsp[(6) - (8)].integer) & EX_DESC_SFID_MASK);
                      gen8_set_eot(GEN8(&(yyval.instruction)), !!((yyvsp[(6) - (8)].integer) & EX_DESC_EOT_MASK));
		  } else {
                      GEN(&(yyval.instruction))->header.destreg__conditionalmod = ((yyvsp[(6) - (8)].integer) & EX_DESC_SFID_MASK); /* SFID */
                      GEN(&(yyval.instruction))->bits3.generic_gen5.end_of_thread = !!((yyvsp[(6) - (8)].integer) & EX_DESC_EOT_MASK);
                  }
		}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1320 "gram.y"
    {
		  struct src_operand src0;

		  if (!IS_GENp(6))
                      error(&(yylsp[(2) - (8)]), "invalid syntax for send on gen6+\n");

                  if ((yyvsp[(7) - (8)].src_operand).reg.file != BRW_ARCHITECTURE_REGISTER_FILE ||
                      ((yyvsp[(7) - (8)].src_operand).reg.nr & 0xF0) != BRW_ARF_ADDRESS ||
                      ((yyvsp[(7) - (8)].src_operand).reg.nr & 0x0F) != 0 ||
                      (yyvsp[(7) - (8)].src_operand).reg.subnr != 0) {
                      error (&(yylsp[(7) - (8)]), "scalar register must be a0.0<0;1,0>:ud\n");
		  }

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate));

		  (yyvsp[(4) - (8)].reg).width = (yyvsp[(3) - (8)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (8)].reg)) != 0)
                      YYERROR;

                  memset(&src0, 0, sizeof(src0));
                  src0.reg.address_mode = BRW_ADDRESS_DIRECT;

                  if (IS_GENp(7)) {
                      src0.reg.file = BRW_GENERAL_REGISTER_FILE;
                      src0.reg.type = BRW_REGISTER_TYPE_UB;
                  } else {
                      src0.reg.file = BRW_MESSAGE_REGISTER_FILE;
                      src0.reg.type = BRW_REGISTER_TYPE_D;
                  }

                  src0.reg.nr = (yyvsp[(5) - (8)].reg).nr;
                  src0.reg.subnr = 0;
                  set_instruction_src0(&(yyval.instruction), &src0, NULL);

                  set_instruction_src1(&(yyval.instruction), &(yyvsp[(7) - (8)].src_operand), &(yylsp[(7) - (8)]));

                  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), (yyvsp[(6) - (8)].integer) & EX_DESC_SFID_MASK);
                      gen8_set_eot(GEN8(&(yyval.instruction)), !!((yyvsp[(6) - (8)].integer) & EX_DESC_EOT_MASK));
		  } else {
                      GEN(&(yyval.instruction))->header.destreg__conditionalmod = ((yyvsp[(6) - (8)].integer) & EX_DESC_SFID_MASK); /* SFID */
                      GEN(&(yyval.instruction))->bits3.generic_gen5.end_of_thread = !!((yyvsp[(6) - (8)].integer) & EX_DESC_EOT_MASK);
                  }
		}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1367 "gram.y"
    {
		  if (IS_GENp(6))
                      error(&(yylsp[(2) - (9)]), "invalid syntax for send on gen6+\n");

		  if ((yyvsp[(8) - (9)].src_operand).reg.type != BRW_REGISTER_TYPE_UD &&
		      (yyvsp[(8) - (9)].src_operand).reg.type != BRW_REGISTER_TYPE_D &&
		      (yyvsp[(8) - (9)].src_operand).reg.type != BRW_REGISTER_TYPE_V) {
		    error(&(yylsp[(8) - (9)]), "non-int D/UD/V representation: %d,"
			  "type=%d\n", (yyvsp[(8) - (9)].src_operand).reg.dw1.ud, (yyvsp[(8) - (9)].src_operand).reg.type);
		  }
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (9)].integer));
		  GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(5) - (9)].reg).nr; /* msg reg index */

		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (9)].predicate));
		  (yyvsp[(4) - (9)].reg).width = (yyvsp[(3) - (9)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (9)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(6) - (9)].src_operand), &(yylsp[(6) - (9)])) != 0)
		    YYERROR;
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(8) - (9)].src_operand), &(yylsp[(8) - (9)])) != 0)
		    YYERROR;

		  if (IS_GENx(5)) {
		      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = ((yyvsp[(7) - (9)].integer) & EX_DESC_SFID_MASK);
		      GEN(&(yyval.instruction))->bits3.generic_gen5.end_of_thread = !!((yyvsp[(7) - (9)].integer) & EX_DESC_EOT_MASK);
		  }
		}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1396 "gram.y"
    {
		  if (IS_GENp(6))
                      error(&(yylsp[(2) - (9)]), "invalid syntax for send on gen6+\n");

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (9)].integer));
		  GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(5) - (9)].reg).nr; /* msg reg index */

		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (9)].predicate));

		  (yyvsp[(4) - (9)].reg).width = (yyvsp[(3) - (9)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (9)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(6) - (9)].src_operand), &(yylsp[(6) - (9)])) != 0)
		    YYERROR;
		  /* XXX is this correct? */
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(8) - (9)].src_operand), &(yylsp[(8) - (9)])) != 0)
		    YYERROR;
		  if (IS_GENx(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = (yyvsp[(7) - (9)].integer);
		  }
		}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1422 "gram.y"
    {
			(yyval.integer) = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1428 "gram.y"
    {
		  /* The jump instruction requires that the IP register
		   * be the destination and first source operand, while the
		   * offset is the second source operand.  The next instruction
		   * is the post-incremented IP plus the offset.
		   */
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (4)].integer));
		  if(advanced_flag) {
                      if (IS_GENp(8))
                          gen8_set_mask_control(GEN8(&(yyval.instruction)), BRW_MASK_DISABLE);
                      else
                          GEN(&(yyval.instruction))->header.mask_control = BRW_MASK_DISABLE;
		  }
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (4)].predicate));
		  ip_dst.width = BRW_WIDTH_1;
		  set_instruction_dest(&(yyval.instruction), &ip_dst);
		  set_instruction_src0(&(yyval.instruction), &ip_src, NULL);
		  set_instruction_src1(&(yyval.instruction), &(yyvsp[(4) - (4)].src_operand), NULL);
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (4)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (4)].src_operand).imm32;
		}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1453 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (8)].integer));

		  if (IS_GENp(8))
                      gen8_set_math_function(GEN8(&(yyval.instruction)), (yyvsp[(7) - (8)].integer));
		  else
                      GEN(&(yyval.instruction))->header.destreg__conditionalmod = (yyvsp[(7) - (8)].integer);

		  set_instruction_options(&(yyval.instruction), (yyvsp[(8) - (8)].options));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (8)].predicate));
		  (yyvsp[(4) - (8)].reg).width = (yyvsp[(3) - (8)].integer);
		  if (set_instruction_dest(&(yyval.instruction), &(yyvsp[(4) - (8)].reg)) != 0)
		    YYERROR;
		  if (set_instruction_src0(&(yyval.instruction), &(yyvsp[(5) - (8)].src_operand), &(yylsp[(5) - (8)])) != 0)
		    YYERROR;
		  if (set_instruction_src1(&(yyval.instruction), &(yyvsp[(6) - (8)].src_operand), &(yylsp[(6) - (8)])) != 0)
		    YYERROR;
		}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1475 "gram.y"
    {
		  // for Gen6, Gen7
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_predicate(&(yyval.instruction), &(yyvsp[(1) - (6)].predicate));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (6)].integer));
		  set_execsize(&(yyval.instruction), (yyvsp[(3) - (6)].integer));
		  (yyval.instruction).reloc.first_reloc_target = (yyvsp[(4) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.first_reloc_offset = (yyvsp[(4) - (6)].src_operand).imm32;
		  (yyval.instruction).reloc.second_reloc_target = (yyvsp[(5) - (6)].src_operand).reloc_target;
		  (yyval.instruction).reloc.second_reloc_offset = (yyvsp[(5) - (6)].src_operand).imm32;
		}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1497 "gram.y"
    {
		  struct brw_reg notify_dst;
		  struct src_operand notify_src;

		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(2) - (3)].integer));
		  set_direct_dst_operand(&notify_dst, &(yyvsp[(3) - (3)].reg), BRW_REGISTER_TYPE_D);
		  notify_dst.width = BRW_WIDTH_1;
		  set_instruction_dest(&(yyval.instruction), &notify_dst);
		  set_direct_src_operand(&notify_src, &(yyvsp[(3) - (3)].reg), BRW_REGISTER_TYPE_D);
		  set_instruction_src0(&(yyval.instruction), &notify_src, NULL);
		  set_instruction_src1(&(yyval.instruction), &src_null_reg, NULL);
		}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1514 "gram.y"
    {
		  memset(&(yyval.instruction), 0, sizeof((yyval.instruction)));
		  set_instruction_opcode(&(yyval.instruction), (yyvsp[(1) - (1)].integer));
		}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1527 "gram.y"
    {
		  if (IS_GENp(8)) {
		      gen8_set_sfid(GEN8(&(yyval.instruction)), BRW_SFID_NULL);
		      gen8_set_header_present(GEN8(&(yyval.instruction)), 0);
		  } else if (IS_GENp(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid= BRW_SFID_NULL;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 0;  /* ??? */
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_NULL;
		  }
		}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1540 "gram.y"
    {
		  if (IS_GENp(8)) {
		      gen8_set_sfid(GEN8(&(yyval.instruction)), BRW_SFID_SAMPLER);
		      gen8_set_header_present(GEN8(&(yyval.instruction)), 1); /* ??? */
		      gen8_set_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (8)].integer));
		      gen8_set_sampler(GEN8(&(yyval.instruction)), (yyvsp[(5) - (8)].integer));
		      gen8_set_sampler_simd_mode(GEN8(&(yyval.instruction)), 2); /* SIMD16 */
		  } else if (IS_GENp(7)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = BRW_SFID_SAMPLER;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;   /* ??? */
                      GEN(&(yyval.instruction))->bits3.sampler_gen7.binding_table_index = (yyvsp[(3) - (8)].integer);
                      GEN(&(yyval.instruction))->bits3.sampler_gen7.sampler = (yyvsp[(5) - (8)].integer);
                      GEN(&(yyval.instruction))->bits3.sampler_gen7.simd_mode = 2; /* SIMD16, maybe we should add a new parameter */
		  } else if (IS_GENp(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = BRW_SFID_SAMPLER;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;   /* ??? */
                      GEN(&(yyval.instruction))->bits3.sampler_gen5.binding_table_index = (yyvsp[(3) - (8)].integer);
                      GEN(&(yyval.instruction))->bits3.sampler_gen5.sampler = (yyvsp[(5) - (8)].integer);
                      GEN(&(yyval.instruction))->bits3.sampler_gen5.simd_mode = 2; /* SIMD16, maybe we should add a new parameter */
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_SAMPLER;
                      GEN(&(yyval.instruction))->bits3.sampler.binding_table_index = (yyvsp[(3) - (8)].integer);
                      GEN(&(yyval.instruction))->bits3.sampler.sampler = (yyvsp[(5) - (8)].integer);
                      switch ((yyvsp[(7) - (8)].integer)) {
                      case TYPE_F:
                          GEN(&(yyval.instruction))->bits3.sampler.return_format =
                              BRW_SAMPLER_RETURN_FORMAT_FLOAT32;
                          break;
                      case TYPE_UD:
                          GEN(&(yyval.instruction))->bits3.sampler.return_format =
                              BRW_SAMPLER_RETURN_FORMAT_UINT32;
                          break;
                      case TYPE_D:
                          GEN(&(yyval.instruction))->bits3.sampler.return_format =
                              BRW_SAMPLER_RETURN_FORMAT_SINT32;
                          break;
                      }
		  }
		}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1580 "gram.y"
    {
		  if (IS_GENp(6)) {
                      error (&(yylsp[(1) - (5)]), "Gen6+ doesn't have math function\n");
		  } else if (IS_GENx(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = BRW_SFID_MATH;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 0;
                      GEN(&(yyval.instruction))->bits3.math_gen5.function = (yyvsp[(2) - (5)].integer);
		      set_instruction_saturate(&(yyval.instruction), (yyvsp[(3) - (5)].integer));
                      GEN(&(yyval.instruction))->bits3.math_gen5.int_type = (yyvsp[(4) - (5)].integer);
                      GEN(&(yyval.instruction))->bits3.math_gen5.precision = BRW_MATH_PRECISION_FULL;
                      GEN(&(yyval.instruction))->bits3.math_gen5.data_type = (yyvsp[(5) - (5)].integer);
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_MATH;
                      GEN(&(yyval.instruction))->bits3.math.function = (yyvsp[(2) - (5)].integer);
		      set_instruction_saturate(&(yyval.instruction), (yyvsp[(3) - (5)].integer));
                      GEN(&(yyval.instruction))->bits3.math.int_type = (yyvsp[(4) - (5)].integer);
                      GEN(&(yyval.instruction))->bits3.math.precision = BRW_MATH_PRECISION_FULL;
                      GEN(&(yyval.instruction))->bits3.math.data_type = (yyvsp[(5) - (5)].integer);
		  }
		}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1601 "gram.y"
    {
		  if (IS_GENp(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = BRW_SFID_MESSAGE_GATEWAY;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 0;  /* ??? */
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_MESSAGE_GATEWAY;
		  }
		}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1611 "gram.y"
    {
		  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), GEN6_SFID_DATAPORT_SAMPLER_CACHE);
                      gen8_set_header_present(GEN8(&(yyval.instruction)), 1);
                      gen8_set_dp_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (10)].integer));
                      gen8_set_dp_message_control(GEN8(&(yyval.instruction)), (yyvsp[(7) - (10)].integer));
                      gen8_set_dp_message_type(GEN8(&(yyval.instruction)), (yyvsp[(9) - (10)].integer));
                      gen8_set_dp_category(GEN8(&(yyval.instruction)), 0);
		  } else if (IS_GENx(7)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                          GEN6_SFID_DATAPORT_SAMPLER_CACHE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.gen7_dp.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_control = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_type = (yyvsp[(9) - (10)].integer);
		  } else if (IS_GENx(6)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                          GEN6_SFID_DATAPORT_SAMPLER_CACHE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.gen6_dp_sampler_const_cache.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp_sampler_const_cache.msg_control = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp_sampler_const_cache.msg_type = (yyvsp[(9) - (10)].integer);
		  } else if (IS_GENx(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                          BRW_SFID_DATAPORT_READ;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.dp_read_gen5.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read_gen5.target_cache = (yyvsp[(5) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read_gen5.msg_control = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read_gen5.msg_type = (yyvsp[(9) - (10)].integer);
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target =
                          BRW_SFID_DATAPORT_READ;
                      GEN(&(yyval.instruction))->bits3.dp_read.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read.target_cache = (yyvsp[(5) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read.msg_control = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_read.msg_type = (yyvsp[(9) - (10)].integer);
		  }
		}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1652 "gram.y"
    {
		  if (IS_GENp(8)) {
                      if ((yyvsp[(9) - (10)].integer) != 0 &&
			  (yyvsp[(9) - (10)].integer) != GEN6_SFID_DATAPORT_RENDER_CACHE &&
			  (yyvsp[(9) - (10)].integer) != GEN7_SFID_DATAPORT_DATA_CACHE &&
			  (yyvsp[(9) - (10)].integer) != HSW_SFID_DATAPORT_DATA_CACHE1) {
			  error (&(yylsp[(9) - (10)]), "error: wrong cache type\n");
		      }

		      if ((yyvsp[(9) - (10)].integer) == 0)
			  gen8_set_sfid(GEN8(&(yyval.instruction)), GEN6_SFID_DATAPORT_RENDER_CACHE);
		      else
			  gen8_set_sfid(GEN8(&(yyval.instruction)), (yyvsp[(9) - (10)].integer));

                      gen8_set_header_present(GEN8(&(yyval.instruction)), 1);
                      gen8_set_dp_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (10)].integer));
                      gen8_set_dp_message_control(GEN8(&(yyval.instruction)), (yyvsp[(5) - (10)].integer));
                      gen8_set_dp_message_type(GEN8(&(yyval.instruction)), (yyvsp[(7) - (10)].integer));
                      gen8_set_dp_category(GEN8(&(yyval.instruction)), 0);
		  } else if (IS_GENx(7)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN6_SFID_DATAPORT_RENDER_CACHE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.gen7_dp.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_control = (yyvsp[(5) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_type = (yyvsp[(7) - (10)].integer);
                  } else if (IS_GENx(6)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN6_SFID_DATAPORT_RENDER_CACHE;
                      /* Sandybridge supports headerlesss message for render target write.
                       * Currently the GFX assembler doesn't support it. so the program must provide 
                       * message header
                       */
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.gen6_dp.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp.msg_control = (yyvsp[(5) - (10)].integer);
                     GEN(&(yyval.instruction))->bits3.gen6_dp.msg_type = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp.send_commit_msg = (yyvsp[(9) - (10)].integer);
		  } else if (IS_GENx(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                          BRW_SFID_DATAPORT_WRITE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.last_render_target = ((yyvsp[(5) - (10)].integer) & 0x8) >> 3;
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.msg_control = (yyvsp[(5) - (10)].integer) & 0x7;
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.msg_type = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.send_commit_msg = (yyvsp[(9) - (10)].integer);
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target =
                          BRW_SFID_DATAPORT_WRITE;
                      GEN(&(yyval.instruction))->bits3.dp_write.binding_table_index = (yyvsp[(3) - (10)].integer);
                      /* The msg control field of brw_struct.h is split into
                       * msg control and last_render_target, even though
                       * last_render_target isn't common to all write messages.
                       */
                      GEN(&(yyval.instruction))->bits3.dp_write.last_render_target = ((yyvsp[(5) - (10)].integer) & 0x8) >> 3;
                      GEN(&(yyval.instruction))->bits3.dp_write.msg_control = (yyvsp[(5) - (10)].integer) & 0x7;
                      GEN(&(yyval.instruction))->bits3.dp_write.msg_type = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write.send_commit_msg = (yyvsp[(9) - (10)].integer);
		  }
		}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1713 "gram.y"
    {
		  if (IS_GENp(8)) {
                      if ((yyvsp[(9) - (12)].integer) != 0 &&
			  (yyvsp[(9) - (12)].integer) != GEN6_SFID_DATAPORT_RENDER_CACHE &&
			  (yyvsp[(9) - (12)].integer) != GEN7_SFID_DATAPORT_DATA_CACHE &&
			  (yyvsp[(9) - (12)].integer) != HSW_SFID_DATAPORT_DATA_CACHE1) {
			  error (&(yylsp[(9) - (12)]), "error: wrong cache type\n");
		      }

		      if ((yyvsp[(9) - (12)].integer) == 0)
			  gen8_set_sfid(GEN8(&(yyval.instruction)), GEN6_SFID_DATAPORT_RENDER_CACHE);
		      else
			  gen8_set_sfid(GEN8(&(yyval.instruction)), (yyvsp[(9) - (12)].integer));

                      gen8_set_header_present(GEN8(&(yyval.instruction)), ((yyvsp[(11) - (12)].integer) != 0));
                      gen8_set_dp_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (12)].integer));
                      gen8_set_dp_message_control(GEN8(&(yyval.instruction)), (yyvsp[(5) - (12)].integer));
                      gen8_set_dp_message_type(GEN8(&(yyval.instruction)), (yyvsp[(7) - (12)].integer));
                      gen8_set_dp_category(GEN8(&(yyval.instruction)), 0);
		  } else if (IS_GENx(7)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN6_SFID_DATAPORT_RENDER_CACHE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = ((yyvsp[(11) - (12)].integer) != 0);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.binding_table_index = (yyvsp[(3) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_control = (yyvsp[(5) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.gen7_dp.msg_type = (yyvsp[(7) - (12)].integer);
		  } else if (IS_GENx(6)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN6_SFID_DATAPORT_RENDER_CACHE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = ((yyvsp[(11) - (12)].integer) != 0);
                      GEN(&(yyval.instruction))->bits3.gen6_dp.binding_table_index = (yyvsp[(3) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp.msg_control = (yyvsp[(5) - (12)].integer);
                     GEN(&(yyval.instruction))->bits3.gen6_dp.msg_type = (yyvsp[(7) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.gen6_dp.send_commit_msg = (yyvsp[(9) - (12)].integer);
		  } else if (IS_GENx(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                          BRW_SFID_DATAPORT_WRITE;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = ((yyvsp[(11) - (12)].integer) != 0);
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.binding_table_index = (yyvsp[(3) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.last_render_target = ((yyvsp[(5) - (12)].integer) & 0x8) >> 3;
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.msg_control = (yyvsp[(5) - (12)].integer) & 0x7;
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.msg_type = (yyvsp[(7) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write_gen5.send_commit_msg = (yyvsp[(9) - (12)].integer);
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target =
                          BRW_SFID_DATAPORT_WRITE;
                      GEN(&(yyval.instruction))->bits3.dp_write.binding_table_index = (yyvsp[(3) - (12)].integer);
                      /* The msg control field of brw_struct.h is split into
                       * msg control and last_render_target, even though
                       * last_render_target isn't common to all write messages.
                       */
                      GEN(&(yyval.instruction))->bits3.dp_write.last_render_target = ((yyvsp[(5) - (12)].integer) & 0x8) >> 3;
                      GEN(&(yyval.instruction))->bits3.dp_write.msg_control = (yyvsp[(5) - (12)].integer) & 0x7;
                      GEN(&(yyval.instruction))->bits3.dp_write.msg_type = (yyvsp[(7) - (12)].integer);
                      GEN(&(yyval.instruction))->bits3.dp_write.send_commit_msg = (yyvsp[(9) - (12)].integer);
		  }
		}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1769 "gram.y"
    {
		  GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_URB;
		  if (IS_GENp(5)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = BRW_SFID_URB;
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
		      set_instruction_opcode(&(yyval.instruction), BRW_URB_OPCODE_WRITE);
                      GEN(&(yyval.instruction))->bits3.urb_gen5.offset = (yyvsp[(2) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb_gen5.swizzle_control = (yyvsp[(3) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb_gen5.pad = 0;
                      GEN(&(yyval.instruction))->bits3.urb_gen5.allocate = (yyvsp[(4) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb_gen5.used = (yyvsp[(5) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb_gen5.complete = (yyvsp[(6) - (6)].integer);
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target = BRW_SFID_URB;
		      set_instruction_opcode(&(yyval.instruction), BRW_URB_OPCODE_WRITE);
                      GEN(&(yyval.instruction))->bits3.urb.offset = (yyvsp[(2) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb.swizzle_control = (yyvsp[(3) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb.pad = 0;
                      GEN(&(yyval.instruction))->bits3.urb.allocate = (yyvsp[(4) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb.used = (yyvsp[(5) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.urb.complete = (yyvsp[(6) - (6)].integer);
		  }
		}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1794 "gram.y"
    {
		  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), BRW_SFID_THREAD_SPAWNER);
                      gen8_set_header_present(GEN8(&(yyval.instruction)), 0); /* Must be 0 */
                      gen8_set_ts_opcode(GEN8(&(yyval.instruction)), (yyvsp[(3) - (8)].integer));
                      gen8_set_ts_request_type(GEN8(&(yyval.instruction)), (yyvsp[(5) - (8)].integer));
                      gen8_set_ts_resource_select(GEN8(&(yyval.instruction)), (yyvsp[(7) - (8)].integer));
		  } else {
                      GEN(&(yyval.instruction))->bits3.generic.msg_target =
                          BRW_SFID_THREAD_SPAWNER;
                      if (IS_GENp(5)) {
                          GEN(&(yyval.instruction))->bits2.send_gen5.sfid =
                              BRW_SFID_THREAD_SPAWNER;
                          GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 0;
                          GEN(&(yyval.instruction))->bits3.thread_spawner_gen5.opcode = (yyvsp[(3) - (8)].integer);
                          GEN(&(yyval.instruction))->bits3.thread_spawner_gen5.requester_type  = (yyvsp[(5) - (8)].integer);
                          GEN(&(yyval.instruction))->bits3.thread_spawner_gen5.resource_select = (yyvsp[(7) - (8)].integer);
                      } else {
                          GEN(&(yyval.instruction))->bits3.generic.msg_target =
                              BRW_SFID_THREAD_SPAWNER;
                          GEN(&(yyval.instruction))->bits3.thread_spawner.opcode = (yyvsp[(3) - (8)].integer);
                          GEN(&(yyval.instruction))->bits3.thread_spawner.requester_type  = (yyvsp[(5) - (8)].integer);
                          GEN(&(yyval.instruction))->bits3.thread_spawner.resource_select = (yyvsp[(7) - (8)].integer);
                      }
		  }
		}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1821 "gram.y"
    {
		  GEN(&(yyval.instruction))->bits3.generic.msg_target = GEN6_SFID_VME;

		  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), GEN6_SFID_VME);
                      gen8_set_header_present(GEN8(&(yyval.instruction)), 1); /* Must be 1 */
                      gen8_set_vme_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (10)].integer));
                      gen8_set_vme_message_type(GEN8(&(yyval.instruction)), (yyvsp[(9) - (10)].integer));
		  } else if (IS_GENp(6)) {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = GEN6_SFID_VME;
                      GEN(&(yyval.instruction))->bits3.vme_gen6.binding_table_index = (yyvsp[(3) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.vme_gen6.search_path_index = (yyvsp[(5) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.vme_gen6.lut_subindex = (yyvsp[(7) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.vme_gen6.message_type = (yyvsp[(9) - (10)].integer);
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
		  } else {
                      error (&(yylsp[(1) - (10)]), "Gen6- doesn't have vme function\n");
		  }    
		}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1841 "gram.y"
    {
		  if (IS_GENp(8)) {
                      gen8_set_sfid(GEN8(&(yyval.instruction)), HSW_SFID_CRE);
                      gen8_set_header_present(GEN8(&(yyval.instruction)), 1); /* Must be 1 */
                      gen8_set_cre_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(3) - (6)].integer));
                      gen8_set_cre_message_type(GEN8(&(yyval.instruction)), (yyvsp[(5) - (6)].integer));
		  } else {
                      if (gen_level < 75)
                          error (&(yylsp[(1) - (6)]), "Below Gen7.5 doesn't have CRE function\n");

                      GEN(&(yyval.instruction))->bits3.generic.msg_target = HSW_SFID_CRE;

                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = HSW_SFID_CRE;
                      GEN(&(yyval.instruction))->bits3.cre_gen75.binding_table_index = (yyvsp[(3) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.cre_gen75.message_type = (yyvsp[(5) - (6)].integer);
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = 1;
		  }
		}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1862 "gram.y"
    {
		  if (IS_GENp(8)) {
                      if ((yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_SAMPLER_CACHE &&
                          (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_RENDER_CACHE &&
                          (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_CONSTANT_CACHE &&
                          (yyvsp[(3) - (14)].integer) != GEN7_SFID_DATAPORT_DATA_CACHE &&
                          (yyvsp[(3) - (14)].integer) != HSW_SFID_DATAPORT_DATA_CACHE1) {
                          error (&(yylsp[(3) - (14)]), "error: wrong cache type\n");
                      }

                      gen8_set_sfid(GEN8(&(yyval.instruction)), (yyvsp[(3) - (14)].integer));
                      gen8_set_header_present(GEN8(&(yyval.instruction)), ((yyvsp[(13) - (14)].integer) != 0));
                      gen8_set_dp_binding_table_index(GEN8(&(yyval.instruction)), (yyvsp[(9) - (14)].integer));
                      gen8_set_dp_message_control(GEN8(&(yyval.instruction)), (yyvsp[(7) - (14)].integer));
                      gen8_set_dp_message_type(GEN8(&(yyval.instruction)), (yyvsp[(5) - (14)].integer));
                      gen8_set_dp_category(GEN8(&(yyval.instruction)), (yyvsp[(11) - (14)].integer));
		  } else {
                      GEN(&(yyval.instruction))->bits2.send_gen5.sfid = (yyvsp[(3) - (14)].integer);
                      GEN(&(yyval.instruction))->bits3.generic_gen5.header_present = ((yyvsp[(13) - (14)].integer) != 0);

                      if (IS_GENp(7)) {
                          if ((yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_SAMPLER_CACHE &&
                              (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_RENDER_CACHE &&
                              (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_CONSTANT_CACHE &&
                              (yyvsp[(3) - (14)].integer) != GEN7_SFID_DATAPORT_DATA_CACHE) {
                              error (&(yylsp[(3) - (14)]), "error: wrong cache type\n");
                          }

                          GEN(&(yyval.instruction))->bits3.gen7_dp.category = (yyvsp[(11) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen7_dp.binding_table_index = (yyvsp[(9) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen7_dp.msg_control = (yyvsp[(7) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen7_dp.msg_type = (yyvsp[(5) - (14)].integer);
                      } else if (IS_GENx(6)) {
                          if ((yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_SAMPLER_CACHE &&
                              (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_RENDER_CACHE &&
                              (yyvsp[(3) - (14)].integer) != GEN6_SFID_DATAPORT_CONSTANT_CACHE) {
                              error (&(yylsp[(3) - (14)]), "error: wrong cache type\n");
                          }

                          GEN(&(yyval.instruction))->bits3.gen6_dp.send_commit_msg = (yyvsp[(11) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen6_dp.binding_table_index = (yyvsp[(9) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen6_dp.msg_control = (yyvsp[(7) - (14)].integer);
                          GEN(&(yyval.instruction))->bits3.gen6_dp.msg_type = (yyvsp[(5) - (14)].integer);
                      } else if (!IS_GENp(5)) {
                          error (&(yylsp[(1) - (14)]), "Gen6- doesn't support data port for sampler/render/constant/data cache\n");
                      }
                  }
		}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1912 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1913 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1916 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1917 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1920 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1921 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1924 "gram.y"
    { (yyval.integer) = BRW_URB_SWIZZLE_TRANSPOSE; }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1925 "gram.y"
    { (yyval.integer) = BRW_URB_SWIZZLE_INTERLEAVE; }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1926 "gram.y"
    { (yyval.integer) = BRW_URB_SWIZZLE_NONE; }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1939 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1940 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1943 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1944 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1953 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (2)].symbol_reg).reg;
	          (yyval.reg).hstride = resolve_dst_region(&(yyvsp[(1) - (2)].symbol_reg), (yyvsp[(2) - (2)].integer));
		}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1958 "gram.y"
    {
		  /* Returns an instruction with just the destination register
		   * filled in.
		   */
		  (yyval.reg) = (yyvsp[(1) - (4)].reg);
	          (yyval.reg).hstride = resolve_dst_region(NULL, (yyvsp[(2) - (4)].integer));
		  (yyval.reg).dw1.bits.writemask = (yyvsp[(3) - (4)].reg).dw1.bits.writemask;
		  (yyval.reg).type = (yyvsp[(4) - (4)].regtype).type;
		}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1973 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (3)].reg);
	          (yyval.reg).hstride = resolve_dst_region(NULL, (yyvsp[(2) - (3)].integer));
		  (yyval.reg).type = (yyvsp[(3) - (3)].regtype).type;
		}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1979 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).hstride = 1;
		  (yyval.reg).type = BRW_REGISTER_TYPE_UW;
		}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1985 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).hstride = 1;
		  (yyval.reg).type = BRW_REGISTER_TYPE_UD;
		}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1991 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).hstride = 1;
		  (yyval.reg).type = BRW_REGISTER_TYPE_UD;
		}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1997 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (3)].reg);
	          (yyval.reg).hstride = resolve_dst_region(NULL, (yyvsp[(2) - (3)].integer));
		  (yyval.reg).type = (yyvsp[(3) - (3)].regtype).type;
		}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 2008 "gram.y"
    {
		    struct declared_register *dcl_reg = find_register((yyvsp[(1) - (1)].string));

		    if (dcl_reg == NULL)
			error(&(yylsp[(1) - (1)]), "can't find register %s\n", (yyvsp[(1) - (1)].string));

		    memcpy(&(yyval.symbol_reg), dcl_reg, sizeof(*dcl_reg));
		    free((yyvsp[(1) - (1)].string)); // $1 has been malloc'ed by strdup
		}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 2018 "gram.y"
    {
			(yyval.symbol_reg)=(yyvsp[(1) - (1)].symbol_reg);
		}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 2024 "gram.y"
    {
		    struct declared_register *dcl_reg = find_register((yyvsp[(1) - (4)].string));	

		    if (dcl_reg == NULL)
			error(&(yylsp[(1) - (4)]), "can't find register %s\n", (yyvsp[(1) - (4)].string));

		    memcpy(&(yyval.symbol_reg), dcl_reg, sizeof(*dcl_reg));
		    (yyval.symbol_reg).reg.nr += (yyvsp[(3) - (4)].integer);
		    free((yyvsp[(1) - (4)].string));
		}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 2035 "gram.y"
    {
		    struct declared_register *dcl_reg = find_register((yyvsp[(1) - (6)].string));	

		    if (dcl_reg == NULL)
			error(&(yylsp[(1) - (6)]), "can't find register %s\n", (yyvsp[(1) - (6)].string));

		    memcpy(&(yyval.symbol_reg), dcl_reg, sizeof(*dcl_reg));
		    (yyval.symbol_reg).reg.nr += (yyvsp[(3) - (6)].integer);
		    if(advanced_flag) {
			int size = get_type_size(dcl_reg->reg.type);
		        (yyval.symbol_reg).reg.nr += ((yyval.symbol_reg).reg.subnr + (yyvsp[(5) - (6)].integer)) / (32 / size);
		        (yyval.symbol_reg).reg.subnr = ((yyval.symbol_reg).reg.subnr + (yyvsp[(5) - (6)].integer)) % (32 / size);
		    } else {
		        (yyval.symbol_reg).reg.nr += ((yyval.symbol_reg).reg.subnr + (yyvsp[(5) - (6)].integer)) / 32;
		        (yyval.symbol_reg).reg.subnr = ((yyval.symbol_reg).reg.subnr + (yyvsp[(5) - (6)].integer)) % 32;
		    }
		    free((yyvsp[(1) - (6)].string));
		}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 2058 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).address_mode = BRW_ADDRESS_DIRECT;
		}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 2063 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).address_mode = BRW_ADDRESS_DIRECT;
		}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 2068 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).address_mode = BRW_ADDRESS_REGISTER_INDIRECT_REGISTER;
		}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 2073 "gram.y"
    {
		  (yyval.reg) = (yyvsp[(1) - (1)].reg);
		  (yyval.reg).address_mode = BRW_ADDRESS_REGISTER_INDIRECT_REGISTER;
		}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 2090 "gram.y"
    {
		  union {
		    int i;
		    float f;
		  } intfloat;
		  uint32_t	d;

		  switch ((yyvsp[(2) - (2)].integer)) {
		  case BRW_REGISTER_TYPE_UD:
		  case BRW_REGISTER_TYPE_D:
		  case BRW_REGISTER_TYPE_V:
		  case BRW_REGISTER_TYPE_VF:
		    switch ((yyvsp[(1) - (2)].imm32).r) {
		    case imm32_d:
		      d = (yyvsp[(1) - (2)].imm32).u.d;
		      break;
		    default:
		      error (&(yylsp[(2) - (2)]), "non-int D/UD/V/VF representation: %d,type=%d\n", (yyvsp[(1) - (2)].imm32).r, (yyvsp[(2) - (2)].integer));
		    }
		    break;
		  case BRW_REGISTER_TYPE_UW:
		  case BRW_REGISTER_TYPE_W:
		    switch ((yyvsp[(1) - (2)].imm32).r) {
		    case imm32_d:
		      d = (yyvsp[(1) - (2)].imm32).u.d;
		      break;
		    default:
		      error (&(yylsp[(2) - (2)]), "non-int W/UW representation\n");
		    }
		    d &= 0xffff;
		    d |= d << 16;
		    break;
		  case BRW_REGISTER_TYPE_F:
		    switch ((yyvsp[(1) - (2)].imm32).r) {
		    case imm32_f:
		      intfloat.f = (yyvsp[(1) - (2)].imm32).u.f;
		      break;
		    case imm32_d:
		      intfloat.f = (float) (yyvsp[(1) - (2)].imm32).u.d;
		      break;
		    default:
		      error (&(yylsp[(2) - (2)]), "non-float F representation\n");
		    }
		    d = intfloat.i;
		    break;
#if 0
		  case BRW_REGISTER_TYPE_VF:
		    fprintf (stderr, "Immediate type VF not supported yet\n");
		    YYERROR;
#endif
		  default:
		    error(&(yylsp[(2) - (2)]), "unknown immediate type %d\n", (yyvsp[(2) - (2)].integer));
		  }
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = BRW_IMMEDIATE_VALUE;
		  (yyval.src_operand).reg.type = (yyvsp[(2) - (2)].integer);
		  (yyval.src_operand).reg.dw1.ud = d;
		}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 2152 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (3)].reg), (yyvsp[(3) - (3)].regtype).type);
		  (yyval.src_operand).reg.vstride = (yyvsp[(2) - (3)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(2) - (3)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(2) - (3)].region).horiz_stride;
		  (yyval.src_operand).default_region = (yyvsp[(2) - (3)].region).is_default;
		}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 2163 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = (yyvsp[(1) - (3)].reg).file;
		  (yyval.src_operand).reg.type = (yyvsp[(3) - (3)].regtype).type;
		  (yyval.src_operand).reg.subnr = (yyvsp[(1) - (3)].reg).subnr;
		  (yyval.src_operand).reg.nr = (yyvsp[(1) - (3)].reg).nr;
		  (yyval.src_operand).reg.vstride = (yyvsp[(2) - (3)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(2) - (3)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(2) - (3)].region).horiz_stride;
		  (yyval.src_operand).default_region = (yyvsp[(2) - (3)].region).is_default;
		  (yyval.src_operand).reg.negate = 0;
		  (yyval.src_operand).reg.abs = 0;
		}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 2177 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (1)].reg), BRW_REGISTER_TYPE_UB);
		}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 2181 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (1)].reg), BRW_REGISTER_TYPE_UD);
		}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 2189 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (1)].reg), BRW_REGISTER_TYPE_UD);
		}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 2193 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (1)].reg), BRW_REGISTER_TYPE_UD);
		}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 2197 "gram.y"
    {
		  if ((yyvsp[(3) - (3)].regtype).is_default) {
		    set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (3)].reg), BRW_REGISTER_TYPE_UD);
		  } else {
		    set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (3)].reg), (yyvsp[(3) - (3)].regtype).type);
		  }
		  (yyval.src_operand).default_region = 1;
		}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 2211 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = (yyvsp[(1) - (1)].symbol_reg).reg.file;
		  (yyval.reg).nr = (yyvsp[(1) - (1)].symbol_reg).reg.nr;
		  (yyval.reg).subnr = (yyvsp[(1) - (1)].symbol_reg).reg.subnr;
             }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 2224 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.address_mode = BRW_ADDRESS_DIRECT;
		  (yyval.src_operand).reg.file = (yyvsp[(3) - (5)].symbol_reg).reg.file;
		  (yyval.src_operand).reg.nr = (yyvsp[(3) - (5)].symbol_reg).reg.nr;
		  (yyval.src_operand).reg.subnr = (yyvsp[(3) - (5)].symbol_reg).reg.subnr;
		  if ((yyvsp[(5) - (5)].regtype).is_default) {
		    (yyval.src_operand).reg.type = (yyvsp[(3) - (5)].symbol_reg).reg.type;
		  } else {
		    (yyval.src_operand).reg.type = (yyvsp[(5) - (5)].regtype).type;
		  }
		  if ((yyvsp[(4) - (5)].region).is_default) {
		    (yyval.src_operand).reg.vstride = (yyvsp[(3) - (5)].symbol_reg).src_region.vert_stride;
		    (yyval.src_operand).reg.width = (yyvsp[(3) - (5)].symbol_reg).src_region.width;
		    (yyval.src_operand).reg.hstride = (yyvsp[(3) - (5)].symbol_reg).src_region.horiz_stride;
		  } else {
		    (yyval.src_operand).reg.vstride = (yyvsp[(4) - (5)].region).vert_stride;
		    (yyval.src_operand).reg.width = (yyvsp[(4) - (5)].region).width;
		    (yyval.src_operand).reg.hstride = (yyvsp[(4) - (5)].region).horiz_stride;
		  }
		  (yyval.src_operand).reg.negate = (yyvsp[(1) - (5)].integer);
		  (yyval.src_operand).reg.abs = (yyvsp[(2) - (5)].integer);
		}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 2248 "gram.y"
    {
		  if((yyvsp[(2) - (3)].region).is_default ==1 && (yyvsp[(3) - (3)].regtype).is_default == 1)
		  {
		    set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (3)].reg), BRW_REGISTER_TYPE_UD);
		  }
		  else{
		    memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		    (yyval.src_operand).reg.address_mode = BRW_ADDRESS_DIRECT;
		    (yyval.src_operand).reg.file = (yyvsp[(1) - (3)].reg).file;
		    (yyval.src_operand).reg.nr = (yyvsp[(1) - (3)].reg).nr;
		    (yyval.src_operand).reg.subnr = (yyvsp[(1) - (3)].reg).subnr;
		    (yyval.src_operand).reg.vstride = (yyvsp[(2) - (3)].region).vert_stride;
		    (yyval.src_operand).reg.width = (yyvsp[(2) - (3)].region).width;
		    (yyval.src_operand).reg.hstride = (yyvsp[(2) - (3)].region).horiz_stride;
		    (yyval.src_operand).reg.type = (yyvsp[(3) - (3)].regtype).type;
		  }
		}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 2266 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.address_mode = BRW_ADDRESS_DIRECT;
		  (yyval.src_operand).reg.file = (yyvsp[(3) - (6)].reg).file;
		  (yyval.src_operand).reg.nr = (yyvsp[(3) - (6)].reg).nr;
		  (yyval.src_operand).reg.subnr = (yyvsp[(3) - (6)].reg).subnr;
		  (yyval.src_operand).reg.type = (yyvsp[(6) - (6)].regtype).type;
		  (yyval.src_operand).reg.vstride = (yyvsp[(4) - (6)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(4) - (6)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(4) - (6)].region).horiz_stride;
		  (yyval.src_operand).default_region = (yyvsp[(4) - (6)].region).is_default;
		  (yyval.src_operand).reg.negate = (yyvsp[(1) - (6)].integer);
		  (yyval.src_operand).reg.abs = (yyvsp[(2) - (6)].integer);
		  (yyval.src_operand).reg.dw1.bits.swizzle = (yyvsp[(5) - (6)].src_operand).reg.dw1.bits.swizzle;
		}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 2286 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.address_mode = BRW_ADDRESS_REGISTER_INDIRECT_REGISTER;
		  (yyval.src_operand).reg.file = (yyvsp[(3) - (6)].reg).file;
		  (yyval.src_operand).reg.subnr = (yyvsp[(3) - (6)].reg).subnr;
		  (yyval.src_operand).reg.dw1.bits.indirect_offset = (yyvsp[(3) - (6)].reg).dw1.bits.indirect_offset;
		  (yyval.src_operand).reg.type = (yyvsp[(5) - (6)].regtype).type;
		  (yyval.src_operand).reg.vstride = (yyvsp[(4) - (6)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(4) - (6)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(4) - (6)].region).horiz_stride;
		  (yyval.src_operand).reg.negate = (yyvsp[(1) - (6)].integer);
		  (yyval.src_operand).reg.abs = (yyvsp[(2) - (6)].integer);
		  (yyval.src_operand).reg.dw1.bits.swizzle = (yyvsp[(6) - (6)].src_operand).reg.dw1.bits.swizzle;
		}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 2307 "gram.y"
    {
		  if ((yyvsp[(3) - (3)].integer) < -512 || (yyvsp[(3) - (3)].integer) > 511)
		    error(&(yylsp[(3) - (3)]), "Address immediate offset %d out of range\n", (yyvsp[(3) - (3)].integer));
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).subnr = (yyvsp[(1) - (3)].reg).subnr;
		  (yyval.reg).dw1.bits.indirect_offset = (yyvsp[(3) - (3)].integer);
		}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 2315 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).subnr = (yyvsp[(1) - (1)].reg).subnr;
		  (yyval.reg).dw1.bits.indirect_offset = 0;
		}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 2325 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 2332 "gram.y"
    {
		  (yyval.integer) = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 2336 "gram.y"
    {
		  /* Default to subreg 0 if unspecified. */
		  (yyval.integer) = 0;
		}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 2343 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_GENERAL_REGISTER_FILE;
		  (yyval.reg).nr = (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 2352 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_GENERAL_REGISTER_FILE;
		  (yyval.reg).subnr = (yyvsp[(3) - (4)].reg).subnr;
		  (yyval.reg).dw1.bits.indirect_offset = (yyvsp[(3) - (4)].reg).dw1.bits.indirect_offset;
		}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 2361 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_MESSAGE_REGISTER_FILE;
		  (yyval.reg).nr = (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 2370 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_MESSAGE_REGISTER_FILE;
		  (yyval.reg).subnr = (yyvsp[(3) - (4)].reg).subnr;
		  (yyval.reg).dw1.bits.indirect_offset = (yyvsp[(3) - (4)].reg).dw1.bits.indirect_offset;
		}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 2379 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) != 0)
		    error(&(yylsp[(2) - (2)]), "address register number %d out of range", (yyvsp[(1) - (2)].integer));

		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_ADDRESS | (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 2391 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) > 1)
		    error(&(yylsp[(1) - (2)]), "accumulator register number %d out of range", (yyvsp[(1) - (2)].integer));
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_ACCUMULATOR | (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 2402 "gram.y"
    {
		  if ((!IS_GENp(7) && (yyvsp[(1) - (2)].integer) > 0) ||
		      (IS_GENp(7) && (yyvsp[(1) - (2)].integer) > 1)) {
                    error(&(yylsp[(2) - (2)]), "flag register number %d out of range\n", (yyvsp[(1) - (2)].integer));
		  }

		  if ((yyvsp[(2) - (2)].integer) > 1)
		    error(&(yylsp[(2) - (2)]), "flag subregister number %d out of range\n", (yyvsp[(1) - (2)].integer));

		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_FLAG | (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 2419 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) > 0)
		    error(&(yylsp[(1) - (2)]), "mask register number %d out of range", (yyvsp[(1) - (2)].integer));

		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_MASK;
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 2429 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_MASK;
		  (yyval.reg).subnr = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 2441 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) > 0)
		    error(&(yylsp[(1) - (2)]), "mask stack register number %d out of range", (yyvsp[(1) - (2)].integer));
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_MASK_STACK;
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 2450 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_MASK_STACK;
		  (yyval.reg).subnr = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 2485 "gram.y"
    {
		  int num_notifyreg = (IS_GENp(6)) ? 3 : 2;

		  if ((yyvsp[(1) - (2)].integer) > num_notifyreg)
		    error(&(yylsp[(1) - (2)]), "notification register number %d out of range",
			  (yyvsp[(1) - (2)].integer));

		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;

                  if (IS_GENp(6)) {
		    (yyval.reg).nr = BRW_ARF_NOTIFICATION_COUNT;
                    (yyval.reg).subnr = (yyvsp[(1) - (2)].integer);
                  } else {
		    (yyval.reg).nr = BRW_ARF_NOTIFICATION_COUNT | (yyvsp[(1) - (2)].integer);
                    (yyval.reg).subnr = 0;
                  }
		}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 2521 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) > 0)
		    error(&(yylsp[(1) - (2)]), "state register number %d out of range", (yyvsp[(1) - (2)].integer));

		  if ((yyvsp[(2) - (2)].integer) > 1)
		    error(&(yylsp[(2) - (2)]), "state subregister number %d out of range", (yyvsp[(1) - (2)].integer));

		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_STATE | (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 2536 "gram.y"
    {
		  if ((yyvsp[(1) - (2)].integer) > 0)
		    error(&(yylsp[(1) - (2)]), "control register number %d out of range", (yyvsp[(1) - (2)].integer));

		  if ((yyvsp[(2) - (2)].integer) > 2)
		    error(&(yylsp[(2) - (2)]), "control subregister number %d out of range", (yyvsp[(1) - (2)].integer));
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_CONTROL | (yyvsp[(1) - (2)].integer);
		  (yyval.reg).subnr = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 2550 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_IP;
		  (yyval.reg).subnr = 0;
		}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 2559 "gram.y"
    {
		  memset (&(yyval.reg), '\0', sizeof ((yyval.reg)));
		  (yyval.reg).file = BRW_ARCHITECTURE_REGISTER_FILE;
		  (yyval.reg).nr = BRW_ARF_NULL;
		  (yyval.reg).subnr = 0;
		}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 2570 "gram.y"
    {
		  if (((yyvsp[(1) - (1)].integer) > 32767) || ((yyvsp[(1) - (1)].integer) < -32768))
		    error(&(yylsp[(1) - (1)]), "error: relative offset %d out of range \n", (yyvsp[(1) - (1)].integer));

		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = BRW_IMMEDIATE_VALUE;
		  (yyval.src_operand).reg.type = BRW_REGISTER_TYPE_D;
		  (yyval.src_operand).imm32 = (yyvsp[(1) - (1)].integer) & 0x0000ffff;
		}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 2580 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = BRW_IMMEDIATE_VALUE;
		  (yyval.src_operand).reg.type = BRW_REGISTER_TYPE_D;
		  (yyval.src_operand).reloc_target = (yyvsp[(1) - (1)].string);
		}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 2590 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = BRW_IMMEDIATE_VALUE;
		  (yyval.src_operand).reg.type = BRW_REGISTER_TYPE_D;
		  (yyval.src_operand).reloc_target = (yyvsp[(1) - (1)].string);
		}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 2597 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.file = BRW_IMMEDIATE_VALUE;
		  (yyval.src_operand).reg.type = BRW_REGISTER_TYPE_D;
		  (yyval.src_operand).imm32 = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 2604 "gram.y"
    {
		  set_direct_src_operand(&(yyval.src_operand), &(yyvsp[(1) - (3)].reg), (yyvsp[(3) - (3)].regtype).type);
		  (yyval.src_operand).reg.vstride = (yyvsp[(2) - (3)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(2) - (3)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(2) - (3)].region).horiz_stride;
		  (yyval.src_operand).default_region = (yyvsp[(2) - (3)].region).is_default;
		}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 2612 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.address_mode = BRW_ADDRESS_DIRECT;
		  (yyval.src_operand).reg.file = (yyvsp[(1) - (1)].symbol_reg).reg.file;
		  (yyval.src_operand).reg.nr = (yyvsp[(1) - (1)].symbol_reg).reg.nr;
		  (yyval.src_operand).reg.subnr = (yyvsp[(1) - (1)].symbol_reg).reg.subnr;
		  (yyval.src_operand).reg.type = (yyvsp[(1) - (1)].symbol_reg).reg.type;
		  (yyval.src_operand).reg.vstride = (yyvsp[(1) - (1)].symbol_reg).src_region.vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(1) - (1)].symbol_reg).src_region.width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(1) - (1)].symbol_reg).src_region.horiz_stride;
		}
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 2624 "gram.y"
    {
		  memset (&(yyval.src_operand), '\0', sizeof ((yyval.src_operand)));
		  (yyval.src_operand).reg.address_mode = BRW_ADDRESS_REGISTER_INDIRECT_REGISTER;
		  (yyval.src_operand).reg.file = (yyvsp[(1) - (3)].reg).file;
		  (yyval.src_operand).reg.subnr = (yyvsp[(1) - (3)].reg).subnr;
		  (yyval.src_operand).reg.dw1.bits.indirect_offset = (yyvsp[(1) - (3)].reg).dw1.bits.indirect_offset;
		  (yyval.src_operand).reg.type = (yyvsp[(3) - (3)].regtype).type;
		  (yyval.src_operand).reg.vstride = (yyvsp[(2) - (3)].region).vert_stride;
		  (yyval.src_operand).reg.width = (yyvsp[(2) - (3)].region).width;
		  (yyval.src_operand).reg.hstride = (yyvsp[(2) - (3)].region).horiz_stride;
		}
    break;

  case 257:
/* Line 1792 of yacc.c  */
#line 2639 "gram.y"
    {
		  (yyval.integer) = DEFAULT_DSTREGION;
		}
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 2643 "gram.y"
    {
		  /* Returns a value for a horiz_stride field of an
		   * instruction.
		   */
		  if ((yyvsp[(2) - (3)].integer) != 1 && (yyvsp[(2) - (3)].integer) != 2 && (yyvsp[(2) - (3)].integer) != 4)
		    error(&(yylsp[(2) - (3)]), "Invalid horiz size %d\n", (yyvsp[(2) - (3)].integer));

		  (yyval.integer) = ffs((yyvsp[(2) - (3)].integer));
		}
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 2655 "gram.y"
    {
		  /* XXX is this default value correct?*/
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = ffs(0);
		  (yyval.region).width = BRW_WIDTH_1;
		  (yyval.region).horiz_stride = ffs(0);
		  (yyval.region).is_default = 1;
		}
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 2664 "gram.y"
    {
		  /* XXX is this default value correct for accreg?*/
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = ffs((yyvsp[(2) - (3)].integer));
		  (yyval.region).width = BRW_WIDTH_1;
		  (yyval.region).horiz_stride = ffs(0);
		}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 2672 "gram.y"
    {
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = ffs((yyvsp[(2) - (7)].integer));
		  (yyval.region).width = ffs((yyvsp[(4) - (7)].integer)) - 1;
		  (yyval.region).horiz_stride = ffs((yyvsp[(6) - (7)].integer));
		}
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 2679 "gram.y"
    {
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = ffs((yyvsp[(2) - (7)].integer));
		  (yyval.region).width = ffs((yyvsp[(4) - (7)].integer)) - 1;
		  (yyval.region).horiz_stride = ffs((yyvsp[(6) - (7)].integer));
		}
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 2692 "gram.y"
    {
		  memset (&(yyval.region), '\0', sizeof ((yyval.region)));
		  (yyval.region).vert_stride = BRW_VERTICAL_STRIDE_ONE_DIMENSIONAL;
		  (yyval.region).width = ffs((yyvsp[(2) - (5)].integer)) - 1;
		  (yyval.region).horiz_stride = ffs((yyvsp[(4) - (5)].integer));
		}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 2709 "gram.y"
    { (yyval.regtype).type = program_defaults.register_type;(yyval.regtype).is_default = 1;}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 2710 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_F;(yyval.regtype).is_default = 0; }
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 2711 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_UD;(yyval.regtype).is_default = 0; }
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 2712 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_D;(yyval.regtype).is_default = 0; }
    break;

  case 270:
/* Line 1792 of yacc.c  */
#line 2713 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_UW;(yyval.regtype).is_default = 0; }
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 2714 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_W;(yyval.regtype).is_default = 0; }
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 2715 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_UB;(yyval.regtype).is_default = 0; }
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 2716 "gram.y"
    { (yyval.regtype).type = BRW_REGISTER_TYPE_B;(yyval.regtype).is_default = 0; }
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 2720 "gram.y"
    {
		    /* XXX change to default when pragma parse is done */
		   (yyval.integer) = BRW_REGISTER_TYPE_D;
		}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 2724 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_F; }
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 2725 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_UD; }
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 2726 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_D; }
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 2727 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_UW; }
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 2728 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_W; }
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 2729 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_V; }
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 2730 "gram.y"
    { (yyval.integer) = BRW_REGISTER_TYPE_VF; }
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 2738 "gram.y"
    {
		  (yyval.src_operand).reg.dw1.bits.swizzle = BRW_SWIZZLE_NOOP;
		}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 2742 "gram.y"
    {
		  (yyval.src_operand).reg.dw1.bits.swizzle = BRW_SWIZZLE4((yyvsp[(2) - (2)].integer), (yyvsp[(2) - (2)].integer), (yyvsp[(2) - (2)].integer), (yyvsp[(2) - (2)].integer));
		}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 2746 "gram.y"
    {
		  (yyval.src_operand).reg.dw1.bits.swizzle = BRW_SWIZZLE4((yyvsp[(2) - (5)].integer), (yyvsp[(3) - (5)].integer), (yyvsp[(4) - (5)].integer), (yyvsp[(5) - (5)].integer));
		}
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 2759 "gram.y"
    {
		  (yyval.reg).dw1.bits.writemask = BRW_WRITEMASK_XYZW;
		}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 2763 "gram.y"
    {
		  (yyval.reg).dw1.bits.writemask = (yyvsp[(2) - (5)].integer) | (yyvsp[(3) - (5)].integer) | (yyvsp[(4) - (5)].integer) | (yyvsp[(5) - (5)].integer);
		}
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 2768 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 2769 "gram.y"
    { (yyval.integer) = 1 << BRW_CHANNEL_X; }
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 2772 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 2773 "gram.y"
    { (yyval.integer) = 1 << BRW_CHANNEL_Y; }
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 2776 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 2777 "gram.y"
    { (yyval.integer) = 1 << BRW_CHANNEL_Z; }
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 2780 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 2781 "gram.y"
    { (yyval.integer) = 1 << BRW_CHANNEL_W; }
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 2785 "gram.y"
    { (yyval.imm32).r = imm32_d; (yyval.imm32).u.d = (yyvsp[(1) - (1)].integer); }
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 2786 "gram.y"
    { (yyval.imm32).r = imm32_f; (yyval.imm32).u.f = (yyvsp[(1) - (1)].number); }
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 2791 "gram.y"
    {
		  (yyval.predicate).pred_control = BRW_PREDICATE_NONE;
		  (yyval.predicate).flag_reg_nr = 0;
		  (yyval.predicate).flag_subreg_nr = 0;
		  (yyval.predicate).pred_inverse = 0;
		}
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 2798 "gram.y"
    {
		  (yyval.predicate).pred_control = (yyvsp[(4) - (5)].integer);
		  (yyval.predicate).flag_reg_nr = (yyvsp[(3) - (5)].reg).nr;
		  (yyval.predicate).flag_subreg_nr = (yyvsp[(3) - (5)].reg).subnr;
		  (yyval.predicate).pred_inverse = (yyvsp[(2) - (5)].integer);
		}
    break;

  case 303:
/* Line 1792 of yacc.c  */
#line 2806 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 2807 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 2808 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 2811 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_NORMAL; }
    break;

  case 307:
/* Line 1792 of yacc.c  */
#line 2812 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN16_REPLICATE_X; }
    break;

  case 308:
/* Line 1792 of yacc.c  */
#line 2813 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN16_REPLICATE_Y; }
    break;

  case 309:
/* Line 1792 of yacc.c  */
#line 2814 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN16_REPLICATE_Z; }
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 2815 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN16_REPLICATE_W; }
    break;

  case 311:
/* Line 1792 of yacc.c  */
#line 2816 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ANYV; }
    break;

  case 312:
/* Line 1792 of yacc.c  */
#line 2817 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ALLV; }
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 2818 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ANY2H; }
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 2819 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ALL2H; }
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 2820 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ANY4H; }
    break;

  case 316:
/* Line 1792 of yacc.c  */
#line 2821 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ALL4H; }
    break;

  case 317:
/* Line 1792 of yacc.c  */
#line 2822 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ANY8H; }
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 2823 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ALL8H; }
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 2824 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ANY16H; }
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 2825 "gram.y"
    { (yyval.integer) = BRW_PREDICATE_ALIGN1_ALL16H; }
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 2828 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 2829 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 2832 "gram.y"
    { (yyval.integer) = 0; }
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 2833 "gram.y"
    { (yyval.integer) = 1; }
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 2837 "gram.y"
    {
		  (yyval.integer) = ffs(program_defaults.execute_size) - 1;
		}
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 2841 "gram.y"
    {
		  /* Returns a value for the execution_size field of an
		   * instruction.
		   */
		  if ((yyvsp[(2) - (3)].integer) != 1 && (yyvsp[(2) - (3)].integer) != 2 && (yyvsp[(2) - (3)].integer) != 4 && (yyvsp[(2) - (3)].integer) != 8 && (yyvsp[(2) - (3)].integer) != 16 &&
		      (yyvsp[(2) - (3)].integer) != 32)
		    error(&(yylsp[(2) - (3)]), "Invalid execution size %d\n", (yyvsp[(2) - (3)].integer));

		  (yyval.integer) = ffs((yyvsp[(2) - (3)].integer)) - 1;
		}
    break;

  case 327:
/* Line 1792 of yacc.c  */
#line 2853 "gram.y"
    { (yyval.integer) = BRW_INSTRUCTION_NORMAL; }
    break;

  case 328:
/* Line 1792 of yacc.c  */
#line 2854 "gram.y"
    { (yyval.integer) = BRW_INSTRUCTION_SATURATE; }
    break;

  case 329:
/* Line 1792 of yacc.c  */
#line 2857 "gram.y"
    {
		    (yyval.condition).cond = (yyvsp[(1) - (1)].integer);
		    (yyval.condition).flag_reg_nr = 0;
		    (yyval.condition).flag_subreg_nr = -1;
		}
    break;

  case 330:
/* Line 1792 of yacc.c  */
#line 2863 "gram.y"
    {
		    (yyval.condition).cond = (yyvsp[(1) - (3)].integer);
		    (yyval.condition).flag_reg_nr = ((yyvsp[(3) - (3)].reg).nr & 0xF);
		    (yyval.condition).flag_subreg_nr = (yyvsp[(3) - (3)].reg).subnr;
		}
    break;

  case 331:
/* Line 1792 of yacc.c  */
#line 2869 "gram.y"
    { (yyval.integer) = BRW_CONDITIONAL_NONE; }
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 2885 "gram.y"
    { memset(&(yyval.options), 0, sizeof((yyval.options))); }
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 2887 "gram.y"
    { (yyval.options) = (yyvsp[(2) - (3)].options); }
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 2891 "gram.y"
    {
		  (yyval.options) = (yyvsp[(1) - (3)].options);
		  add_option(&(yyval.options), (yyvsp[(3) - (3)].integer));
		}
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 2896 "gram.y"
    {
		  (yyval.options) = (yyvsp[(1) - (2)].options);
		  add_option(&(yyval.options), (yyvsp[(2) - (2)].integer));
		}
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 2901 "gram.y"
    {
		  memset(&(yyval.options), 0, sizeof((yyval.options)));
		}
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 2906 "gram.y"
    { (yyval.integer) = ALIGN1; }
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 2907 "gram.y"
    { (yyval.integer) = ALIGN16; }
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 2908 "gram.y"
    { (yyval.integer) = SECHALF; }
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 2909 "gram.y"
    { (yyval.integer) = COMPR; }
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 2910 "gram.y"
    { (yyval.integer) = SWITCH; }
    break;

  case 353:
/* Line 1792 of yacc.c  */
#line 2911 "gram.y"
    { (yyval.integer) = ATOMIC; }
    break;

  case 354:
/* Line 1792 of yacc.c  */
#line 2912 "gram.y"
    { (yyval.integer) = NODDCHK; }
    break;

  case 355:
/* Line 1792 of yacc.c  */
#line 2913 "gram.y"
    { (yyval.integer) = NODDCLR; }
    break;

  case 356:
/* Line 1792 of yacc.c  */
#line 2914 "gram.y"
    { (yyval.integer) = MASK_DISABLE; }
    break;

  case 357:
/* Line 1792 of yacc.c  */
#line 2915 "gram.y"
    { (yyval.integer) = BREAKPOINT; }
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 2916 "gram.y"
    { (yyval.integer) = ACCWRCTRL; }
    break;

  case 359:
/* Line 1792 of yacc.c  */
#line 2917 "gram.y"
    { (yyval.integer) = EOT; }
    break;


/* Line 1792 of yacc.c  */
#line 6010 "gram.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 2920 "gram.y"

extern int yylineno;

void yyerror (char *msg)
{
	fprintf(stderr, "%s: %d: %s at \"%s\"\n",
		input_filename, yylineno, msg, lex_text());
	++errors;
}

static int get_type_size(unsigned type)
{
    int size = 1;

    switch (type) {
    case BRW_REGISTER_TYPE_F:
    case BRW_REGISTER_TYPE_UD:
    case BRW_REGISTER_TYPE_D:
        size = 4;
        break;

    case BRW_REGISTER_TYPE_UW:
    case BRW_REGISTER_TYPE_W:
        size = 2;
        break;

    case BRW_REGISTER_TYPE_UB:
    case BRW_REGISTER_TYPE_B:
        size = 1;
        break;

    default:
        assert(0);
        size = 1;
        break;
    }

    return size;
}

static void reset_instruction_src_region(struct brw_instruction *instr, 
                                         struct src_operand *src)
{
    if (IS_GENp(8))
	return;

    if (!src->default_region)
        return;

    if (src->reg.file == BRW_ARCHITECTURE_REGISTER_FILE && 
        ((src->reg.nr & 0xF0) == BRW_ARF_ADDRESS)) {
        src->reg.vstride = ffs(0);
        src->reg.width = BRW_WIDTH_1;
        src->reg.hstride = ffs(0);
    } else if (src->reg.file == BRW_ARCHITECTURE_REGISTER_FILE &&
               ((src->reg.nr & 0xF0) == BRW_ARF_ACCUMULATOR)) {
        int horiz_stride = 1, width, vert_stride;
        if (instr->header.compression_control == BRW_COMPRESSION_COMPRESSED) {
            width = 16;
        } else {
            width = 8;
        }

        if (width > (1 << instr->header.execution_size))
            width = (1 << instr->header.execution_size);

        vert_stride = horiz_stride * width;
        src->reg.vstride = ffs(vert_stride);
        src->reg.width = ffs(width) - 1;
        src->reg.hstride = ffs(horiz_stride);
    } else if ((src->reg.file == BRW_ARCHITECTURE_REGISTER_FILE) &&
               (src->reg.nr == BRW_ARF_NULL) &&
               (instr->header.opcode == BRW_OPCODE_SEND)) {
        src->reg.vstride = ffs(8);
        src->reg.width = BRW_WIDTH_8;
        src->reg.hstride = ffs(1);
    } else {

        int horiz_stride = 1, width, vert_stride;

        if (instr->header.execution_size == 0) { /* scalar */
            horiz_stride = 0;
            width = 1;
            vert_stride = 0;
        } else {
            if ((instr->header.opcode == BRW_OPCODE_MUL) ||
                (instr->header.opcode == BRW_OPCODE_MAC) ||
                (instr->header.opcode == BRW_OPCODE_CMP) ||
                (instr->header.opcode == BRW_OPCODE_ASR) ||
                (instr->header.opcode == BRW_OPCODE_ADD) ||
				(instr->header.opcode == BRW_OPCODE_SHL)) {
                horiz_stride = 0;
                width = 1;
                vert_stride = 0;
            } else {
                width = (1 << instr->header.execution_size) / horiz_stride;
                vert_stride = horiz_stride * width;

                if (get_type_size(src->reg.type) * (width + src->reg.subnr) > 32) {
                    horiz_stride = 0;
                    width = 1;
                    vert_stride = 0;
                }
            }
        }

        src->reg.vstride = ffs(vert_stride);
        src->reg.width = ffs(width) - 1;
        src->reg.hstride = ffs(horiz_stride);
    }
}

static void set_instruction_opcode(struct brw_program_instruction *instr,
				  unsigned opcode)
{
    if (IS_GENp(8))
	gen8_set_opcode(GEN8(instr), opcode);
    else
	GEN(instr)->header.opcode = opcode;
}

/**
 * Fills in the destination register information in instr from the bits in dst.
 */
static int set_instruction_dest(struct brw_program_instruction *instr,
				struct brw_reg *dest)
{
	if (!validate_dst_reg(instr, dest))
		return 1;

	/* the assembler support expressing subnr in bytes or in number of
	 * elements. */
	resolve_subnr(dest);

	if (IS_GENp(8)) {
		gen8_set_exec_size(GEN8(instr), dest->width);
		gen8_set_dst(GEN8(instr), *dest);
	} else {
		brw_set_dest(&genasm_compile, GEN(instr), *dest);
	}

	return 0;
}

/* Sets the first source operand for the instruction.  Returns 0 on success. */
static int set_instruction_src0(struct brw_program_instruction *instr,
				struct src_operand *src,
				YYLTYPE *location)
{

	if (advanced_flag)
		reset_instruction_src_region(GEN(instr), src);

	if (!validate_src_reg(instr, src->reg, location))
		return 1;

	/* the assembler support expressing subnr in bytes or in number of
	 * elements. */
	resolve_subnr(&src->reg);

	if (IS_GENp(8))
		gen8_set_src0(GEN8(instr), src->reg);
	else
		brw_set_src0(&genasm_compile, GEN(instr), src->reg);

	return 0;
}

/* Sets the second source operand for the instruction.  Returns 0 on success.
 */
static int set_instruction_src1(struct brw_program_instruction *instr,
				struct src_operand *src,
				YYLTYPE *location)
{
	if (advanced_flag)
		reset_instruction_src_region(GEN(instr), src);

	if (!validate_src_reg(instr, src->reg, location))
		return 1;

	/* the assembler support expressing subnr in bytes or in number of
	 * elements. */
	resolve_subnr(&src->reg);

	if (IS_GENp(8))
		gen8_set_src1(GEN8(instr), src->reg);
	else
		brw_set_src1(&genasm_compile, GEN(instr), src->reg);

	return 0;
}

static int set_instruction_dest_three_src(struct brw_program_instruction *instr,
					  struct brw_reg *dest)
{
    resolve_subnr(dest);
    brw_set_3src_dest(&genasm_compile, GEN(instr), *dest);
    return 0;
}

static int set_instruction_src0_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src)
{
    if (advanced_flag)
	reset_instruction_src_region(GEN(instr), src);

    resolve_subnr(&src->reg);

    // TODO: src0 modifier, src0 rep_ctrl
    brw_set_3src_src0(&genasm_compile, GEN(instr), src->reg);
    return 0;
}

static int set_instruction_src1_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src)
{
    if (advanced_flag)
	reset_instruction_src_region(GEN(instr), src);

    resolve_subnr(&src->reg);

    // TODO: src1 modifier, src1 rep_ctrl
    brw_set_3src_src1(&genasm_compile, GEN(instr), src->reg);
    return 0;
}

static int set_instruction_src2_three_src(struct brw_program_instruction *instr,
					  struct src_operand *src)
{
    if (advanced_flag)
	reset_instruction_src_region(GEN(instr), src);

    resolve_subnr(&src->reg);

    // TODO: src2 modifier, src2 rep_ctrl
    brw_set_3src_src2(&genasm_compile, GEN(instr), src->reg);
    return 0;
}

static void set_instruction_saturate(struct brw_program_instruction *instr,
				     int saturate)
{
    if (IS_GENp(8))
	gen8_set_saturate(GEN8(instr), saturate);
    else
	GEN(instr)->header.saturate = saturate;
}

static void set_instruction_options(struct brw_program_instruction *instr,
				    struct options options)
{
    if (IS_GENp(8)) {
	gen8_set_access_mode(GEN8(instr), options.access_mode);
	gen8_set_thread_control(GEN8(instr), options.thread_control);
	gen8_set_dep_control(GEN8(instr), options.dependency_control);
	gen8_set_mask_control(GEN8(instr), options.mask_control);
	gen8_set_debug_control(GEN8(instr), options.debug_control);
	gen8_set_acc_wr_control(GEN8(instr), options.acc_wr_control);
	gen8_set_eot(GEN8(instr), options.end_of_thread);
    } else {
	GEN(instr)->header.access_mode = options.access_mode;
	GEN(instr)->header.compression_control = options.compression_control;
	GEN(instr)->header.thread_control = options.thread_control;
	GEN(instr)->header.dependency_control = options.dependency_control;
	GEN(instr)->header.mask_control = options.mask_control;
	GEN(instr)->header.debug_control = options.debug_control;
	GEN(instr)->header.acc_wr_control = options.acc_wr_control;
	GEN(instr)->bits3.generic.end_of_thread = options.end_of_thread;
    }
}

static void set_instruction_predicate(struct brw_program_instruction *instr,
				      struct predicate *p)
{
    if (IS_GENp(8)) {
	gen8_set_pred_control(GEN8(instr), p->pred_control);
	gen8_set_pred_inv(GEN8(instr), p->pred_inverse);
	gen8_set_flag_reg_nr(GEN8(instr), p->flag_reg_nr);
	gen8_set_flag_subreg_nr(GEN8(instr), p->flag_subreg_nr);
    } else {
	GEN(instr)->header.predicate_control = p->pred_control;
	GEN(instr)->header.predicate_inverse = p->pred_inverse;
	GEN(instr)->bits2.da1.flag_reg_nr = p->flag_reg_nr;
	GEN(instr)->bits2.da1.flag_subreg_nr = p->flag_subreg_nr;
    }
}

static void set_instruction_pred_cond(struct brw_program_instruction *instr,
				      struct predicate *p,
				      struct condition *c,
				      YYLTYPE *location)
{
    set_instruction_predicate(instr, p);

    if (IS_GENp(8))
	gen8_set_cond_modifier(GEN8(instr), c->cond);
    else
	GEN(instr)->header.destreg__conditionalmod = c->cond;

    if (c->flag_subreg_nr == -1)
	return;

    if (p->pred_control != BRW_PREDICATE_NONE &&
	(p->flag_reg_nr != c->flag_reg_nr ||
	 p->flag_subreg_nr != c->flag_subreg_nr))
    {
	warn(ALWAYS, location, "must use the same flag register if both "
	     "prediction and conditional modifier are enabled\n");
    }

    if (IS_GENp(8)) {
	gen8_set_flag_reg_nr(GEN8(instr), c->flag_reg_nr);
	gen8_set_flag_subreg_nr(GEN8(instr), c->flag_subreg_nr);
    } else {
	GEN(instr)->bits2.da1.flag_reg_nr = c->flag_reg_nr;
	GEN(instr)->bits2.da1.flag_subreg_nr = c->flag_subreg_nr;
    }
}

static void set_direct_dst_operand(struct brw_reg *dst, struct brw_reg *reg,
				   int type)
{
	*dst = *reg;
	dst->address_mode = BRW_ADDRESS_DIRECT;
	dst->type = type;
	dst->hstride = 1;
	dst->dw1.bits.writemask = BRW_WRITEMASK_XYZW;
}

static void set_direct_src_operand(struct src_operand *src, struct brw_reg *reg,
				   int type)
{
	memset(src, 0, sizeof(*src));
	src->reg.address_mode = BRW_ADDRESS_DIRECT;
	src->reg.file = reg->file;
	src->reg.type = type;
	src->reg.subnr = reg->subnr;
	src->reg.nr = reg->nr;
	src->reg.vstride = 0;
	src->reg.width = 0;
	src->reg.hstride = 0;
	src->reg.negate = 0;
	src->reg.abs = 0;
	SWIZZLE(src->reg) = BRW_SWIZZLE_NOOP;
}

static inline int instruction_opcode(struct brw_program_instruction *insn)
{
    if (IS_GENp(8))
	return gen8_opcode(GEN8(insn));
    else
	return GEN(insn)->header.opcode;
}

/*
 * return the offset used in native flow control (branch) instructions
 */
static inline int branch_offset(struct brw_program_instruction *insn, int offset)
{
    /*
     * bspec: Unlike other flow control instructions, the offset used by JMPI
     * is relative to the incremented instruction pointer rather than the IP
     * value for the instruction itself.
     */
    if (instruction_opcode(insn) == BRW_OPCODE_JMPI)
        offset--;

    /*
     * Gen4- bspec: the jump distance is in number of sixteen-byte units
     * Gen5+ bspec: the jump distance is in number of eight-byte units
     * Gen7.5+: the offset is in unit of 8bits for JMPI, 64bits for other flow
     * control instructions
     */
    if (gen_level >= 75 &&
        (instruction_opcode(insn) == BRW_OPCODE_JMPI))
        offset *= 16;
    else if (gen_level >= 50)
        offset *= 2;

    return offset;
}

void set_branch_two_offsets(struct brw_program_instruction *insn, int jip_offset, int uip_offset)
{
    int jip = branch_offset(insn, jip_offset);
    int uip = branch_offset(insn, uip_offset);

    assert(instruction_opcode(insn) != BRW_OPCODE_JMPI);

    if (IS_GENp(8)) {
        gen8_set_jip(GEN8(insn), jip);
	gen8_set_uip(GEN8(insn), uip);
    } else {
        GEN(insn)->bits3.break_cont.jip = jip;
        GEN(insn)->bits3.break_cont.uip = uip;
    }
}

void set_branch_one_offset(struct brw_program_instruction *insn, int jip_offset)
{
    int jip = branch_offset(insn, jip_offset);

    if (IS_GENp(8)) {
        gen8_set_jip(GEN8(insn), jip);
    } else if (IS_GENx(7)) {
        /* Gen7 JMPI Restrictions in bspec:
         * The JIP data type must be Signed DWord
         */
        if (instruction_opcode(insn) == BRW_OPCODE_JMPI)
            GEN(insn)->bits3.JIP = jip;
        else
            GEN(insn)->bits3.break_cont.jip = jip;
    } else if (IS_GENx(6)) {
        if ((instruction_opcode(insn) == BRW_OPCODE_CALL) ||
            (instruction_opcode(insn) == BRW_OPCODE_JMPI))
            GEN(insn)->bits3.JIP = jip;
        else
            GEN(insn)->bits1.branch_gen6.jump_count = jip; // for CASE,ELSE,FORK,IF,WHILE
    } else {
        GEN(insn)->bits3.JIP = jip;

        if (instruction_opcode(insn) == BRW_OPCODE_ELSE)
            GEN(insn)->bits3.break_cont.uip = 1; // Set the istack pop count, which must always be 1.
    }
}
