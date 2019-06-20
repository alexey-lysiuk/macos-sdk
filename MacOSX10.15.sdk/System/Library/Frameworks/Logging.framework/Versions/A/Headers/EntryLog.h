/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_ENTRY_LOG_H
#define LOGGING_OS_LOG_ENTRY_LOG_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum OSLogEntryLogLevel
 *
 * @abstract
 * The level that this entry was generated at.
 */
typedef NS_ENUM(NSInteger, OSLogEntryLogLevel) {
    OSLogEntryLogLevelUndefined,
    OSLogEntryLogLevelDebug,
    OSLogEntryLogLevelInfo,
    OSLogEntryLogLevelNotice,
    OSLogEntryLogLevelError,
    OSLogEntryLogLevelFault,
}
API_AVAILABLE(macos(10.15))
NS_SWIFT_NAME(OSLogEntryLog.Level);

/*!
 * @class OSLogEntryLog
 *
 * @abstract
 * Entries made by the os_log API.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogEntryLog : OSLogEntry <OSLogEntryFromProcess, OSLogEntryWithPayload>

/*!
 * @property level
 *
 * @abstract
 * The level of the entry, e.g., info, debug.
 */
@property (nonatomic, readonly) OSLogEntryLogLevel level;

@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_ENTRY_LOG_H */
