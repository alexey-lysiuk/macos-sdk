/*
 *
 *  GameKit.h
 *  GameKit
 *
 */


// Game Center cross-platform headers
#import <GameKit/GKAchievement.h>
#import <GameKit/GKAchievementDescription.h>
#import <GameKit/GKDefines.h>
#import <GameKit/GKError.h>
#import <GameKit/GKLeaderboard.h>
#import <GameKit/GKLocalPlayer.h>
#import <GameKit/GKMatch.h>
#import <GameKit/GKTurnBasedMatch.h>
#import <GameKit/GKMatchmaker.h>
#import <GameKit/GKPlayer.h>
#import <GameKit/GKScore.h>
#import <GameKit/GKVoiceChat.h>
#import <GameKit/GKNotificationBanner.h>
#import <GameKit/GKMatchmakerViewController.h>
#import <GameKit/GKTurnBasedMatchmakerViewController.h>
#import <GameKit/GKLeaderboardViewController.h>
#import <GameKit/GKAchievementViewController.h>
#import <GameKit/GKFriendRequestComposeViewController.h>

#if TARGET_OS_IPHONE
// GameKit 3.0 iOS (Deprecated)
#import <GameKit/GKPeerPickerController.h>
#import <GameKit/GKPublicConstants.h>
#import <GameKit/GKPublicProtocols.h>
#import <GameKit/GKSession.h>
#import <GameKit/GKSessionError.h>
#import <GameKit/GKVoiceChatService.h>

#else

#import <GameKit/GKDialogController.h>

#endif
