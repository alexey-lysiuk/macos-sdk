/*
 *  IO80211LegacyUserClient.h
 *  Family
 *
 *  Created by Pete on 8/4/05.
 *  Copyright 2005 Apple Computer, Inc. All rights reserved.
 *
 */

#ifndef _IO80211_LEGACY_USER_CLIENT_H
#define _IO80211_LEGACY_USER_CLIENT_H

#include <IOKit/IOUserClient.h>
#include <IOKit/IOLib.h>

#include "AirPortComm.h"

class IO80211Controller;

class IO80211LegacyUserClient : public IOUserClient
{
	OSDeclareDefaultStructors( IO80211LegacyUserClient )
	
	public:
		
		static IO80211LegacyUserClient * withTask(task_t owningTask, void *security_id , UInt32 type);
		
		virtual bool start( IOService *provider );
		
		IOReturn userPostCommand(	AirportCommandPtr pIn,
									void *pOut,
									IOByteCount inputSize,
									IOByteCount *outPutSize );
									
		virtual IOReturn clientClose();
		virtual IOReturn connectClient(IOUserClient *client);
		virtual IOExternalMethod * getExternalMethodForIndex(UInt32 index);
		virtual IOReturn setProperties( OSObject * properties );
		
		void setTask( task_t inTask );
		task_t task();
		
		void setSecurity( void * inSecurity );
		void * security();
	
	private:
	
		IO80211Controller * _controller;
		task_t _task;
		void * _security;
		IOExternalMethod _methods[1];
};

#endif	/* _IO80211_LEGACY_USER_CLIENT_H */