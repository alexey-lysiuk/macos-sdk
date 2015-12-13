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

#ifndef CHUD_PMCS_H
#define CHUD_PMCS_H

#include <CHUD/chudCtrl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*indices into arrays PMC results*/
#define PMC_1 		0
#define PMC_2 		1
#define PMC_3		2
#define PMC_4 		3
#define PMC_5 		4
#define PMC_6 		5

#define CHUD_PMCS_PAUSED	2
#define CHUD_PMCS_RUNNING	1
#define CHUD_PMCS_STOPPED	0

typedef enum {
    chudFmodeUnconditional		= 0,
    chudFmodeIgnorePrivOnlyMarked	= 1,
    chudFmodeIgnorePrivOnlyUnmarked	= 2,
    chudFmodeOnlySuperIgnoreMarkBit	= 3,
    chudFmodeOnlySuperOnlyMarked	= 4,
    chudFmodeOnlySuperOnlyUnmarked	= 5,
    chudFmodeOnlyUserIgnoreMarkBit	= 6,
    chudFmodeOnlyUserOnlyMarked		= 7,
    chudFmodeOnlyUserOnlyUnmarked	= 8,
} chud_device_filter_t;

typedef enum {
    chudFmodeIgnorePriv			= 9,
    chudFmodeOnlySuper			= 10,
    chudFmodeOnlyUser			= 11,
} chud_priv_filter_t;
    
typedef enum {
    chudFmodeIgnoreMarkBit		= 12,
    chudFmodeOnlyMarked			= 13,
    chudFmodeOnlyUnmarked		= 14
} chud_mark_filter_t;

typedef enum {
    chudMCFmodeAll		= 0x7C,
    chudMCFmodeCPU1		= 0x40,
    chudMCFmodeCPU2		= 0x20,
    chudMCFmodeAGP		= 0x10,
    chudMCFmodePCI		= 0x08,
    chudMCFmodeFWireEnet	= 0x04
} chud_mc_filter_t;

typedef enum {
    chudUnused = 0x1,
    chudCounter,
    chudTrigger
} chud_counter_t;


#ifndef CHUD_KEXT
int 	chudSetCounterEvent( chud_device_t dev, int pmc, int evtnum ); 
int	chudGetCounterEvent( chud_device_t dev, int pmc ); 

int	chudGetMaxCounterEventIndex( chud_device_t dev, int pmc ); 
char *	chudGetCounterEventStr( chud_device_t dev, int pmc ); 
char *	chudGetEventString( chud_device_t dev, int pmc, int evt );
int	chudIsEventValid( chud_device_t dev, int pmc, int evt );
int 	chudGetMaxCounterValidEvents( chud_device_t dev, int pmc );

// new alternate inquiry routines
int	chudGetAltMaxCounterEventIndex( chud_device_t dev, int pmc ); 
char *	chudGetAltEventString( chud_device_t dev, int pmc, int evt );
int	chudIsAltEventValid( chud_device_t dev, int pmc, int evt );
int 	chudGetAltMaxCounterValidEvents( chud_device_t dev, int pmc );


int 	chudSetDeviceFilter( chud_device_t dev, chud_device_filter_t fmode ); 
int 	chudGetDeviceFilter( chud_device_t dev ); 
int	chudSetPrivilegeFilter( chud_device_t dev, chud_priv_filter_t fmode );
int 	chudGetPrivilegeFilter( chud_device_t dev );
int	chudSetMarkFilter( chud_device_t dev, chud_mark_filter_t fmode );
int	chudGetMarkFilter( chud_device_t dev );
int	chudSetMCRequestFilter( chud_mc_filter_t fmode );
int 	chudGetMCRequestFilter( void );

int 	chudClearCounters( void );
int 	chudStopCounters( void );
int 	chudStartCounters( void );
int 	chudPauseCounters( void );
int 	chudResumeCounters( void );

unsigned int chudSetThresholdValue( chud_device_t dev, unsigned int thresh );
unsigned int chudGetThresholdValue( chud_device_t dev );

int	chudGetBranchFoldingState( int cpunum );
int	chudSetBranchFoldingState( int cpunum, int state );

int	chudSetCounterMode( chud_device_t dev, int pmc, chud_counter_t mode );
int	chudGetCounterMode( chud_device_t dev, int pmc );
int	chudSetCounterModes( chud_device_t dev, chud_counter_t *counter_modes );
chud_counter_t *chudGetCounterModes( chud_device_t dev, int *mode_ct );
#endif /* !CHUD_KEXT */

#ifdef __cplusplus
}
#endif

#endif /* CHUD_PMCS_H */