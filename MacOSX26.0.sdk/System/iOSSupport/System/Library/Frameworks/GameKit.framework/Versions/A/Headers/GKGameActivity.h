// Copyright © Apple Inc. All rights reserved.

#import <TargetConditionals.h>

#if !TARGET_OS_WATCH

#import <Foundation/Foundation.h>
#import <GameKit/GKGameActivityState.h>
#import <TargetConditionals.h>

@class GKAchievement;
@class GKGameActivityDefinition;
@class GKLeaderboard;
@class GKLeaderboardScore;
@class GKMatch;
@class GKMatchRequest;
@class GKPlayer;
@class GKTurnBasedMatch;
NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
/// `GKGameActivity` represents a single instance of a game activity for the current game.
NS_SWIFT_SENDABLE @interface GKGameActivity : NSObject

/// The identifier of this activity instance.
@property (nonatomic, readonly, copy) NSString *identifier;

/// The activity definition that this activity instance is based on.
@property (nonatomic, readonly, strong) GKGameActivityDefinition *activityDefinition;

/// Properties that contain additional information about the activity.
///
/// This takes precedence over the `defaultProperties` on the `activityDefinition`.
///
/// 1. This dictionary is initialized with the default properties from the activity definition and deep linked properties if any.
/// 2. If deep linking contains the same key as the default properties, the deep linked value will override the default value.
/// 3. The properties can be updated at runtime.
@property (nonatomic, readwrite, copy) NSDictionary<NSString *, NSString *> *properties;

/// The state of the game activity.
@property (nonatomic, readonly, assign) GKGameActivityState state;

/// If the game supports party code, this is the party code that can be shared among players to join the party.
///
/// If the game does not support party code, this value will be nil.
/// - SeeAlso: ``-[GKGameActivity startWithDefinition:partyCode:completionHandler:]`` for creating a game activity with a custom party code.
@property (nonatomic, readonly, copy, nullable) NSString *partyCode;

/// If the game supports party code, this is the URL that can be shared among players to join the party.
@property (nonatomic, readonly, strong, nullable) NSURL *partyURL;

/// The date when the activity was created.
@property (nonatomic, readonly, strong) NSDate *creationDate;

/// The date when the activity was initially started.
@property (nonatomic, readonly, strong, nullable) NSDate *startDate;

/// The date when the activity was last resumed.
///
/// - If the activity was first started, this will be the same as the start date.
/// - If the activity was paused and resumed, this will be the date when the activity was resumed.
@property (nonatomic, readonly, strong, nullable) NSDate *lastResumeDate;

/// The date when the activity was officially ended.
@property (nonatomic, readonly, strong, nullable) NSDate *endDate;

/// Total time elapsed while in active state.
@property (nonatomic, readonly, assign) NSTimeInterval duration;

/// All achievements that have been associated with this activity.
///
/// Progress of each achievement will be reported when the activity ends.
@property(nonatomic, readonly, copy) NSSet<GKAchievement *> *achievements;

/// All leaderboard scores that have been associated with this activity.
///
/// Scores will be submitted to the leaderboards when the activity ends.
@property(nonatomic, readonly, copy) NSSet<GKLeaderboardScore *> *leaderboardScores;

/// Allowed characters for the party code to be used to share this activity.
@property(class, readonly, copy) NSArray<NSString *> *validPartyCodeAlphabet;

- (instancetype)init NS_UNAVAILABLE;

/// Creates and starts a new game activity with a custom party code.
///
/// The party code will be converted to uppercased.
+ (GKGameActivity * _Nullable)startWithDefinition:(GKGameActivityDefinition *)activityDefinition
                                        partyCode:(NSString *)partyCode
                                            error:(NSError **)error NS_SWIFT_NAME(start(definition:partyCode:));

/// Initializes and starts a game activity with definition.
+ (GKGameActivity * _Nullable)startWithDefinition:(GKGameActivityDefinition *)activityDefinition
                                            error:(NSError **)error NS_SWIFT_NAME(start(definition:));

/// Checks whether a party code is in valid format.
///
/// Party code should be two parts of strings with the same length (2-6) connected with a dash, and the code can be either pure digits (0-9), or both parts are uppercased characters from `validPartyCodeAlphabet`.
/// - SeeAlso: `validPartyCodeAlphabet` for allowed characters.
+ (BOOL)isValidPartyCode:(NSString *)partyCode;

/// Initializes a game activity with definition.
- (instancetype)initWithDefinition:(GKGameActivityDefinition *)activityDefinition;

/// Starts the game activity if it is not already started.
- (void)start;

/// Pauses the game activity if it is not already paused.
- (void)pause;

/// Resumes the game activity if it was paused.
- (void)resume;

/// Ends the game activity if it is not already ended.
///
/// This will report all associated achievements and submit scores to leaderboards.
- (void)end;

/// Set a score of a leaderboard with a context for a player.
///
/// The score will be submitted to the leaderboard when the activity ends.
- (void)setScoreOnLeaderboard:(GKLeaderboard *)leaderboard
                      toScore:(NSInteger)score
                      context:(NSUInteger)context NS_SWIFT_NAME(setScore(on:to:context:));

/// Set a score of a leaderboard for a player.
///
/// The score will be submitted to the leaderboard when the activity ends.
- (void)setScoreOnLeaderboard:(GKLeaderboard *)leaderboard
                      toScore:(NSInteger)score NS_SWIFT_NAME(setScore(on:to:));

/// Get the leaderboard score from a specific leaderboard of the local player if previously set.
- (GKLeaderboardScore * _Nullable)getScoreOnLeaderboard:(GKLeaderboard *)leaderboard NS_SWIFT_NAME(score(on:));

/// Removes all scores from leaderboards for a player if exist.
- (void)removeScoresFromLeaderboards:(NSArray<GKLeaderboard *> *)leaderboards NS_SWIFT_NAME(removeScores(from:));

/// Set a progress for an achievement for a player.
///
/// Achievement progress will be reported when the activity ends.
- (void)setProgressOnAchievement:(GKAchievement *)achievement
               toPercentComplete:(double)percentComplete NS_SWIFT_NAME(setProgress(on:to:));

/// Convenience method to set a progress to 100% for an achievement for a player.
///
/// Achievement completion will be reported when the activity ends.
- (void)setAchievementCompleted:(GKAchievement *)achievement NS_SWIFT_NAME(setAchievementCompleted(_:));

/// Get the achievement progress from a specific achievement of the local player if previously set.
/// 
/// Returns 0 if the achievement has not been set in the current activity.
- (double)getProgressOnAchievement:(GKAchievement *)achievement NS_SWIFT_NAME(progress(on:));

/// Removes all achievements if exist.
- (void)removeAchievements:(NSArray<GKAchievement *> *)achievements NS_SWIFT_NAME(removeAchievements(_:));
@end

#if __LP64__
API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
@interface GKGameActivity (Multiplayer)

/// Makes a `GKMatchRequest` object with information from the activity, which can be used to find matches for the local player.
- (GKMatchRequest * _Nullable)makeMatchRequest;

/// Use information from the activity to find matches for the local player.
///
/// GameKit will create a classic match making request with the activity's party code and other information, and return the match object in the completion handler or any error that occurred.
/// Error occurs if this activity doesn't support party code, or has unsupported range of players, which is used to be configured as match request's minPlayers and maxPlayers.
- (void)findMatchWithCompletionHandler:(void(^)(GKMatch * _Nullable match,
                                                NSError * _Nullable error))completionHandler NS_SWIFT_NAME(findMatch(completionHandler:));

/// Use information from the activity to find server hosted players for the local player.
///
/// GameKit will create a classic server hosted match making request with the activity's party code and other information, and return the players in the completion handler or any error that occurred.
/// Error occurs if this activity doesn't support party code, or has unsupported range of players, which is used to be configured as match request's minPlayers and maxPlayers.
- (void)findPlayersForHostedMatchWithCompletionHandler:(void(^)(NSArray<GKPlayer *> * _Nullable players,
                                                                NSError * _Nullable error))completionHandler NS_SWIFT_NAME(findPlayersForHostedMatch(completionHandler:));

@end
#endif

API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
@interface GKGameActivity (State)

/// Checks whether there is a pending activity to handle for the current game.
+ (void)checkPendingGameActivityExistenceWithCompletionHandler:(void(^)(BOOL))completionHandler NS_SWIFT_ASYNC_NAME(getter:hasPendingGameActivities());

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // #if !TARGET_OS_WATCH
