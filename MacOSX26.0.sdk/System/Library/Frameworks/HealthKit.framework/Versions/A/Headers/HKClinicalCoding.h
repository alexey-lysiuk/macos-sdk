//
//  HKClinicalCoding.h
//  HealthKit
//
//  Copyright © 2025 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class         HKClinicalCoding
 @abstract      A coding embedded within a system.
 @discussion    Typically represents a single abstract concept within a coding system. This model is closely related to the FHIR model for codings. (https://build.fhir.org/datatypes.html#Coding)
 */
HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0))
@interface HKClinicalCoding : NSObject <NSCopying, NSSecureCoding>
/*!
 @property      system
 @abstract      A string identifier that uniquely represents a system.
 @discussion    In most cases, it will be the canonical reference URL for the coding system with respect to the HL7 Terminology. For the system RxNorm, for example, this would be "http://www.nlm.nih.gov/research/umls/rxnorm", according to https://terminology.hl7.org/CodeSystem-v3-rxNorm.html.
 */
@property (nonatomic, copy, readonly) NSString *system;

/*!
 @property      version
 @abstract      The version of the coding system, if it is relevant.
 */
@property (nonatomic, copy, readonly, nullable) NSString *version;

/*!
 @property      code
 @abstract      The code for this concept.
 @discussion    The format of this code varies within each system.
 */
@property (nonatomic, copy, readonly) NSString *code;

- (instancetype)init NS_UNAVAILABLE;

/*!
 @method        initWithSystem:version:code:
 @abstract      Initializer for a clinical coding.
 
 @param         system      The system for this clinical coding.
 @param         version     A version, if applicable.
 @param         code           The actual code.
 */
- (instancetype)initWithSystem:(NSString *)system
                       version:(nullable NSString *)version
                          code:(NSString *)code;

@end

NS_ASSUME_NONNULL_END
