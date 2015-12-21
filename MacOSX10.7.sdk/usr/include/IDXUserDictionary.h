/*
 * File: IDXUserDictionary.h
 *
 * Copyright: 2010 by Apple Inc. All rights reserved.
 *
 */

#ifndef __IDX_USER_DICTIONARY__
#define __IDX_USER_DICTIONARY__

#include <CoreFoundation/CoreFoundation.h>

struct IDXUserDictionaryEntry {
	UniChar       *reading;
	CFIndex       readingLength;
	UniChar       *surface;
	CFIndex       surfaceLength;
	UniChar       *keyExtraInfo;
	CFIndex       keyExtraInfoLength;
	UInt32        seed;
};

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct __IDXUserDictionary * IDXUserDictionaryRef;

typedef struct IDXUserDictionaryEntry IDXUserDictionaryEntry;
    
typedef void (*IDXUserDictionarySearchCallBack)( IDXUserDictionaryEntry *entry, void *userInfo );
	
/* Open a user dictionary. New dictionary package is created if needed. */
extern
IDXUserDictionaryRef IDXUserDictionaryOpen( CFURLRef dictionaryURL, Boolean	keyIsReading );

/* Add an entry into dictionary. */
extern
Boolean IDXUserDictionaryAddEntry(IDXUserDictionaryRef dictionary, CFStringRef key, CFStringRef reading, CFStringRef surface, CFStringRef keyExtraInfo, Boolean updateExistingEntry);

/* Delete an entry from dictionary */
extern
Boolean IDXUserDictionaryDeleteEntry(IDXUserDictionaryRef dictionary, CFStringRef key, CFStringRef reading, CFStringRef surface);
    
/* Build dictionary */
extern
Boolean IDXUserDictionaryBuild(IDXUserDictionaryRef dictionary, CFArrayRef keyArray, CFArrayRef readingArray, CFArrayRef surfaceArray);    
    
/* Search the user dictionary. */
extern
void IDXUserDictionarySearch(IDXUserDictionaryRef dictionary, UniChar *keyBuffer, CFIndex keyLength, int voiceAmbi, int smallAmbi,
                             Boolean prefixSearch, Boolean wildcardSearch, IDXUserDictionarySearchCallBack callback, void *userInfo );

/* Save user dictionary */
extern
void IDXUserDictionarySave(IDXUserDictionaryRef dictionary);
    
/* Close user dictionary. */
extern
void IDXUserDictionaryClose(IDXUserDictionaryRef dictionary);

#ifdef __cplusplus
}
#endif

#endif /* __IDX_USER_DICTIONARY__ */