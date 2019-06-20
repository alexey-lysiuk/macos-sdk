//
//  INTicketedEvent.h
//  Intents
//
//  Copyright (c) 2016-2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Intents/INTicketedEventCategory.h>

@class CLPlacemark;
@class INDateComponentsRange;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), watchos(6.0))
API_UNAVAILABLE(macosx)
@interface INTicketedEvent : NSObject <NSCopying, NSSecureCoding>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCategory:(INTicketedEventCategory)category
                            name:(nullable NSString *)name
                   eventDuration:(nullable INDateComponentsRange *)eventDuration
                        location:(nullable CLPlacemark *)location NS_DESIGNATED_INITIALIZER;

@property (readonly, assign, NS_NONATOMIC_IOSONLY) INTicketedEventCategory category;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *name;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INDateComponentsRange *eventDuration;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) CLPlacemark *location;

@end

NS_ASSUME_NONNULL_END
