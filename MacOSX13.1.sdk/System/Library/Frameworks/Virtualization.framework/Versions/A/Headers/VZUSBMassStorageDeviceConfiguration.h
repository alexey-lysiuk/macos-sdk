//
//  VZUSBMassStorageDeviceConfiguration.h
//  Virtualization
//
//  Copyright © 2021-2022 Apple Inc. All rights reserved.
//

#import <Virtualization/VZStorageDeviceConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract Configuration of a USB Mass Storage storage device.
 @discussion
    This device configuration creates a storage device that conforms to the USB Mass Storage specification.
 */
VZ_EXPORT API_AVAILABLE(macos(13.0))
@interface VZUSBMassStorageDeviceConfiguration : VZStorageDeviceConfiguration

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 @abstract Initialize a VZUSBMassStorageDeviceConfiguration with a device attachment.
 @param attachment The storage device attachment. This defines how the virtualized device operates on the host side.
 @see VZDiskImageStorageDeviceAttachment
 */
- (instancetype)initWithAttachment:(VZStorageDeviceAttachment *)attachment NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
