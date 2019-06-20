/*
	NSImageCell.h
	Application Kit
	Copyright (c) 1994-2018, Apple Inc.
	All rights reserved.
*/


#import <AppKit/NSCell.h>

API_UNAVAILABLE_BEGIN(ios)

@class NSImage;

typedef NS_ENUM(NSUInteger, NSImageAlignment) {
    NSImageAlignCenter = 0,
    NSImageAlignTop,
    NSImageAlignTopLeft,
    NSImageAlignTopRight,
    NSImageAlignLeft,
    NSImageAlignBottom,
    NSImageAlignBottomLeft,
    NSImageAlignBottomRight,
    NSImageAlignRight
};

typedef NS_ENUM(NSUInteger, NSImageFrameStyle) {
    NSImageFrameNone = 0,
    NSImageFramePhoto,
    NSImageFrameGrayBezel,
    NSImageFrameGroove,
    NSImageFrameButton
};


@interface NSImageCell : NSCell <NSCopying, NSCoding>

@property NSImageAlignment imageAlignment;
@property NSImageScaling imageScaling;
@property NSImageFrameStyle imageFrameStyle;

@end

API_UNAVAILABLE_END
