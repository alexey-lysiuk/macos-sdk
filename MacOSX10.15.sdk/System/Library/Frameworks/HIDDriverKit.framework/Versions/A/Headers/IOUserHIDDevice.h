/* iig(DriverKit-54.0.0.110.1) generated from IOUserHIDDevice.iig */

/* IOUserHIDDevice.iig:1-9 */
#ifndef _HIDDRIVERKIT_IOUSERHIDDEVICE_H
#define _HIDDRIVERKIT_IOUSERHIDDEVICE_H

#include <DriverKit/IOService.h>  /* .iig include */ 
#include <HIDDriverKit/IOHIDDevice.h>  /* .iig include */ 

class  OSData;
class  OSDictionary;

/* class IOUserHIDDevice IOUserHIDDevice.iig:10-77 */


#define IOUserHIDDevice_Start_Args \
        IOService * provider

#define IOUserHIDDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserHIDDevice * self, const IORPC rpc);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
\
protected:\
    /* _Invoke methods */\
\


#define IOUserHIDDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOUserHIDDevice_VirtualMethods \
\
public:\
\
    virtual bool\
    handleStart(\
        IOService * provider) APPLE_KEXT_OVERRIDE;\
\
    virtual OSDictionary *\
    newDeviceDescription(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual OSData *\
    newReportDescriptor(\
) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserHIDDeviceMetaClass;
extern OSClassLoadInformation IOUserHIDDevice_Class;

class IOUserHIDDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserHIDDeviceInterface : public OSInterface
{
public:
    virtual bool
    handleStart(IOService * provider) = 0;

    virtual OSDictionary *
    newDeviceDescription() = 0;

    virtual OSData *
    newReportDescriptor() = 0;

};

struct IOUserHIDDevice_IVars;
struct IOUserHIDDevice_LocalIVars;

class IOUserHIDDevice : public IOHIDDevice, public IOUserHIDDeviceInterface
{
#if !KERNEL
    friend class IOUserHIDDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserHIDDevice_IVars * ivars;
        IOUserHIDDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOHIDDevice;

#if !KERNEL
    IOUserHIDDevice_Methods
    IOUserHIDDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUserHIDDevice.iig:79- */
#endif /* ! _HIDDRIVERKIT_IOUSERHIDDEVICE_H */
