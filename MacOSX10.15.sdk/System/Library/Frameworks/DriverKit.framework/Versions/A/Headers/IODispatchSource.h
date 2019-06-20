/* iig(DriverKit-54.0.0.111.1) generated from IODispatchSource.iig */

/* IODispatchSource.iig:1-8 */
#ifndef _IOKIT_UIODISPATCHSOURCE_H
#define _IOKIT_UIODISPATCHSOURCE_H

#include <DriverKit/OSObject.h>  /* .iig include */ 


typedef void (^IODispatchSourceCancelHandler)(void);

/* class IODispatchSource IODispatchSource.iig:9-26 */

#define IODispatchSource_Cancel_ID            0xd963bb196f70bb93ULL
#define IODispatchSource_SetEnable_ID            0xbbc036b4c2a26c45ULL
#define IODispatchSource_CheckForWork_ID            0xef19d38d4f945fd0ULL

#define IODispatchSource_Cancel_Args \
        IODispatchSourceCancelHandler handler

#define IODispatchSource_SetEnable_Args \
        bool enable

#define IODispatchSource_CheckForWork_Args \
        const IORPC rpc, \
        bool synchronous

#define IODispatchSource_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IODispatchSource * self, const IORPC rpc);\
\
    kern_return_t\
    Cancel(\
        IODispatchSourceCancelHandler handler,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetEnable(\
        bool enable,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CheckForWork(\
        bool synchronous,\
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
    Cancel_Invoke(const IORPC rpc,\
        kern_return_t (IODispatchSource::*func)(IODispatchSource_Cancel_Args));\
\
    kern_return_t\
    SetEnable_Invoke(const IORPC rpc,\
        kern_return_t (IODispatchSource::*func)(IODispatchSource_SetEnable_Args));\
\
    kern_return_t\
    CheckForWork_Invoke(const IORPC rpc,\
        kern_return_t (IODispatchSource::*func)(IODispatchSource_CheckForWork_Args));\
\


#define IODispatchSource_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IODispatchSource_VirtualMethods \
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



extern OSMetaClass          * gIODispatchSourceMetaClass;
extern OSClassLoadInformation IODispatchSource_Class;

class IODispatchSourceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};


class IODispatchSourceInterface : public OSInterface
{
public:
};

struct IODispatchSource_IVars;
struct IODispatchSource_LocalIVars;

class IODispatchSource : public OSObject, public IODispatchSourceInterface
{

    friend class IODispatchSourceMetaClass;

public:
    union
    {
        IODispatchSource_IVars * ivars;
        IODispatchSource_LocalIVars * lvars;
    };
    virtual const OSMetaClass *
    getMetaClass() const APPLE_KEXT_OVERRIDE { return OSTypeID(IODispatchSource); };

    using super = OSObject;

    IODispatchSource_Methods

    IODispatchSource_VirtualMethods
};
/* IODispatchSource.iig:28- */
#endif /* ! _IOKIT_UIODISPATCHSOURCE_H */
