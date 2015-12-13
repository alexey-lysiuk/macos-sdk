/*
 * Copyright (c) 2000-2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * @OSF_COPYRIGHT@
 */
/* 
 * Mach Operating System
 * Copyright (c) 1991,1990,1989 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 * 
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 * 
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 */
/*
 *	File:	thread_status.h
 *	Author:	Avadis Tevanian, Jr.
 *	Date:	1985
 *
 *	This file contains the structure definitions for the thread
 *	state as applied to I386 processors.
 */

#ifndef	_MACH_I386_THREAD_STATUS_H_
#define _MACH_I386_THREAD_STATUS_H_

#include <mach/message.h>
#include <mach/i386/fp_reg.h>
#include <mach/i386/thread_state.h>
#include <i386/eflags.h>
/*
 *	i386_thread_state	this is the structure that is exported
 *				to user threads for use in status/mutate
 *				calls.  This structure should never
 *				change.
 *
 *	i386_float_state	exported to use threads for access to 
 *				floating point registers. Try not to 
 *				change this one, either.
 *
 */

/*     THREAD_STATE_FLAVOR_LIST 0 */
#define i386_THREAD_STATE		1
#define i386_FLOAT_STATE		2
#define i386_EXCEPTION_STATE	3
#define THREAD_STATE_NONE		4


/*
 * Largest state on this machine:
 * (be sure mach/machine/thread_state.h matches!)
 */
#define THREAD_MACHINE_STATE_MAX	THREAD_STATE_MAX


/*
 * VALID_THREAD_STATE_FLAVOR is a platform specific macro that when passed
 * an exception flavor will return if that is a defined flavor for that
 * platform. The macro must be manually updated to include all of the valid
 * exception flavors as defined above.
 */
#define VALID_THREAD_STATE_FLAVOR(x)        \
	 ((x == i386_THREAD_STATE)           || \
	 (x == i386_FLOAT_STATE)             || \
	 (x == i386_EXCEPTION_STATE)		 || \
	 (x == THREAD_STATE_NONE))


/*
 * Main thread state consists of
 * general registers, segment registers,
 * eip and eflags.
 */

struct i386_thread_state {
    unsigned int	eax;
    unsigned int	ebx;
    unsigned int	ecx;
    unsigned int	edx;
    unsigned int	edi;
    unsigned int	esi;
    unsigned int	ebp;
    unsigned int	esp;
    unsigned int	ss;
    unsigned int	eflags;
    unsigned int	eip;
    unsigned int	cs;
    unsigned int	ds;
    unsigned int	es;
    unsigned int	fs;
    unsigned int	gs;
} ;

typedef struct i386_thread_state i386_thread_state_t;
#define i386_THREAD_STATE_COUNT	((mach_msg_type_number_t) \
    ( sizeof (i386_thread_state_t) / sizeof (int) ))

/*
 * Default segment register values.
 */
    
#define USER_CODE_SELECTOR	0x0017
#define USER_DATA_SELECTOR	0x001f
#define KERN_CODE_SELECTOR	0x0008
#define KERN_DATA_SELECTOR	0x0010

typedef struct fp_control {
    unsigned short		invalid	:1,
    				denorm	:1,
				zdiv	:1,
				ovrfl	:1,
				undfl	:1,
				precis	:1,
					:2,
				pc	:2,
#define FP_PREC_24B		0
#define	FP_PREC_53B		2
#define FP_PREC_64B		3
				rc	:2,
#define FP_RND_NEAR		0
#define FP_RND_DOWN		1
#define FP_RND_UP		2
#define FP_CHOP			3
				/*inf*/	:1,
					:3;
} fp_control_t;
/*
 * Status word.
 */

typedef struct fp_status {
    unsigned short		invalid	:1,
    				denorm	:1,
				zdiv	:1,
				ovrfl	:1,
				undfl	:1,
				precis	:1,
				stkflt	:1,
				errsumm	:1,
				c0	:1,
				c1	:1,
				c2	:1,
				tos	:3,
				c3	:1,
				busy	:1;
} fp_status_t;
				
/* defn of 80bit x87 FPU or MMX register  */
struct mmst_reg {
	char	mmst_reg[10];
	char	mmst_rsrv[6];
};


/* defn of 128 bit XMM regs */
struct xmm_reg {
	char		xmm_reg[16];
};

/* 
 * Floating point state.
 */

#define FP_STATE_BYTES		512	/* number of chars worth of data from fpu_fcw */

/* For legacy reasons we need to leave the hw_state as char bytes */
struct i386_float_state {
	int 			fpu_reserved[2];
	fp_control_t	fpu_fcw;			/* x87 FPU control word */
	fp_status_t		fpu_fsw;			/* x87 FPU status word */
	uint8_t			fpu_ftw;			/* x87 FPU tag word */
	uint8_t			fpu_rsrv1;			/* reserved */ 
	uint16_t		fpu_fop;			/* x87 FPU Opcode */
	uint32_t		fpu_ip;				/* x87 FPU Instruction Pointer offset */
	uint16_t		fpu_cs;				/* x87 FPU Instruction Pointer Selector */
	uint16_t		fpu_rsrv2;			/* reserved */
	uint32_t		fpu_dp;				/* x87 FPU Instruction Operand(Data) Pointer offset */
	uint16_t		fpu_ds;				/* x87 FPU Instruction Operand(Data) Pointer Selector */
	uint16_t		fpu_rsrv3;			/* reserved */
	uint32_t		fpu_mxcsr;			/* MXCSR Register state */
	uint32_t		fpu_mxcsrmask;		/* MXCSR mask */
	struct mmst_reg	fpu_stmm0;		/* ST0/MM0   */
	struct mmst_reg	fpu_stmm1;		/* ST1/MM1  */
	struct mmst_reg	fpu_stmm2;		/* ST2/MM2  */
	struct mmst_reg	fpu_stmm3;		/* ST3/MM3  */
	struct mmst_reg	fpu_stmm4;		/* ST4/MM4  */
	struct mmst_reg	fpu_stmm5;		/* ST5/MM5  */
	struct mmst_reg	fpu_stmm6;		/* ST6/MM6  */
	struct mmst_reg	fpu_stmm7;		/* ST7/MM7  */
	struct xmm_reg	fpu_xmm0;		/* XMM 0  */
	struct xmm_reg	fpu_xmm1;		/* XMM 1  */
	struct xmm_reg	fpu_xmm2;		/* XMM 2  */
	struct xmm_reg	fpu_xmm3;		/* XMM 3  */
	struct xmm_reg	fpu_xmm4;		/* XMM 4  */
	struct xmm_reg	fpu_xmm5;		/* XMM 5  */
	struct xmm_reg	fpu_xmm6;		/* XMM 6  */
	struct xmm_reg	fpu_xmm7;		/* XMM 7  */
	char			fpu_rsrv4[14*16];	/* reserved */
	int 			fpu_reserved1;
};


#define i386_FLOAT_STATE_COUNT ((mach_msg_type_number_t) \
		(sizeof(struct i386_float_state)/sizeof(unsigned int)))
		
typedef struct i386_float_state i386_float_state_t;
	 
/*
 * Extra state that may be
 * useful to exception handlers.
 */


struct i386_exception_state {
    unsigned int	trapno;
    unsigned int	err;
    unsigned int	faultvaddr;
};

typedef struct i386_exception_state i386_exception_state_t;

#define i386_EXCEPTION_STATE_COUNT	((mach_msg_type_number_t) \
    ( sizeof (i386_exception_state_t) / sizeof (int) ))

#define I386_EXCEPTION_STATE_COUNT i386_EXCEPTION_STATE_COUNT

/*
 * Machine-independent way for servers and Mach's exception mechanism to
 * choose the most efficient state flavor for exception RPC's:
 */
#define MACHINE_THREAD_STATE		i386_THREAD_STATE
#define MACHINE_THREAD_STATE_COUNT	i386_THREAD_STATE_COUNT




#endif	/* _MACH_I386_THREAD_STATUS_H_ */
