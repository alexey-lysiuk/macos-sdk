//
//  NSFileProviderRequest.h
//  FileProvider
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <FileProvider/NSFileProviderExtension.h>
#import <FileProvider/NSFileProviderManager.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), macos(10.15)) API_UNAVAILABLE(watchos, tvos)
@interface NSFileProviderRequest : NSObject
/**
 An identifier for the application. The identifier is system-specific and may
 change between different installations of the application.
 */
@property (nonatomic, readonly, strong) NSUUID *requestingApplicationIdentifier;

/**
 The following properties are available only after user opt-in, via the
 -requestPresenceAuthorization method on NSFileProviderManager.
 */
@property (nonatomic, readonly, copy, nullable) NSURL *requestingExecutable API_UNAVAILABLE(ios);

@end

@interface NSFileProviderExtension (Request)
- (nullable NSFileProviderRequest *)currentRequest API_AVAILABLE(ios(13.0), macos(10.15)) API_UNAVAILABLE(watchos, tvos);
@end


typedef NS_ENUM(NSUInteger, NSFileProviderPresenceAuthorizationStatus) {
    NSFileProviderPresenceAuthorizationNotDetermined,
    NSFileProviderPresenceAuthorizationRestricted,
    NSFileProviderPresenceAuthorizationDenied,
    NSFileProviderPresenceAuthorizationAllowed
};

@interface NSFileProviderManager (Presence)

@property (nonatomic, assign, readonly) NSFileProviderPresenceAuthorizationStatus presenceAuthorizationStatus API_UNAVAILABLE(ios);

/**
 If (presenceAuthorizationStatus == NSFileProviderPresenceAuthorizationNotDetermined),
 presents a dialog requesting authorization to share additional information
 about requests with the provider.

 The authorization dialog will display the contents of the
 NSFileProviderPresenceUsageDescription key.  The key must be present in the
 app's Info.plist.
 */
- (void)requestPresenceAuthorization API_UNAVAILABLE(ios);

@end

NS_ASSUME_NONNULL_END
