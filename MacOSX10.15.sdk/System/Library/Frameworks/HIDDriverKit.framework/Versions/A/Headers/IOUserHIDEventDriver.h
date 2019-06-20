/* iig(DriverKit-54.0.0.110.1) generated from IOUserHIDEventDriver.iig */

/* IOUserHIDEventDriver.iig:1-9 */
#ifndef _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H
#define _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H

#include <HIDDriverKit/IOUserHIDEventService.h>  /* .iig include */ 

class IOHIDElement;
class IOHIDEvent;
class IOHIDDigitizerCollection;

/* class IOUserHIDEventDriver IOUserHIDEventDriver.iig:10-282 */


#define IOUserHIDEventDriver_Start_Args \
        IOService * provider

#define IOUserHIDEventDriver_SetLED_Args \
        uint32_t usage, \
        bool on

#define IOUserHIDEventDriver_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserHIDEventDriver * self, const IORPC rpc);\
\
    void\
    setAccelerationProperties(\
);\
\
    void\
    setSurfaceDimensions(\
);\
\
    IOHIDEvent *\
    createEventForDigitizerCollection(\
        IOHIDDigitizerCollection * collection,\
        uint64_t timestamp,\
        uint32_t reportID);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
    void\
    SetLED_Impl(IOHIDEventService_SetLED_Args);\
\
\
protected:\
    /* _Invoke methods */\
\


#define IOUserHIDEventDriver_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOUserHIDEventDriver_VirtualMethods \
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
    virtual void\
    handleReport(\
        uint64_t timestamp,\
        uint8_t * report,\
        uint32_t reportLength,\
        IOHIDReportType type,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseElements(\
        OSArray * elements) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseKeyboardElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parsePointerElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseScrollElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseLEDElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseDigitizerElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleKeyboardReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleRelativePointerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleAbsolutePointerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleScrollReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleDigitizerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserHIDEventDriverMetaClass;
extern OSClassLoadInformation IOUserHIDEventDriver_Class;

class IOUserHIDEventDriverMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserHIDEventDriverInterface : public OSInterface
{
public:
    virtual bool
    parseElements(OSArray * elements) = 0;

    virtual bool
    parseKeyboardElement(IOHIDElement * element) = 0;

    virtual bool
    parsePointerElement(IOHIDElement * element) = 0;

    virtual bool
    parseScrollElement(IOHIDElement * element) = 0;

    virtual bool
    parseLEDElement(IOHIDElement * element) = 0;

    virtual bool
    parseDigitizerElement(IOHIDElement * element) = 0;

    virtual void
    handleKeyboardReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleRelativePointerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleAbsolutePointerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleScrollReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleDigitizerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

};

struct IOUserHIDEventDriver_IVars;
struct IOUserHIDEventDriver_LocalIVars;

class IOUserHIDEventDriver : public IOUserHIDEventService, public IOUserHIDEventDriverInterface
{
#if !KERNEL
    friend class IOUserHIDEventDriverMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserHIDEventDriver_IVars * ivars;
        IOUserHIDEventDriver_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOUserHIDEventService;

#if !KERNEL
    IOUserHIDEventDriver_Methods
    IOUserHIDEventDriver_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUserHIDEventDriver.iig:284- */
#endif /* _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H */
