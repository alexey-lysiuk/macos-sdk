/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_ENUMERATOR_H
#define LOGGING_OS_LOG_ENUMERATOR_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

@class OSLogPosition;

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum OSLogEnumeratorOptions
 *
 * @abstract
 * Control the direction of the iteration.
 *
 * @constant OSLogEnumeratorReverse
 * Iterate backward in time. If no starting position is specified,
 * start at the latest entry.
 */
typedef NS_OPTIONS(NSUInteger, OSLogEnumeratorOptions) {
    OSLogEnumeratorReverse                                  = 0x01,
}
API_AVAILABLE(macos(10.15))
NS_SWIFT_NAME(OSLogEnumerator.Options);

/*!
 * @class OSLogEnumerator
 *
 * @abstract
 * An enumerator that views entries in the unified logging system.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogEnumerator : NSEnumerator

/*!
 * @property currentPosition
 *
 * @abstract
 * The position of the last entry yielded by the enumerator.
 *
 * @discussion
 * A second enumerator can be created with the same OSLogStore and
 * this position.
 */
@property (nonatomic, readonly) OSLogPosition *currentPosition;

@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_ENUMERATOR_H */
