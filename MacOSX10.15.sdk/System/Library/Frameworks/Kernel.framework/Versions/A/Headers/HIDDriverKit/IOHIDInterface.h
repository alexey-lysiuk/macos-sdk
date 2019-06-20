/* iig(DriverKit-54.0.0.110.1) generated from IOHIDInterface.iig */

/* IOHIDInterface.iig:1-23 */
#if !__IIG
#if KERNEL
#include <IOKit/hid/IOHIDInterface.h>
#endif
#endif

#ifndef _HIDDRIVERKIT_IOHIDINTERFACE_H
#define _HIDDRIVERKIT_IOHIDINTERFACE_H

#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 
#include <DriverKit/IOBufferMemoryDescriptor.h>  /* .iig include */ 
#include <HIDDriverKit/IOHIDDeviceTypes.h>
#include <DriverKit/IOTypes.h>

class OSArray;

typedef struct IOHIDElementValueHeader {
    uint32_t cookie;
    uint32_t value[0];
} IOHIDElementValueHeader;

/* class IOHIDInterface IOHIDInterface.iig:24-237 */

#define IOHIDInterface_GetElementValues_ID            0xc4a89d6fd6fd065cULL
#define IOHIDInterface_SetElementValues_ID            0xf964ed7a299eb3a5ULL
#define IOHIDInterface_GetSupportedCookies_ID            0xec13cf336ecceaccULL
#define IOHIDInterface_ReportAvailable_ID            0xd46e690536704302ULL
#define IOHIDInterface_AddReportToPool_ID            0xbe04e3d42572fd53ULL
#define IOHIDInterface_Open_ID            0x9f3263b463025b4fULL
#define IOHIDInterface_Close_ID            0x9bcf029fa80af1b5ULL
#define IOHIDInterface_SetReport_ID            0xca9744a1af98f7dfULL
#define IOHIDInterface_GetReport_ID            0xa8ccbd83dbbed4cdULL

#define IOHIDInterface_GetElementValues_Args \
        uint32_t count, \
        IOMemoryDescriptor * elementValues

#define IOHIDInterface_SetElementValues_Args \
        uint32_t count, \
        IOMemoryDescriptor * elementValues

#define IOHIDInterface_GetSupportedCookies_Args \
        IOBufferMemoryDescriptor ** cookies

#define IOHIDInterface_ReportAvailable_Args \
        uint64_t timestamp, \
        uint32_t reportID, \
        uint32_t reportLength, \
        IOHIDReportType type, \
        IOMemoryDescriptor * report, \
        OSAction * action

#define IOHIDInterface_AddReportToPool_Args \
        IOBufferMemoryDescriptor * report

#define IOHIDInterface_Open_Args \
        IOOptionBits options, \
        OSAction * action

#define IOHIDInterface_Close_Args \
        IOOptionBits options

#define IOHIDInterface_SetReport_Args \
        IOMemoryDescriptor * report, \
        IOHIDReportType reportType, \
        uint32_t reportID, \
        IOOptionBits options

#define IOHIDInterface_GetReport_Args \
        IOMemoryDescriptor * report, \
        IOHIDReportType reportType, \
        uint32_t reportID, \
        IOOptionBits options

#define IOHIDInterface_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOHIDInterface * self, const IORPC rpc);\
\
    kern_return_t\
    GetElementValues(\
        uint32_t count,\
        IOMemoryDescriptor * elementValues,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetElementValues(\
        uint32_t count,\
        IOMemoryDescriptor * elementValues,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetSupportedCookies(\
        IOBufferMemoryDescriptor ** cookies,\
        OSDispatchMethod supermethod = NULL);\
\
    bool\
    createElements(\
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
    kern_return_t\
    AddReportToPool(\
        IOBufferMemoryDescriptor * report,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Open(\
        IOOptionBits options,\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Close(\
        IOOptionBits options,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetReport(\
        IOMemoryDescriptor * report,\
        IOHIDReportType reportType,\
        uint32_t reportID,\
        IOOptionBits options,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetReport(\
        IOMemoryDescriptor * report,\
        IOHIDReportType reportType,\
        uint32_t reportID,\
        IOOptionBits options,\
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
    GetElementValues_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_GetElementValues_Args));\
\
    kern_return_t\
    SetElementValues_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_SetElementValues_Args));\
\
    kern_return_t\
    GetSupportedCookies_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_GetSupportedCookies_Args));\
\
    kern_return_t\
    ReportAvailable_Invoke(const IORPC rpc,\
        void (IOHIDInterface::*func)(IOHIDInterface_ReportAvailable_Args));\
\
    kern_return_t\
    AddReportToPool_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_AddReportToPool_Args));\
\
    kern_return_t\
    Open_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_Open_Args));\
\
    kern_return_t\
    Close_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_Close_Args));\
\
    kern_return_t\
    SetReport_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_SetReport_Args));\
\
    kern_return_t\
    GetReport_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDInterface::*func)(IOHIDInterface_GetReport_Args));\
\


#define IOHIDInterface_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    GetElementValues_Impl(IOHIDInterface_GetElementValues_Args);\
\
    kern_return_t\
    SetElementValues_Impl(IOHIDInterface_SetElementValues_Args);\
\
    kern_return_t\
    GetSupportedCookies_Impl(IOHIDInterface_GetSupportedCookies_Args);\
\
    kern_return_t\
    AddReportToPool_Impl(IOHIDInterface_AddReportToPool_Args);\
\
    kern_return_t\
    Open_Impl(IOHIDInterface_Open_Args);\
\
    kern_return_t\
    Close_Impl(IOHIDInterface_Close_Args);\
\
    kern_return_t\
    SetReport_Impl(IOHIDInterface_SetReport_Args);\
\
    kern_return_t\
    GetReport_Impl(IOHIDInterface_GetReport_Args);\
\


#define IOHIDInterface_VirtualMethods \
\
public:\
\
    virtual kern_return_t\
    getElementValues(\
        OSArray * elements) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    setElementValues(\
        OSArray * elements) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    init(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    processReport(\
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
    virtual kern_return_t\
    commitElements(\
        OSArray * elements,\
        IOHIDElementCommitDirection direction) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOHIDInterfaceMetaClass;
extern OSClassLoadInformation IOHIDInterface_Class;

class IOHIDInterfaceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOHIDInterfaceInterface : public OSInterface
{
public:
    virtual kern_return_t
    getElementValues(OSArray * elements) = 0;

    virtual kern_return_t
    setElementValues(OSArray * elements) = 0;

    virtual void
    processReport(uint64_t timestamp,
        uint8_t * report,
        uint32_t reportLength,
        IOHIDReportType type,
        uint32_t reportID) = 0;

    virtual OSArray *
    getElements() = 0;

    virtual kern_return_t
    commitElements(OSArray * elements,
        IOHIDElementCommitDirection direction) = 0;

};

struct IOHIDInterface_IVars;
struct IOHIDInterface_LocalIVars;

class IOHIDInterface : public IOService, public IOHIDInterfaceInterface
{
#if !KERNEL
    friend class IOHIDInterfaceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOHIDInterface_IVars * ivars;
        IOHIDInterface_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOHIDInterface_Methods
    IOHIDInterface_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


/* IOHIDInterface.iig:254- */
#endif /* ! _HIDDRIVERKIT_IOHIDINTERFACE_H */
