#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIMenu.h>)
//
//  UIMenu.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIMenuElement.h>

typedef NSString *UIMenuIdentifier NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(ios(13.0));

typedef NS_OPTIONS(NSUInteger, UIMenuOptions) {
    /// Show children inline in parent, instead of hierarchically
    UIMenuOptionsDisplayInline  = 1 << 0,

    /// Indicates whether the menu should be rendered with a destructive appearance in its parent
    UIMenuOptionsDestructive    = 1 << 1,
} API_AVAILABLE(ios(13.0));

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIMenu<T> : UIMenuElement<T> <NSSecureCoding>

/// Unique identifier.
@property (nonatomic, readonly) UIMenuIdentifier identifier;

/// Options.
@property (nonatomic, readonly) UIMenuOptions options;

/// The menu's sub-elements and sub-menus.
@property (nonatomic, readonly) NSArray<UIMenuElement<T> *> *children;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*!
 * @abstract Copies this menu and replaces its children.
 *
 * @param newChildren  The replacement children.
 *
 * @return A copy of this menu with updated children.
 */
- (UIMenu<T> *)menuByReplacingChildren:(NSArray<UIMenuElement<T> *> *)newChildren;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIMenu.h>
#endif
