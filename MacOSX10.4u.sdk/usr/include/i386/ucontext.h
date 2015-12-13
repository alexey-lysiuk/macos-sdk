/*
 * Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
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

#ifndef _I386_UCONTEXT_H_
#define _I386_UCONTEXT_H_


#include <sys/appleapiopts.h>
#include <mach/thread_status.h>

#ifndef _POSIX_C_SOURCE
struct mcontext
#else /* _POSIX_C_SOURCE */
struct __darwin_mcontext
#endif /* _POSIX_C_SOURCE */
{
	i386_exception_state_t	es;
	i386_thread_state_t 	ss;	
	i386_float_state_t	fs;
};

#ifndef _POSIX_C_SOURCE
#define I386_MCONTEXT_SIZE	(i386_THREAD_STATE_COUNT + i386_FLOAT_STATE_COUNT + I386_EXCEPTION_STATE_COUNT) * sizeof(int)
#endif /* _POSIX_C_SOURCE */

#ifndef _MCONTEXT_T
#define _MCONTEXT_T
typedef __darwin_mcontext_t	mcontext_t;
#endif


#endif /* _I386_UCONTEXT_H_ */
