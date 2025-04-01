/*
	File:  VTFrameProcessor_OpticalFlow.h
 
	Framework:  VideoToolbox
 
	Copyright 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_OPTICALFLOW_H
#define VTFRAMEPROCESSOR_OPTICALFLOW_H

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>

/*!
    @brief A few words about the OpticalFlow

    @details
*/

/*!
 @brief Quality prioritization levels to favor quality or performance.
*/
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTOpticalFlowConfigurationQualityPrioritization) {
	VTOpticalFlowConfigurationQualityPrioritizationNormal = 1,
	VTOpticalFlowConfigurationQualityPrioritizationQuality = 2,
} NS_SWIFT_NAME(VTOpticalFlowConfiguration.QualityPrioritization);

/*!
 @brief List of existing algorithm revisions with the highest being the latest. Clients can read defaultRevision property to find the default revision.
 */
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTOpticalFlowConfigurationRevision) {
	VTOpticalFlowConfigurationRevision1           = 1,    // revision 1
} NS_SWIFT_NAME(VTOpticalFlowConfiguration.Revision);

/*!
 @brief Hint to let the processor know whether frames are being submitted in presenatation sequence, allowing performance optimizations based on previous processing requests
 */
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
typedef NS_ENUM(NSInteger, VTOpticalFlowParametersSubmissionMode) {
	VTOpticalFlowParametersSubmissionModeRandom             = 1,    // Frames are submitted in non-sequential order
	VTOpticalFlowParametersSubmissionModeSequential         = 2,    // Frames are submitted sequentially following presentation time order
} NS_SWIFT_NAME(VTOpticalFlowParameters.SubmissionMode);

NS_HEADER_AUDIT_BEGIN(nullability, sendability)


/*!
 @class VTOpticalFlowConfiguration
 @abstract Configuration that is used to set up an OpticalFlow processor

 @discussion This configuration enables the OpticalFlow on a VTFrameProcessing session.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
NS_SWIFT_SENDABLE __attribute__((objc_subclassing_restricted))
@interface VTOpticalFlowConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTOpticalFlowConfiguration with specified flow width and height.
 
 @discussion init will return nil if dimensions are out of range or revision is unsupported.

 @param frameWidth    Width of source frame in pixels. Maximum value is 8192 for macOS, and 4096 for iOS.

 @param frameHeight   Height of source frame in pixels. Maximum value is 4320 for macOS, and 2160 for iOS.

 @param usePrecomputedFlow  Boolean value to indicate that Optical Flow will be provided by the user, if false this configuration will compute the optical flow on the fly.

 @param qualityPrioritization Used to control quality and performance levels. See VTOpticalFlowConfigurationQualityPrioritization for more info.
 
 @param revision The specific algorithm or configuration revision that is to be used to perform the request.
 
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
					  qualityPrioritization:(VTOpticalFlowConfigurationQualityPrioritization)qualityPrioritization
								   revision:(VTOpticalFlowConfigurationRevision)revision;

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
 * @property qualityPrioritization
 * @abstract parameter used to control quality and performance levels. See VTOpticalFlowConfigurationQualityPrioritization for more info.
*/
@property (nonatomic, readonly) VTOpticalFlowConfigurationQualityPrioritization qualityPrioritization;

/*!
 @property revision
 @abstract The specific algorithm or configuration revision that is to be used to perform the request.
 */
@property (nonatomic, readonly) VTOpticalFlowConfigurationRevision revision;

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
@property (class, nonatomic, readonly) VTOpticalFlowConfigurationRevision defaultRevision;

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
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as OpticalFlow buffers
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

/*!
	@property processorSupported
	@abstract reports that this processor is  supported
*/
@property (class, nonatomic, readonly) Boolean processorSupported;

@end


/*!
 @class VTOpticalFlowParameters
 @abstract VTOpticalFlowParameters object contains both input and output parameters needed to generate optical flow between two frames. This object is used in the processWithParameters call of VTFrameProcessor class. The output parameter for this class is destinationOpticalFlow where the output flow is returned (as VTFrameProcessorMutableOpticalFlow) back to the caller function once the processWithParameters completes.
 
 @discussion VTOpticalFlowParameters are frame level parameters.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))

@interface VTOpticalFlowParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTOpticalFlowParameters .

 @discussion init will return nil if sourceFrame or nextFrame is nil, or sourceFrame and nextFrame are different pixelFormats..

 @param sourceFrame Current source frame. Must be non nil.
  
 @param nextFrame Next source frame in presentation time order.
  
 @param submissionMode Set to VTOpticalFlowParametersSubmissionModeSequential to indicate that current submission follow presentation time order without jump or skip when compared to previous submission. VTOpticalFlowParametersSubmissionModeSequential will yield better performance. Set to  VTOpticalFlowParametersSubmissionModeRandom to indicate a skip or a jump in frame sequence. If VTOpticalFlowParametersSubmissionModeRandom is set internal cache will be cleared during processWithParameters call.
 
 @param destinationOpticalFlow User allocated VTFrameProcessorMutableOpticalFlow that will receive the results.
*/
- (nullable instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
									nextFrame:(VTFrameProcessorFrame *)nextFrame
							   submissionMode:(VTOpticalFlowParametersSubmissionMode)submissionMode
					   destinationOpticalFlow:(VTFrameProcessorOpticalFlow *) destinationOpticalFlow;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property sourceFrame
 * @abstract sourceFrame Current source frame. Must be non nil
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/**
 * @property nextFrame
 * @abstract Next source frame in presentation time order.
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * nextFrame;

/**
 * @property submissionMode
 * @abstract A VTOpticalFlowParametersSubmissionMode value describing the processing request in this Parameters object .
*/
@property (nonatomic, readonly) VTOpticalFlowParametersSubmissionMode submissionMode;

/**
 * @property destinationOpticalFlow
 * @abstract VTFrameProcessorMutableOpticalFlow that contains user allocated flow pixel buffers that will receive the results.
*/

@property(nonatomic, readonly) VTFrameProcessorOpticalFlow * destinationOpticalFlow;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // VTFRAMEPROCESSOR_OPTICALFLOW_H
