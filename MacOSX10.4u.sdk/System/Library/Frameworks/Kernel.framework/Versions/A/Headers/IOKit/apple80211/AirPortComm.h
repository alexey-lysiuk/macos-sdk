/*
 * Copyright (c) 1999 Apple Computer, Inc.  All rights reserved.
 *
 * AirPortComm.h - IOKit Wireless Ethernet driver.
 * ()
 *
 * HISTORY
 *
 * <1>    8/25/99 Import the code from the original written by Les Vogel
 *        fixed to be compiled in MacOSX (and compacted it a little does
 *        Les have a 26'' monitor ??)                                        
 */

#ifndef AIRPORTCOMMON_H
#define AIRPORTCOMMON_H

typedef unsigned char UChar;
typedef unsigned short UShort;
typedef unsigned long ULong;

#define NAME_SIZE    33    // Max station name length 32 + zero
#define SSID_SIZE    33    // Max SSID length 32 + zero
#define KEY_SIZE     5

#ifndef MAC_ADDR_SIZE
#define MAC_ADDR_SIZE 6
#endif

// Signal quality:
typedef struct CommQuality
{
    long communicationQuality;	// Communication Quality of the BSS the station is connected to
    long signalQuality;	        // Average Signal Level of the BSS the station is connected to
    long noiseQuality;	        // Average Noise Level of the currently used Frequency Channel
} CommQuality;
typedef CommQuality *CommQualityPtr;

// These are good default values. If the developer attempts to
// read the status of the communication with inconsistent
// references (read min >= max) the references will be set
// to their defualt values (value in %):
#define DEFAULTMINQUALITYREFERENCE 0
#define DEFAULTMAXQUALITYREFERENCE 100

// PortType -> CFG_CNF_PORT_TYPE
#define PORTTYPE_STATION	0x0001
#define PORTTYPE_AP			0x0002
#define PORTTYPE_DEMO		0x0003
#define DEFAULTPORTTYPE PORTNORMAL
#define PROPERTY_PORT_TYPE "APPortType"

// OwnChannel -> CFG_CNF_OWN_CHANNEL
// Controls the frequency used by the adapter. (1..14)
#define DEFUALTCHANNEL 0
#define IS_VALID_CHANNEL(X) (((X) >=1) && ((X) <=14))
#define PROPERTY_OWN_CHANNEL "APOwnChannel"
#define PROPERTY_CRNT_CHANNEL "APCurrentChannel"
#define PROPERTY_CRNT_SSID "APCurrentSSID"

// ApDensity -> CFG_CNF_SYSTEM_SCALE
// density of the Access Points in the ESS.
// 1..3 APDenisty in ESS.  
#define APDENSITYDEFAULT 1
#define PROPERTY_DENSITY "APDensity"

// MaxDataLen -> CFG_CNF_MAX_DATA_LEN
// Maximum length of MAC Frame Body data:
// Max length of an incoming packet. it makes sense
// to define the maximum fragment as the dimension
// of an mbuffer. (the MacOS9 sets it to 1508)
#define MAXDATALENDEFAULT 1514
#define PROPERTY_MAX_DATA "APMaxDataLen"

// FragmentationThreshold  -> CFG_FRAGMENTATION_THRH (e.g. packetsize):
// MLEN comes directly from the mbuf.h. Since
// we use mbuffers to send data it makes sense
// to define the maximum fragment as the dimension
// of an mbuffer.
// 256..2346 maximum fragment size
#define DEFAULT_FRAG_THRH	(UShort)-1
#define PROPERTY_FRAG_THRH "APFragmentationThreshold"

// RTSThreshold -> CFG_RTS_THRH
// 0..3000 maximum message transmit without RTS/CTS
#define RTSTHRESHOLDDEFAULT (UShort)-1
#define PROPERTY_RTS_THRH "APRTSThreshold"

// TxRateControl -> CFG_TX_RATE_CONTROL
// 3;1..7 data rate used by the transmitter.
// by default is set to  3-auto:
#define TXRATECONTROLDEFAULT 0x0003
#define PROPERTY_TX_RATE "APTxRateControl"

// OwnATIMWindow -> CFG_CNF_OWN_ATIM_WINDOW
// ATIM Window time for IBSS creation
// 0..100 PowerManagement
#define OWNATIMWINDOW 10
#define PROPERTY_OWN_ATIM "APOwnATIMWindow"

// PMMaxSleepDuration -> CFG_CNF_MAX_SLEEP_DURATION
// 1..65535
#define PMMAXSLEEPDURATIONDEFAULT (UShort)-1
#define PROPERTY_MAX_SLEEP "APPMMaxSleepDuration"

// PMHoldoverDuration -> CFG_CNF_HOLDOVER_DURATION
// 1..1000
#define PMHOLDOVERDURATIONDEFAULT (UShort)-1
#define PROPERTY_HOLDOVER_DURATION "APPMHoldoverDuration"

// PMEnabled -> CFG_CNF_PM_ENABLED
// Power manager: default value is disabled (for now)
// 0 = disabled any other value enables it:
#define PMENABLEDDEFAULT 0x0000
#define PROPERTY_PM_ENABLED "APPMEnabled"

// DesiredSSID -> CFG_CNF_DESIRED_SSID
// Specifies the network name to operate within.
// If no name is give it will choose the strongest one
#define DESIREDSSIDDEFAULT ""
#define PROPERTY_DESIRED_SSID "APDesiredSSID"

// OwnSSID -> CFG_CNF_OWN_SSID
#define OWNSSIDDEFUALT "Wireless Network"
#define PROPERTY_OWN_SSID "APOwnSSID"

// OwnName -> CFG_CNF_OWN_NAME
// FIXME: the header says "identification text for diagnostic purposes"
// but I do not really know what to put here ase default value.
#define OWNNAMEDEFUALT ""
#define PROPERTY_OWN_NAME "APOwnName"

// OwnDTIMPeriod -> CFG_CNF_OWN_DTIM_PERIOD
// 1..65535 # of Beacons between Delivery Traffic ID Maps
#define OWNDTIMPERIOD 1
#define PROPERTY_OWN_DTIM "APOwnDTIMPeriod"

// CFG_CNF_DEFAULT_KEYS - encryption key
#define PROPERTY_WEP_KEY "WepKey"

// CFG_CNF_TX_KEY_ID - we always use first of four
#define PROPERTY_TX_KEY "TxKey"
#define DEFAULT_TX_KEY	0

// CFG_CNF_ENCRYPTION - encryption on/off
enum {
	kEncryptionOff	= 0,
	kEncryptionOn	= 1
};
#define PROPERTY_ENCRYPTION "Encryption"
#define DEFAULT_ENCRYPTION	kEncryptionOff

// cipher types passed by join (doubles as keylen for WEP)
enum {
	kNoEncryption	= 0,
	kSecWpaNONE		= 1,
	kSecWpaTKIP		= 2,
	kSecWpaAES		= 3,
	kSecWep40		= 5,	// doubles as the length
	kSecWep104		= 13	// doubles as the length
};

// CFG_CNF_AUTHENTICATION - open system or shared key
enum {
	kAuthUndefined	=	0,
	kAuthOpenSys	=	1,
	kAuthSharedkey	=	2,
	kAuthCiscoLeap	=	3,		// illegal 0x80 Mac-layer auth
	kWpaAuthDisabled = 	4,		// not sure this gets used ???
	kWpaAuthPSK = 		5,		// WPA-PSK (uses 4-way handshake)
	kWpaAuthUnspecd = 	6,		// good ol' EAP
	kWpa2AuthPSK = 		7,		// WPA2 PSK
	kWpa2AuthUnspecd = 	8		// good ol' EAP, but WPA2
};
#define PROPERTY_AUTHENTICATION "Authentication"
#define DEFAULT_AUTH	kAuthOpenSys

// MACRO to test for upper-layer auth mode
#define IS_WPA_AUTHMODE( x )			( (x == kWpaAuthPSK) || (x == kWpaAuthUnspecd) || (x == kWpa2AuthPSK) || (x == kWpa2AuthUnspecd) )
#define kRsnKeyDescType					254		/* EAPOL-KEY frame WPA key desc type */

// IBSS - defaults to don't create
#define PROPERTY_IBSS "IBSSCreation"
#define DEFAULT_IBSS	0

// AllowEnable - User poweroff--default is off
#define PROPERTY_ALLOWENABLE	"AllowEnable"
#define DEFAULT_ALLOWENABLE		1

// Software BaseStation
#define PROPERTY_SWBS			"APAccessPoint"
#define DEFAULT_SWBS			0

// PR: Driver doesn't use these anymore
//#define NET_STACK_SIZE			4
//#define PROPERTY_NETSTACK		"APNetStack"
#define PROPERTY_ROBUSTNESS		"InterferenceRobustness"

// This is the property used to hold the image of the access point rom
#define ACCESS_POINT_IMAGE	"AccessPointImage"

#define kIOLocale			"IOLocale"			// property to indicate locale (USA, etc)
#define kIOFirmwareVersion	"IOFirmwareVersion"	// firmware version string property
#define kAirPortFeatures	"APFeatures"		// bit fields defining features
#define kAPPropUseBSSID		"APUseBSSID"		// force fixed BSSID on next join
#define kAPPropUseBrcmSupp	"APUseBrcmSupp"		// bool: use Broadcom internal supplicant
#define kAPPropMPCTimeout	"APMPCTimeout"		// MPC timer in seconds
#define kAPPropSysLogDbg	"APSysLogDebug"		// bool:  enable SysLog debug output

enum	// defines feature bits used by kAirPortFeatures property
{
	kAPFeatureWpaTKIP = 1,
	kAPFeatureWpaAES = 2
};


// Access to the hcf configutartion functions:
// ==========================================
#define HCFBUFFERSIZE	512

typedef struct AirPortHCFParamerter
{
   UShort parameterName;               // the type of HFS parameter
   ULong dataLength;                   // the size of the buffer data (on bytes)
   char   dataBuffer[HCFBUFFERSIZE];   // the buffer data follows...
} AirPortHCFParamerter;
typedef AirPortHCFParamerter *AirPortHCFParamerterPtr;

// Gets scan results
// =================
#ifndef FRAMEWORK_BUILD
// This is also defined in Wireless.h ...
typedef struct WirelessScanInfo
{
    UShort bssChannelID;           // BSS Channel ID 1..14
    UShort averageNoiseLevel;      // Avg Noise
    UShort signalLevel;            // signal level
    UChar  bssMACAddress[6];       // MAC address of BSSID
    UShort bssBeaconInterval;      // BSS Beacon interval
    UShort bssCapability;          // BSS Capability
    UShort ssidLen;   	           // name length
    char   ssid[32];               // name
} WirelessScanInfo;
typedef WirelessScanInfo *WirelessScanInfoPtr;
#endif

// this wpa struct must match the corresponding one in wlc_bss_info_t
typedef struct
{
	UInt8 flags;		/* wpa flags */
	UInt8 multicast;	/* multicast cipher */
	UInt8 ucount;		/* count of unicast ciphers */
	UInt8 unicast[4];	/* unicast ciphers */
	UInt8 acount;		/* count of auth modes */
	UInt8 auth[4];		/* Authentication modes */
} WpaInfo;

// define bits for WpaInfo flags field
#define WPA_FLAGS_1SUPPORTED	0x1		// WPA-1 is supported
#define WPA_FLAGS_PREAUTH		0x2
#define WPA_FLAGS_2SUPPORTED	0x80	// WPA-2 is supported

/* WPA cipher suites for WpaInfo struct */
#define WPA_CIPHER_NONE		0	/* None */
#define WPA_CIPHER_WEP_40	1	/* WEP (40-bit) */
#define WPA_CIPHER_TKIP		2	/* TKIP: default for WPA */
#define WPA_CIPHER_AES_OCB	3	/* AES (OCB) */
#define WPA_CIPHER_AES_CCM	4	/* AES (CCM) */
#define WPA_CIPHER_WEP_104	5	/* WEP (104-bit) */

/* WPA authentication modes for WpaInfo struct */
//#define WPA_AUTH_NONE		0	/* None */
//#define WPA_AUTH_UNSPECIFIED	1	/* Unspecified authentication over 802.1X: default for WPA */
//#define WPA_AUTH_PSK		2	/* Pre-shared Key over 802.1X */
#define WPA2_AUTH			0x80	// hi bit indicates WPA-2 (as opposed to WPA-1)

typedef struct
{
	WirelessScanInfo	si;		// This is the original scan info results struct
	WpaInfo				wpa;	// this is the WPA add-on
} ScanInfoW;

enum {
	kInterferenceRobustness = 0x01,
	kFactoryFresh			= 0x02,
	//
	kCurrentVersionIE		= 1
};

// The data structure contained within the proprietary information element
// This data is received in Network byte order
typedef struct AppleIE
{
	UInt8		type;			// IE type
	UInt8		len;			// IE length
	UInt8		oui[3];			// Apple OUI
	UInt8		version;		// current version number
	UInt8		productID;		// allows for 256 products
	UInt8		flags0;			// reserved
	UInt8		flags1;			// flag bits as defined above
} AppleIE;

typedef struct ProprietaryIE
{
	UInt32		index;				// index into scan array
	UInt32		oui;				// OUI in 32-bit format
	union {
		struct AppleIE	appleIE;	// Apple information element
	} u;							// room to add others
} ProprietaryIE;					// get proprietary information element

#define APPLE_OUI		0x000393	/* 00-03-93 */
#define APPLE_IE_LEN	(7 + 2)		/*includes type/length bytes.  this may change */

#ifndef FRAMEWORK_BUILD
// This is also defined in Wireless.h ...
typedef enum {							// capability flags
    kWirelessESS			= 0x0001,	// base station
    kWirelessIBSS			= 0x0002,	// IBSS (Peer-to-peer)
    kWirelessPrivacy		= 0x0010,	// Requires WEP
	
    kWirelessApple10AP		= 0x8000,	// Apple 1.0 Base Station (can't roam)
										// (1st 6 chars of name don't display)
    kWirelessUninitedAP		= 0x4000,	// Unitialized base station
										// (1st 6 chars of name match MAC address)
} WirelessAPICapabilityFlags;

// This block holds all the scans:
typedef struct WirelessScanHolder
{
    UInt32 numberOfScans;
    WirelessScanInfo scans[1];
} WirelessScanHolder;
typedef WirelessScanHolder *WirelessScanHolderPtr;
#endif

// Wireless Status:
// ================
#define WSTATUS_VERSION		0
typedef struct WirelessStatus
{
	UInt16		version;			// version of this struct
	UInt16		linkStatus;			// Link status returned by CFG_PORT_STAT
	UInt16		portType;			// operating mode (client, AP, ibss)
	char		ssid[34];			// Network name (C-string)
	UInt8		macAddr[6];			// this card's MAC address
	UInt8		bssID[6];			// current BSS ID (if valid)
	UInt32		lastAssocStatus;	// result of last associate
	
} WirelessStatus, *WirelessStatusPtr;

enum	// lastAssocStatus
{
	kAssocReset,			// 0 = start over, wait for new assoc
	kAssocConnect,			// 1 = connected
	kAssocBadPW,			// 2 = challenge fail
	kAssocBadAuth,			// 3 = authenticate fail
	kAssocUnknown,			// 4 - unkown failure
	kAssocNotAuthenticated,	// 5 - not in ACL list
	kAssocDirectScanFail,	// 6 - Low level directed scan failed
	kAssocTimeOut,			// 7 - timed out
	kAssocDenied,			// 8 - AP denying for personal reaons
	kAssocOutOfRange		// 9 - client lost beacons
};

enum	// Link status returned by CFG_PORT_STAT
{
	kPortStatusUnavailable,	// 0 = CFG_PORT_STAT failed
	kPortDisabled,			// 1 = Disabled
	kPortSearching,			// 2 = Searching for initial connection
	kPortIBSSConn,			// 3 = Connected to IBSS
	kPortESSConn,			// 4 = Connected to ESS
	kPortOutOfRange,		// 5 = Out of Range (in ESS)
	kPortWDSConn,			// 6 = Connected to WDS
//	kPortULAuthenticating,	// 7 = Upper-Layer Authenticating
xxxxkPortULAuthenticating,	// 7 = Upper-Layer Authenticating
	kPortSecure				// 8 = Secure (RSN handshake succeeded)
};

enum
{
	kPortTypeStation = 1,	// 1 - station
	kPortTypeAP,			// 2 - Access Point
	kPortTypeDemo,			// 3 - Demo Mode (not used, I hope!)
	kPortTypeIBSS			// 4 - IBSS
};

// bssType values for switching networks
enum
{
	kBssTypeAny,			// 0 - any available
	kBssTypeInfra,			// 1 - Infrastructure BSS
	kBssTypeIBSS,			// 2 - IBSS
	kBssTypeLegacy = 7		// Legacy (b-only) -- defined in Apple80211.h
};

// Switch network parameter:
// =========================
typedef struct AttachToNetwork
{
	UShort	bssChannelID;			// Desired channel
	UChar	bssMACAddress[6];		// Desired BSSID
	char	ssid[34];				// Network name.
	UInt32	bssType;				// selects Infra/IBSS
} AttachToNetwork;
typedef AttachToNetwork *AttachToNetworkPtr;

// Switch WEP network parameter:
// =============================
// Note:  cannot change this structure without changing format of prefs!!!
typedef struct WepNetwork
{
//	UInt32	keyLen;					// zero keyLen ==> encryption off
	UInt16	bssType;				// selects Infra/IBSS
	UInt16	keyLen;					// zero keyLen ==> encryption off
	UInt8	key[16];				// WEP key (5 or 13 bytes)
	UInt16	authentication;			// open system, or shared key
	char	ssid[34];               // Network name.
	UInt8	rsnKey[32];				// RSN keys are bigger
} WepNetwork;
typedef WepNetwork *WepNetworkPtr;

// Create IBSS network parameter:
// =============================
typedef struct IbssNetwork
{
	WepNetwork	netParams;			// the usual params
	UInt16		channel;			// channel to use
} IbssNetwork;
typedef IbssNetwork *IbssNetworkPtr;

// Access Point parameters
// =========================
typedef struct BaseStationParams
{
	WepNetwork	netParams;			// the usual params
	UInt16		channel;			// channel to use
	UInt16		enabled;			// whether to enable or disable
} BaseStationParams;
typedef BaseStationParams *BaseStationParamsPtr;

// define key types when creating a network (SWBS)
enum {
	kKeyTypeNone,
	kKeyType40Bit,
	kKeyType104Bit
};

// These errors are returned by the AirPort Driver
// while trying to update the base station.
#define sys_airport       err_system(0x88)
#define airport_driver_err(err)  (sys_airport | err)

#define kBaseStationUpdateOK                    0
#define kBaseStationDoesNotNeedUpdate           airport_driver_err(256)
#define kFailToContactAirPort           	airport_driver_err(257)
#define kAirPortReturnUserClientCreateErr       airport_driver_err(258)
#define kAirPortReturnUserClientAttachErr       airport_driver_err(259)
#define kAirPortReturnUserClientStartErr        airport_driver_err(260)
#define kAirPortReturnBadMagicCookie            airport_driver_err(261)
#define kAirPortReturnRequiresUpgrade           airport_driver_err(262)
#define kAirPortReturnNotRequiresUpgrade        airport_driver_err(263)
#define kAirPortReturnNoScanAvailable           airport_driver_err(264)
#define kAirPortReturnNoMoreScanAvailable	airport_driver_err(265)
#define kAirPortReturnEnabled			airport_driver_err(266)
#define kAirPortReturnDisabled			airport_driver_err(267)
#define kAirPortReturnPowerOn			airport_driver_err(268)
#define kAirPortReturnPowerOff			airport_driver_err(269)
#define kAirPortReturnNoSuchIE			airport_driver_err(270)

// These are events we may wish to communicate at the level above:
#define kIOScanResultEvent                      0x00010000
#define kIOAirPortAssociation                   0x00020000
#define kIOAirPortReassociation                 0x00040000
#define kIOAirPortDisassociation                0x00080000
#define kIOAirPortInvalidWEPKey                 0x00100000

// This is the magic number to identify the airport user clients
#define kAirPortTypeMagicCookie	12

// define MIC error report bit values
enum
{
	kReportMicErrorPairwise		= 0x80000000,
	kReportMicErrorCMActive		= 0x40000000
};

// The user accessible methods:
//	NOTE:	these same selectors are also used by notifications to
//			report status changes, etc.
enum {
    kAirPortSetConfiguration = 0,
    kAirPortGetConfiguration,
    kAirPortConfigure,
    kAirPortGetSignalInfo,
    kAirPortGetNetworkInfo,
    kAirPortDownloadStation,					// 5
    kAirPortDownloadAccessPoint,
    kAirPortParameter,
    kAirPortPerformScan,
    kAirPortGetScanResult,
    kAirPortSwitchNetwork,						// 10
    kAirPortBeAccessPoint,
    kAirSetPowerStatus,							// 12
    kAirSetPortStatus = kAirSetPowerStatus,		// 12
    kAirGetPowerStatus,							// 13
    kAirGetPortStatus = kAirGetPowerStatus,		// 13
    kAirSetPowerMode,
    kAirGetPowerMode,							// 15
    kAirSetTraceMode,
    kAirPortSwitchWepNetwork,
    kGetWirelessStatus,
    kCreateIbssNetwork,
    kGetChannelList,							// 20
    kAirPortDownloadFirmware,
    kNetStackChanged,			// only used to messageClients
    kNetStackChanged1,			// hack to circumvent message size limit???
    kNetStackChanged2,
    kNetStackChanged3,							// 25
	kSetLeapIDPW,				// passes in Leap ID & password
	kSetDynamicKey,				// change WEP key settings on the fly
	kDriverPrivate,				// private selector understood only by driver
	kDisassociate,				// disasssociate from current network
	kGetInterferenceMitigation,					// 30
	kSetInterferenceMitigation,
	kReportLinkStatus,
    kGetScanWResult,			// expanded scan includes WPA info
	kReportMicError,
	kGetInformationElement,						// 35
	kGetCurrentMaxTxRate,		// return the current maximum data rate
	kGetPowerSavingsMode,		// return power savings mode on/off
	kTimeoutScan,				// Inform the driver that a scan has timed out
	kGetCurrentTxRate,			// return the current Tx data rate
    
    // This is the count for the method arrary:
    kAirPortCommands
};

	// use to change keys dynamically (kSetDynamicKey)
typedef struct KeyMaterial
{
	UInt32		keyType;		// Unicast, Multicast, etc.
	UInt32		keyIndex;		// for default keys
	UInt32		keyMap;			// for key-mapping keys
	UInt32		keyLen;			// length of key in octets
	UInt8		key[32];		// room for 256 bits
} KeyMaterial;
typedef KeyMaterial *KeyMaterialPtr;

#define kPairwiseKey	0x80000000	/* bit 31 of keyMap indicates Pairwise key */

// define keytypes for above
enum {
	kKeyTypeDefault = 0,
	kKeyTypeMulticast,			// used for multi/broad-cast rx
	kKeyTypeIndexedTx,			// default (indexed) key for tx
	kKeyTypeIndexedRx,			// default (indexed) key for unicast rx
	kKeyTypeWPA_TKIP,			// WPA-TKIP
	kKeyTypeWPA_AES,			// WPA-AES
	//
	kKeyTypeWPA_PSK,
	kKeyTypeWPA_Session,
	kKeyTypeWPA_Server,
	//
	kNumKeyTypes
};

	// selectors for kAirSetPowerStatus
enum {
	kUserAllowEnable	= 1,	// 1 - enable allowed by user, always enable
	kUserDisallowEnable,		// 2 - enable disallowed by user, always disable
	kCardEnable,				// 3 - enable card if allowed by user
	kCardDisable,				// 4 - always disable
	kCardConfigure,				// 5 - called when ioReg populated with config at boot
	kCardPowered,				// 6 - used in messageClients whenever power really goes on
	kPowerSaveOff,				// 7 - 802.11 PowerSave off (default)
	kPowerSaveOn,				// 8 - 802.11 PowerSave on
	kPowerSaveFast				// 9 - 802.11 "Fast" PowerSave (Broadcom feature)
};
	
	// bit definitions for kAirGetPowerStatus
#define kUserEnabled		0x0001
#define kCardIsEnabled		0x0002
#define kCardIsConfigured	0x0004

typedef struct FWBlock
{
	UInt32	fwType;
		// these are offsets(in bytes) from the beginning of the data[] block
	UInt32	memOffset;
	UInt32	plugOffset;
	UInt32	segOffset;
	UInt32	infoOffset;
	UInt32	compOffset;
	UInt32	buildOffset;
	UInt32	idOffset;
	UInt8	data[1];
} FWBlock;
typedef struct FWBlock* FWBlockPtr;

// valid types for FWBlock
enum {
	kPrimaryFirmware,		// 0 - Primary
	kStationFirmware,		// 1 - Station (client or secondary)
	kAccessPointFirmware,	// 2 - AP (tertiary)
	
	kNumFirmwareTypes
};

// This is the way the messages are sent frm the user space to kernel space:
typedef struct AirportCommand
{
    unsigned char commandID;	// one of the commands above (kAirPortCommands)
    char data[1];		// this is not really one byte, it is as bis as I like
                                // I set it to 1 just to make the compiler happy
} AirportCommand;
typedef AirportCommand *AirportCommandPtr;



#endif // AIRPORTCOMMON_H
