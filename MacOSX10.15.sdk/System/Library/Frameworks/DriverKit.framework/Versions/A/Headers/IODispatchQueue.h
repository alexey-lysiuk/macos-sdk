/* iig(DriverKit-54.0.0.111.1) generated from IODispatchQueue.iig */

/* IODispatchQueue.iig:1-12 */
#ifndef _IOKIT_UIODISPATCHQUEUE_H
#define _IOKIT_UIODISPATCHQUEUE_H

#include <DriverKit/OSObject.h>  /* .iig include */ 
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IODispatchSource.h>  /* .iig include */ 

typedef int (*IODispatchLogFunction)(const char *format, ...);
typedef void (^IODispatchBlock)(void);
typedef void (*IODispatchFunction)(void * context);
typedef void (^IODispatchQueueCancelHandler)(void);

/* class IODispatchQueue IODispatchQueue.iig:13-51 */

#define IODispatchQueue_SetPort_ID            0xc437e970b5609767ULL
#define IODispatchQueue_Create_ID            0xac000428df2a91d0ULL

#define IODispatchQueue_SetPort_Args \
        mach_port_t port

#define IODispatchQueue_Create_Args \
        const char * name, \
        uint64_t options, \
        uint64_t priority, \
        IODispatchQueue ** queue

#define IODispatchQueue_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IODispatchQueue * self, const IORPC rpc);\
\
    kern_return_t\
    SetPort(\
        mach_port_t port,\
        OSDispatchMethod supermethod = NULL);\
\
    static kern_return_t\
    Create(\
        const IODispatchQueueName name,\
        uint64_t options,\
        uint64_t priority,\
        IODispatchQueue ** queue);\
\
    bool\
    OnQueue(\
);\
\
    const char *\
    GetName(\
);\
\
    kern_return_t\
    Cancel(\
        IODispatchQueueCancelHandler handler);\
\
    void\
    DispatchAsync(\
        IODispatchBlock block);\
\
    void\
    DispatchAsync_f(\
        void * context,\
        IODispatchFunction function);\
\
    void\
    DispatchSync(\
        IODispatchBlock block);\
\
    void\
    DispatchSync_f(\
        void * context,\
        IODispatchFunction function);\
\
    static void\
    Log(\
        const char * message,\
        IODispatchLogFunction output);\
\
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Call(IODispatchQueue_Create_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    SetPort_Invoke(const IORPC rpc,\
        kern_return_t (IODispatchQueue::*func)(IODispatchQueue_SetPort_Args));\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IODispatchQueue_Create_Args));\
\


#define IODispatchQueue_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    SetPort_Impl(IODispatchQueue_SetPort_Args);\
\
    static kern_return_t\
    Create_Impl(IODispatchQueue_Create_Args);\
\


#define IODispatchQueue_VirtualMethods \
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



extern OSMetaClass          * gIODispatchQueueMetaClass;
extern OSClassLoadInformation IODispatchQueue_Class;

class IODispatchQueueMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};


class IODispatchQueueInterface : public OSInterface
{
public:
};

struct IODispatchQueue_IVars;
struct IODispatchQueue_LocalIVars;

class IODispatchQueue : public OSObject, public IODispatchQueueInterface
{

    friend class IODispatchQueueMetaClass;

public:
    union
    {
        IODispatchQueue_IVars * ivars;
        IODispatchQueue_LocalIVars * lvars;
    };
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(IODispatchQueue); };

    using super = OSObject;

    IODispatchQueue_Methods

    IODispatchQueue_VirtualMethods
};
/* IODispatchQueue.iig:53-54 */

#if DRIVERKIT_PRIVATE
/* IODispatchQueue.iig:61- */#endif

#endif /* ! _IOKIT_UIODISPATCH_H */
