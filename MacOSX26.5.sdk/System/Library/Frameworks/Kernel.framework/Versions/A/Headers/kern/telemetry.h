/*
 * Copyright (c) 2012-2013 Apple Inc. All rights reserved.
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

#ifndef _KERNEL_TELEMETRY_H_
#define _KERNEL_TELEMETRY_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <mach/mach_types.h>
#include <kern/kcdata.h>
#include <kern/debug.h>

__BEGIN_DECLS


__enum_decl(telemetry_command_t, uint64_t, {
	/*
	 * Set up PMI-based microstackshot sampling.
	 *
	 * - deadline: telemetry_pmi_t
	 * - interval: PMI period
	 */
	TELEMETRY_CMD_PMI_SETUP = 3,
	/*
	 * Set up page-in file and offset tracing with parameters.
	 * This is meant to be called during boot to allow user space to control
	 * buffer sizes.
	 *
	 * - deadline: buffer size
	 */
	TELEMETRY_CMD_PAGEIN_SETUP = 4,

	/*
	 * Read back paged-in files and offsets.
	 * This also stops tracing.
	 *
	 * Pass a buffer of size 0 to get amount of space needed.  This is a
	 * lower-bound; if telemetry is still active, additional events will
	 * increase the buffer space needed.
	 *
	 * - deadline: buffer to read pagein data to
	 * - interval: buffer size
	 */
	TELEMETRY_CMD_PAGEIN_READ = 5,

	/*
	 * Set up memory usage microstackshot sampling.
	 *
	 * - deadline: a per-CPU period of VM faults to sample on
	 * - interval: a per-CPU period of page grabs to sample on
	 */
	TELEMETRY_CMD_MEMORY_USAGE_SETUP = 6,
});

/*
 * PMI-based telemetry
 */

__enum_decl(telemetry_pmi_t, uint32_t, {
	TELEMETRY_PMI_NONE,
	TELEMETRY_PMI_INSTRS,
	TELEMETRY_PMI_CYCLES,
});

/*
 * Page-in Telemetry
 */

__options_decl(telemetry_pagein_flags_t, uint64_t, {
	TELEMETRY_PAGEIN_BASE = 0x00,
});

#define TELEMETRY_PAGEIN_MAGIC 0x70616765

/**
 * The first bytes of a successful `TELEMETRY_CMD_PAGEIN_READ`.
 */
struct telemetry_pagein_header {
	uint32_t tph_magic;
	uint32_t tph_version;
	uint32_t tph_pagein_count;
	uint32_t tph_reserved;
	uint64_t tph_flags;
	uint64_t tph_duration_mct;
};

/**
 * Details about a page-in, for communicating telemetry to user space.
 */
struct telemetry_pagein {
	uint64_t tp_fsid;
	uint64_t tp_fsobj_id;
	int64_t  tp_file_offset;
};

/**
 * How page-in data is copied out to user space.
 */
struct telemetry_pagein_buffer {
	struct telemetry_pagein_header tpb_header;
	struct telemetry_pagein        tpb_pageins[0];
};

/**
 * Flags to report for fault samples.
 */
__options_decl(telemetry_vm_fault_flags_t, uint16_t, {
	TM_VMF_BASE = 0x0,
});

/**
 * The kind of page grab that occurred in a sample.
 */
__enum_decl(telemetry_page_grab_t, uint8_t, {
	TM_PG_UPL = 1,
	TM_PG_IOPL = 2,
});

/**
 * Flags to report for page grab samples.
 */
__options_decl(telemetry_page_grab_flags_t, uint8_t, {
	TM_PGF_BASE = 0x0,
});

/**
 * The data layout of task data in a microstackshot sample.
 *
 * XXX This is overlaid on a `struct task_snapshot` and the order of the
 * fields must not change.
 */
struct microstackshot_task {
	uint32_t mst_magic;
	int32_t  mst_pid;
	uint64_t mst_task_uniqueid;
	uint64_t mst_user_term_mach_time;
	uint64_t mst_system_term_mach_time;
	uint8_t  mst_shared_cache_identifier[16];
	uint64_t mst_shared_cache_slide;
	uint32_t mst_loadinfo_count;
	uint32_t mst_suspend_count;
	uint32_t mst_page_count;
	uint32_t mst_fault_count;
	uint32_t mst_pagein_count;
	uint32_t mst_cow_fault_count;
	uint32_t mst_stackshot_flags_trunc;
	uint64_t mst_resource_coal_id;
	int32_t  mst_on_behalf_origin_pid;
	int32_t  mst_on_behalf_proximate_pid;
	char     mst_proc_comm_name[17];
	uint32_t mst_was_throttled;
	uint32_t mst_did_throttle;
	uint32_t mst_latency_qos;
	uint64_t mst_stackshot_flags;
	uint64_t mst_energy_nj;
	uint64_t mst_page_grab_count;
	uint64_t mst_iopl_upl_page_grab_count;
	char     mst_proc_name_extra[32];
	struct {
		uint32_t mstm_telemetry_generation;
		uint32_t mstm_telemetry_source;
		uint64_t mstm_telemetry_period;
		uint64_t mstm_serial_number;
		uint64_t mstm_telemetry_skipped;
	} mst_metadata;
	uint64_t mst_reserved[8];
	uint32_t mst_reserved32[1];
} __attribute__((packed));

_Static_assert(sizeof(struct microstackshot_task) == sizeof(struct task_snapshot),
    "microstackshot's version of the snapshot must be the same size for ABI compatibility");
_Static_assert(offsetof(struct microstackshot_task, mst_proc_name_extra) ==
    offsetof(struct task_snapshot, io_priority_count),
    "microstackshot's usage of io_priority_count should be ABI compatible with task_snaphsot");

/**
 * The data layout of thread data in a microstackshot sample.
 *
 * XXX This is overlaid on a `struct thread_snapshot` and the order of the
 * fields must not change.
 */
struct microstackshot_thread {
	uint32_t msth_magic;
	uint32_t msth_kern_frame_count;
	uint32_t msth_user_frame_count;
	uint64_t msth_wait_event;
	uint64_t msth_continuation;
	uint64_t msth_thread_id;
	uint64_t msth_user_mach_time;
	uint64_t msth_system_mach_time;
	int32_t  msth_state;
	int32_t  msth_base_priority;
	int32_t  msth_sched_priority;
	int32_t  msth_sched_flags;
	uint8_t  msth_stackshot_flags;
	uint8_t  msth_effective_qos;
	uint8_t  msth_requested_qos;
	uint8_t  msth_requested_qos_override;
	uint8_t  msth_io_tier;

	uint8_t  msth_reserved_c;
	uint16_t msth_async_index;

	uint64_t msth_fault_va;
	uint16_t msth_reserved_fault1;
	uint16_t msth_fault_type;
	uint16_t msth_reserved_fault2;
	uint16_t msth_fault_flags; /* telemetry_vm_fault_flags_t */

	uint16_t msth_reserved_grab1;
	uint16_t msth_grab_vm_tag; /* Kernel Tags in vm_statistics.h */
	uint16_t msth_grab_iopl_count;
	uint16_t msth_grab_upl_count;

	uint64_t  msth_reserved[19];
	char      msth_name[STACKSHOT_MAX_THREAD_NAME_SIZE];
} __attribute__((packed));

_Static_assert(sizeof(struct microstackshot_thread) == sizeof(struct thread_snapshot),
    "microstackshot's version of the snapshot must be the same size for ABI compatibility");
_Static_assert(offsetof(struct microstackshot_thread, msth_async_index) ==
    offsetof(struct thread_snapshot, _reserved) + 1,
    "microstackshot's usage of async index should be ABI compatible with task_snaphsot");
_Static_assert(offsetof(struct microstackshot_thread, msth_reserved_fault1) ==
    offsetof(struct thread_snapshot, disk_reads_size),
    "microstackshot's usage of disk_reads_size should be ABI compatible with thread_snaphsot");
_Static_assert(offsetof(struct microstackshot_thread, msth_reserved_grab1) ==
    offsetof(struct thread_snapshot, disk_writes_count),
    "microstackshot's usage of disk_writes_count should be ABI compatible with thread_snaphsot");

__END_DECLS



#endif /* _KERNEL_TELEMETRY_H_ */
