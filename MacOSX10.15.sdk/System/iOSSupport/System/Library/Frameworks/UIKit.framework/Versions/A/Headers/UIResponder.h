#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIResponder.h>)
//
//  UIResponder.h
//  UIKit
//
//  Copyright (c) 2005-2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UIKeyCommand.h>
#import <UIKit/UIPasteConfigurationSupporting.h>
#import <UIKit/UIUserActivity.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UICommandBuilder;

@class UICommandValidation;
@class UIPress;
@class UIPressesEvent;

typedef NSDictionary<NSAttributedStringKey, id> * _Nonnull(^UITextAttributesConversionHandler)(NSDictionary<NSAttributedStringKey, id> * _Nonnull);

@protocol UIResponderStandardEditActions <NSObject>
@optional
- (void)cut:(nullable id)sender API_AVAILABLE(ios(3.0));
- (void)copy:(nullable id)sender API_AVAILABLE(ios(3.0));
- (void)paste:(nullable id)sender API_AVAILABLE(ios(3.0));
- (void)select:(nullable id)sender API_AVAILABLE(ios(3.0));
- (void)selectAll:(nullable id)sender API_AVAILABLE(ios(3.0));
- (void)delete:(nullable id)sender API_AVAILABLE(ios(3.2));
- (void)makeTextWritingDirectionLeftToRight:(nullable id)sender API_AVAILABLE(ios(5.0));
- (void)makeTextWritingDirectionRightToLeft:(nullable id)sender API_AVAILABLE(ios(5.0));
- (void)toggleBoldface:(nullable id)sender API_AVAILABLE(ios(6.0));
- (void)toggleItalics:(nullable id)sender API_AVAILABLE(ios(6.0));
- (void)toggleUnderline:(nullable id)sender API_AVAILABLE(ios(6.0));

- (void)increaseSize:(nullable id)sender API_AVAILABLE(ios(7.0));
- (void)decreaseSize:(nullable id)sender API_AVAILABLE(ios(7.0));

- (void)updateTextAttributesWithConversionHandler:(NS_NOESCAPE UITextAttributesConversionHandler _Nonnull)conversionHandler API_AVAILABLE(ios(13.0));

@end

UIKIT_EXTERN API_AVAILABLE(ios(2.0)) @interface UIResponder : NSObject <UIResponderStandardEditActions>

@property(nonatomic, readonly, nullable) UIResponder *nextResponder;

@property(nonatomic, readonly) BOOL canBecomeFirstResponder;    // default is NO
- (BOOL)becomeFirstResponder;

@property(nonatomic, readonly) BOOL canResignFirstResponder;    // default is YES
- (BOOL)resignFirstResponder;

@property(nonatomic, readonly) BOOL isFirstResponder;

// Generally, all responders which do custom touch handling should override all four of these methods.
// Your responder will receive either touchesEnded:withEvent: or touchesCancelled:withEvent: for each
// touch it is handling (those touches it received in touchesBegan:withEvent:).
// *** You must handle cancelled touches to ensure correct behavior in your application.  Failure to
// do so is very likely to lead to incorrect behavior or crashes.
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;
- (void)touchesEstimatedPropertiesUpdated:(NSSet<UITouch *> *)touches API_AVAILABLE(ios(9.1));

// Generally, all responders which do custom press handling should override all four of these methods.
// Your responder will receive either pressesEnded:withEvent or pressesCancelled:withEvent: for each
// press it is handling (those presses it received in pressesBegan:withEvent:).
// pressesChanged:withEvent: will be invoked for presses that provide an analog value
// (like thumbsticks or analog push buttons)
// *** You must handle cancelled presses to ensure correct behavior in your application.  Failure to
// do so is very likely to lead to incorrect behavior or crashes.
- (void)pressesBegan:(NSSet<UIPress *> *)presses withEvent:(nullable UIPressesEvent *)event API_AVAILABLE(ios(9.0));
- (void)pressesChanged:(NSSet<UIPress *> *)presses withEvent:(nullable UIPressesEvent *)event API_AVAILABLE(ios(9.0));
- (void)pressesEnded:(NSSet<UIPress *> *)presses withEvent:(nullable UIPressesEvent *)event API_AVAILABLE(ios(9.0));
- (void)pressesCancelled:(NSSet<UIPress *> *)presses withEvent:(nullable UIPressesEvent *)event API_AVAILABLE(ios(9.0));

- (void)motionBegan:(UIEventSubtype)motion withEvent:(nullable UIEvent *)event API_AVAILABLE(ios(3.0));
- (void)motionEnded:(UIEventSubtype)motion withEvent:(nullable UIEvent *)event API_AVAILABLE(ios(3.0));
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(nullable UIEvent *)event API_AVAILABLE(ios(3.0));

- (void)remoteControlReceivedWithEvent:(nullable UIEvent *)event API_AVAILABLE(ios(4.0));

- (BOOL)canPerformAction:(SEL)action withSender:(nullable id)sender API_AVAILABLE(ios(3.0));
// Allows an action to be forwarded to another target. By default checks -canPerformAction:withSender: to either return self, or go up the responder chain.
- (nullable id)targetForAction:(SEL)action withSender:(nullable id)sender API_AVAILABLE(ios(7.0));

// Overrides for command building and validation
- (void)buildCommandsWithBuilder:(id<UICommandBuilder>)builder;
- (void)validateCommand:(UIMutableCommand *)command;

/** START OF V1 API, TO REMOVE **/
- (UICommandValidation *)validationForCommand:(UICommand *)command API_DEPRECATED_WITH_REPLACEMENT("validateCommand:", ios(13.0, 13.0));
/** END OF V1 API, TO REMOVE **/

@property(nullable, nonatomic,readonly) NSUndoManager *undoManager API_AVAILABLE(ios(3.0));

@end

@interface UIResponder (UIResponderKeyCommands)
@property (nullable,nonatomic,readonly) NSArray<UIKeyCommand *> *keyCommands API_AVAILABLE(ios(7.0)); // returns an array of UIKeyCommand objects<
@end

@class UIInputViewController;
@class UITextInputMode;
@class UITextInputAssistantItem;

@interface UIResponder (UIResponderInputViewAdditions)

// Called and presented when object becomes first responder.  Goes up the responder chain.
@property (nullable, nonatomic, readonly, strong) __kindof UIView *inputView API_AVAILABLE(ios(3.2));
@property (nullable, nonatomic, readonly, strong) __kindof UIView *inputAccessoryView API_AVAILABLE(ios(3.2));

/// This method is for clients that wish to put buttons on the Shortcuts Bar, shown on top of the keyboard.
/// You may modify the returned inputAssistantItem to add to or replace the existing items on the bar.
/// Modifications made to the returned UITextInputAssistantItem are reflected automatically.
/// This method should not be overridden. Goes up the responder chain.
@property (nonnull, nonatomic, readonly, strong) UITextInputAssistantItem *inputAssistantItem API_AVAILABLE(ios(9.0)) API_UNAVAILABLE(tvos) API_UNAVAILABLE(watchos);

// For viewController equivalents of -inputView and -inputAccessoryView
// Called and presented when object becomes first responder.  Goes up the responder chain.
@property (nullable, nonatomic, readonly, strong) UIInputViewController *inputViewController API_AVAILABLE(ios(8.0));
@property (nullable, nonatomic, readonly, strong) UIInputViewController *inputAccessoryViewController API_AVAILABLE(ios(8.0));

/* When queried, returns the current UITextInputMode, from which the keyboard language can be determined.
 * When overridden it should return a previously-queried UITextInputMode object, which will attempt to be
 * set inside that app, but not persistently affect the user's system-wide keyboard settings. */
@property (nullable, nonatomic, readonly, strong) UITextInputMode *textInputMode API_AVAILABLE(ios(7.0));
/* When the first responder changes and an identifier is queried, the system will establish a context to
 * track the textInputMode automatically. The system will save and restore the state of that context to
 * the user defaults via the app identifier. Use of -textInputMode above will supersede use of -textInputContextIdentifier. */
@property (nullable, nonatomic, readonly, strong) NSString *textInputContextIdentifier API_AVAILABLE(ios(7.0));
// This call is to remove stored app identifier state that is no longer needed.
+ (void)clearTextInputContextIdentifier:(NSString *)identifier API_AVAILABLE(ios(7.0));

// If called while object is first responder, reloads inputView, inputAccessoryView, and textInputMode.  Otherwise ignored.
- (void)reloadInputViews API_AVAILABLE(ios(3.2));

@end

// These are pre-defined constants for use with the input property of UIKeyCommand objects.
UIKIT_EXTERN NSString *const UIKeyInputUpArrow         API_AVAILABLE(ios(7.0));
UIKIT_EXTERN NSString *const UIKeyInputDownArrow       API_AVAILABLE(ios(7.0));
UIKIT_EXTERN NSString *const UIKeyInputLeftArrow       API_AVAILABLE(ios(7.0));
UIKIT_EXTERN NSString *const UIKeyInputRightArrow      API_AVAILABLE(ios(7.0));
UIKIT_EXTERN NSString *const UIKeyInputEscape          API_AVAILABLE(ios(7.0));

@interface UIResponder (ActivityContinuation) <UIUserActivityRestoring>
@property (nullable, nonatomic, strong) NSUserActivity *userActivity API_AVAILABLE(ios(8.0));
- (void)updateUserActivityState:(NSUserActivity *)activity API_AVAILABLE(ios(8.0));
- (void)restoreUserActivityState:(NSUserActivity *)activity API_AVAILABLE(ios(8.0));
@end

#if TARGET_OS_IOS
@interface UIResponder (UIPasteConfigurationSupporting) <UIPasteConfigurationSupporting>
@end
#endif

NS_ASSUME_NONNULL_END


#else
#import <UIKitCore/UIResponder.h>
#endif
