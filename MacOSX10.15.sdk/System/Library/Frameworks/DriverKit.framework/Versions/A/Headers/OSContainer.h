/* iig(DriverKit-54.0.0.111.1) generated from OSContainer.iig */

/* OSContainer.iig:1-9 */
#ifndef _IOKIT_OSCONTAINER_H
#define _IOKIT_OSCONTAINER_H

#include <DriverKit/OSObject.h>  /* .iig include */ 


class OSContainer;
typedef OSContainer * OSContainerPtr;

/* class OSContainer OSContainer.iig:10-11 */


#define OSContainer_Methods \
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


#define OSContainer_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSContainer_VirtualMethods \
\
public:\
\


#if !KERNEL

extern OSMetaClass          * gOSContainerMetaClass;
extern OSClassLoadInformation OSContainer_Class;

class OSContainerMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSContainerInterface : public OSInterface
{
public:
};

struct OSContainer_IVars;
struct OSContainer_LocalIVars;

class OSContainer : public OSObject, public OSContainerInterface
{
#if !KERNEL
    friend class OSContainerMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSContainer_IVars * ivars;
        OSContainer_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSObject;

#if !KERNEL
    OSContainer_Methods
    OSContainer_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSContainer.iig:13- */
#endif /* ! _IOKIT_OSCONTAINER_H */
