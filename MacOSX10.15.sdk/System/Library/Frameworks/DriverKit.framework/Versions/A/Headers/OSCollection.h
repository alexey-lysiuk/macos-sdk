/* iig(DriverKit-54.0.0.111.1) generated from OSCollection.iig */

/* OSCollection.iig:1-15 */
#ifndef _IOKIT_OSCOLLECTION_H
#define _IOKIT_OSCOLLECTION_H

#include <DriverKit/OSObject.h>  /* .iig include */ 
#include <DriverKit/OSContainer.h>  /* .iig include */ 


class OSCollection;
typedef OSCollection * OSCollectionPtr;

class OSDictionary;

typedef bool (^OSCollectionIterateObjectsBlock)(OSObject * object);
typedef bool (*OSCollectionIterateObjectsCallback)(void * refcon, OSObject * object);

/* class OSCollection OSCollection.iig:16-39 */


#define OSCollection_Methods \
\
public:\
\
    bool\
    iterateObjects(\
        void * refcon,\
        OSCollectionIterateObjectsCallback callback) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSCollection_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSCollection_VirtualMethods \
\
public:\
\
    virtual bool\
    iterateObjects(\
        OSCollectionIterateObjectsBlock block) const APPLE_KEXT_OVERRIDE;\
\
    virtual OSCollectionPtr\
    copyCollection(\
        OSDictionary * cycleDict) const APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSCollectionMetaClass;
extern OSClassLoadInformation OSCollection_Class;

class OSCollectionMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSCollectionInterface : public OSInterface
{
public:
    virtual uint32_t
    getCount() const = 0;

    virtual uint32_t
    getCapacity() const = 0;

    virtual uint32_t
    ensureCapacity(uint32_t newCapacity) = 0;

    virtual void
    flushCollection() = 0;

    virtual bool
    iterateObjects(OSCollectionIterateObjectsBlock block) const = 0;

    virtual OSCollectionPtr
    copyCollection(OSDictionary * cycleDict) const = 0;

};

struct OSCollection_IVars;
struct OSCollection_LocalIVars;

class OSCollection : public OSContainer, public OSCollectionInterface
{
#if !KERNEL
    friend class OSCollectionMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSCollection_IVars * ivars;
        OSCollection_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSCollection_Methods
    OSCollection_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSCollection.iig:41- */
#endif /* ! _IOKIT_OSCOLLECTION_H */
