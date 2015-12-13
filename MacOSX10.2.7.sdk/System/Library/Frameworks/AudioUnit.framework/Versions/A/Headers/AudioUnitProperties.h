/*
     File:       AudioUnitProperties.h
 
     Contains:   Property constants for AudioUnits
 
     Version:    Technology: Mac OS X
                 Release:    Mac OS X
 
     Copyright:  (c) 2001 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/

#ifndef __AudioUnitProperties
#define __AudioUnitProperties

#include <AudioUnit/AUComponent.h>

#if TARGET_API_MAC_OSX
	#include <CoreFoundation/CoreFoundation.h>
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Properties
// Apple reserves property values from 0 -> 63999
// Developers are free to use property IDs above this range at their own discretion

enum
{
// Applicable to all AudioUnits in general	(0 -> 999)
	kAudioUnitProperty_ClassInfo					= 0,
	kAudioUnitProperty_MakeConnection				= 1,
	kAudioUnitProperty_SampleRate					= 2,
	kAudioUnitProperty_ParameterList				= 3,
	kAudioUnitProperty_ParameterInfo				= 4,
	kAudioUnitProperty_FastDispatch					= 5,
	kAudioUnitProperty_CPULoad						= 6,
	kAudioUnitProperty_StreamFormat					= 8,
	kAudioUnitProperty_SRCAlgorithm					= 9,
	kAudioUnitProperty_ReverbRoomType				= 10,
	kAudioUnitProperty_BusCount						= 11,
	kAudioUnitProperty_Latency						= 12,
	kAudioUnitProperty_SupportedNumChannels			= 13,
	kAudioUnitProperty_MaximumFramesPerSlice		= 14,
	kAudioUnitProperty_SetExternalBuffer			= 15,
	kAudioUnitProperty_ParameterValueStrings		= 16,
	kAudioUnitProperty_MIDIControlMapping			= 17,
	kAudioUnitProperty_GetUIComponentList			= 18,
// this property is deprecated and ID will be reused at a later date for soemthing else
//	kAudioUnitProperty_RampUpTime					= 19,  
	kAudioUnitProperty_TailTime						= 20,
	kAudioUnitProperty_BypassEffect					= 21,
	kAudioUnitProperty_LastRenderError				= 22,
	kAudioUnitProperty_SetRenderCallback			= 23,
	kAudioUnitProperty_FactoryPresets				= 24,
	kAudioUnitProperty_ContextName					= 25,
	kAudioUnitProperty_RenderQuality				= 26,
	kAudioUnitProperty_HostCallbacks				= 27,
	kAudioUnitProperty_CurrentPreset				= 28,
	kAudioUnitProperty_UsesInternalReverb			= 1005,
	
// Applicable to MusicDevices				(1000 -> 1999)
	kMusicDeviceProperty_InstrumentCount 			= 1000,
	kMusicDeviceProperty_InstrumentName				= 1001,
	kMusicDeviceProperty_GroupOutputBus				= 1002,
	kMusicDeviceProperty_SoundBankFSSpec			= 1003,
	kMusicDeviceProperty_InstrumentNumber 			= 1004,
	kMusicDeviceProperty_UsesInternalReverb			= kAudioUnitProperty_UsesInternalReverb,
	kMusicDeviceProperty_MIDIXMLNames				= 1006,
	kMusicDeviceProperty_BankName					= 1007,
	
// Applicable to "output" AudioUnits		(2000 -> 2999)
	kAudioOutputUnitProperty_CurrentDevice			= 2000,
	kAudioOutputUnitProperty_IsRunning				= 2001,
	kAudioOutputUnitProperty_ChannelMap				= 2002,

// miscellaneous AudioUnit - specific properties
	kAudioUnitProperty_SpatializationAlgorithm		= 3000,
	kAudioUnitProperty_SpeakerConfiguration			= 3001,
	kAudioUnitProperty_DopplerShift					= 3002,
	kAudioUnitProperty_3DMixerRenderingFlags		= 3003,
	kAudioUnitProperty_3DMixerDistanceAtten			= 3004
};

enum {
	kAudioUnitSRCAlgorithm_Polyphase			= 'poly',
	kAudioUnitSRCAlgorithm_MediumQuality		= 'csrc'
};

enum {
	kReverbRoomType_SmallRoom	= 0,
	kReverbRoomType_MediumRoom	= 1,
	kReverbRoomType_LargeRoom	= 2,
	kReverbRoomType_MediumHall	= 3,
	kReverbRoomType_LargeHall	= 4,
	kReverbRoomType_Plate		= 8
};

enum {
	kSpatializationAlgorithm_EqualPowerPanning 		= 0,
	kSpatializationAlgorithm_SphericalHead 			= 1,
	kSpatializationAlgorithm_HRTF			 		= 2,
	kSpatializationAlgorithm_SoundField		 		= 3,
	kSpatializationAlgorithm_VectorBasedPanning		= 4
};
	
enum {
	kSpeakerConfiguration_HeadPhones		 		= 0,
	kSpeakerConfiguration_Stereo			 		= 1,
	kSpeakerConfiguration_Quad			 			= 2,
	kSpeakerConfiguration_5_1				 		= 3
};

enum {
	k3DMixerRenderingFlags_InterAuralDelay			= (1L << 0),
	k3DMixerRenderingFlags_DopplerShift				= (1L << 1),
	k3DMixerRenderingFlags_DistanceAttenuation		= (1L << 2),
	k3DMixerRenderingFlags_DistanceFilter			= (1L << 3),
	k3DMixerRenderingFlags_DistanceDiffusion		= (1L << 4)
};

	
enum {
	kRenderQuality_Max								= 0x7F,
	kRenderQuality_High								= 0x60,
	kRenderQuality_Medium							= 0x40,
	kRenderQuality_Low								= 0x20,
	kRenderQuality_Min								= 0
};

enum {
	kAudioUnitScope_Global	= 0,
	kAudioUnitScope_Input	= 1,
	kAudioUnitScope_Output	= 2,
	kAudioUnitScope_Group	= 3
};

typedef struct AudioUnitConnection {
	AudioUnit	sourceAudioUnit;
	UInt32		sourceOutputNumber;
	UInt32		destInputNumber;
} AudioUnitConnection;

typedef struct AURenderCallbackStruct {
	AURenderCallback			inputProc;
	void *						inputProcRefCon;
} AURenderCallbackStruct;
	
typedef struct AudioUnitExternalBuffer {
	Byte *		buffer;
	UInt32		size;
} AudioUnitExternalBuffer;

typedef struct AUChannelInfo {
	SInt16		inChannels;
	SInt16		outChannels;
} AUChannelInfo;

typedef struct AUPreset {
	SInt32		presetNumber;
	CFStringRef	presetName;
} AUPreset;

// If the host is unable to provide the requested information
// then it can return the kAudioUnitErr_CannotDoInCurrentContext error code

// Any of these parameters when called by the AudioUnit can be NULL
// ie. the AU doesn't want to know about this. 
// (except for the HostUserData which must be supplied by the AU as given to it when the property was set)

typedef OSStatus (*HostCallback_GetBeatAndTempo) (void		*inHostUserData, 
											Float64			*outCurrentBeat, 
											Float64			*outCurrentTempo);

typedef OSStatus (*HostCallback_GetMusicalTimeLocation) (void     *inHostUserData, 
												UInt32            *outDeltaSampleOffsetToNextBeat,
												Float32           *outTimeSig_Numerator,
												UInt32            *outTimeSig_Denominator,
												Float64           *outCurrentMeasureDownBeat);

typedef struct HostCallbackInfo {
	void *		hostUserData;
	HostCallback_GetBeatAndTempo beatAndTempoProc;
    HostCallback_GetMusicalTimeLocation     musicalTimeLocationProc;
} HostCallbackInfo;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Parameters

// assume kAudioUnitParameterUnit_Generic if not found in this enum
enum
{
	kAudioUnitParameterUnit_Generic				= 0,	/* untyped value generally between 0.0 and 1.0 */
	kAudioUnitParameterUnit_Indexed				= 1,	/* takes an integer value (good for menu selections) */
	kAudioUnitParameterUnit_Boolean				= 2,	/* 0.0 means FALSE, non-zero means TRUE */
	kAudioUnitParameterUnit_Percent				= 3,	/* usually from 0 -> 100, sometimes -50 -> +50 */
	kAudioUnitParameterUnit_Seconds				= 4,	/* absolute or relative time */
	kAudioUnitParameterUnit_SampleFrames		= 5,	/* one sample frame equals (1.0/sampleRate) seconds */
	kAudioUnitParameterUnit_Phase				= 6,	/* -180 to 180 degrees */
	kAudioUnitParameterUnit_Rate				= 7,	/* rate multiplier, for playback speed, etc. (e.g. 2.0 == twice as fast) */
	kAudioUnitParameterUnit_Hertz				= 8,	/* absolute frequency/pitch in cycles/second */
	kAudioUnitParameterUnit_Cents				= 9,	/* unit of relative pitch */
	kAudioUnitParameterUnit_RelativeSemiTones	= 10,	/* useful for coarse detuning */
	kAudioUnitParameterUnit_MIDINoteNumber		= 11,	/* absolute pitch as defined in the MIDI spec (exact freq may depend on tuning table) */
	kAudioUnitParameterUnit_MIDIController		= 12,	/* a generic MIDI controller value from 0 -> 127 */
	kAudioUnitParameterUnit_Decibels			= 13,	/* logarithmic relative gain */
	kAudioUnitParameterUnit_LinearGain			= 14,	/* linear relative gain */
	kAudioUnitParameterUnit_Degrees				= 15,	/* -180 to 180 degrees, similar to phase but more general (good for 3D coord system) */
	kAudioUnitParameterUnit_EqualPowerCrossfade = 16,	/* 0 -> 100, crossfade mix two sources according to sqrt(x) and sqrt(1.0 - x) */
	kAudioUnitParameterUnit_MixerFaderCurve1	= 17,	/* 0.0 -> 1.0, pow(x, 3.0) -> linear gain to simulate a reasonable mixer channel fader response */
	kAudioUnitParameterUnit_Pan					= 18,	/* standard left to right mixer pan */
	kAudioUnitParameterUnit_Meters				= 19,	/* distance measured in meters */
	kAudioUnitParameterUnit_AbsoluteCents		= 20,	/* absolute frequency measurement : if f is freq in hertz then 	*/
                                                        /* absoluteCents = 1200 * log2(f / 440) + 6900					*/
	kAudioUnitParameterUnit_Octaves				= 21,	/* octaves in relative pitch where a value of 1 is equal to 1200 cents*/
	kAudioUnitParameterUnit_BPM					= 22,	/* beats per minute, ie tempo */
    kAudioUnitParameterUnit_Beats               = 23,	/* time relative to tempo, ie. 1.0 at 120 BPM would equal 1/2 a second */
	kAudioUnitParameterUnit_Milliseconds		= 24	/* parameter is expressed in milliseconds */
};

typedef UInt32		AudioUnitParameterUnit;

// if the "unit" field contains a value not in the enum above, then assume kAudioUnitParameterUnit_Generic
typedef struct AudioUnitParameterInfo
{
#if TARGET_API_MAC_OSX
	char 					name[60];			// UTF8 encoded C string, may be treated as 64 characters
												// if kAudioUnitParameterFlag_HasCFNameString not set
	CFStringRef				cfNameString;		// only valid if kAudioUnitParameterFlag_HasCFNameString set
#else
	char 					name[64];			// UTF8 encoded C string
#endif
	AudioUnitParameterUnit	unit;						
	Float32					minValue;			
	Float32					maxValue;			
	Float32					defaultValue;		
	UInt32					flags;				
} AudioUnitParameterInfo;

// flags for AudioUnitParameterInfo
enum
{
// -------------------------------
// THESE ARE DEPRECATED AS OF 10.2
	kAudioUnitParameterFlag_Global		= (1L << 0),	//	parameter scope is global
	kAudioUnitParameterFlag_Input		= (1L << 1),	//	parameter scope is input
	kAudioUnitParameterFlag_Output		= (1L << 2),	//	parameter scope is output
	kAudioUnitParameterFlag_Group		= (1L << 3),	//	parameter scope is group
// -------------------------------
 // new for 10.2 and AUv2
	kAudioUnitParameterFlag_IsHighResolution = (1L << 23),
	kAudioUnitParameterFlag_NonRealTime = (1L << 24),
	kAudioUnitParameterFlag_CanRamp 	= (1L << 25),
	kAudioUnitParameterFlag_ExpertMode = (1L << 26),
	kAudioUnitParameterFlag_HasCFNameString = (1L << 27),
	kAudioUnitParameterFlag_IsGlobalMeta = (1L << 28),
	kAudioUnitParameterFlag_IsElementMeta	= (1L << 29),
	kAudioUnitParameterFlag_IsReadable	= (1L << 30),
	kAudioUnitParameterFlag_IsWritable	= (1L << 31)
};

// new for 10.2
typedef struct AudioUnitMIDIControlMapping
{
	UInt16					midiNRPN;
	UInt8					midiControl;
	UInt8					scope;
	AudioUnitElement		element;
	AudioUnitParameterID	parameter;
} AudioUnitMIDIControlMapping;

#endif // __AudioUnitProperties
