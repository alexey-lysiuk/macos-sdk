//
//  SWRemoveParticipantAlert.h
//  SWRemoveParticipantAlert
//
//  Copyright (c) 2022 Apple. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <SharedWithYouCore/SWDefines.h>

@class SWCollaborationHighlight;
@class SWPerson;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0))
SW_EXTERN @interface SWRemoveParticipantAlert : NSObject

+ (void)showAlertWithParticipant:(SWPerson *)participant highlight:(SWCollaborationHighlight *)highlight inWindow:(nullable NSWindow *)window;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
