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

#ifndef CHUD_CTRL_H
#define CHUD_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CPU_COUNT	 	2	/* maximum number of processors */
#define MAX_MC_COUNT	 	1	/* maximum number of memory controllers */
#define MAX_OS_COUNT		1	/* maximum number of kernels */

#define MAX_PMC_COUNT		6	/* maximum number of counters for all devices */
#define MAX_CPUPMC_COUNT 	6	/* maximum number of available hardware performance counters */
#define MAX_OSPMC_COUNT	 	2	/* maximum number of available OS performance counters */
#define MAX_MCPMC_COUNT	 	4	/* maximum number of available memory controller performance counters */

#define MisCPUDevice( dev ) \
((dev) == chudCPU1Dev || (dev) == chudCPU2Dev || (dev) == chudAllCPUDev)

#define MisMCDevice( dev ) \
((dev) == chudMCDev)

#define MisOSDevice( dev ) \
((dev) == chudOSDev)

#define MdeviceIndex( dev ) \
(((dev) == chudCPU1Dev || (dev) == chudMCDev || (dev) == chudOSDev)?0:1)

#define MindexToCPUDevice( index ) \
((index)?chudCPU2Dev:chudCPU1Dev)

#define MisStrictCPUDevice( dev ) \
((dev) == chudCPU1Dev || (dev) == chudCPU2Dev)

typedef void (*chudCallbackFunc)(unsigned long _instnc, unsigned long _commnd);
typedef void (*chudCallbackFuncData)(unsigned long _instnc, unsigned long _commnd, int data);

/* device types */
typedef enum {
    chudNoDev		= 0,
    chudAllCPUDev	= -3,
    chudAllDev 		= -2,
    chudUserDev 	= 16,
    chudCPU1Dev 	= 32,
    chudCPU2Dev 	= 33,
    chudMCDev 		= 64,
    chudOSDev 		= 96,
    chudTimerDev	= 128
} chud_device_t;

typedef enum {
    // generic
    chudSuccess             	=      0,
    chudFailure			= -10999,
    chudInvalidIndex,
    chudInvalidValue,
    chudInvalidUnits,
    chudInvalidMemoryPointer,
    chudMemAllocFailure,
    chudIOKitFailure,
    chudMachFailure,
    chudInvalidArgument,
        
    // init
    chudBootstrapFailure	= -11999,
    chudUnknownCpu,
    chudNotInitialized,
    
    // device
    chudBadDeviceID		= -12999,
    chudDeviceNotSupported,
    chudDeviceNotPresent,
    chudSamplingDeviceNotSet,
    
    // pmc
    chudBadPmcID		= -13999,
    chudReservedEvent,
    chudInvalidEvent,
    chudBadFilterMode,
    chudBadCounterMode,
    chudPMItriggerNotSet,
    
    // thread/task
    chudCheckPIDFailure		= -14999,
    chudCheckTaskFailure,
    chudCheckThreadFailure,

    // shortcut
    chudNoShortcutFileOpen	= -15999,
    chudNoBuiltinShortcutFile,
    chudNoUserShortcutFile,
    chudInvalidShortcutIndex,
    chudShortcutListFull,
    chudNoShortcutActive,
    chudInvalidShortcutFile,
    chudShortcutSaveFailure,
    
    // hotkey
    chudAddHotkeyFailed		= -16999,
    chudRemoveHotkeyFailed,
    chudNoHotkeyCallback,
    chudInvalidModifierKey,
    
    // sample facility
    chudSampleFacilityInUse	= -17999,
    chudWaitingForSampleFacility,
    chudSampleFacilityNotAcquired,
    chudMapSampleBufferFailure,
    chudNoSamplesAvailable,
    
    // remote facility
    chudRemoteFacilityInUse	= -18999,
    chudRemoteFacilityNoServer,
    chudRemoteFacilityNotAcquired,
    
    // kext
    chudUtilsKextNotLoaded	= -19999,
    chudProfKextNotLoaded,

    // Alternate info error codes
    chudNoAlternateProcessorInfo = -20999,
    chudNoAlternateMemoryControllerInfo,
    chudNoAlternateIOControllerInfo,
    chudInvalidProcessorClass,
    chudInvalidProcessorType,
    chudInvalidMemoryControllerType,
    chudInvalidIOControllerType

} chud_status_t;

#ifndef CHUD_KEXT
#include <stdio.h>

int	chudInitialize( void );
void	chudCleanup( void );
int	chudIsReady( void ); 

void	chudSetErrorLogFile( FILE *err );
void	chudTrapOnErrors( int doTrapOnErrors );

int	chudGetStatusVal( void ); 
char *	chudGetStatusStr( void ); 

unsigned int chudFrameworkVersion( void );

#endif /* !CHUD_KEXT */

#ifdef __cplusplus
}
#endif

#endif /* CHUD_CTRL_H */
