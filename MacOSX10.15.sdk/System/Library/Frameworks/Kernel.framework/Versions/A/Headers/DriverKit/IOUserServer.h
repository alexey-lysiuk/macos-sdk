/* iig(DriverKit-54.0.0.111.1) generated from IOUserServer.iig */

/* IOUserServer.iig:1-14 */
#ifndef _IOKIT_UIOUSERSERVER_H
#define _IOKIT_UIOUSERSERVER_H

#include <DriverKit/OSObject.h>  /* .iig include */ 
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOService.h>  /* .iig include */ 


/*!
@iig implementation
#include <IOKit/IOUserServer.h>
@iig end
*/

/* class IOUserServer IOUserServer.iig:15-32 */

#define IOUserServer_Create_ID            0xc1dbaee5e75e22b9ULL
#define IOUserServer_LoadModule_ID            0xd96f074a91a53982ULL

#define IOUserServer_Create_Args \
        const char * name, \
        uint64_t tag, \
        uint64_t options, \
        IOUserServer ** server

#define IOUserServer_LoadModule_Args \
        const char * path

#define IOUserServer_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserServer * self, const IORPC rpc);\
\
    static kern_return_t\
    Create(\
        const char * name,\
        uint64_t tag,\
        uint64_t options,\
        IOUserServer ** server);\
\
    kern_return_t\
    LoadModule(\
        const char * path,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    LoadModule_Impl(IOUserServer_LoadModule_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IOUserServer_Create_Args));\
\
    kern_return_t\
    LoadModule_Invoke(const IORPC rpc,\
        kern_return_t (IOUserServer::*func)(IOUserServer_LoadModule_Args));\
\


#define IOUserServer_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    static kern_return_t\
    Create_Impl(IOUserServer_Create_Args);\
\


#define IOUserServer_VirtualMethods \
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




/* IOUserServer.iig:34- */
#endif /* ! _IOKIT_UIOUSERSERVER_H */
