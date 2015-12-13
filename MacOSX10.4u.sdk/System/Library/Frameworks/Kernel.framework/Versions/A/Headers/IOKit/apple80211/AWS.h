/*
 *  AWS.h
 *  Family
 *
 *  Created by Pete on 11/10/05.
 *  Copyright 2005 Apple Compute, Inc. All rights reserved.
 *
 */

// Definitions for the Apple Wireless Statistics Protocol

#ifndef _AWS_H_
#define _AWS_H_

#include <net/ethernet.h>
#include <libkern/OSTypes.h>

#define AWS_MULTICAST_ADDR_BYTES	0x01, 0x03, 0x93, 0xDF, 0x0B, 0x92
#define AWS_SNAP_HEADER_BYTES		0xAA, 0xAA, 0x03, 0x01, 0x03, 0x93, 0xDF, 0x0B

#define AWS_REQUEST_RSSI			0x72737369	// 'rssi'
#define AWS_REQUEST_NOISE			0x6e6f6973	// 'nois'
#define AWS_REQUEST_TX_FRAME_COUNT	0x6e6d7478	// 'nmtx'
#define AWS_REQUEST_RX_FRAME_COUNT	0x6e6d7278	// 'nmrx'
#define AWS_REQUEST_TX_ERR_COUNT	0x65727478	// 'ertx'
#define AWS_REQUEST_RX_ERR_COUNT	0x65727278	// 'errx'
#define AWS_REQUEST_TX_RATE			0x72617465	// 'rate'

typedef UInt8	AWS_Version;
typedef UInt8	AWS_PacketType;
typedef UInt16	AWS_PacketID;
typedef UInt32	AWS_ID;
typedef UInt32	AWS_Length;

#define AWS_VERSION	0

#define AWS_TYPE_REQUEST	0
#define AWS_TYPE_RESPONSE	1

struct AWSResponse
{
	AWS_ID	id;
	UInt32	value;
}__attribute__((packed));

struct AWSRequest
{
	AWS_ID	id;
}__attribute__((packed));

struct AWSHeader
{
	AWS_Version		version;
	AWS_PacketType	type;
	AWS_PacketID	packetID;
}__attribute__((packed));

struct AWSRequestPacket
{
	struct AWSHeader requestHeader;
	struct AWSRequest request[1];
}__attribute__((packed));

struct AWSResponsePacket
{
	struct AWSHeader responseHeader;
	struct AWSResponse response[1];
}__attribute__((packed));

// Snap header, plus a packet with one request
#define AWS_MIN_PACKET_LEN	8 + sizeof( struct AWSRequestPacket )

#endif /* _AWS_H_ */
