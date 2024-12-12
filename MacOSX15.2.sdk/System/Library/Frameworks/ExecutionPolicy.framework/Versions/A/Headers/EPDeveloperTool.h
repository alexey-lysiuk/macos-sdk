//
//  EPDeveloperTool.h
//  ExecutionPolicy
//
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, EPDeveloperToolStatus) {
    EPDeveloperToolStatusNotDetermined = 0,
    EPDeveloperToolStatusRestricted,
    EPDeveloperToolStatusDenied,
    EPDeveloperToolStatusAuthorized,
} API_AVAILABLE(macos(10.15));


NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.15), macCatalyst(13.0))
@interface EPDeveloperTool : NSObject

/*
 @method init
 Initialization sets up the XPC connection backing most of the object's functionality.
 The XPC connection remains for the lifecycle of the object, as deallocation is
 required to trigger the teardown of the XPC connection.
 */
- (instancetype)init;

/*
 @property authorizationStatus
 The authorization status of the current process.

 @return An EPDeveloperToolStatus indicating whether the current process has developer tool privileges.
 */
@property (readonly) EPDeveloperToolStatus authorizationStatus;

/*
 @method requestDeveloperToolAccessWithCompletionHandler
 Requests developer tool privileges.

 @param handler A block called asynchronously with whether the privilege was granted.
 */
/// > Concurrency Note: You can call this method from synchronous code using a completion handler,
/// > as shown on this page, or you can call it as an asynchronous method that has the
/// > following declaration:
/// >
/// > ```swift
/// > func requestAccess() async -> Bool
/// > ```
/// >
/// > For information about concurrency and asynchronous code in Swift, see <doc://com.apple.documentation/documentation/swift/calling-objective-c-apis-asynchronously>.
- (void)requestDeveloperToolAccessWithCompletionHandler:(void (^)(BOOL granted))handler;

@end

NS_ASSUME_NONNULL_END
