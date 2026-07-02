/*
 * Copyright (c) 2012-2025 Apple Inc. All rights reserved.
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

#ifndef KERN_KPC_H
#define KERN_KPC_H

/*
 * Kernel interfaces for the legacy KPC PMC infrastructure, superceded by
 * CPC.
 */

#include <kern/thread.h> /* thread_* */


__BEGIN_DECLS

#if CONFIG_CPU_COUNTERS
#if __arm64__
/* Defer to CPC on this. */
#define KPC_MAX_COUNTERS (CPMU_PMC_COUNT)
#elif __x86_64__
#define KPC_MAX_COUNTERS (8)
#endif // !__arm64__ && !__x86_64__
#else // CONFIG_CPU_COUNTERS
#define KPC_MAX_COUNTERS (0)
#endif // !CONFIG_CPU_COUNTERS

/**
 * A configuration word that's understood by KPC and supplied to the
 * underlying hardware.
 *
 * The low bits are passed as-is on Apple silicon, but higher bits encode
 * EL filtering attributes.
 */
typedef uint64_t kpc_config_t;

/*
 * KPC calls groups of similar counters "classes" and restructures arrays of
 * counter values and configuration to only include those counters.
 */

/*
 * The fixed instructions and cycles (and on Intel, reference cycles) counters.
 */
#define KPC_CLASS_FIXED         (0)
/*
 * The configurable counters that can be programmed with microarchitecture-
 * specific events.
 */
#define KPC_CLASS_CONFIGURABLE  (1)
/*
 * The set of configurable counters reserved by power management services.
 */
#define KPC_CLASS_POWER         (2)
/*
 * Only for configuration, allows setting extra CPMU registers as if they
 * were counter configurations.
 */
#define KPC_CLASS_RAWPMU        (3)

/*
 * The bit masks for the classes, to allow constraining the interfaces to just
 * the requested classes.
 */
#define KPC_CLASS_FIXED_MASK         (1u << KPC_CLASS_FIXED)
#define KPC_CLASS_CONFIGURABLE_MASK  (1u << KPC_CLASS_CONFIGURABLE)
#define KPC_CLASS_POWER_MASK         (1u << KPC_CLASS_POWER)
#define KPC_CLASS_RAWPMU_MASK        (1u << KPC_CLASS_RAWPMU)

/*
 * The kinds of "PMUs" that KPC supports.
 *
 * This was only used for Intel.
 */
#define KPC_PMU_ERROR     (0)
#define KPC_PMU_INTEL_V3  (1)
#define KPC_PMU_ARM_APPLE (2)
#define KPC_PMU_INTEL_V2  (3)
#define KPC_PMU_ARM_V2    (4)

/*
 * Whether the request for counter values through sysctl should collect
 * information for all CPUs.
 *
 * It's unclear how useful just getting the current CPU is for user space.
 */
#define KPC_ALL_CPUS (1u << 31)

/**
 * Callback for notification when PMCs are acquired/released by a task. The
 * argument is equal to TRUE if the Power Manager (PM) can use its reserved PMCs.
 * Otherwise, the argument is equal to FALSE.
 */
typedef void (*kpc_pm_handler_t)(boolean_t);

/* bootstrap */
extern void kpc_init(void);

/* Architecture specific initialisation */
extern void kpc_arch_init(void);

/* Get the bitmask of available classes */
extern uint32_t kpc_get_classes(void);

/* Get the bitmask of currently running counter classes  */
extern uint32_t kpc_get_running(void);

/* Get the version of KPC that's being run */
extern int kpc_get_pmu_version(void);

/* Set the bitmask of currently running counter classes. Specify
 * classes = 0 to stop counters
 */
extern int kpc_set_running(uint32_t classes);

/* Read CPU counters */
extern int kpc_get_cpu_counters(boolean_t all_cpus, uint32_t classes,
    int *curcpu, uint64_t *buf);

/* Read current thread's counter accumulations */
extern int kpc_get_curthread_counters(uint32_t *inoutcount, uint64_t *buf);

/* Given a config, how many counters and config registers there are */
extern uint32_t kpc_get_counter_count(uint32_t classes);
extern uint32_t kpc_get_config_count(uint32_t classes);

/* enable/disable thread counting */
extern uint32_t kpc_get_thread_counting(void);
extern int      kpc_set_thread_counting(uint32_t classes);

/* get and set config registers */
extern int kpc_get_config(uint32_t classes, kpc_config_t *current_config);
extern int kpc_set_config(uint32_t classes, kpc_config_t *new_config);

/* get and set PMI period */
extern int kpc_get_period(uint32_t classes, uint64_t *period);
extern int kpc_set_period(uint32_t classes, uint64_t *period);

/* get and set kperf actionid */
extern int kpc_get_actionid(uint32_t classes, uint32_t *actionid);
extern int kpc_set_actionid(uint32_t classes, uint32_t *actionid);

/* hooks on thread create and delete */
extern void kpc_thread_create(thread_t thread);
extern void kpc_thread_destroy(thread_t thread);

/* allocate a buffer big enough for all counters */
extern uint64_t *kpc_counterbuf_alloc(void);
extern void      kpc_counterbuf_free(uint64_t*);
extern uint32_t  kpc_get_counterbuf_size(void);

/* whether we're currently accounting into threads */
extern int kpc_threads_counting;

/* AST callback for KPC */
extern void kpc_thread_ast_handler( thread_t thread );



/* acquire/release the counters used by the Power Manager */
extern int kpc_force_all_ctrs( task_t task, int val );
extern int kpc_get_force_all_ctrs( void );

/*
 * Register the Power Manager as a PMCs user.
 *
 * This is a deprecated function used by old Power Managers, new Power Managers
 * should use the @em kpc_reserve_pm_counters() function. This function actually
 * calls @em kpc_reserve_pm_counters() with the following arguments:
 *      - handler	= handler
 *      - pmc_mask	= 0x83
 *      - custom_config	= TRUE
 *
 * See @em kpc_reserve_pm_counters() for more details about the return value.
 */
extern boolean_t kpc_register_pm_handler(void (*handler)(boolean_t));

/*
 * Register the Power Manager as a PMCs user.
 *
 * @param handler
 * Notification callback to use when PMCs are acquired/released by a task.
 * Power management must acknowledge the change using kpc_pm_acknowledge.
 *
 * @param pmc_mask
 * Bitmask of the configurable PMCs used by the Power Manager. The number of bits
 * set must less or equal than the number of configurable counters
 * available on the SoC.
 *
 * @param custom_config
 * If custom_config=TRUE, the legacy sharing mode is enabled, otherwise the
 * Modern Sharing mode is enabled. These modes are explained in more details in
 * the kperf documentation.
 *
 * @return
 * FALSE if a task has acquired all the PMCs, otherwise TRUE and the Power
 * Manager can start using the reserved PMCs.
 */
extern boolean_t kpc_reserve_pm_counters(uint64_t pmc_mask, kpc_pm_handler_t handler,
    boolean_t custom_config);

/*
 * Unregister the Power Manager as a PMCs user, and release the previously
 * reserved counters.
 */
extern void kpc_release_pm_counters(void);

/*
 * Acknowledge the callback that PMCs are available to power management.
 *
 * @param available_to_pm Whether the counters were made available to power
 * management in the callback.  Pass in whatever was passed into the handler
 * function.  After this point, if the value is TRUE, power management is able
 * to use POWER_CLASS counters.
 */
extern void kpc_pm_acknowledge(boolean_t available_to_pm);

/*
 * Is kpc controlling the fixed counters?
 *
 * This returns false when the power manager has requested custom configuration
 * control.
 */
extern boolean_t kpc_controls_fixed_counters(void);

extern void kpc_idle(void);
extern void kpc_idle_exit(void);

/*
 * KPC PRIVATE
 */


/*
 * Backwards-compatible declarations for CLPC.
 */

#if defined(__arm64__)

#include <pexpert/arm64/board_config.h>

#define KPC_ARM64_FIXED_COUNT        (2)
#define KPC_ARM64_CONFIGURABLE_COUNT (CPMU_PMC_COUNT - KPC_ARM64_FIXED_COUNT)

#if CPMU_64BIT_PMCS
#define KPC_ARM64_COUNTER_WIDTH    (63)
#define KPC_ARM64_COUNTER_OVF_BIT  (63)
#else // CPMU_64BIT_PMCS
#define KPC_ARM64_COUNTER_WIDTH    (47)
#define KPC_ARM64_COUNTER_OVF_BIT  (47)
#endif // !CPMU_64BIT_PMCS

#define KPC_ARM64_COUNTER_MASK     ((UINT64_C(1) << KPC_ARM64_COUNTER_WIDTH) - 1)
#define KPC_ARM64_COUNTER_OVF_MASK (UINT64_C(1) << KPC_ARM64_COUNTER_OVF_BIT)

/* arm64 uses fixed counter shadows */
#define FIXED_COUNTER_SHADOW (1)

#define KPC_ARM64_PMC_COUNT (KPC_ARM64_FIXED_COUNT + KPC_ARM64_CONFIGURABLE_COUNT)

#endif /* defined(__arm64__) */

__END_DECLS

#endif /* !defined(KERN_KPC_H) */
