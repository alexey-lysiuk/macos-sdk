/* iig(DriverKit-54.0.0.111.1) generated from IOBlockStorageDevice.iig */

/* IOBlockStorageDevice.iig:1-8 */
#ifndef _IOKIT_UIOBLOCKSTORAGEDEVICE_H
#define _IOKIT_UIOBLOCKSTORAGEDEVICE_H

#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 
#include <DriverKit/IODataQueueDispatchSource.h>  /* .iig include */ 

/* class _IOBlockStorageDevice IOBlockStorageDevice.iig:9-42 */

#define _IOBlockStorageDevice_DoAsyncReadWriteCompletion_ID            0x4f3d0282014e62d4ULL
#define _IOBlockStorageDevice_DoAsyncReadWrite_ID            0x531da66b034f3069ULL
#define _IOBlockStorageDevice_CopyProducerDataQueue_ID            0x5eb9e790228e9cfaULL
#define _IOBlockStorageDevice_CopyReceiverDataQueue_ID            0x48630eeb0d6b8b14ULL
#define _IOBlockStorageDevice_KernelCompletion_ID            0xade816e976e7c376ULL

#define _IOBlockStorageDevice_DoAsyncReadWriteCompletion_Args \
        OSAction * action, \
        IOReturn status, \
        uint64_t actualByteCount

#define _IOBlockStorageDevice_DoAsyncReadWrite_Args \
        IOMemoryDescriptor * buffer, \
        uint64_t block, \
        uint64_t nblks, \
        OSAction * completion

#define _IOBlockStorageDevice_CopyProducerDataQueue_Args \
        IODataQueueDispatchSource ** dataQueue

#define _IOBlockStorageDevice_CopyReceiverDataQueue_Args \
        IODataQueueDispatchSource ** dataQueue

#define _IOBlockStorageDevice_KernelCompletion_Args \
        OSAction * action, \
        IOReturn status, \
        uint64_t actualByteCount

#define _IOBlockStorageDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(_IOBlockStorageDevice * self, const IORPC rpc);\
\
    void\
    DoAsyncReadWriteCompletion(\
        OSAction * action,\
        IOReturn status,\
        uint64_t actualByteCount,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    DoAsyncReadWrite(\
        IOMemoryDescriptor * buffer,\
        uint64_t block,\
        uint64_t nblks,\
        OSAction * completion,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyProducerDataQueue(\
        IODataQueueDispatchSource ** dataQueue,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyReceiverDataQueue(\
        IODataQueueDispatchSource ** dataQueue,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    KernelCompletion(\
        OSAction * action,\
        IOReturn status,\
        uint64_t actualByteCount,\
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
    DoAsyncReadWriteCompletion_Invoke(const IORPC rpc,\
        void (_IOBlockStorageDevice::*func)(_IOBlockStorageDevice_DoAsyncReadWriteCompletion_Args));\
\
    kern_return_t\
    DoAsyncReadWrite_Invoke(const IORPC rpc,\
        kern_return_t (_IOBlockStorageDevice::*func)(_IOBlockStorageDevice_DoAsyncReadWrite_Args));\
\
    kern_return_t\
    CopyProducerDataQueue_Invoke(const IORPC rpc,\
        kern_return_t (_IOBlockStorageDevice::*func)(_IOBlockStorageDevice_CopyProducerDataQueue_Args));\
\
    kern_return_t\
    CopyReceiverDataQueue_Invoke(const IORPC rpc,\
        kern_return_t (_IOBlockStorageDevice::*func)(_IOBlockStorageDevice_CopyReceiverDataQueue_Args));\
\
    kern_return_t\
    KernelCompletion_Invoke(const IORPC rpc,\
        void (_IOBlockStorageDevice::*func)(_IOBlockStorageDevice_KernelCompletion_Args));\
\


#define _IOBlockStorageDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    void\
    KernelCompletion_Impl(_IOBlockStorageDevice_KernelCompletion_Args);\
\


#define _IOBlockStorageDevice_VirtualMethods \
\
public:\
\


#if !KERNEL

extern OSMetaClass          * g_IOBlockStorageDeviceMetaClass;
extern OSClassLoadInformation _IOBlockStorageDevice_Class;

class _IOBlockStorageDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class _IOBlockStorageDeviceInterface : public OSInterface
{
public:
};

struct _IOBlockStorageDevice_IVars;
struct _IOBlockStorageDevice_LocalIVars;

class _IOBlockStorageDevice : public IOService, public _IOBlockStorageDeviceInterface
{
#if !KERNEL
    friend class _IOBlockStorageDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        _IOBlockStorageDevice_IVars * ivars;
        _IOBlockStorageDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    _IOBlockStorageDevice_Methods
    _IOBlockStorageDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOBlockStorageDevice.iig:44- */
#endif /* ! _IOKIT_UIOBLOCKSTORAGEDEVICE_H */
