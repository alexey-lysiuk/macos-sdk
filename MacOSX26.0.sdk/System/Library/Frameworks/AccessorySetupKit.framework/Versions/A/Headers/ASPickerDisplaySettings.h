/*
    Copyright (C) 2025 Apple Inc. All Rights Reserved.
*/

#pragma once

#ifndef ACCESSORY_SETUP_KIT_INDIRECT_INCLUDES
#error "Please #import <AccessorySetupKit/AccessorySetupKit.h> instead of this file directly."
#endif

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//---------------------------------------------------------------------------------------------------------------------------

/// The type used for the accessory picker's discovery timeout value.
typedef NSTimeInterval ASPickerDisplaySettingsDiscoveryTimeout NS_TYPED_ENUM NS_SWIFT_NAME(ASPickerDisplaySettings.DiscoveryTimeout) API_AVAILABLE( ios( 26.0 ) );

/// A picker discovery timeout value that times out after about about 60 seconds.
AS_EXTERN ASPickerDisplaySettingsDiscoveryTimeout const ASPickerDisplaySettingsDiscoveryTimeoutShort API_AVAILABLE( ios( 26.0 ) );
/// A picker discovery timeout value that times out after about two minutes.
AS_EXTERN ASPickerDisplaySettingsDiscoveryTimeout const ASPickerDisplaySettingsDiscoveryTimeoutMedium API_AVAILABLE( ios( 26.0 ) );
/// A picker discovery timeout value that times out after about five minutes.
AS_EXTERN ASPickerDisplaySettingsDiscoveryTimeout const ASPickerDisplaySettingsDiscoveryTimeoutLong API_AVAILABLE( ios( 26.0 ) );

/// A type that contains settings to customize the display of the accessory picker
AS_EXTERN
API_AVAILABLE( ios( 26.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
NS_SWIFT_SENDABLE
@interface ASPickerDisplaySettings : NSObject

/// An empty settings object.
@property (class, readonly, nonatomic) ASPickerDisplaySettings *defaultSettings;

/// Custom timeout for picker. Default is 30 seconds.
@property (readwrite, assign, nonatomic) ASPickerDisplaySettingsDiscoveryTimeout discoveryTimeout;

@end

NS_ASSUME_NONNULL_END
