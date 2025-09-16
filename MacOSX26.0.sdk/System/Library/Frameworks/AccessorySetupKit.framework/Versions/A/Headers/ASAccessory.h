/*
    Copyright (C) 2024 Apple Inc. All Rights Reserved.
*/

#pragma once

#ifndef ACCESSORY_SETUP_KIT_INDIRECT_INCLUDES
#error "Please #import <AccessorySetupKit/AccessorySetupKit.h> instead of this file directly."
#endif

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ASDiscoveryDescriptor;
@class ASPickerDisplayItem;

//---------------------------------------------------------------------------------------------------------------------------
/// A type that defines values for the state of an accessory.
typedef NS_ENUM( NSInteger, ASAccessoryState )
{
    /// The accessory is invalid or unauthorized.
    ASAccessoryStateUnauthorized            = 0,
    /// The accessory is selected, but full authorization is still pending.
    ASAccessoryStateAwaitingAuthorization   = 10,
    /// The accessory is authorized and available.
    ASAccessoryStateAuthorized              = 20,
} NS_SWIFT_NAME(ASAccessory.AccessoryState);

//---------------------------------------------------------------------------------------------------------------------------
/*!    @brief        Accessory Rename Options
*/
typedef NS_OPTIONS( NSUInteger, ASAccessoryRenameOptions )
{
    /// An option to change an accessory's SSID along with its display name.
    ASAccessoryRenameSSID NS_SWIFT_NAME(ssid)       = ( 1U << 0 ),
} NS_SWIFT_NAME(ASAccessory.RenameOptions);

//---------------------------------------------------------------------------------------------------------------------------
/*!    @brief        Accessory Support Options
*/
typedef NS_OPTIONS( NSUInteger, ASAccessorySupportOptions )
{
    /// The accessory supports Bluetooth Low Energy pairing.
    ASAccessorySupportBluetoothPairingLE                           = ( 1U << 1 ),
    /// The accessory supports bridging to Bluetooth classic transport.
    ///
    /// This option indicates that when connecting with low energy transport, the accessory supports activating Bluetooth classic transport profiles.
    ASAccessorySupportBluetoothTransportBridging                   = ( 1U << 2 ),
    /// The accessory supports Bluetooth Low Energy HID service.
    ASAccessorySupportBluetoothHID API_AVAILABLE( ios( 18.4 ) )    = ( 1U << 3 ),
} NS_SWIFT_NAME(ASAccessory.SupportOptions);

API_AVAILABLE( ios( 26.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
typedef uint64_t ASAccessoryWiFiAwarePairedDeviceID NS_SWIFT_NAME(ASAccessory.WiFiAwarePairedDeviceID);

AS_EXTERN
API_AVAILABLE( ios( 18.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
NS_SWIFT_SENDABLE
@interface ASAccessory : NSObject

/// The current authorization state of the accessory.
@property (readonly, assign, nonatomic) ASAccessoryState state;

/// The accessory's unique Bluetooth identifier, if any.
///
/// Use this identifier to establish a connection to the accessory.
@property (readonly, copy, nullable, nonatomic) NSUUID *bluetoothIdentifier;

/// The accessory's Bluetooth identifier, if any, for use when bridging classic transport profiles.
@property (readonly, copy, nullable, nonatomic) NSData *bluetoothTransportBridgingIdentifier;

/// The accessory's name, suitable for displaying to someone using your app.
@property (readonly, copy, nonatomic) NSString *displayName;

/// The accessory's Wi-Fi SSID, if any.
///
/// Use this identifier to establish a connection to the accessory.
@property (readonly, copy, nullable, nonatomic) NSString *SSID;

/// The accessory's Wi-Fi Aware Pairing Identifier.
///
/// Use this identifier to establish a connection to the accessory using Wi-Fi Aware Framework.
@property (readonly, assign, nonatomic) ASAccessoryWiFiAwarePairedDeviceID wifiAwarePairedDeviceID API_AVAILABLE( ios( 26.0 ) );

/// The descriptor used to discover the accessory.
@property (readonly, copy, nonatomic) ASDiscoveryDescriptor *descriptor;

@end

NS_ASSUME_NONNULL_END
