/*
 * Copyright (c) 2018 Apple Inc. All rights reserved.
 */

#ifndef LOGGING_OS_LOG_STORE_H
#define LOGGING_OS_LOG_STORE_H

#ifndef __INDIRECT_LOGGING_HEADER_USER__
#error "Please use <Logging/Logging.h> instead of directly using this file."
#endif

typedef NS_OPTIONS(NSUInteger, OSLogEnumeratorOptions);
@class OSLogEnumerator;
@class OSLogPosition;

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class OSLogStore
 *
 * @abstract
 * A set of entries from the unified logging system. Instances
 * represent a fixed range of entries and may be backed by a
 * logarchive or the Mac's local store.
 *
 * @discussion
 * Entries in OSLogStore objects are used by OSLogEnumerator
 * instances; one store can support multiple OSLogEnumerator
 * instances concurrently.
 */
API_AVAILABLE(macos(10.15))
OS_EXPORT
@interface OSLogStore : NSObject

/*!
 * @method localStoreAndReturnError
 *
 * @abstract
 * Create an OSLogStore representing the Mac's local store.
 *
 * @param error
 * If initialization is unsuccessful --- for example, this process
 * does not have access to local logs --- return nil and set this
 * parameter to a pointer to an error object describing the reason.
 *
 * @discussion
 * This enables processing of a sequence of logs as of the particular
 * point in time when this object is created.
 *
 * Gaining access to the local unified logging system requires
 * permission from the system. The caller must be run by an admin
 * account and the have the com.apple.logging.local-store
 * entitlement.
 */
+ (nullable instancetype)localStoreAndReturnError:(NSError **)error
NS_SWIFT_NAME(local());

/*!
 * @method storeWithURL
 *
 * @abstract
 * Create an OSLogStore based on a logarchive.
 *
 * @param url
 * The path identifying a logarchive to be read.
 *
 * @param error
 * If initialization is unsuccessful --- for example, the path is not
 * to a valid logarchive or the logarchive is not compatible because
 * it is from a newer version --- return nil and set this parameter
 * to a pointer to an error object that describes the reason.
 */
+ (nullable instancetype)storeWithURL:(NSURL *)url
                                error:(NSError **)error;

/*!
 * @method entriesEnumeratorWithOptions
 *
 * @abstract
 * Return an OSLogEnumerator object based on an underlying store.
 * This object represents the sequence of entries for the store.
 * OSLogStore. Additional parameters control which entries are
 * yielded and their order.
 *
 * @param options
 * Control the direction of iteration.
 *
 * @param position
 * Where to start iteration. If nil, depend on the direction of
 * the iteration: if forwards, start with the earliest entry; if
 * reverse, start with the latest entry.
 *
 * @param predicate
 * A predicate that filters which entries are in the sequence. If
 * this is nil, yield all entries.
 *
 * @param error
 * If the enumerator cannot be set up --- for example, the
 * predicate has an unrecognized key --- return nil and set this
 * to a pointer to an error object that describes the reason.
 */
- (nullable OSLogEnumerator *)entriesEnumeratorWithOptions:(OSLogEnumeratorOptions)options
                                                  position:(nullable OSLogPosition *)position
                                                 predicate:(nullable NSPredicate *)predicate
                                                     error:(NSError **)error
NS_REFINED_FOR_SWIFT;

/*!
 * @method entriesEnumeratorAndReturnError
 *
 * @abstract
 * Return an OSLogEnumerator object with default options for
 * viewing the entries; all are viewed, from earliest to latest.
 *
 * @param error
 * If the enumerator cannot be set up, return nil and set this
 * to a pointer to an error object that describes the reason.
 */
- (nullable OSLogEnumerator *)entriesEnumeratorAndReturnError:(NSError **)error
NS_SWIFT_UNAVAILABLE("Use `entries` method");

/*!
 * @method positionWithDate
 *
 * @abstract
 * Return a position representing the time specified.
 *
 * @param date
 * The date to look for.
 *
 * @discussion
 * If there are multiple occurences of the same time --- if, for
 * example, there was a time change during the range of entries
 * --- the earliest occurrence is used.
 */
- (OSLogPosition *)positionWithDate:(NSDate *)date
NS_SWIFT_NAME(position(date:));

/*!
 * @method positionsWithDate
 *
 * @abstract
 * Return an array of positions representing each occurrence of a
 * particular date. The same date can be observed more than once due
 * to time changes.
 *
 * @param date
 * The date to look for.
 */
- (NSArray<OSLogPosition *> *)positionsWithDate:(NSDate *)date
NS_SWIFT_NAME(positions(date:));

/*!
 * @method positionWithTimeIntervalSinceEnd
 *
 * @abstract
 * Return a position representing an offset since the end of the time
 * range that the entries span.
 *
 * @param seconds
 * The seconds to add to the last time point in the range of entries.
 */
- (OSLogPosition *)positionWithTimeIntervalSinceEnd:(NSTimeInterval)seconds
NS_SWIFT_NAME(position(timeIntervalSinceEnd:));

/*!
 * @method positionWithTimeIntervalSinceLatestBoot
 *
 * @abstract
 * Return a position representing time since the last boot in the
 * series of entries.
 *
 * @param seconds
 * The seconds to add to the boot time point in the log time range.
 *
 * @discussion
 * Negative seconds would create an ambiguous or imprecise position;
 * this function asserts that the interval is positive.
 */
- (OSLogPosition *)positionWithTimeIntervalSinceLatestBoot:(NSTimeInterval)seconds
NS_SWIFT_NAME(position(timeIntervalSinceLatestBoot:));

@end

NS_ASSUME_NONNULL_END

#endif /* LOGGING_OS_LOG_STORE_H */
