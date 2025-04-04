/*
	File:           AVFAudio.h
	Framework:      AVFoundation
	
	Copyright 2016 Apple Inc. All rights reserved.
*/

#import <AVFAudio/AVFAudio.h>

#import <AVFoundation/AVAudioSessionDeprecated.h>
#import <AVFoundation/AVAudioSessionRoute.h>
#import <AVFoundation/AVAudioSessionTypes.h>
#import <AVFoundation/AVAudioBuffer.h>
#import <AVFoundation/AVAudioChannelLayout.h>
#import <AVFoundation/AVAudioConnectionPoint.h>
#import <AVFoundation/AVAudioConverter.h>
#import <AVFoundation/AVAudioEngine.h>
#import <AVFoundation/AVAudioEnvironmentNode.h>
#import <AVFoundation/AVAudioFile.h>
#import <AVFoundation/AVAudioFormat.h>
#import <AVFoundation/AVAudioIONode.h>
#import <AVFoundation/AVAudioMixerNode.h>
#import <AVFoundation/AVAudioMixing.h>
#import <AVFoundation/AVAudioNode.h>
#import <AVFoundation/AVAudioPlayer.h>
#import <AVFoundation/AVAudioPlayerNode.h>
#import <AVFoundation/AVAudioRecorder.h>
#import <AVFoundation/AVAudioSequencer.h>
#import <AVFoundation/AVAudioSession.h>

#import <AVFoundation/AVAudioSettings.h>
#import <AVFoundation/AVAudioTime.h>
#import <AVFoundation/AVAudioTypes.h>
#import <AVFoundation/AVAudioUnit.h>
#import <AVFoundation/AVAudioUnitComponent.h>
#import <AVFoundation/AVAudioUnitDelay.h>
#import <AVFoundation/AVAudioUnitDistortion.h>
#import <AVFoundation/AVAudioUnitEQ.h>
#import <AVFoundation/AVAudioUnitEffect.h>
#import <AVFoundation/AVAudioUnitGenerator.h>
#import <AVFoundation/AVAudioUnitMIDIInstrument.h>
#import <AVFoundation/AVAudioUnitReverb.h>
#import <AVFoundation/AVAudioUnitSampler.h>
#import <AVFoundation/AVAudioUnitTimeEffect.h>
#import <AVFoundation/AVAudioUnitTimePitch.h>
#import <AVFoundation/AVAudioUnitVarispeed.h>
#import <AVFoundation/AVMIDIPlayer.h>

#import <AVFoundation/AVAudioSessionDeprecated.h>
#import <AVFoundation/AVAudioSessionRoute.h>
#import <AVFoundation/AVAudioSessionTypes.h>

#if TARGET_OS_OSX || TARGET_OS_MACCATALYST
#import <AVFoundation/AVAudioRoutingArbiter.h>
#endif // TARGET_OS_OSX || TARGET_OS_MACCATALYST

#if TARGET_OS_EMBEDDED || TARGET_OS_SIMULATOR
#import <AVFoundation/AVSpeechSynthesis.h>
#endif // TARGET_OS_IPHONE
