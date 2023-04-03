//
//  VZError.h
//  Virtualization
//
//  Copyright © 2019-2022 Apple Inc. All rights reserved.
//

#import <Virtualization/VZDefines.h>

VZ_EXPORT NSErrorDomain const VZErrorDomain API_AVAILABLE(macos(11.0));

/*!
 @enum VZErrorCode
 @abstract
    Error type returned by the Virtualization framework.
    The NSError domain is VZErrorDomain, the code is one of the VZErrorCode constants.

    The virtualization framework can also report errors from other domains when the error originates from a lower level component.

 @constant VZErrorInternal
    Internal error such as the virtual machine unexpectedly stopping.
 @constant VZErrorInvalidVirtualMachineConfiguration
    Invalid machine configuration.
 @constant VZErrorInvalidVirtualMachineState
    API used with a machine in the wrong state (e.g. interacting with a machine before it is running).
 @constant VZErrorInvalidVirtualMachineStateTransition
    Invalid change of state (e.g. pausing a virtual machine that is not started).
 @constant VZErrorInvalidDiskImage
    Unrecognized disk image format or invalid disk image.
 @constant VZErrorVirtualMachineLimitExceeded
    The running virtual machine limit was exceeded.
 @constant VZErrorNetworkError
    Network error occurred.
 @constant VZErrorOutOfDiskSpace
    Machine ran out of disk space.
 @constant VZErrorOperationCancelled
    The operation was cancelled.
 @constant VZErrorNotSupported
    The operation is not supported.
 @constant VZErrorRestoreImageCatalogLoadFailed
    The restore image catalog failed to load.
 @constant VZErrorInvalidRestoreImageCatalog
    The restore image catalog is invalid.
 @constant VZErrorNoSupportedRestoreImagesInCatalog
    The restore image catalog has no supported restore images.
 @constant VZErrorRestoreImageLoadFailed
    The restore image failed to load.
 @constant VZErrorInvalidRestoreImage
    The restore image is invalid.
 @constant VZErrorInstallationRequiresUpdate
    A software update is required to complete the installation.
 @constant VZErrorInstallationFailed
    An error occurred during installation.
 */
typedef NS_ERROR_ENUM(VZErrorDomain, VZErrorCode) {
    VZErrorInternal NS_SWIFT_NAME(internalError) = 1,
    VZErrorInvalidVirtualMachineConfiguration = 2,
    VZErrorInvalidVirtualMachineState = 3,
    VZErrorInvalidVirtualMachineStateTransition = 4,
    VZErrorInvalidDiskImage = 5,
    VZErrorVirtualMachineLimitExceeded API_AVAILABLE(macos(12.0)) = 6,
    VZErrorNetworkError API_AVAILABLE(macos(13.0)) = 7,
    VZErrorOutOfDiskSpace API_AVAILABLE(macos(13.0)) = 8,
    VZErrorOperationCancelled API_AVAILABLE(macos(13.0)) = 9,
    VZErrorNotSupported API_AVAILABLE(macos(13.0)) = 10,

    /* macOS installation errors. */
    VZErrorRestoreImageCatalogLoadFailed API_AVAILABLE(macos(13.0)) = 10001,
    VZErrorInvalidRestoreImageCatalog API_AVAILABLE(macos(13.0)) = 10002,
    VZErrorNoSupportedRestoreImagesInCatalog API_AVAILABLE(macos(13.0)) = 10003,
    VZErrorRestoreImageLoadFailed API_AVAILABLE(macos(13.0)) = 10004,
    VZErrorInvalidRestoreImage API_AVAILABLE(macos(13.0)) = 10005,
    VZErrorInstallationRequiresUpdate API_AVAILABLE(macos(13.0)) = 10006,
    VZErrorInstallationFailed API_AVAILABLE(macos(13.0)) = 10007,
};
