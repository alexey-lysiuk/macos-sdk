/* iig(DriverKit-54.0.0.111.1) generated from IOUSBHostInterface.iig */

/* IOUSBHostInterface.iig:1-19 */
#ifndef _IOKIT_IOUSBHOSTINTERFACE_H
#define _IOKIT_IOUSBHOSTINTERFACE_H

#include <USBDriverKit/AppleUSBDefinitions.h>
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 
#include <USBDriverKit/IOUSBHostPipe.h>  /* .iig include */ 
#include <USBDriverKit/IOUSBHostDevice.h>  /* .iig include */ 
#include <DriverKit/IOBufferMemoryDescriptor.h>  /* .iig include */ 

/*!
@iig implementation
#if KERNEL
#include <IOKit/usb/IOUSBHostInterface.h>
#endif
@iig end
*/

/* class IOUSBHostInterface IOUSBHostInterface.iig:20-236 */

#define IOUSBHostInterface__GetInterfaceDescriptorHeader_ID            0x9434ede8968ad899ULL
#define IOUSBHostInterface_Open_ID            0xe1d4ddd5e2cbe425ULL
#define IOUSBHostInterface_Close_ID            0xcc4d8955a6ca402dULL
#define IOUSBHostInterface_GetFrameNumber_ID            0xa54dc3018b39ad1dULL
#define IOUSBHostInterface_CopyPipe_ID            0x86bb6756a5becea0ULL
#define IOUSBHostInterface_SelectAlternateSetting_ID            0xbf28ca8ee6edc0d3ULL
#define IOUSBHostInterface_GetPortStatus_ID            0xbed0143a5a239d9cULL
#define IOUSBHostInterface_SetIdlePolicy_ID            0x832000ee4e988f9fULL
#define IOUSBHostInterface_GetIdlePolicy_ID            0xc5f9b873ec9e7322ULL
#define IOUSBHostInterface_CopyDevice_ID            0xba535ca623a6536cULL

#define IOUSBHostInterface__GetInterfaceDescriptorHeader_Args \
        IOUSBInterfaceDescriptor * descriptor

#define IOUSBHostInterface_Open_Args \
        IOService * forClient, \
        IOOptionBits options, \
        uint8_t * arg

#define IOUSBHostInterface_Close_Args \
        IOService * forClient, \
        IOOptionBits options

#define IOUSBHostInterface_GetFrameNumber_Args \
        uint64_t * frameNumber, \
        uint64_t * theTime

#define IOUSBHostInterface_CopyPipe_Args \
        uint8_t address, \
        IOUSBHostPipe ** pipe

#define IOUSBHostInterface_SelectAlternateSetting_Args \
        uint8_t bAlternateSetting

#define IOUSBHostInterface_GetPortStatus_Args \
        uint32_t * portStatus

#define IOUSBHostInterface_SetIdlePolicy_Args \
        uint32_t deviceIdleTimeout

#define IOUSBHostInterface_GetIdlePolicy_Args \
        uint32_t * deviceIdleTimeout

#define IOUSBHostInterface_CopyDevice_Args \
        IOUSBHostDevice ** device

#define IOUSBHostInterface_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUSBHostInterface * self, const IORPC rpc);\
\
    kern_return_t\
    _GetInterfaceDescriptorHeader(\
        IOUSBInterfaceDescriptor * descriptor,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Open(\
        IOService * forClient,\
        IOOptionBits options,\
        uint8_t * arg,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Close(\
        IOService * forClient,\
        IOOptionBits options,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetFrameNumber(\
        uint64_t * frameNumber,\
        uint64_t * theTime,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyPipe(\
        uint8_t address,\
        IOUSBHostPipe ** pipe,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SelectAlternateSetting(\
        uint8_t bAlternateSetting,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetPortStatus(\
        uint32_t * portStatus,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetIdlePolicy(\
        uint32_t deviceIdleTimeout,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetIdlePolicy(\
        uint32_t * deviceIdleTimeout,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyDevice(\
        IOUSBHostDevice ** device,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    _GetInterfaceDescriptorHeader_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface__GetInterfaceDescriptorHeader_Args));\
\
    kern_return_t\
    Open_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_Open_Args));\
\
    kern_return_t\
    Close_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_Close_Args));\
\
    kern_return_t\
    GetFrameNumber_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_GetFrameNumber_Args));\
\
    kern_return_t\
    CopyPipe_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_CopyPipe_Args));\
\
    kern_return_t\
    SelectAlternateSetting_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_SelectAlternateSetting_Args));\
\
    kern_return_t\
    GetPortStatus_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_GetPortStatus_Args));\
\
    kern_return_t\
    SetIdlePolicy_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_SetIdlePolicy_Args));\
\
    kern_return_t\
    GetIdlePolicy_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_GetIdlePolicy_Args));\
\
    kern_return_t\
    CopyDevice_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostInterface::*func)(IOUSBHostInterface_CopyDevice_Args));\
\


#define IOUSBHostInterface_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _GetInterfaceDescriptorHeader_Impl(IOUSBHostInterface__GetInterfaceDescriptorHeader_Args);\
\
    kern_return_t\
    Open_Impl(IOUSBHostInterface_Open_Args);\
\
    kern_return_t\
    Close_Impl(IOUSBHostInterface_Close_Args);\
\
    kern_return_t\
    GetFrameNumber_Impl(IOUSBHostInterface_GetFrameNumber_Args);\
\
    kern_return_t\
    CopyPipe_Impl(IOUSBHostInterface_CopyPipe_Args);\
\
    kern_return_t\
    SelectAlternateSetting_Impl(IOUSBHostInterface_SelectAlternateSetting_Args);\
\
    kern_return_t\
    GetPortStatus_Impl(IOUSBHostInterface_GetPortStatus_Args);\
\
    kern_return_t\
    SetIdlePolicy_Impl(IOUSBHostInterface_SetIdlePolicy_Args);\
\
    kern_return_t\
    GetIdlePolicy_Impl(IOUSBHostInterface_GetIdlePolicy_Args);\
\
    kern_return_t\
    CopyDevice_Impl(IOUSBHostInterface_CopyDevice_Args);\
\


#define IOUSBHostInterface_VirtualMethods \
\
public:\
\
    virtual const IOUSBConfigurationDescriptor *\
    CopyConfigurationDescriptor(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBInterfaceDescriptor *\
    GetInterfaceDescriptor(\
        const IOUSBConfigurationDescriptor * configurationDescriptor) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBStringDescriptor *\
    CopyStringDescriptor(\
        uint8_t index,\
        uint16_t languageID) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBStringDescriptor *\
    CopyStringDescriptor(\
        uint8_t index) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    CreateIOBuffer(\
        IOOptionBits options,\
        uint64_t capacity,\
        IOBufferMemoryDescriptor ** buffer) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    AsyncDeviceRequest(\
        uint8_t bmRequestType,\
        uint8_t bRequest,\
        uint16_t wValue,\
        uint16_t wIndex,\
        uint16_t wLength,\
        IOMemoryDescriptor * dataBuffer,\
        OSAction * completion,\
        uint32_t completionTimeoutMs) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    DeviceRequest(\
        uint8_t bmRequestType,\
        uint8_t bRequest,\
        uint16_t wValue,\
        uint16_t wIndex,\
        uint16_t wLength,\
        IOMemoryDescriptor * dataBuffer,\
        uint16_t * bytesTransferred,\
        uint32_t completionTimeoutMs) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    AbortDeviceRequests(\
        IOOptionBits options,\
        IOReturn withError) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUSBHostInterfaceMetaClass;
extern OSClassLoadInformation IOUSBHostInterface_Class;

class IOUSBHostInterfaceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUSBHostInterfaceInterface : public OSInterface
{
public:
    virtual const IOUSBConfigurationDescriptor *
    CopyConfigurationDescriptor() = 0;

    virtual const IOUSBInterfaceDescriptor *
    GetInterfaceDescriptor(const IOUSBConfigurationDescriptor * configurationDescriptor) = 0;

    virtual const IOUSBStringDescriptor *
    CopyStringDescriptor(uint8_t index,
        uint16_t languageID) = 0;

    virtual const IOUSBStringDescriptor *
    CopyStringDescriptor(uint8_t index) = 0;

    virtual kern_return_t
    CreateIOBuffer(IOOptionBits options,
        uint64_t capacity,
        IOBufferMemoryDescriptor ** buffer) = 0;

    virtual kern_return_t
    AsyncDeviceRequest(uint8_t bmRequestType,
        uint8_t bRequest,
        uint16_t wValue,
        uint16_t wIndex,
        uint16_t wLength,
        IOMemoryDescriptor * dataBuffer,
        OSAction * completion,
        uint32_t completionTimeoutMs) = 0;

    virtual kern_return_t
    DeviceRequest(uint8_t bmRequestType,
        uint8_t bRequest,
        uint16_t wValue,
        uint16_t wIndex,
        uint16_t wLength,
        IOMemoryDescriptor * dataBuffer,
        uint16_t * bytesTransferred,
        uint32_t completionTimeoutMs) = 0;

    virtual kern_return_t
    AbortDeviceRequests(IOOptionBits options,
        IOReturn withError) = 0;

};

struct IOUSBHostInterface_IVars;
struct IOUSBHostInterface_LocalIVars;

class IOUSBHostInterface : public IOService, public IOUSBHostInterfaceInterface
{
#if !KERNEL
    friend class IOUSBHostInterfaceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUSBHostInterface_IVars * ivars;
        IOUSBHostInterface_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOUSBHostInterface_Methods
    IOUSBHostInterface_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUSBHostInterface.iig:238-239 */


/* IOUSBHostInterface.iig:246- */
#endif /* ! _IOKIT_IOUSBHOSTINTERFACE_H */

