// Copyright © Apple Inc. All rights reserved.

#import <TargetConditionals.h>
#import <GameKit/GKLocalPlayer.h>
#import <GameKit/GKSavedGameListener.h>

/// Class representing a saved game for the local player, or a version of a saved game when in conflict
API_AVAILABLE(macos(10.10), ios(8.0)) API_UNAVAILABLE(tvos, watchos)
@interface GKSavedGame : NSObject <NSCopying>

NS_ASSUME_NONNULL_BEGIN

@property (atomic, nullable, readonly) NSString *name;
@property (atomic, nullable, readonly) NSString *deviceName;
@property (atomic, nullable, readonly) NSDate *modificationDate;

/// Asynchronously load the data for this saved game. The completion handler is called with loaded data or an error.
- (void)loadDataWithCompletionHandler:(void(^__nullable)(NSData * __nullable data, NSError * __nullable error))handler;

@end

API_UNAVAILABLE(tvos, watchos)
@interface GKLocalPlayer (GKSavedGame) <GKSavedGameListener>

/// Asynchronously fetch saved games. The handler is called with an array of GKSavedGame objects or an error.
/// If there is more than one saved game with the same name then a conflict exists. The application should determine the correct data to use and call resolveConflictingSavedGames:withData:completionHandler:. This may require data merging or asking the user.
- (void)fetchSavedGamesWithCompletionHandler:(void(^__nullable)(NSArray<GKSavedGame *> * __nullable savedGames, NSError * __nullable error))handler API_AVAILABLE(macos(10.10), ios(8.0)) API_UNAVAILABLE(tvos, watchos);

/// Asynchronously save game data. If a saved game with that name already exists it is overwritten, otherwise a new one is created. The completion handler is called with the new / modified GKSavedGame or an error.
/// If the saved game was in conflict then the overwritten version will be the one with the same deviceName if present, otherwise the most recent overall.
- (void)saveGameData:(NSData *)data withName:(NSString *)name completionHandler:(void(^__nullable)(GKSavedGame * __nullable savedGame, NSError * __nullable error))handler API_AVAILABLE(macos(10.10), ios(8.0)) API_UNAVAILABLE(tvos, watchos);

/// Asynchronously delete saved games with the given name. The completion handler will indicate whether or not the deletion was successful.
- (void)deleteSavedGamesWithName:(NSString *)name completionHandler:(void(^__nullable)(NSError * __nullable error))handler API_AVAILABLE(macos(10.10), ios(8.0)) API_UNAVAILABLE(tvos, watchos);

/// Asynchronously resolve a saved game conflict. This deletes all versions included in conflictingSavedGames and creates a new version with the given data. The completion handler is called with the newly created save and all other remaining versions or an error.
- (void)resolveConflictingSavedGames:(NSArray<GKSavedGame *> *)conflictingSavedGames withData:(NSData *)data completionHandler:(void(^__nullable)(NSArray<GKSavedGame *> * __nullable savedGames, NSError * __nullable error))handler API_AVAILABLE(macos(10.10), ios(8.0)) API_UNAVAILABLE(tvos, watchos);

@end

NS_ASSUME_NONNULL_END
