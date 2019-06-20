/* iig(DriverKit-54.0.0.111.1) generated from OSArray.iig */

/* OSArray.iig:1-8 */
#ifndef _IOKIT_OSARRAY_H
#define _IOKIT_OSARRAY_H

#include <DriverKit/OSCollection.h>  /* .iig include */ 

class OSArray;
typedef OSArray * OSArrayPtr;

/* class OSArray OSArray.iig:9-82 */


#define OSArray_Methods \
\
public:\
\
    static OSArrayPtr\
    withCapacity(\
        uint32_t capacity);\
\
    static OSArrayPtr\
    withObjects(\
        const OSObject ** values,\
        uint32_t count,\
        uint32_t capacity);\
\
    static OSArrayPtr\
    withArray(\
        const OSArray * array,\
        uint32_t capacity);\
\
    bool\
    setObject(\
        const OSMetaClassBase * anObject);\
\
    bool\
    setObject(\
        uint32_t index,\
        const OSMetaClassBase * anObject);\
\
    bool\
    merge(\
        const OSArray * otherArray);\
\
    void\
    replaceObject(\
        uint32_t index,\
        const OSMetaClassBase * anObject);\
\
    void\
    removeObject(\
        uint32_t index);\
\
    bool\
    isEqualTo(\
        const OSArray * anArray) const;\
\
    OSObject *\
    getObject(\
        uint32_t index) const;\
\
    OSObject *\
    getLastObject(\
) const;\
\
    uint32_t\
    getNextIndexOfObject(\
        const OSMetaClassBase * anObject,\
        uint32_t index) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSArray_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSArray_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual uint32_t\
    getCount(\
) const APPLE_KEXT_OVERRIDE;\
\
    virtual uint32_t\
    getCapacity(\
) const APPLE_KEXT_OVERRIDE;\
\
    virtual uint32_t\
    ensureCapacity(\
        uint32_t newCapacity) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    flushCollection(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    iterateObjects(\
        OSCollectionIterateObjectsBlock block) const APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    isEqualTo(\
        const OSMetaClassBase * anObject) const APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSArrayMetaClass;
extern OSClassLoadInformation OSArray_Class;

class OSArrayMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSArrayInterface : public OSInterface
{
public:
};

struct OSArray_IVars;
struct OSArray_LocalIVars;

class OSArray : public OSCollection, public OSArrayInterface
{
#if !KERNEL
    friend class OSArrayMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSArray_IVars * ivars;
        OSArray_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSCollection;

#if !KERNEL
    OSArray_Methods
    OSArray_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSArray.iig:84- */
#endif /* ! _IOKIT_OSARRAY_H */
