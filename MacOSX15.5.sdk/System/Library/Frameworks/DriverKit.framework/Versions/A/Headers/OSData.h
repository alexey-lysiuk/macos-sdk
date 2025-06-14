/* iig(DriverKit-427.120.2) generated from OSData.iig */

/* OSData.iig:1-37 */
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

#ifndef _IOKIT_OSDATA_H
#define _IOKIT_OSDATA_H

#include <DriverKit/OSContainer.h>  /* .iig include */

class OSData;
typedef OSData * OSDataPtr;
class OSString;

/* source class OSData OSData.iig:38-211 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
 * @class OSData
 *
 * @abstract
 * OSData provides a container for untyped data.
 *
 * @discussion
 * OSData represents an array of bytes as a container object.
 * OSData objects are mutable:
 * You can add bytes to them and
 * overwrite portions of the byte array.
 *
 * OSData provides no concurrency protection;
 * it's up to the usage context to provide any protection necessary.
 */

class LOCALONLY OSData : public OSContainer
{
public:

	// OSObject

	virtual void
	free() override;

    /*!
     * @brief       Compares the data with an OSObject
     * @discussion  If the object is of class OSData, the result of isEqualTo(const OSData * aDataObj) is returned.
     *              If the object is of class OSString, the result of OSString::isEqualTo(const OSData * aDataObj) is returned.
     *              Otherwise false is returned.
     * @param       anObject The object to compare with.
     * @result      true iff the object is of class OSData or OSString and isEqualTo() returns true.
     */
	virtual
	bool isEqualTo(const OSMetaClassBase * anObject) const override;

	// OSData

    /*!
     * @brief       Allocates an OSData object with preallocated capacity.
     * @discussion  Allocates an OSData object with preallocated capacity. The OSData will have zero length until data is added to it with appendBytes().
     * @param       capacity Number of bytes of data the object can hold.
     * @return      NULL on failure, otherwise the allocated OSData with reference count 1 to be released by the caller.
     */
	static OSDataPtr
	withCapacity(uint32_t capacity);

    /*!
     * @brief       Allocates an OSData object with a copy of bytes.
     * @param       bytes C-pointer to untyped data. The data will be copied at the time of the call.
     * @param       numBytes Count of bytes to be copied.
     * @return      NULL on failure, otherwise the allocated OSData with reference count 1 to be released by the caller.
     */
	static OSDataPtr
	withBytes(
		const void   * bytes,
		size_t         numBytes);

    /*!
     * @brief       Allocates an OSData object with a copy of bytes.
     * @discussion  Allocates an OSData object with a copy of bytes. A synonym for OSData::withBytes() for compatibility with kernel code.
     * @param       bytes C-pointer to untyped data. The data will be copied at the time of the call.
     * @param       numBytes Count of bytes to be copied.
     * @return      NULL on failure, otherwise the allocated OSData with reference count 1 to be released by the caller.
     */
	static OSDataPtr
	withBytesNoCopy(
		void         * bytes,
		size_t         numBytes);

    /*!
     * @brief       Allocates an OSData object with a copy of bytes from another OSData.
     * @param       inData An OSData object to copy. The data will be copied at the time of the call.
     * @return      NULL on failure, otherwise the allocated OSData with reference count 1 to be released by the caller.
     */
	static OSDataPtr
	withData(const OSData * inData);

    /*!
     * @brief       Allocates an OSData object with a copy of bytes from a subset of another OSData.
     * @param       inData An OSData object to copy. The data will be copied at the time of the call.
     * @param       start An offset into the OSData object to copy from.
     * @param       numBytes The length of data to copy. If (start + numBytes) exceeds the length of inData, the call will fail.
     * @return      NULL on failure, otherwise the allocated OSData with reference count 1 to be released by the caller.
     */
	static OSDataPtr
	withData(
		const OSData * inData,
		size_t         start,
		size_t         numBytes);

    /*!
     * @brief       Returns length of data present.
     * @return      length of data present.
     */
	size_t
	getLength() const;

    /*!
     * @brief       Returns length of preallocated capacity.
     * @return      length of preallocated capacity.
     */
	size_t
	getCapacity() const;

    /*!
     * @brief       Appends a buffer of bytes to the OSData object's internal data buffer.
     * @param       bytes C-pointer to untyped data. The data will be copied at the time of the call.
     * @param       numBytes Count of bytes to be copied.
     * @return      true on success or false on failure, due to allocation failure.
     */
	bool
	appendBytes(
		const void   * bytes,
		size_t         numBytes);

    /*!
     * @brief       Appends a buffer of bytes to the OSData object's internal data buffer.
     * @param       aDataObj An OSData object to copy all bytes from.
     * @return      true on success or false on failure, due to allocation failure.
     */
	bool
	appendBytes(const OSData * aDataObj);
	
    /*!
     * @brief       Returns a pointer to the OSData object's internal data buffer.
     * @return      A pointer to the data or NULL if the OSData has zero length.
     */
	const void *
	getBytesNoCopy() const;

    /*!
     * @brief       Returns a pointer to the OSData object's internal data buffer.
     * @param       start An offset into the OSData object.
     * @param       numBytes The length of data intended to be read. If (start + numBytes) exceeds the size of the OSData's length, the call will fail.
     * @return      A pointer to the data or NULL if the OSData does not have data for all the requested range.
     */
	const void *
	getBytesNoCopy(
		size_t start,
		size_t numBytes) const;

    /*!
     * @brief       Compares the data with an OSData
     * @discussion  If the passed OSData object has the same length and all bytes are identical, true is returned.
     *              Otherwise false is returned.
     * @param       aDataObj The OSData to compare with.
     * @result      true iff the object is of class OSArray and isEqualTo(const OSArray * anArray) returns true.
     */
	bool
	isEqualTo(const OSData * aDataObj) const;

    /*!
     * @brief       Compares the data with an OSString
     * @discussion  If the passed OSString object has the same length and all bytes are identical, true is returned.
     *              If the passed OSString object has a length one byte less than the OSData, all bytes are identical, and the last byte of the OSData is zero, true is returned.
     *              Otherwise false is returned.
     * @param       aString The object to compare with.
     * @result      true if the OSData and OSString contain the same c-string.
     */
	bool isEqualTo(const OSString * aString) const;

    /*!
     * @brief       Compares the data with a pointer to bytes
     * @discussion  If the passed data has the same length and all bytes are identical, true is returned.
     *              Otherwise false is returned.
     * @param       bytes C-pointer to untyped data.
     * @param       numBytes Count of bytes to be compared.
     * @result      true iff the length of the data are equal and all bytes are identical.
     */
    bool isEqualTo(
		const void   * bytes,
		size_t         numBytes) const;

};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class OSData OSData.iig:38-211 */


#define OSData_Methods \
\
public:\
\
    static OSDataPtr\
    withCapacity(\
        uint32_t capacity);\
\
    static OSDataPtr\
    withBytes(\
        const void * bytes,\
        size_t numBytes);\
\
    static OSDataPtr\
    withBytesNoCopy(\
        void * bytes,\
        size_t numBytes);\
\
    static OSDataPtr\
    withData(\
        const OSData * inData);\
\
    static OSDataPtr\
    withData(\
        const OSData * inData,\
        size_t start,\
        size_t numBytes);\
\
    size_t\
    getLength(\
) const;\
\
    size_t\
    getCapacity(\
) const;\
\
    bool\
    appendBytes(\
        const void * bytes,\
        size_t numBytes);\
\
    bool\
    appendBytes(\
        const OSData * aDataObj);\
\
    const void *\
    getBytesNoCopy(\
) const;\
\
    const void *\
    getBytesNoCopy(\
        size_t start,\
        size_t numBytes) const;\
\
    bool\
    isEqualTo(\
        const OSData * aDataObj) const;\
\
    bool\
    isEqualTo(\
        const OSString * aString) const;\
\
    bool\
    isEqualTo(\
        const void * bytes,\
        size_t numBytes) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
public:\
    /* _Invoke methods */\
\


#define OSData_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define OSData_VirtualMethods \
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

extern OSMetaClass          * gOSDataMetaClass;
extern const OSClassLoadInformation OSData_Class;

class OSDataMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class  OSDataInterface : public OSInterface
{
public:
};

struct OSData_IVars;
struct OSData_LocalIVars;

class OSData : public OSContainer, public OSDataInterface
{
#if !KERNEL
    friend class OSDataMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
#ifdef OSData_DECLARE_IVARS
OSData_DECLARE_IVARS
#else /* OSData_DECLARE_IVARS */
    union
    {
        OSData_IVars * ivars;
        OSData_LocalIVars * lvars;
    };
#endif /* OSData_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gOSDataMetaClass; };
#endif /* KERNEL */

    using super = OSContainer;

#if !KERNEL
    OSData_Methods
    OSData_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* OSData.iig:213- */

#endif /* ! _IOKIT_OSDATA_H */
