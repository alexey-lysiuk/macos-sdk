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

#ifndef CHUD_SAMPLE_H
#define CHUD_SAMPLE_H

#include <libkern/OSTypes.h> /* AbsoluteTime */

#include <CHUD/chudCtrl.h>
#include <CHUD/chudPMCs.h>
#include <CHUD/chudTimeBase.h>

#ifdef __cplusplus
extern "C" {
#endif

/* sample facilty acquisition methods */
#define CHUD_NONBLOCKING   0
#define CHUD_BLOCKING      1

typedef struct chud_context_s {
    unsigned int interval;
    unsigned int pc;
    unsigned int thread_id;
    unsigned int cpu_num : 2;
    unsigned int supervisor : 1;
    unsigned int pid : 29;
} chud_context_t;

/* 96 bytes per chud_sample_record_t */
typedef struct chud_sample_record_s {
    AbsoluteTime t_begin;
    AbsoluteTime t_end;
    chud_context_t context;
    unsigned int pmc[MAX_CPUPMC_COUNT];
    unsigned int ospmc[MAX_OSPMC_COUNT];
    unsigned int mcpmc[MAX_MCPMC_COUNT];
} chud_sample_record_t;

#ifndef CHUD_KEXT
int	chudAcquireSamplingFacility( int blocking_acquire );
int	chudReleaseSamplingFacility( int retain_samples );
int 	chudGetSamplingFacilityOwnerPID( void );

chud_device_t chudGetSamplingDevice( void );
int	chudSetSamplingDevice( chud_device_t dev );

int 	chudGetSampleCount( void ); 
chud_sample_record_t *chudGetSampleRecord( int sample_idx );
chud_sample_record_t *chudGetAllSampleRecords( int *nItrRtn );
int 	chudGetRangeSampleRecords( int startIdx, int endIdx, chud_sample_record_t *samplePtr, int *nResults);

int 	chudSetFuzziness( unsigned int pct );
int 	chudGetFuzziness( void );

int 	chudSetStartDelay( int delay_time, chud_time_unit_t delay_time_units );
int	chudGetStartDelay( int *delay_time, chud_time_unit_t *delay_time_units );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void	chudTaskWillExitCallback( chudCallbackFuncData uicf, unsigned long ha1, unsigned long ha2 ); 

#endif /* !CHUD_KEXT */

#ifdef __cplusplus
}
#endif

#endif /* CHUD_SAMPLE_H */