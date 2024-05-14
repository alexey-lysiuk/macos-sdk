//
//  VZGenericPlatformConfiguration.h
//  Virtualization
//
//  Copyright © 2021-2023 Apple Inc. All rights reserved.
//

#import <Virtualization/VZPlatformConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

@class VZGenericMachineIdentifier;

/*!
 @abstract The platform configuration for a generic Intel or ARM virtual machine.
*/
VZ_EXPORT API_AVAILABLE(macos(12.0))
@interface VZGenericPlatformConfiguration : VZPlatformConfiguration

- (instancetype)init NS_DESIGNATED_INITIALIZER;

/*!
 @abstract The machine identifier.
 */
@property (copy) VZGenericMachineIdentifier *machineIdentifier API_AVAILABLE(macos(13.0));

@end

NS_ASSUME_NONNULL_END
