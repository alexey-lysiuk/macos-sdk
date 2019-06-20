/*!
 *  @header WFConnectionStatus.h
 *  @copyright 2019 Apple Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 *  @class
 *  @brief Class containing WiFi connection status information.
 *  @discussion Properties may only be available temporarily to specific apps. See individual property details.
 */
API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0))
@interface WFConnectionStatus : NSObject <NSCopying, NSSecureCoding>

/*!
 *  @property
 *  @brief Human-readable, UTF8-encoded string representation of the SSID of the currently associated WiFi network.
 *  @discussion Only available to the app that originally added the corresponding known network.
 */
@property(readonly, copy, nullable, nonatomic) NSString *networkName;

/*!
 *  @property
 *  @brief The service set identifier of the currently associated WiFi network.
 *  @discussion Only available to the app that originally added the corresponding known network. To derive the human-readable network name from the SSID, use -[NSString initWithData:encoding:] with NSUTF8StringEncoding (or another encoding). Returns NULL if not associated to a WiFi network.
 */
@property (readonly, copy, nullable, nonatomic) NSData *SSID;

/*!
 *  @property
 *  @brief A device-specific, vendor-specific identifier corresponding to the SSID of the currently associated WiFi network.
 *  @discussion Available to all apps. Returns NULL if not associated to a WiFi network. The value of this property is the same for apps that come from the same vendor running on the same device for a given SSID. A different value is returned for apps on the same device that come from different vendors, and for apps on different devices regardless of vendor.
 */
@property (readonly, copy, nullable, nonatomic) NSString *networkIdentifierForVendor;

/*!
 *  @property
 *  @brief The basic service set identifier of the currently associated WiFi access point.
 *  @discussion Only available to the app that originally added the corresponding known network, and within 300 seconds of when that known network was added. Returns NULL if not associated to a WiFi network.
 */
@property (readonly, copy, nullable, nonatomic) NSString *BSSID;

/*!
 *  @property
 *  @brief A device-specific, vendor-specific identifier corresponding to the BSSID of the currently associated WiFi access point.
 *  @discussion Available to all apps. Returns NULL if not associated to a WiFi network. The value of this property is the same for apps that come from the same vendor running on the same device for a given BSSID. A different value is returned for apps on the same device that come from different vendors, and for apps on different devices regardless of vendor.
 */
@property (readonly, copy, nullable, nonatomic) NSString *accessPointIdentifierForVendor;

@end

NS_ASSUME_NONNULL_END
