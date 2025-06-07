//
//  INMessageReactionType.h
//  Intents
//
//  Copyright (c) 2016-2024 Apple Inc. All rights reserved.
//

#ifndef INMessageReactionType_h
#define INMessageReactionType_h

#import <Foundation/Foundation.h>
#import <Intents/IntentsDefines.h>

/// Constants that describe the type of the message reaction.
typedef NS_ENUM(NSInteger, INMessageReactionType) {
    INMessageReactionTypeUnknown = 0,
    INMessageReactionTypeEmoji,
    INMessageReactionTypeGeneric,
} API_AVAILABLE(ios(18.0), macos(15.0), watchos(11.0)) API_UNAVAILABLE(tvos);

#endif // INMessageReactionType_h
