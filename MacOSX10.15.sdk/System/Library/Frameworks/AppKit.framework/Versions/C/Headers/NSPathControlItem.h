/*
 NSPathControlItem.h
 Application Kit
 Copyright (c) 2013-2018, Apple Inc.
 All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <AppKit/AppKitDefines.h>

NS_ASSUME_NONNULL_BEGIN
API_UNAVAILABLE_BEGIN(ios)

@class NSPathComponentCell;

/*  NSPathControlItem is used to represent an individual path segment in an NSPathControl.
    NSPathControlItem should not be subclassed.
 */
API_AVAILABLE(macos(10.10))
@interface NSPathControlItem : NSObject

/* The title of the path item.
 */
@property(copy) NSString *title;
@property(copy) NSAttributedString *attributedTitle;

/* The image/icon shown for this particular component along the path. The NSPathControlItem can display both an image and title.  When drawing, your image will be scaled to fit the available area, which in 10.10 and earlier releases is 16x16 points for NSPathStyleStandard or NSPathStylePopUp, and 14x14 points for NSPathStyleNavigationBar.
 */
@property (nullable, strong) NSImage *image;

/* A url for the partial path from the beginning up to this particular item.
 */
@property (nullable, readonly) NSURL *URL;

@end

API_UNAVAILABLE_END
NS_ASSUME_NONNULL_END
