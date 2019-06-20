//
//  ASAuthorizationAppleIDButton.h
//  AuthenticationServices Framework
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <AuthenticationServices/ASFoundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ASAuthorizationAppleIDButtonType) {
    ASAuthorizationAppleIDButtonTypeDefault = 0,
    ASAuthorizationAppleIDButtonTypeSignUp = 1,
    ASAuthorizationAppleIDButtonTypeContinue = 2
} NS_SWIFT_NAME(ButtonType) API_AVAILABLE(ios(13.0), tvos(13.0)) API_UNAVAILABLE(watchos) API_UNAVAILABLE(macos);


typedef NS_ENUM(NSInteger, ASAuthorizationAppleIDButtonStyle) {
    ASAuthorizationAppleIDButtonStyleWhite = 0,
    ASAuthorizationAppleIDButtonStyleWhiteOutline = 1,
    ASAuthorizationAppleIDButtonStyleBlack = 2
} NS_SWIFT_NAME(ButtonStyle) API_AVAILABLE(ios(13.0), tvos(13.0)) API_UNAVAILABLE(watchos) API_UNAVAILABLE(macos);


NS_ASSUME_NONNULL_BEGIN

AS_EXTERN API_AVAILABLE(ios(13.0), tvos(13.0)) API_UNAVAILABLE(watchos) API_UNAVAILABLE(macos)
@interface ASAuthorizationAppleIDButton : UIControl

+ (instancetype)buttonWithType:(ASAuthorizationAppleIDButtonType)type style:(ASAuthorizationAppleIDButtonStyle)style;

- (instancetype)initWithAuthorizationButtonType:(ASAuthorizationAppleIDButtonType)type authorizationButtonStyle:(ASAuthorizationAppleIDButtonStyle)style NS_DESIGNATED_INITIALIZER;

/*! @abstract Set a custom corner radius to be used by this button.
 */
@property (nonatomic, assign) IBInspectable CGFloat cornerRadius;

@end

NS_ASSUME_NONNULL_END
