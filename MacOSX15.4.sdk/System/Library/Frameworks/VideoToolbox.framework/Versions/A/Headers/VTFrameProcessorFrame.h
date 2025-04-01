/*
	File:  VTFrameProcessorFrame.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSORFRAME_H
#define VTFRAMEPROCESSORFRAME_H

#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CMTime.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/*!
	@class     VTFrameProcessorFrame
	@abstract  Helper class to wrap video frames that will be sent to the processor, as source frames, reference frames, or output frames.  Instances retain the buffer backing them.
*/
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))

@interface VTFrameProcessorFrame : NSObject

/*!
	@method    initWithBuffer
	@abstract  initialize class with a CVPixelBufferRef and a presentation time. Buffer is retained.  Returns nil if no CVPixelBuffer is provided or CVPixelBuffer is not IOSurface backed.
	@param     buffer The CVPixelBufferRef that this VTFrameProcessorFrame will wrap.  Must not be nil and must be IOSurface backed.
	@param     presentationTimeStamp   The presentation timestamp of the buffer.
*/
- (nullable instancetype)initWithBuffer:(CVPixelBufferRef)buffer
         presentationTimeStamp:(CMTime)presentationTimeStamp;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/*!
	@property buffer
	@abstract Returns the CVPixelBufferRef  that was provided when the object was initialized with.
*/

@property(nonatomic,readonly) CVPixelBufferRef buffer;

/*!
	@property presentationTimeStamp
	@abstract Returns the presentation timestamp that was provided when the object was initialized with
*/
@property(nonatomic,readonly) CMTime presentationTimeStamp;


@end


/*!
	@class     VTFrameProcessorOpticalFlow
	@abstract  Helper class to wrap optical flow that will be sent to the processor.   Instances retain the buffers backing them.
*/
API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
__attribute__((objc_subclassing_restricted))

@interface VTFrameProcessorOpticalFlow : NSObject

/*!
	@method    initWithForwardFlow
	@abstract  initialize class with forward and backward optical flow CVPixelBufferRefs. Instances retain the buffers backing them. Returns nil if a nil CVPixelBuffer is provided or CVPixelBuffers are not IOSurface backed.
	@param     forwardFlow CVPixelBufferRef that contains forward optical flow. Must not be nil and must be IOSurface backed.
	@param     backwardFlow CVPixelBufferRef that contains backward optical flow. Must not be nil and must be IOSurface backed.
*/
- (nullable instancetype)initWithForwardFlow:(CVPixelBufferRef)forwardFlow
                       backwardFlow:(CVPixelBufferRef)backwardFlow;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/*!
	@property forwardFlow
	@abstract Returns the forward optical flow CVPixelBufferRef that was provided when the object was initialized.
*/

@property(nonatomic, readonly) CVPixelBufferRef forwardFlow;

/*!
	@property backwardFlow
	@abstract Returns the backward optical flow CVPixelBufferRef that was provided when the object was initialized.
*/

@property(nonatomic, readonly) CVPixelBufferRef backwardFlow;

@end


NS_HEADER_AUDIT_END(nullability, sendability)

#endif // VTFRAMEPROCESSORFRAME_H
