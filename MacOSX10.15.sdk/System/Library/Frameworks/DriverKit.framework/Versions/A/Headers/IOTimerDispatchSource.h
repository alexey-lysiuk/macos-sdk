/* iig(DriverKit-54.0.0.111.1) generated from IOTimerDispatchSource.iig */

/* IOTimerDispatchSource.iig:1-41 */
#ifndef _IOKIT_UIOTIMERDISPATCHSOURCE_H
#define _IOKIT_UIOTIMERDISPATCHSOURCE_H

#include <DriverKit/IODispatchQueue.h>  /* .iig include */ 

/*!
 * @enum Clock type to pass in IOTimerDispatchSource::WakeAtTime() `options`
 * @discussion Determines how `deadline` and `leeway` arguments are interpreted.
 *
 * @constant kIOTimerClockUptimeRaw
 * Type of a clock value from clock_gettime_nsec_np(CLOCK_UPTIME_RAW).
 * Equivalent to a value from mach_absolute_time() but in nanoseconds.
 *
 * @constant kIOTimerClockMonotonicRaw
 * Type of a clock value from clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW).
 * Equivalent to a value from mach_continuous_time() but in nanoseconds.
 *
 * @constant kIOTimerClockRealTime
 * @constant kIOTimerClockWallTime
 * Type of a clock value from clock_gettime_nsec_np(CLOCK_REALTIME).
 * Equivalent to a value from gettimeofday() but in nanoseconds.
 *
 * @constant kIOTimerClockMachAbsoluteTime
 * Type of a clock value from mach_absolute_time() in tick units.
 * Prefer to use equivalent clock_gettime_nsec_np(CLOCK_UPTIME_RAW) in
 * nanoseconds.
 *
 * @constant kIOTimerClockMachContinuousTime
 * Type of a clock value from mach_continuous_time() in tick units.
 * Prefer to use equivalent clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW) in
 * nanoseconds.
 */
enum {
	kIOTimerClockUptimeRaw = 0x88ull,
	kIOTimerClockMonotonicRaw = 0x84ull,
	kIOTimerClockRealTime = 0x80ull,
	kIOTimerClockWallTime = 0x80ull,
	kIOTimerClockMachAbsoluteTime = 0xC8ull,
	kIOTimerClockMachContinuousTime = 0xC4ull,
};

/* class IOTimerDispatchSource IOTimerDispatchSource.iig:42-79 */

#define IOTimerDispatchSource_Create_ID            0x5703101ba090eaf0ULL
#define IOTimerDispatchSource_SetHandler_ID            0x487f4f13f1a0a074ULL
#define IOTimerDispatchSource_WakeAtTime_ID            0x1da868f27d5d7d37ULL
#define IOTimerDispatchSource_TimerOccurred_ID            0x0f4ab1c3cbb5ae47ULL

#define IOTimerDispatchSource_Create_Args \
        IODispatchQueue * queue, \
        IOTimerDispatchSource ** source

#define IOTimerDispatchSource_SetHandler_Args \
        OSAction * action

#define IOTimerDispatchSource_SetEnable_Args \
        bool enable

#define IOTimerDispatchSource_Cancel_Args \
        IODispatchSourceCancelHandler handler

#define IOTimerDispatchSource_CheckForWork_Args \
        const IORPC rpc, \
        bool synchronous

#define IOTimerDispatchSource_WakeAtTime_Args \
        uint64_t options, \
        uint64_t deadline, \
        uint64_t leeway

#define IOTimerDispatchSource_TimerOccurred_Args \
        OSAction * action, \
        uint64_t time

#define IOTimerDispatchSource_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOTimerDispatchSource * self, const IORPC rpc);\
\
    static kern_return_t\
    Create(\
        IODispatchQueue * queue,\
        IOTimerDispatchSource ** source);\
\
    kern_return_t\
    SetHandler(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    WakeAtTime(\
        uint64_t options,\
        uint64_t deadline,\
        uint64_t leeway,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    TimerOccurred(\
        IORPC rpc,\
        OSAction * action,\
        uint64_t time,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Impl(IOTimerDispatchSource_Create_Args);\
\
    kern_return_t\
    SetHandler_Impl(IOTimerDispatchSource_SetHandler_Args);\
\
    kern_return_t\
    SetEnable_Impl(IODispatchSource_SetEnable_Args);\
\
    kern_return_t\
    Cancel_Impl(IODispatchSource_Cancel_Args);\
\
    kern_return_t\
    CheckForWork_Impl(IODispatchSource_CheckForWork_Args);\
\
    kern_return_t\
    WakeAtTime_Impl(IOTimerDispatchSource_WakeAtTime_Args);\
\
    void\
    TimerOccurred_Impl(IOTimerDispatchSource_TimerOccurred_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IOTimerDispatchSource_Create_Args));\
\
    kern_return_t\
    SetHandler_Invoke(const IORPC rpc,\
        kern_return_t (IOTimerDispatchSource::*func)(IOTimerDispatchSource_SetHandler_Args));\
\
    kern_return_t\
    WakeAtTime_Invoke(const IORPC rpc,\
        kern_return_t (IOTimerDispatchSource::*func)(IOTimerDispatchSource_WakeAtTime_Args));\
\
    kern_return_t\
    TimerOccurred_Invoke(const IORPC rpc,\
        void (IOTimerDispatchSource::*func)(IOTimerDispatchSource_TimerOccurred_Args));\
\


#define IOTimerDispatchSource_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOTimerDispatchSource_VirtualMethods \
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


#if !KERNEL

extern OSMetaClass          * gIOTimerDispatchSourceMetaClass;
extern OSClassLoadInformation IOTimerDispatchSource_Class;

class IOTimerDispatchSourceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

class IOTimerDispatchSourceInterface : public OSInterface
{
public:
};

struct IOTimerDispatchSource_IVars;
struct IOTimerDispatchSource_LocalIVars;

class IOTimerDispatchSource : public IODispatchSource, public IOTimerDispatchSourceInterface
{
#if KERNEL
    OSDeclareDefaultStructorsWithDispatch(IOTimerDispatchSource);
#endif /* KERNEL */

#if !KERNEL
    friend class IOTimerDispatchSourceMetaClass;
#endif /* !KERNEL */

public:
    union
    {
        IOTimerDispatchSource_IVars * ivars;
        IOTimerDispatchSource_LocalIVars * lvars;
    };
#if !KERNEL
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(IOTimerDispatchSource); };
#endif /* KERNEL */

    using super = IODispatchSource;

#if !KERNEL
    IOTimerDispatchSource_Methods
#endif /* !KERNEL */

    IOTimerDispatchSource_VirtualMethods
};
/* IOTimerDispatchSource.iig:81- */

#endif /* ! _IOKIT_UIOTIMERDISPATCHSOURCE_H */
