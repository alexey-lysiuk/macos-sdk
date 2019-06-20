/* iig(DriverKit-54.0.0.111.1) generated from IOInterruptDispatchSource.iig */

/* IOInterruptDispatchSource.iig:1-11 */
#ifndef _IOKIT_UIOINTERRUPTDISPATCHSOURCE_H
#define _IOKIT_UIOINTERRUPTDISPATCHSOURCE_H

#include <DriverKit/IODispatchQueue.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 

struct IOInterruptDispatchSourcePayload {
	uint64_t time;
	uint64_t count;
};

/* class IOInterruptDispatchSource IOInterruptDispatchSource.iig:12-45 */

#define IOInterruptDispatchSource_Create_ID            0xb6a948b1585fc259ULL
#define IOInterruptDispatchSource_SetHandler_ID            0xfcc79b0928501bb1ULL
#define IOInterruptDispatchSource_InterruptOccurred_ID            0xce0513291cfa1ee1ULL

#define IOInterruptDispatchSource_Create_Args \
        IOService * provider, \
        uint32_t index, \
        IODispatchQueue * queue, \
        IOInterruptDispatchSource ** source

#define IOInterruptDispatchSource_SetHandler_Args \
        OSAction * action

#define IOInterruptDispatchSource_SetEnable_Args \
        bool enable

#define IOInterruptDispatchSource_Cancel_Args \
        IODispatchSourceCancelHandler handler

#define IOInterruptDispatchSource_CheckForWork_Args \
        const IORPC rpc, \
        bool synchronous

#define IOInterruptDispatchSource_InterruptOccurred_Args \
        OSAction * action, \
        uint64_t count, \
        uint64_t time

#define IOInterruptDispatchSource_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOInterruptDispatchSource * self, const IORPC rpc);\
\
    static kern_return_t\
    Create(\
        IOService * provider,\
        uint32_t index,\
        IODispatchQueue * queue,\
        IOInterruptDispatchSource ** source);\
\
    kern_return_t\
    SetHandler(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    InterruptOccurred(\
        IORPC rpc,\
        OSAction * action,\
        uint64_t count,\
        uint64_t time,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Call(IOInterruptDispatchSource_Create_Args);\
\
    kern_return_t\
    SetHandler_Impl(IOInterruptDispatchSource_SetHandler_Args);\
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
    void\
    InterruptOccurred_Impl(IOInterruptDispatchSource_InterruptOccurred_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IOInterruptDispatchSource_Create_Args));\
\
    kern_return_t\
    SetHandler_Invoke(const IORPC rpc,\
        kern_return_t (IOInterruptDispatchSource::*func)(IOInterruptDispatchSource_SetHandler_Args));\
\
    kern_return_t\
    InterruptOccurred_Invoke(const IORPC rpc,\
        void (IOInterruptDispatchSource::*func)(IOInterruptDispatchSource_InterruptOccurred_Args));\
\


#define IOInterruptDispatchSource_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Impl(IOInterruptDispatchSource_Create_Args);\
\


#define IOInterruptDispatchSource_VirtualMethods \
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



extern OSMetaClass          * gIOInterruptDispatchSourceMetaClass;
extern OSClassLoadInformation IOInterruptDispatchSource_Class;

class IOInterruptDispatchSourceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};


class IOInterruptDispatchSourceInterface : public OSInterface
{
public:
};

struct IOInterruptDispatchSource_IVars;
struct IOInterruptDispatchSource_LocalIVars;

class IOInterruptDispatchSource : public IODispatchSource, public IOInterruptDispatchSourceInterface
{

    friend class IOInterruptDispatchSourceMetaClass;

public:
    union
    {
        IOInterruptDispatchSource_IVars * ivars;
        IOInterruptDispatchSource_LocalIVars * lvars;
    };
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(IOInterruptDispatchSource); };

    using super = IODispatchSource;

    IOInterruptDispatchSource_Methods

    IOInterruptDispatchSource_VirtualMethods
};
/* IOInterruptDispatchSource.iig:47- */
#endif /* ! _IOKIT_UIOINTERRUPTDISPATCHSOURCE_H */
