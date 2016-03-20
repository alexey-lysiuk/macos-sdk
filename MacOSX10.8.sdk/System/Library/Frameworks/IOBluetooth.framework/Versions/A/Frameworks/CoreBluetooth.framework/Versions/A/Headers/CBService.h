/*
 *	@file CBService.h
 *	@framework CoreBluetooth
 *
 *  @discussion A Bluetooth LE service representation. A LE Service provides a number of
 *		characteristics and may also reference other services.
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>



@class CBPeripheral, CBUUID;

/*!
 * @class CBService
 *
 * @discussion
 *      Represents a peripheral's service or a service's included service.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBService : NSObject
{
@package
	CBPeripheral	*_peripheral;
	CBUUID			*_UUID;
	
	NSArray			*_includedServices;
	NSArray			*_characteristics;
}

/*!
 * @property peripheral
 *
 * @discussion
 *      A back-pointer to the peripheral this service belongs to.
 *
 */
@property(readonly, nonatomic) CBPeripheral *peripheral;

/*!
 * @property UUID
 *
 * @discussion
 *      The Bluetooth UUID of the service.
 *
 */
@property(readonly, nonatomic) CBUUID *UUID;

/*!
 * @property includedServices
 *
 * @discussion
 *      A list of included CBServices that have so far been discovered in this service.
 *
 */
@property(retain, readonly) NSArray *includedServices;

/*!
 * @property characteristics
 *
 * @discussion
 *      A list of CBCharacteristics that have so far been discovered in this service.
 *
 */
@property(retain, readonly) NSArray *characteristics;

@end