/*
 * Copyright (c) 2013 Apple Inc. All rights reserved.
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

#pragma once

#include <mach/kern_return.h>
#include <stdint.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

/* Old ECC logging mechanism */

#define ECC_EVENT_INFO_DATA_ENTRIES     8
struct ecc_event {
	uint8_t         id;     // ID of memory (e.g. L2C), platform-specific
	uint8_t         count;  // Of uint64_t's used, starting at index 0
	uint64_t        data[ECC_EVENT_INFO_DATA_ENTRIES] __attribute__((aligned(8))); // Event-specific data
};



/* New CoreAnalytics ECC logging mechanism */

/* Flags to describe ECC memory errors */
__options_decl(ecc_flags_t, uint32_t, {
	ECC_NONE                        = 0x00000000,
	ECC_IS_CORRECTABLE              = 0x00000001,
	ECC_IS_RETIRED                  = 0x00000002,
	ECC_IS_PANIC_PATH               = 0x00000004,
	ECC_IS_CPU_REPORTED             = 0x00000008,
	ECC_DB_CORRUPTED                = 0x00000010,
	ECC_IS_TEST_ERROR               = 0x00000020,
});

/* Flags to describe MCC memory errors */
__options_decl(mcc_flags_t, uint32_t, {
	MCC_NONE                        = 0x00000000,
	MCC_IS_SINGLE_BIT               = 0x00000001,
	MCC_IS_MULTI_BIT                = 0x00000002,
});

/**
 * MCC ECC versions.
 */
typedef enum {
	MCC_ECC_V1,

	// Metadata
	MCC_ECC_NUM_VERSIONS
} mcc_ecc_version_t;

/**
 * MCC ECC event descriptor.
 *
 * @note If a new MCC ECC version has been added, because i.e. future hardware must log new or different data,
 * new fields should be appended to this struct to represent the new data.  No fields should be
 * deleted from this struct unless the field corresponds only to hardware that has been deprecated.
 */
typedef struct {
	/* Version of this struct. */
	mcc_ecc_version_t version;
	/* Flags used to describe the error. */
	mcc_flags_t flags;
	/* Interrupt status at the time of the MCC error. */
	uint32_t status;
	/* AMCC on which the error occurred. */
	uint32_t amcc;
	/* Plane of the AMCC on which the error occurred. */
	uint32_t plane;
	/* MemCache error Bank of first one bit error. */
	uint32_t bank;
	/* MemCache error Way of first one bit error. */
	uint32_t way;
	/* MemCache error Index of first one bit error. */
	uint32_t index;
	/* Indicates whether the error is in upper half cache line or lower half cache line. */
	uint32_t bit_off_cl;
	/* MemCache one bit error bit offset of first one bit error with in half cache line. */
	uint32_t bit_off_within_hcl;
} mcc_ecc_event_t;


__END_DECLS
