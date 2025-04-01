/*
	File:  VTFrameProcessor_FrameRateConversion.h
 
	Framework:  VideoToolbox
 
	Copyright 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_FRAMERATECONVERSION_H
#define VTFRAMEPROCESSOR_FRAMERATECONVERSION_H

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>

/*!
    @brief Interfaces for creating and using a FrameRateConversion processor

    @details The VTFrameRateConversion processor Configuration and Parameters objects are used with the VTFrameProcessor interface defined in VTFrameProcessor.h.
*/

/*!
 @brief Quality prioritization levels to favor quality or performance.
*/
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTFrameRateConversionConfigurationQualityPrioritization) {
	VTFrameRateConversionConfigurationQualityPrioritizationNormal = 1,
	VTFrameRateConversionConfigurationQualityPrioritizationQuality = 2,
} NS_SWIFT_NAME(VTFrameRateConversionConfiguration.QualityPrioritization);

/*!
 @brief List of existing algorithm revisions with the highest being the latest. Clients can read defaultRevision property to find the default revision.
 */

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTFrameRateConversionConfigurationRevision) {
	VTFrameRateConversionConfigurationRevision1           = 1,    // revision 1
} NS_SWIFT_NAME(VTFrameRateConversionConfiguration.Revision);

/*!
 @brief Hint to let the processor know whether frames are being submitted in presenatation sequence, allowing performance optimizations based on previous processing requests
 */
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTFrameRateConversionParametersSubmissionMode) {
	VTFrameRateConversionParametersSubmissionModeRandom							= 1,    // Frames are submitted in non-sequential order
	VTFrameRateConversionParametersSubmissionModeSequential						= 2,    // Frames are submitted sequentially following presentation time order
	VTFrameRateConversionParametersSubmissionModeSequentialReferencesUnchanged	= 3,    // Frames are being submitted sequentially.  This processing request uses the same source and next reference frames as the previous submission.
} NS_SWIFT_NAME(VTFrameRateConversionParameters.SubmissionMode);


NS_HEADER_AUDIT_BEGIN(nullability, sendability)


/*!
 @class VTFrameRateConversionConfiguration
 @abstract Configuration that is used to set up the FrameRateConversion Processor.

 @discussion This configuration enables the FrameRateConversion on a VTFrameProcesing session.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
NS_SWIFT_SENDABLE __attribute__((objc_subclassing_restricted))
@interface VTFrameRateConversionConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTFrameRateConversionConfiguration with specified flow width and height.

 @discussion init will return nil if dimensions are out of range or revision is unsupported.

 @param frameWidth    Width of source frame in pixels. Maximum value is 8192 for macOS, and 4096 for iOS.

 @param frameHeight   Height of source frame in pixels. Maximum value is 4320 for macOS, and 2160 for iOS.

 @param usePrecomputedFlow  Boolean value to indicate that Optical Flow will be provided by the user, if false this configuration will compute the optical flow on the fly.

 @param qualityPrioritization Used to control quality and performance levels. See VTFrameRateConversionConfigurationQualityPrioritization for more info.
 
 @param revision The specific algorithm or configuration revision that is to be used to perform the request.
 
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
						 usePrecomputedFlow:(BOOL)usePrecomputedFlow
					  qualityPrioritization:(VTFrameRateConversionConfigurationQualityPrioritization)qualityPrioritization
								   revision:(VTFrameRateConversionConfigurationRevision)revision;

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
 * @abstract parameter used to control quality and performance levels. See VTFrameRateConversionConfigurationQualityPrioritization for more info.
*/
@property (nonatomic, readonly) VTFrameRateConversionConfigurationQualityPrioritization qualityPrioritization;

/*!
 @property revision
 @abstract The specific algorithm or configuration revision that is to be used to perform the request.
 */
@property (nonatomic, readonly) VTFrameRateConversionConfigurationRevision revision;

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
@property (class, nonatomic, readonly) VTFrameRateConversionConfigurationRevision defaultRevision;

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
 @class VTFrameRateConversionParameters
 @abstract VTFrameRateConversionParameters object contains both input and output parameters needed to run the FrameRateConversion processor on a frame. This object is used in the processWithParameters call of VTFrameProcessor class. The output parameter for this class is destinationFrame where the output frame is returned (as VTFrameProcessorMutableFrame) back to the caller function once the processWithParameters completes.
 
 @discussion VTFrameRateConversionParameters are frame level parameters.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))

@interface VTFrameRateConversionParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTFrameRateConversionParameters .
 
 @discussion init will return nil if sourceFrame or nextFrame is nil, if sourceFrame and reference frames don't have the same pixelformat, or if interpolationPhase array count does not match destinationFrames array count.

 @param sourceFrame Current source frame. Must be non nil.
  
 @param nextFrame Next source frame in presentation time order.  Must be non nil.
  
 @param opticalFlow Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow with next frame. Only needed if optical flow is pre-computed. For the first frame this will always be nil.
 
 @param interpolationPhase Array of float numbers to indicate at what intervals to insert a frame between current and next frame. Array size indicates how many frames to interpolate and needs to match destinationFrames size, one interval for each destination frame. Float number values should be between 0 and 1, e.g to insert one frame in the middle a value of 0.5 can be used.

 @param submissionMode Set to VTFrameRateConversionParametersSubmissionModeSequential to indicate that current submission follow presentation time order without jump or skip when compared to previous submission. VTFrameRateConversionParametersSubmissionModeSequential will yield better performance. Set to  VTFrameRateConversionParametersSubmissionModeRandom to indicate a skip or a jump in frame sequence. If VTFrameRateConversionParametersSubmissionModeRandom is set internal cache will be cleared during processWithParameters call.
 
 @param destinationFrames Caller-allocated NSArray of VTFrameProcessorFrame that contains  pixel buffers that will receive the results.  Must contain the same number of elements as interpolationPhase NSArray.
*/
- (nullable instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
									nextFrame:(VTFrameProcessorFrame *)nextFrame
								  opticalFlow:(VTFrameProcessorOpticalFlow * _Nullable)opticalFlow
						   interpolationPhase:(NSArray<NSNumber *> *) interpolationPhase
							   submissionMode:(VTFrameRateConversionParametersSubmissionMode)submissionMode
							destinationFrames:(NSArray<VTFrameProcessorFrame *> *)destinationFrame NS_REFINED_FOR_SWIFT;

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
 * @property opticalFlow
 * @abstract Optional VTFrameProcessorReadOnlyOpticalFlow object that contains forward and backward optical flow with next frame. Only needed if optical flow is pre-computed. For the last frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorOpticalFlow * opticalFlow;

/**
 * @property interpolationPhase
 * @abstract Array of float numbers to indicate at what intervals to insert a frame between current and next frame. Array size indicates how many frames to interpolate and needs to match destinationFrames size, one interval for each destination frame. Float number values should be between 0 and 1, e.g to insert one frame in the middle a value of 0.5 can be used.
*/
@property (nonatomic, readonly) NSArray<NSNumber *> * interpolationPhase NS_REFINED_FOR_SWIFT;

/**
 * @property submissionMode
 * @abstract A VTFrameRateConversionParametersSubmissionMode value describing the processing request in this Parameters object .
*/
@property (nonatomic, readonly) VTFrameRateConversionParametersSubmissionMode submissionMode;


/**
 * @property destinationFrames
 * @abstract Caller-allocated NSArray of VTFrameProcessorFrame that contains  pixel buffers that will receive the results.  Must contain the same number of elements as interpolationPhase NSArray.
*/

@property(nonatomic, readonly) NSArray<VTFrameProcessorFrame *> * destinationFrames;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // VTFRAMEPROCESSOR_FRAMERATECONVERSION_H
