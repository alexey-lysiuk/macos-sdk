#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommand.h>)
//
//  UICommand.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIMenuElement.h>
#import <UIKit/UIMenu.h>

typedef NS_ENUM(NSInteger, UICommandState) {
    UICommandStateOff,
    UICommandStateOn,
    UICommandStateMixed,
    UICommandStateHidden
} NS_SWIFT_NAME(UICommand.State) API_AVAILABLE(ios(13.0));

/** START OF V1 API, TO REMOVE **/

typedef NS_OPTIONS(NSUInteger, UICommandStateMask) {
    UICommandStateMaskOn = 1 << UICommandStateOn,
    UICommandStateMaskMixed = 1 << UICommandStateMixed,
    UICommandStateMaskHidden = 1 << UICommandStateHidden
} NS_SWIFT_NAME(UICommand.StateMask) API_DEPRECATED("Do not use", ios(13.0, 13.0));

/** END OF V1 API, TO REMOVE **/

typedef NS_OPTIONS(NSInteger, UIKeyModifierFlags) {
    UIKeyModifierAlphaShift     = 1 << 16,  // This bit indicates CapsLock
    UIKeyModifierShift          = 1 << 17,
    UIKeyModifierControl        = 1 << 18,
    UIKeyModifierAlternate      = 1 << 19,
    UIKeyModifierCommand        = 1 << 20,
    UIKeyModifierNumericPad     = 1 << 21,
} API_AVAILABLE(ios(7.0));

@class UICommand;
@class UIImage;

NS_ASSUME_NONNULL_BEGIN

/// Represents an alternate action to take for a command.
///
/// Two alternates are equal iff their modifierFlags are equal.
UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UICommandAlternate : NSObject <NSCopying, NSSecureCoding>

/// Short display title.
@property (nonatomic, readonly) NSString *title;

/// Action to take on choosing this command alternate.
@property (nonatomic, readonly) SEL action;

/// Bitmask of modifier flags to choose this command alternate.
@property (nonatomic, readonly) UIKeyModifierFlags modifierFlags;

/// Initialize an alternate action to take for a command.
///
/// @param title Short display title. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param modifierFlags Bitmask of modifier flags to choose this command alternate.
/// @return A new command alternate.
+ (instancetype)alternateWithTitle:(NSString *)title
                            action:(SEL)action
                     modifierFlags:(UIKeyModifierFlags)modifierFlags;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

/// Represents an action to take.
UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UICommand : UIMenuElement<UICommand *> <NSCopying, NSMutableCopying, NSSecureCoding>

/// Elaborated title, if any.
@property (nullable, nonatomic, readonly) NSString *discoverabilityTitle;

/// Action to take on choosing this command.
@property (nonatomic, readonly) SEL action;

/// Property list object to distinguish commands, if needed.
@property (nullable, nonatomic, readonly) id propertyList;

/// Whether to enable or disable the command.
@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;

/// State that can appear next to the command.
@property (nonatomic, readonly) UICommandState state;

/// Alternates that differ in modifier flags, if any.
@property (nonatomic, readonly) NSArray<UICommandAlternate *> *alternates;

/// Initializes a keyless command.
///
/// @param title Short display title. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @return A new keyless command.
+ (instancetype)commandWithTitle:(NSString *)title
                          action:(SEL)action
                    propertyList:(nullable id)propertyList NS_REFINED_FOR_SWIFT;

/// Initializes a keyless command with alternates.
///
/// @param title Short display title. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param alternates Alternates that differ in modifier flags.
/// @return A new keyless command with alternates.
+ (instancetype)commandWithTitle:(NSString *)title
                          action:(SEL)action
                    propertyList:(nullable id)propertyList
                      alternates:(NSArray<UICommandAlternate *> *)alternates NS_REFINED_FOR_SWIFT;

/** START OF V1 API, TO REMOVE **/

/// Property list object to distinguish commands, if needed.
@property (nullable, nonatomic, readonly) id __propertyList API_DEPRECATED_WITH_REPLACEMENT("propertyList", ios(13.0, 13.0));

/// Visible states that can appear next to the command.
@property (nonatomic, readonly) UICommandStateMask supportedStates API_DEPRECATED("Do not use", ios(13.0, 13.0));

/// Initializes a keyless command.
///
/// @param title Short display title. This should be localized.
/// @param discoverabilityTitle Elaborated title, if any. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param supportedStates Visible states that can appear next to the command
/// @return A new keyless command.
+ (instancetype)commandWithTitle:(NSString *)title
            discoverabilityTitle:(nullable NSString *)discoverabilityTitle
                          action:(SEL)action
                    propertyList:(nullable id)propertyList
                 supportedStates:(UICommandStateMask)supportedStates NS_REFINED_FOR_SWIFT API_DEPRECATED_WITH_REPLACEMENT("commandWithTitle:action:propertyList:", ios(13.0, 13.0));

/// Initializes a keyless command with alternates.
///
/// @param title Short display title. This should be localized.
/// @param discoverabilityTitle Elaborated title, if any. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param supportedStates Visible states that can appear next to the command.
/// @param alternates Alternates that differ in modifier flags.
/// @return A new keyless command with alternates.
+ (instancetype)commandWithTitle:(NSString *)title
            discoverabilityTitle:(nullable NSString *)discoverabilityTitle
                          action:(SEL)action
                    propertyList:(nullable id)propertyList
                 supportedStates:(UICommandStateMask)supportedStates
                      alternates:(NSArray<UICommandAlternate *> *)alternates NS_REFINED_FOR_SWIFT API_DEPRECATED_WITH_REPLACEMENT("commandWithTitle:action:propertyList:alternates:", ios(13.0, 13.0));

/// Initializes a key command.
///
/// @param title Short display title. This should be localized.
/// @param discoverabilityTitle Elaborated title, if any. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param supportedStates Visible states that can appear next to the command.
/// @param input Keys that must be pressed to choose this command.
/// @param modifierFlags Bit mask of key modifier flags to choose this command.
/// @return A new key command.
+ (instancetype)commandWithTitle:(NSString *)title
            discoverabilityTitle:(nullable NSString *)discoverabilityTitle
                          action:(SEL)action
                    propertyList:(nullable id)propertyList
                 supportedStates:(UICommandStateMask)supportedStates
                           input:(NSString *)input
                   modifierFlags:(UIKeyModifierFlags)modifierFlags NS_REFINED_FOR_SWIFT API_DEPRECATED_WITH_REPLACEMENT("UIKeyCommand", ios(13.0, 13.0));

/// Initializes a key command with alternates.
///
/// @param title Short display title. This should be localized.
/// @param discoverabilityTitle Elaborated title, if any. This should be localized.
/// @param action Action to take on choosing this command alternate.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @param supportedStates Visible states that can appear next to the command.
/// @param input Keys that must be pressed to choose this command.
/// @param modifierFlags Bit mask of key modifier flags to choose this command.
/// @param alternates Alternates that differ in modifier flags.
/// @return A new key command.
+ (instancetype)commandWithTitle:(NSString *)title
            discoverabilityTitle:(nullable NSString *)discoverabilityTitle
                          action:(SEL)action
                    propertyList:(nullable id)propertyList
                 supportedStates:(UICommandStateMask)supportedStates
                           input:(NSString *)input
                   modifierFlags:(UIKeyModifierFlags)modifierFlags
                      alternates:(NSArray<UICommandAlternate *> *)alternates NS_REFINED_FOR_SWIFT API_DEPRECATED_WITH_REPLACEMENT("UIKeyCommand", ios(13.0, 13.0));

/** END OF V1 API, TO REMOVE **/

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

/// Represents an action to take, with mutable properties.
UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIMutableCommand : UICommand

/// Short display title.
@property (nonatomic, copy) NSString *title;

/// Image that can appear next to the command.
@property (nullable, nonatomic, retain) UIImage *image;

/// Elaborated title, if any.
@property (nullable, nonatomic, copy) NSString *discoverabilityTitle;

/// Whether to enable or disable the command.
@property (nonatomic, getter=isEnabled) BOOL enabled;

/// State that can appear next to the command.
@property (nonatomic) UICommandState state;

@end

@interface UIMenu (UICommand)

/// Creates a menu with the given arguments.
///
/// @param title  The menu's title.
/// @param children The menu's action-based sub-elements and sub-menus.
/// @return A new menu.
+ (UIMenu<UICommand *> *)commandMenuWithTitle:(NSString *)title
                                     children:(NSArray<UIMenuElement<UICommand *> *> *)children NS_SWIFT_NAME(create(title:children:));

/// Creates a menu with the given arguments.
///
/// @param title The menu's title.
/// @param image Image to be displayed alongside the menu's title.
/// @param identifier The menu's unique identifier. Pass nil to use an auto-generated identifier.
/// @param options The menu's options.
/// @param children The menu's action-based sub-elements and sub-menus.
+ (UIMenu<UICommand *> *)commandMenuWithTitle:(NSString *)title
                                        image:(nullable UIImage *)image
                                   identifier:(nullable UIMenuIdentifier)identifier
                                      options:(UIMenuOptions)options
                                     children:(NSArray<UIMenuElement<UICommand *> *> *)children NS_SWIFT_NAME(create(title:image:identifier:options:children:));

@end

/// -- Group identifiers for top-level menus

/// Application menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuApplication API_AVAILABLE(ios(13.0));

/// File menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuFile API_AVAILABLE(ios(13.0));

/// Edit menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuEdit API_AVAILABLE(ios(13.0));

/// View menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuView API_AVAILABLE(ios(13.0));

/// Window menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuWindow API_AVAILABLE(ios(13.0));

/// Help menu top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuHelp API_AVAILABLE(ios(13.0));

/// -- Group identifiers for Application menu sections

/// About command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuAbout API_AVAILABLE(ios(13.0));

/// Preferences command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuPreferences API_AVAILABLE(ios(13.0));

/// Services command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuServices API_AVAILABLE(ios(13.0));

/// Hide, Hide Others, Show All command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuHide API_AVAILABLE(ios(13.0));

/// Quit command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuQuit API_AVAILABLE(ios(13.0));

/// -- Group identifiers for File menu sections

/// New scene group
UIKIT_EXTERN const UIMenuIdentifier UIMenuNewScene API_AVAILABLE(ios(13.0));

/// Close group
UIKIT_EXTERN const UIMenuIdentifier UIMenuClose API_AVAILABLE(ios(13.0));

/// Print group
UIKIT_EXTERN const UIMenuIdentifier UIMenuPrint API_AVAILABLE(ios(13.0));

/// -- Group identifiers for Edit menu sections

/// Undo, Redo group
UIKIT_EXTERN const UIMenuIdentifier UIMenuUndoRedo API_AVAILABLE(ios(13.0));

/// Cut, Copy, Paste, Delete, Select, Select All command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuStandardEdit API_AVAILABLE(ios(13.0));

// Find command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuFind API_AVAILABLE(ios(13.0));

/// Replace..., Transliterate Chinese command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuReplace API_AVAILABLE(ios(13.0));

/// Share command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuShare API_AVAILABLE(ios(13.0));

/// Bold, Italics, Underline inline command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuTextStyle API_AVAILABLE(ios(13.0));

/// Spelling command group contained within Edit group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSpelling API_AVAILABLE(ios(13.0));

/// Show Spelling, Check Document Now command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSpellingPanel API_AVAILABLE(ios(13.0));

/// Check Spelling While Typing and other spelling and grammar-checking options command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSpellingOptions API_AVAILABLE(ios(13.0));

/// Substitutions command group contained within Edit group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSubstitutions API_AVAILABLE(ios(13.0));

// Show Substitutions command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSubstitutionsPanel API_AVAILABLE(ios(13.0));

/// Smart Copy, Smart Paste, Smart Quotes, and other substitution options command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuSubstitutionOptions API_AVAILABLE(ios(13.0));

/// Transformations command group contained within Edit menu (contains Make Uppercase, Make Lowercase, Capitalize)
UIKIT_EXTERN const UIMenuIdentifier UIMenuTransformations API_AVAILABLE(ios(13.0));

/// Speech command group contained within Edit menu (contains Speak, Speak..., Pause)
UIKIT_EXTERN const UIMenuIdentifier UIMenuSpeech API_AVAILABLE(ios(13.0));

/// Lookup command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuLookup API_AVAILABLE(ios(13.0));

/// Learn command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuLearn API_AVAILABLE(ios(13.0));

/// Format top-level command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuFormat API_AVAILABLE(ios(13.0));

/// Font command group contained within Format menu (contains UIMenuTextStyle)
UIKIT_EXTERN const UIMenuIdentifier UIMenuFont API_AVAILABLE(ios(13.0));

/// Bigger and Smaller command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuTextSize API_AVAILABLE(ios(13.0));

/// Show Colors command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuTextColor API_AVAILABLE(ios(13.0));

/// Copy Style and Paste Style command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuTextStylePasteboard API_AVAILABLE(ios(13.0));

/// Text command group contained within Format menu (contains UIMenuAlignment and UIMenuWritingDirection)
UIKIT_EXTERN const UIMenuIdentifier UIMenuText API_AVAILABLE(ios(13.0));

/// Default, Right to Left, Left to Right command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuWritingDirection API_AVAILABLE(ios(13.0));

/// Align Left, Center, Justify, Align Right command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuAlignment API_AVAILABLE(ios(13.0));

/// -- Group identifiers for View menu sections

/// Fullscreen command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuFullscreen API_AVAILABLE(ios(13.0));

/// -- Group identifiers for Window menu sections

/// Minimize, Zoom command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuMinimizeAndZoom API_AVAILABLE(ios(13.0));

/// Bring All to Front, Arrange in Front command group
UIKIT_EXTERN const UIMenuIdentifier UIMenuBringAllToFront API_AVAILABLE(ios(13.0));

// Root-level group
UIKIT_EXTERN const UIMenuIdentifier UIMenuRoot API_AVAILABLE(ios(13.0));

// UICommand.propertyList value to indicate that a command is a Sharing menu item. Such an item automatically receives a standard Share submenu.
UIKIT_EXTERN NSString *const UICommandTagShare API_AVAILABLE(ios(13.0));

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommand.h>
#endif
