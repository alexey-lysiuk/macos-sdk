/* iig(DriverKit-54.0.0.111.1) generated from IOMemoryDescriptor.iig */

/* IOMemoryDescriptor.iig:1-38 */
#if !__IIG
#endif

#ifndef _IOKIT_UIOMEMORYDESCRIPTOR_H
#define _IOKIT_UIOMEMORYDESCRIPTOR_H

#include <DriverKit/OSObject.h>  /* .iig include */ 

class IOService;
class IOMemoryMap;


enum{
	kIOMemoryDirectionIn    = 0x00000001,
	kIOMemoryDirectionOut   = 0x00000002,
	kIOMemoryDirectionOutIn = kIOMemoryDirectionIn | kIOMemoryDirectionOut,
	kIOMemoryDirectionInOut = kIOMemoryDirectionOutIn,
};

struct IOAddressSegment {
	uint64_t address;
	uint64_t length;
};

struct IOMDPrivateState {
	uint64_t length;
	uint64_t options;
};

/*!
@iig implementation
#include <DriverKit/IOService.h>
@iig end
*/

/* class IOMemoryDescriptor IOMemoryDescriptor.iig:39-88 */

#define IOMemoryDescriptor__CopyState_ID            0xa2c0861d4118ce5eULL
#define IOMemoryDescriptor_Create_ID            0xf6b547659b5665d4ULL
#define IOMemoryDescriptor_CreateMapping_ID            0xc5e69b0414ff6ee5ULL
#define IOMemoryDescriptor_PrepareForDMA_ID            0xfd78519a57b70575ULL

#define IOMemoryDescriptor__CopyState_Args \
        IOMDPrivateState * state

#define IOMemoryDescriptor_Create_Args \
        uint64_t options, \
        uint32_t segmentsCount, \
        const IOAddressSegment * segments, \
        IOMemoryDescriptor ** memory

#define IOMemoryDescriptor_CreateMapping_Args \
        uint64_t options, \
        uint64_t address, \
        uint64_t length, \
        uint64_t alignment, \
        IOMemoryMap ** map

#define IOMemoryDescriptor_PrepareForDMA_Args \
        uint64_t options, \
        IOService * device, \
        uint64_t offset, \
        uint64_t length, \
        uint64_t * flags, \
        uint64_t * returnLength, \
        uint32_t * segmentsCount, \
        IOAddressSegment * segments

#define IOMemoryDescriptor_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOMemoryDescriptor * self, const IORPC rpc);\
\
    kern_return_t\
    _CopyState(\
        IOMDPrivateState * state,\
        OSDispatchMethod supermethod = NULL);\
\
    static kern_return_t\
    Create(\
        uint64_t options,\
        uint32_t segmentsCount,\
        const IOAddressSegment * segments,\
        IOMemoryDescriptor ** memory);\
\
    kern_return_t\
    GetLength(\
        uint64_t * returnLength);\
\
    kern_return_t\
    Map(\
        uint64_t options,\
        uint64_t address,\
        uint64_t length,\
        uint64_t alignment,\
        uint64_t * returnAddress,\
        uint64_t * returnLength);\
\
    kern_return_t\
    CreateMapping(\
        uint64_t options,\
        uint64_t address,\
        uint64_t length,\
        uint64_t alignment,\
        IOMemoryMap ** map,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    PrepareForDMA(\
        uint64_t options,\
        IOService * device,\
        uint64_t offset,\
        uint64_t length,\
        uint64_t * flags,\
        uint64_t * returnLength,\
        uint32_t * segmentsCount,\
        IOAddressSegment * segments,\
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
    _CopyState_Invoke(const IORPC rpc,\
        kern_return_t (IOMemoryDescriptor::*func)(IOMemoryDescriptor__CopyState_Args));\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IOMemoryDescriptor_Create_Args));\
\
    kern_return_t\
    CreateMapping_Invoke(const IORPC rpc,\
        kern_return_t (IOMemoryDescriptor::*func)(IOMemoryDescriptor_CreateMapping_Args));\
\
    kern_return_t\
    PrepareForDMA_Invoke(const IORPC rpc,\
        kern_return_t (IOMemoryDescriptor::*func)(IOMemoryDescriptor_PrepareForDMA_Args));\
\


#define IOMemoryDescriptor_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _CopyState_Impl(IOMemoryDescriptor__CopyState_Args);\
\
    static kern_return_t\
    Create_Impl(IOMemoryDescriptor_Create_Args);\
\
    kern_return_t\
    CreateMapping_Impl(IOMemoryDescriptor_CreateMapping_Args);\
\
    kern_return_t\
    PrepareForDMA_Impl(IOMemoryDescriptor_PrepareForDMA_Args);\
\


#define IOMemoryDescriptor_VirtualMethods \
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



extern OSMetaClass          * gIOMemoryDescriptorMetaClass;
extern OSClassLoadInformation IOMemoryDescriptor_Class;

class IOMemoryDescriptorMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};



class IOMemoryDescriptorInterface : public OSInterface
{
public:
};

struct IOMemoryDescriptor_IVars;
struct IOMemoryDescriptor_LocalIVars;

class IOMemoryDescriptor : public OSObject, public IOMemoryDescriptorInterface
{
    friend class IOMemoryDescriptorMetaClass;

public:
    union
    {
        IOMemoryDescriptor_IVars * ivars;
        IOMemoryDescriptor_LocalIVars * lvars;
    };

    using super = OSObject;

    IOMemoryDescriptor_Methods
    IOMemoryDescriptor_VirtualMethods

};


/* IOMemoryDescriptor.iig:97- */


#endif /* ! _IOKIT_UIOMEMORYDESCRIPTOR_H */
