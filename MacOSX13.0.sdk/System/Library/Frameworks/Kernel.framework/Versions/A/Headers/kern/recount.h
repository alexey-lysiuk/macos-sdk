// Copyright (c) 2021 Apple Inc.  All rights reserved.
//
// @APPLE_OSREFERENCE_LICENSE_HEADER_START@
//
// This file contains Original Code and/or Modifications of Original Code
// as defined in and that are subject to the Apple Public Source License
// Version 2.0 (the 'License'). You may not use this file except in
// compliance with the License. The rights granted to you under the License
// may not be used to create, or enable the creation or redistribution of,
// unlawful or unlicensed copies of an Apple operating system, or to
// circumvent, violate, or enable the circumvention or violation of, any
// terms of an Apple operating system software license agreement.
//
// Please obtain a copy of the License at
// http://www.opensource.apple.com/apsl/ and read it before using this file.
//
// The Original Code and all software distributed under the License are
// distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
// INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
// Please see the License for the specific language governing rights and
// limitations under the License.
//
// @APPLE_OSREFERENCE_LICENSE_HEADER_END@

#ifndef KERN_RECOUNT_H
#define KERN_RECOUNT_H

#include <os/base.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/_types/_size_t.h>

__BEGIN_DECLS;

// Recount maintains counters for resources used by software, like CPU time and cycles.
// These counters are tracked at different levels of granularity depending on what execution bucket they're tracked in.
// For instance, while threads only differentiate on the broad CPU kinds due to memory constraints,
// the fewer number of tasks are free to use more memory and accumulate counters per-CPU.
//
// At context-switch, the scheduler calls `recount_context_switch` to update the counters.
// The difference between the current counter values and per-CPU snapshots are added to each thread.
// On modern systems with fast timebase reads, the counters are also updated on entering and exiting the kernel.

#pragma mark - config

// A level of the system's CPU topology, used as the precision when tracking
// counter values.
__enum_decl(recount_topo_t, unsigned int, {
	RCT_TOPO_SYSTEM,
	RCT_TOPO_CPU,
	RCT_TOPO_CPU_KIND,
	RCT_TOPO_COUNT,
});

// Get the number of elements in an array for per-topography data.
size_t recount_topo_count(recount_topo_t topo);

// Recount's definitions of CPU kinds, in lieu of one from the platform layers.
__enum_decl(recount_cpu_kind_t, unsigned int, {
	RCT_CPU_EFFICIENCY,
	RCT_CPU_PERFORMANCE,
	RCT_CPU_KIND_COUNT,
});

// A `recount_plan` structure controls the granularity of counting for a set of
// tracks and must be consulted when updating their counters.
typedef const struct recount_plan {
	const char *rpl_name;
	recount_topo_t rpl_topo;
} *recount_plan_t;

#define RECOUNT_PLAN_DECLARE(_name) \
    extern const struct recount_plan _name;

#define RECOUNT_PLAN_DEFINE(_name, _topo) \
	const struct recount_plan _name = { \
	        .rpl_name = #_name, \
	        .rpl_topo = _topo, \
	}

// The current objects with resource accounting policies.
RECOUNT_PLAN_DECLARE(recount_thread_plan);
RECOUNT_PLAN_DECLARE(recount_task_plan);
RECOUNT_PLAN_DECLARE(recount_task_terminated_plan);
RECOUNT_PLAN_DECLARE(recount_coalition_plan);
RECOUNT_PLAN_DECLARE(recount_processor_plan);

#pragma mark - generic accounting

// A track is where counter values can be updated atomically for readers by a
// single writer.
struct recount_track {
	uint32_t rt_sync;
	uint32_t rt_pad;

	// The CPU usage metrics currently supported by Recount.
	struct recount_usage {
		uint64_t ru_user_time_mach;
		uint64_t ru_system_time_mach;
#if CONFIG_PERVASIVE_CPI
		uint64_t ru_cycles;
		uint64_t ru_instructions;
#endif // CONFIG_PERVASIVE_CPI
#if CONFIG_PERVASIVE_ENERGY
		uint64_t ru_energy_nj;
#endif // CONFIG_PERVASIVE_ENERGY
	} rt_usage;
};

// Memory management routines for tracks and usage structures.
struct recount_track *recount_tracks_create(recount_plan_t plan);
void recount_tracks_destroy(recount_plan_t plan, struct recount_track *tracks);
struct recount_usage *recount_usage_alloc(recount_topo_t topo);
void recount_usage_free(recount_topo_t topo, struct recount_usage *usage);

// Attribute tracks to usage structures, to read their values for typical high-level interfaces.

// Sum any tracks to a single sum.
void recount_sum(recount_plan_t plan, const struct recount_track *tracks,
    struct recount_usage *sum);

// Summarize tracks into a total sum and another for a particular CPU kind.
void recount_sum_and_isolate_cpu_kind(recount_plan_t plan,
    struct recount_track *tracks, recount_cpu_kind_t kind,
    struct recount_usage *sum, struct recount_usage *only_kind);
// The same as above, but for usage-only objects, like coalitions.
void recount_sum_usage_and_isolate_cpu_kind(recount_plan_t plan,
    struct recount_usage *usage_list, recount_cpu_kind_t kind,
    struct recount_usage *sum, struct recount_usage *only_kind);

// Sum the counters for each perf-level, in the order returned by the sysctls.
void recount_sum_perf_levels(recount_plan_t plan,
    struct recount_track *tracks, struct recount_usage *sums);

#pragma mark - xnu internals



__END_DECLS

#endif // KERN_RECOUNT_H
