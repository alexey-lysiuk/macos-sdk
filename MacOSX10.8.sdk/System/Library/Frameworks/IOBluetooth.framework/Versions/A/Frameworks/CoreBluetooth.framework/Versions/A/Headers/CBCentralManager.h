/*
 *	@file CBCentralManager.h
 *	@framework CoreBluetooth
 *
 *  @discussion Entry point to the central role.
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>



/*!
 *  @enum CBCentralManagerState
 *
 *  @discussion Represents the current state of a CBCentralManager.
 *
 */
enum {
	CBCentralManagerStateUnknown = 0,	// State unknown, update imminent.
	CBCentralManagerStateResetting,		// The connection with the system service was momentarily lost, update imminent.
	CBCentralManagerStateUnsupported,	// The platform doesn't support Bluetooth Low Energy.
	CBCentralManagerStateUnauthorized,	// The app is not authorized to use Bluetooth Low Energy.
	CBCentralManagerStatePoweredOff,	// Bluetooth is currently powered off.
	CBCentralManagerStatePoweredOn,		// Bluetooth is currently powered on and available to use.
};
typedef NSInteger CBCentralManagerState;

/*!
 *  @const CBCentralManagerScanOption
 *
 *  @discussion Keys used to pass options to the -[scanForPeripheralsWithServices:options:] method.
 *
 */
CB_EXTERN NSString * const CBCentralManagerScanOptionAllowDuplicatesKey;	// A NSNumber

/*!
 *  @const CBConnectPeripheralOption
 *
 *  @discussion Keys used to pass options to the -[connectPeripheral:] method.
 *
 */
CB_EXTERN NSString * const CBConnectPeripheralOptionNotifyOnDisconnectionKey;	// A NSNumber



@protocol CBCentralManagerDelegate;
@class CBUUID, CBPeripheral;

/*!
 *  @class CBCentralManager
 *
 *  @discussion Entry point to the central role.
 *      Commands should only be issued when its state is CBCentralStatePoweredOn.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBCentralManager : NSObject
{
@package
	id<CBCentralManagerDelegate> _delegate;
	
	CBCentralManagerState	_state;
}

/*!
 *  @property delegate
 *
 *  @discussion The delegate object you want to receive central events.
 *
 */
@property(assign, nonatomic) id<CBCentralManagerDelegate> delegate;

/*!
 *  @property state
 *
 *  @discussion The current state of the central.
 *      Initially set to CBCentralStateUnknown.
 *		It can be updated at any moment, upon which the relevant delegate callback will be invoked.
 *
 */
@property(readonly) CBCentralManagerState state;

/*!
 *  @method initWithDelegate:queue:
 *
 *  @param delegate	The delegate to receive the central events
 *  @param queue	The dispatch queue on which the events will be dispatched.
 *  @discussion The initialization call.
 *      The events of the central and its associated peripherals will be dispatched on the provided queue.
 *      If nil, the main queue will be used by default.
 *
 */
- (CBCentralManager *)initWithDelegate:(id<CBCentralManagerDelegate>)delegate queue:(dispatch_queue_t)queue;

/*!
 *  @method retrievePeripherals:
 *
 *  @param peripheralUUIDs An array of CFUUIDRef from which CBPeripherals will be retrieved.
 *  @discussion Ask the central to retrieve a list of known peripherals by their UUIDs.
 *      The relevant delegate callback will then promptly be invoked with the status of the request.
 *
 */
- (void)retrievePeripherals:(NSArray *)peripheralUUIDs;

/*!
 *  @method retrieveConnectedPeripherals
 *
 *  @discussion Ask the central to retrieve the list of the peripherals currently connected to the system.
 *      The relevant delegate callback will then promptly be invoked with the status of the request.
 *
 */
- (void)retrieveConnectedPeripherals;

/*!
 *  @method scanForPeripheralsWithServices:options:
 *
 *  @param serviceUUIDs An array of CBUUID which the app is interested in.
 *  @param options A dictionary to customize the scan, see CBCentralManagerScanOptionAllowDuplicatesKey.
 *
 *  @discussion Ask the central to scan for peripherals.
 *      The relevant delegate callback will then be invoked for each discovered peripheral.
 *      An array of CBUUIDs may be provided in "serviceUUIDs", in which case the central will
 *      only return peripherals which advertise this/these service(s) (recommended).
 *      If nil, all discovered peripherals will be returned (not recommmended).
 *      If the central is already scanning with different parameters, the provided parameters
 *      will replace them.
 *
 * @see CBCentralManagerScanOptionAllowDuplicatesKey
 */
- (void)scanForPeripheralsWithServices:(NSArray *)serviceUUIDs options:(NSDictionary *)options;

/*!
 *  @method stopScan:
 *
 *  @discussion Ask the central to stop scanning for peripherals.
 *
 */
- (void)stopScan;

/*!
 *  @method connectPeripheral:options:
 *
 *  @param peripheral The peripheral to connect to.
 *  @param options A dictionary to customize the behaviour of the connection. See CBConnectPeripheralOptionNotifyOnDisconnectionKey.
 *
 *  @discussion Establish a connection to the peripheral.
 *      This never times out, use -[cancelPeripheralConnection:] to cancel a pending connection.
 *
 * @see CBConnectPeripheralOptionNotifyOnDisconnectionKey
 */
- (void)connectPeripheral:(CBPeripheral *)peripheral options:(NSDictionary *)options;

/*!
 *  @method cancelPeripheralConnection:
 *
 *  @param peripheral The peripheral.
 *
 *  @discussion Cancel a pending connection or a connection to the peripheral.
 *
 */
- (void)cancelPeripheralConnection:(CBPeripheral *)peripheral;

@end



/*!
 *  @constant CBAdvertisementDataServiceUUIDsKey
 *
 *  @discussion Array of service UUIDs.
 *
 */
CB_EXTERN NSString * const CBAdvertisementDataServiceUUIDsKey;		// An array of CBUUIDs

/*!
 *  @constant CBAdvertisementDataLocalNameKey
 *
 *  @discussion Peripheral name.
 *
 */
CB_EXTERN NSString * const CBAdvertisementDataLocalNameKey;			// A NSString

/*!
 *  @constant CBAdvertisementDataTxPowerLevelKey
 *
 *  @discussion Tx power.
 *
 */
CB_EXTERN NSString * const CBAdvertisementDataTxPowerLevelKey;		// A NSNumber

/*!
 *  @constant CBAdvertisementDataManufacturerDataKey
 *
 *  @discussion Manufacturer data.
 *
 */
CB_EXTERN NSString * const CBAdvertisementDataManufacturerDataKey;	// A NSData

/*!
 *  @constant CBAdvertisementDataServiceDataKey
 *
 *  @discussion Service Data.
 *
 */
CB_EXTERN NSString * const CBAdvertisementDataServiceDataKey;		// A NSDictionary of NSDatas, indexed by CBUUIDs



@class CBPeripheral;

/*!
 *  @protocol CBCentralManagerDelegate
 *
 *  @discussion Delegate protocol for CBCentral.
 *
 */
@protocol CBCentralManagerDelegate <NSObject>

@required

/*!
 *  @method centralManagerDidUpdateState:
 *
 *  @param central The central whose state has changed.
 *
 *  @discussion Invoked whenever the central's state has been updated.
 *      See the "state" property for more information.
 *
 */
- (void)centralManagerDidUpdateState:(CBCentralManager *)central;

@optional

/*!
 *  @method centralManager:didRetrievePeripheral:
 *
 *  @discussion Invoked when the central retrieved a list of known peripherals.
 *      See the -[retrievePeripherals:] method for more information.
 *
 */
- (void)centralManager:(CBCentralManager *)central didRetrievePeripherals:(NSArray *)peripherals;

/*!
 *  @method centralManager:didRetrieveConnectedPeripherals:
 *
 *  @discussion Invoked when the central retrieved the list of peripherals currently connected to the system.
 *      See the -[retrieveConnectedPeripherals] method for more information.
 *
 */
- (void)centralManager:(CBCentralManager *)central didRetrieveConnectedPeripherals:(NSArray *)peripherals;

/*!
 *  @method centralManager:didDiscoverPeripheral:advertisementData:RSSI:
 *
 *  @discussion Invoked when the central discovered a peripheral while scanning.
 *      The advertisement / scan response data is stored in "advertisementData", and
 *      can be accessed through the CBAdvertisementData* keys.
 *      The peripheral must be retained if any command is to be performed on it.
 *
 */
- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI;

/*!
 *  @method centralManager:didConnectPeripheral:
 *
 *  @discussion Invoked whenever a connection has been succesfully created with the peripheral.
 *
 */
- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral;

/*!
 *  @method centralManager:didFailToConnectPeripheral:error:
 *
 *  @discussion Invoked whenever a connection has failed to be created with the peripheral.
 *      The failure reason is stored in "error".
 *
 */
- (void)centralManager:(CBCentralManager *)central didFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/*!
 *  @method centralManager:didDisconnectPeripheral:error:
 *
 *  @discussion Invoked whenever an existing connection with the peripheral has been teared down.
 *
 */
- (void)centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

@end