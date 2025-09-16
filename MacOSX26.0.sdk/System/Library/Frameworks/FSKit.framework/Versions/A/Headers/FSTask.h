//
//  Copyright (c) 2024 Apple Inc.  All rights reserved.
//
//  FSTask.h
//  FSKit
//

#import <FSKit/FSKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// A class that enables a file system module to pass log messages and completion notifications to clients.
///
/// FSKit creates an instance of this class for each long-running operations.
FSKIT_API_AVAILABILITY_V1
@interface FSTask : NSObject

/// Logs the given string to the initiating client.
///
/// - Parameter str: The string to log.
- (void)logMessage:(NSString *)str FSKIT_API_AVAILABILITY_V1;

/// Informs the client that the task completed.
///
/// - Parameter error: `nil` if the task completed successfully; otherwise, an error that caused the task to fail.
- (void)didCompleteWithError:(NSError * _Nullable)error FSKIT_API_AVAILABILITY_V1 NS_SWIFT_NAME(didComplete(error:));

/// The cancellation handler will be called when the given task has been canceled.
///
/// The cancellation handler will be called wtihin an independent execution context. The cancellationHandler property is cleared after a task is canceled or completed. This is to accelerate the cleanup of retained state.
///
/// The exact structuring of the completion handler depends on the structuring of the code imlementing the task.
/// As a concrete example, consider a check operation with the following class:
///
/// ```obj-c
/// @ interface yourFileSystemChecker : NSObject
/// @property (retain) dispatch_group_t work_group;
/// @property (nonatomic,getter=interrupted) BOOL interrupted;
/// - (void)performCheck:(FSTask *)task
///             progress:(NSProgress *)progress;
/// @ end
/// ```
///
/// and a startCheckWithTask:(FSTask *)task like:

/// ```obj-c
/// {
/// NSProgress *progress = [[NSProgress alloc] init];
/// yourFileSystemChecker *checker= [[yourFileSystemChecker alloc] init];
/// checker.work_group = dispatch_group_create();
/// dispatch_group_enter(checker.work_group);
/// [task setCancellationHandler:^NSError * _Nullable{
///     checker.terminate = TRUE;
///     dispatch_group_wait(checker.work_group);
///     return nil;
/// }];
/// dispatch_async(someQueue, ^{[self performCheck:task progress:progress];});
/// return progress;
/// }
/// ```
///
/// > Note: this example did not account for errors while delivered code must. finally, the `performCheck`
/// code should perform the check operation. It should periodically update the progress object and check
/// its `interrupted` variable. The check can either complete successfully, complete with an error, or
/// be interrupted. It should then call `[task didCompleteWithError:...]` wtih the appropriate
/// error value or nil. Finally it should `dispatch_group_leave(self.work_group);`
///
/// - Returns: An error if the cancellation did not complete successfully. Any returned error will be logged, and FSKit will then terminate all activity in the container.
///
@property (nullable, copy) NSError * _Nullable(^NS_SWIFT_SENDABLE  cancellationHandler)(void) FSKIT_API_AVAILABILITY_V2;

@end

NS_ASSUME_NONNULL_END
