/*
	File:  VTFrameProcessorParameters.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/
 
#ifndef VTFRAMEPROCESSORPARAMETERS_H
#define VTFRAMEPROCESSORPARAMETERS_H

#import <VideoToolbox/VTFrameProcessorFrame.h>

NS_HEADER_AUDIT_BEGIN(nullability)

/*!
@protocol VTFrameProcessorParameters
@abstract VTFrameProcessorParameters is the base protocol for input and output processing parameters for a VTFrameProcessor processing implementation..  An instance of a class corresponding to this protocol is passed to processFrameWithParameters calls, and in async versions of those APIs, the same instance is returned in the completion.
*/

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)
@protocol VTFrameProcessorParameters <NSObject>

@required

/**
 * @property sourceFrame
 * @abstract VTFrameProcessorFrame that contains the current source frame to be used for all processing features. Must be non-null
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

@end

NS_HEADER_AUDIT_END(nullability)

#endif // VTFRAMEPROCESSORPARAMETERS_H

