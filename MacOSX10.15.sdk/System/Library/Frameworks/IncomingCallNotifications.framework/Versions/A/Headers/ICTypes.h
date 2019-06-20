//
//  ICTypes.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <IncomingCallNotifications/ICBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ICDeclineReason) {
    ICDeclineReasonGeneric,    // A generic decline, for example the decline button was pressed.
    ICDeclineReasonCancelled,  // The notification was cancelled.
    ICDeclineReasonUserBusy,   // The user was busy, such as another incoming call already being present.
    ICDeclineReasonUnanswered, // The notification was never responded to, and was automatically declined.
} API_AVAILABLE(ios(13.0));

NS_ASSUME_NONNULL_END
