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

#ifndef CHUD_INFO_H
#define CHUD_INFO_H

#include <CHUD/chudCtrl.h>

#ifdef __cplusplus
extern "C" {
#endif

// PowerPC processor classes

typedef enum  {
    PPC_UNKNOWN		= 0,
    PPC_750  		= 1,
    PPC_7400 		= 2,
    PPC_7450 		= 3
} ppc_processor_class_t;

// PowerPC processor types
typedef enum  {
    TYP_UNKNOWN		= 0,
    MOT_750		= 750,
    IBM_750CX 		= 751,
    IBM_750FX 		= 752,
    IBM_750CXe		= 753,
    MOT_7400 		= 7400,
    MOT_7410 		= 7410,
    MOT_7450 		= 7450,
    MOT_7455 		= 7455
} ppc_processor_t;

// memory controller types
typedef enum  {
    MC_NONE		= 0,
    MC_UNIN_UNKNOWN	= 1000,	/* Uni-North (Unknown Type) */
    MC_MPC106		= 106,	/* Motorola MPC106 (Grackle) */
    MC_UNIN10		= 10,	/* Uni-North 1.0 */
    MC_UNIN10_PANGEA	= 11,	/* Uni-North 1.0 (integrated into Pangea) */
    MC_UNIN15		= 15,	/* Uni-North 1.5 */
    MC_UNIN20		= 20	/* U2 */
} memory_controller_t;

// io controller types
typedef enum  {
    IOC_NONE		= 0,
    IOC_KEYLARGO_UNKNOWN = 1000,	/* KeyLargo (Unknown Type) */
    IOC_KEYLARGO	= 16,	/* KeyLargo */
    IOC_KEYLARGO_PANGEA	= 17	/* KeyLargo (integrated into Pangea) */
} io_controller_t;

#ifndef CHUD_KEXT
int	chudPMCCount( chud_device_t dev);

int	chudProcessorCount( void );
int	chudProcessorType( void );
int	chudProcessorClass( void );
int	chudProcessorVersion( unsigned int *vers );
int	chudProcessorRev( int *major, int *minor, int *tech );
char *	chudProcessorName( void );
int 	chudProcessorCacheConfig(int *iL1Size_p, int *dL1Size_p, int *L2Size_p, int *L2Enabled_p, int *L3Size_p, int *L3Enabled_p);
float   chudProcessorFreq( void );

//new functions for setting up alternate device info
int	chudSetAltProcessorInfo( ppc_processor_class_t pc, ppc_processor_t ptb );
int	chudAltPMCCount( chud_device_t dev );
int	chudAltProcessorType( void );
int	chudAltProcessorClass( void );
char *	chudAltProcessorName( void );
int	chudSetAltMemCtrlInfo( memory_controller_t mct );
int     chudAltMCType( void );
char *	chudAltMCName( void );
int	chudSetAltIOCtrlInfo( io_controller_t ioct );
int	chudAltIOCType( void );
char *	chudAltIOCName( void );

int     chudMCCount( void );
int     chudMCType( void );
int	chudMCRev( void );
char *	chudMCName( void );

int	chudIOCCount(void);
int	chudIOCType( void );
int	chudIOCRev( void );
char *	chudIOCName( void );

float	chudTimebaseFreq( void );
float	chudBusFreq( void );
float 	chudProcessorMHz( void );
#endif /* !CHUD_KEXT */

#ifdef __cplusplus
}
#endif

#endif /* CHUD_INFO_H */
