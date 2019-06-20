/*==================================================================================================
 File:       CHHapticEngine.h
 
 Contains:   API for CHHapticEngine
 
 Copyright:  (c) 2018 by Apple, Inc., all rights reserved.
 
 Bugs?:      For bug reports, consult the following page on
 the World Wide Web:
 
 http://developer.apple.com/bugreporter/
 
 ==================================================================================================*/

#import <Foundation/NSObjCRuntime.h>
#import <CoreHaptics/CHHapticEvent.h>
#import <CoreHaptics/CHHapticPatternPlayer.h>

#define CH_EXPORT __attribute__((visibility("default"))) extern

NS_ASSUME_NONNULL_BEGIN

/*! @define CHHapticTimeImmediate
    @abstract
        A floating point constant representing the time "as soon as possible". This time value should be used
        whenever an app wishes to schedule a command at the soonest possible moment without the need to
        synchronize with other media.
 */
#define CHHapticTimeImmediate (NSTimeInterval)0.0f

@class CHHapticPattern;
@class AVAudioSession;
@protocol CHHapticDeviceCapability;

/*!	@typedef CHHapticCompletionHandler
	@abstract
		A block which is called asynchronously when a call to start or stop the haptic engine completes.
	@param error
		If the call fails, this is set to a valid NSError describing the error.
	@discussion
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
typedef void (^CHHapticCompletionHandler)(NSError *_Nullable error);

/*!	@typedef CHHapticTimeoutHandler
	@abstract
		A block which is called asynchronously when the engine detects that it has been idle for a period of time.
	@param error
		If the engine times out due to an error, this is set to a valid NSError describing the error.
	@discussion
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
typedef BOOL (^CHHapticTimeoutHandler)(NSError *_Nullable error);

/*!	@enum CHHapticEngineStoppedReason
 	@abstract
 		Constants indicating the reason why the CHHapticEngine has stopped.
 
 	@constant	CHHapticEngineStoppedReasonAudioSessionInterrupt
		The AVAudioSession bound to this engine has been interrupted.
 
 	@constant	CHHapticEngineStoppedReasonApplicationSuspended
 		The application owning this engine has been suspended (i.e., put into the background).
 
 	@constant	CHHapticEngineStoppedReasonIdleTimeout
 		The engine has stopped due to an idle timeout, or the client has exceeded the number of
 		timeout postponements and the engine has stopped for power considerations.  See `CHHapticTimeoutHandler`.
 
 	@constant	CHHapticEngineStoppedReasonSystemError
 		An error has occurred.
 */

typedef NS_ENUM(NSInteger, CHHapticEngineStoppedReason) {
	CHHapticEngineStoppedReasonAudioSessionInterrupt	= 1,
	CHHapticEngineStoppedReasonApplicationSuspended		= 2,
	CHHapticEngineStoppedReasonIdleTimeout				= 3,
	CHHapticEngineStoppedReasonSystemError				= -1
};

/*!	@typedef CHHapticEngineStoppedHandler
	@abstract
		A block which is called asynchronously when the engine has stopped due to external causes (such as
 		an audio session interruption) or due to the client exceeding their timeout-postponement limit.
	@param stoppedReason
		This constant indicates the reason why the engine stopped.
	@discussion
		This handler is NOT called if the client directly calls stopWithCompletionHandler:.
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
typedef void (^CHHapticEngineStoppedHandler)(CHHapticEngineStoppedReason stoppedReason);

/*!	@typedef CHHapticEngineResetHandler
	@abstract
		A block which is called asynchronously if the haptic engine had to reset itself after a server failure.
	@discussion
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
typedef void (^CHHapticEngineResetHandler)(void);

/*!	@class CHHapticEngine
	@abstract
		Represents the connection with the haptic server.
 */
CH_EXPORT API_AVAILABLE(ios(13.0), macos(10.15))
@interface CHHapticEngine : NSObject

+ (id<CHHapticDeviceCapability>)capabilitiesForHardware;

/*!
	@property currentTime
		The absolute time from which all current and future event times may be calculated.
		The units are seconds.
 */
@property (readonly) NSTimeInterval currentTime;

/*!	@property timeoutHandler
	@abstract
		The engine will call this block when it has detected that it has been idle for a period of time.
 		Idle in this context means that no haptic pattern is currently active.
	@discussion
		The client's handler block should return YES if no new haptic request is immediately pending, and NO if they need
 		the engine to continue running.  If YES is returned, the client can restart the engine at any future time.
 		Multiple requests to keep the engine running may eventually be denied due to power restrictions, in which case
 		the client will need to restart the engine.
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
@property (readwrite,atomic) CHHapticTimeoutHandler timeoutHandler;

/*!	@property stoppedHandler
	@abstract
		The engine will call this block when it has stopped due to external causes (such as
		an audio session interruption) or due to the client exceeding their timeout-postponement
 		limit. This is NOT called if the client calls stopWithCompletionHandler:.  See `CHHapticTimeoutHandler`.
	@discussion
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle
		it in a thread-safe manner.
 */

@property (readwrite,atomic) CHHapticEngineStoppedHandler stoppedHandler;

/*!	@property resetHandler
	@abstract
		This block will called asynchronously if the haptic engine has to reset itself after a server failure.
	@discussion
 		In response to this handler being called, the client must release all haptic pattern players
 		and recreate them.  All CHHapticPattern objects and CHHapticEngine properties will have been preserved.
 		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle
		it in a thread-safe manner.
 */
@property (readwrite,atomic) CHHapticEngineResetHandler resetHandler;

/*!
	@property hapticsOnly
		If set to YES, the CHHapticEngine will ignore all events of type CHHapticEventTypeAudio and play only haptic events.
	@discussion
		This behavior change will only take effect after the engine is stopped and restarted.
		The default is NO.
 */
@property (readwrite,nonatomic) BOOL hapticsOnly;

/*!
	@property muteHapticsWhileRecordingAudio
		When set to YES, the CHHapticEngine mutes all haptics when any system on the device enters audio record mode.
	@discussion
		Muting will stop when the device leaves record mode.
 		Default is YES.
 */
@property (readwrite,nonatomic) BOOL muteHapticsWhileRecordingAudio;

/*!
 	@property audioIsMuted
 		When set to YES, the CHHapticEngine mutes all its audio events.
 	@discussion
 		Default is NO.
 */
@property (readwrite,nonatomic) BOOL audioIsMuted;

/*!
 	@property hapticsIsMuted
 		When set to YES, the CHHapticEngine mutes all its haptic events.
 	@discussion
 		Default is NO.
 */
@property (readwrite,nonatomic) BOOL hapticsIsMuted;

- (nullable instancetype)init NS_UNAVAILABLE;

/*! @method initAndReturnError:
	@abstract
		Create an instance of the CHHapticEngine.
	@discussion
		More than one instance may exist within a process.  Each will function independently of the others.
 */
- (nullable instancetype)initAndReturnError:(NSError **)error NS_DESIGNATED_INITIALIZER;

/*! @method initWithAudioSession:error
	@abstract
		Create an instance of the CHHapticEngine and associate it with an audio session.  If 'audioSession' is nil,
 		the engine will create its own.
	@discussion
		More than one instance may exist within a process.  Each will function independently of the others, but all
 		CHHapticEngines which share an audio session will have identical audio behavior with regard to interruptions, etc.
 */
- (nullable instancetype)initWithAudioSession:(nullable AVAudioSession *)audioSession error:(NSError **)error NS_DESIGNATED_INITIALIZER;

/*! @method startWithCompletionHandler:
	@abstract
		Asynchronously start the engine.
 	@discussion
 		The handler is guaranteed to be called on either success or failure.
 */
- (void)startWithCompletionHandler:(CHHapticCompletionHandler _Nullable)completionHandler;

/*! @method startAndReturnError:
	@abstract
		Start the engine and block until the engine has started.
 	@discussion
 		This method will return NO upon failure, and outError will be set to a valid NSError describing the error.
 */
- (BOOL)startAndReturnError:(NSError **)outError;

/*! @method stop:
	@abstract
		Asynchronously stop the engine.
	@discussion
		The handler is guaranteed to be called on either success or failure.
 */
- (void)stopWithCompletionHandler:(CHHapticCompletionHandler _Nullable)completionHandler;

/*! @method createPlayerWithPattern:error
	@abstract
		Factory method for creating a CHHapticPatternPlayer from a CHHapticPattern.
	@param pattern
		The pattern to be played.
 */
- (nullable id<CHHapticPatternPlayer>)createPlayerWithPattern:(CHHapticPattern *)pattern
																	error:(NSError **)outError;

/*! @method createAdvancedPlayerWithPattern:error
	@abstract
		Factory method for creating a CHHapticAdvancedPatternPlayer from a CHHapticPattern.
	@param pattern
		The pattern to be played.
 */
- (nullable id<CHHapticAdvancedPatternPlayer>)createAdvancedPlayerWithPattern:(CHHapticPattern *)pattern
																		error:(NSError **)outError;

/*! @method registerAudioResource:options:error
	@abstract
		Register an external audio file for use as a custom waveform.
	@param resourceURL
 		A URL referencing the location of the audio file to be registered.
 	@param options
 		A dictionary containing key/value pairs describing how this resource should be played.
 	@param outError
 		If register operation fails, this will be set to a valid NSError describing the error.
 */
- (CHHapticAudioResourceID)registerAudioResource:(NSURL *)resourceURL
										 options:(NSDictionary *)options
										   error:(NSError **)outError __attribute__((swift_error(zero_result)));

/*!	@method unregisterAudioResource:error
 	@abstract
 		Unregister and remove a previously-registered audio resource.
 	@param resourcedID
 		The resource ID that was returned when the resource was registered.
 	@param outError
 		If the unregister operation fails, this will be set to a valid NSError describing the error.
 */
- (BOOL)unregisterAudioResource:(CHHapticAudioResourceID)resourceID
						  error:(NSError **)outError;

/*! @method playPatternFromURL:error
	@abstract
		Simple one-shot call to play a pattern specified by a URL.
 	@param fileURL
 		The URL of the file containing a haptic/audio pattern dictionary.
 	@param outError
 		If the operation fails, this will be set to a valid NSError describing the error.
 	@discussion
 		The engine should be started prior to calling this method if low latency is desired. If this is not done,
 		this method will start it, which can cause a significant delay.
 */
- (BOOL)playPatternFromURL:(NSURL *)fileURL
					 error:(NSError **)outError;

/*! @method playPatternFromData:error
 	@abstract
 		Simple one-shot call to play a pattern specified by NSData.
	@param data
 		The NSData containing a haptic/audio pattern dictionary.
 	@param outError
 		If the operation fails, this will be set to a valid NSError describing the error.
 	@discussion
 		The engine should be started prior to calling this method if low latency is desired. If this is not done,
 		this method will start it, which can cause a significant delay.
 */
- (BOOL)playPatternFromData:(NSData *)data
					  error:(NSError **)outError;

@end

NS_ASSUME_NONNULL_END
