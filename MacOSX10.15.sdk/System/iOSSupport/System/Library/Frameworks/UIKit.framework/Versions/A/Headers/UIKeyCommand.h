#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIKeyCommand.h>)
//
//  UIKeyCommand.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UICommand.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(7.0)) @interface UIKeyCommand :
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_13_0 || __TV_OS_VERSION_MIN_REQUIRED || __WATCH_OS_VERSION_MIN_REQUIRED
UICommand
#else
NSObject <NSCopying, NSSecureCoding>
#endif

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property (nullable, nonatomic, readonly) NSString *input;
@property (nonatomic, readonly) UIKeyModifierFlags modifierFlags;
@property (nullable, nonatomic, copy) NSString *discoverabilityTitle API_AVAILABLE(ios(9.0));
@property (nullable, nonatomic, readonly) SEL action;

- (void)setDiscoverabilityTitle:(NSString *_Nullable)discoverabilityTitle API_DEPRECATED_WITH_REPLACEMENT("UIMutableKeyCommand", ios(9.0, 13.0));

/// Initializes a key command.
///
/// @param title Short display title. This should be localized.
/// @param action Action to take on choosing this command.
/// @param input Keys that must be pressed to choose this command.
/// @param modifierFlags Bit mask of key modifier flags to choose this command.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @return A new key command.
+ (instancetype)commandWithTitle:(NSString *)title
                          action:(SEL)action
                           input:(NSString *)input
                   modifierFlags:(UIKeyModifierFlags)modifierFlags
                    propertyList:(nullable id)propertyList NS_SWIFT_UNAVAILABLE("Use init(title:action:input:modifierFlags:propertyList:alternates:) instead");

/// Initializes a key command with alternates.
///
/// @param title Short display title. This should be localized.
/// @param action Action to take on choosing this command.
/// @param input Keys that must be pressed to choose this command.
/// @param modifierFlags Bit mask of key modifier flags to choose this command.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param alternates Alternates that differ in modifier flags.
/// @return A new key command.
+ (instancetype)commandWithTitle:(NSString *)title
                          action:(SEL)action
                           input:(NSString *)input
                   modifierFlags:(UIKeyModifierFlags)modifierFlags
                    propertyList:(nullable id)propertyList
                      alternates:(NSArray<UICommandAlternate *> *)alternates NS_REFINED_FOR_SWIFT;

// The action for UIKeyCommands should accept a single (id)sender, as do the UIResponderStandardEditActions above

// Creates an key command that will _not_ be discoverable in the UI.
+ (instancetype)keyCommandWithInput:(NSString *)input modifierFlags:(UIKeyModifierFlags)modifierFlags action:(SEL)action;

// Key Commands with a discoverabilityTitle _will_ be discoverable in the UI.
+ (instancetype)keyCommandWithInput:(NSString *)input modifierFlags:(UIKeyModifierFlags)modifierFlags action:(SEL)action discoverabilityTitle:(NSString *)discoverabilityTitle API_DEPRECATED_WITH_REPLACEMENT("UIMutableKeyCommand", ios(9.0, 13.0));

@end

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIMutableKeyCommand : UIKeyCommand

@property (nonatomic, copy) NSString *title;
@property (nullable, nonatomic, retain) UIImage *image;
@property (nullable, nonatomic, copy) NSString *discoverabilityTitle;

@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic) UICommandState state;

@end


NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIKeyCommand.h>
#endif
