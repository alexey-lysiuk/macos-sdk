/* iig(DriverKit-54.0.0.111.1) generated from OSBoolean.iig */

/* OSBoolean.iig:1-11 */
#ifndef _IOKIT_OSBOOLEAN_H
#define _IOKIT_OSBOOLEAN_H

#include <DriverKit/OSCollection.h>  /* .iig include */ 

class OSBoolean;
typedef OSBoolean * OSBooleanPtr;

extern OSBooleanPtr kOSBooleanTrue;
extern OSBooleanPtr kOSBooleanFalse;

/* class OSBoolean OSBoolean.iig:12-26 */


#define OSBoolean_Methods \
\
public:\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSBoolean_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSBoolean_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    retain(\
) const APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    release(\
) const APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSBooleanMetaClass;
extern OSClassLoadInformation OSBoolean_Class;

class OSBooleanMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSBooleanInterface : public OSInterface
{
public:
};

struct OSBoolean_IVars;
struct OSBoolean_LocalIVars;

class OSBoolean : public OSContainer, public OSBooleanInterface
{
#if !KERNEL
    friend class OSBooleanMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSBoolean_IVars * ivars;
        OSBoolean_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSBoolean_Methods
    OSBoolean_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSBoolean.iig:28- */
#endif /* ! _IOKIT_OSBOOLEAN_H */
