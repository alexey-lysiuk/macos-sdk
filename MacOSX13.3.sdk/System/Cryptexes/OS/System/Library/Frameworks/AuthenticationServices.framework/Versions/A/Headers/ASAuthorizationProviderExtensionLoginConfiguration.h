// Copyright © 2021 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
@interface ASAuthorizationProviderExtensionKerberosMapping : NSObject

/*!
 @abstract The keypath in the response JSON that uses this set of mappings.
 @discussion If the response tokens from login contain this keypath, then the mapping in this class will be used to create a Kerberos ticket. The expected response is a JSON dictionary with the supplied key names.
 */
@property (nonatomic, nullable, copy) NSString *ticketKeyPath;

/*!
 @abstract The key name that contains the base64 encoded kerberos AS-REP string.
 */
@property (nonatomic, nullable, copy) NSString *messageBufferKeyName;

/*!
 @abstract The key name that contains the Kerberos Realm string.
 */
@property (nonatomic, nullable, copy) NSString *realmKeyName;

/*!
 @abstract The key name that contains the Kerberos service name string.
 */
@property (nonatomic, nullable, copy) NSString *serviceNameKeyName;

/*!
 @abstract The key name that contains the Kerberos client name string.
 */
@property (nonatomic, nullable, copy) NSString *clientNameKeyName;

/*!
 @abstract The key name that contains the Kerberos session key type number.
 @discussion The value for this key should be the correct encryption type per RFC3962, section 7 for the session key.
 */
@property (nonatomic, nullable, copy) NSString *encryptionKeyTypeKeyName;

/*!
 @abstract The key name that contains the Kerberos session key.
 */
@property (nonatomic, nullable, copy) NSString *sessionKeyKeyName;

@end

API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos)
typedef NS_ENUM(NSInteger, ASAuthorizationProviderExtensionFederationType)
{
    ASAuthorizationProviderExtensionFederationTypeNone = 0,
    ASAuthorizationProviderExtensionFederationTypeWSTrust = 1,
    ASAuthorizationProviderExtensionFederationTypeDynamicWSTrust = 2,
}  NS_SWIFT_NAME(ASAuthorizationProviderExtensionLoginConfiguration.FederationType);

API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, watchos, tvos)
@interface ASAuthorizationProviderExtensionLoginConfiguration : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 @abstract Initializes an ASAuthorizationProviderExtensionLoginConfiguration class with the required values.
 @param clientID The client_id for the Apple platform SSO login at the identity provider.
 @param issuer The issuer for the requests, used to validate responses.
 @param tokenEndpointURL The token endpoint at the idP for login.
 @param jwksEndpointURL The JWKS URL at the idP for validating tokens.
 @param audience The audience used for signed assertions.  This should be the tenent at the idP.
 @return An instance of a ASAuthorizationProviderExtensionLoginConfiguration.
 */
- (instancetype)initWithClientID:(NSString *)clientID issuer:(NSString *)issuer tokenEndpointURL:(NSURL *)tokenEndpointURL jwksEndpointURL:(NSURL *)jwksEndpointURL audience:(nullable NSString *)audience;

/*!
 @abstract Creates a login configuration using the OpenID configuration.
 @param openIDConfigurationURL The base URL to load the .well-known/openid-configuration.
 @param clientID The client_id for the Apple platform SSO login at the identity provider.
 @param issuer The issuer for the requests, used to validate responses.
 @param completion The completion called when it is complete or the error.
 */
+ (void)configurationWithOpenIDConfigurationURL:(NSURL *)openIDConfigurationURL clientID:(NSString *)clientID issuer:(nullable NSString *)issuer completion:(void (^)(ASAuthorizationProviderExtensionLoginConfiguration * _Nullable loginConfiguration, NSError * _Nullable error))completion NS_SWIFT_NAME(configuration(openIDConfigurationURL:clientID:issuer:completion:));

/*!
 @abstract Predicate string used to identify invalid credential errors.
 @discussion If there is an HTTP 400 or HTTP 401 error when authenticating, this predicate will be used on the response body JSON to determine if the error is due to an invalid password or something else.  If nil, then only an HTTP 401 will be used for an invalid credential.
 */
@property (nonatomic, nullable, copy) NSString *invalidCredentialPredicate;

/*!
 @abstract The display name for the account.  Used for notifications and login prompts.
 */
@property (nonatomic, nullable, copy) NSString *accountDisplayName;

/*!
 @abstract The login client_id.
 */
@property (nonatomic, readonly, copy) NSString *clientID;

/*!
 @abstract The issuer for validation.
 */
@property (nonatomic, readonly, copy) NSString *issuer;

/*!
 @abstract The audience for validation and requests.
 */
@property (nonatomic, copy) NSString *audience;

/*!
 @abstract Token Endpoint URL for login request.
 */
@property (nonatomic, copy) NSURL *tokenEndpointURL;

/*!
 @abstract JWKS Endpoint URL for keys.
 */
@property (nonatomic, copy) NSURL *jwksEndpointURL;

#pragma mark - Server Nonce

/*!
 @abstract Nonce Endpoint URL, defaults to token tokenEndpointURL.
 */
@property (nonatomic, copy) NSURL *nonceEndpointURL;

/*!
 @abstract The keypath in the nonce response that contains the nonce value.
 */
@property (nonatomic, copy) NSString *nonceResponseKeypath;

/*!
 @abstract The name of the server nonce claim when included in authentication requests.
 */
@property (nonatomic, copy) NSString *serverNonceClaimName;

/*!
 @abstract Custom values added to the server nonce POST request body.
 */
@property (nonatomic, copy) NSArray<NSURLQueryItem *> *customNonceRequestValues;

#pragma mark - Embedded Assertions

/*!
 @abstract Sets custom claims to be added to the embedded assertion request header.
 @param claims The claims to be added. It must serialize as valid JSON to be accepted.
 @param error Nil or a NSError indicating why the claims where rejected.
 @returns True when successful and false when claims are rejected.
 */
- (BOOL)setCustomAssertionRequestHeaderClaims:(NSDictionary<NSString *, id> *)claims returningError:(NSError * _Nullable * _Nullable)error;

/*!
 @abstract Sets custom claims to be added to the embedded assertion request body.
 @param claims The claims to be added. It must serialize as valid JSON to be accepted.
 @param error Nil or a NSError indicating why the claims where rejected.
 @returns True when successful and false when claims are rejected.
 */
- (BOOL)setCustomAssertionRequestBodyClaims:(NSDictionary<NSString *, id> *)claims returningError:(NSError * _Nullable * _Nullable)error;

#pragma mark - Login Request

/*!
 @abstract Additional login scopes.
 */
@property (nonatomic, copy) NSString *additionalScopes;

/*!
 @abstract If true and there is a refresh token for the user in the SSO tokens, it will be included in the login request.
 */
@property (nonatomic) BOOL includePreviousRefreshTokenInLoginRequest;

/*!
 @abstract The claim name for the previous SSO token value in the login request.
 */
@property (nonatomic, copy) NSString *previousRefreshTokenClaimName;

/*!
 @abstract Custom values added to the login POST request body.
 */
@property (nonatomic, copy) NSArray<NSURLQueryItem *> *customLoginRequestValues;

/*!
 @abstract Sets custom claims to be added to the login request header.
 @param claims The claims to be added. It must serialize as valid JSON to be accepted.
 @param error Nil or a NSError indicating why the claims where rejected.
 @returns True when successful and false when claims are rejected.
 */
- (BOOL)setCustomLoginRequestHeaderClaims:(NSDictionary<NSString *, id> *)claims returningError:(NSError * _Nullable * _Nullable) error;

/*!
 @abstract Sets custom claims to be added to the login request body.
 @param claims The claims to be added. It must serialize as valid JSON to be accepted.
 @param error Nil or a NSError indicating why the claims where rejected.
 @returns True when successful and false when claims are rejected.
 */
- (BOOL)setCustomLoginRequestBodyClaims:(NSDictionary<NSString *, id> *)claims returningError:(NSError * _Nullable * _Nullable) error;

/*!
 @abstract The Kerberos ticket mappings to use.
 */
@property (nonatomic, copy) NSArray<ASAuthorizationProviderExtensionKerberosMapping *> *kerberosTicketMappings;


// MARK: - Federation

/*!
 @abstract The federation method to use.
 */
@property (nonatomic) ASAuthorizationProviderExtensionFederationType federationType API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The URN to request when performing a federated login.
 */
@property (nonatomic, nullable, copy) NSString *federationRequestURN API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The federation MEX URL to use.  This can be overwritten when using dynamic federation.
 */
@property (nonatomic, nullable, copy) NSURL *federationMEXURL API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The URL to use when performing dynamic federation.
 */
@property (nonatomic, nullable, copy) NSURL *federationUserPreauthenticationURL API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The claim in the preauthentication response that contains the MEX URL.
 */
@property (nonatomic, nullable, copy) NSString *federationMEXURLKeypath API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The predicate to apply to the preauthentication response to perform federation or not.
 */
@property (nonatomic, nullable, copy) NSString *federationPredicate API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

/*!
 @abstract The custom query string values to add when making the preauthenticaion request.
 */
@property (nonatomic, copy) NSArray<NSURLQueryItem *> *customFederationUserPreauthenticationRequestValues API_AVAILABLE(macos(13.3)) API_UNAVAILABLE(ios, watchos, tvos);

@end

NS_ASSUME_NONNULL_END
