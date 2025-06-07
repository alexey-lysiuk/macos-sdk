/*
 *  CLRegion.h
 *  CoreLocation
 *
 *  Copyright (c) 2009-2010 Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLAvailability.h>

NS_ASSUME_NONNULL_BEGIN

/*
 * CLRegionState
 *
 * Discussion:
 *    Represents the current state of the device with reference to a region.
 *
 */
typedef NS_CLOSED_ENUM(NSInteger, CLRegionState) {
	CLRegionStateUnknown,
	CLRegionStateInside,
	CLRegionStateOutside
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
} API_AVAILABLE(macos(10.10), ios(7.0)) API_UNAVAILABLE(watchos, tvos, visionos);
#else
} API_AVAILABLE(macos(10.10), ios(7.0)) API_UNAVAILABLE(watchos, tvos);
#endif

/*
 * CLProximity
 *
 * Discussion:
 *    Represents the current proximity of an entity.
 *
 */
typedef NS_ENUM(NSInteger, CLProximity) {
	CLProximityUnknown,
	CLProximityImmediate,
	CLProximityNear,
	CLProximityFar
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
} API_AVAILABLE(ios(7.0), macos(10.15)) API_UNAVAILABLE(watchos, tvos, visionos);
#else
} API_AVAILABLE(ios(7.0), macos(10.15)) API_UNAVAILABLE(watchos, tvos);
#endif

/*
 *  CLRegion
 *  
 *  Discussion:
 *    A logical area.
 */
CL_EXTERN
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
API_AVAILABLE(macos(10.7), ios(4.0)) API_UNAVAILABLE(visionos)
#else
API_AVAILABLE(macos(10.7), ios(4.0))
#endif
@interface CLRegion : NSObject <NSCopying, NSSecureCoding>
/*
 *  initCircularRegionWithCenter:radius:identifier:
 *  
 *  Discussion:
 *    Initialize a region.  center gives the coordinates of center of the region, while radius gives
 *    the distance in meters between the center and the region's boundary. identifier is a description
 *    for the region that could be displayed to the user, and ideally should be chosen by the user.
 *
 *    This method has been deprecated, please see CLCircularRegion.
 */
- (instancetype)initCircularRegionWithCenter:(CLLocationCoordinate2D)center
									  radius:(CLLocationDistance)radius
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
								  identifier:(NSString *)identifier API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos, visionos);
#else
								  identifier:(NSString *)identifier API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos);
#endif
/*
 *  center
 *  
 *  Discussion:
 *    Returns the coordinate of the center of the region.
 *
 *    This method has been deprecated, please see CLCircularRegion.
 */
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
@property (readonly, atomic) CLLocationCoordinate2D center API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos, visionos);
#else
@property (readonly, atomic) CLLocationCoordinate2D center API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos);
#endif
/*
 *  radius
 *  
 *  Discussion:
 *    Returns the radius of the region.
 *
 *    This method has been deprecated, please see CLCircularRegion.
 */
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
@property (readonly, atomic) CLLocationDistance radius API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos, visionos);
#else
@property (readonly, atomic) CLLocationDistance radius API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos);
#endif
/*
 *  identifier
 *  
 *  Discussion:
 *    Returns the region's identifier.
 */
@property (readonly, nonatomic, copy) NSString *identifier API_AVAILABLE(ios(4.0), macos(10.7));

/*
 *  notifyOnEntry
 *
 *  Discussion:
 *    App will be launched and the delegate will be notified via locationManager:didEnterRegion:
 *    when the user enters the region. By default, this is YES.
 */
@property (atomic, assign) BOOL notifyOnEntry API_AVAILABLE(ios(7.0), macos(10.10));

/*
 *  notifyOnExit
 *
 *  Discussion:
 *    App will be launched and the delegate will be notified via locationManager:didExitRegion:
 *    when the user exits the region. By default, this is YES.
 */
@property (atomic, assign) BOOL notifyOnExit API_AVAILABLE(ios(7.0), macos(10.10));

/*
 *  containsCoordinate:
 *
 *  Discussion:
 *    Returns YES if the coordinate lies inside the region, and NO otherwise.
 *
 *    This method has been deprecated, please see CLCircularRegion.
 */
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coordinate API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos, visionos);
#else
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coordinate API_DEPRECATED("Please see CLCircularRegion", ios(4.0, 7.0), macos(10.7, 10.10)) API_UNAVAILABLE(tvos);
#endif
@end

NS_ASSUME_NONNULL_END
