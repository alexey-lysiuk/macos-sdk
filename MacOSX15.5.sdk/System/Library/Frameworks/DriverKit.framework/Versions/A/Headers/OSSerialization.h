/* iig(DriverKit-427.120.2) generated from OSSerialization.iig */

/* OSSerialization.iig:1-38 */
/*
 * Copyright (c) 2019-2019 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _IOKIT_OSSERIALIZATION_H
#define _IOKIT_OSSERIALIZATION_H

#include <DriverKit/OSContainer.h>  /* .iig include */

class OSSerialization;
typedef OSSerialization * OSSerializationPtr;

typedef void (^OSSerializationFreeBufferHandler)(const void * buffer, size_t length);

/* source class OSSerialization OSSerialization.iig:39-110 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
 * @class OSSerialization
 *
 * @abstract
 * OSSerialization provides methods to serialize an object to binary data.
 *
 * @discussion
 * OSSerialization provides methods to serialize an object to binary data suitable for messaging.
 * Only certain DriverKit classes may be serialized:
 * OSData, OSString, OSNumber, OSBoolean, OSArray, OSDictionary.
 *
 * OSSerialization provides no concurrency protection;
 * it's up to the usage context to provide any protection necessary.
 */

class LOCALONLY OSSerialization : public OSContainer
{
public:

	// OSObject

	virtual void
	free() override;

	// OSSerialization

    /*!
     * @brief       Allocates an OSSerialization object with the serialized data of an object.
     * @discussion  Allocates an OSSerialization object with the serialized data of an object.
     * @param       object Object to serialize. Only certain DriverKit classes may be serialized:
	 *              OSData, OSString, OSNumber, OSBoolean, OSArray, OSDictionary.
     * @return      NULL on failure, otherwise the allocated OSSerialization with reference count 1 to be released by the caller.
     */
	static OSSerializationPtr
	createFromObject(const OSObjectPtr object);

    /*!
     * @brief       Allocates an OSSerialization object from the serialized data of a previous serialization.
     * @discussion  Allocates an OSSerialization object from the serialized data of a previous serialization.
     * @param       bytes The serialized data from a previous call to OSSerialization::finalizeBuffer().
     * @param       length The length of the serialized data from a previous call to OSSerialization::finalizeBuffer().
     * @param       freeBuffer A required block to be called when the OSSerialization is freed and the serialized data will no longer be accessed. Note that unserialized objects may retain the OSSerialization they were created from, so the OSSerialization will retain the data until they have been freed.
     * @return      NULL on failure, otherwise the allocated OSSerialization with reference count 1 to be released by the caller.
     */
	static OSSerializationPtr
	createFromBytes(const void * bytes, size_t length, OSSerializationFreeBufferHandler freeBuffer);

    /*!
     * @brief       Obtain the result of the deserialization performed by createFromBytes().
     * @discussion  Obtain the result of the deserialization performed by createFromBytes().
     * @return      NULL on failure, otherwise the allocated OSObject with reference count 1 to be released by the caller.
     */
	OSObjectPtr
	copyObject();

    /*!
     * @brief       Obtain the result of the serialization performed by createFromObject().
     * @discussion  Obtain the result of the serialization performed by createFromObject().
     * @param       length The length of the serialization data.
     * @return      NULL on failure, otherwise a pointer to the serialization data.
     */
	const void *
	finalizeBuffer(size_t * length);

    /*!
     * @brief       Free a buffer returned by finalizeBuffer().
     * @discussion  Free a buffer returned by finalizeBuffer().
     * @param       buffer Pointer to the serialization data.
     * @param       length The length of the serialization data.
     */
	void
	static freeBuffer(const void * buffer, size_t length);
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class OSSerialization OSSerialization.iig:39-110 */


#define OSSerialization_Methods \
\
public:\
\
    static OSSerializationPtr\
    createFromObject(\
        const OSObjectPtr object);\
\
    static OSSerializationPtr\
    createFromBytes(\
        const void * bytes,\
        size_t length,\
        OSSerializationFreeBufferHandler freeBuffer);\
\
    OSObjectPtr\
    copyObject(\
);\
\
    const void *\
    finalizeBuffer(\
        size_t * length);\
\
    static void\
    freeBuffer(\
        const void * buffer,\
        size_t length);\
\
\
protected:\
    /* _Impl methods */\
\
\
public:\
    /* _Invoke methods */\
\


#define OSSerialization_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSSerialization_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSSerializationMetaClass;
extern const OSClassLoadInformation OSSerialization_Class;

class OSSerializationMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class  OSSerializationInterface : public OSInterface
{
public:
};

struct OSSerialization_IVars;
struct OSSerialization_LocalIVars;

class OSSerialization : public OSContainer, public OSSerializationInterface
{
#if !KERNEL
    friend class OSSerializationMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
#ifdef OSSerialization_DECLARE_IVARS
OSSerialization_DECLARE_IVARS
#else /* OSSerialization_DECLARE_IVARS */
    union
    {
        OSSerialization_IVars * ivars;
        OSSerialization_LocalIVars * lvars;
    };
#endif /* OSSerialization_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gOSSerializationMetaClass; };
#endif /* KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSSerialization_Methods
    OSSerialization_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* OSSerialization.iig:112- */

#endif /* ! _IOKIT_OSSERIALIZATION_H */
