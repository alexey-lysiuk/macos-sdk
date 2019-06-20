//
//  NSButtonTouchBarItem.h
//  Framework
//
//  Created by John Tegtmeyer on 3/5/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <AppKit/NSTouchBarItem.h>

#if !TARGET_OS_IPHONE
@class NSColor, NSImage;
#else
@class UIColor, UIImage;
#endif

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.15)) API_AVAILABLE(ios(13.0))
@interface NSButtonTouchBarItem : NSTouchBarItem

/*
 Creates a standard item with an button appropriate for use in an NSTouchBar
 */
+ (instancetype)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier title:(NSString *)title target:(nullable id)target action:(nullable SEL)action;

#if !TARGET_OS_IPHONE
+ (instancetype)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier image:(NSImage *)image target:(nullable id)target action:(nullable SEL)action;
+ (instancetype)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier title:(NSString *)title image:(NSImage *)image target:(nullable id)target action:(nullable SEL)action;
#else
+ (instancetype)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier image:(UIImage *)image target:(nullable id)target action:(nullable SEL)action;
+ (instancetype)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier title:(NSString *)title image:(UIImage *)image target:(nullable id)target action:(nullable SEL)action;
#endif

@property (copy) NSString *title;

#if !TARGET_OS_IPHONE
@property (nullable, strong) NSImage *image;
@property (nullable, copy) NSColor *bezelColor;
#else
@property (nullable, strong) UIImage *image;
@property (nullable, copy) UIColor *bezelColor;
#endif

@property (nullable, weak) id target;
@property (nullable ) SEL action;

/// The localized string labelling this item during user customization. The default value is empty string.
@property (readwrite, copy, null_resettable) NSString *customizationLabel;

@end

NS_ASSUME_NONNULL_END
