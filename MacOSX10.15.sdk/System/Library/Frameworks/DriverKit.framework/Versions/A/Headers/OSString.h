/* iig(DriverKit-54.0.0.111.1) generated from OSString.iig */

/* OSString.iig:1-11 */
#ifndef _IOKIT_OSSTRING_H
#define _IOKIT_OSSTRING_H

#include <DriverKit/OSContainer.h>  /* .iig include */ 

class OSString;
typedef OSString * OSStringPtr;
typedef OSString OSSymbol;

class OSData;

/* class OSString OSString.iig:12-52 */


#define OSString_Methods \
\
public:\
\
    static OSStringPtr\
    withCString(\
        const char * cString);\
\
    static OSStringPtr\
    withCStringNoCopy(\
        const char * cString);\
\
    static OSStringPtr\
    withCString(\
        const char * cString,\
        size_t length);\
\
    static OSStringPtr\
    withString(\
        const OSString * aString);\
\
    size_t\
    getLength(\
) const;\
\
    const char *\
    getCStringNoCopy(\
) const;\
\
    bool\
    isEqualTo(\
        const OSString * aString) const;\
\
    bool\
    isEqualTo(\
        const char * cString) const;\
\
    bool\
    isEqualTo(\
        const OSData * aDataObject) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\


#define OSString_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSString_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    isEqualTo(\
        const OSMetaClassBase * anObject) const APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSStringMetaClass;
extern OSClassLoadInformation OSString_Class;

class OSStringMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class OSStringInterface : public OSInterface
{
public:
};

struct OSString_IVars;
struct OSString_LocalIVars;

class OSString : public OSContainer, public OSStringInterface
{
#if !KERNEL
    friend class OSStringMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        OSString_IVars * ivars;
        OSString_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSString_Methods
    OSString_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* OSString.iig:54- */
#endif /* ! _IOKIT_OSSTRING_H */
