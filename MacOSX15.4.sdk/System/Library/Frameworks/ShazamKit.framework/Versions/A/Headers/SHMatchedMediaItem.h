//
//  SHMatchedMediaItem.h
//  ShazamKit
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <ShazamKit/SHMediaItem.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// How far in seconds is this match from the start of the reference audio
API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0))
SH_EXPORT SHMediaItemProperty const SHMediaItemMatchOffset;

/// How much the match differs in frequency from reference material
API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0))
SH_EXPORT SHMediaItemProperty const SHMediaItemFrequencySkew;

/// The value ranges from 0.0 to 1.0, where 1.0 indicates the highest level of confidence.
API_AVAILABLE(macos(15.4), ios(18.4), tvos(18.4), watchos(11.4), visionos(2.4))
SH_EXPORT SHMediaItemProperty const SHMediaItemConfidence;

/// @brief @c SHMatchedMediaItem represents metadata that has been matched against a @c SHCatalog
/// @discussion Extra information is presented that can only be generated from a match. The properties provided here
/// that are not available on @c SHMediaItem are ephemeral and can differ each time there is a match of the @c SHSignature that this
/// object represents
///
/// @note @c SHMatchedMediaItem is not intended to be subclassed
SH_EXPORT NS_SWIFT_SENDABLE API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0))
@interface SHMatchedMediaItem : SHMediaItem <NSSecureCoding>

/// The frequency difference between the reference and sample audio
/// @discussion A value of 0.0 indicates the matched audio at the original frequency,
/// a value of 0.1 indicates 100hz is now 110hz
@property (NS_NONATOMIC_IOSONLY, assign, readonly) float frequencySkew;

/// @brief The difference between the start of the reference audio and the start of the sample audio
/// @note This value can be negative if the source audio starts before the reference audio
@property (NS_NONATOMIC_IOSONLY, assign, readonly) NSTimeInterval matchOffset;

/// @brief The auto updating playback position in the reference signature
@property (NS_NONATOMIC_IOSONLY, assign, readonly) NSTimeInterval predictedCurrentMatchOffset;

/// The level of confidence in the match result.
/// @note This may be fetched using the key @c SHMediaItemConfidence
/// @discussion The value ranges from 0.0 to 1.0, where 1.0 indicates the highest level of confidence.
@property (NS_NONATOMIC_IOSONLY, assign, readonly) float confidence API_AVAILABLE(macos(15.4), ios(18.4), tvos(18.4), watchos(11.4), visionos(2.4));

@end

NS_HEADER_AUDIT_END(nullability, sendability)
