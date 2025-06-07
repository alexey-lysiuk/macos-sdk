//
//  INEditMessageIntentResponse.h
//  Intents
//
//  Copyright (c) 2016-2024 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

typedef NS_ENUM(NSInteger, INEditMessageIntentResponseCode) {
    INEditMessageIntentResponseCodeUnspecified = 0,
    INEditMessageIntentResponseCodeReady,
    INEditMessageIntentResponseCodeInProgress,
    INEditMessageIntentResponseCodeSuccess,
    INEditMessageIntentResponseCodeFailure,
    INEditMessageIntentResponseCodeFailureRequiringAppLaunch,
    INEditMessageIntentResponseCodeFailureMessageNotFound,
    INEditMessageIntentResponseCodeFailurePastEditTimeLimit,
    INEditMessageIntentResponseCodeFailureMessageTypeUnsupported,
    INEditMessageIntentResponseCodeFailureUnsupportedOnService,
    INEditMessageIntentResponseCodeFailureMessageServiceNotAvailable,
    INEditMessageIntentResponseCodeFailureRequiringInAppAuthentication API_AVAILABLE(macos(14.0)) API_UNAVAILABLE(tvos),
} API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0)) API_UNAVAILABLE(tvos);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0))
API_UNAVAILABLE(tvos)
@interface INEditMessageIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INEditMessageIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INEditMessageIntentResponseCode code;

@end

NS_ASSUME_NONNULL_END
