/* iig(DriverKit-54.0.0.111.1) generated from IOMemoryMap.iig */

/* IOMemoryMap.iig:1-17 */
#if !__IIG
#include <IOKit/IOMemoryDescriptor.h>
#endif

#ifndef _IOKIT_UIOMEMORYMAP_H
#define _IOKIT_UIOMEMORYMAP_H

#include <DriverKit/OSObject.h>  /* .iig include */ 

struct IOMemoryMapPrivateState {
	uint64_t length;
	uint64_t options;
	uint64_t address;
};

/* class IOMemoryMap IOMemoryMap.iig:18-32 */

#define IOMemoryMap__CopyState_ID            0xfc92b3d7f2d48ec7ULL

#define IOMemoryMap__CopyState_Args \
        IOMemoryMapPrivateState * state

#define IOMemoryMap_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOMemoryMap * self, const IORPC rpc);\
\
    kern_return_t\
    _CopyState(\
        IOMemoryMapPrivateState * state,\
        OSDispatchMethod supermethod = NULL);\
\
    uint64_t\
    GetAddress(\
);\
\
    uint64_t\
    GetLength(\
);\
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
        kern_return_t (IOMemoryMap::*func)(IOMemoryMap__CopyState_Args));\
\


#define IOMemoryMap_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _CopyState_Impl(IOMemoryMap__CopyState_Args);\
\


#define IOMemoryMap_VirtualMethods \
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





/* IOMemoryMap.iig:41- */
#endif /* ! _IOKIT_UIOMEMORYMAP_H */
