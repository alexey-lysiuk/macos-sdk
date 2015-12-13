/*
 *  status_dev.h
 *  IOFamily
 *
 *  Created by Pete on 4/14/05.
 *  Copyright 2005 Apple Computer, Inc. All rights reserved.
 *
 */

#ifndef _STATUS_DEV_H_
#define _STATUS_DEV_H_

#ifdef  __cplusplus
extern "C" {
#endif

#define APPLE_STATUS_CLIENT_PROC_MAX 20

int apple80211msg_devinit( char * name, int * minor );
int apple80211msg_devfree( int min );
int apple80211msg_post( int min, int msg );

#ifdef  __cplusplus
}
#endif

#endif /*_STATUS_DEV_H_*/