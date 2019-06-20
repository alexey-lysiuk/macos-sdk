//
//  ICNotificationManagerConfiguration.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <IncomingCallNotifications/ICBase.h>
#import <IncomingCallNotifications/ICTypes.h>

NS_ASSUME_NONNULL_BEGIN

/// The configuration used for the notification manager. Each configuration is unique, so it is advised that you don't cache this configuration and use it for multiple notification manager instances. Instead, create a new one each time you initialize the notification manager.
IC_CLASS_AVAILABLE(ios(13.0))
@interface ICNotificationManagerConfiguration : NSObject <NSCopying>

/// The localized display name to use when showing the notification. If this is nil, the display name of your application will be used instead.
@property (nonatomic, readwrite, copy, nullable) NSString *localizedDisplayName;

@end

NS_ASSUME_NONNULL_END
