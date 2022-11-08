//
//  ASAuthorizationProviderExtensionLoginManager.h
//  AuthenticationServices Framework
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

@class ASAuthorizationProviderExtensionLoginConfiguration;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ASAuthorizationProviderExtensionKeyType)
{
    /// The user's device signing key.
    ASAuthorizationProviderExtensionKeyTypeUserDeviceSigning = 1,
    /// The user's device encryption key.
    ASAuthorizationProviderExtensionKeyTypeUserDeviceEncryption = 2,
    /// The user's Secure Enclave backed key.
    ASAuthorizationProviderExtensionKeyTypeUserSecureEnclaveKey = 3,
} API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos);

API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
@interface ASAuthorizationProviderExtensionLoginManager : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// @abstract Returns YES if the current device completed registration.
@property (readonly, getter=isDeviceRegistered) BOOL deviceRegistered;

/// @abstract Returns YES if current user completed registration.
@property (readonly, getter=isUserRegistered) BOOL userRegistered;

/// @abstract Returns the device registration token from the MDM profile.
@property (nonatomic, nullable, readonly, copy) NSString *registrationToken;

/// @abstract The user name to use when authenticating with the identity provider.
@property (nonatomic, nullable, copy) NSString *loginUserName;

/// @abstract Retrieves or sets the current SSO tokens response for the current user and extension.
@property (nonatomic, copy, nullable) NSDictionary *ssoTokens;

/// @abstract Retrieves or sets the current login configuration for the extension.
@property (nonatomic, copy, nullable, readonly) ASAuthorizationProviderExtensionLoginConfiguration *loginConfiguration;

/// Saves or replaces the login configration.
/// @param loginConfiguration The login configration to use.
/// @param error The error when there are validation errors or nil.
- (BOOL)saveLoginConfiguration:(ASAuthorizationProviderExtensionLoginConfiguration *)loginConfiguration error:(NSError * _Nullable * _Nullable)error;

/// @abstract Saves the provided certificate for the key type.
/// @param certificate The certificate to save.
/// @param keyType The key type for the certificate.
- (void)saveCertificate:(SecCertificateRef)certificate keyType:(ASAuthorizationProviderExtensionKeyType)keyType NS_SWIFT_NAME(saveCertificate(_:keyType:));

/// @abstract Retrieves the key for the specified platform SSO key type.
/// @param keyType The key type to retrieve.
- (nullable SecKeyRef)copyKeyForKeyType:(ASAuthorizationProviderExtensionKeyType)keyType NS_SWIFT_NAME(key(for:)) CF_RETURNS_RETAINED;

/// @abstract Retrieves the identity for the specified platform SSO key type.
/// @param keyType The key type to retrieve.
- (nullable SecIdentityRef)copyIdentityForKeyType:(ASAuthorizationProviderExtensionKeyType)keyType NS_SWIFT_NAME(identity(for:)) CF_RETURNS_RETAINED;

/// @abstract Requests AppSSOAgent reauthenticate the current user for the current extension.  This is used when the tokens are revoked, or expired and need to be requested again.
- (void)userNeedsReauthenticationWithCompletion:(void(^)(NSError * _Nullable error))completion;

/// @abstract Requests that the device registration be run again to repair it.
- (void)deviceRegistrationsNeedsRepair;

/// @abstract Requests that user registration be run again for the current user to repair it.
- (void)userRegistrationsNeedsRepair;

/// @abstract Creates new Encryption, Signing, and Secure Enclave keys for the user.  The old keys will be destroyed.
- (void)resetKeys;

/*! @abstract Asks authorization service to show extension view controller for registration. If the controller cannot be shown an error is returned.  This is only valid during registration.
*/
- (void)presentRegistrationViewControllerWithCompletion:(void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
