/*
 *  GKError.h
 *  GameKit
 *
 *  Copyright 2010 Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <GameKit/GKDefines.h>

extern NSString *GKErrorDomain;

enum {
    GKErrorUnknown                              = 1,
    GKErrorCancelled                            = 2,
    GKErrorCommunicationsFailure                = 3,
    GKErrorUserDenied                           = 4,
    GKErrorInvalidCredentials                   = 5,
    GKErrorNotAuthenticated                     = 6,
    GKErrorAuthenticationInProgress             = 7,
    GKErrorInvalidPlayer                        = 8,
    GKErrorScoreNotSet                          = 9,
    GKErrorParentalControlsBlocked              = 10,
    GKErrorMatchRequestInvalid                  = 13,
    GKErrorUnderage                             = 14,
    GKErrorGameUnrecognized                     = 15,
    GKErrorNotSupported                         = 16,
    GKErrorInvalidParameter                     = 17,
    GKErrorUnexpectedConnection                 = 18,
    GKErrorOffline                              = 19,
};
typedef NSInteger GKErrorCode;

