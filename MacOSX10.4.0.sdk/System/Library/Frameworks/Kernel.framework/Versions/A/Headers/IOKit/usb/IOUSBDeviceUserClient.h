/*
 * Copyright (c) 1998-2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef __OPEN_SOURCE__
/*
 *
 *	$Log: IOUSBDeviceUserClient.h,v $
 *	Revision 1.24  2004/05/17 21:42:00  nano
 *	Made the Device and Interface User Clients subclassable.
 *	
 *	Revision 1.23.16.1  2004/05/17 15:57:29  nano
 *	API Changes for Tiger
 *	
 *	Revision 1.23  2004/02/03 22:09:52  nano
 *	Fix <rdar://problem/3548194>: Remove $ Id $ from source files to prevent conflicts
 *	
 *	Revision 1.22.48.2  2004/04/28 17:26:11  nano
 *	Remove $ ID $ so that we don't get conflicts on merge
 *	
 *	Revision 1.22.48.1  2003/11/04 22:27:39  nano
 *	Work in progress to add time stamping to interrupt handler
 *	
 *	Revision 1.22  2003/08/20 19:41:45  nano
 *	
 *	Bug #:
 *	New version's of Nima's USB Prober (2.2b17)
 *	3382540  Panther: Ejecting a USB CardBus card can freeze a machine
 *	3358482  Device Busy message with Modems and IOUSBFamily 201.2.14 after sleep
 *	3385948  Need to implement device recovery on High Speed Transaction errors to full speed devices
 *	3377037  USB EHCI: returnTransactions can cause unstable queue if transactions are aborted
 *	
 *	Also, updated most files to use the id/log functions of cvs
 *	
 *	Submitted by: nano
 *	Reviewed by: rhoads/barryt/nano
 *	
 */
#endif
#ifndef _IOKIT_IOUSBDEVICEUSERCLIENT_H
#define _IOKIT_IOUSBDEVICEUSERCLIENT_H

//================================================================================================
//
//   Headers
//
//================================================================================================
//
#include <libkern/OSByteOrder.h>

#include <IOKit/IOUserClient.h>
#include <IOKit/assert.h>
#include <IOKit/IOLib.h>
#include <IOKit/IOBufferMemoryDescriptor.h>
#include <IOKit/IOMessage.h>
#include <IOKit/usb/IOUSBUserClient.h>
#include <IOKit/usb/IOUSBControllerV2.h>
#include <IOKit/usb/IOUSBDevice.h>
#include <IOKit/usb/IOUSBInterface.h>
#include <IOKit/usb/IOUSBPipe.h>
#include <IOKit/usb/IOUSBLog.h>


//================================================================================================
//
//   Structure declarations
//
//================================================================================================
//
typedef struct IOUSBDeviceUserClientAsyncParamBlock IOUSBDeviceUserClientAsyncParamBlock;

struct IOUSBDeviceUserClientAsyncParamBlock {
    OSAsyncReference 		fAsyncRef;
    UInt32 			fMax;
    IOMemoryDescriptor 		*fMem;
    IOUSBDevRequestDesc		req;
};

//================================================================================================
//
//   Class Declaration for IOUSBDeviceUserClient
//
//================================================================================================
//
class IOUSBDeviceUserClient : public IOUserClient
{
    OSDeclareDefaultStructors(IOUSBDeviceUserClient)

    IOUSBDevice *			fOwner;
    task_t				fTask;
    mach_port_t 			fWakePort;
    const IOExternalMethod *		fMethods;
    const IOExternalAsyncMethod *	fAsyncMethods;
    IOCommandGate *			fGate;
    IOWorkLoop	*			fWorkLoop;
    UInt32				fNumMethods;
    UInt32				fNumAsyncMethods;
    UInt32				fOutstandingIO;
    bool				fDead;
    bool				fNeedToClose;
    
    struct IOUSBDeviceUserClientExpansionData 
    {
    };
   
    IOUSBDeviceUserClientExpansionData * fIOUSBDeviceUserClientExpansionData;

protected:
        
    virtual void                        SetExternalMethodVectors(void);

public:
        
    // IOService methods
    //
    virtual void                        stop(IOService * provider);
    virtual bool                        start( IOService * provider );
    virtual bool                        finalize(IOOptionBits options);
    virtual void                        free();
    virtual bool                        willTerminate( IOService * provider, IOOptionBits options );
    virtual bool                        didTerminate( IOService * provider, IOOptionBits options, bool * defer );

    // pseudo IOKit methods - these methods are NOT the IOService:: methods, since both IOService::open
    // and IOService::close require an IOService* as the first parameter
    //
    virtual IOReturn                    open(bool seize);
    virtual IOReturn                    close(void);

    // IOUserClient methods
    //
    virtual bool			initWithTask(task_t owningTask, void *security_id, UInt32 type);
    virtual IOExternalMethod * 		getTargetAndMethodForIndex(IOService **target, UInt32 index);
    virtual IOExternalAsyncMethod * 	getAsyncTargetAndMethodForIndex(IOService **target, UInt32 index);
    virtual IOReturn 			clientClose( void );
    virtual IOReturn 			clientDied( void );

    // IOUSBDevice methods
    //
    virtual IOReturn                    SetConfiguration(UInt8 configIndex);
    virtual IOReturn                    GetConfigDescriptor(UInt8 configIndex, IOUSBConfigurationDescriptorPtr desc, UInt32 *size);
    virtual IOReturn                    CreateInterfaceIterator(IOUSBFindInterfaceRequest *reqIn, io_object_t *iterOut, IOByteCount inCount, IOByteCount *outCount);
    virtual IOReturn                    GetFrameNumber(IOUSBGetFrameStruct *data, UInt32 *size);
    virtual IOReturn                    GetMicroFrameNumber(IOUSBGetFrameStruct *data, UInt32 *size);
    virtual IOReturn                    DeviceReqIn(UInt16 param1, UInt32 param2, UInt32 noDataTimeout, UInt32 completionTimeout, void *buf, UInt32 *size);
    virtual IOReturn                    DeviceReqOut(UInt16 param1, UInt32 param2, UInt32 noDataTimeout, UInt32 completionTimeout, void *buf, UInt32 size);
    virtual IOReturn                    DeviceReqInOOL(IOUSBDevRequestTO *reqIn, IOByteCount inCount, UInt32 *sizeOut, IOByteCount *outCount);
    virtual IOReturn                    DeviceReqOutOOL(IOUSBDevRequestTO *reqIn, IOByteCount inCount);
    virtual IOReturn                    DeviceReqInAsync(OSAsyncReference asyncRef, IOUSBDevRequestTO *reqIn, IOByteCount inCount);
    virtual IOReturn                    DeviceReqOutAsync(OSAsyncReference asyncRef, IOUSBDevRequestTO *reqIn, IOByteCount inCount);
    virtual IOReturn                    SetAsyncPort(OSAsyncReference asyncRef);
    virtual IOReturn                    ResetDevice( void );
    virtual IOReturn                    SuspendDevice(bool suspend);
    virtual IOReturn                    AbortPipeZero(void);
    virtual IOReturn                    ReEnumerateDevice(UInt32 options);
    
    // bookkeeping methods
    virtual void                        DecrementOutstandingIO(void);
    virtual void                        IncrementOutstandingIO(void);
    virtual UInt32                      GetOutstandingIO(void);

    // Getters
    //
    IOUSBDevice *               GetOwner(void)                          { return fOwner; }
    task_t                      GetTask(void)                           { return fTask; }
    IOCommandGate *             GetCommandGate(void)                    { return fGate; }
    UInt32                      GetNumMethods(void)                     { return fNumMethods; }
    UInt32                      GetNumAsyncMethods(void)                { return fNumAsyncMethods; }
    mach_port_t                 GetWakePort(void)                       { return fWakePort; }
    bool                        IsDead(void)                            { return fDead; }
    bool                        NeedToClose(void)                       { return fNeedToClose; }
    
    // static methods
    //
    static const IOExternalMethod	sMethods[kNumUSBDeviceMethods];
    static const IOExternalAsyncMethod	sAsyncMethods[kNumUSBDeviceAsyncMethods];
    static void 			ReqComplete(void *obj, void *param, IOReturn status, UInt32 remaining);
    static IOReturn			ChangeOutstandingIO(OSObject *target, void *arg0, void *arg1, void *arg2, void *arg3);
    static IOReturn			GetGatedOutstandingIO(OSObject *target, void *arg0, void *arg1, void *arg2, void *arg3);

    // padding methods
    //
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  0);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  1);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  2);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  3);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  4);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  5);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  6);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  7);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  8);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient,  9);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 10);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 11);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 12);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 13);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 14);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 15);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 16);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 17);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 18);
    OSMetaClassDeclareReservedUnused(IOUSBDeviceUserClient, 19);
};


#endif /* ! _IOKIT_IOUSBDEVICEUSERCLIENT_H */

