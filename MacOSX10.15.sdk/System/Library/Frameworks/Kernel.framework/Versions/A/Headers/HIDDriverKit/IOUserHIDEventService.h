/* iig(DriverKit-54.0.0.110.1) generated from IOUserHIDEventService.iig */

/* IOUserHIDEventService.iig:1-10 */
#ifndef _HIDDRIVERKIT_IOUSERHIDEVENTSERVICE_H
#define _HIDDRIVERKIT_IOUSERHIDEVENTSERVICE_H

#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <HIDDriverKit/IOHIDInterface.h>  /* .iig include */ 
#include <HIDDriverKit/IOHIDEventService.h>  /* .iig include */ 

class OSArray;

/* class IOUserHIDEventService IOUserHIDEventService.iig:11-178 */

#define IOUserHIDEventService_ReportAvailable_ID            0x64b213ea6ab88649ULL

#define IOUserHIDEventService_Start_Args \
        IOService * provider

#define IOUserHIDEventService_Stop_Args \
        IOService * provider

#define IOUserHIDEventService_ReportAvailable_Args \
        uint64_t timestamp, \
        uint32_t reportID, \
        uint32_t reportLength, \
        IOHIDReportType type, \
        IOMemoryDescriptor * report, \
        OSAction * action

#define IOUserHIDEventService_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserHIDEventService * self, const IORPC rpc);\
\
    bool\
    createReportPool(\
);\
\
    void\
    ReportAvailable(\
        uint64_t timestamp,\
        uint32_t reportID,\
        uint32_t reportLength,\
        IOHIDReportType type,\
        IOMemoryDescriptor * report,\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
    kern_return_t\
    Stop_Impl(IOService_Stop_Args);\
\
    void\
    ReportAvailable_Impl(IOUserHIDEventService_ReportAvailable_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    ReportAvailable_Invoke(const IORPC rpc,\
        void (IOUserHIDEventService::*func)(IOUserHIDEventService_ReportAvailable_Args));\
\


#define IOUserHIDEventService_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOUserHIDEventService_VirtualMethods \
\
public:\
\
    virtual bool\
    init(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    conformsTo(\
        uint32_t usagePage,\
        uint32_t usage) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    handleStart(\
        IOService * provider) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleReport(\
        uint64_t timestamp,\
        uint8_t * report,\
        uint32_t reportLength,\
        IOHIDReportType type,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual OSArray *\
    getElements(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    dispatchEvent(\
        IOHIDEvent * event) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserHIDEventServiceMetaClass;
extern OSClassLoadInformation IOUserHIDEventService_Class;

class IOUserHIDEventServiceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserHIDEventServiceInterface : public OSInterface
{
public:
    virtual bool
    conformsTo(uint32_t usagePage,
        uint32_t usage) = 0;

    virtual bool
    handleStart(IOService * provider) = 0;

    virtual void
    handleReport(uint64_t timestamp,
        uint8_t * report,
        uint32_t reportLength,
        IOHIDReportType type,
        uint32_t reportID) = 0;

    virtual OSArray *
    getElements() = 0;

};

struct IOUserHIDEventService_IVars;
struct IOUserHIDEventService_LocalIVars;

class IOUserHIDEventService : public IOHIDEventService, public IOUserHIDEventServiceInterface
{
#if !KERNEL
    friend class IOUserHIDEventServiceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserHIDEventService_IVars * ivars;
        IOUserHIDEventService_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOHIDEventService;

#if !KERNEL
    IOUserHIDEventService_Methods
    IOUserHIDEventService_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUserHIDEventService.iig:180- */
#endif /* ! _HIDDRIVERKIT_IOUSERHIDEVENTSERVICE_H */
