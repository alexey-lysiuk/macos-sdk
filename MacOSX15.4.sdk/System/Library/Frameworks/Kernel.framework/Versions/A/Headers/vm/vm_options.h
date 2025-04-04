/*
 * Copyright (c) 2009 Apple, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef __VM_VM_OPTIONS_H__
#define __VM_VM_OPTIONS_H__

#define UPL_DEBUG (DEVELOPMENT || DEBUG)
// #define VM_PIP_DEBUG

#define VM_PAGE_BUCKETS_CHECK DEBUG
#if VM_PAGE_BUCKETS_CHECK
#define VM_PAGE_FAKE_BUCKETS 1
#endif /* VM_PAGE_BUCKETS_CHECK */

#define VM_OBJECT_TRACKING 0
#define VM_SCAN_FOR_SHADOW_CHAIN (DEVELOPMENT || DEBUG)

#define VM_OBJECT_ACCESS_TRACKING (DEVELOPMENT || DEBUG)

#define VM_NAMED_ENTRY_DEBUG (DEVELOPMENT || DEBUG)

#define FBDP_DEBUG_OBJECT_NO_PAGER (DEVELOPMENT || DEBUG)

#define PAGE_SLEEP_WITH_INHERITOR (1)

#endif /* __VM_VM_OPTIONS_H__ */
