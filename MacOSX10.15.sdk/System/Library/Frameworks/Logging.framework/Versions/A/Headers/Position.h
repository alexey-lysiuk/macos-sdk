/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_POSITION_H
#define LOGGING_OS_LOG_POSITION_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class OSLogPosition
 *
 * @abstract
 * An opaque abstraction representing a point in a sequence of
 * entries in the unified logging system.
 *
 * @discussion
 * Generate positions with OSLogStore instance methods and use them
 * to start viewing entries from a particular starting point.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogPosition : NSObject
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_POSITION_H */
