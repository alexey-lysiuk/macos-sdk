/*
 *	@file CBCharacteristic.h
 *	@framework CoreBluetooth
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>



/*!
 *  @enum CBCharacteristicProperties
 */
enum {
	CBCharacteristicPropertyBroadcast					= 0x01,
	CBCharacteristicPropertyRead						= 0x02,
	CBCharacteristicPropertyWriteWithoutResponse		= 0x04,
	CBCharacteristicPropertyWrite						= 0x08,
	CBCharacteristicPropertyNotify						= 0x10,
	CBCharacteristicPropertyIndicate					= 0x20,
	CBCharacteristicPropertyAuthenticatedSignedWrites	= 0x40,
	CBCharacteristicPropertyExtendedProperties			= 0x80,
};
typedef NSUInteger CBCharacteristicProperties;



@class CBService, CBUUID;

/*!
 *  @class CBCharacteristic
 *
 *  @discussion
 *      Represents a service's characteristic.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBCharacteristic : NSObject
{
@package
	CBService					*_service;
	CBUUID						*_UUID;
	CBCharacteristicProperties	 _properties;
	
	NSData						*_value;
	NSArray						*_descriptors;
	BOOL						 _isBroadcasted;
	BOOL						 _isNotifying;
}

/*!
 * @property service
 *
 *  @discussion
 *      A back-pointer to the service this characteristic belongs to.
 *
 */
@property(readonly, nonatomic) CBService *service;

/*!
 * @property UUID
 *
 *  @discussion
 *      The Bluetooth UUID of the characteristic.
 *
 */
@property(readonly, nonatomic) CBUUID *UUID;

/*!
 * @property properties
 *
 *  @discussion
 *      The properties of the characteristic.
 *
 */
@property(readonly, nonatomic) CBCharacteristicProperties properties;

/*!
 * @property value
 *
 *  @discussion
 *      The value of the characteristic.
 *
 */
@property(retain, readonly) NSData *value;

/*!
 * @property descriptors
 *
 *  @discussion
 *      A list of the CBDescriptors that have so far been discovered in this characteristic.
 *
 */
@property(retain, readonly) NSArray *descriptors;

/*!
 * @property isBroadcasted
 *
 *  @discussion
 *      Whether the characteristic is currently broadcasted or not.
 *
 */
@property(readonly) BOOL isBroadcasted;

/*!
 * @property isNotifying
 *
 *  @discussion
 *      Whether the characteristic is currently notifying or not.
 *
 */
@property(readonly) BOOL isNotifying;

@end