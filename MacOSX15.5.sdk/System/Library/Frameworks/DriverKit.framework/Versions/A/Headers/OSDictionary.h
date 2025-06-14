/* iig(DriverKit-427.120.2) generated from OSDictionary.iig */

/* OSDictionary.iig:1-42 */
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

#ifndef _IOKIT_OSDICTIONARY_H
#define _IOKIT_OSDICTIONARY_H

#include <DriverKit/OSCollection.h>  /* .iig include */

class OSDictionary;
typedef OSDictionary * OSDictionaryPtr;

class OSString;

typedef bool (^OSDictionaryIterateObjectsBlock)(OSObject * key, OSObject * value);
typedef bool (*OSDictionaryIterateObjectsCallback)(void * refcon, OSObject * key, OSObject * value);


/* source class OSDictionary OSDictionary.iig:43-264 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
 * @class OSDictionary
 *
 * @abstract
 * OSDictionary provides an associative store using strings for keys.
 *
 * @discussion
 * OSDictionary is a collection class for objects derived from OSObject.
 * Storage and access are associative, based on keys that are uniqued OSObjects.
 * OSString is commonly used as a key since it is uniqued.
 * When adding an object to an OSDictionary, you provide a string identifier,
 * which can then used to retrieve that object or remove it from the dictionary.
 * Setting an object with a key that already has an associated object
 * replaces the original object.
 *
 * You must generally cast retrieved objects from
 * OSObject to the desired class using the OSDynamicCast macro.
 * This macro returns the object cast to the desired class,
 * or <code>NULL</code> if the object isn't derived from that class.
 *
 * As with all DriverKit collection classes,
 * OSDictionary retains objects added to it,
 * and releases objects removed from it (or replaced).
 * An OSDictionary also grows as necessary to accommodate new objects.
 *
 * OSArray provides no concurrency protection;
 * it's up to the usage context to provide any protection necessary.
 */

class LOCALONLY OSDictionary : public OSCollection
{
public:

	// OSObject

	virtual void
	free() override;

	// OSCollection

    /*!
     * @brief       Returns count of members in dictionary.
     * @return      Count of members in dictionary.
     */
	virtual uint32_t
	getCount() const override;

    /*!
     * @brief       Returns count of currently allocated capacity for members in dictionary.
     * @return      Capacity for members in dictionary.
     */
	virtual uint32_t
	getCapacity() const override;

    /*!
     * @brief       Allocates capacity for members in dictionary.
     * @param       newCapacity Count of allocated capacity for members in dictionary.
     * @return      New count of capacity for members in dictionary, may return prior capacity on failure.
     */
	virtual uint32_t
	ensureCapacity(uint32_t newCapacity) override;

    /*!
     * @brief       Removes and drops references to all members of dictionary.
     */
	virtual void
	flushCollection() override;

    /*!
     * @brief       Iterates the dictionary calling a callback block for each member.
     * @discussion  Calls the block with each member of the dictionary. The block must not modify the dictionary during iteration. If the block returns false the iteration continues for all members, returning true halts the iteration early. OSDictionary also has a dictionary specific iterateObjects() which supplies the key and value to the callback.
     * @param       block The block to invoke.
     * @return      false if the callback block returned false, otherwise true (including if the array is empty).
     */
	bool
	iterateObjects(OSCollectionIterateObjectsBlock block) const override;

	// OSDictionary

    /*!
     * @brief       Allocates an OSDictionary object with preallocated capacity.
     * @param       capacity Count of allocated capacity for members in dictionary.
     * @return      NULL on failure, otherwise the allocated OSDictionary with reference count 1 to be released by the caller.
     */
	static OSDictionaryPtr
	withCapacity(uint32_t capacity);

    /*!
     * @brief       Allocates an OSDictionary object with given members and preallocated capacity.
     * @param       values C-array pointer to values for the dictionary.
     * @param       keys C-array pointer to keys for the dictionary.
     * @param       count Count of members being added to the dictionary.
     * @param       capacity Count of allocated capacity for members in dictionary.
     * @return      NULL on failure, otherwise the allocated OSDictionary with reference count 1 to be released by the caller.
     */
	static OSDictionaryPtr
	withObjects(
		const OSObject ** values,
		const OSObject ** keys,
		uint32_t     count,
		uint32_t     capacity);

    /*!
     * @brief       Allocates an OSictionary object with given members and preallocated capacity.
     * @param       dictionary Dictionary object containing members for the new dictionary.
     * @param       capacity Count of allocated capacity for members in array.
     * @return      NULL on failure, otherwise the allocated OSDictionary with reference count 1 to be released by the caller.
     */
	static OSDictionaryPtr
	withDictionary(
		const OSDictionary * dictionary,
		uint32_t         capacity);

    /*!
     * @brief       Add or replace an object in the dictionary.
     * @discussion  The object is added to the dictionary with the key object. If an object with the given key existed prior to the call it is replaced and released. The dictionary capacity will be grown if necessary.
     * @param       aKey An object pointer used to lookup the object. The key should be uniqued within the dictionary. Usually an OSString is passed as the key.
     * @param       anObject Object to be added to the dictionary.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	bool
	setObject(
		const OSObject        * aKey,
		const OSMetaClassBase * anObject);

    /*!
     * @brief       Add or replace an object in the dictionary.
     * @discussion  The object is added to the dictionary with the key object. If an object with the given key existed prior to the call it is replaced and released. The dictionary capacity will be grown if necessary.
     * @param       aKey A c-string key. An OSString is created from aKey and used as the key for the dictionary.
     * @param       anObject Object to be added to the dictionary.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	bool
	setObject(
		const char            * aKey,
		const OSMetaClassBase * anObject);

    /*!
     * @brief       Remove an object by key from the dictionary.
     * @discussion  An object in the dictionary with the given key object is removed and released.
     * @param       aKey An object pointer used to lookup the object. The key should be uniqued within the dictionary. Usually an OSString is passed as the key.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	void
	removeObject(const OSObject * aKey);

    /*!
     * @brief       Remove an object by key from the dictionary.
     * @discussion  An object in the dictionary with the given key object is removed and released.
     * @param       aKey A c-string key. An OSString is created from aKey and used as the key for the dictionary.
     * @return      true on success, which retains the object, or false on failure which does not retain the object.
     */
	void
	removeObject(const char * aKey);

    /*!
     * @brief       Adds all members of a dictionary to this dictionary.
     * @discussion  Adds all members of a dictionary to this dictionary. Any keys in the dictionary that exist will be replaced. The dictionary capacity will be grown if necessary.
     * @param       otherDictionary All members of thie dictionary will be added to the array.
     * @return      true on success, which retains all the added objects, or false on failure which does not retain the objects.
     */
	bool
	merge(const OSDictionary * otherDictionary);


    /*!
     * @brief       Returns a member of the dictionary.
     * @discussion  Looks up an existing object in the dictionary with the given key and returns it.
     * @param       aKey An object pointer used to lookup the object. The key should be uniqued within the dictionary. Usually an OSString is passed as the key.
     * @result      Member at the given index or NULL if the index is greater or equal to the array count. The retain count of the result object is not incremented and the object should not be release by the caller.
     */
	OSObject *
	getObject(const OSObject * aKey) const;

    /*!
     * @brief       Returns a member of the dictionary.
     * @discussion  Looks up an existing object in the dictionary with the given key and returns it.
     * @param       aKey A c-string key. An OSString is created from aKey and used as the key for the dictionary.
     * @result      Member at the given index or NULL if the index is greater or equal to the array count. The retain count of the result object is not incremented and the object should not be release by the caller.
     */
	OSObject *
	getObject(const char * aKey) const;

    /*!
     * @brief       Compares certain members of two dictionaries with isEqualTo().
     * @discussion  For each key in the given collection, both dictionaries must contain values for the key that compare successfully with isEqualTo().
     * @param       aDictionary The other dictionary to compare with.
     * @result      true if both dictionaries have equal counts, every key exists in both, values for each key compare true with isEqualTo().
     */
	bool
	isEqualTo(
		const OSDictionary * aDictionary,
		const OSCollection * keys) const;

    /*!
     * @brief       Compares all members of two dictionaries with isEqualTo().
     * @discussion  If the dictionaries have equal counts, each member is compared with the other at the same index with isEqualTo().
     *              Otherwise false is returned.
     * @param       aDictionary The other dictionary to compare with.
     * @result      true if both dictionaries have equal counts, every key exists in both, values for each key compare true with isEqualTo().
     */
	bool
	isEqualTo(const OSDictionary * aDictionary) const;

    /*!
     * @brief       Compares the dictionary with an OSObject
     * @discussion  If the object is of class OSDictionary, the result of isEqualTo(const OSDictionary * anArray) is returned.
     *              Otherwise false is returned.
     * @param       anObject The object to compare with.
     * @result      true iff the object is of class OSDictionary and isEqualTo(const OSDictionary * anArray) returns true.
     */
	bool
	isEqualTo(const OSMetaClassBase * anObject) const override;

    /*!
     * @brief       Iterates the dictionary calling a callback block for each member.
     * @discussion  Calls the block with each value in the dictionary. The block must not modify the dictionary during iteration. If the block returns true the iteration continues for all members, returning false halts the iteration early.
     * @param       block The block to invoke.
     * @return      false if the callback block returned false, otherwise true (including if the dictionary is empty).
     */
	bool
	iterateObjects(OSDictionaryIterateObjectsBlock block) const;
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class OSDictionary OSDictionary.iig:43-264 */


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
        const OSDictionary * dictionary,\
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
        const OSDictionary * otherDictionary);\
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
        OSDictionaryIterateObjectsBlock block) const;\
\
\
protected:\
    /* _Impl methods */\
\
\
public:\
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
extern const OSClassLoadInformation OSDictionary_Class;

class OSDictionaryMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
};

#endif /* !KERNEL */

#if !KERNEL

class  OSDictionaryInterface : public OSInterface
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
#ifdef OSDictionary_DECLARE_IVARS
OSDictionary_DECLARE_IVARS
#else /* OSDictionary_DECLARE_IVARS */
    union
    {
        OSDictionary_IVars * ivars;
        OSDictionary_LocalIVars * lvars;
    };
#endif /* OSDictionary_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gOSDictionaryMetaClass; };
#endif /* KERNEL */

    using super = OSCollection;

#if !KERNEL
    OSDictionary_Methods
    OSDictionary_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* OSDictionary.iig:266- */

#endif /* ! _IOKIT_OSDICTIONARY_H */
