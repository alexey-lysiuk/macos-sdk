/*
	File:  VTFrameProcessorConfiguration.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSORCONFIGURATION_H
#define VTFRAMEPROCESSORCONFIGURATION_H

#import <CoreMedia/CMFormatDescription.h>

NS_HEADER_AUDIT_BEGIN(nullability)

/*!
	@protocol VTFrameProcessorConfiguration
	@abstract The VTFrameProcessorConfiguration protocol describes the configuration of a processor to be used during a video processing session.
 
	@discussion VTFrameProcessorConfiguration protocol conformance is used to start an frame processing session.  These properties can be  queried on an implementation conforming to VTFrameProcessorConfiguration without starting a session.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
NS_SWIFT_SENDABLE
@protocol VTFrameProcessorConfiguration <NSObject>

@required

/*!
	@property processorSupported
	@abstract Returns a Boolean indicating whether the processor supported on the current config.
*/
@property (class, nonatomic, readonly) Boolean processorSupported;

/*!
	@property frameSupportedPixelFormats
	@abstract Returns a list of supported pixel formats for the current configuration
*/

@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats;

/*!
	@property sourcePixelBufferAttributes
	@abstract Returns a dictionary of CVPixelBuffer attributes which source and reference frames passed to the processor must conform to.
*/

@property (nonatomic, readonly) NSDictionary * sourcePixelBufferAttributes;

/*!
	@property destinationPixelBufferAttributes
	@abstract Returns a dictionary of CVPixelBuffer attributes which output frames passed to the processor must conform to.
*/

@property (nonatomic, readonly) NSDictionary * destinationPixelBufferAttributes;

@optional

/*!
	@property nextFrameCount
	@abstract returns the number of "next" frames that this processor requires for processing.
*/
@property (nonatomic, readonly) NSInteger nextFrameCount;

/*!
	@property previousFrameCount
	@abstract returns the number of "previous" frames that this processor requires for processing.
*/
@property (nonatomic, readonly) NSInteger previousFrameCount;

/*!
	@property maximumDimensions
	@abstract returns the maximum dimension for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions maximumDimensions;

/*!
	@property minimumDimensions
	@abstract returns the minimum dimension for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions minimumDimensions;

@end

NS_HEADER_AUDIT_END(nullability)

#endif // VTFRAMEPROCESSORPARAMETERS_H
