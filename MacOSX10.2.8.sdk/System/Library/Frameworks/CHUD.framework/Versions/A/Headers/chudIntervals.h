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

#ifndef CHUD_INTERVALS_H
#define CHUD_INTERVALS_H

#ifdef __cplusplus
extern "C" {
#endif

int	chudGetMaxIntervals( void );
int	chudSetMaxIntervals( int max );

double *chudGetIntervalResult( chud_device_t dev, int theInterval, int *nItrRtn );
double *chudGetSingleResult( chud_device_t dev, int *nCtrRtn );
int	chudGetRangeIntervalResults( chud_device_t dev, int startIdx, int endIdx, double **resultsPtr, int *nResults );
int	chudGetIntervalCount( void );
int	chudGetValidIntervalCount( chud_device_t dev );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void	chudMaxIntervalCallback( chudCallbackFunc uicf, unsigned long ha1, unsigned long ha2 ); 
void 	chudPerIntervalCallback( chudCallbackFunc uicf, unsigned long ha1, unsigned long ha2 );

#ifdef __cplusplus
}
#endif

#endif /* CHUD_INTERVALS_H */


