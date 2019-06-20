/* iig(DriverKit-54.0.0.111.1) generated from OSData.iig */

/* OSData.iig:1-9 */
#ifndef _IOKIT_OSDATA_H
#define _IOKIT_OSDATA_H

#include <DriverKit/OSContainer.h>  /* .iig include */ 

class OSData;
typedef OSData * OSDataPtr;
class OSString;

/* class OSData OSData.iig:10-76 */


#define OSData_Methods \
\
public:\
\
    static OSDataPtr\
    withCapacity(\
        uint32_t capacity);\
\
    static OSDataPtr\
    withBytes(\
        const void * bytes,\
        size_t numBytes);\
\
    static OSDataPtr\
    withBytesNoCopy(\
        void * bytes,\
        size_t numBytes);\
\
    static OSDataPtr\
    withData(\
        const OSData * inData);\
\
    static OSDataPtr\
    withData(\
        const OSData * inData,\
        size_t start,\
        size_t numBytes);\
\
    size_t\
    getLength(\
) const;\
\
    size_t\
    getCapacity(\
) const;\
\
    bool\
    appendBytes(\
        const void * bytes,\
        size_t numBytes);\
\
    bool\
    appendBytes(\
        const OSData * aDataObj);\
\
    const void *\
    getBytesNoCopy(\
) const;\
\
    const void *\
    getBytesNoCopy(\
        size_t start,\
        size_t numBytes) const;\
\
    bool\
    isEqualTo(\
        const OSData * aDataObj) const;\
\
    bool\
    isEqualTo(\
        const OSString * aString) const;\
\
    bool\
    isEqualTo(\
        const void * bytes,\
        size_t numBytes) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSData_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSData_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    isEqualTo(\
        const OSMetaClassBase * anObject) const APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSDataMetaClass;
extern OSClassLoadInformation OSData_Class;

class OSDataMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSDataInterface : public OSInterface
{
public:
};

struct OSData_IVars;
struct OSData_LocalIVars;

class OSData : public OSContainer, public OSDataInterface
{
#if !KERNEL
    friend class OSDataMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSData_IVars * ivars;
        OSData_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSData_Methods
    OSData_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSData.iig:78- */
#endif /* ! _IOKIT_OSDATA_H */
