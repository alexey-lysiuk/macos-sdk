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
 
#ifndef CHUD_PPCMMCRS_DEFS_H
#define CHUD_PPCMMCRS_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ppc_mmcr0_bits_s {
    unsigned int disable_counters_always : 1;     /*     0: freeze counters */
    unsigned int disable_counters_supervisor : 1; /*     1: freeze counters (supervisor) */
    unsigned int disable_counters_user : 1;       /*     2: freeze counters (user) */
    unsigned int disable_counters_marked : 1;     /*     3: freeze counters (marked bit == 1) */
    unsigned int disable_counters_unmarked : 1;   /*     4: freeze counters (marked bit == 0) */
    unsigned int enable_pmi : 1;                  /*     5: performance monitor interrupt enable */
    unsigned int on_pmi_stop_counting : 1;        /*     6: freeze counters (pmi) */
    unsigned int timebase_pmi_selector : 2;       /*   7-8: select TBL bit that causes pmi */
    unsigned int enable_timebase_pmi : 1;         /*     9: enable timebase events */
    unsigned int threshold_value : 6;             /* 10-15: threshold value */
    unsigned int enable_pmi_on_pmc1 : 1;          /*    16: enable pmi on pmc1 overflow */
    unsigned int enable_pmi_on_pmcn : 1;          /*    17: enable pmi on any pmc except pmc1 overflow */
    unsigned int enable_pmi_trigger : 1;          /*    18: enable triggering of pmcn by pmc1 overflow */
    unsigned int pmc1_event : 7;               	/* 19-25: pmc1 event select */
    unsigned int pmc2_event : 6;               	/* 26-31: pmc2 event select */
} ppc_mmcr0_bits_t;

typedef union ppc_mmcr0_reg_s {
    unsigned int value;
    ppc_mmcr0_bits_t field;
} ppc_mmcr0_reg_t;

typedef struct ppc_mmcr1_bits_s {
    unsigned int pmc3_event : 5;
    unsigned int pmc4_event : 5;
    unsigned int pmc5_event : 5;
    unsigned int pmc6_event : 6;
    unsigned int /*reserved*/     : 11;
} ppc_mmcr1_bits_t;

typedef union ppc_mmcr1_reg_s {
    unsigned int value;
    ppc_mmcr1_bits_t field;
} ppc_mmcr1_reg_t;

typedef struct ppc_mmcr2_bits_s {
    unsigned int threshold_multiplier : 1;
    unsigned int /*reserved*/     : 31;
} ppc_mmcr2_bits_t;

typedef union ppc_mmcr2_reg_s {
    unsigned int value;
    ppc_mmcr2_bits_t field;
} ppc_mmcr2_reg_t;

typedef ppc_mmcr0_reg_t os_mmcr_reg_t;

typedef struct ppc_mmcrs_s {
    ppc_mmcr0_reg_t mmcr0;
    ppc_mmcr1_reg_t mmcr1;
    ppc_mmcr2_reg_t mmcr2;    
} ppc_mmcrs_t;

#ifdef __cplusplus
}
#endif

#endif /* CHUD_PPCMMCRS_DEFS_H */
