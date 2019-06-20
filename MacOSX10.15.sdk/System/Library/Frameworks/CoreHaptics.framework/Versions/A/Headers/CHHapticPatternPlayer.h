/*==================================================================================================
 File:       CHHapticPatternPlayer.h
 
 Contains:   API for playing haptic patterns
 
 Copyright:  (c) 2018 by Apple, Inc., all rights reserved.
 
 Bugs?:      For bug reports, consult the following page on
 the World Wide Web:
 
 http://developer.apple.com/bugreporter/
 
 ==================================================================================================*/

#import <Foundation/NSArray.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSObjCRuntime.h>

#define CH_EXPORT __attribute__((visibility("default"))) extern

@class CHHapticDynamicParameter;
@class CHHapticParameterCurve;

NS_ASSUME_NONNULL_BEGIN

/*!	@protocol CHHapticPatternPlayer
	@abstract
		A protocol which defines operations for starting, stopping, and sending parameters to a pattern player.
	@discussion
		Instances of these objects are created via the factory methods such as `CHHapticEngine(createPlayerWithPattern:error)`.
 */
CH_EXPORT API_AVAILABLE(ios(13.0), macos(10.15))
@protocol CHHapticPatternPlayer <NSObject>

/*! @method startAtTime:error
	@abstract
		Start playing the pattern at the specified time (see `CHHapticEngine(currentTime)`).
		If 'time' is set to 'CHHapticTimeImmediate', the pattern is started as soon as possible.
 */
- (BOOL)startAtTime:(NSTimeInterval)time error:(NSError **)outError;

/*! @method stopAtTime:error
	@abstract
		Stop playing the pattern at the specified time (see `CHHapticEngine(currentTime)`).
		If 'time' is set to 'CHHapticTimeImmediate', the pattern is stopped as soon as possible.
 */
- (BOOL)stopAtTime:(NSTimeInterval)time error:(NSError **)outError;

/*! @method sendParameters:atTime:error
	@abstract
		Send an array of CHHapticDynamicParameters, starting at the specified time (see `CHHapticEngine(currentTime)`).
		If 'time' is set to 'CHHapticTimeImmediate', the parameters are sent as soon as possible.
 */
- (BOOL)sendParameters:(NSArray<CHHapticDynamicParameter *> *)parameters
				atTime:(NSTimeInterval)time
				 error:(NSError **)outError;

/*! @method scheduleParameterCurve:atTime:error
 	@abstract
 		Schedule a CHHapticParameterCurve, starting at the specified time (see `CHHapticEngine(currentTime)`).
 		If 'time' is set to 'CHHapticTimeImmediate', the parameter curve is scheduled as soon as possible.
 	@discussion
 		This method overrides the relativeTime property of the passed-in CHHapticParameterCurve,
 		setting it to the method's 'time' argument. All the curve's control point times will then be
 		calculated relative to that time.
 */

- (BOOL)scheduleParameterCurve:(CHHapticParameterCurve *)parameterCurve
						atTime:(NSTimeInterval)time
						 error:(NSError **)outError;

/*! @method cancelAndReturnError:
	@abstract
		Removes all pending commands and stops the player as soon as possible.
 */

- (BOOL)cancelAndReturnError:(NSError **)outError;

/*! @property isMuted
	@abstract
		When set to YES, all audio and haptic output will be silenced.
 */
@property (readwrite) BOOL isMuted;

@end

/*!	@typedef CHHapticAdvancedPatternPlayerCompletionHandler
	@abstract
		Block which is called asynchronously when a CHHapticAdvancedPatternPlayer finishes playing.
	@param error
		If the call to start the player fails, this is set to a valid NSError describing the error.
	@discussion
		In general, callbacks arrive on a non-main thread and it is the client's responsibility to handle them
		in a thread-safe manner.
 */
typedef void (^CHHapticAdvancedPatternPlayerCompletionHandler)(NSError *_Nullable error);

/*!	@protocol CHHapticAdvancedPatternPlayer
	@abstract
		A protocol which defines operations for pausing, resuming, seeking, and sending parameters to a pattern player.
	@discussion
		Instances of these objects are created via the factory methods such as `CHHapticEngine(createAdvancedPlayerWithPattern:error)`.
 */
CH_EXPORT API_AVAILABLE(ios(13.0), macos(10.15))
@protocol CHHapticAdvancedPatternPlayer<CHHapticPatternPlayer>

- (BOOL)prepareAndReturnError:(NSError **)outError;

/*! @method pauseAtTime:error
	@abstract
		Pause playback of the pattern at the specified time (see `CHHapticEngine(currentTime)`).
		If 'time' is set to 'CHHapticTimeImmediate', the pattern is paused immediately.
 */
- (BOOL)pauseAtTime:(NSTimeInterval)time error:(NSError **)outError;

/*! @method resumeAtTime:error
	@abstract
		Resume playback on a previously-paused player at the specified time (see `CHHapticEngine(currentTime)`).
		Playback will resume at the exact point in the pattern at which it was paused.
		If 'time' is set to 'CHHapticTimeImmediate', the pattern is resumed as soon as possible.
 */
- (BOOL)resumeAtTime:(NSTimeInterval)time error:(NSError **)outError;

/*! @method seekToOffset:error
	@abstract
		Set the playback position on an active player to the specified offset time.
		If 'offsetTime' is set to 0.0, the pattern will start from the beginning.  If
		set to >= the duration of the pattern, playback will terminate as soon as possible.
 */
- (BOOL)seekToOffset:(NSTimeInterval)offsetTime error:(NSError **)outError;

/*! @property loopEnabled
	@abstract
		When set to YES, the player will loop back to the beginning of the pattern whenever it
		reaches the loopEnd.
 */
@property (readwrite) BOOL loopEnabled;

/*! @property loopEnd
	@abstract
 		The time in seconds at which the pattern will loop back if looping is enabled.  If set to 0.0,
        the length will be set to the end of the last event in the pattern.
 */
@property (readwrite) NSTimeInterval loopEnd;

/*! @property playbackRate
	@abstract
		Allows a pattern to be played back at any multiple of its normal rate.  The rate can be adjusted
		at any point before or during pattern playback.  Note that this rate factor scales the relative
		times of all events and parameters as they are played, as well as the durations of Continuous events.
 		It does not affect the pitches of the events.
 */
@property (readwrite) float playbackRate;

/*! @property isMuted
	@abstract
		When set to YES, all audio and haptic output will be silenced.
 */
@property (readwrite) BOOL isMuted;

/*! @property completionHandler
	@abstract
		The block or enclosure that will be called when the player finishes.
 */
@property (readwrite) CHHapticAdvancedPatternPlayerCompletionHandler completionHandler;

@end

NS_ASSUME_NONNULL_END

