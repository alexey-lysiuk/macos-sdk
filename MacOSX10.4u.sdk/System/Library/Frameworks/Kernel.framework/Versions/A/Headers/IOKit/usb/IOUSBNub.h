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
 *	$Log: IOUSBNub.h,v $
 *	Revision 1.12  2004/09/24 20:14:23  nano
 *	<rdar://problem/3810184> PERF: Implement a mask to allow matching to partial productIDs and <rdar://problem/3776707> The IOUSBFamily driver gives up on non-compliant USB devices sending it too much data
 *	
 *	Revision 1.11.10.1  2004/09/23 17:45:43  nano
 *	Added define for kUSBProductIDMask
 *	
 *	Revision 1.11  2004/09/09 04:52:59  nano
 *	Merge branch PR-3731180 into TOT
 *	
 *	Revision 1.10.50.1  2004/09/08 16:35:03  nano
 *	Fix <rdar://problem/3748428> PERF: Enhanced matching criteria for USB devices and interfaces
 *	
 *	Revision 1.10.42.1  2004/08/23 17:14:42  nano
 *	Implement wildcard support for matching criteria
 *	
 *	Revision 1.10  2004/02/03 22:09:49  nano
 *	Fix <rdar://problem/3548194>: Remove $ Id $ from source files to prevent conflicts
 *	
 *	Revision 1.9  2003/08/20 19:41:40  nano
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
#ifndef _IOKIT_IOUSBNUB_H
#define _IOKIT_IOUSBNUB_H

#include <IOKit/IOService.h>
#include <libkern/c++/OSData.h>
#include <IOKit/IOMemoryDescriptor.h>

#include <IOKit/usb/USB.h>

class IOUSBController;
class IOUSBPipe;

class IOUSBNub : public IOService
{
    OSDeclareDefaultStructors(IOUSBNub)

public:
    virtual bool    USBCompareProperty(OSDictionary   * matching,
                                    const char     * key );
    
    bool            IsWildCardMatch( OSDictionary   * matching, const char     * key );
    bool	    USBComparePropertyWithMask( OSDictionary *matching, const char *key, const char * maskKey );
};

#ifdef __cplusplus
extern "C" {
#endif

void printDescriptor(const IOUSBDescriptorHeader *desc);
void printDeviceDescriptor(const IOUSBDeviceDescriptor *desc);
void printConfigDescriptor(const IOUSBConfigurationDescriptor *cd);
void printEndpointDescriptor(const IOUSBEndpointDescriptor *ed);
void printInterfaceDescriptor(const IOUSBInterfaceDescriptor *id);

#ifdef __cplusplus
}
#endif

#endif /* _IOKIT_IOUSBNUB_H */
