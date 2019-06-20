/*!
 *  @header WFConnectionMonitor.h
 *  @copyright 2019 Apple Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WFConnectionStatus;

/*!
 *  @class
 *  @brief Use this class to monitor for WiFi connection status changes.
 *  @discussion To use this API, enable the Access WiFi Information capability for your app in Xcode. When you enable this capability, Xcode automatically adds the Access WiFi Information entitlement (com.apple.developer.networking.wifi-info) to your entitlements file and App ID. This API is intended to be used specifically for accessing WiFi connection information. Use NWPathMonitor to monitor which available network connection path your app will use (e.g. cellular, WiFi).
 *  @seealso NWPathMonitor, NEHotspotConfigurationManager, NSHotspotConfiguration
 */
API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0))
@interface WFConnectionMonitor : NSObject

/*!
 *  @property
 *  @brief Dispatch queue on which all event handlers will be invoked.
 *  @discussion A private serial queue is used by default. The target queue cannot be changed after activation.
 */
@property (strong) dispatch_queue_t targetQueue;

/*!
 *  @property
 *  @brief Invoked when the instance is invalidated.
 *  @discussion After a client becomes invalidated, no more events will be received.
 */
@property (nullable, copy) void (^invalidationHandler)(void);

/*!
 *  @property
 *  @brief Invoked when WiFi connection status changes.
 */
@property (nullable, copy) void (^connectionStatusHandler)(WFConnectionStatus *connectionStatus);

/*!
 *  @property
 *  @brief Updated when the WiFi connection status changes.
 *  @discussion Can return NULL if queried before initial WiFi connection status update has been received.
 */
@property (readonly, nullable, copy) WFConnectionStatus *lastConnectionStatus;

/*!
 *  @method init
 *  @brief Designated initializer for WFConnectionMonitor.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/*!
 *  @method
 *  @brief Begin monitoring for WiFi connection status changes.
 *  @discussion Upon activatation, the configured connectionStatusHandler will be invoked and the lastConnectedStatus property will be updated asynchronously with the current WiFi connection status.
 */
- (void)activate;

/*!
 *  @method
 *  @brief Invalidates the connection monitor.
 *  @discussion A connection monitor must be invalidated before it is deallocated. After it is invalidated, no more events will received and all configured event handlers are automatically cleared.
 */
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
