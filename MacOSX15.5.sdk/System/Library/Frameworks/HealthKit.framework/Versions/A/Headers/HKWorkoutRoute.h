//
//  HKWorkoutRoute.h
//  HealthKit
//
//  Copyright © 2017-2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>
#import <HealthKit/HKSeriesSample.h>

NS_ASSUME_NONNULL_BEGIN

HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(11.0), watchos(4.0), macCatalyst(13.0), macos(13.0))
@interface HKWorkoutRoute : HKSeriesSample
@end

NS_ASSUME_NONNULL_END
