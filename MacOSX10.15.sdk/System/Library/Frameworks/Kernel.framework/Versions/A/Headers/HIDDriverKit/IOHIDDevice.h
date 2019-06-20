/* iig(DriverKit-54.0.0.110.1) generated from IOHIDDevice.iig */

/* IOHIDDevice.iig:1-16 */
#if !__IIG
#if KERNEL
#include <IOKit/hid/IOHIDDevice.h>
#endif
#endif

#ifndef _HIDDRIVERKIT_IOHIDDEVICE_H
#define _HIDDRIVERKIT_IOHIDDEVICE_H

#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <HIDDriverKit/IOHIDDeviceTypes.h>
#include <DriverKit/IOTypes.h>

class IOMemoryDescriptor;

/* class IOHIDDevice IOHIDDevice.iig:17-106 */

#define IOHIDDevice_KernelStart_ID            0xff0b791163823830ULL
#define IOHIDDevice_KernelCompleteReport_ID            0xdb01a9b43a5e9a30ULL
#define IOHIDDevice__ProcessReport_ID            0xd539b835ea14880fULL
#define IOHIDDevice__SetProperty_ID            0xa6ee936a6065f6baULL
#define IOHIDDevice_HandleReport_ID            0xc307c6b8732db3efULL
#define IOHIDDevice_CompleteReport_ID            0xf2d80ecf6d8c6cb5ULL

#define IOHIDDevice_KernelStart_Args \
        IOService * provider

#define IOHIDDevice_KernelCompleteReport_Args \
        OSAction * action, \
        IOReturn status, \
        uint32_t actualByteCount

#define IOHIDDevice__ProcessReport_Args \
        HIDReportCommandType command, \
        IOMemoryDescriptor * report, \
        IOHIDReportType reportType, \
        IOOptionBits options, \
        uint32_t completionTimeout, \
        OSAction * action

#define IOHIDDevice__SetProperty_Args \
        IOBufferMemoryDescriptor * serialization

#define IOHIDDevice_HandleReport_Args \
        uint64_t timestamp, \
        IOMemoryDescriptor * report, \
        uint32_t reportLength, \
        IOHIDReportType reportType, \
        IOOptionBits options

#define IOHIDDevice_CompleteReport_Args \
        OSAction * action, \
        IOReturn status, \
        uint32_t actualByteCount

#define IOHIDDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOHIDDevice * self, const IORPC rpc);\
\
    kern_return_t\
    KernelStart(\
        IOService * provider,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    KernelCompleteReport(\
        OSAction * action,\
        IOReturn status,\
        uint32_t actualByteCount,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    _ProcessReport(\
        HIDReportCommandType command,\
        IOMemoryDescriptor * report,\
        IOHIDReportType reportType,\
        IOOptionBits options,\
        uint32_t completionTimeout,\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    _SetProperty(\
        IOBufferMemoryDescriptor * serialization,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HandleReport(\
        uint64_t timestamp,\
        IOMemoryDescriptor * report,\
        uint32_t reportLength,\
        IOHIDReportType reportType,\
        IOOptionBits options,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    CompleteReport(\
        OSAction * action,\
        IOReturn status,\
        uint32_t actualByteCount,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    void\
    _ProcessReport_Impl(IOHIDDevice__ProcessReport_Args);\
\
    void\
    _SetProperty_Impl(IOHIDDevice__SetProperty_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    KernelStart_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDDevice::*func)(IOHIDDevice_KernelStart_Args));\
\
    kern_return_t\
    KernelCompleteReport_Invoke(const IORPC rpc,\
        void (IOHIDDevice::*func)(IOHIDDevice_KernelCompleteReport_Args));\
\
    kern_return_t\
    _ProcessReport_Invoke(const IORPC rpc,\
        void (IOHIDDevice::*func)(IOHIDDevice__ProcessReport_Args));\
\
    kern_return_t\
    _SetProperty_Invoke(const IORPC rpc,\
        void (IOHIDDevice::*func)(IOHIDDevice__SetProperty_Args));\
\
    kern_return_t\
    HandleReport_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDDevice::*func)(IOHIDDevice_HandleReport_Args));\
\
    kern_return_t\
    CompleteReport_Invoke(const IORPC rpc,\
        void (IOHIDDevice::*func)(IOHIDDevice_CompleteReport_Args));\
\


#define IOHIDDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    KernelStart_Impl(IOHIDDevice_KernelStart_Args);\
\
    void\
    KernelCompleteReport_Impl(IOHIDDevice_KernelCompleteReport_Args);\
\
    kern_return_t\
    HandleReport_Impl(IOHIDDevice_HandleReport_Args);\
\


#define IOHIDDevice_VirtualMethods \
\
public:\
\
    virtual kern_return_t\
    getReport(\
        IOMemoryDescriptor * report,\
        IOHIDReportType reportType,\
        IOOptionBits options,\
        uint32_t completionTimeout,\
        OSAction * action) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    setReport(\
        IOMemoryDescriptor * report,\
        IOHIDReportType reportType,\
        IOOptionBits options,\
        uint32_t completionTimeout,\
        OSAction * action) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    setProperty(\
        OSObject * key,\
        OSObject * value) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOHIDDeviceMetaClass;
extern OSClassLoadInformation IOHIDDevice_Class;

class IOHIDDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOHIDDeviceInterface : public OSInterface
{
public:
    virtual kern_return_t
    getReport(IOMemoryDescriptor * report,
        IOHIDReportType reportType,
        IOOptionBits options,
        uint32_t completionTimeout,
        OSAction * action) = 0;

    virtual kern_return_t
    setReport(IOMemoryDescriptor * report,
        IOHIDReportType reportType,
        IOOptionBits options,
        uint32_t completionTimeout,
        OSAction * action) = 0;

    virtual void
    setProperty(OSObject * key,
        OSObject * value) = 0;

};

struct IOHIDDevice_IVars;
struct IOHIDDevice_LocalIVars;

class IOHIDDevice : public IOService, public IOHIDDeviceInterface
{
#if !KERNEL
    friend class IOHIDDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOHIDDevice_IVars * ivars;
        IOHIDDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOHIDDevice_Methods
    IOHIDDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


/* IOHIDDevice.iig:157- */

#endif /* ! _HIDDRIVERKIT_IOHIDDEVICE_H */
