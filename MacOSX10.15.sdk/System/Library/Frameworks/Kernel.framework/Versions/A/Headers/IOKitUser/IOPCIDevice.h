/* iig generated from IOPCIDevice.h */

/* IOPCIDevice.h:1-20 */
#ifndef _IOKIT_UIOPCIDEVICE_H
#define _IOKIT_UIOPCIDEVICE_H

#include <IOKitUser/IOService.h>
#include <IOKitUser/IOMemoryDescriptor.h>

enum {
    kIOPCIMemoryApertureAccessReadDevice   = 0x00000100,
    kIOPCIMemoryApertureAccessWriteDevice  = 0x00000200,
    kIOPCIMemoryApertureAccessApertureMask = 0x000000FF,

    kIOPCIMemoryConfigAccessReadDevice     = 0x00000300,
    kIOPCIMemoryConfigAccessWriteDevice    = 0x00000400,

    kIOPCIMemoryAccess8Bit                 = 0x00080000,
    kIOPCIMemoryAccess16Bit                = 0x00100000,
    kIOPCIMemoryAccess32Bit                = 0x00200000,
    kIOPCIMemoryAccess64Bit                = 0x00400000,
};

/* class IOPCIDevice IOPCIDevice.h:21-36 */

#define IOPCIDevice_MemoryAccess_ID            0x9d3d9c1d611e2483ULL
#define IOPCIDevice_CopyMemoryDescriptor_ID            0xc6f0a79ac2e3c858ULL

#define IOPCIDevice_MemoryAccess_Args \
        uint64_t operation, \
        uint64_t space, \
        uint64_t address, \
        uint64_t data, \
        uint64_t * returnData

#define IOPCIDevice_CopyMemoryDescriptor_Args \
        uint64_t index, \
        IOMemoryDescriptor ** memory

#define IOPCIDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOPCIDevice * self, const IORPC rpc);\
\
    kern_return_t\
    MemoryAccess(\
        uint64_t operation,\
        uint64_t space,\
        uint64_t address,\
        uint64_t data,\
        uint64_t * returnData,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyMemoryDescriptor(\
        uint64_t index,\
        IOMemoryDescriptor ** memory,\
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
    MemoryAccess_Invoke(const IORPC rpc,\
        kern_return_t (IOPCIDevice::*func)(IOPCIDevice_MemoryAccess_Args));\
\
    kern_return_t\
    CopyMemoryDescriptor_Invoke(const IORPC rpc,\
        kern_return_t (IOPCIDevice::*func)(IOPCIDevice_CopyMemoryDescriptor_Args));\
\


#define IOPCIDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    MemoryAccess_Impl(IOPCIDevice_MemoryAccess_Args);\
\
    kern_return_t\
    CopyMemoryDescriptor_Impl(IOPCIDevice_CopyMemoryDescriptor_Args);\
\


#define IOPCIDevice_VirtualMethods \
\
public:\
\


#if !KERNEL

extern OSMetaClass          * gIOPCIDeviceMetaClass;
extern OSClassLoadInformation IOPCIDevice_Class;

class IOPCIDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOPCIDeviceInterface : public OSInterface
{
public:
};

struct IOPCIDevice_IVars;
struct IOPCIDevice_LocalIVars;

class IOPCIDevice : public IOService, public IOPCIDeviceInterface
{
#if !KERNEL
    friend class IOPCIDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOPCIDevice_IVars * ivars;
        IOPCIDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOPCIDevice_Methods
    IOPCIDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOPCIDevice.h:38- */
#endif /* ! _IOKIT_UIOPCIDEVICE_H */
