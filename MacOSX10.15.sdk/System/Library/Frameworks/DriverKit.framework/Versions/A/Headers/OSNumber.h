/* iig(DriverKit-54.0.0.111.1) generated from OSNumber.iig */

/* OSNumber.iig:1-9 */
#ifndef _IOKIT_OSNUMBER_H
#define _IOKIT_OSNUMBER_H

#include <DriverKit/OSContainer.h>  /* .iig include */ 

class OSNumber;
typedef OSNumber * OSNumberPtr;


/* class OSNumber OSNumber.iig:10-50 */


#define OSNumber_Methods \
\
public:\
\
    static OSNumberPtr\
    withNumber(\
        uint64_t value,\
        size_t numberOfBits);\
\
    static OSNumberPtr\
    withNumber(\
        const char * valueString,\
        size_t numberOfBits);\
\
    size_t\
    numberOfBits(\
) const;\
\
    uint8_t\
    unsigned8BitValue(\
) const;\
\
    uint16_t\
    unsigned16BitValue(\
) const;\
\
    uint32_t\
    unsigned32BitValue(\
) const;\
\
    uint64_t\
    unsigned64BitValue(\
) const;\
\
    bool\
    isEqualTo(\
        const OSNumber * aNumber) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSNumber_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSNumber_VirtualMethods \
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

extern OSMetaClass          * gOSNumberMetaClass;
extern OSClassLoadInformation OSNumber_Class;

class OSNumberMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSNumberInterface : public OSInterface
{
public:
};

struct OSNumber_IVars;
struct OSNumber_LocalIVars;

class OSNumber : public OSContainer, public OSNumberInterface
{
#if !KERNEL
    friend class OSNumberMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSNumber_IVars * ivars;
        OSNumber_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSNumber_Methods
    OSNumber_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSNumber.iig:52- */
#endif /* ! _IOKIT_OSNUMBER_H */
