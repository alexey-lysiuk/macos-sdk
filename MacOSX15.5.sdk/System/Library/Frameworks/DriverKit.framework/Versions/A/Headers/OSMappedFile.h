/* iig(DriverKit-427.120.2) generated from OSMappedFile.iig */

/* OSMappedFile.iig:1-33 */
/*
 * Copyright (c) 2020-2020 Apple Inc. All rights reserved.
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

#ifndef _IOKIT_OSMAPPEDFILE_H
#define _IOKIT_OSMAPPEDFILE_H

#include <DriverKit/OSObject.h>  /* .iig include */

/* source class OSMappedFile OSMappedFile.iig:34-75 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
 * @class OSMappedFile
 *
 * @abstract
 * OSMappedFile represents a file mapped read-only into the driver's address space. When a OSMappedFile object is freed, it unmaps
 * the file automatically.
 */
class LOCALONLY OSMappedFile : public OSObject
{
public:

	/*!
	 * @brief  Open the specified file.
	 * @param path         Path to the file.
	 * @param options      Options to use when opening the file. This field is currently ignored and should be set to 0.
	 * @param minGuardSize The size of the guard page region surrounding this file's mapping.
	 *                     This is rounded up to the nearest page size multiple.
	 * @param outputMap    Allocated OSMappedFile object with reference count 1 to be released by the caller.
	 * @return kIOReturnSuccess on success. See IOReturn.h for error codes.
	 */
	static kern_return_t
	createFromPath(const char * path, uint64_t options, size_t minGuardSize, OSMappedFile **outputMappedFile);

	virtual void
	free() override;

	virtual bool
	init() override;

	/*!
	 * @brief    Get the data from the file.
	 * @return   Pointer to file data.
	 */
	const void *
	data() const;

	/*!
	 * @brief    Get the size of the file.
	 * @return   Size of the file.
	 */
	size_t
	size() const;
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class OSMappedFile OSMappedFile.iig:34-75 */


#define OSMappedFile_Methods \
\
public:\
\
    static kern_return_t\
    createFromPath(\
        const char * path,\
        uint64_t options,\
        size_t minGuardSize,\
        OSMappedFile ** outputMappedFile);\
\
    const void *\
    data(\
) const;\
\
    size_t\
    size(\
) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
public:\
    /* _Invoke methods */\
\


#define OSMappedFile_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSMappedFile_VirtualMethods \
\
public:\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    init(\
) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gOSMappedFileMetaClass;
extern const OSClassLoadInformation OSMappedFile_Class;

class OSMappedFileMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class  OSMappedFileInterface : public OSInterface
{
public:
};

struct OSMappedFile_IVars;
struct OSMappedFile_LocalIVars;

class OSMappedFile : public OSObject, public OSMappedFileInterface
{
#if !KERNEL
    friend class OSMappedFileMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
#ifdef OSMappedFile_DECLARE_IVARS
OSMappedFile_DECLARE_IVARS
#else /* OSMappedFile_DECLARE_IVARS */
    union
    {
        OSMappedFile_IVars * ivars;
        OSMappedFile_LocalIVars * lvars;
    };
#endif /* OSMappedFile_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gOSMappedFileMetaClass; };
#endif /* KERNEL */

    using super = OSObject;

#if !KERNEL
    OSMappedFile_Methods
    OSMappedFile_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* OSMappedFile.iig:77- */

#endif /* ! _IOKIT_OSMAPPEDFILE_H */
