/*
 * Copyright (c) 2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _IO80211CONTROLLER_H
#define _IO80211CONTROLLER_H

/*
 * Kernel
 */
#if defined(KERNEL) && defined(__cplusplus)

#include <IOKit/network/IOEthernetController.h>

#include <sys/param.h>
#include <net/bpf.h>

// always compile with legacy compatibility for now. This will go away soon.
#ifndef IO80211_LEGACY_COMPAT
#define IO80211_LEGACY_COMPAT
#endif 

#ifdef IO80211_LEGACY_COMPAT
#include "apple80211_var.h"
#endif

#define DEFAULT_SCAN_TIME	3	// seconds

/*! @enum LinkSpeed.
    @abstract ???.
    @discussion ???.
    @constant LINK_SPEED_80211B 11 Mbps.
    @constant LINK_SPEED_80211G 54 Mbps.
	*/
enum {
	LINK_SPEED_80211B	= 11000000ul,		// 11 Mbps
	LINK_SPEED_80211G	= 54000000ul		// 54 Mbps
};

class IO80211Interface;

/*! @class IO80211Controller
    @abstract Abstract superclass for 80211 controllers. 
    @discussion 80211 controller drivers should subclass IO80211Controller, and implement or override the hardware specific methods to create an 80211 driver. An interface object (an IO80211Interface instance) must be instantiated by the driver, through attachInterface(), to connect the controller driver to the data link layer. 
	*/
class IO80211Controller : public IOEthernetController
{
    OSDeclareAbstractStructors( IO80211Controller )

	#ifdef IO80211_LEGACY_COMPAT
	private:
		struct apple80211_key		_lastAssocKey;
		UInt8	_appleIE[9];	// one-behind IE cache
		
		public:
		IOReturn newUserClient( task_t owningTask, void * securityID, UInt32 type, 
						OSDictionary * properties, IOUserClient ** handler );
		IOReturn queueCommand( UInt8 commandCode, void *arguments, void *returnValue );
		static IOReturn execCommand( OSObject * obj, void *field0, void *field1, void *field2, void *field3 );
		UInt8 * getAppleIEPtr();

		IOReturn IO80211Controller::getLastAssocKey(struct apple80211_key* key);
		IOReturn IO80211Controller::setLastAssocKey(struct apple80211_key* key);
	#endif

public:
	
	/*! @function start
		@abstract ???.
		@param provider ???.
		@result Returns true on success, false otherwise. 
		*/ 
	virtual bool				start(IOService *provider);

	/*! @function stop
		@abstract ???.
		@param provider ???.
		*/ 
	virtual void				stop(IOService *provider);

	/*! @function createWorkLoop
		@abstract ???.
		@result ???. 
		*/ 
	virtual bool				createWorkLoop();

	/*! @function getWorkLoop
		@abstract ???.
		@result ???. 
		*/ 
	virtual IOWorkLoop			*getWorkLoop() const;

	/*! @function createOutputQueue
		@abstract ???.
		@result IOOutputQueue ???. 
		*/ 
	virtual IOOutputQueue		*createOutputQueue();

	/*! @function enable
		@abstract ???.
		@param aNetif ???.
		@result Returns ???. 
		*/ 
	virtual IOReturn			enable(IONetworkInterface *aNetif);

	/*! @function disable
		@abstract ???.
		@param aNetif ???.
		@result Returns ???. 
		*/ 
	virtual IOReturn			disable(IONetworkInterface *aNetif);

	/*! @function getHardwareAddress
		@abstract Gets the 80211 controller's station address.
		@discussion The default implementation of the abstract method inherited from IONetworkController. This method will call the overloaded form IO80211Controller::getHardwareAddress() that subclasses are expected to override.
		@param addr The buffer where the controller's hardware address should be written.
		@param inOutAddrBytes The size of the address buffer provided by the client, and replaced by this method with the actual size of the hardware address in bytes.
		@result Returns kIOReturnSuccess on success, or an error otherwise. 
		*/
	virtual IOReturn			getHardwareAddress(IOEthernetAddress *addr);

	/*! @function registerWithPolicyMaker
		@abstract ???.
		@param policyMaker ???.
		@result Returns ???. 
		*/ 
    virtual IOReturn			registerWithPolicyMaker(IOService *policyMaker);
	
	/*! @function scanTimeForRequest
		@abstract ???.
		@param policyMaker ???.
		@result Returns ???. 
		*/ 
	virtual UInt32				scanTimeForRequest( IO80211Interface * interface, 
													struct apple80211_scan_data * sd ) { return DEFAULT_SCAN_TIME; }
	
	/*! @function inputMonitorPacket
		@abstract ???.
		@param m ???.
		*/ 
#if defined( _MODERN_BPF )
	virtual void				inputMonitorPacket( mbuf_t m, UInt32 dlt, void * header, size_t header_len );
#else
	virtual void				inputMonitorPacket( mbuf_t m );
#endif
	
	/*! @function outputRaw80211Packet
		@abstract ???.
		@param m ???.
		*/ 
	virtual int					outputRaw80211Packet( IO80211Interface * interface, mbuf_t m )	{ return ENXIO; }

	/*! @function monitorPacketHeaderLength
		@abstract ???.
		@result Returns ???. 
		*/ 
	virtual UInt32				monitorPacketHeaderLength( IO80211Interface * interface )	{ return 0; }

	/*! @function inputMonitorPacket
		@abstract ???.
		@result Returns ???. 
		*/ 
	virtual UInt32				monitorDLT( IO80211Interface * interface ) { return DLT_NULL; }
	
	
	/*! @function monitorModeSetEnabled
		@abstract ???.
		@result Returns ???. 
		*/ 
	
#if defined( _MODERN_BPF )
	virtual SInt32				monitorModeSetEnabled( IO80211Interface * interface, bool enabled, UInt32 dlt ) {return ENXIO; }
#else
	virtual	SInt32				monitorModeSetEnabled( IO80211Interface * interface, bool enabled )	{ return ENXIO; }
#endif
	
	
	/*! @function getNetworkInterface
		@abstract ???.
		@result Returns ???. 
		*/ 

	virtual IO80211Interface	*getNetworkInterface();
	
	/*! @function apple80211_ioctl
		@abstract ???.
		@param interface ???.
		@param ifn ???.
		@param cmd ???.
		@param data ???.
		@result Returns ???. 
		*/ 
	virtual	SInt32				apple80211_ioctl(IO80211Interface	*interface,
												 ifnet_t			ifn,
												 u_int32_t			cmd,
												 void				*data);
	
	/* ioctl handlers */
	
	// SIOCGA80211
	
	// Required
	virtual SInt32				getSSID(IO80211Interface			*interface,
										struct apple80211_ssid_data *sd) = 0;

	virtual SInt32				getCHANNEL(IO80211Interface			*interface,
										   struct apple80211_channel_data *cd) = 0;

	virtual SInt32				getBSSID(IO80211Interface			*interface,
										 struct apple80211_bssid_data *bd) = 0;

	virtual SInt32				getCARD_CAPABILITIES(IO80211Interface	*interface,
													 struct apple80211_capability_data *cd) = 0;

	virtual SInt32				getSTATE(IO80211Interface			*interface,
										 struct apple80211_state_data *sd) = 0;

	virtual SInt32				getRSSI(IO80211Interface			*interface,
										struct apple80211_rssi_data *rd) = 0;

	virtual SInt32				getPOWER(IO80211Interface			*interface,
										 struct apple80211_power_data *pd) = 0;

	virtual SInt32				getSCAN_RESULT(IO80211Interface		*interface,
											   struct apple80211_scan_result **scan_result)	= 0;
	
	virtual SInt32				getASSOCIATE_RESULT(IO80211Interface	*interface,
													struct apple80211_assoc_result_data *ard) = 0;

	virtual SInt32				getRATE(IO80211Interface			*interface,
										struct apple80211_rate_data *rd) = 0;

	virtual SInt32				getSTATUS_DEV(IO80211Interface		*interface,
											  struct apple80211_status_dev_data *dd) = 0;
											  
	virtual SInt32				getRATE_SET(IO80211Interface	*interface,
												  struct apple80211_rate_set_data *rd) = 0;

	virtual SInt32				getPOWERSAVE(IO80211Interface		*interface,
											 struct apple80211_powersave_data *pd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getPROTMODE(IO80211Interface		*interface,
											struct apple80211_protmode_data *pd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getTXPOWER(IO80211Interface			*interface,
										   struct apple80211_txpower_data *td)
		{ return EOPNOTSUPP; }

	virtual SInt32				getPHY_MODE(IO80211Interface		*interface,
											struct apple80211_phymode_data *pd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getOP_MODE(IO80211Interface			*interface,
										   struct apple80211_opmode_data *od)
		{ return EOPNOTSUPP; }

	virtual SInt32				getNOISE(IO80211Interface			*interface,
										 struct apple80211_noise_data *nd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getINT_MIT(IO80211Interface			*interface,
										   struct apple80211_intmit_data *imd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getAUTH_TYPE(IO80211Interface		*interface,
											 struct apple80211_authtype_data *ad)
		{ return EOPNOTSUPP; }

	virtual SInt32				getSUPPORTED_CHANNELS(IO80211Interface	*interface,
													  struct apple80211_sup_channel_data *sd)
		{ return EOPNOTSUPP; }

	virtual SInt32				getLOCALE(IO80211Interface			*interface,
										  struct apple80211_locale_data *ld)
		{ return EOPNOTSUPP; }

	virtual SInt32				getAP_MODE(IO80211Interface			*interface,
										   struct apple80211_apmode_data *ad)
		{ return EOPNOTSUPP; }

	virtual SInt32				getFRAG_THRESHOLD(IO80211Interface	*interface,
												  struct apple80211_frag_threshold_data *td)
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getSHORT_SLOT(IO80211Interface *interface, 
												  struct apple80211_short_slot_data * sd)
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getMULTICAST_RATE( IO80211Interface * interface,
												  struct apple80211_rate_data * rd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getSHORT_RETRY_LIMIT( IO80211Interface * interface,
													struct apple80211_retry_limit_data * rld )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getLONG_RETRY_LIMIT( IO80211Interface * interface,
													struct apple80211_retry_limit_data * rld )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getTX_ANTENNA( IO80211Interface * interface,
											   struct apple80211_antenna_data * ad )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getRX_ANTENNA( IO80211Interface * interface,
											   struct apple80211_antenna_data * ad )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getANTENNA_DIVERSITY( IO80211Interface * interface,
													  struct apple80211_antenna_data * ad )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getDTIM_INT( IO80211Interface * interface,
											  struct apple80211_dtim_int_data * dd )
		{ return EOPNOTSUPP; }
	
	virtual SInt32				getSTATION_LIST( IO80211Interface * interface,
												 struct apple80211_sta_data * sd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getDRIVER_VERSION( IO80211Interface * interface,
												   struct apple80211_version_data * vd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getHARDWARE_VERSION( IO80211Interface * interface,
												    struct apple80211_version_data * vd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getROM( IO80211Interface * interface,
										struct apple80211_rom_data * rd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getRAND( IO80211Interface * interface,
										 struct apple80211_rand_data * rd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getBACKGROUND_SCAN( IO80211Interface * interface,
													struct apple80211_scan_data * sd )
		{ return EOPNOTSUPP; }
	
	virtual SInt32				getRSN_IE( IO80211Interface * interface,
											struct apple80211_rsn_ie_data * rid )
		{ return EOPNOTSUPP; }
	
	virtual SInt32				getAP_IE_LIST( IO80211Interface * interface,
												struct apple80211_ap_ie_data * ied )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				getSTATS( IO80211Interface * interface,
										   struct apple80211_stats_data * sd )
		{ return EOPNOTSUPP; }
	
	// SIOCSA80211
	
	// Required 
	virtual SInt32				setSCAN_REQ(IO80211Interface		*interface,
											struct apple80211_scan_data *sd) = 0;

	virtual SInt32				setASSOCIATE(IO80211Interface		*interface,
											 struct apple80211_assoc_data *ad) = 0;

	virtual SInt32				setPOWER(IO80211Interface			*interface,
										 struct apple80211_power_data *pd) = 0;

	virtual SInt32				setCIPHER_KEY(IO80211Interface		*interface,
											  struct apple80211_key *key) = 0;

	virtual SInt32				setAUTH_TYPE(IO80211Interface		*interface,
											 struct apple80211_authtype_data *ad) = 0;

	virtual SInt32				setDISASSOCIATE(IO80211Interface	*interface) = 0;

	virtual SInt32				setSSID(IO80211Interface			*interface,
										struct apple80211_ssid_data *sd) = 0;

	virtual SInt32				setAP_MODE(IO80211Interface			*interface,
										   struct apple80211_apmode_data *ad) = 0;
	
	virtual SInt32				setCHANNEL(IO80211Interface			*interface,
										   struct apple80211_channel_data *cd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setPOWERSAVE(IO80211Interface		*interface,
											 struct apple80211_powersave_data *pd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setPROTMODE(IO80211Interface		*interface,
											struct apple80211_protmode_data *pd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setTXPOWER(IO80211Interface			*interface,
										   struct apple80211_txpower_data *td)
		{ return EOPNOTSUPP; }

	virtual SInt32				setIBSS_MODE(IO80211Interface		*interface,
											 struct apple80211_network_data *nd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setHOST_AP_MODE(IO80211Interface	*interface,
												struct apple80211_network_data *nd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setLOCALE(IO80211Interface			*interface,
										  struct apple80211_locale_data *ld)
		{ return EOPNOTSUPP; }

	virtual SInt32				setINT_MIT(IO80211Interface			*interface,
										   struct apple80211_intmit_data *imd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setBSSID(IO80211Interface			*interface,
										 struct apple80211_bssid_data *bd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setDEAUTH(IO80211Interface			*interface,
										  struct apple80211_deauth_data *dd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setCOUNTERMEASURES(IO80211Interface	*interface,
												   struct apple80211_countermeasures_data *cd)
		{ return EOPNOTSUPP; }

	virtual SInt32				setFRAG_THRESHOLD(IO80211Interface	*interface,
												  struct apple80211_frag_threshold_data *td)
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setRATE_SET(IO80211Interface	*interface,
												  struct apple80211_rate_set_data *rd)
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setSHORT_SLOT(IO80211Interface *interface, 
												  struct apple80211_short_slot_data * sd)
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setRATE( IO80211Interface * interface,
												  struct apple80211_rate_data * rd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setMULTICAST_RATE( IO80211Interface * interface,
												  struct apple80211_rate_data * rd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setSHORT_RETRY_LIMIT( IO80211Interface * interface,
													struct apple80211_retry_limit_data * rld )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setLONG_RETRY_LIMIT( IO80211Interface * interface,
													struct apple80211_retry_limit_data * rld )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setTX_ANTENNA( IO80211Interface * interface,
											   struct apple80211_antenna_data * ad )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setANTENNA_DIVERSITY( IO80211Interface * interface,
													  struct apple80211_antenna_data * ad )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setDTIM_INT( IO80211Interface * interface,
											  struct apple80211_dtim_int_data * dd )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setRSN_IE( IO80211Interface * interface,
											struct apple80211_rsn_ie_data * rid )
		{ return EOPNOTSUPP; }
		
	virtual SInt32				setBACKGROUND_SCAN( IO80211Interface * interface,
													struct apple80211_scan_data * sd )
		{ return EOPNOTSUPP; }
		
	
protected:
	
		// optional methods provided by subclass
	virtual bool				promiscuousEnabled();
	
		// mostly internal use, but may need to override
	
	virtual IONetworkInterface *createInterface();

	virtual void				inputPacket( mbuf_t m );

	virtual SInt32				apple80211_ioctl_get(IO80211Interface	*interface,
													 ifnet_t			ifn,
													 void				*data);

	virtual SInt32				apple80211_ioctl_set(IO80211Interface	*interface,
													 ifnet_t			ifn,
													 void				*data);

private:
	IOWorkLoop					*_myWorkLoop;
	IONetworkInterface			*_netIF;


		// Virtual function padding
	OSMetaClassDeclareReservedUnused( IO80211Controller,  0);
	OSMetaClassDeclareReservedUnused( IO80211Controller,  1);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  2);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  3);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  4);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  5);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  6);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  7);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  8);
    OSMetaClassDeclareReservedUnused( IO80211Controller,  9);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 10);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 11);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 12);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 13);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 14);
    OSMetaClassDeclareReservedUnused( IO80211Controller, 15);
};
	
#endif /* defined(KERNEL) && defined(__cplusplus) */
	
#endif /* !_IO80211CONTROLLER_H */
	