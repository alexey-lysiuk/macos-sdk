/*
 *	@file CBDescriptor.h
 *	@framework CoreBluetooth
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>



@class CBCharacteristic, CBUUID;

/*!
 * @class CBDescriptor
 *
 *  @discussion
 *      Represents a characteristic's descriptor.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBDescriptor : NSObject
{
@package
	CBCharacteristic	*_characteristic;
	CBUUID				*_UUID;
	
	id					 _value;
}

/*!
 *  @property characteristic
 *
 *  @discussion
 *      A back-pointer to the characteristic this descriptor belongs to.
 *
 */
@property(readonly, nonatomic) CBCharacteristic *characteristic;

/*!
 *  @property UUID
 *
 *  @discussion
 *      The Bluetooth UUID of the descriptor.
 *
 */
@property(readonly, nonatomic) CBUUID *UUID;

/*!
 *  @property value
 *
 *  @discussion
 *      The value of the descriptor.
 *
 */
@property(retain, readonly) id value;

@end
