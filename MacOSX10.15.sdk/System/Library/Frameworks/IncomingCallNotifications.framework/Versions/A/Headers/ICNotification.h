//
//  ICNotification.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <IncomingCallNotifications/ICBase.h>
#import <IncomingCallNotifications/ICTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class ICHandle;

IC_CLASS_AVAILABLE(ios(13.0))
@interface ICNotification : NSObject <NSCopying>

- (instancetype)initWithUUID:(NSUUID *)identifier handle:(ICHandle *)handle NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/// The unique identifier for this notification. This can be used to map this notification back to the sending call in your application.
@property (nonatomic, readonly, copy) NSUUID *identifier;

/// The handle for the person that will be displayed on the incoming call notification.
@property (nonatomic, readonly, copy) ICHandle *handle;

/// Whether or not this notification is for a call that supports video.
@property (nonatomic, readwrite, assign, getter=isVideo) BOOL video;

@end

NS_ASSUME_NONNULL_END
