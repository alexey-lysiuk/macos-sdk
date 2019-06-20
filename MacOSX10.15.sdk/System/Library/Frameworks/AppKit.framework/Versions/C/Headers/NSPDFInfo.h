/*
        NSPDFInfo.h
        Application Kit
        Copyright (c) 2013-2018, Apple Inc.
        All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSGeometry.h>
#import <AppKit/NSPrintInfo.h>

NS_ASSUME_NONNULL_BEGIN
API_UNAVAILABLE_BEGIN(ios)

@class NSURL;

API_AVAILABLE(macos(10.9))
@interface NSPDFInfo : NSObject <NSCopying, NSCoding>

@property (copy, nullable) NSURL *URL;
@property (getter=isFileExtensionHidden) BOOL fileExtensionHidden;
@property (copy) NSArray<NSString *> *tagNames;
@property NSPaperOrientation orientation;
@property NSSize paperSize;
@property (readonly) NSMutableDictionary<NSPrintInfoAttributeKey, id> *attributes;

@end

API_UNAVAILABLE_END
NS_ASSUME_NONNULL_END
