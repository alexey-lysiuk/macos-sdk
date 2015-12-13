/*=============================================================================
	AudioUnitUtilities.h
		
	Copyright (c) 2002 Apple Computer, Inc.  All Rights Reserved
=============================================================================*/

// Utilities for use of AudioUnit clients - higher-level functions.


#ifndef __AudioUnitUtilities_h__
#define __AudioUnitUtilities_h__

#include <AudioUnit/AudioUnit.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
	kAUParameterListener_AnyParameter = 0xFFFFFFFF
};

typedef struct AUParameterListener *AUParameterListenerRef;	// opaque

typedef void (*AUParameterListenerProc)(	void *						inRefCon,
											void *						inObject,
											const AudioUnitParameter *	inParameter,
											Float32						inValue);

extern OSStatus
AUListenerCreate(					AUParameterListenerProc			inProc,
									void *							inRefCon,
									CFRunLoopRef					inRunLoop,
									CFStringRef						inRunLoopMode,
									Float32							inNotificationInterval,
									AUParameterListenerRef *		outListener);

extern OSStatus
AUListenerDispose(			AUParameterListenerRef			inListener);


extern OSStatus
AUListenerAddParameter(				AUParameterListenerRef			inListener, 
									void *							inObject,
									const AudioUnitParameter *		inParameter);

extern OSStatus
AUListenerRemoveParameter(			AUParameterListenerRef			inListener, 
									void *							inObject, 
									const AudioUnitParameter *		inParameter);


extern OSStatus
AUParameterSet(						AUParameterListenerRef			inListener, 
									void *							inObject,
									const AudioUnitParameter *		inParameter,
									Float32							inValue,
									UInt32							inBufferOffsetInFrames);



extern OSStatus
AUParameterListenerNotify(			AUParameterListenerRef			inListener,
									void *							inObject,
									const AudioUnitParameter *		inParameter);

extern Float32
AUParameterValueFromLinear(			Float32							inLinearValue,		// 0-1
									const AudioUnitParameter *		inParameter);

extern Float32
AUParameterValueToLinear(			Float32							inParameterValue,
									const AudioUnitParameter *		inParameter);		// returns 0-1
									
extern char *
AUParameterFormatValue(				double							inParameterValue,
									const AudioUnitParameter *		inParameter,
									char *							inTextBuffer,
									UInt32							inDigits);


#ifdef __cplusplus
}
#endif


#endif
