/* iig(DriverKit-54.0.0.111.1) generated from IOService.iig */

/* IOService.iig:1-23 */
#if !__IIG
#endif

#ifndef _IOKIT_UIOSERVICE_H
#define _IOKIT_UIOSERVICE_H

#include <DriverKit/OSObject.h>  /* .iig include */ 

class IOMemoryDescriptor;
class IOBufferMemoryDescriptor;

class OSDictionary;
typedef OSDictionary * OSDictionaryPtr;

/*!
@iig implementation
#include <DriverKit/IOBufferMemoryDescriptor.h>
@iig end
*/

/* class IOService IOService.iig:24-69 */

#define IOService__CopyProperties_ID            0xcc1ef14b3f8e4a96ULL
#define IOService__SetProperties_ID            0xcbf7f6d6ac0ac588ULL
#define IOService_GetRegistryEntryID_ID            0x8a6f522f3894a0d7ULL
#define IOService_Start_ID            0xab6f76dde6d693f2ULL
#define IOService_Stop_ID            0x98e715041c459fa5ULL
#define IOService_RegisterService_ID            0xe9722c2bb1347c28ULL
#define IOService_SetProperties_ID            0xd8a753ea156f9162ULL
#define IOService_CopyProperties_ID            0x833ec8f92f8b5362ULL
#define IOService_SetPowerState_ID            0xd200fde7d57ecca6ULL
#define IOService_ChangePowerState_ID            0xdb75cfc3395484a0ULL

#define IOService__CopyProperties_Args \
        IOBufferMemoryDescriptor ** serialization

#define IOService__SetProperties_Args \
        IOMemoryDescriptor * serialization

#define IOService_GetRegistryEntryID_Args \
        uint64_t * registryEntryID

#define IOService_Start_Args \
        IOService * provider

#define IOService_Stop_Args \
        IOService * provider

#define IOService_RegisterService_Args \


#define IOService_SetDispatchQueue_Args \
        const char * name, \
        IODispatchQueue * queue

#define IOService_CopyDispatchQueue_Args \
        const char * name, \
        IODispatchQueue ** queue

#define IOService_SetProperties_Args \
        OSObjectPtr properties

#define IOService_CopyProperties_Args \
        OSDictionaryPtr * properties

#define IOService_SetPowerState_Args \
        uint32_t powerState

#define IOService_ChangePowerState_Args \
        uint32_t powerState

#define IOService_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOService * self, const IORPC rpc);\
\
    kern_return_t\
    _CopyProperties(\
        IOBufferMemoryDescriptor ** serialization,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    _SetProperties(\
        IOMemoryDescriptor * serialization,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetRegistryEntryID(\
        uint64_t * registryEntryID,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Start(\
        IOService * provider,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    Stop(\
        IOService * provider,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    RegisterService(\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetProperties(\
        OSObjectPtr properties,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyProperties(\
        OSDictionaryPtr * properties,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetPowerState(\
        uint32_t powerState,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    ChangePowerState(\
        uint32_t powerState,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    GetRegistryEntryID_Impl(IOService_GetRegistryEntryID_Args);\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
    kern_return_t\
    Stop_Impl(IOService_Stop_Args);\
\
    kern_return_t\
    SetDispatchQueue_Impl(OSObject_SetDispatchQueue_Args);\
\
    kern_return_t\
    SetProperties_Impl(IOService_SetProperties_Args);\
\
    kern_return_t\
    CopyProperties_Impl(IOService_CopyProperties_Args);\
\
    kern_return_t\
    SetPowerState_Impl(IOService_SetPowerState_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    _CopyProperties_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService__CopyProperties_Args));\
\
    kern_return_t\
    _SetProperties_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService__SetProperties_Args));\
\
    kern_return_t\
    GetRegistryEntryID_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_GetRegistryEntryID_Args));\
\
    kern_return_t\
    Start_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_Start_Args));\
\
    kern_return_t\
    Stop_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_Stop_Args));\
\
    kern_return_t\
    RegisterService_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_RegisterService_Args));\
\
    kern_return_t\
    SetProperties_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_SetProperties_Args));\
\
    kern_return_t\
    CopyProperties_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_CopyProperties_Args));\
\
    kern_return_t\
    SetPowerState_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_SetPowerState_Args));\
\
    kern_return_t\
    ChangePowerState_Invoke(const IORPC rpc,\
        kern_return_t (IOService::*func)(IOService_ChangePowerState_Args));\
\


#define IOService_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _CopyProperties_Impl(IOService__CopyProperties_Args);\
\
    kern_return_t\
    _SetProperties_Impl(IOService__SetProperties_Args);\
\
    kern_return_t\
    RegisterService_Impl(IOService_RegisterService_Args);\
\
    kern_return_t\
    CopyDispatchQueue_Impl(OSObject_CopyDispatchQueue_Args);\
\
    kern_return_t\
    ChangePowerState_Impl(IOService_ChangePowerState_Args);\
\


#define IOService_VirtualMethods \
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



extern OSMetaClass          * gIOServiceMetaClass;
extern OSClassLoadInformation IOService_Class;

class IOServiceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};



class IOServiceInterface : public OSInterface
{
public:
};

struct IOService_IVars;
struct IOService_LocalIVars;

class IOService : public OSObject, public IOServiceInterface
{
    friend class IOServiceMetaClass;

public:
    union
    {
        IOService_IVars * ivars;
        IOService_LocalIVars * lvars;
    };

    using super = OSObject;

    IOService_Methods
    IOService_VirtualMethods

};


/* IOService.iig:83- */

#endif /* ! _IOKIT_UIOSERVICE_H */
