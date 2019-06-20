//
//  ICNotificationManager.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <IncomingCallNotifications/ICBase.h>
#import <IncomingCallNotifications/ICTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class ICNotification;
@class ICNotificationManagerConfiguration;
@class ICNotificationManager;

@protocol ICNotificationManagerDelegate <NSObject>

@optional

/// Called when a notification is responded to by accepting it (e.g. choosing to accept the incoming call). Your application will be brought to the foreground and this callback will be invoked on the delegate.
- (void)notificationManager:(ICNotificationManager *)notificationManager didAcceptNotification:(ICNotification *)notification;

/// Called when a notification is responded to by declining it (e.g. the users declines the incoming call notification).
- (void)notificationManager:(ICNotificationManager *)notificationManager didDeclineNotification:(ICNotification *)notification reason:(ICDeclineReason)reason;

@end

IC_CLASS_AVAILABLE(ios(13.0))
@interface ICNotificationManager : NSObject

- (instancetype)initWithConfiguration:(ICNotificationManagerConfiguration *)configuration NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/// Set delegate and optional queue for delegate callbacks to be performed on.
/// A nil queue implies that delegate callbacks should happen on the main queue. The delegate is stored weakly
- (void)setDelegate:(nullable id<ICNotificationManagerDelegate>)delegate queue:(nullable dispatch_queue_t)queue;

/// Post an incoming call notification to the system. If there is an error posting the notification, the error will be set in the completion block.
- (void)postNotification:(ICNotification *)notification completion:(void (^_Nullable)(NSError *_Nullable))completion;

/// If an incoming call notification is currently being displayed with this identifier, this cancels the notification. The notification manager's delegate will also get called with a decline reason of ICDeclineReasonCancelled.
- (void)cancelNotificationWithIdentifier:(NSUUID *)identifier;

@end

NS_ASSUME_NONNULL_END
