//
//  HKUserAnnotatedMedication.h
//  HealthKit
//
//  Copyright © 2025 Apple. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>

@class HKMedicationConcept;
@class HKUserAnnotatedMedicationType;

NS_ASSUME_NONNULL_BEGIN

/*!
 @class         HKUserAnnotatedMedication
 @abstract      An object that contains all of the user-customizable details relevant to the medication tracking experience and a reference to a medication being tracked.
 */
HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0))
@interface HKUserAnnotatedMedication : NSObject <NSSecureCoding, NSCopying>

/*!
 @property      nickname
 @abstract      The nickname a added to a medication during the entry experience.
 @discussion    This can be edited at any point.
 */
@property (nonatomic, copy, readonly, nullable) NSString *nickname;

/*!
 @property      isArchived
 @abstract      A boolean value indicating if a medication is archived.
 @discussion    True if a user moves a medication to the archived section in the medication tracking experience. False if a medication is not in the archived section.
 */
@property (nonatomic, assign, readonly) BOOL isArchived;

/*!
 @property      hasSchedule
 @abstract      A boolean value indicating if a medication has a schedule set up.
 @discussion    True if a user has set up reminders for a medication. False for "As Needed" medications.
 */
@property (nonatomic, assign, readonly) BOOL hasSchedule;

/*!
 @property      medication
 @abstract      A reference to the specific medication a user is tracking.
 @discussion    This concept's identifier is directly associated with the logged dose events.
 */
@property (nonatomic, copy, readonly) HKMedicationConcept *medication;

- (instancetype)init NS_UNAVAILABLE;

@end

// Predicate Key Paths
HK_EXTERN NSString * const HKUserAnnotatedMedicationPredicateKeyPathIsArchived API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));
HK_EXTERN NSString * const HKUserAnnotatedMedicationPredicateKeyPathHasSchedule API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));

NS_ASSUME_NONNULL_END
