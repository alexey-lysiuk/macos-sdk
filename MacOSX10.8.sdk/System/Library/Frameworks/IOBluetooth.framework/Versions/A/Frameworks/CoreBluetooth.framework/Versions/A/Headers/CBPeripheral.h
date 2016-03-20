/*
 *	@file CBPeripheral.h
 *	@framework CoreBluetooth
 *
 *  @discussion Representation of a remote peripheral.
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>



/*!
 *  @enum CBCharacteristicWriteType
 *
 *  @discussion Specifies which type of write is to be performed on a CBCharacteristic.
 *
 */
enum {
	CBCharacteristicWriteWithResponse = 0,
	CBCharacteristicWriteWithoutResponse,
};
typedef NSInteger CBCharacteristicWriteType;



@protocol CBPeripheralDelegate;
@class CBService, CBCharacteristic, CBDescriptor, CBUUID;

/*!
 *  @class CBPeripheral
 *
 *  @discussion Represents a peripheral.
 *      Commands should only be issued when it is connected.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBPeripheral : NSObject
{
@package
	id<CBPeripheralDelegate> _delegate;
	
	CFUUIDRef	 _UUID;
	
	NSString	*_name;
	NSNumber	*_RSSI;
	BOOL		 _isConnected;
	NSArray		*_services;
}

/*!
 *  @property delegate
 *
 *  @discussion The delegate object you want to receive peripheral events.
 *
 */
@property(assign, nonatomic) id<CBPeripheralDelegate> delegate;

/*!
 *  @property UUID
 *
 *  @discussion The UUID of the peripheral.
 *      This UUID can be stored and then later used to retrieve this specific peripheral
 *      with another central instance.
 *
 */
@property(readonly, nonatomic) CFUUIDRef UUID;

/*!
 *  @property name
 *
 *  @discussion The name of the peripheral.
 *
 */
@property(retain, readonly) NSString *name;

/*!
 *  @property RSSI
 *
 *  @discussion While connected, the RSSI of the link in dB.
 *
 */
@property(retain, readonly) NSNumber *RSSI;

/*!
 *  @property isConnected
 *
 *  @discussion Whether the peripheral is currently connected or not.
 *
 */
@property(readonly) BOOL isConnected;

/*!
 *  @property services
 *
 *  @discussion A list of CBServices that have so far been discovered on the peripheral.
 *
 */
@property(retain, readonly) NSArray *services;

/*!
 *  @method readRSSI
 *
 *  @discussion While connected, fetch the current RSSI of the link.
 *
 * @see peripheralDidUpdateRSSI:error:
 */
- (void)readRSSI;

/*!
 *  @method discoverServices
 *
 *  @param serviceUUIDs The array of servcice UUIDs to be discovered.
 *
 *  @discussion Discover available services on the peripheral.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *      An array of CBUUIDs may be provided in "serviceUUIDs", in which case only services
 *      with matching UUIDs will be discovered (recommended).
 *      If nil, all services will be discovered (not recommmended).
 *
 *  @see peripheral:didDiscoverServices:
 */
- (void)discoverServices:(NSArray *)serviceUUIDs;

/*!
 *  @method discoverIncludedServices:forService:
 *
 *  @param includedServiceUUIDs The array of included service UUIDs to be discovered.
 *  @param service The service on which to discover the secondary services.
 *
 *  @discussion Discover included services of a service.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *      An array of CBUUIDs may be provided in "includedServiceUUIDs", in which case only
 *      included services with matching UUIDs will be discovered (recommended).
 *      If nil, all included services will be discovered (not recommmended).
 *
 *  @see peripheral:didDiscoverIncludedServicesForService:error:
 */
- (void)discoverIncludedServices:(NSArray *)includedServiceUUIDs forService:(CBService *)service;

/*!
 *  @method discoverCharacteristics:forService:
 *
 *  @param characteristicUUIDs The array of characteristic UUIDs.
 *  @param service The service on which to discover the characteristics.
 *
 *  @discussion Discover characteristics of a service.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *      An array of CBUUIDs may be provided in "characteristicUUIDs", in which case only
 *      characteristics with matching UUIDs will be discovered (recommended).
 *      If nil, all characteristics will be discovered (not recommmended).
 *
 *  @see peripheral:didDiscoverCharacteristicsForService:error:
 */
- (void)discoverCharacteristics:(NSArray *)characteristicUUIDs forService:(CBService *)service;

/*!
 *  @method readValueForCharacteristic:
 *
 *  @param characteristic The characteristic for which the value needs to be read.
 *
 *  @discussion Fetch the value of a characteristic.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didUpdateValueForCharacteristic:error:
 */
- (void)readValueForCharacteristic:(CBCharacteristic *)characteristic;

/*!
 *  @method writeValue:forCharacteristic:withResponse:
 *
 *  @param data The value to write.
 *  @param characteristic The characteristic on which to perform the write operation.
 *  @param type The type of write to be executed.
 *
 *  @discussion Write the value of a characteristic.
 *      The passed data is copied and can be disposed of after the call finishes.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didWriteValueForCharacteristic:error:
 */
- (void)writeValue:(NSData *)data forCharacteristic:(CBCharacteristic *)characteristic type:(CBCharacteristicWriteType)type;

/*!
 *  @method setNotifyValue:forCharacteristic:
 *
 *  @param notifyValue The value to set the client configuration descriptor to.
 *  @param characteristic The characteristic containing the client configuration.
 *
 *  @discussion Ask to start/stop receiving notifications for a characteristic.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didUpdateNotificationStateForCharacteristic:error:
 */
- (void)setNotifyValue:(BOOL)notifyValue forCharacteristic:(CBCharacteristic *)characteristic;

/*!
 *  @method discoverDescriptorsForCharacteristic:
 *
 *  @param characteristic The characteristic for which to discover the descriptors.
 *
 *  @discussion Discover the descriptors of a characteristic.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didDiscoverDescriptorsForCharacteristic:error:
 */
- (void)discoverDescriptorsForCharacteristic:(CBCharacteristic *)characteristic;

/*!
 *  @method readValueForDescriptor:
 *
 *  @param descriptor The descriptor to read from.
 *
 *  @discussion Fetch the value of a descriptor.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didUpdateValueForDescriptor:error:
 */
- (void)readValueForDescriptor:(CBDescriptor *)descriptor;

/*!
 *  @method writeValue:forDescriptor:
 *
 *  @param data The value to write to the descriptor.
 *  @param descriptor The descriptor to write to.
 *
 *  @discussion Write the value of a descriptor.
 *      The passed data is copied and can be disposed of after the call finishes.
 *      The relevant delegate callback will then be invoked with the status of the request.
 *
 *  @see peripheral:didWriteValueForCharacteristic:error:
 */
- (void)writeValue:(NSData *)data forDescriptor:(CBDescriptor *)descriptor;

@end



/*!
 *  @protocol CBPeripheralDelegate
 *
 *  @discussion Delegate for CBPeripheral.
 *
 */
@protocol CBPeripheralDelegate <NSObject>

@optional

/*!
 *  @method peripheralDidUpdateRSSI:error:
 *
 *  @discussion Invoked upon completion of a -[readRSSI:] request.
 *      If successful, "error" is nil and the "RSSI" property of the peripheral has been updated.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheralDidUpdateRSSI:(CBPeripheral *)peripheral error:(NSError *)error;

/*!
 *  @method peripheral:didDiscoverServices:
 *
 *  @discussion Invoked upon completion of a -[discoverServices:] request.
 *      If successful, "error" is nil and discovered services, if any, have been merged into the
 *      "services" property of the peripheral.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverServices:(NSError *)error;

/*!
 *  @method peripheral:didDiscoverIncludedServicesForService:error:
 *
 *  @discussion Invoked upon completion of a -[discoverIncludedServices:forService:] request.
 *      If successful, "error" is nil and discovered services, if any, have been merged into the
 *      "includedServices" property of the service.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverIncludedServicesForService:(CBService *)service error:(NSError *)error;

/*!
 *  @method peripheral:didDiscoverCharacteristicsForService:error:
 *
 *  @discussion Invoked upon completion of a -[discoverCharacteristics:forService:] request.
 *      If successful, "error" is nil and discovered characteristics, if any, have been merged into the
 *      "characteristics" property of the service.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverCharacteristicsForService:(CBService *)service error:(NSError *)error;

/*!
 *  @method peripheral:didUpdateValueForCharacteristic:error:
 *
 *  @discussion Invoked upon completion of a -[readValueForCharacteristic:] request or on the reception of a notification/indication.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  @method peripheral:didWriteValueForCharacteristic:error:
 *
 *  @discussion Invoked upon completion of a -[writeValue:forCharacteristic:] request.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  @method peripheral:didUpdateNotificationStateForCharacteristic:error:
 *
 *  @discussion Invoked upon completion of a -[setNotifyValue:forCharacteristic:] request.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  @method peripheral:didDiscoverDescriptorsForCharacteristic:error:
 *
 *  @discussion Invoked upon completion of a -[discoverDescriptorsForCharacteristic:] request.
 *      If successful, "error" is nil and discovered descriptors, if any, have been merged into the
 *      "descriptors" property of the characteristic.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverDescriptorsForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  @method peripheral:didUpdateValueForDescriptor:error:
 *
 *  @discussion Invoked upon completion of a -[readValueForDescriptor:] request.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForDescriptor:(CBDescriptor *)descriptor error:(NSError *)error;

/*!
 *  @method peripheral:didWriteValueForDescriptor:error:
 *
 *  @discussion Invoked upon completion of a -[writeValue:forDescriptor:] request.
 *      If unsuccessful, "error" is set with the encountered failure.
 *
 */
- (void)peripheral:(CBPeripheral *)peripheral didWriteValueForDescriptor:(CBDescriptor *)descriptor error:(NSError *)error;

@end