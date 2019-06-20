/* iig(DriverKit-54.0.0.111.1) generated from IODataQueueDispatchSource.iig */

/* IODataQueueDispatchSource.iig:1-9 */
#ifndef _IOKIT_UIODATAQUEUEDISPATCHSOURCE_H
#define _IOKIT_UIODATAQUEUEDISPATCHSOURCE_H

#include <DriverKit/IODispatchQueue.h>  /* .iig include */ 
#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 

typedef void (^IODataQueueClientEnqueueEntryBlock)(void *data, size_t dataSize);
typedef void (^IODataQueueClientDequeueEntryBlock)(const void *data, size_t dataSize);

/* class IODataQueueDispatchSource IODataQueueDispatchSource.iig:10-86 */

#define IODataQueueDispatchSource_Create_ID            0xe8544306a54d09e0ULL
#define IODataQueueDispatchSource_CopyMemory_ID            0x9be617ec7d8cd728ULL
#define IODataQueueDispatchSource_SetDataAvailableHandler_ID            0xd2c1d8cc6ec3a591ULL
#define IODataQueueDispatchSource_SetDataServicedHandler_ID            0xd0aac29bba67b644ULL
#define IODataQueueDispatchSource_CopyDataAvailableHandler_ID            0xc856b17471f65d99ULL
#define IODataQueueDispatchSource_CopyDataServicedHandler_ID            0xd8759c8da406b3fcULL
#define IODataQueueDispatchSource_DataAvailable_ID            0xf799c876baf566f3ULL
#define IODataQueueDispatchSource_DataServiced_ID            0x8daa79f78047d8d8ULL

#define IODataQueueDispatchSource_Create_Args \
        uint64_t queueByteCount, \
        IODispatchQueue * queue, \
        IODataQueueDispatchSource ** source

#define IODataQueueDispatchSource_CopyMemory_Args \
        IOMemoryDescriptor ** memory

#define IODataQueueDispatchSource_SetDataAvailableHandler_Args \
        OSAction * action

#define IODataQueueDispatchSource_SetDataServicedHandler_Args \
        OSAction * action

#define IODataQueueDispatchSource_CopyDataAvailableHandler_Args \
        OSAction ** action

#define IODataQueueDispatchSource_CopyDataServicedHandler_Args \
        OSAction ** action

#define IODataQueueDispatchSource_SetEnable_Args \
        bool enable

#define IODataQueueDispatchSource_Cancel_Args \
        IODispatchSourceCancelHandler handler

#define IODataQueueDispatchSource_CheckForWork_Args \
        const IORPC rpc, \
        bool synchronous

#define IODataQueueDispatchSource_DataAvailable_Args \
        OSAction * action

#define IODataQueueDispatchSource_DataServiced_Args \
        OSAction * action

#define IODataQueueDispatchSource_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IODataQueueDispatchSource * self, const IORPC rpc);\
\
    static kern_return_t\
    Create(\
        uint64_t queueByteCount,\
        IODispatchQueue * queue,\
        IODataQueueDispatchSource ** source);\
\
    kern_return_t\
    CopyMemory(\
        IOMemoryDescriptor ** memory,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetDataAvailableHandler(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetDataServicedHandler(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    SendDataAvailable(\
);\
\
    void\
    SendDataServiced(\
);\
\
    kern_return_t\
    CopyDataAvailableHandler(\
        OSAction ** action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyDataServicedHandler(\
        OSAction ** action,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    DataAvailable(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    DataServiced(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    bool\
    IsDataAvailable(\
);\
\
    kern_return_t\
    Peek(\
        IODataQueueClientDequeueEntryBlock callback);\
\
    kern_return_t\
    Dequeue(\
        IODataQueueClientDequeueEntryBlock callback);\
\
    kern_return_t\
    DequeueWithCoalesce(\
        bool * sendDataServiced,\
        IODataQueueClientDequeueEntryBlock callback);\
\
    kern_return_t\
    Enqueue(\
        uint32_t dataSize,\
        IODataQueueClientEnqueueEntryBlock callback);\
\
    kern_return_t\
    EnqueueWithCoalesce(\
        uint32_t dataSize,\
        bool * sendDataAvailable,\
        IODataQueueClientEnqueueEntryBlock callback);\
\
\
protected:\
    /* _Impl methods */\
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
\
protected:\
    /* _Invoke methods */\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IODataQueueDispatchSource_Create_Args));\
\
    kern_return_t\
    CopyMemory_Invoke(const IORPC rpc,\
        kern_return_t (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_CopyMemory_Args));\
\
    kern_return_t\
    SetDataAvailableHandler_Invoke(const IORPC rpc,\
        kern_return_t (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_SetDataAvailableHandler_Args));\
\
    kern_return_t\
    SetDataServicedHandler_Invoke(const IORPC rpc,\
        kern_return_t (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_SetDataServicedHandler_Args));\
\
    kern_return_t\
    CopyDataAvailableHandler_Invoke(const IORPC rpc,\
        kern_return_t (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_CopyDataAvailableHandler_Args));\
\
    kern_return_t\
    CopyDataServicedHandler_Invoke(const IORPC rpc,\
        kern_return_t (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_CopyDataServicedHandler_Args));\
\
    kern_return_t\
    DataAvailable_Invoke(const IORPC rpc,\
        void (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_DataAvailable_Args));\
\
    kern_return_t\
    DataServiced_Invoke(const IORPC rpc,\
        void (IODataQueueDispatchSource::*func)(IODataQueueDispatchSource_DataServiced_Args));\
\


#define IODataQueueDispatchSource_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Impl(IODataQueueDispatchSource_Create_Args);\
\
    kern_return_t\
    CopyMemory_Impl(IODataQueueDispatchSource_CopyMemory_Args);\
\
    kern_return_t\
    SetDataAvailableHandler_Impl(IODataQueueDispatchSource_SetDataAvailableHandler_Args);\
\
    kern_return_t\
    SetDataServicedHandler_Impl(IODataQueueDispatchSource_SetDataServicedHandler_Args);\
\
    kern_return_t\
    CopyDataAvailableHandler_Impl(IODataQueueDispatchSource_CopyDataAvailableHandler_Args);\
\
    kern_return_t\
    CopyDataServicedHandler_Impl(IODataQueueDispatchSource_CopyDataServicedHandler_Args);\
\


#define IODataQueueDispatchSource_VirtualMethods \
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



extern OSMetaClass          * gIODataQueueDispatchSourceMetaClass;
extern OSClassLoadInformation IODataQueueDispatchSource_Class;

class IODataQueueDispatchSourceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};


class IODataQueueDispatchSourceInterface : public OSInterface
{
public:
};

struct IODataQueueDispatchSource_IVars;
struct IODataQueueDispatchSource_LocalIVars;

class IODataQueueDispatchSource : public IODispatchSource, public IODataQueueDispatchSourceInterface
{

    friend class IODataQueueDispatchSourceMetaClass;

public:
    union
    {
        IODataQueueDispatchSource_IVars * ivars;
        IODataQueueDispatchSource_LocalIVars * lvars;
    };
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(IODataQueueDispatchSource); };

    using super = IODispatchSource;

    IODataQueueDispatchSource_Methods

    IODataQueueDispatchSource_VirtualMethods
};
/* IODataQueueDispatchSource.iig:88- */
#endif /* ! _IOKIT_UIODATAQUEUEDISPATCHSOURCE_H */
