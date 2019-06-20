/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_ENTRY_BOUNDARY_H
#define LOGGING_OS_LOG_ENTRY_BOUNDARY_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class OSLogEntryBoundary
 *
 * @abstract
 * This entry represents metadata that partitions sequences of
 * other entries.
 *
 * @discussion
 * For example, this kind of entry is used for boot boundaries.
 * The data here are currently informational and carried in the
 * composedMessage property.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogEntryBoundary : OSLogEntry
@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_ENTRY_BOUNDARY_H */
