//
//  ASAuthorizationProviderExtensionRegistrationHandler.h
//  AuthenticationServices Framework
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ASAuthorizationProviderExtensionLoginManager;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
typedef NS_ENUM(NSInteger, ASAuthorizationProviderExtensionAuthenticationMethod)
{
    ASAuthorizationProviderExtensionAuthenticationMethodPassword = 1,
    ASAuthorizationProviderExtensionAuthenticationMethodUserSecureEnclaveKey = 2,
    ASAuthorizationProviderExtensionAuthenticationMethodSmartCard API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos) = 3,
} API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos);

API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
typedef NS_OPTIONS(NSUInteger, ASAuthorizationProviderExtensionRequestOptions) {
    // No Options.
    ASAuthorizationProviderExtensionRequestOptionsNone = 0,
    // User interaction is enabled.
    ASAuthorizationProviderExtensionRequestOptionsUserInteractionEnabled = 1 << 0,
    // The registration is called to repair a previous registration.
    ASAuthorizationProviderExtensionRequestOptionsRegistrationRepair = 1 << 1,
    // The registration is using shared device keys.
    ASAuthorizationProviderExtensionRequestOptionsRegistrationSharedDeviceKeys API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos) = 1 << 2,
    // The registration is changing to or from shared device keys.
    ASAuthorizationProviderExtensionRequestOptionsRegistrationDeviceKeyMigration API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos) = 1 << 3,
};

typedef NS_ENUM(NSInteger, ASAuthorizationProviderExtensionRegistrationResult)
{
    // The registration was successful.
    ASAuthorizationProviderExtensionRegistrationResultSuccess = 0,
    // The registration failed, try again later.
    ASAuthorizationProviderExtensionRegistrationResultFailed = 1,
    // User interface is required to complete the registration.
    ASAuthorizationProviderExtensionRegistrationResultUserInterfaceRequired = 2,
    // The registration failed, do not retry.
    ASAuthorizationProviderExtensionRegistrationResultFailedNoRetry = 3,
} API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos);


typedef NS_OPTIONS(NSInteger, ASAuthorizationProviderExtensionSupportedGrantTypes) {
    // None
    ASAuthorizationProviderExtensionSupportedGrantTypesNone = 0,
    // password grant type
    ASAuthorizationProviderExtensionSupportedGrantTypesPassword = 1 << 0,
    // jwt-bearer
    ASAuthorizationProviderExtensionSupportedGrantTypesJWTBearer = 1 << 1,
    // SAML 1.1
    ASAuthorizationProviderExtensionSupportedGrantTypesSAML1_1 NS_SWIFT_NAME(saml1_1) = 1 << 2 ,
    // SAML 2.0
    ASAuthorizationProviderExtensionSupportedGrantTypesSAML2_0 NS_SWIFT_NAME(saml2_0) = 1 << 3,
} API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos);

typedef NS_ENUM(NSInteger, ASAuthorizationProviderExtensionPlatformSSOProtocolVersion) {
    // Version 1.0
    ASAuthorizationProviderExtensionPlatformSSOProtocolVersion1_0 = 0,
    // Version 2.0
    ASAuthorizationProviderExtensionPlatformSSOProtocolVersion2_0 = 1,
} API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos);


API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
@protocol ASAuthorizationProviderExtensionRegistrationHandler <NSObject>

/*!
 @abstract This initiates device registration process for the SSO extension.
 @param loginManager The login manager used to interface with Platform SSO.
 @param options The request options that apply to the request.
 @param completion The completion to call to continue device registration.
 @param result Return the result of the registration.
 */
- (void)beginDeviceRegistrationUsingLoginManager:(ASAuthorizationProviderExtensionLoginManager *)loginManager options:(ASAuthorizationProviderExtensionRequestOptions)options completion:(void (^)(ASAuthorizationProviderExtensionRegistrationResult result))completion NS_SWIFT_NAME(beginDeviceRegistration(loginManager:options:completion:));

/*!
 @abstract This initiates user registration process for the user and the extension.
 @param loginManager The login manager used to interface with Platform SSO.
 @param userName The username for the user registration.
 @param method The authentication method to be used for the user.
 @param options The request options that apply to the request.
 @param completion The completion to call to continue user registration.
 @param result Return the result of the registration.
 */
- (void)beginUserRegistrationUsingLoginManager:(ASAuthorizationProviderExtensionLoginManager *)loginManager userName:(nullable NSString *)userName authenticationMethod:(ASAuthorizationProviderExtensionAuthenticationMethod)authenticationMethod options:(ASAuthorizationProviderExtensionRequestOptions)options completion:(void (^)(ASAuthorizationProviderExtensionRegistrationResult result))completion NS_SWIFT_NAME(beginUserRegistration(loginManager:userName:method:options:completion:));

@optional

/// @abstract Call to extension to free any resources used by the extension during registration. It will be called once after all current registration calls are complete.
- (void)registrationDidComplete;

/// @abstract Call to extension when the registration has been cancelled.
- (void)registrationDidCancel API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos);


/*!
 @abstract The grant types supported by the identity provider.
 */
- (ASAuthorizationProviderExtensionSupportedGrantTypes)supportedGrantTypes API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The protocol version supported by the identity provider.
 */
- (ASAuthorizationProviderExtensionPlatformSSOProtocolVersion)protocolVersion API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(ios, watchos, tvos);


@end

NS_ASSUME_NONNULL_END
