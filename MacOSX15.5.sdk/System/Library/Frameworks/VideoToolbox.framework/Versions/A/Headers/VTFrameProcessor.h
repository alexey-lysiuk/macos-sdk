/*
	File:  VTFrameProcessor.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_H
#define VTFRAMEPROCESSOR_H

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>
#import <VideoToolbox/VTFrameProcessorErrors.h>
#import <VideoToolbox/VTFrameProcessor_MotionBlur.h>
#import <VideoToolbox/VTFrameProcessor_FrameRateConversion.h>
#import <VideoToolbox/VTFrameProcessor_OpticalFlow.h>
#import <Metal/Metal.h>

/*!
	@header VTFrameProcessor.h
	@abstract
		This header defines the interface for a VTrameProcessor object, an interface which is used to access a range of different video processing features.
		
	@discussion
		The VTrameProcessor gives access to a set of powerful video procesing implemenation suitable for different use csaes.
		Each processor implementation is defined by a Configuration object (conforming to the VTFrameProcessorConfiguration protocol), used to pass initialization and configuration parameters for the processor and a Parameter object (conforming to the VTFrameProcessorParameters protocol) which provides the parameters for each individual processing operation.  These Configuration and Parameters objects for each implementation are defined in a processor-specific header file.
		The following processors are available:
			- VTFrameProcessor_MotionBlur.h: a high quality motion blur processor suitable for professional video applications.  May not be suitable for realtime scenarios.
			- VTFrameProcessor_FrameRateconversion.h: a high quality Frame Interpolation processor suitable for professional video applications.  May not be suitable for realtime scenarios.
			- VTFrameProcessor_OpticalFlow.h: a processor which generates formward and backward OpticalFlow between two source frames.
*/


NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/*!
	@class		VTFrameProcessor
	@abstract	Creates a new VTFrameProcessor for the configured video effect
	@discussion	The VTFrameProcessor class is the main class to perform frame processing. Users can specify a video effect by passing a VTFrameProcessorConfiguration based object to the startSessionWithConfiguration call. Once a session is created, the processWithParameters method is called in a loop to process the frames one by one. Once all the frames are processed, endSession needs to called to finish all pending processing.  The caller needs to ensure that all buffers passed to the processWithParameters interface are unmodified (inclduing attachments) until the function returns or the callback is received in the case of asynchronous mode.
 */

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))
@interface VTFrameProcessor : NSObject

- (instancetype) init;

/*!
	@method		startSessionWithConfiguration:error
	@abstract	Starts a new session and configures the processor pipeline.
	@param		configuration
		A VTFrameProcessorConfiguration based object corresponding to the video effect that will be applied in the subsequent processWithParameters calls.
	@param		error
		Will contain error information if any. You may specify NULL for this parameter if you do not want the error information.
 */

- (BOOL) startSessionWithConfiguration:(id<VTFrameProcessorConfiguration>)configuration
                                 error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(startSession(configuration:));

/*!
	@method		processWithParameters:error
	@abstract	Synchronously performs the effect specified in startSessionWithConfigurations.
	@discussion	Frame level settings and frame level input/output parameters are passed by using the respective VTFrameProcessorParameters for the effect that VTFrameProcessor is configured for.
	@param		parameters
		A VTFrameProcessorParameters based object to specify additional frame based parameters to be used during processing. it needs to match the configuration type used during start session.
	@param		error
		Will contain error information if any. You may specify NULL for this parameter if you do not want the error information.
 */

- (BOOL) processWithParameters:(id<VTFrameProcessorParameters>)parameters
                         error:(NSError * _Nullable * _Nullable)error NS_SWIFT_UNAVAILABLE("use the async version processWithParameters:completionHandler instead");

/*!
	 @method	processWithParameters:completionHandler
	 @abstract	Asynchronously performs the effect specified in startSessionWithConfigurations.
	 @param		parameters
		A VTFrameProcessorParameters based object to specify additional frame based parameters to be used during processing. it needs to match the configuration type used during start session.
	 @param		completionHandler
		This completion handler will be called when frame processing in competed.  The completion handler will receive the same parameters object that was provided tot he original call, as well as an NSError which will contain an error code if processing was not successful.
 */

- (void) processWithParameters:(id<VTFrameProcessorParameters>)parameters
             completionHandler:(void (^)(id<VTFrameProcessorParameters> , NSError * _Nullable) )completionHandler NS_SWIFT_NAME(process(parameters:completionHandler:));


/*!
	@method		processWithCommandBuffer:parameters
	@abstract	This API provides a Metal API friendly version of processWithParameters.
	@discussion	This function allows clients to add the effect to an existing Metal command buffer. This can be used by clients that have an existing Metal pipeline and want to add this effect to it. Note: this function will wait until all previously inserted tasks in the command buffer finished before running. Tasks inserted after the processWithCommandBuffer will run after the effect is applied.  Processing does not happen until the commandBuffer is executed.
	@param		commandBuffer
		An existing Metal command buffer where the frame processing will be inserted.
	@param		parameters
		A VTFrameProcessorParameters based object to specify additional frame based parameters to be used during processing. it needs to match the configuration type used during start session.
*/

- (void) processWithCommandBuffer:(id <MTLCommandBuffer>) commandBuffer
                       parameters:(id<VTFrameProcessorParameters>)parameters;



/*!
	@method		endSession
	@abstract	Performs all necessary tasks to end the session. After this call completes, no new frames can be processed unless startSessionWithConfigurations is called again.
*/

- (void) endSession;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // VTFRAMEPROCESSOR_H
