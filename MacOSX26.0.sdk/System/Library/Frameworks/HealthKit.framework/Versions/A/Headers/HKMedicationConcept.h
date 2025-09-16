//
//  HKMedicationConcept.h
//  HealthKit
//
//  Copyright © 2025 Apple. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>

@class HKClinicalCoding;
@class HKHealthConceptIdentifier;

NS_ASSUME_NONNULL_BEGIN

/// Represents a medications general form.
typedef NSString * NS_TYPED_ENUM HKMedicationGeneralForm;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormCapsule;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormCream;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormDevice;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormDrops;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormFoam;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormGel;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormInhaler;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormInjection;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormLiquid;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormLotion;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormOintment;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormPatch;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormPowder;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormSpray;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormSuppository;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormTablet;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormTopical;
HK_EXTERN HKMedicationGeneralForm const HKMedicationGeneralFormUnknown;

/*!
 @class         HKMedicationConcept
 @abstract      An object that represents the concept of a medication.
 @discussion    Medications can have clinical significance, or can be created by the user.
 */
HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0))
@interface HKMedicationConcept : NSObject <NSSecureCoding, NSCopying>

/*!
 @property      identifier
 @abstract      A unique identifier that differentiates concepts from each other.
 @discussion    One medication concept will have a stable identifier across multiple devices, and can be used for direct comparison.
 */
@property (nonatomic, copy, readonly) HKHealthConceptIdentifier *identifier;


/*!
 @property      displayText
 @abstract      An unlocalized string suitable for display.
 @discussion    The name of the medication entered or selected during medication onboarding.
 */
@property (nonatomic, copy, readonly) NSString *displayText;

/*!
 @property      generalForm
 @abstract      The general form this medication is manufactured in.
 @discussion    A general manufactured dose form for this medication.
 */
@property (nonatomic, copy, readonly) HKMedicationGeneralForm generalForm;

/*!
 @property      relatedCodings
 @abstract      A list of potentially related codings.
 @discussion    Contains a set of relevant codes for this particular medication.
 */
@property (nonatomic, copy, readonly) NSSet<HKClinicalCoding *> *relatedCodings;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
