/*
	File:  VTFrameProcessorErrors.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSORERRORS_H
#define VTFRAMEPROCESSORERRORS_H

API_AVAILABLE(macos(15.4)) API_UNAVAILABLE(ios) API_UNAVAILABLE(tvos, watchos, visionos)

extern NSErrorDomain _Nonnull const VTFrameProcessorErrorDomain;

/*!
	@enum       	VTFrameProcessorError
	@abstract		VTFrameProcessor  error codes.
	@discussion		These error codes are returned in the NSError object in the event a method fails.
	@constant		VTFrameProcessorUnknownError
		Returned if the processor failed for unknown reason.
	@constant		VTFrameProcessorUnsupportedResolution
		Returned if the processor failed due to an unsupported resolution.
	@constant		VTFrameProcessorSessionNotStarted
		Returned if the session is used to process frames without being started.
	@constant		VTFrameProcessorSessionAlreadyActive
		Returned if a startSessionWithConfiguration call is made on a session which has already been started.
	@constant		VTFrameProcessorFatalError
		Returned if a fatal error is encoutnered during processing.
	@constant		VTFrameProcessorSessionLevelError
		Returned if processing failed and current session should be stopped.
	@constant		VTFrameProcessorInitializationFailed
		Returned if the session failed to initialize the processing pipeline.
	@constant		VTFrameProcessorUnsupportedInput
		Returned to indicate that one or more frames is in a format which is not supproted by the processor.
	@constant		VTFrameProcessorMemoryAllocationFailure
		Returned if the session or processor is unable to allocate required memory.
	@constant		VTFrameProcessorRevisionNotSupported
		Returned if the specifed revision is not supported by the configured processor.
	@constant		VTFrameProcessorProcessingError
		Returned if the processor encountered an issue preventing it from processing the provided frame.
	@constant		VTFrameProcessorInvalidParameterError
		Returned if one of the provided parameters is not valid.
	@constant		VTFrameProcessorInvalidFrameTiming
		Returned if one of the provided VTFrameProcessorFrame objects has a PTS which is not supported by the processor, either invalid or out-of-order.
*/


typedef NS_ERROR_ENUM(VTFrameProcessorErrorDomain, VTFrameProcessorError)
{
	VTFrameProcessorUnknownError				= -19730,
	VTFrameProcessorUnsupportedResolution		= -19731,
	VTFrameProcessorSessionNotStarted			= -19732,
	VTFrameProcessorSessionAlreadyActive		= -19733,
	VTFrameProcessorFatalError					= -19734,
	VTFrameProcessorSessionLevelError			= -19735,
	VTFrameProcessorInitializationFailed		= -19736,
	VTFrameProcessorUnsupportedInput			= -19737,
	VTFrameProcessorMemoryAllocationFailure		= -19738,
	VTFrameProcessorRevisionNotSupported		= -19739,
	VTFrameProcessorProcessingError				= -19740,
	VTFrameProcessorInvalidParameterError		= -19741,
	VTFrameProcessorInvalidFrameTiming			= -19742,
};

#endif // VTFRAMEPROCESSORERRORS_H

