/*
	File:  VTFrameProcessor_MotionBlur.h
 
	Framework:  VideoToolbox
 
	Copyright 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_MOTIONBLUR_H
#define VTFRAMEPROCESSOR_MOTIONBLUR_H

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>

/*!
    @brief Interfaces for creating and using a MotionBlur processor

    @details The VTMotionBlur processor Configuration and Parameters objects are used with the VTFrameProcessor interface defined in VTFrameProcessor.h.
*/

/*!
 @brief Quality prioritization levels to favor quality or performance.
*/
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTMotionBlurConfigurationQualityPrioritization) {
	VTMotionBlurConfigurationQualityPrioritizationNormal = 1,
	VTMotionBlurConfigurationQualityPrioritizationQuality = 2,
} NS_SWIFT_NAME(VTMotionBlurConfiguration.QualityPrioritization);

/*!
 @brief List of existing algorithm revisions with the highest being the latest. Clients can read defaultRevision property to find the default revision.
 */
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTMotionBlurConfigurationRevision) {
	VTMotionBlurConfigurationRevision1           = 1,    // revision 1
} NS_SWIFT_NAME(VTMotionBlurConfiguration.Revision);

/*!
 @brief Hint to let the processor know whether frames are being submitted in presenatation sequence, allowing performance optimizations based on previous processing requests
 */
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTMotionBlurParametersSubmissionMode) {
	VTMotionBlurParametersSubmissionModeRandom             = 1,    // Frames are submitted in non-sequential order
	VTMotionBlurParametersSubmissionModeSequential         = 2,    // Frames are submitted sequentially following presentation time order
} NS_SWIFT_NAME(VTMotionBlurParameters.SubmissionMode);

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/*!
 @class VTMotionBlurConfiguration
 @abstract Configuration that is used to set up the MotionBlur Processor.

 @discussion This configuration enables the MotionBlur on a VTFrameProcesing session.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
NS_SWIFT_SENDABLE __attribute__((objc_subclassing_restricted))
@interface VTMotionBlurConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTMotionBlurConfiguration with specified flow width and height.

 @discussion init will return nil if dimensions are out of range or revision is unsupported.

 @param frameWidth    Width of source frame in pixels. Maximum value is 8192 for macOS, and 4096 for iOS.

 @param frameHeight   Height of source frame in pixels. Maximum value is 4320 for macOS, and 2160 for iOS.

 @param usePrecomputedFlow  Boolean value to indicate that Optical Flow will be provided by the user, if false this configuration will compute the optical flow on the fly.

 @param qualityPrioritization Used to control quality and performance levels. See VTMotionBlurConfigurationQualityPrioritization for more info.
 
 @param revision The specific algorithm or configuration revision that is to be used to perform the request.
 
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
						 usePrecomputedFlow:(BOOL)usePrecomputedFlow
					  qualityPrioritization:(VTMotionBlurConfigurationQualityPrioritization)qualityPrioritization
								   revision:(VTMotionBlurConfigurationRevision)revision;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property frameWidth
 * @abstract Width of source frame in pixels.
 */
@property (nonatomic, readonly) NSInteger frameWidth;

/**
 * @property frameHeight
 * @abstract Height of source frame in pixels.
 */
@property (nonatomic, readonly) NSInteger frameHeight;

/**
 * @property usePrecomputedFlow
 * @abstract Indicates that caller will provide optical flow.
*/
@property (nonatomic, readonly) BOOL usePrecomputedFlow;

/**
 * @property qualityPrioritization
 * @abstract parameter used to control quality and performance levels. See VTMotionBlurConfigurationQualityPrioritization for more info.
*/
@property (nonatomic, readonly) VTMotionBlurConfigurationQualityPrioritization qualityPrioritization;

/*!
 @property revision
 @abstract The specific algorithm or configuration revision that is to be used to perform the request.
 */
@property (nonatomic, readonly) VTMotionBlurConfigurationRevision revision;

/*!
 @property supportedRevisions
 @abstract Provides the collection of currently-supported algorithm or configuration revisions for the class of configuration.
 @discussion This property allows clients to introspect at runtime what revisions are available for each configuration.
 */
@property (class, nonatomic, readonly) NSIndexSet* supportedRevisions;

/*!
 @property defaultRevision
 @abstract Provides the default revision of a particular algorithm or configuration.
 */
@property (class, nonatomic, readonly) VTMotionBlurConfigurationRevision defaultRevision;

/**
 * @property frameSupportedPixelFormats
 * @abstract list of source frame supported pixel formats for current configuration
 */
@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats;

/**
 * @property sourcePixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as source frames and reference frames.
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/**
 * @property destinationPixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as destination frames.
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;


/*!
	@property processorSupported
	@abstract reports that this processor is  supported
*/
@property (class, nonatomic, readonly) Boolean processorSupported;

@end


/*!
 @class VTMotionBlurParameters
 @abstract VTMotionBlurParameters object contains both input and output parameters needed to run the MotionBlur processor on a frame. This object is used in the processWithParameters call of VTFrameProcessor class. The output parameter for this class is destinationFrame where the output frame is returned (as VTFrameProcessorFrame) back to the caller function once the processWithParameters completes.
 
 @discussion VTMotionBlurParameters are frame level parameters.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))

@interface VTMotionBlurParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTMotionBlurParameters .

 @discussion init will return nil if sourceFrame or destinationFrame is nil, sourceFrame and reference frames  are different pixelFormats, or motionBlurStrength is out of range.

 @param sourceFrame Current source frame. Must be non nil.
  
 @param nextFrame Next source frame in presentation time order. For the last frame this can be set to nil.

 @param previousFrame  Previous source frame in presentation time order. For the first frame this can be set to nil.
 
 @param nextOpticalFlow Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow with next frame. Only needed if optical flow is pre-computed. For the last frame this will always be nil.
  
 @param previousOpticalFlow Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow with previous frame. Only needed if optical flow is pre-computed. For the first frame this will always be nil.
 
 @param motionBlurStrength NSInteger number to indicate the strength of blur to apply. Range is from 1 to 100. Default value is 50.

 @param submissionMode Set to VTMotionBlurParametersSubmissionModeSequential to indicate that current submission follow presentation time order without jump or skip when compared to previous submission. VTMotionBlurParametersSubmissionModeSequential will yield better performance. Set to VTMotionBlurParametersSubmissionModeRandom to indicate a skip or a jump in frame sequence. If VTMotionBlurParametersSubmissionModeRandom is set internal cache will be cleared during processWithParameters call.
 
 @param destinationFrame User allocated pixel buffer that will receive the results.
*/
- (nullable instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
									nextFrame:(VTFrameProcessorFrame * _Nullable)nextFrame
								previousFrame:(VTFrameProcessorFrame * _Nullable)previousFrame
							  nextOpticalFlow:(VTFrameProcessorOpticalFlow * _Nullable)nextOpticalFlow
						  previousOpticalFlow:(VTFrameProcessorOpticalFlow * _Nullable)previousOpticalFlow
						   motionBlurStrength:(NSInteger)motionBlurStrength
							   submissionMode:(VTMotionBlurParametersSubmissionMode)submissionMode
							 destinationFrame:(VTFrameProcessorFrame *)destinationFrame;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property sourceFrame
 * @abstract sourceFrame Current source frame. Must be non nil
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/**
 * @property nextFrame
 * @abstract Next source frame in presentation time order. For the last frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorFrame * nextFrame;

/**
 * @property previousFrame
 * @abstract Previous source frame in presentation time order. For the first frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorFrame * previousFrame;

/**
 * @property nextOpticalFlow
 * @abstract Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow with next frame. Only needed if optical flow is pre-computed. For the last frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorOpticalFlow * nextOpticalFlow;

/**
 * @property previousOpticalFlow
 * @abstract Optional VTFrameProcessorOpticalFlow object  that contains forward and backward optical flow with previous frame. Only needed if optical flow is pre-computed. For the first frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorOpticalFlow * previousOpticalFlow;

/**
 * @property motionBlurStrength
 * @abstract motionBlurStrength NSInteger number to indicate the strength of blur to apply. Range is from 1 to 100. Default value is 50.
*/
@property (nonatomic, readonly) NSInteger motionBlurStrength;

/**
 * @property submissionMode
 * @abstract A VTMotionBlurParametersSubmissionMode value describing the processing request in this Parameters object .
*/
@property (nonatomic, readonly) VTMotionBlurParametersSubmissionMode submissionMode;

/**
 * @property destinationFrame
 * @abstract VTFrameProcessorFrame that contains user allocated pixel buffer that will receive the results.
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * destinationFrame;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // VTFRAMEPROCESSOR_MOTIONBLUR_H
