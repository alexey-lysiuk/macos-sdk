/* iig(DriverKit-54.0.0.110.1) generated from IOHIDEventService.iig */

/* IOHIDEventService.iig:1-16 */
#if !__IIG
#if KERNEL
#include <IOKit/hidevent/IOHIDEventService.h>
#endif
#endif

#ifndef _HIDDRIVERKIT_IOHIDEVENTSERVICE_H
#define _HIDDRIVERKIT_IOHIDEVENTSERVICE_H

#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/IOTypes.h>

class IOBufferMemoryDescriptor;
class IOHIDEvent;

/* class IOHIDEventService IOHIDEventService.iig:17-196 */

#define IOHIDEventService_EventAvailable_ID            0xb6d3212b1068148aULL
#define IOHIDEventService_SetEventMemory_ID            0xed62c58e8d2f64e7ULL
#define IOHIDEventService_DispatchKeyboardEvent_ID            0xc68d55b208972672ULL
#define IOHIDEventService_DispatchRelativePointerEvent_ID            0x93fd32cdf15513ddULL
#define IOHIDEventService_DispatchAbsolutePointerEvent_ID            0xf67d76377eba22b4ULL
#define IOHIDEventService_DispatchRelativeScrollWheelEvent_ID            0x994151fca1cd35a4ULL
#define IOHIDEventService_KernelStart_ID            0xae2fd4b5293ad02aULL
#define IOHIDEventService_SetLED_ID            0xfee475ac1384bab8ULL

#define IOHIDEventService_EventAvailable_Args \
        uint32_t length

#define IOHIDEventService_SetEventMemory_Args \
        IOBufferMemoryDescriptor * memory

#define IOHIDEventService_DispatchKeyboardEvent_Args \
        uint64_t timeStamp, \
        uint32_t usagePage, \
        uint32_t usage, \
        uint32_t value, \
        IOOptionBits options, \
        bool repeat

#define IOHIDEventService_DispatchRelativePointerEvent_Args \
        uint64_t timeStamp, \
        IOFixed dx, \
        IOFixed dy, \
        uint32_t buttonState, \
        IOOptionBits options, \
        bool accelerate

#define IOHIDEventService_DispatchAbsolutePointerEvent_Args \
        uint64_t timeStamp, \
        IOFixed x, \
        IOFixed y, \
        uint32_t buttonState, \
        IOOptionBits options, \
        bool accelerate

#define IOHIDEventService_DispatchRelativeScrollWheelEvent_Args \
        uint64_t timeStamp, \
        IOFixed dx, \
        IOFixed dy, \
        IOFixed dz, \
        IOOptionBits options, \
        bool accelerate

#define IOHIDEventService_KernelStart_Args \
        IOService * provider

#define IOHIDEventService_SetLED_Args \
        uint32_t usage, \
        bool on

#define IOHIDEventService_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOHIDEventService * self, const IORPC rpc);\
\
    kern_return_t\
    EventAvailable(\
        uint32_t length,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetEventMemory(\
        IOBufferMemoryDescriptor * memory,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DispatchKeyboardEvent(\
        uint64_t timeStamp,\
        uint32_t usagePage,\
        uint32_t usage,\
        uint32_t value,\
        IOOptionBits options,\
        bool repeat,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DispatchRelativePointerEvent(\
        uint64_t timeStamp,\
        IOFixed dx,\
        IOFixed dy,\
        uint32_t buttonState,\
        IOOptionBits options,\
        bool accelerate,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DispatchAbsolutePointerEvent(\
        uint64_t timeStamp,\
        IOFixed x,\
        IOFixed y,\
        uint32_t buttonState,\
        IOOptionBits options,\
        bool accelerate,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DispatchRelativeScrollWheelEvent(\
        uint64_t timeStamp,\
        IOFixed dx,\
        IOFixed dy,\
        IOFixed dz,\
        IOOptionBits options,\
        bool accelerate,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    KernelStart(\
        IOService * provider,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    SetLED(\
        uint32_t usage,\
        bool on,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    void\
    SetLED_Impl(IOHIDEventService_SetLED_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    EventAvailable_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_EventAvailable_Args));\
\
    kern_return_t\
    SetEventMemory_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_SetEventMemory_Args));\
\
    kern_return_t\
    DispatchKeyboardEvent_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_DispatchKeyboardEvent_Args));\
\
    kern_return_t\
    DispatchRelativePointerEvent_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_DispatchRelativePointerEvent_Args));\
\
    kern_return_t\
    DispatchAbsolutePointerEvent_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_DispatchAbsolutePointerEvent_Args));\
\
    kern_return_t\
    DispatchRelativeScrollWheelEvent_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_DispatchRelativeScrollWheelEvent_Args));\
\
    kern_return_t\
    KernelStart_Invoke(const IORPC rpc,\
        kern_return_t (IOHIDEventService::*func)(IOHIDEventService_KernelStart_Args));\
\
    kern_return_t\
    SetLED_Invoke(const IORPC rpc,\
        void (IOHIDEventService::*func)(IOHIDEventService_SetLED_Args));\
\


#define IOHIDEventService_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    EventAvailable_Impl(IOHIDEventService_EventAvailable_Args);\
\
    kern_return_t\
    SetEventMemory_Impl(IOHIDEventService_SetEventMemory_Args);\
\
    kern_return_t\
    DispatchKeyboardEvent_Impl(IOHIDEventService_DispatchKeyboardEvent_Args);\
\
    kern_return_t\
    DispatchRelativePointerEvent_Impl(IOHIDEventService_DispatchRelativePointerEvent_Args);\
\
    kern_return_t\
    DispatchAbsolutePointerEvent_Impl(IOHIDEventService_DispatchAbsolutePointerEvent_Args);\
\
    kern_return_t\
    DispatchRelativeScrollWheelEvent_Impl(IOHIDEventService_DispatchRelativeScrollWheelEvent_Args);\
\
    kern_return_t\
    KernelStart_Impl(IOHIDEventService_KernelStart_Args);\
\


#define IOHIDEventService_VirtualMethods \
\
public:\
\
    virtual void\
    dispatchEvent(\
        IOHIDEvent * event) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOHIDEventServiceMetaClass;
extern OSClassLoadInformation IOHIDEventService_Class;

class IOHIDEventServiceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOHIDEventServiceInterface : public OSInterface
{
public:
    virtual void
    dispatchEvent(IOHIDEvent * event) = 0;

};

struct IOHIDEventService_IVars;
struct IOHIDEventService_LocalIVars;

class IOHIDEventService : public IOService, public IOHIDEventServiceInterface
{
#if !KERNEL
    friend class IOHIDEventServiceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOHIDEventService_IVars * ivars;
        IOHIDEventService_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOHIDEventService_Methods
    IOHIDEventService_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


/* IOHIDEventService.iig:205- */
#endif /* ! _HIDDRIVERKIT_IOHIDEVENTSERVICE_H */
