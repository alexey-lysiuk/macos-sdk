//
//  INSnoozeTasksTaskResolutionResult.h
//  Intents
//
//  Copyright (c) 2016-2019 Apple Inc. All rights reserved.
//

#import <Intents/INTaskResolutionResult.h>

typedef NS_ENUM(NSInteger, INSnoozeTasksTaskUnsupportedReason) {
    INSnoozeTasksTaskUnsupportedReasonNoTasksFound = 1,
} API_AVAILABLE(ios(13.0), watchos(6.0)) API_UNAVAILABLE(macosx);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), watchos(6.0))
API_UNAVAILABLE(macosx)
@interface INSnoozeTasksTaskResolutionResult : INTaskResolutionResult

+ (instancetype)unsupportedForReason:(INSnoozeTasksTaskUnsupportedReason)reason NS_SWIFT_NAME(unsupported(forReason:));

- (instancetype)initWithTaskResolutionResult:(INTaskResolutionResult *)taskResolutionResult;

@end

NS_ASSUME_NONNULL_END
