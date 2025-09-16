//
//  HKHealthConceptIdentifier.h
//  HealthKit
//
//  Copyright © 2025 Apple. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Concepts

/// Represents the domain of a HKHealthConceptIdentifier
typedef NSString * HKHealthConceptDomain NS_TYPED_ENUM API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));

/// The domain that represents medication concept identifiers
HK_EXTERN HKHealthConceptDomain const HKHealthConceptDomainMedication API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0));

/*!
 @class         HKHealthConceptIdentifier
 @abstract      The identifier that differentiates concepts from each other.
 @discussion    This identifier is internally unique to each concept within a domain.
 */
HK_EXTERN
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.0), watchos(26.0), macCatalyst(26.0), macos(26.0), visionos(26.0))
@interface HKHealthConceptIdentifier : NSObject <NSSecureCoding, NSCopying>

/*!
 @property      domain
 @abstract      The domain of this identifier.
 @discussion    A string that represents the domain this identifier is understood within.
 */
@property (nonatomic, copy, readonly) HKHealthConceptDomain domain;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
