/*
 * Copyright (c) 2007-2021 Apple Inc. All rights reserved.
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
/*
 * @OSF_COPYRIGHT@
 */

#ifndef _ARM_MACHINE_ROUTINES_H_
#define _ARM_MACHINE_ROUTINES_H_

#include <mach/mach_types.h>
#include <mach/vm_types.h>
#include <mach/boolean.h>
#include <kern/kern_types.h>
#include <pexpert/pexpert.h>

#include <sys/cdefs.h>
#include <sys/appleapiopts.h>

#include <stdarg.h>


__BEGIN_DECLS

/* Interrupt handling */

void ml_cpu_signal(unsigned int cpu_id);
void ml_cpu_signal_deferred_adjust_timer(uint64_t nanosecs);
uint64_t ml_cpu_signal_deferred_get_timer(void);
void ml_cpu_signal_deferred(unsigned int cpu_id);
void ml_cpu_signal_retract(unsigned int cpu_id);
bool ml_cpu_signal_is_enabled(void);

/* Initialize Interrupts */
void    ml_init_interrupt(void);

/* Get Interrupts Enabled */
boolean_t ml_get_interrupts_enabled(void);

/* Set Interrupts Enabled */
#if __has_feature(ptrauth_calls)
uint64_t ml_pac_safe_interrupts_disable(void);
void ml_pac_safe_interrupts_restore(uint64_t);
#endif /* __has_feature(ptrauth_calls) */
boolean_t ml_set_interrupts_enabled_with_debug(boolean_t enable, boolean_t debug);
boolean_t ml_set_interrupts_enabled(boolean_t enable);
boolean_t ml_early_set_interrupts_enabled(boolean_t enable);

/*
 * Functions for disabling measurements for AppleCLPC only.
 */
boolean_t sched_perfcontrol_ml_set_interrupts_without_measurement(boolean_t enable);
void sched_perfcontrol_abandon_preemption_disable_measurement(void);

/* Check if running at interrupt context */
boolean_t ml_at_interrupt_context(void);


/* Generate a fake interrupt */
void ml_cause_interrupt(void);

#if HAS_SIQ
void siq_init(void);
void siq_cpu_init(void);
#endif


/* Type for the Time Base Enable function */
typedef void (*time_base_enable_t)(cpu_id_t cpu_id, boolean_t enable);

#define CacheConfig                     0x00000000UL
#define CacheControl                    0x00000001UL
#define CacheClean                      0x00000002UL
#define CacheCleanRegion                0x00000003UL
#define CacheCleanFlush                 0x00000004UL
#define CacheCleanFlushRegion           0x00000005UL
#define CacheShutdown                   0x00000006UL

#define CacheControlEnable              0x00000000UL

#define CacheConfigCCSIDR               0x00000001UL
#define CacheConfigSize                 0x00000100UL

/* Type for the Processor Idle function */
typedef void (*processor_idle_t)(cpu_id_t cpu_id, boolean_t enter, uint64_t *new_timeout_ticks);

/* Type for the Idle Tickle function */
typedef void (*idle_tickle_t)(void);

/* Type for the Idle Timer function */
typedef void (*idle_timer_t)(void *refcon, uint64_t *new_timeout_ticks);

/* Type for the IPI Hander */
typedef void (*ipi_handler_t)(void);

/* Type for the Lockdown Hander */
typedef void (*lockdown_handler_t)(void *);

/* Type for the Platform specific Error Handler */
typedef void (*platform_error_handler_t)(void *refcon, vm_offset_t fault_addr);

/*
 * The exception callback (ex_cb) module is obsolete.  Some definitions related
 * to ex_cb were exported through the SDK, and are only left here for historical
 * reasons.
 */

/* Unused.  Left for historical reasons. */
typedef enum{
	EXCB_CLASS_ILLEGAL_INSTR_SET,
#ifdef CONFIG_XNUPOST
	EXCB_CLASS_TEST1,
	EXCB_CLASS_TEST2,
	EXCB_CLASS_TEST3,
#endif
	EXCB_CLASS_MAX
}
ex_cb_class_t;

/* Unused.  Left for historical reasons. */
typedef enum{
	EXCB_ACTION_RERUN,
	EXCB_ACTION_NONE,
#ifdef CONFIG_XNUPOST
	EXCB_ACTION_TEST_FAIL,
#endif
}
ex_cb_action_t;

/* Unused.  Left for historical reasons. */
typedef struct{
	vm_offset_t far;
}
ex_cb_state_t;

/* Unused.  Left for historical reasons. */
typedef ex_cb_action_t (*ex_cb_t) (
	ex_cb_class_t           cb_class,
	void                            *refcon,
	const ex_cb_state_t     *state
	);

/*
 * This function is unimplemented.  Its definition is left for historical
 * reasons.
 */
kern_return_t ex_cb_register(
	ex_cb_class_t   cb_class,
	ex_cb_t                 cb,
	void                    *refcon );

/*
 * This function is unimplemented.  Its definition is left for historical
 * reasons.
 */
ex_cb_action_t ex_cb_invoke(
	ex_cb_class_t   cb_class,
	vm_offset_t         far);

typedef enum {
	CLUSTER_TYPE_SMP,
	CLUSTER_TYPE_E,
	CLUSTER_TYPE_P,
	MAX_CPU_TYPES,
} cluster_type_t;

void ml_parse_cpu_topology(void);

unsigned int ml_get_cpu_count(void);

unsigned int ml_get_cpu_number_type(cluster_type_t cluster_type, bool logical, bool available);

unsigned int ml_get_cluster_number_type(cluster_type_t cluster_type);

unsigned int ml_cpu_cache_sharing(unsigned int level, cluster_type_t cluster_type, bool include_all_cpu_types);

unsigned int ml_get_cpu_types(void);

int ml_get_boot_cpu_number(void);

int ml_get_cpu_number(uint32_t phys_id);

unsigned int ml_get_cpu_number_local(void);

int ml_get_cluster_number(uint32_t phys_id);

int ml_get_max_cpu_number(void);

int ml_get_max_cluster_number(void);

/*
 * Return the id of a cluster's first cpu.
 */
unsigned int ml_get_first_cpu_id(unsigned int cluster_id);

/*
 * Return the die id of a cluster.
 */
unsigned int ml_get_die_id(unsigned int cluster_id);

/*
 * Return the index of a cluster in its die.
 */
unsigned int ml_get_die_cluster_id(unsigned int cluster_id);

/*
 * Return the highest die id of the system.
 */
unsigned int ml_get_max_die_id(void);

#ifdef __arm64__
int ml_get_cluster_number_local(void);
#endif /* __arm64__ */

/* Struct for ml_cpu_get_info */
struct ml_cpu_info {
	unsigned long           vector_unit;
	unsigned long           cache_line_size;
	unsigned long           l1_icache_size;
	unsigned long           l1_dcache_size;
	unsigned long           l2_settings;
	unsigned long           l2_cache_size;
	unsigned long           l3_settings;
	unsigned long           l3_cache_size;
};
typedef struct ml_cpu_info ml_cpu_info_t;

cluster_type_t ml_get_boot_cluster_type(void);

/*!
 * @typedef ml_topology_cpu_t
 * @brief Describes one CPU core in the topology.
 *
 * @field cpu_id            Logical CPU ID: 0, 1, 2, 3, 4, ...
 *                          Dynamically assigned by XNU so it might not match EDT.  No holes.
 * @field phys_id           Physical CPU ID (EDT: reg).  Same as MPIDR[15:0], i.e.
 *                          (cluster_id << 8) | core_number_within_cluster
 * @field cluster_id        Logical Cluster ID: 0, 1, 2, 3, 4, ...
 *                          Dynamically assigned by XNU so it might not match EDT.  No holes.
 * @field die_id            Die ID (EDT: die-id)
 * @field cluster_type      The type of CPUs found in this cluster.
 * @field l2_access_penalty Indicates that the scheduler should try to de-prioritize a core because
 *                          L2 accesses are slower than on the boot processor.
 * @field l2_cache_size     Size of the L2 cache, in bytes.  0 if unknown or not present.
 * @field l2_cache_id       l2-cache-id property read from EDT.
 * @field l3_cache_size     Size of the L3 cache, in bytes.  0 if unknown or not present.
 * @field l3_cache_id       l3-cache-id property read from EDT.
 * @field cpu_IMPL_regs     IO-mapped virtual address of cpuX_IMPL (implementation-defined) register block.
 * @field cpu_IMPL_pa       Physical address of cpuX_IMPL register block.
 * @field cpu_IMPL_len      Length of cpuX_IMPL register block.
 * @field cpu_UTTDBG_regs   IO-mapped virtual address of cpuX_UTTDBG register block.
 * @field cpu_UTTDBG_pa     Physical address of cpuX_UTTDBG register block, if set in DT, else zero
 * @field cpu_UTTDBG_len    Length of cpuX_UTTDBG register block, if set in DT, else zero
 * @field coresight_regs    IO-mapped virtual address of CoreSight debug register block.
 * @field coresight_pa      Physical address of CoreSight register block.
 * @field coresight_len     Length of CoreSight register block.
 * @field die_cluster_id    Physical cluster ID within the local die (EDT: die-cluster-id)
 * @field cluster_core_id   Physical core ID within the local cluster (EDT: cluster-core-id)
 */
typedef struct ml_topology_cpu {
	unsigned int                    cpu_id;
	uint32_t                        phys_id;
	unsigned int                    cluster_id;
	unsigned int                    die_id;
	cluster_type_t                  cluster_type;
	uint32_t                        l2_access_penalty;
	uint32_t                        l2_cache_size;
	uint32_t                        l2_cache_id;
	uint32_t                        l3_cache_size;
	uint32_t                        l3_cache_id;
	vm_offset_t                     cpu_IMPL_regs;
	uint64_t                        cpu_IMPL_pa;
	uint64_t                        cpu_IMPL_len;
	vm_offset_t                     cpu_UTTDBG_regs;
	uint64_t                        cpu_UTTDBG_pa;
	uint64_t                        cpu_UTTDBG_len;
	vm_offset_t                     coresight_regs;
	uint64_t                        coresight_pa;
	uint64_t                        coresight_len;
	unsigned int                    die_cluster_id;
	unsigned int                    cluster_core_id;
} ml_topology_cpu_t;

/*!
 * @typedef ml_topology_cluster_t
 * @brief Describes one cluster in the topology.
 *
 * @field cluster_id        Cluster ID (EDT: cluster-id)
 * @field cluster_type      The type of CPUs found in this cluster.
 * @field num_cpus          Total number of usable CPU cores in this cluster.
 * @field first_cpu_id      The cpu_id of the first CPU in the cluster.
 * @field cpu_mask          A bitmask representing the cpu_id's that belong to the cluster.  Example:
 *                          If the cluster contains CPU4 and CPU5, cpu_mask will be 0x30.
 * @field acc_IMPL_regs     IO-mapped virtual address of acc_IMPL (implementation-defined) register block.
 * @field acc_IMPL_pa       Physical address of acc_IMPL register block.
 * @field acc_IMPL_len      Length of acc_IMPL register block.
 * @field cpm_IMPL_regs     IO-mapped virtual address of cpm_IMPL (implementation-defined) register block.
 * @field cpm_IMPL_pa       Physical address of cpm_IMPL register block.
 * @field cpm_IMPL_len      Length of cpm_IMPL register block.
 */
typedef struct ml_topology_cluster {
	unsigned int                    cluster_id;
	cluster_type_t                  cluster_type;
	unsigned int                    num_cpus;
	unsigned int                    first_cpu_id;
	uint64_t                        cpu_mask;
	vm_offset_t                     acc_IMPL_regs;
	uint64_t                        acc_IMPL_pa;
	uint64_t                        acc_IMPL_len;
	vm_offset_t                     cpm_IMPL_regs;
	uint64_t                        cpm_IMPL_pa;
	uint64_t                        cpm_IMPL_len;
} ml_topology_cluster_t;

// Bump this version number any time any ml_topology_* struct changes, so
// that KPI users can check whether their headers are compatible with
// the running kernel.
#define CPU_TOPOLOGY_VERSION 1

/*!
 * @typedef ml_topology_info_t
 * @brief Describes the CPU topology for all APs in the system.  Populated from EDT and read-only at runtime.
 * @discussion This struct only lists CPU cores that are considered usable by both iBoot and XNU.  Some
 *             physically present CPU cores may be considered unusable due to configuration options like
 *             the "cpus=" boot-arg.  Cores that are disabled in hardware will not show up in EDT at all, so
 *             they also will not be present in this struct.
 *
 * @field version           Version of the struct (set to CPU_TOPOLOGY_VERSION).
 * @field num_cpus          Total number of usable CPU cores.
 * @field max_cpu_id        The highest usable logical CPU ID.
 * @field num_clusters      Total number of AP CPU clusters on the system (usable or not).
 * @field max_cluster_id    The highest cluster ID found in EDT.
 * @field cpus              List of |num_cpus| entries.
 * @field clusters          List of |num_clusters| entries.
 * @field boot_cpu          Points to the |cpus| entry for the boot CPU.
 * @field boot_cluster      Points to the |clusters| entry which contains the boot CPU.
 * @field chip_revision     Silicon revision reported by iBoot, which comes from the
 *                          SoC-specific fuse bits.  See CPU_VERSION_xx macros for definitions.
 */
typedef struct ml_topology_info {
	unsigned int                    version;
	unsigned int                    num_cpus;
	unsigned int                    max_cpu_id;
	unsigned int                    num_clusters;
	unsigned int                    max_cluster_id;
	unsigned int                    max_die_id;
	ml_topology_cpu_t               *cpus;
	ml_topology_cluster_t           *clusters;
	ml_topology_cpu_t               *boot_cpu;
	ml_topology_cluster_t           *boot_cluster;
	unsigned int                    chip_revision;
	unsigned int                    cluster_types;
	unsigned int                    cluster_type_num_cpus[MAX_CPU_TYPES];
	unsigned int                    cluster_type_num_clusters[MAX_CPU_TYPES];
} ml_topology_info_t;

/*!
 * @function ml_get_topology_info
 * @result A pointer to the read-only topology struct.  Does not need to be freed.  Returns NULL
 *         if the struct hasn't been initialized or the feature is unsupported.
 */
const ml_topology_info_t *ml_get_topology_info(void);

/*!
 * @function ml_map_cpu_pio
 * @brief Maps per-CPU and per-cluster PIO registers found in EDT.  This needs to be
 *        called after arm_vm_init() so it can't be part of ml_parse_cpu_topology().
 */
void ml_map_cpu_pio(void);

/* Struct for ml_processor_register */
struct ml_processor_info {
	cpu_id_t                        cpu_id;
	vm_offset_t                     start_paddr;
	boolean_t                       supports_nap;
	void                            *platform_cache_dispatch;
	time_base_enable_t              time_base_enable;
	processor_idle_t                processor_idle;
	idle_tickle_t                   *idle_tickle;
	idle_timer_t                    idle_timer;
	void                            *idle_timer_refcon;
	vm_offset_t                     powergate_stub_addr;
	uint32_t                        powergate_stub_length;
	uint32_t                        powergate_latency;
	platform_error_handler_t        platform_error_handler;
	uint64_t                        regmap_paddr;
	uint32_t                        phys_id;
	uint32_t                        log_id;
	uint32_t                        l2_access_penalty;
	uint32_t                        cluster_id;
	cluster_type_t                  cluster_type;
	uint32_t                        l2_cache_id;
	uint32_t                        l2_cache_size;
	uint32_t                        l3_cache_id;
	uint32_t                        l3_cache_size;
};
typedef struct ml_processor_info ml_processor_info_t;



/*!
 * @function ml_processor_register
 *
 * @abstract callback from platform kext to register processor
 *
 * @discussion This function is called by the platform kext when a processor is
 * being registered.  This is called while running on the CPU itself, as part of
 * its initialization.
 *
 * @param ml_processor_info provides machine-specific information about the
 * processor to xnu.
 *
 * @param processor is set as an out-parameter to an opaque handle that should
 * be used by the platform kext when referring to this processor in the future.
 *
 * @param ipi_handler is set as an out-parameter to the function that should be
 * registered as the IPI handler.
 *
 * @param pmi_handler is set as an out-parameter to the function that should be
 * registered as the PMI handler.
 *
 * @returns KERN_SUCCESS on success and an error code, otherwise.
 */
kern_return_t ml_processor_register(ml_processor_info_t *ml_processor_info,
    processor_t *processor, ipi_handler_t *ipi_handler,
    perfmon_interrupt_handler_func *pmi_handler);

/* Register a lockdown handler */
kern_return_t ml_lockdown_handler_register(lockdown_handler_t, void *);

/* Register a M$ flushing  */
typedef kern_return_t (*mcache_flush_function)(void *service);
kern_return_t ml_mcache_flush_callback_register(mcache_flush_function func, void *service);
kern_return_t ml_mcache_flush(void);


/* Initialize Interrupts */
void ml_install_interrupt_handler(
	void *nub,
	int source,
	void *target,
	IOInterruptHandler handler,
	void *refCon);

vm_offset_t
    ml_static_vtop(
	vm_offset_t);

kern_return_t
ml_static_verify_page_protections(
	uint64_t base, uint64_t size, vm_prot_t prot);

vm_offset_t
    ml_static_ptovirt(
	vm_offset_t);

/* Offset required to obtain absolute time value from tick counter */
uint64_t ml_get_abstime_offset(void);

/* Offset required to obtain continuous time value from tick counter */
uint64_t ml_get_conttime_offset(void);

#ifdef __APPLE_API_UNSTABLE
/* PCI config cycle probing */
boolean_t ml_probe_read(
	vm_offset_t paddr,
	unsigned int *val);
boolean_t ml_probe_read_64(
	addr64_t paddr,
	unsigned int *val);

/* Read physical address byte */
unsigned int ml_phys_read_byte(
	vm_offset_t paddr);
unsigned int ml_phys_read_byte_64(
	addr64_t paddr);

/* Read physical address half word */
unsigned int ml_phys_read_half(
	vm_offset_t paddr);
unsigned int ml_phys_read_half_64(
	addr64_t paddr);

/* Read physical address word*/
unsigned int ml_phys_read(
	vm_offset_t paddr);
unsigned int ml_phys_read_64(
	addr64_t paddr);
unsigned int ml_phys_read_word(
	vm_offset_t paddr);
unsigned int ml_phys_read_word_64(
	addr64_t paddr);

/* Read physical address double word */
unsigned long long ml_phys_read_double(
	vm_offset_t paddr);
unsigned long long ml_phys_read_double_64(
	addr64_t paddr);

/* Write physical address byte */
void ml_phys_write_byte(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_byte_64(
	addr64_t paddr, unsigned int data);

/* Write physical address half word */
void ml_phys_write_half(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_half_64(
	addr64_t paddr, unsigned int data);

/* Write physical address word */
void ml_phys_write(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_64(
	addr64_t paddr, unsigned int data);
void ml_phys_write_word(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_word_64(
	addr64_t paddr, unsigned int data);

/* Write physical address double word */
void ml_phys_write_double(
	vm_offset_t paddr, unsigned long long data);
void ml_phys_write_double_64(
	addr64_t paddr, unsigned long long data);

#if defined(__SIZEOF_INT128__) && APPLE_ARM64_ARCH_FAMILY
/*
 * Not all dependent projects consuming `machine_routines.h` are built using
 * toolchains that support 128-bit integers.
 */
#define BUILD_QUAD_WORD_FUNCS 1
#else
#define BUILD_QUAD_WORD_FUNCS 0
#endif /* defined(__SIZEOF_INT128__) && APPLE_ARM64_ARCH_FAMILY */

#if BUILD_QUAD_WORD_FUNCS
/*
 * Not all dependent projects have their own typedef of `uint128_t` at the
 * time they consume `machine_routines.h`.
 */
typedef unsigned __int128 uint128_t;

/* Read physical address quad word */
uint128_t ml_phys_read_quad(
	vm_offset_t paddr);
uint128_t ml_phys_read_quad_64(
	addr64_t paddr);

/* Write physical address quad word */
void ml_phys_write_quad(
	vm_offset_t paddr, uint128_t data);
void ml_phys_write_quad_64(
	addr64_t paddr, uint128_t data);
#endif /* BUILD_QUAD_WORD_FUNCS */

void ml_static_mfree(
	vm_offset_t,
	vm_size_t);

kern_return_t
ml_static_protect(
	vm_offset_t start,
	vm_size_t size,
	vm_prot_t new_prot);

/* virtual to physical on wired pages */
vm_offset_t ml_vtophys(
	vm_offset_t vaddr);

/* Get processor cache info */
void ml_cpu_get_info(ml_cpu_info_t *ml_cpu_info);
void ml_cpu_get_info_type(ml_cpu_info_t * ml_cpu_info, cluster_type_t cluster_type);

#endif /* __APPLE_API_UNSTABLE */

typedef int ml_page_protection_t;

/* Return the type of page protection supported */
ml_page_protection_t ml_page_protection_type(void);

#ifdef __APPLE_API_PRIVATE

/* Zero bytes starting at a physical address */
void bzero_phys(
	addr64_t phys_address,
	vm_size_t length);

void bzero_phys_nc(addr64_t src64, vm_size_t bytes);


void ml_thread_policy(
	thread_t thread,
	unsigned policy_id,
	unsigned policy_info);

#define MACHINE_GROUP                                   0x00000001
#define MACHINE_NETWORK_GROUP                   0x10000000
#define MACHINE_NETWORK_WORKLOOP                0x00000001
#define MACHINE_NETWORK_NETISR                  0x00000002

/* Set the maximum number of CPUs */
void ml_set_max_cpus(
	unsigned int max_cpus);

/* Return the maximum number of CPUs set by ml_set_max_cpus(), waiting if necessary */
unsigned int ml_wait_max_cpus(
	void);

/* Return the maximum memory size */
unsigned int ml_get_machine_mem(void);


extern void     ml_cpu_init_completed(void);
extern void     ml_cpu_up(void);
extern void     ml_cpu_down(void);
/*
 * The update to CPU counts needs to be separate from other actions
 * in ml_cpu_up() and ml_cpu_down()
 * because we don't update the counts when CLPC causes temporary
 * cluster powerdown events, as these must be transparent to the user.
 */
extern void     ml_cpu_up_update_counts(int cpu_id);
extern void     ml_cpu_down_update_counts(int cpu_id);
extern void     ml_arm_sleep(void);

extern uint64_t ml_get_wake_timebase(void);
extern uint64_t ml_get_conttime_wake_time(void);

/* Time since the system was reset (as part of boot/wake) */
uint64_t ml_get_time_since_reset(void);

/*
 * Called by ApplePMGR to set wake time.  Units and epoch are identical
 * to mach_continuous_time().  Has no effect on !HAS_CONTINUOUS_HWCLOCK
 * chips.  If wake_time == UINT64_MAX, that means the wake time is
 * unknown and calls to ml_get_time_since_reset() will return UINT64_MAX.
 */
void ml_set_reset_time(uint64_t wake_time);


/* Bytes available on current stack */
vm_offset_t ml_stack_remaining(void);


extern  uint32_t        arm_debug_read_dscr(void);

extern int      set_be_bit(void);
extern int      clr_be_bit(void);
extern int      be_tracing(void);

/* Please note that cpu_broadcast_xcall is not as simple is you would like it to be.
 * It will sometimes put the calling thread to sleep, and it is up to your callback
 * to wake it up as needed, where "as needed" is defined as "all other CPUs have
 * called the broadcast func". Look around the kernel for examples, or instead use
 * cpu_broadcast_xcall_simple() which does indeed act like you would expect, given
 * the prototype. cpu_broadcast_immediate_xcall has the same caveats and has a similar
 * _simple() wrapper
 */
typedef void (*broadcastFunc) (void *);
unsigned int cpu_broadcast_xcall(uint32_t *, boolean_t, broadcastFunc, void *);
unsigned int cpu_broadcast_xcall_simple(boolean_t, broadcastFunc, void *);
__result_use_check kern_return_t cpu_xcall(int, broadcastFunc, void *);
unsigned int cpu_broadcast_immediate_xcall(uint32_t *, boolean_t, broadcastFunc, void *);
unsigned int cpu_broadcast_immediate_xcall_simple(boolean_t, broadcastFunc, void *);
__result_use_check kern_return_t cpu_immediate_xcall(int, broadcastFunc, void *);


boolean_t machine_timeout_suspended(void);
void ml_get_power_state(boolean_t *, boolean_t *);

uint32_t get_arm_cpu_version(void);
boolean_t user_cont_hwclock_allowed(void);
uint8_t user_timebase_type(void);
boolean_t ml_thread_is64bit(thread_t thread);

#ifdef __arm64__
bool ml_feature_supported(uint32_t feature_bit);
void ml_set_align_checking(void);
extern void wfe_timeout_configure(void);
extern void wfe_timeout_init(void);
#endif /* __arm64__ */

void ml_timer_evaluate(void);
boolean_t ml_timer_forced_evaluation(void);
void ml_gpu_stat_update(uint64_t);
uint64_t ml_gpu_stat(thread_t);
#endif /* __APPLE_API_PRIVATE */





extern uint32_t phy_read_panic;
extern uint32_t phy_write_panic;
#if DEVELOPMENT || DEBUG
extern uint64_t simulate_stretched_io;
#endif

void ml_hibernate_active_pre(void);
void ml_hibernate_active_post(void);

void ml_report_minor_badness(uint32_t badness_id);
#define ML_MINOR_BADNESS_CONSOLE_BUFFER_FULL              0
#define ML_MINOR_BADNESS_MEMFAULT_REPORTING_NOT_ENABLED   1
#define ML_MINOR_BADNESS_PIO_WRITTEN_FROM_USERSPACE       2



__END_DECLS

#endif /* _ARM_MACHINE_ROUTINES_H_ */
