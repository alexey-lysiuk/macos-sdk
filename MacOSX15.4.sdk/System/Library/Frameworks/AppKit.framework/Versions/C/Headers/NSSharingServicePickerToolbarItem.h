/*
 NSSharingServicePickerToolbarItem.h
 Application Kit
 Copyright (c) 2019-2024, Apple Inc.
 All rights reserved.
 */
#import <TargetConditionals.h>
#import <AppKit/NSToolbarItem.h>
#import <AppKit/NSSharingService.h>

#if !TARGET_OS_IPHONE
@protocol NSSharingServicePickerToolbarItemDelegate;
#endif

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(10.15), ios(10.13))
@interface NSSharingServicePickerToolbarItem : NSToolbarItem

#if !TARGET_OS_IPHONE
@property (weak) id<NSSharingServicePickerToolbarItemDelegate> delegate;
#endif

@end

#if !TARGET_OS_IPHONE
@protocol NSSharingServicePickerToolbarItemDelegate <NSSharingServicePickerDelegate>
@required
/**
 Return the items that represent the objects to be shared.
 They must conform to the <NSPasteboardWriting> protocol or be an NSItemProvider. (e.g. NSString, NSImage, NSURL, etc.). 
 */
- (NSArray *)itemsForSharingServicePickerToolbarItem:(NSSharingServicePickerToolbarItem *)pickerToolbarItem NS_SWIFT_UI_ACTOR;

@end
#endif

NS_HEADER_AUDIT_END(nullability, sendability)
