/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
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

#ifndef _IOKIT_IOAUDIOPANCONTROL_H
#define _IOKIT_IOAUDIOPANCONTROL_H

#include <IOKit/audio/IOAudioControl.h>

class OSArray;

/*!
 * @class IOAudioPanControl
 * @abstract
 * @discussion
 */

class IOAudioPanControl : public IOAudioControl
{
    OSDeclareDefaultStructors(IOAudioPanControl)

protected:
    SInt32	maxLeftValue;
    SInt32	maxRightValue;
	UInt32	leftChannelID;
	UInt32	rightChannelID;

protected:
    struct ExpansionData { };
    
    ExpansionData *reserved;

private:
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 0);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 1);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 2);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 3);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 4);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 5);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 6);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 7);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 8);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 9);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 10);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 11);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 12);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 13);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 14);
    OSMetaClassDeclareReservedUnused(IOAudioPanControl, 15);

public:
    /*!
     * @function create
     * @abstract Allocates a new stereo panning control with the given attributes.
	 * 0 should represent no panning, and a negative number full left pan with a positive number being full right pan.
	 * For example, maxLeftValue = -16, maxRightValue = 16 for a control that has 33 settings from full right to full left.
     * @param initialValue The initial value of the control
     * @param maxLeftValue The value of the control that represents full left panning, should be negative
     * @param maxRightValue The value of the control that represents full right panning, should be positive
     * @param leftChannelID The ID of the left channel that the control acts on.  Common IDs are located in IOAudioTypes.h.
     * @param rightChannelID The ID of the right channel that the control acts on.  Common IDs are located in IOAudioTypes.h.
     * @param cntrlID An optional ID for the control that can be used to uniquely identify controls.
     * @result Returns a newly allocted and initialized stereo panning IOAudioControl
     */
    static IOAudioPanControl *create(SInt32 initialValue,
                                       SInt32 maxLeftValue,
                                       SInt32 maxRightValue,
                                       UInt32 leftChannelID,
                                       UInt32 rightChannelID,
                                       UInt32 cntrlID = 0,
                                       UInt32 subType = 0,
                                       UInt32 usage = 0);
                                       
    static IOAudioPanControl *createStereoPanControl(SInt32 initialValue,
                                                    SInt32 maxLeftValue,
                                                    SInt32 maxRightValue,
													UInt32 leftChannelID,
													UInt32 rightChannelID,
                                                    UInt32 cntrlID = 0,
                                                    UInt32 usage = 0);

    /*!
     * @function init
     * @abstract Initializes a newly allocated IOAudioPanControl with the given attributes
     * @param initialValue The initial value of the control
     * @param minValue The lowest possible value the control may have 
     * @param maxValue The highest possible value the control may have
     * @param minDB A fixed point representation of the db value matching minValue 
     * @param maxDB A fixed point representation of the db value matching maxValue 
     * @param channelID The ID of the channel(s) that the control acts on.  Common IDs are located in IOAudioTypes.h.
     * @param channelName An optional name for the channel.  Common names are located in IOAudioTypes.h.
     * @param cntrlID An optional ID for the control that can be used to uniquely identify controls.
     * @param properties Standard property list passed to the init() function of any new IOService.  This dictionary
     *  gets stored in the registry entry for this service.
     * @result Returns true on success
     */
    virtual bool init(SInt32 initialValue,
                      SInt32 maxLeftValue,
                      SInt32 maxRightValue,
					  UInt32 leftChannelID,
					  UInt32 rightChannelID,
                      UInt32 cntrlID = 0,
                      UInt32 subType = 0,
                      UInt32 usage = 0,
                      OSDictionary *properties = 0);
                      
    virtual void free();

    /*!
     * @function setMaxLeftValue
     * @abstract Sets the value the control representing maxiumum left panning
     * @param maxLeftValue The value for the control when panning to full left
     */
    virtual void setMaxLeftValue(SInt32 maxLeftValue);

    virtual SInt32 getMaxLeftValue();
     
    /*!
     * @function setMaxRightValue
     * @abstract Sets the value the control representing maxiumum right panning
     * @param maxValue The value for the control when panning to full right
     */ 
    virtual void setMaxRightValue(SInt32 maxRightValue);

    virtual SInt32 getMaxRightValue();

	virtual void setPanChannelIDs(UInt32 newLeftChannelID, UInt32 newRightChannelID);

    /*!
     * @function getChannelID Returns the channel ID for the control
     */
    virtual void getPanChannelIDs(UInt32 *leftChannelID, UInt32 *rightChannelID);

    virtual IOReturn validateValue(OSObject *newValue);
};

#endif /* _IOKIT_IOAUDIOPANCONTROL_H */
