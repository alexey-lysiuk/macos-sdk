//
//  GKDialogController.h
//  Game Center
//
//  Copyright 2012-2023 Apple Inc. All rights reserved.
//

#if !TARGET_OS_MACCATALYST
#ifndef GKDialogController_h
#define GKDialogController_h

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GKViewController
@end

@interface GKDialogController : NSResponder

@property (weak, nullable) IBOutlet NSWindow *parentWindow;

- (BOOL)presentViewController:(NSViewController<GKViewController>  *)viewController;
- (IBAction)dismiss:(id)sender;

@end

@interface GKDialogController (SharedDialogController)
+ (GKDialogController *)sharedDialogController;
@end

NS_ASSUME_NONNULL_END

#endif
#endif
