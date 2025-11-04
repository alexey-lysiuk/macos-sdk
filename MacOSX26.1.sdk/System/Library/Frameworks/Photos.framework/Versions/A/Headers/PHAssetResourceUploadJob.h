
//
//  PHAssetResourceUploadJob.h
//  PhotoKit
//
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#import <Photos/PHObject.h>
#import <Photos/PhotosTypes.h>

@class PHAssetResource;
@class PHFetchOptions;
@class PHFetchResult<T>;

NS_ASSUME_NONNULL_BEGIN

/// Represents a request to upload a `PHAssetResource`
///
/// Used within an application's `com.apple.photos.background-upload` extension to represent a request to upload a `PHAssetResource` to a destination `NSURLRequest`.
///
/// When the extensions principal class receives a call to `process` background uploads, it can create new `PHAssetResourceUploadJob`s using `PHAssetResourceUploadJobChangeRequest` and any existing upload jobs can be fetched using `fetchJobsWithAction:options:` and handled by updating their state using a `PHAssetResourceUploadJobChangeRequest` to mark them as acknowledged, or to be retried. The maximum number of jobs that can be a in flight is limited to the `jobLimit`.
NS_SWIFT_SENDABLE
API_AVAILABLE(ios(26.1)) API_UNAVAILABLE(macos, macCatalyst, tvos, visionos, watchos)
@interface PHAssetResourceUploadJob : PHObject

@property (class, readonly) NSInteger jobLimit; /// The maximum number of unacknowledged upload jobs allowed, this includes registered, pending, succeeded and failed jobs.

@property (strong, readonly) PHAssetResource *resource; /// The asset resource this upload job represents.
@property (strong, readonly) NSURLRequest *destination; /// The destination to send this asset resource.
@property (readonly) PHAssetResourceUploadJobState state; /// The state of this upload job.

/// Returns all asset resource upload jobs applicable for a given action.
///
/// - Parameters:
///     - action: The actions a client can take on a job.
///     - options: The fetch options to be passed in.
///
/// - Returns: The jobs available to apply `action` on them.
+ (PHFetchResult<PHAssetResourceUploadJob *> *)fetchJobsWithAction:(PHAssetResourceUploadJobAction)action options:(nullable PHFetchOptions *)options NS_SWIFT_NAME(fetchJobs(action:options:));

@end

NS_ASSUME_NONNULL_END
