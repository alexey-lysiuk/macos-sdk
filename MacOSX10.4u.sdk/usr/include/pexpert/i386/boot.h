/*
 * Copyright (c) 2000 Apple Computer, Inc. All rights reserved.
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
#ifndef _PEXPERT_I386_BOOT_H
#define _PEXPERT_I386_BOOT_H

/*
 * What the booter leaves behind for the kernel.
 */

/*
 * Types of boot driver that may be loaded by the booter.
 */
enum {
    kBootDriverTypeInvalid = 0,
    kBootDriverTypeKEXT    = 1,
    kBootDriverTypeMKEXT   = 2
};

/*
 * Video information.
 */
struct boot_video {
    unsigned long v_baseAddr;	// Base address of video memory
    unsigned long v_display;    // Display Code
    unsigned long v_rowBytes;   // Number of bytes per pixel row
    unsigned long v_width;      // Width
    unsigned long v_height;     // Height
    unsigned long v_depth;      // Pixel Depth
};

typedef struct boot_video  boot_video;

/* Values for v_display */

#define VGA_TEXT_MODE         0
#define GRAPHICS_MODE     1
#define FB_TEXT_MODE          2


enum {
    kEfiReservedMemoryType	= 0,
    kEfiLoaderCode		= 1,
    kEfiLoaderData		= 2,
    kEfiBootServicesCode	= 3,
    kEfiBootServicesData	= 4,
    kEfiRuntimeServicesCode	= 5,
    kEfiRuntimeServicesData	= 6,
    kEfiConventionalMemory	= 7,
    kEfiUnusableMemory		= 8,
    kEfiACPIReclaimMemory	= 9,
    kEfiACPIMemoryNVS		= 10,
    kEfiMemoryMappedIO		= 11,
    kEfiMemoryMappedIOPortSpace = 12,
    kEfiPalCode			= 13,
    kEfiMaxMemoryType		= 14
};

/*
 * Memory range descriptor.
 */
typedef struct EfiMemoryRange {
    unsigned long Type;
    unsigned long pad;
    unsigned long long PhysicalStart;
    unsigned long long VirtualStart;
    unsigned long long NumberOfPages;
    unsigned long long Attribute;
} EfiMemoryRange;

#define BOOT_LINE_LENGTH        1024
#define BOOT_STRING_LEN         BOOT_LINE_LENGTH

/*
 * Video information.. 
 */

struct Boot_Video {
	unsigned long	v_baseAddr;	/* Base address of video memory */
	unsigned long	v_display;	/* Display Code (if Applicable */
	unsigned long	v_rowBytes;	/* Number of bytes per pixel row */
	unsigned long	v_width;	/* Width */
	unsigned long	v_height;	/* Height */
	unsigned long	v_depth;	/* Pixel Depth */
};

typedef struct Boot_Video	Boot_Video;


/* Boot argument structure - passed into Mach kernel at boot time.
 */
#define kBootArgsRevision		3
#define kBootArgsVersion		1

typedef struct boot_args {
  unsigned short	Revision;	/* Revision of boot_args structure */
  unsigned short	Version;	/* Version of boot_args structure */

    char		CommandLine[BOOT_LINE_LENGTH];	/* Passed in command line */

    void *         MemoryMap;
    unsigned long  MemoryMapSize;
    unsigned long  MemoryMapDescriptorSize;
    unsigned long  MemoryMapDescriptorVersion;

    Boot_Video	Video;		/* Video Information */

    void		*deviceTreeP;	/* Base of flattened device tree */
    unsigned long	deviceTreeLength;/* Length of flattened tree */

    unsigned long       kaddr;
    unsigned long       ksize;

    unsigned long	efiRuntimeServicesPageStart;
    unsigned long	efiRuntimeServicesPageCount;
    void	      * efiSystemTable;

    unsigned long	__reserved[8];

} boot_args;

#endif /* _PEXPERT_I386_BOOT_H */

