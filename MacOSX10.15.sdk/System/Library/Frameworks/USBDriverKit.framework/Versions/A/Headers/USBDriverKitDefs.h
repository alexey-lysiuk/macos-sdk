//
//  USBDriverKitDefs.h
//  USBDriverKit
//
//  Created by Shawn Lennox on 2/12/19.
//

#ifndef USBDriverKitDefs_h
#define USBDriverKitDefs_h

/*!
 * @enum        IOUSBAbortOptions
 * @brief       Options for <code>abort()</code>
 * @constant    kIOUSBAbortAsynchronous abort() should return immediately without waiting for the aborted IO to complete
 * @constant    kIOUSBAbortSynchronous abort() should not return until the aborted IO has completed
 */
enum IOUSBAbortOptions
{
    kIOUSBAbortAsynchronous = 0x0,
    kIOUSBAbortSynchronous  = 0x1
};

/*!
 * @brief Port types returned by IOUSBHostDevice::GetPortStatus
 *
 * @constant kIOUSBHostPortTypeStandard A general-purpose USB port.
 * @constant kIOUSBHostPortTypeCaptive The attached device cannot be physically disconnected from the port.
 * @constant kIOUSBHostPortTypeInternal The attached device cannot be physically disconnected from the host machine.
 * @constant kIOUSBHostPortTypeAccessory The attached device may require authentication before function drivers can access it.
 * @constant kIOUSBHostPortTypeCount The number of entries in this enum.
 */
enum IOUSBHostPortType
{
    kIOUSBHostPortTypeStandard = 0,
    kIOUSBHostPortTypeCaptive,
    kIOUSBHostPortTypeInternal,
    kIOUSBHostPortTypeAccessory,
    kIOUSBHostPortTypeExpressCard,
    kIOUSBHostPortTypeCount
};

/*!
 * @brief Connection speeds returned by IOUSBHostDevice::GetPortStatus
 * @discussion This enumeration matches the default speed ID mappings defined in XHCI 1.0 Table 147.
 *
 * @constant kIOUSBHostPortConnectionSpeedNone No device is connected
 * @constant kIOUSBHostPortConnectionSpeedFull A full-speed (12 Mb/s) device is connected
 * @constant kIOUSBHostPortConnectionSpeedLow A low-speed (1.5 Mb/s) device is connected
 * @constant kIOUSBHostPortConnectionSpeedHigh A high-speed (480 Mb/s) device is connected)
 * @constant kIOUSBHostPortConnectionSpeedSuper A superspeed (5 Gb/s) device is connected)
 * @constant kIOUSBHostPortConnectionSpeedSuperPlus A superspeed (10 Gb/s) device is connected)
 */
enum IOUSBHostConnectionSpeed
{
    kIOUSBHostPortConnectionSpeedNone         = 0,
    kIOUSBHostPortConnectionSpeedFull         = 1,
    kIOUSBHostPortConnectionSpeedLow          = 2,
    kIOUSBHostPortConnectionSpeedHigh         = 3,
    kIOUSBHostPortConnectionSpeedSuper        = 4,
    kIOUSBHostPortConnectionSpeedSuperPlus    = 5,
    kIOUSBHostPortConnectionSpeedCount        = 6
};



/*!
 * @brief Values returned by IOUSBHostDevice::GetPortStatus
 *
 * @constant kIOUSBHostPortStatusPortTypeMask The mask for bits representing the port type.
 * @constant kIOUSBHostPortStatusPortTypeStandard A general-purpose USB port.
 * @constant kIOUSBHostPortStatusPortTypeCaptive The attached device cannot be physically disconnected from the port.
 * @constant kIOUSBHostPortStatusPortTypeInternal The attached device cannot be physically disconnected from the host machine.
 * @constant kIOUSBHostPortStatusPortTypeAccessory The attached device may require authentication before function drivers can access it.
 * @constant kIOUSBHostPortStatusConnectedSpeedMask The mask for bits representing the connection state.
 * @constant kIOUSBHostPortStatusConnectedSpeedNone The port does not have a connected device.
 * @constant kIOUSBHostPortStatusConnectedSpeedFull The port has a full-speed device connected.
 * @constant kIOUSBHostPortStatusConnectedSpeedLow The port has a low-speed device connected.
 * @constant kIOUSBHostPortStatusConnectedSpeedHigh The port has a high-speed device connected.
 * @constant kIOUSBHostPortStatusConnectedSpeedSuper The port has a superspeed device connected.
 * @constant kIOUSBHostPortStatusResetting The port is currently resetting the link.
 * @constant kIOUSBHostPortStatusEnabled The port is enabled and packets are permitted to reach the device.  Not valid unless kIOUSBHostPortStatusConnectedSpeedMask is nonzero.
 * @constant kIOUSBHostPortStatusSuspended The port is suspended.  Not valid unless kUSBHostPortStatusConnectedSpeedMask is nonzero.
 * @constant kIOUSBHostPortStatusOvercurrent The port is in the overcurrent condition.
 * @constant kIOUSBHostPortStatusTestMode The port is in test mode.
 */
enum IOUSBHostPortStatus
{
    kIOUSBHostPortStatusPortTypeMask              = IOUSBBitRange(0, 3),
    kIOUSBHostPortStatusPortTypePhase             = IOUSBBitRangePhase(0, 3),
    kIOUSBHostPortStatusPortTypeStandard          = (kIOUSBHostPortTypeStandard << IOUSBBitRangePhase(0, 3)),
    kIOUSBHostPortStatusPortTypeCaptive           = (kIOUSBHostPortTypeCaptive << IOUSBBitRangePhase(0, 3)),
    kIOUSBHostPortStatusPortTypeInternal          = (kIOUSBHostPortTypeInternal << IOUSBBitRangePhase(0, 3)),
    kIOUSBHostPortStatusPortTypeAccessory         = (kIOUSBHostPortTypeAccessory << IOUSBBitRangePhase(0, 3)),
    kIOUSBHostPortStatusPortTypeReserved          = IOUSBBitRange(4, 7),
    kIOUSBHostPortStatusConnectedSpeedMask        = IOUSBBitRange(8, 10),
    kIOUSBHostPortStatusConnectedSpeedPhase       = IOUSBBitRangePhase(8, 10),
    kIOUSBHostPortStatusConnectedSpeedNone        = (kIOUSBHostPortConnectionSpeedNone << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusConnectedSpeedFull        = (kIOUSBHostPortConnectionSpeedFull << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusConnectedSpeedLow         = (kIOUSBHostPortConnectionSpeedLow << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusConnectedSpeedHigh        = (kIOUSBHostPortConnectionSpeedHigh << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusConnectedSpeedSuper       = (kIOUSBHostPortConnectionSpeedSuper << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusConnectedSpeedSuperPlus   = (kIOUSBHostPortConnectionSpeedSuperPlus << IOUSBBitRangePhase(8, 10)),
    kIOUSBHostPortStatusResetting                 = IOUSBBit(11),
    kIOUSBHostPortStatusEnabled                   = IOUSBBit(12),
    kIOUSBHostPortStatusSuspended                 = IOUSBBit(13),
    kIOUSBHostPortStatusOvercurrent               = IOUSBBit(14),
    kIOUSBHostPortStatusTestMode                  = IOUSBBit(15)
};




/*!
 * @brief       Free a descriptor returned by a copy descriptor method.
 * @discussion  Copy descriptor methods belonging to the IOUSBHost* classes will return
 *              newly allocated buffers containing the requested descriptor.
 *              These buffers must be freed using IOUSBFreeDescriptors().
 *              e.g.  Descriptors returned by the following methods all need to be freed:
 *              CopyDescriptor(), CopyConfigurationDescriptor(), CopyDeviceDescriptor(), ...
 * @param       descriptor to be freed.
 */

void IOUSBFreeDescriptor(const IOUSBDeviceDescriptor * descriptor);
void IOUSBFreeDescriptor(const IOUSBConfigurationDescriptor * descriptor);
void IOUSBFreeDescriptor(const IOUSBBOSDescriptor * descriptor);
void IOUSBFreeDescriptor(const IOUSBStringDescriptor * descriptor);


#endif /* USBDriverKitDefs_h */
