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

#ifndef CHUD_UNIN_DEFS_H
#define CHUD_UNIN_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#define chudUniNVersion		(0x0000)

// Uni-N 1.5 Performance Monitoring Registers
#define chudUniNMMCR		(0x0F00)
#define chudUniNMCMDR		(0x0F10)
#define chudUniNMPMC1		(0x0F20)
#define chudUniNMPMC2		(0x0F30)
#define chudUniNMPMC3		(0x0F40)
#define chudUniNMPMC4		(0x0F50)

typedef struct unin_mmcr_bits_s {
    unsigned int  /*reserved*/        :25;
    unsigned int  cpu0_req_src        : 1; //select cpu0 requests for counting
    unsigned int  cpu1_req_src        : 1; //select cpu1 requests for counting 
    unsigned int  agp_req_src         : 1; //select agp requests for counting
    unsigned int  pci_req_src         : 1; //select pci requests for counting
    unsigned int  enet_fwire_req_src  : 1; //select ethernet and firewire requests for counting
    unsigned int  read_then_zero_pmcs : 1; //0==read only, 1==read then zero
    unsigned int  enable_counting     : 1; //0==disable, 1==enable
} unin_mmcr_bits_t;

typedef union unin_mmcr_reg_s {
    unsigned int value;
    unin_mmcr_bits_t field;
} unin_mmcr_reg_t;

typedef struct unin_mcmdr_bits_s {
    unsigned int  pmc1_event_id       : 8; 
    unsigned int  pmc2_event_id       : 8;  
    unsigned int  pmc3_event_id       : 8; 
    unsigned int  pmc4_event_id       : 8; 
} unin_mcmdr_bits_t;

typedef union unin_mcmdr_reg_s {
    unsigned int value;
    unin_mcmdr_bits_t field;
} unin_mcmdr_reg_t;

#ifdef __cplusplus
}
#endif

#endif //CHUD_UNIN_DEFS_H