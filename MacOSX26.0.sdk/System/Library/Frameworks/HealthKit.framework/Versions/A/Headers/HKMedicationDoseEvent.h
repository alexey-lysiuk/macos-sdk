//
//  HKMedicationDoseEvent.h
//  HealthKit
//
//  Copyright © 2025 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>
#import <HealthKit/HKSample.h>

@class HKHealthConceptIdentifier;
@class HKUnit;
@class HKMedicationDoseEventType;

NS_ASSUME_NONNULL_BEGIN

/*!
 @enum          HKMedicationDoseEventLogStatus
 @abstract      The possible statuses of a logged HKMedicationDoseEvent
 
 @constant      HKMedicationDoseEventLogStatusNotInteracted             User has not logged information for a scheduled medication. System generated status.
 @constant      HKMedicationDoseEventLogStatusNotificationNotSent    Could not deliver a notification for a scheduled medication. System generated status.
 @constant      HKMedicationDoseEventLogStatusSnoozed                    User snoozed the notification.
 @constant      HKMedicationDoseEventLogStatusTaken                         Logged the medication dose as taken.
 @constant      HKMedicationDoseEventLogStatusSkipped                      Logged the medication dose as skipped.
 @constant      HKMedicationDoseEventLogStatusNotLogged                 User has undone logging.
 */

typedef NS_ENUM(NSInteger, HKMedicationDoseEventLogStatus) {
    HKMedicationDoseEventLogStatusNotInteracted = 1,
    HKMedicationDoseEventLogStatusNotificationNotSent,
    HKMedicationDoseEventLogStatusSnoozed,
    HKMedicationDoseEventLogStatusTaken,
    HKMedicationDoseEventLogStatusSkipped,
    HKMedicationDoseEventLogStatusNotLogged,
} API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0)) NS_SWIFT_NAME(HKMedicationDoseEvent.LogStatus);

/*!
 @enum          HKMedicationDoseEventScheduleType
 @abstract      The kind of schedule used to log this dose event.
 
 @constant      HKMedicationDoseEventScheduleTypeAsNeeded         The dose event was created while logging a medication as needed.
 @constant      HKMedicationDoseEventScheduleTypeSchedule           The dose event was created while logging a medication from a scheduled event.
 */
typedef NS_ENUM(NSInteger, HKMedicationDoseEventScheduleType) {
    HKMedicationDoseEventScheduleTypeAsNeeded = 1,
    HKMedicationDoseEventScheduleTypeSchedule
} API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0)) NS_SWIFT_NAME(HKMedicationDoseEvent.ScheduleType);

HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0))
@interface HKMedicationDoseEvent : HKSample <NSSecureCoding, NSCopying>

/*!
@property   medicationDoseEventType
@abstract   The data type of the HKMedicationDoseEvent object.
*/
@property (readonly, copy) HKMedicationDoseEventType *medicationDoseEventType;

/*!
@property   scheduleType
@abstract   The impetus behind the dose event.
@discussion HKMedicationDoseEventScheduleTypeAsNeeded for doses logged as needed, and HKMedicationDoseEventScheduleTypeSchedule for doses logged from a scheduled event.
*/
@property (nonatomic, assign, readonly) HKMedicationDoseEventScheduleType scheduleType;

/*!
@property   medicationConceptIdentifier
@abstract   A unique identifier of the medication concept for which the dose event was created for, used to relate the dose event to the backing HKMedicationConcept object.
*/
@property (nonatomic, copy, readonly) HKHealthConceptIdentifier *medicationConceptIdentifier;

/*!
@property   scheduledDate
@abstract   The time that the medication dose was supposed to be taken.
@discussion Always non-null for scheduled medication dose events, always null for as needed dose events.
*/
@property (nonatomic, copy, readonly, nullable) NSDate *scheduledDate;

/*!
@property   scheduledDoseQuantity
@abstract   The dose quantity a user is expected to take per the user's schedule.
@discussion Always non-null for scheduled medication dose events, always null for as needed dose events.
*/
@property (nonatomic, copy, readonly, nullable) NSNumber *scheduledDoseQuantity NS_REFINED_FOR_SWIFT;

/*!
@property   doseQuantity
@abstract   The dose quantity the user indicates has actually been taken.
@discussion For scheduled dose events, defaults to the scheduledDoseQuantity, when logged from a reminder. For as needed dose events, defaults to 1 in the medication tracking experience, but can be edited by the user at any time.
*/
@property (nonatomic, copy, readonly, nullable) NSNumber *doseQuantity NS_REFINED_FOR_SWIFT;

/*!
@property   logStatus
@abstract   The log status of HKMedicationDoseEvent sample.
*/
@property (nonatomic, assign, readonly) HKMedicationDoseEventLogStatus logStatus;


/*!
@property   unit
@abstract   The unit that the associated medication had associated at time the user logged the dose event.
*/
@property (nonatomic, copy, readonly, nonnull) HKUnit *unit;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

// Predicate Key Paths
HK_EXTERN NSString * const HKPredicateKeyPathStatus API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));
HK_EXTERN NSString * const HKPredicateKeyPathLogOrigin API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));
HK_EXTERN NSString * const HKPredicateKeyPathScheduledDate API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));
HK_EXTERN NSString * const HKPredicateKeyPathMedicationConceptIdentifier API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));

NS_ASSUME_NONNULL_END

