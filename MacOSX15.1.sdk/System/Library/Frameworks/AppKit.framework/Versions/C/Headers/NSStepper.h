/*
        NSStepper.h
        Application Kit
        Copyright (c) 2000-2024, Apple Inc.
        All rights reserved.
*/

#import <AppKit/NSControl.h>
#import <AppKit/AppKitDefines.h>

APPKIT_API_UNAVAILABLE_BEGIN_MACCATALYST

@interface NSStepper : NSControl <NSAccessibilityStepper>

@property double minValue;

@property double maxValue;

@property double increment;

@property BOOL valueWraps;

@property BOOL autorepeat;

@end

API_UNAVAILABLE_END
