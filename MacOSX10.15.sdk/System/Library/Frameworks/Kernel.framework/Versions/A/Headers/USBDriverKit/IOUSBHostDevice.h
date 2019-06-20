/* iig(DriverKit-54.0.0.111.1) generated from IOUSBHostDevice.iig */

/* IOUSBHostDevice.iig:1-19 */
#ifndef _IOKIT_IOUSBHOSTDEVICE_H
#define _IOKIT_IOUSBHOSTDEVICE_H

#include <USBDriverKit/AppleUSBDefinitions.h>
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/IOBufferMemoryDescriptor.h>  /* .iig include */ 

class IOUSBHostInterface;

/*!
@iig implementation
#if KERNEL
#include <IOKit/usb/IOUSBHostDevice.h>
#include <IOKit/usb/IOUSBHostInterface.h>
#endif
@iig end
*/

/* class IOUSBHostDevice IOUSBHostDevice.iig:20-352 */

#define IOUSBHostDevice__GetDescriptor_ID            0xc769617535436f0eULL
#define IOUSBHostDevice_Open_ID            0xe139dec6668972a6ULL
#define IOUSBHostDevice_Close_ID            0xf5b5354a1a05c969ULL
#define IOUSBHostDevice_CreateIOBuffer_ID            0xb5f78ffc0afa7e23ULL
#define IOUSBHostDevice_CompleteAsyncDeviceRequest_ID            0xc489759689d7d751ULL
#define IOUSBHostDevice_AsyncDeviceRequest_ID            0xb6ab02bb32783f83ULL
#define IOUSBHostDevice_DeviceRequest_ID            0x862ae6f7392b79feULL
#define IOUSBHostDevice_AbortDeviceRequests_ID            0xe0da9ed8caee6fbeULL
#define IOUSBHostDevice_SetConfiguration_ID            0xa67a186949eaf68cULL
#define IOUSBHostDevice_GetAddress_ID            0xb682fa0b4e80b1d3ULL
#define IOUSBHostDevice_GetSpeed_ID            0xa2715c4284f99e61ULL
#define IOUSBHostDevice_GetFrameNumber_ID            0xc660b158ed52fa93ULL
#define IOUSBHostDevice_GetPortStatus_ID            0xa04ec9e19b0a96b7ULL
#define IOUSBHostDevice_Reset_ID            0xd0fbe57a84270361ULL
#define IOUSBHostDevice_CreateInterfaceIterator_ID            0xa7d9f292889bbb05ULL
#define IOUSBHostDevice_DestroyInterfaceIterator_ID            0xc49102faaad2fb20ULL
#define IOUSBHostDevice_CopyInterface_ID            0xcdb581972196795fULL

#define IOUSBHostDevice__GetDescriptor_Args \
        uint8_t type, \
        uint8_t index, \
        uint16_t languageID, \
        uint8_t requestType, \
        uint8_t requestRecipient, \
        IOMemoryDescriptor * dataBuffer, \
        uint16_t * bytesTransferred

#define IOUSBHostDevice_Open_Args \
        IOService * forClient, \
        IOOptionBits options, \
        uintptr_t arg

#define IOUSBHostDevice_Close_Args \
        IOService * forClient, \
        IOOptionBits options

#define IOUSBHostDevice_CreateIOBuffer_Args \
        IOOptionBits options, \
        uint64_t capacity, \
        IOBufferMemoryDescriptor ** buffer

#define IOUSBHostDevice_CompleteAsyncDeviceRequest_Args \
        OSAction * action, \
        IOReturn status, \
        uint32_t bytesTransferred

#define IOUSBHostDevice_AsyncDeviceRequest_Args \
        IOService * forClient, \
        uint8_t bmRequestType, \
        uint8_t bRequest, \
        uint16_t wValue, \
        uint16_t wIndex, \
        uint16_t wLength, \
        IOMemoryDescriptor * dataBuffer, \
        OSAction * completion, \
        uint32_t completionTimeoutMs

#define IOUSBHostDevice_DeviceRequest_Args \
        IOService * forClient, \
        uint8_t bmRequestType, \
        uint8_t bRequest, \
        uint16_t wValue, \
        uint16_t wIndex, \
        uint16_t wLength, \
        IOMemoryDescriptor * dataBuffer, \
        uint16_t * bytesTransferred, \
        uint32_t completionTimeoutMs

#define IOUSBHostDevice_AbortDeviceRequests_Args \
        IOService * forClient, \
        IOOptionBits options, \
        IOReturn withError

#define IOUSBHostDevice_SetConfiguration_Args \
        uint8_t bConfigurationValue, \
        bool matchInterfaces

#define IOUSBHostDevice_GetAddress_Args \
        uint8_t * address

#define IOUSBHostDevice_GetSpeed_Args \
        uint8_t * speed

#define IOUSBHostDevice_GetFrameNumber_Args \
        uint64_t * frameNumber, \
        uint64_t * theTime

#define IOUSBHostDevice_GetPortStatus_Args \
        uint32_t * portStatus

#define IOUSBHostDevice_Reset_Args \


#define IOUSBHostDevice_CreateInterfaceIterator_Args \
        uintptr_t * ref

#define IOUSBHostDevice_DestroyInterfaceIterator_Args \
        uintptr_t ref

#define IOUSBHostDevice_CopyInterface_Args \
        uintptr_t ref, \
        IOUSBHostInterface ** interface

#define IOUSBHostDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUSBHostDevice * self, const IORPC rpc);\
\
    kern_return_t\
    _GetDescriptor(\
        uint8_t type,\
        uint8_t index,\
        uint16_t languageID,\
        uint8_t requestType,\
        uint8_t requestRecipient,\
        IOMemoryDescriptor * dataBuffer,\
        uint16_t * bytesTransferred,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Open(\
        IOService * forClient,\
        IOOptionBits options,\
        uintptr_t arg,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Close(\
        IOService * forClient,\
        IOOptionBits options,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CreateIOBuffer(\
        IOOptionBits options,\
        uint64_t capacity,\
        IOBufferMemoryDescriptor ** buffer,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    CompleteAsyncDeviceRequest(\
        OSAction * action,\
        IOReturn status,\
        uint32_t bytesTransferred,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    AsyncDeviceRequest(\
        IOService * forClient,\
        uint8_t bmRequestType,\
        uint8_t bRequest,\
        uint16_t wValue,\
        uint16_t wIndex,\
        uint16_t wLength,\
        IOMemoryDescriptor * dataBuffer,\
        OSAction * completion,\
        uint32_t completionTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DeviceRequest(\
        IOService * forClient,\
        uint8_t bmRequestType,\
        uint8_t bRequest,\
        uint16_t wValue,\
        uint16_t wIndex,\
        uint16_t wLength,\
        IOMemoryDescriptor * dataBuffer,\
        uint16_t * bytesTransferred,\
        uint32_t completionTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    AbortDeviceRequests(\
        IOService * forClient,\
        IOOptionBits options,\
        IOReturn withError,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetConfiguration(\
        uint8_t bConfigurationValue,\
        bool matchInterfaces,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetAddress(\
        uint8_t * address,\
        OSDispatchMethod supermethod = NULL) const;\
\
    kern_return_t\
    GetSpeed(\
        uint8_t * speed,\
        OSDispatchMethod supermethod = NULL) const;\
\
    kern_return_t\
    GetFrameNumber(\
        uint64_t * frameNumber,\
        uint64_t * theTime,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetPortStatus(\
        uint32_t * portStatus,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Reset(\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CreateInterfaceIterator(\
        uintptr_t * ref,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DestroyInterfaceIterator(\
        uintptr_t ref,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyInterface(\
        uintptr_t ref,\
        IOUSBHostInterface ** interface,\
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
    _GetDescriptor_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice__GetDescriptor_Args));\
\
    kern_return_t\
    Open_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_Open_Args));\
\
    kern_return_t\
    Close_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_Close_Args));\
\
    kern_return_t\
    CreateIOBuffer_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_CreateIOBuffer_Args));\
\
    kern_return_t\
    CompleteAsyncDeviceRequest_Invoke(const IORPC rpc,\
        void (IOUSBHostDevice::*func)(IOUSBHostDevice_CompleteAsyncDeviceRequest_Args));\
\
    kern_return_t\
    AsyncDeviceRequest_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_AsyncDeviceRequest_Args));\
\
    kern_return_t\
    DeviceRequest_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_DeviceRequest_Args));\
\
    kern_return_t\
    AbortDeviceRequests_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_AbortDeviceRequests_Args));\
\
    kern_return_t\
    SetConfiguration_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_SetConfiguration_Args));\
\
    kern_return_t\
    GetAddress_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_GetAddress_Args));\
\
    kern_return_t\
    GetSpeed_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_GetSpeed_Args));\
\
    kern_return_t\
    GetFrameNumber_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_GetFrameNumber_Args));\
\
    kern_return_t\
    GetPortStatus_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_GetPortStatus_Args));\
\
    kern_return_t\
    Reset_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_Reset_Args));\
\
    kern_return_t\
    CreateInterfaceIterator_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_CreateInterfaceIterator_Args));\
\
    kern_return_t\
    DestroyInterfaceIterator_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_DestroyInterfaceIterator_Args));\
\
    kern_return_t\
    CopyInterface_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostDevice::*func)(IOUSBHostDevice_CopyInterface_Args));\
\


#define IOUSBHostDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _GetDescriptor_Impl(IOUSBHostDevice__GetDescriptor_Args);\
\
    kern_return_t\
    Open_Impl(IOUSBHostDevice_Open_Args);\
\
    kern_return_t\
    Close_Impl(IOUSBHostDevice_Close_Args);\
\
    kern_return_t\
    CreateIOBuffer_Impl(IOUSBHostDevice_CreateIOBuffer_Args);\
\
    kern_return_t\
    AsyncDeviceRequest_Impl(IOUSBHostDevice_AsyncDeviceRequest_Args);\
\
    kern_return_t\
    DeviceRequest_Impl(IOUSBHostDevice_DeviceRequest_Args);\
\
    kern_return_t\
    AbortDeviceRequests_Impl(IOUSBHostDevice_AbortDeviceRequests_Args);\
\
    kern_return_t\
    SetConfiguration_Impl(IOUSBHostDevice_SetConfiguration_Args);\
\
    kern_return_t\
    GetAddress_Impl(IOUSBHostDevice_GetAddress_Args);\
\
    kern_return_t\
    GetSpeed_Impl(IOUSBHostDevice_GetSpeed_Args);\
\
    kern_return_t\
    GetFrameNumber_Impl(IOUSBHostDevice_GetFrameNumber_Args);\
\
    kern_return_t\
    GetPortStatus_Impl(IOUSBHostDevice_GetPortStatus_Args);\
\
    kern_return_t\
    Reset_Impl(IOUSBHostDevice_Reset_Args);\
\
    kern_return_t\
    CreateInterfaceIterator_Impl(IOUSBHostDevice_CreateInterfaceIterator_Args);\
\
    kern_return_t\
    DestroyInterfaceIterator_Impl(IOUSBHostDevice_DestroyInterfaceIterator_Args);\
\
    kern_return_t\
    CopyInterface_Impl(IOUSBHostDevice_CopyInterface_Args);\
\


#define IOUSBHostDevice_VirtualMethods \
\
public:\
\
    virtual kern_return_t\
    CopyDescriptor(\
        uint8_t type,\
        uint16_t * length,\
        uint8_t index,\
        uint16_t languageID,\
        uint8_t requestType,\
        uint8_t requestRecipient,\
        uint8_t * descriptor) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBDeviceDescriptor *\
    CopyDeviceDescriptor(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBConfigurationDescriptor *\
    CopyConfigurationDescriptor(\
        uint8_t index) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBConfigurationDescriptor *\
    CopyConfigurationDescriptorWithValue(\
        uint8_t bConfigurationValue) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBConfigurationDescriptor *\
    CopyConfigurationDescriptor(\
        IOService * forClient) APPLE_KEXT_OVERRIDE;\
\
    virtual const IOUSBBOSDescriptor *\
    CopyCapabilityDescriptors(\
) APPLE_KEXT_OVERRIDE;\
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


#if !KERNEL

extern OSMetaClass          * gIOUSBHostDeviceMetaClass;
extern OSClassLoadInformation IOUSBHostDevice_Class;

class IOUSBHostDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUSBHostDeviceInterface : public OSInterface
{
public:
    virtual kern_return_t
    CopyDescriptor(uint8_t type,
        uint16_t * length,
        uint8_t index,
        uint16_t languageID,
        uint8_t requestType,
        uint8_t requestRecipient,
        uint8_t * descriptor) = 0;

    virtual const IOUSBDeviceDescriptor *
    CopyDeviceDescriptor() = 0;

    virtual const IOUSBConfigurationDescriptor *
    CopyConfigurationDescriptor(uint8_t index) = 0;

    virtual const IOUSBConfigurationDescriptor *
    CopyConfigurationDescriptorWithValue(uint8_t bConfigurationValue) = 0;

    virtual const IOUSBConfigurationDescriptor *
    CopyConfigurationDescriptor(IOService * forClient) = 0;

    virtual const IOUSBBOSDescriptor *
    CopyCapabilityDescriptors() = 0;

    virtual const IOUSBStringDescriptor *
    CopyStringDescriptor(uint8_t index,
        uint16_t languageID) = 0;

    virtual const IOUSBStringDescriptor *
    CopyStringDescriptor(uint8_t index) = 0;

};

struct IOUSBHostDevice_IVars;
struct IOUSBHostDevice_LocalIVars;

class IOUSBHostDevice : public IOService, public IOUSBHostDeviceInterface
{
#if !KERNEL
    friend class IOUSBHostDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUSBHostDevice_IVars * ivars;
        IOUSBHostDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOUSBHostDevice_Methods
    IOUSBHostDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUSBHostDevice.iig:354-355 */


/* IOUSBHostDevice.iig:368- */

#endif /* ! _IOKIT_IOUSBHOSTDEVICE_H */

