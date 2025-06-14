/* iig(DriverKit-427.120.2) generated from OSArray.iig */

/* OSArray.iig:1-36 */
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

#ifndef _IOKIT_OSARRAY_H
#define _IOKIT_OSARRAY_H

#include <DriverKit/OSCollection.h>  /* .iig include */

class OSArray;
typedef OSArray * OSArrayPtr;

/* source class OSArray OSArray.iig:37-235 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
 * @class OSArray
 *
 * @abstract
 * OSArray provides an indexed store of objects.
 *
 * @discussion
 * OSArray is a collection class for objects derived from OSObject.
 * Storage and access are by array index.
 *
 * You must generally cast retrieved objects from
 * OSObject to the desired class using the OSDynamicCast macro.
 * This macro returns the object cast to the desired class,
 * or <code>NULL</code> if the object isn't derived from that class.
 *
 * As with all DriverKit collection classes,
 * OSArray retains objects added to it,
 * and releases objects removed from it (or replaced).
 * An OSArray also grows as necessary to accommodate new objects.
 *
 * OSArray provides no concurrency protection;
 * it's up to the usage context to provide any protection necessary.
 */

class LOCALONLY OSArray : public OSCollection
{
public:

	// OSObject

	virtual void
	free() override;

	// OSCollection

    /*!
     * @brief       Returns count of members in array.
     * @return      Count of members in array.
     */
	virtual uint32_t
	getCount() const override;

    /*!
     * @brief       Returns count of currently allocated capacity for members in array.
     * @return      Capacity for members in array.
     */
	virtual uint32_t
	getCapacity() const override;

    /*!
     * @brief       Allocates capacity for members in array.
     * @param       newCapacity Count of allocated capacity for members in array.
     * @return      New count of capacity for members in array, may return prior capacity on failure.
     */
	virtual uint32_t
	ensureCapacity(uint32_t newCapacity) override;

    /*!
     * @brief       Removes and drops references to all members of array.
     */
	virtual void
	flushCollection() override;

    /*!
     * @brief       Iterates the array calling a callback block for each member.
     * @discussion  Calls the block with each member of the array, starting at index zero. The block must not modify the array during iteration. If the block returns false the iteration continues for all members, returning true halts the iteration early.
     * @param       block The block to invoke.
     * @return      false if the callback block returned false, otherwise true (including if the array is empty).
     */
	bool
	iterateObjects(OSCollectionIterateObjectsBlock block) const override;

	// OSArray

    /*!
     * @brief       Allocates an OSArray object with preallocated capacity.
     * @param       capacity Count of allocated capacity for members in array.
     * @return      NULL on failure, otherwise the allocated OSArray with reference count 1 to be released by the caller.
     */
	static OSArrayPtr withCapacity(uint32_t capacity);

    /*!
     * @brief       Allocates an OSArray object with given members and preallocated capacity.
     * @param       values C-array pointer to members for the array.
     * @param       count Count of members being added to the array.
     * @param       capacity Count of allocated capacity for members in array.
     * @return      NULL on failure, otherwise the allocated OSArray with reference count 1 to be released by the caller.
     */
	static OSArrayPtr withObjects(
		const OSObject ** values,
		uint32_t     count,
		uint32_t     capacity);

    /*!
     * @brief       Allocates an OSArray object with given members and preallocated capacity.
     * @param       array Array object containing members for the new array.
     * @param       capacity Count of allocated capacity for members in array.
     * @return      NULL on failure, otherwise the allocated OSArray with reference count 1 to be released by the caller.
     */
	static OSArrayPtr withArray(
		const OSArray * array,
		uint32_t    capacity);

    /*!
     * @brief       Appends an object as the last member of the array.
     * @discussion  Appends an object as the last member of the array. The array capacity will be grown if necessary.
     * @param       anObject Object to be added as the last member of the array.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	bool
	setObject(const OSMetaClassBase * anObject);

    /*!
     * @brief       Sets an object as the member of the array at a given index.
     * @discussion  Sets an object as the member of the array at a given index. The array capacity will be grown if necessary.
     * @param       index Zero based index less than or equal to the array count to add the object.
     * @param       anObject Object to be added to the array.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	bool
	setObject(
		uint32_t            index,
		const OSMetaClassBase * anObject);

    /*!
     * @brief       Appends all members of an array to this array.
     * @discussion  Appends all members of an array to this array. The array capacity will be grown if necessary.
     * @param       otherArray All members of thie array will be appended to the array.
     * @return      true on success, which retains all the added objects, or false on failure which does not retain the objects.
     */
	bool
	merge(const OSArray * otherArray);

    /*!
     * @brief       Removes a current member of the array and replaces it with another object.
     * @param       index Zero based index less than the array count to add the object.
     * @param       anObject Object to be added to the array.
     * @return      true on success, which retains the added object and releases the current member, or false on failure which does not retain the object and leaves the current member.
     */
	bool
	replaceObject(
		uint32_t            index,
		const OSMetaClassBase * anObject);

    /*!
     * @brief       Removes a current member of the array.
     * @discussion  Removes a current member of the array, shifting down all following members. The removed object is released.
     * @param       index Zero based index less than the array count of the object to remove.
     */
	void
	removeObject(uint32_t index);

    /*!
     * @brief       Compares all members of two arrays with isEqualTo().
     * @discussion  If the arrays have equal counts, each member is compared with the other at the same index with isEqualTo().
     *              Otherwise false is returned.
     * @param       anArray The other array to compare with.
     * @result      true if both arrays have equal counts and all members compare successfully with isEqualTo.
     */
	bool
	isEqualTo(const OSArray * anArray) const;

    /*!
     * @brief       Compares the array with an OSObject
     * @discussion  If the object is of class OSArray, the result of isEqualTo(const OSArray * anArray) is returned.
     *              Otherwise false is returned.
     * @param       anObject The object to compare with.
     * @result      true iff the object is of class OSArray and isEqualTo(const OSArray * anArray) returns true.
     */
	bool
	isEqualTo(const OSMetaClassBase * anObject) const override;

    /*!
     * @brief       Returns a member of the array.
     * @discussion  If the index is less than the array count the member at that index is returned, with no additional retain count (the caller should not release). Otherwise NULL.
     * @param       index Zero based index less than the array count to add the object.
     * @result      Member at the given index or NULL if the index is greater or equal to the array count. The retain count of the result object is not incremented and the object should not be release by the caller.
     */
	OSObject *
	getObject(uint32_t index) const;

    /*!
     * @brief       Returns the last member of the array.
     * @discussion  If the array has non-zero count the member at the last index is returned, with no additional retain count (the caller should not release). Otherwise NULL.
     * @result      Member at the last index or NULL if array has no members.
     */
	OSObject *
	getLastObject() const;

    /*!
     * @brief       Searches the array for an object.
     * @discussion  Beginning at the passed index, iterate the array until the object instance is found or there are no more members. The search is done by pointer equality.
     * @param       index Zero based index less than the array count to begin the search.
     * @result      Index at which the object was found, or -1U if the member was not found in the array after the index parameter.
     */
	uint32_t
	getNextIndexOfObject(
		const OSMetaClassBase * anObject,
		uint32_t            index) const;
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class OSArray OSArray.iig:37-235 */


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
    bool\
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
public:\
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
extern const OSClassLoadInformation OSArray_Class;

class OSArrayMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class  OSArrayInterface : public OSInterface
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
#ifdef OSArray_DECLARE_IVARS
OSArray_DECLARE_IVARS
#else /* OSArray_DECLARE_IVARS */
    union
    {
        OSArray_IVars * ivars;
        OSArray_LocalIVars * lvars;
    };
#endif /* OSArray_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gOSArrayMetaClass; };
#endif /* KERNEL */

    using super = OSCollection;

#if !KERNEL
    OSArray_Methods
    OSArray_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* OSArray.iig:237- */

#endif /* ! _IOKIT_OSARRAY_H */
