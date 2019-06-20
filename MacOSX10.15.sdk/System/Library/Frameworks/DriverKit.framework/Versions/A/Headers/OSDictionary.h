/* iig(DriverKit-54.0.0.111.1) generated from OSDictionary.iig */

/* OSDictionary.iig:1-13 */
#ifndef _IOKIT_OSDICTIONARY_H
#define _IOKIT_OSDICTIONARY_H

#include <DriverKit/OSCollection.h>  /* .iig include */ 

class OSDictionary;
typedef OSDictionary * OSDictionaryPtr;

class OSString;

typedef bool (^OSDictionaryIterateObjectsBlock)(OSObject * key, OSObject * value);
typedef bool (*OSDictionaryIterateObjectsCallback)(void * refcon, OSObject * key, OSObject * value);

/* class OSDictionary OSDictionary.iig:14-91 */


#define OSDictionary_Methods \
\
public:\
\
    static OSDictionaryPtr\
    withCapacity(\
        uint32_t capacity);\
\
    static OSDictionaryPtr\
    withObjects(\
        const OSObject ** values,\
        const OSObject ** keys,\
        uint32_t count,\
        uint32_t capacity);\
\
    static OSDictionaryPtr\
    withDictionary(\
        const OSDictionary * dict,\
        uint32_t capacity);\
\
    bool\
    setObject(\
        const OSObject * aKey,\
        const OSMetaClassBase * anObject);\
\
    bool\
    setObject(\
        const char * aKey,\
        const OSMetaClassBase * anObject);\
\
    void\
    removeObject(\
        const OSObject * aKey);\
\
    void\
    removeObject(\
        const char * aKey);\
\
    bool\
    merge(\
        const OSDictionary * aDictionary);\
\
    OSObject *\
    getObject(\
        const OSObject * aKey) const;\
\
    OSObject *\
    getObject(\
        const char * aKey) const;\
\
    bool\
    isEqualTo(\
        const OSDictionary * aDictionary,\
        const OSCollection * keys) const;\
\
    bool\
    isEqualTo(\
        const OSDictionary * aDictionary) const;\
\
    bool\
    iterateObjects(\
        void * refcon,\
        OSDictionaryIterateObjectsCallback callback) const;\
\
    bool\
    iterateObjects(\
        OSDictionaryIterateObjectsBlock block) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSDictionary_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSDictionary_VirtualMethods \
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

extern OSMetaClass          * gOSDictionaryMetaClass;
extern OSClassLoadInformation OSDictionary_Class;

class OSDictionaryMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSDictionaryInterface : public OSInterface
{
public:
};

struct OSDictionary_IVars;
struct OSDictionary_LocalIVars;

class OSDictionary : public OSCollection, public OSDictionaryInterface
{
#if !KERNEL
    friend class OSDictionaryMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSDictionary_IVars * ivars;
        OSDictionary_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSCollection;

#if !KERNEL
    OSDictionary_Methods
    OSDictionary_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSDictionary.iig:93- */
#endif /* ! _IOKIT_OSDICTIONARY_H */
