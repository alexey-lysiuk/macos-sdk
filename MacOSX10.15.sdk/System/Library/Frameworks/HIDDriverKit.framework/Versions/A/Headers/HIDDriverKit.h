//
//  HIDDriverKit.h
//  HIDDriverKit
//
//  Created by yg on 12/5/18.
//

#import <DriverKit/DriverKit.h>

//! Project version number for HIDDriverKit.
extern double HIDDriverKitVersionNumber;

//! Project version string for HIDDriverKit.
extern const unsigned char HIDDriverKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <HIDDriverKit/PublicHeader.h>

#include <HIDDriverKit/IOHIDDeviceTypes.h>
#include <HIDDriverKit/IOHIDDeviceKeys.h>
#include <HIDDriverKit/IOHIDEventServiceTypes.h>
#include <HIDDriverKit/IOHIDEventServiceKeys.h>
#include <HIDDriverKit/IOHIDUsageTables.h>
#include <HIDDriverKit/IOHIDDevice.h>
#include <HIDDriverKit/IOHIDInterface.h>
#include <HIDDriverKit/IOHIDEventService.h>
#include <HIDDriverKit/IOUserHIDDevice.h>
#include <HIDDriverKit/IOUserHIDEventService.h>
#include <HIDDriverKit/IOUserHIDEventDriver.h>
#include <HIDDriverKit/IOUserUSBHostHIDDevice.h>
#include <HIDDriverKit/IOHIDElement.h>
