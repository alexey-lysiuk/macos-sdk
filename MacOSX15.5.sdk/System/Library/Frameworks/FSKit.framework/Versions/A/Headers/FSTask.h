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

@end

NS_ASSUME_NONNULL_END
