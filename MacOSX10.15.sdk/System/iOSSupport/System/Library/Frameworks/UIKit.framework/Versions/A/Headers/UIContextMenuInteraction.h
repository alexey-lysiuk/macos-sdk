#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIContextMenuInteraction.h>)
//
//  UIContextMenuInteraction.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIKitDefines.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIInteraction.h>
#import <UIKit/UIAction.h>

NS_ASSUME_NONNULL_BEGIN

@class UITargetedPreview;
@protocol UIContextMenuInteractionDelegate;

/*!
 * @abstract Return a UIAction-based UIMenu describing the desired action hierarchy.
 *
 * @param suggestedActions  An array of suggested actions gathered from the UIResponder chain. You may choose to include
 *                          some of these actions in the hierarchy returned from this block to display them in the resulting menu.
 */
typedef UIMenu<UIAction *> * _Nullable (^UIContextMenuActionProvider)(NSArray<UIMenuElement<UIAction *> *> *suggestedActions);

/*!
 * @abstract Return a UIViewController to be displayed as this menu's preview component.
 */
typedef UIViewController * _Nullable (^UIContextMenuContentPreviewProvider)(void);


UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(watchos, tvos) @interface UIContextMenuConfiguration : NSObject

@property (nonatomic, readonly) id<NSCopying> identifier;

/*!
 * @abstract Returns a UIContextMenuConfiguration.
 *
 * @param identifier       Optional unique identifier. If omitted, an NSUUID will be generated. May be used to
 *                         identify this configuration throughout the interaction's lifecycle.
 * @param previewProvider  Optional preview view controller provider block, called when the menu is about to be presented.
 * @param actionProvider   Optional action provider block, called when the menu is about to be presented.
 */
+ (instancetype)configurationWithIdentifier:(nullable id<NSCopying>)identifier
                            previewProvider:(nullable UIContextMenuContentPreviewProvider)previewProvider
                             actionProvider:(nullable UIContextMenuActionProvider)actionProvider;

@end


UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(watchos, tvos) @interface UIContextMenuInteraction : NSObject <UIInteraction>

/// The interaction's delegate.
@property (nonatomic, weak, readonly) id<UIContextMenuInteractionDelegate> delegate;

- (instancetype)initWithDelegate:(id<UIContextMenuInteractionDelegate>)delegate NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*!
 * @abstract Returns the interaction's location within the given view.
 *
 * @param view The view in which to locate the interaction.
 */
- (CGPoint)locationInView:(nullable UIView *)view;

@end

typedef NS_ENUM(NSInteger, UIContextMenuInteractionCommitStyle) {
    UIContextMenuInteractionCommitStyleDismiss = 0,
    UIContextMenuInteractionCommitStylePop,
} API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(watchos, tvos);

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(watchos, tvos) @protocol UIContextMenuInteractionCommitAnimating <NSObject>

@property (nonatomic) UIContextMenuInteractionCommitStyle preferredCommitStyle;
@property (nonatomic, readonly, nullable) UIViewController *previewViewController;

- (void)addAnimations:(void (^)(void))animations;
- (void)addCompletion:(void (^)(void))completion;

@end

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(watchos, tvos) @protocol UIContextMenuInteractionDelegate <NSObject>

/*!
 * @abstract Called when the interaction begins.
 *
 * @param interaction  The UIContextMenuInteraction.
 * @param location     The location of the interaction in its view.
 *
 * @return A UIContextMenuConfiguration describing the menu to be presented. Return nil to prevent the interaction from beginning.
 *         Returning an empty configuration causes the interaction to begin then fail with a cancellation effect. You might use this
 *         to indicate to users that it's possible for a menu to be presented from this view, but that there are no actions to
 *         present at this particular time.
 */
- (nullable UIContextMenuConfiguration *)contextMenuInteraction:(UIContextMenuInteraction *)interaction configurationForMenuAtLocation:(CGPoint)location;

@optional

/*!
 * @abstract Called when the interaction begins. Return a UITargetedPreview describing the desired highlight preview.
 *
 * @param interaction    The UIContextMenuInteraction requesting a highlighting preview.
 * @param configuration  The configuration of the menu about to be displayed by this interaction.
 */
- (nullable UITargetedPreview *)contextMenuInteraction:(UIContextMenuInteraction *)interaction previewForHighlightingMenuWithConfiguration:(UIContextMenuConfiguration *)configuration;

/*!
 * @abstract Called when the interaction is about to dismiss. Return a UITargetedPreview describing the desired dismissal target.
 * The interaction will animate the presented menu to the target. Use this to customize the dismissal animation.
 *
 * @param interaction    The UIContextMenuInteraction requesting a dismissal preview.
 * @param configuration  The configuration of the menu displayed by this interaction.
 */
- (nullable UITargetedPreview *)contextMenuInteraction:(UIContextMenuInteraction *)interaction previewForDismissingMenuWithConfiguration:(UIContextMenuConfiguration *)configuration;

/*!
 * @abstract Called when the interaction is about to "commit" in response to the user tapping the preview.
 *
 * @param interaction  The UIContextMenuInteraction.
 * @param animator     Commit animator. Add animations to this object to run them alongside the commit transition.
 */
- (void)contextMenuInteraction:(UIContextMenuInteraction *)interaction willCommitWithAnimator:(id<UIContextMenuInteractionCommitAnimating>)animator;

/*!
 * @abstract Called when the interaction is about to present.
 *
 * @param interaction The UIContextMenuInteraction.
 */
- (void)contextMenuInteractionWillPresent:(UIContextMenuInteraction *)interaction;

/*!
 * @abstract Called when the interaction ends.
 *
 * @param interaction The UIContextMenuInteraction.
 */
- (void)contextMenuInteractionDidEnd:(UIContextMenuInteraction *)interaction;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIContextMenuInteraction.h>
#endif
