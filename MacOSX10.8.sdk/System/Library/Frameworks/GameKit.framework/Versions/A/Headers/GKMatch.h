//
//  GKMatch.h
//  GameKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GKVoiceChat;

@protocol GKMatchDelegate;

enum {
    GKMatchSendDataReliable,         // a.s.a.p. but requires fragmentation and reassembly for large messages, may stall if network congestion occurs
    GKMatchSendDataUnreliable        // Preferred method. Best effort and immediate, but no guarantees of delivery or order; will not stall.
};
typedef NSInteger GKMatchSendDataMode;

enum {
    GKPlayerStateUnknown,       // initial player state
    GKPlayerStateConnected,     // connected to the match
    GKPlayerStateDisconnected   // disconnected from the match
};
typedef NSInteger GKPlayerConnectionState;

// GKMatch represents an active networking sessions between players. It handles network communications and can report player connection status. All matches are created by a GKMatchmaker.
NS_CLASS_AVAILABLE(10_8, 4_1)
@interface GKMatch : NSObject
@end
@interface GKMatch (GKAdditions)
@property(readonly, NS_NONATOMIC_IOSONLY) NSArray *playerIDs;    // NSStrings of player identifiers in the match
@property(assign, NS_NONATOMIC_IOSONLY) id<GKMatchDelegate> delegate;
@property(readonly, NS_NONATOMIC_IOSONLY) NSUInteger expectedPlayerCount;

// Asynchronously send data to one or more players. Returns YES if delivery started, NO if unable to start sending and error will be set.
- (BOOL)sendData:(NSData *)data toPlayers:(NSArray *)playerIDs withDataMode:(GKMatchSendDataMode)mode error:(NSError **)error;
// Asynchronously broadcasts data to all players. Returns YES if delivery started, NO if unable to start sending and error will be set.
- (BOOL)sendDataToAllPlayers:(NSData *)data withDataMode:(GKMatchSendDataMode)mode error:(NSError **)error;

// Disconnect the match. This will show all other players in the match that the local player has disconnected. This should be called before releasing the match instance.
- (void)disconnect;

// Join a named voice chat channel
// Will return nil if parental controls are turned on
- (GKVoiceChat *)voiceChatWithName:(NSString *)name;

@end

@protocol GKMatchDelegate <NSObject>
@required
// The match received data sent from the player.
- (void)match:(GKMatch *)match didReceiveData:(NSData *)data fromPlayer:(NSString *)playerID;

@optional
// The player state changed (eg. connected or disconnected)
- (void)match:(GKMatch *)match player:(NSString *)playerID didChangeState:(GKPlayerConnectionState)state;

// The match was unable to connect with the player due to an error.
- (void)match:(GKMatch *)match connectionWithPlayerFailed:(NSString *)playerID withError:(NSError *)error;
// The match was unable to be established with any players due to an error.
- (void)match:(GKMatch *)match didFailWithError:(NSError *)error;

// This method is called when the match is interrupted; if it returns YES, a new invite will be sent to attempt reconnection. This is supported only for 1v1 games
- (BOOL)match:(GKMatch *)match shouldReinvitePlayer:(NSString *)playerID;

@end
