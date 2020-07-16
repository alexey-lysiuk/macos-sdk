//
//  MorphunAssetsUpdater.h
//  MorphunAssetsUpdater
//
//  Created by Nolan Kramer on 2/16/20.
//  Copyright © 2020 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for MorphunAssetsUpdater.
FOUNDATION_EXPORT double MorphunAssetsUpdaterVersionNumber;

//! Project version string for MorphunAssetsUpdater.
FOUNDATION_EXPORT const unsigned char MorphunAssetsUpdaterVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MorphunAssetsUpdater/PublicHeader.h>

static NSString* const MorphunDomain = @"MorphunAssetsUpdaterDaemon";

enum MUError {
    MU_XPC_OBJECT_CREATION_FAILURE = 0,
    MU_XPC_TIMEOUT,
    MU_XPC_CONNECTION_INVALID,
    MU_XPC_CONNECTION_INTERRUPTED,
    MU_XPC_PROTOCOL_ERROR,
    MU_XPC_INVALID_MESSAGE
};

@interface MorphunAssetsUpdater : NSObject

+ (NSError*)forceUpdate: (BOOL)synchronous updateLanguages:(NSArray*)updateLanguages removeLanguages:(NSArray*)removeLanguages;
+ (NSDictionary<NSString*, NSString*>*)getPaths: (NSError**)error;

@end
