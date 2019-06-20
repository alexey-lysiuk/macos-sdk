#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIAction.h>)
//
//  UIAction.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIMenu.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UIActionOptions) {
    UIActionOptionsDisabled     = 1 << 0,
    UIActionOptionsSelected     = 1 << 1,
    UIActionOptionsDestructive  = 1 << 2
} NS_SWIFT_NAME(UIAction.Options) API_AVAILABLE(ios(13.0));

@class UIAction;

typedef void (^UIActionHandler)(__kindof UIAction *action);

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIAction : UIMenuElement<UIAction *>

/// This action's options
@property (nonatomic, readonly) UIActionOptions options;

/*!
 * @abstract Creates a UIAction with the given arguments.
 *
 * @param title    The action's title.
 * @param image    Image to be displayed alongside the action's title.
 * @param options  The action's options.
 * @param handler  Handler block. Called when the user selects the action.
 *
 * @return A new UIAction.
 */
+ (instancetype)actionWithTitle:(NSString *)title
                          image:(nullable UIImage *)image
                        options:(UIActionOptions)options
                        handler:(UIActionHandler)handler NS_REFINED_FOR_SWIFT;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end


@interface UIMenu (UIAction)

/*!
 * @abstract Creates a UIMenu with the given arguments.
 *
 * @param title       The menu's title.
 * @param children    The menu's action-based sub-elements and sub-menus.
 *
 * @return A new UIMenu.
 */
+ (UIMenu<UIAction *> *)actionMenuWithTitle:(NSString *)title
                                   children:(NSArray<UIMenuElement<UIAction *> *> *)children NS_SWIFT_NAME(create(title:children:));

/*!
 * @abstract Creates a UIMenu with the given arguments.
 *
 * @param title       The menu's title.
 * @param image       Image to be displayed alongside the menu's title.
 * @param identifier  The menu's unique identifier. Pass nil to use an auto-generated identifier.
 * @param options     The menu's options.
 * @param children    The menu's action-based sub-elements and sub-menus.
 *
 * @return A new UIMenu.
 */
+ (UIMenu<UIAction *> *)actionMenuWithTitle:(NSString *)title
                                      image:(nullable UIImage *)image
                                 identifier:(nullable UIMenuIdentifier)identifier
                                    options:(UIMenuOptions)options
                                   children:(NSArray<UIMenuElement<UIAction *> *> *)children NS_SWIFT_NAME(create(title:image:identifier:options:children:));

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIAction.h>
#endif
