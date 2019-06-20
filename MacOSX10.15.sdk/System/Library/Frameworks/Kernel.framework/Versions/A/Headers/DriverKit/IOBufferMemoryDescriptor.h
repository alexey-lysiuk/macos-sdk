/* iig(DriverKit-54.0.0.111.1) generated from IOBufferMemoryDescriptor.iig */

/* IOBufferMemoryDescriptor.iig:1-17 */
#if !__IIG
#include <IOKit/IOBufferMemoryDescriptor.h>
#endif


#ifndef _IOKIT_UIOBUFFERMEMORYDESCRIPTOR_H
#define _IOKIT_UIOBUFFERMEMORYDESCRIPTOR_H

#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 

struct IOBMDPrivateState {
	IOMDPrivateState mdstate;
	uint64_t         address;
};

/* class IOBufferMemoryDescriptor IOBufferMemoryDescriptor.iig:18-39 */

#define IOBufferMemoryDescriptor__CopyState_ID            0xd41ab86053a70affULL
#define IOBufferMemoryDescriptor_Create_ID            0xb78de684e17d5a4bULL
#define IOBufferMemoryDescriptor_SetLength_ID            0xc115230c191a6a9aULL

#define IOBufferMemoryDescriptor__CopyState_Args \
        IOBMDPrivateState * state

#define IOBufferMemoryDescriptor_Create_Args \
        uint64_t options, \
        uint64_t length, \
        uint64_t alignment, \
        IOBufferMemoryDescriptor ** memory

#define IOBufferMemoryDescriptor_SetLength_Args \
        uint64_t length

#define IOBufferMemoryDescriptor_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOBufferMemoryDescriptor * self, const IORPC rpc);\
\
    kern_return_t\
    _CopyState(\
        IOBMDPrivateState * state,\
        OSDispatchMethod supermethod = NULL);\
\
    static kern_return_t\
    Create(\
        uint64_t options,\
        uint64_t length,\
        uint64_t alignment,\
        IOBufferMemoryDescriptor ** memory);\
\
    kern_return_t\
    GetAddressRange(\
        IOAddressSegment * range);\
\
    kern_return_t\
    SetLength(\
        uint64_t length,\
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
    _CopyState_Invoke(const IORPC rpc,\
        kern_return_t (IOBufferMemoryDescriptor::*func)(IOBufferMemoryDescriptor__CopyState_Args));\
\
    static kern_return_t\
    Create_Invoke(const IORPC rpc,\
        kern_return_t (*func)(IOBufferMemoryDescriptor_Create_Args));\
\
    kern_return_t\
    SetLength_Invoke(const IORPC rpc,\
        kern_return_t (IOBufferMemoryDescriptor::*func)(IOBufferMemoryDescriptor_SetLength_Args));\
\


#define IOBufferMemoryDescriptor_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _CopyState_Impl(IOBufferMemoryDescriptor__CopyState_Args);\
\
    static kern_return_t\
    Create_Impl(IOBufferMemoryDescriptor_Create_Args);\
\
    kern_return_t\
    SetLength_Impl(IOBufferMemoryDescriptor_SetLength_Args);\
\


#define IOBufferMemoryDescriptor_VirtualMethods \
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





/* IOBufferMemoryDescriptor.iig:48- */

#endif /* ! _IOKIT_UIOBUFFERMEMORYDESCRIPTOR_H */
