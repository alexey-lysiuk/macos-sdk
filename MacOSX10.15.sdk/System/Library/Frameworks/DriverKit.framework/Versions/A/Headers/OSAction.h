/* iig(DriverKit-54.0.0.111.1) generated from OSAction.iig */

/* OSAction.iig:1-7 */
#ifndef _IOKIT_OSACTION_H
#define _IOKIT_OSACTION_H

#include <DriverKit/OSObject.h>  /* .iig include */ 

typedef void (^OSActionCancelHandler)(void);

/* class OSAction OSAction.iig:8-26 */

#define OSAction_Create_ID            0xaa1fc3ce85ce5497ULL

#define OSAction_Create_Args \
        OSObject * target, \
        uint64_t targetmsgid, \
        uint64_t msgid, \
        size_t referenceSize, \
        OSAction ** action

#define OSAction_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(OSAction * self, const IORPC rpc);\
\
    static kern_return_t\
    Create(\
        OSObject * target,\
        uint64_t targetmsgid,\
        uint64_t msgid,\
        size_t referenceSize,\
        OSAction ** action);\
\
    void *\
    GetReference(\
);\
\
    kern_return_t\
    Cancel(\
        OSActionCancelHandler handler);\
\
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Call(OSAction_Create_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(OSAction_Create_Args));\
\


#define OSAction_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Impl(OSAction_Create_Args);\
\


#define OSAction_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\



extern OSMetaClass          * gOSActionMetaClass;
extern OSClassLoadInformation OSAction_Class;

class OSActionMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};


class OSActionInterface : public OSInterface
{
public:
};

struct OSAction_IVars;
struct OSAction_LocalIVars;

class OSAction : public OSObject, public OSActionInterface
{

    friend class OSActionMetaClass;

public:
    union
    {
        OSAction_IVars * ivars;
        OSAction_LocalIVars * lvars;
    };
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(OSAction); };

    using super = OSObject;

    OSAction_Methods

    OSAction_VirtualMethods
};
/* OSAction.iig:28- */
#endif /* ! _IOKIT_OSACTION_H */
