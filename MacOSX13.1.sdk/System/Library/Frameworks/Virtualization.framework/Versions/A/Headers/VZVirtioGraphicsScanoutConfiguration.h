//
//  VZVirtioGraphicsScanoutConfiguration.h
//  Virtualization
//
//  Copyright © 2021-2022 Apple Inc. All rights reserved.
//

#import <Virtualization/VZDefines.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract Configuration for a scanout attached to a Virtio graphics device.
 @discussion This scanout can be shown in a VZVirtualMachineView.
 @seealso VZVirtioGraphicsDeviceConfiguration
*/
VZ_EXPORT API_AVAILABLE(macos(13.0))
@interface VZVirtioGraphicsScanoutConfiguration : NSObject <NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 @abstract Create a scanout configuration with the specified pixel dimensions.
 @param widthInPixels The width of the scanout, in pixels.
 @param heightInPixels The height of the scanout, in pixels.
*/
- (instancetype)initWithWidthInPixels:(NSInteger)widthInPixels heightInPixels:(NSInteger)heightInPixels NS_DESIGNATED_INITIALIZER;

/*!
 @abstract The width of the scanout, in pixels.
*/
@property NSInteger widthInPixels;

/*!
 @abstract The height of the scanout, in pixels.
*/
@property NSInteger heightInPixels;

@end

NS_ASSUME_NONNULL_END
