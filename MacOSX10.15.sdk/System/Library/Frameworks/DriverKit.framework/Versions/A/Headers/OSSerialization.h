/* iig(DriverKit-54.0.0.111.1) generated from OSSerialization.iig */

/* OSSerialization.iig:1-10 */
#ifndef _IOKIT_OSSERIALIZATION_H
#define _IOKIT_OSSERIALIZATION_H

#include <DriverKit/OSContainer.h>  /* .iig include */ 

class OSSerialization;
typedef OSSerialization * OSSerializationPtr;

typedef void (^OSSerializationFreeBufferHandler)(const void * buffer, size_t length);

/* class OSSerialization OSSerialization.iig:11-35 */


#define OSSerialization_Methods \
\
public:\
\
    static OSSerializationPtr\
    createFromObject(\
        const OSObjectPtr object);\
\
    static OSSerializationPtr\
    createFromBytes(\
        const void * bytes,\
        size_t length,\
        OSSerializationFreeBufferHandler freeBuffer);\
\
    OSObjectPtr\
    copyObject(\
);\
\
    size_t\
    getLength(\
);\
\
    const void *\
    getBytesPtr(\
        size_t * length);\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSSerialization_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSSerialization_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSSerializationMetaClass;
extern OSClassLoadInformation OSSerialization_Class;

class OSSerializationMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSSerializationInterface : public OSInterface
{
public:
};

struct OSSerialization_IVars;
struct OSSerialization_LocalIVars;

class OSSerialization : public OSContainer, public OSSerializationInterface
{
#if !KERNEL
    friend class OSSerializationMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSSerialization_IVars * ivars;
        OSSerialization_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSSerialization_Methods
    OSSerialization_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSSerialization.iig:37- */
#endif /* ! _IOKIT_OSSERIALIZATION_H */
