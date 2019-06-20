#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommandGroup.h>)
//
//  UICommandGroup.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIMenu.h>

@class UICommand;
@protocol UICommandGroupable;

typedef NSString *UICommandGroupIdentifier NS_SWIFT_NAME(UICommandGroup.Identifier) NS_TYPED_EXTENSIBLE_ENUM API_DEPRECATED_WITH_REPLACEMENT("UIMenuIdentifier", ios(13.0, 13.0));

typedef NS_OPTIONS(NSUInteger, UICommandGroupOptions) {
    /// Show group inline in parent, instead of hierarchically
    UICommandGroupOptionsDisplayInline = 1 << 0
} NS_SWIFT_NAME(UICommandGroup.Options) API_DEPRECATED_WITH_REPLACEMENT("UIMenuOptions", ios(13.0, 13.0));

NS_ASSUME_NONNULL_BEGIN

/// Represent a group of commands or subgroups.
UIKIT_EXTERN API_DEPRECATED_WITH_REPLACEMENT("UIMenu", ios(13.0, 13.0)) @interface UICommandGroup : UIMenu<UICommand *>

/// Unique identifier.
@property (nonatomic, readonly) UICommandGroupIdentifier identifier;

/// Elaborated title, if any.
@property (nullable, nonatomic, readonly) NSString *discoverabilityTitle;

/// Options.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, readonly) UICommandGroupOptions options;
#pragma clang diagnostic pop

/// Initializes a command group.
///
/// @param title Short display title. This should be localized.
/// @param discoverabilityTitle Elaborated title, if any. This should be localized.
/// @param identifier Unique identifier, typically a reverse DNS-style string.
///        Apple reserves all identifiers prefixed with "com.apple.".
/// @param options Options.
/// @param children Commands or subgroups to group.
/// @return A new command group.
+ (instancetype)groupWithTitle:(NSString *)title
          discoverabilityTitle:(nullable NSString *)discoverabilityTitle
                    identifier:(UICommandGroupIdentifier)identifier
                       options:(UICommandGroupOptions)options
                      children:(NSArray<id<UICommandGroupable>> *)children NS_REFINED_FOR_SWIFT;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (UICommandGroup *)menuByReplacingChildren:(NSArray<UIMenuElement<UICommand *> *> *)newChildren;

/// Copies this command group, replacing the children.
///
/// @param newChildren The replacement children.
/// @return The copy of this group.
- (UICommandGroup *)groupByReplacingChildren:(NSArray<id<UICommandGroupable>> *)newChildren;

@end

/// -- Group identifiers for top-level menus

/// Application menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupApplication API_DEPRECATED_WITH_REPLACEMENT("UIMenuApplication", ios(13.0, 13.0));

/// File menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupFile API_DEPRECATED_WITH_REPLACEMENT("UIMenuFile", ios(13.0, 13.0));

/// Edit menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupEdit API_DEPRECATED_WITH_REPLACEMENT("UIMenuEdit", ios(13.0, 13.0));

/// View menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupView API_DEPRECATED_WITH_REPLACEMENT("UIMenuView", ios(13.0, 13.0));

/// Window menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupWindow API_DEPRECATED_WITH_REPLACEMENT("UIMenuWindow", ios(13.0, 13.0));

/// Help menu top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupHelp API_DEPRECATED_WITH_REPLACEMENT("UIMenuHelp", ios(13.0, 13.0));

/// -- Group identifiers for Application menu sections

/// About command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupAbout API_DEPRECATED_WITH_REPLACEMENT("UIMenuAbout", ios(13.0, 13.0));

/// Preferences command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupPreferences API_DEPRECATED_WITH_REPLACEMENT("UIMenuPreferences", ios(13.0, 13.0));

/// Services command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupServices API_DEPRECATED_WITH_REPLACEMENT("UIMenuServices", ios(13.0, 13.0));

/// Hide, Hide Others, Show All command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupHide API_DEPRECATED_WITH_REPLACEMENT("UIMenuHide", ios(13.0, 13.0));

/// Quit command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupQuit API_DEPRECATED_WITH_REPLACEMENT("UIMenuQuit", ios(13.0, 13.0));

/// -- Group identifiers for File menu sections

/// New scene group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupNewScene API_DEPRECATED_WITH_REPLACEMENT("UIMenuNewScene", ios(13.0, 13.0));

/// Close group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupClose API_DEPRECATED_WITH_REPLACEMENT("UIMenuClose", ios(13.0, 13.0));

/// Print group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupPrint API_DEPRECATED_WITH_REPLACEMENT("UIMenuPrint", ios(13.0, 13.0));

/// -- Group identifiers for Edit menu sections

/// Undo, Redo group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupUndoRedo API_DEPRECATED_WITH_REPLACEMENT("UIMenuUndoRedo", ios(13.0, 13.0));

/// Cut, Copy, Paste, Delete, Select, Select All command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupStandardEdit API_DEPRECATED_WITH_REPLACEMENT("UIMenuStandardEdit", ios(13.0, 13.0));

// Find command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupFind API_DEPRECATED_WITH_REPLACEMENT("UIMenuFind", ios(13.0, 13.0));

/// Replace..., Transliterate Chinese command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupReplace API_DEPRECATED_WITH_REPLACEMENT("UIMenuReplace", ios(13.0, 13.0));

/// Share command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupShare API_DEPRECATED_WITH_REPLACEMENT("UIMenuShare", ios(13.0, 13.0));

/// Bold, Italics, Underline inline command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupTextStyle API_DEPRECATED_WITH_REPLACEMENT("UIMenuTextStyle", ios(13.0, 13.0));

/// Spelling command group contained within Edit group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSpelling API_DEPRECATED_WITH_REPLACEMENT("UIMenuSpelling", ios(13.0, 13.0));

/// Show Spelling, Check Document Now command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSpellingPanel API_DEPRECATED_WITH_REPLACEMENT("UIMenuSpellingPanel", ios(13.0, 13.0));

/// Check Spelling While Typing and other spelling and grammar-checking options command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSpellingOptions API_DEPRECATED_WITH_REPLACEMENT("UIMenuSpellingOptions", ios(13.0, 13.0));

/// Substitutions command group contained within Edit group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSubstitutions API_DEPRECATED_WITH_REPLACEMENT("UIMenuSubstitutions", ios(13.0, 13.0));

// Show Substitutions command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSubstitutionsPanel API_DEPRECATED_WITH_REPLACEMENT("UIMenuSubstitutionsPanel", ios(13.0, 13.0));

/// Smart Copy, Smart Paste, Smart Quotes, and other substitution options command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSubstitutionOptions API_DEPRECATED_WITH_REPLACEMENT("UIMenuSubstitutionOptions", ios(13.0, 13.0));

/// Transformations command group contained within Edit menu (contains Make Uppercase, Make Lowercase, Capitalize)
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupTransformations API_DEPRECATED_WITH_REPLACEMENT("UIMenuTransformations", ios(13.0, 13.0));

/// Speech command group contained within Edit menu (contains Speak, Speak..., Pause)
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupSpeech API_DEPRECATED_WITH_REPLACEMENT("UIMenuSpeech", ios(13.0, 13.0));

/// Lookup command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupLookup API_DEPRECATED_WITH_REPLACEMENT("UIMenuLookup", ios(13.0, 13.0));

/// Learn command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupLearn API_DEPRECATED_WITH_REPLACEMENT("UIMenuLearn", ios(13.0, 13.0));

/// Format top-level command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupFormat API_DEPRECATED_WITH_REPLACEMENT("UIMenuFormat", ios(13.0, 13.0));

/// Font command group contained within Format menu (contains UICommandGroupTextStyle)
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupFont API_DEPRECATED_WITH_REPLACEMENT("UIMenuFont", ios(13.0, 13.0));

/// Bigger and Smaller command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupTextSize API_DEPRECATED_WITH_REPLACEMENT("UIMenuTextSize", ios(13.0, 13.0));

/// Show Colors command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupTextColor API_DEPRECATED_WITH_REPLACEMENT("UIMenuTextColor", ios(13.0, 13.0));

/// Copy Style and Paste Style command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupTextStylePasteboard API_DEPRECATED_WITH_REPLACEMENT("UIMenuTextStylePasteboard", ios(13.0, 13.0));

/// Text command group contained within Format menu (contains UICommandGroupAlignment and UICommandGroupWritingDirection)
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupText API_DEPRECATED_WITH_REPLACEMENT("UIMenuText", ios(13.0, 13.0));

/// Default, Right to Left, Left to Right command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupWritingDirection API_DEPRECATED_WITH_REPLACEMENT("UIMenuWritingDirection", ios(13.0, 13.0));

/// Align Left, Center, Justify, Align Right command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupAlignment API_DEPRECATED_WITH_REPLACEMENT("UIMenuAlignment", ios(13.0, 13.0));

/// -- Group identifiers for View menu sections

/// Fullscreen command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupFullscreen API_DEPRECATED_WITH_REPLACEMENT("UIMenuFullscreen", ios(13.0, 13.0));

/// -- Group identifiers for Window menu sections

/// Minimize, Zoom command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupMinimizeAndZoom API_DEPRECATED_WITH_REPLACEMENT("UIMenuMinimizeAndZoom", ios(13.0, 13.0));

/// Bring All to Front, Arrange in Front command group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupBringAllToFront API_DEPRECATED_WITH_REPLACEMENT("UIMenuBringAllToFront", ios(13.0, 13.0));

// Root-level group
UIKIT_EXTERN const UICommandGroupIdentifier UICommandGroupRoot API_DEPRECATED_WITH_REPLACEMENT("UIMenuRoot", ios(13.0, 13.0));

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommandGroup.h>
#endif
