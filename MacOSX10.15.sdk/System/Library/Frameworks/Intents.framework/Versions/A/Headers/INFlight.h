//
//  INFlight.h
//  Intents
//
//  Copyright (c) 2016-2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class INAirline;
@class INAirportGate;
@class INDateComponentsRange;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), watchos(6.0))
API_UNAVAILABLE(macosx)
@interface INFlight : NSObject <NSCopying, NSSecureCoding>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithAirline:(nullable INAirline *)airline
                   flightNumber:(nullable NSString *)flightNumber
                   boardingTime:(nullable INDateComponentsRange *)boardingTime
                 flightDuration:(nullable INDateComponentsRange *)flightDuration
           departureAirportGate:(nullable INAirportGate *)departureAirportGate
             arrivalAirportGate:(nullable INAirportGate *)arrivalAirportGate NS_DESIGNATED_INITIALIZER;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INAirline *airline;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *flightNumber;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INDateComponentsRange *boardingTime;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INDateComponentsRange *flightDuration;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INAirportGate *departureAirportGate;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INAirportGate *arrivalAirportGate;

@end

NS_ASSUME_NONNULL_END
