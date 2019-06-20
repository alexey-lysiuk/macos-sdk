/* iig(DriverKit-54.0.0.111.1) generated from OSObject.iig */

/* OSObject.iig:1-61 */
#if !__IIG
#endif

#ifndef _IOKIT_UOSOBJECT_H
#define _IOKIT_UOSOBJECT_H

#include <stddef.h>
#include <stdint.h>
#include <DriverKit/IOReturn.h>
#if DRIVERKIT_PRIVATE
#include <mach/port.h>
#endif
#if !__IIG
#include <string.h>
#include <DriverKit/OSMetaClass.h>
#endif
class OSObject;
typedef OSObject * OSObjectPtr;

#if __IIG && !__IIG_ATTRIBUTES_DEFINED__

#define __IIG_ATTRIBUTES_DEFINED__	1

#define KERNEL       __attribute__((annotate("kernel")))
#define NATIVE       __attribute__((annotate("native")))
#define LOCAL        __attribute__((annotate("local")))
#define LOCALONLY    __attribute__((annotate("localonly")))
#define REMOTE       __attribute__((annotate("remote")))

#define LOCALHOST    __attribute__((annotate("localhost")))

#define INVOKEREPLY  __attribute__((annotate("invokereply")))
#define REPLY        __attribute__((annotate("reply")))

#define PORTMAKESEND __attribute__((annotate("MACH_MSG_TYPE_MAKE_SEND")))
#define PORTCOPYSEND __attribute__((annotate("MACH_MSG_TYPE_COPY_SEND")))

#define TARGET       __attribute__((annotate("target")))
#define TYPE(p)      __attribute__((annotate("type=" # p)))

//#define ARRAY(maxcount) __attribute__((annotate(# maxcount), annotate("array")))
#define EXTENDS(cls) __attribute__((annotate("extends=" # cls)))

//#define INTERFACE    __attribute__((annotate("interface")))
//#define IMPLEMENTS(i)   void implements(i *);

#define QUEUENAME(name) __attribute__((annotate("queuename=" # name)))

#endif /* __IIG */

class OSMetaClass;
class IODispatchQueue;
typedef char IODispatchQueueName[256];


#if __IIG
/* OSObject.iig:76-84 */
#endif /* __IIG */


/*!
@iig implementation
#include <DriverKit/IODispatchQueue.h>
@iig end
*/

/* class OSObject OSObject.iig:85-109 */

#define OSObject_SetDispatchQueue_ID            0xe608ae8273dae1bcULL
#define OSObject_CopyDispatchQueue_ID            0x95115b48fd29f7c9ULL

#define OSObject_SetDispatchQueue_Args \
        const char * name, \
        IODispatchQueue * queue

#define OSObject_CopyDispatchQueue_Args \
        const char * name, \
        IODispatchQueue ** queue

#define OSObject_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(OSObject * self, const IORPC rpc);\
\
    kern_return_t\
    SetDispatchQueue(\
        const IODispatchQueueName name,\
        IODispatchQueue * queue,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CopyDispatchQueue(\
        const IODispatchQueueName name,\
        IODispatchQueue ** queue,\
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
    SetDispatchQueue_Invoke(const IORPC rpc,\
        kern_return_t (OSObject::*func)(OSObject_SetDispatchQueue_Args));\
\
    kern_return_t\
    CopyDispatchQueue_Invoke(const IORPC rpc,\
        kern_return_t (OSObject::*func)(OSObject_CopyDispatchQueue_Args));\
\


#define OSObject_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSObject_VirtualMethods \
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
    virtual void\
    retain(\
) const APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    release(\
) const APPLE_KEXT_OVERRIDE;\
\



extern OSMetaClass          * gOSObjectMetaClass;
extern OSClassLoadInformation OSObject_Class;

class OSObjectMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};



class OSObjectInterface : public OSInterface
{
public:
    virtual bool
    init() = 0;

    virtual void
    free() = 0;

};

struct OSObject_IVars;
struct OSObject_LocalIVars;

class OSObject : public OSMetaClassBase, public OSObjectInterface
{
    friend class OSObjectMetaClass;

public:
    union
    {
        OSObject_IVars * ivars;
        OSObject_LocalIVars * lvars;
    };

    using super = OSMetaClassBase;

    OSObject_Methods
    OSObject_VirtualMethods

};

/* OSObject.iig:111- */
#define DEFN(classname, name)                                       \
name ## _Impl(classname ## _ ## name ## _Args)

#define IMPL(classname, name)                                       \
classname :: DEFN(classname, name)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#endif /* ! _IOKIT_UOSOBJECT_H */
