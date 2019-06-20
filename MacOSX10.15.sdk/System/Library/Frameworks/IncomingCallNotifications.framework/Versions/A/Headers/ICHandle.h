//
//  ICHandle.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <IncomingCallNotifications/ICBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ICHandleType) {
    ICHandleTypeGeneric = 1,
    ICHandleTypePhoneNumber = 2,
    ICHandleTypeEmailAddress = 3,
} API_AVAILABLE(ios(13.0));

IC_CLASS_AVAILABLE(ios(13.0))
@interface ICHandle : NSObject <NSCopying>

@property (nonatomic, readonly) ICHandleType type;
@property (nonatomic, readonly, copy) NSString *value;

- (instancetype)initWithType:(ICHandleType)type value:(NSString *)value NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isEqualToHandle:(ICHandle *)handle;

@end

NS_ASSUME_NONNULL_END
