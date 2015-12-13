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

#ifndef _APPLE80211_VAR_H_
#define _APPLE80211_VAR_H_

#include <sys/types.h>
#include <net/ethernet.h>

// Sizes and limits
#define APPLE80211_ADDR_LEN			6
#define APPLE80211_MAX_RATES		15
#define APPLE80211_MAX_SSID_LEN		32
#define APPLE80211_MAX_ANTENNAE		4
#define APPLE80211_MAX_RADIO		4
#define APPLE80211_MAX_CHANNELS		32
#define APPLE80211_MAX_STATIONS		128
#define APPLE80211_MAX_VERSION_LEN	256
#define APPLE80211_MAX_ROM_SIZE		512
#define APPLE80211_MAX_RSN_IE_LEN	257		// 255 + type and length bytes

enum apple80211_phymode {
	APPLE80211_MODE_UNKNOWN = 0,
	APPLE80211_MODE_AUTO	= 0x1,		// autoselect
	APPLE80211_MODE_11A		= 0x2,		// 5GHz, OFDM
	APPLE80211_MODE_11B		= 0x4,		// 2GHz, CCK
	APPLE80211_MODE_11G		= 0x8,		// 2GHz, OFDM
	APPLE80211_MODE_11N		= 0x10,		// 5GHz, OFDM?
	APPLE80211_MODE_TURBO_A	= 0x20,		// 5GHz, OFDM, 2x clock
	APPLE80211_MODE_TURBO_G	= 0x40,		// 2GHz, OFDM, 2x clock
};

// flags
enum apple80211_opmode {
	APPLE80211_M_NONE		= 0x0,
	APPLE80211_M_STA		= 0x1,		// infrastructure station
	APPLE80211_M_IBSS		= 0x2,		// IBSS (adhoc) station
	APPLE80211_M_AHDEMO		= 0x4,		// Old lucent compatible adhoc demo
	APPLE80211_M_HOSTAP		= 0x8,		// Software Access Point
	APPLE80211_M_MONITOR	= 0x10		// Monitor mode
};

enum apple80211_apmode	{
	APPLE80211_AP_MODE_UNKNOWN = 0,	
	APPLE80211_AP_MODE_IBSS	   = 1,		// IBSS (adhoc) station
	APPLE80211_AP_MODE_INFRA   = 2,		// Access Point
	APPLE80211_AP_MODE_ANY	   = 3,		// Any supported mode
};

enum apple80211_state {
	APPLE80211_S_INIT	= 0,			// default state
	APPLE80211_S_SCAN	= 1,			// scanning
	APPLE80211_S_AUTH	= 2,			// try to authenticate
	APPLE80211_S_ASSOC	= 3,			// try to assoc
	APPLE80211_S_RUN	= 4,			// associated
};

enum apple80211_protmode {
	APPLE80211_PROTMODE_OFF		= 0,	// no protection
	APPLE80211_PROTMODE_AUTO	= 1,	// auto
	APPLE80211_PROTMODE_CTS		= 2,	// CTS to self
	APPLE80211_PROTMODE_RTSCTS	= 3,	// RTS-CTS
};

enum apple80211_cipher_type {  
	APPLE80211_CIPHER_NONE	  = 0,		// open network
	APPLE80211_CIPHER_WEP_40  = 1,		// 40 bit WEP
	APPLE80211_CIPHER_WEP_104 = 2,		// 104 bit WEP
	APPLE80211_CIPHER_TKIP	  = 3,		// TKIP (WPA)
	APPLE80211_CIPHER_AES_OCB = 4,		// AES (OCB)
	APPLE80211_CIPHER_AES_CCM = 5,		// AES (CCM)
	APPLE80211_CIPHER_PMK	  = 6,		// PMK
};

enum apple80211_cipher_key_type
{
	APPLE80211_CIPHER_KEY_TYPE_UNICAST	 = 0,	// unicast cipher key
	APPLE80211_CIPHER_KEY_TYPE_MULTICAST = 1	// multicast cipher key
};

// Low level 802.11 authentication types

enum apple80211_authtype_lower
{
	APPLE80211_AUTHTYPE_OPEN		= 1,	// open
	APPLE80211_AUTHTYPE_SHARED		= 2,	// shared key
	APPLE80211_AUTHTYPE_CISCO		= 3,	// cisco net eap
};

// Higher level authentication used after 802.11 association complete

enum apple80211_authtype_upper
{
	APPLE80211_AUTHTYPE_NONE		= 0,	//	No upper auth
	APPLE80211_AUTHTYPE_WPA			= 1,	//	WPA
	APPLE80211_AUTHTYPE_WPA_PSK		= 2,	//	WPA PSK
	APPLE80211_AUTHTYPE_WPA2		= 3,	//	WPA2
	APPLE80211_AUTHTYPE_WPA2_PSK	= 4,	//	WPA2 PSK
	APPLE80211_AUTHTYPE_LEAP		= 5,	//	LEAP
	APPLE80211_AUTHTYPE_8021X		= 6,	//	802.1x
};

enum apple80211_associate_result
{
	APPLE80211_RESULT_RESET				= 0,	// No result yet available
	APPLE80211_RESULT_SUCCESS			= 1,	// Success
	APPLE80211_RESULT_INVALID_PARAMS	= 2,	// Invalid association parameters
	APPLE80211_RESULT_TIMEOUT			= 3,	// Association timed out
	APPLE80211_RESULT_REFUSED			= 4,	// Association request refused
};

enum apple80211_unit
{
	APPLE80211_UNIT_DBM		= 0,		// dBm
	APPLE80211_UNIT_MW		= 1,		// milliwatts
	APPLE80211_UNIT_PERCENT	= 2,		// value expressed as a percentage
};

enum apple80211_power_state
{
	APPLE80211_POWER_OFF	= 0,
	APPLE80211_POWER_ON		= 1,
};

enum apple80211_locale
{
	APPLE80211_LOCALE_UNKNOWN	= 0,
	APPLE80211_LOCALE_USA		= 1,
	APPLE80211_LOCALE_EUROPE	= 2,
	APPLE80211_LOCALE_ISRAEL	= 3,
	APPLE80211_LOCALE_THAILAND	= 4,
	APPLE80211_LOCALE_JORDAN	= 5,
	APPLE80211_LOCALE_JAPAN		= 6,
	APPLE80211_LOCALE_CHINA		= 7,
	APPLE80211_LOCALE_WORLD		= 8,
};

enum apple80211_scan_type
{
	APPLE80211_SCAN_TYPE_NONE		= 0,
	APPLE80211_SCAN_TYPE_ACTIVE		= 1,
	APPLE80211_SCAN_TYPE_PASSIVE	= 2,
	APPLE80211_SCAN_TYPE_FAST		= 3,	// Ok to return cached scan results
	APPLE80211_SCAN_TYPE_BACKGROUND = 4,	// Initiate background scanning
};

enum apple80211_int_mit {
	APPLE80211_INT_MIT_OFF	= 0,
	APPLE80211_INT_MIT_AUTO = 1,
};

enum apple80211_channel_flag
{
	APPLE80211_C_FLAG_NONE	= 0x0,	// no flags
	APPLE80211_C_FLAG_10MHZ	= 0x1,	// 10 MHz wide
	APPLE80211_C_FLAG_20MHZ = 0x2,	// 20 MHz wide
	APPLE80211_C_FLAG_40MHZ = 0x3,	// 40 MHz wide
	APPLE80211_C_FLAG_2GHZ	= 0x8,	// 2.4 GHz
	APPLE80211_C_FLAG_5GHZ	= 0x10,	// 5 GHz
};

enum apple80211_rate_flag
{
	APPLE80211_RATE_FLAG_NONE	= 0x0,	// no flags
	APPLE80211_RATE_FLAG_BASIC	= 0x1,	// basic rate
};

enum apple80211_short_slot_mode
{
	APPLE80211_SHORT_SLOT_MODE_AUTO		= 1,	// Default behavior
	APPLE80211_SHORT_SLOT_MODE_LONG		= 2,	// long - short slot timing mode
	APPLE80211_SHORT_SLOT_MODE_SHORT	= 3,	// short - short slot timing mode
};

enum apple80211_powersave_mode
{
	APPLE80211_POWERSAVE_MODE_DISABLED	= 0,
	APPLE80211_POWERSAVE_MODE_80211		= 1,
	APPLE80211_POWERSAVE_MODE_VENDOR	= 2,	//	Vendor specific mode, there should be
};												//  more general apple modes in the future.
												//  Vendor modes also likely require more info.
#define APPLE80211_RSC_LEN				 8
#define APPLE80211_KEY_BUFF_LEN			32

#define	APPLE80211_KEY_FLAG_UNICAST		0x1
#define APPLE80211_KEY_FLAG_MULTICAST	0x2
#define APPLE80211_KEY_FLAG_TX			0x4
#define APPLE80211_KEY_FLAG_RX			0x8

struct apple80211_key
{
	u_int32_t			version;
	u_int32_t			key_len;
	u_int32_t			key_cipher_type;					// apple80211_cipher_type
	u_int16_t			key_flags;
	u_int16_t			key_index;
	u_int8_t			key[ APPLE80211_KEY_BUFF_LEN ];
	u_int32_t			key_rsc_len;
	u_int8_t			key_rsc[ APPLE80211_RSC_LEN ];	// receive sequence counter
	struct ether_addr	key_ea;							// key applies to this bssid
};

// Changing this affects any structure that contains a channel
struct apple80211_channel
{
	u_int32_t	version;
	u_int32_t	channel;	//	channel number
	u_int32_t	flags;		//	apple80211_channel_flag vector
};

struct apple80211_rate
{
	u_int32_t	version;
	u_int32_t	rate;	// rate mbps
	u_int32_t	flags;	// apple80211_rate_flag vector
};

// Probe response capability flags, IEEE 7.3.1.4
#define APPLE80211_CAPINFO_ESS				0x0001
#define APPLE80211_CAPINFO_IBSS				0x0002
#define APPLE80211_CAPINFO_CF_POLLABLE		0x0004
#define APPLE80211_CAPINFO_CF_POLLREQ		0x0008
#define APPLE80211_CAPINFO_PRIVACY			0x0010
#define APPLE80211_CAPINFO_SHORT_PREAMBLE	0x0020
#define APPLE80211_CAPINFO_PBCC				0x0040
#define APPLE80211_CAPINFO_AGILITY			0x0080
// 0x0100, 0x0200 reserved
#define APPLE80211_CAPINFO_SHORT_SLOT_TIME	0x0400
// 0x0800, 0x1000 reserved
#define APPLE80211_CAPINFO_DSSS_OFDM		0X2000
// 0x4000, 0x8000 reserved

// Reason codes IEEE 7.3.1.7
#define APPLE80211_REASON_UNSPECIFIED		1
#define APPLE80211_REASON_PREV_AUTH_EXPIRED	2
#define APPLE80211_REASON_AUTH_LEAVING		3
#define APPLE80211_REASON_INACTIVE			4
#define APPLE80211_REASON_AP_OVERLOAD		5
#define APPLE80211_REASON_NOT_AUTHED		6
#define APPLE80211_REASON_NOT_ASSOCED		7
#define APPLE80211_REASON_ASSOC_LEAVING		8
#define	APPLE80211_REASON_ASSOC_NOT_AUTHED	9

#define APPLE80211_REASON_INVALID_IE		13
#define APPLE80211_REASON_MIC_FAILURE		14
#define APPLE80211_REASON_4_WAY_TIMEOUT		15
#define APPLE80211_REASON_GROUP_KEY_TIMEOUT	16
#define APPLE80211_REASON_DIFF_IE			17
#define APPLE80211_REASON_INVALID_GROUP_KEY 18
#define APPLE80211_REASON_INVALID_PAIR_KEY	19
#define APPLE80211_REASON_INVALID_AKMP		20
#define APPLE80211_REASON_UNSUPP_RSN_VER	21
#define APPLE80211_REASON_INVALID_RSN_CAPS	22
#define APPLE80211_REASON_8021X_AUTH_FAILED 23

struct apple80211_scan_result
{
	u_int32_t					version;
	struct apple80211_channel	asr_channel;
	int16_t						asr_noise;
	int16_t						asr_rssi;
	u_int16_t					asr_beacon_int;
	u_int16_t					asr_cap;		// capabilities
	u_int8_t					asr_bssid[ APPLE80211_ADDR_LEN ];
	u_int8_t					asr_nrates;
	u_int32_t					asr_rates[ APPLE80211_MAX_RATES ];
	u_int8_t					asr_ssid_len;
	u_int8_t					asr_ssid[ APPLE80211_MAX_SSID_LEN ];
	u_int32_t					asr_age;	// (ms) non-zero for cached scan result
	u_int16_t					asr_ie_len;
	void					   *asr_ie_data;
};

struct apple80211_network_data
{
	u_int32_t					version;
	u_int16_t					nd_mode;			// apple80211_apmode
	u_int16_t					nd_auth_lower;		// apple80211_authtype_lower
	u_int16_t					nd_auth_upper;		// apple80211_authtype_upper
	struct apple80211_channel	nd_channel;
	u_int32_t					nd_ssid_len;
	u_int8_t					nd_ssid[ APPLE80211_MAX_SSID_LEN ];
	struct apple80211_key		nd_key;
};

// As hostap support improves, this will grow
struct apple80211_station
{
	u_int32_t			version;
	struct ether_addr	sta_mac;
};

enum apple80211_card_capability
{
	APPLE80211_CAP_WEP			= 1,	// CAPABILITY: WEP available
	APPLE80211_CAP_TKIP			= 2,	// CAPABILITY: TKIP available
	APPLE80211_CAP_AES			= 3,	// CAPABILITY: AES OCB avail
	APPLE80211_CAP_AES_CCM		= 4,	// CAPABILITY: AES CCM avail
	APPLE80211_CAP_CKIP			= 5,	// CAPABILITY: CKIP available
	APPLE80211_CAP_IBSS			= 6,	// CAPABILITY: IBSS available
	APPLE80211_CAP_PMGT			= 7,	// CAPABILITY: Power mgmt
	APPLE80211_CAP_HOSTAP		= 8,	// CAPABILITY: HOSTAP avail
	APPLE80211_CAP_TXPMGT		= 9,	// CAPABILITY: tx power mgmt
	APPLE80211_CAP_SHSLOT		= 10,	// CAPABILITY: short slottime
	APPLE80211_CAP_SHPREAMBLE	= 11,	// CAPABILITY: short preamble
	APPLE80211_CAP_MONITOR		= 12,	// CAPABILITY: monitor mode
	APPLE80211_CAP_TKIPMIC		= 13,	// CAPABILITY: TKIP MIC avail
	APPLE80211_CAP_WPA1			= 14,	// CAPABILITY: WPA1 avail
	APPLE80211_CAP_WPA2			= 15,	// CAPABILITY: WPA2 avail
	APPLE80211_CAP_WPA			= 16,	// CAPABILITY: WPA1+WPA2 avail
	APPLE80211_CAP_BURST		= 17,	// CAPABILITY: frame bursting
	APPLE80211_CAP_WME			= 18,	// CAPABILITY: WME avail
};
#define APPLE80211_CAP_MAX	18

// Kernel messages
#define APPLE80211_M_POWER_CHANGED		1
#define APPLE80211_M_SSID_CHANGED		2
#define APPLE80211_M_BSSID_CHANGED		3
#define APPLE80211_M_LINK_CHANGED		4
#define APPLE80211_M_MIC_ERROR_UCAST	5
#define APPLE80211_M_MIC_ERROR_MCAST	6
#define APPLE80211_M_INT_MIT_CHANGED	7
#define APPLE80211_M_MODE_CHANGED		8
#define APPLE80211_M_ASSOC_DONE			9
#define APPLE80211_M_SCAN_DONE			10

#define APPLE80211_M_MAX				10

struct apple80211_status_msg
{
	u_int8_t stat_msgs[ APPLE80211_M_MAX ];
};

// Userland messages
#define APPLE80211_M_RSN_AUTH_SUCCESS			254
#define APPLE80211_M_RSN_AUTH_SUCCESS_TEMPLATE	"com.apple.rsn.%s.auth.success"	// string is interface name

#define APPLE80211_M_RSN_AUTH_TIMEOUT			255
#define APPLE80211_M_RSN_AUTH_TIMEOUT_TEMPLATE	"com.apple.rsn.%s.auth.timeout"	// string is interface name

#define APPLE80211_M_RSN_MSG_MAX				2

#endif // _APPLE80211_VAR_H_