

#ifndef _IOKIT_UOSMETACLASS_H
#define _IOKIT_UOSMETACLASS_H

#include <stddef.h>
#include <DriverKit/IORPC.h>


struct OSMetaClassBasePrivate;
class IODispatchQueue;
class OSMetaClass;
class OSObject;


struct OSClassLoadInformation
{
    const OSClassDescription * description;
    uint32_t                   instanceSize;
    uint64_t                   resv2[8];

    kern_return_t (*New)(OSMetaClass * instance);
};


class OSMetaClassBase
{
public:
    _Atomic mutable int32_t  refcount;
    int32_t                  reserved;
    OSMetaClass            * meta;

public:
    inline void * operator new(size_t sz, void * placed) { return (placed); }

    static OSMetaClassBase *
    safeMetaCast(const OSMetaClassBase * anObject,
                 const OSMetaClass     * toMeta);

    static OSMetaClassBase *
    requiredMetaCast(const OSMetaClassBase * anObject,
                     const OSMetaClass     * toMeta);

    OSMetaClassBasePrivate *
    Private() const;

    bool
    IsRemote();

    const OSMetaClass *
    GetClass();

    const char *
    GetClassName();

    IODispatchQueue *
    QueueForObject(uint64_t msgid);

	//

	virtual const OSMetaClass *
	getMetaClass() const;

    virtual void
    retain() const;

    virtual void
    release() const;

	virtual bool
    isEqualTo(const OSMetaClassBase * anObject) const;

    virtual kern_return_t
    Dispatch(IORPC invoke);

    kern_return_t
    Invoke(IORPC invoke);
};

struct OSMetaClassPrivate;

class OSMetaClass : public OSMetaClassBase
{
public:
    OSMetaClassPrivate * metaClassPrivate;

    virtual kern_return_t
    New(OSObject * instance) = 0;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class OSInterface
{
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define SUPERDISPATCH ((OSDispatchMethod) &super::_Dispatch)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

extern kern_return_t
OSObjectAllocate(
    OSMetaClass * meta,
    OSObject ** pObject);

#define OSTypeID(type)     g ## type ## MetaClass

#define OSTypeIDInst(inst) (inst)->GetClass()

#define OSMTypeID(type)    OSTypeID(type)

#define OSDynamicCast(type, inst)   \
    (inst ? ((type *) OSMetaClassBase::safeMetaCast((inst), OSTypeID(type))) : NULL)

#define OSRequiredCast(type, inst)   \
    (inst ? ((type *) OSMetaClassBase::requiredMetaCast((inst), OSTypeID(type))) : NULL)

#define OSTypeAlloc(type) \
({ \
    kern_return_t ret; \
    type * inst; \
    ret = OSObjectAllocate(OSTypeID(type), (OSObject **) &inst); \
    if (kIOReturnSuccess != ret) inst = NULL; \
    inst; \
})



#define APPLE_KEXT_OVERRIDE override

#endif  /* _IOKIT_UOSMETACLASS_H */
