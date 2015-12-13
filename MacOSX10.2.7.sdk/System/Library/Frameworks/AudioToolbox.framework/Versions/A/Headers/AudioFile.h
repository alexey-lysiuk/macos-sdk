/*
     File:       AudioToolbox/AudioFile.h

     Contains:   API for manipulating Audio Files.

     Version:    Technology: Mac OS X
                 Release:    Mac OS X

     Copyright:  (c) 1985-2001 by Apple Computer, Inc., all rights reserved.

     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:

                        http://developer.apple.com/bugreporter/

*/
#if !defined(__AudioFile_h__)
#define __AudioFile_h__

//=============================================================================
//	Includes
//=============================================================================

#include <CoreAudio/CoreAudio.h>
#include <CoreServices/CoreServices.h>

#if defined(__cplusplus)
extern "C"
{
#endif

// File Types: types used when specifying the type of file to create and returned from get property (file format)
enum {
        kAudioFileAIFFType				= 'AIFF',
        kAudioFileAIFCType				= 'AIFC',
        kAudioFileWAVEType				= 'WAVE',
        kAudioFileSoundDesigner2Type	= 'Sd2f'
};

// Error Codes: AudioFile error codes
enum {
        kAudioFileUnspecifiedError						= 'wht?',
        kAudioFileUnsupportedFileTypeError 				= 'typ?',
        kAudioFileUnsupportedDataFormatError 			= 'fmt?',
        kAudioFileUnsupportedPropertyError 				= 'pty?',
        kAudioFileBadPropertySizeError 					= '!siz',
        kAudioFilePermissionsError	 					= 'prm?',
        kAudioFileNotOptimizedError						= 'optm',
        kAudioFileFormatNameUnavailableError			= 'nme?',
        // file format specific error codes
        kAudioFileInvalidChunkError						= 'chk?',	// applies to AIFF, WAVE chunks
        kAudioFileDoesNotAllow64BitDataSizeError		= 'off?'	// applies to AIFF, WAVE files
};

//=============================================================================
//	Types specific to the Audio File API
//=============================================================================

typedef	struct OpaqueAudioFileID	*AudioFileID;
typedef UInt32			AudioFilePropertyID;

//=============================================================================
//	Routines
//=============================================================================
                        
/*----------------------------------------------------------------------------------
    AudioFileCreate - creates a new audio file located in the parent directory 
                      provided. Upon success, an AudioFileID is returned which can
                      be used for subsequent calls to the AudioFile APIs.
                      
    inParentRef 	- an FSRef to the directory where  the new file should be created.
    inFileName 		- a CFStringRef containing the name of the file to be created.
    inFileType 		- a UInt32 indicating the type of audio file to create. Constants are
                      provided above in the header file.
    inFormat 		- an AudioStreamBasicDescription describing the data format that will be
                      added to the audio file.
    inFlags 		- relevent flags for creating/opening the file. Currently zero.
    outNewFileRef 	- on success, the FSRef of the newly created file.
    outAudioFile  	- upon success, an AudioFileID that can be used for subsequent AudioFile calls.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileCreate (	const FSRef							*inParentRef, 
                    CFStringRef							inFileName,
                    UInt32								inFileType,
                    const AudioStreamBasicDescription	*inFormat,
                    UInt32								inFlags,
                    FSRef								*outNewFileRef,
                    AudioFileID							*outAudioFile);

/*----------------------------------------------------------------------------------
    AudioFileInitialize - Use AudioFileInitialize to wipe clean an existing audio file
                          and prepare it to be populated with new data.
    
    inFileRef 		- the FSRef of an existing audio file.
    inFileType 		- a UInt32 indicating the type of audio file to initialize the file to. 
                      Constants are provided above in the header file.
    inFormat 		- an AudioStreamBasicDescription describing the data format that will be
                      added to the audio file.
    inFlags 		- relevent flags for creating/opening the file. Currently zero.
    outAudioFile	- upon success, an AudioFileID that can be used for subsequent
                      AudioFile calls.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileInitialize (	const FSRef							*inFileRef,
                        UInt32								inFileType,
                        const AudioStreamBasicDescription	*inFormat,
                        UInt32								inFlags,
                        AudioFileID							*outAudioFile);

/*----------------------------------------------------------------------------------
    AudioFileOpen - Open an existing audio file.
    
    inFileRef 		- the FSRef of an existing audio file.
    inPermissions 	- use the permission constants used by FSOpenFork().
    inFlags 		- relevent flags for creating/opening the file. Currently zero.
    outAudioFile	- upon success, an AudioFileID that can be used for subsequent AudioFile calls.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileOpen (	const FSRef		*inFileRef, 
                SInt8  			inPermissions, 
                UInt32			inFlags,
                AudioFileID		*outAudioFile);

/*----------------------------------------------------------------------------------
    AudioFileClose - Close an existing audio file.
//----------------------------------------------------------------------------------*/
extern OSStatus
AudioFileClose	(AudioFileID		inAudioFile);

/*----------------------------------------------------------------------------------
    AudioFileOptimize - Optimize the file so additional audio data can be appended to 
                        the existing data. Generally, this will place the audio data at 
                        the end of the file so additional writes can be placed to the 
                        file end. This can be a potentially expensive and timely operation 
                        and should not be used during time critical operations. There is 
                        a kAudioFilePropertyIsOptimized property for checking on the optimized state 
                        of the file.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileOptimize (AudioFileID  	inAudioFile);

/*----------------------------------------------------------------------------------
    AudioFileReadBytes - Read bytes of audio data from the audio file. 
     
    inUseCache 		- true if it is desired to cache the data upon read, else false
    inStartingByte	- the byte offset of the audio data desired to be returned
    ioNumBytes 		- on input, the number of bytes to read, on output, the number of
                      bytes actually read.
    outBuffer 		- outBuffer should be a void * to user allocated memory of size: 
                      number of bytes requested.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileReadBytes (	AudioFileID  	inAudioFile,
                        Boolean			inUseCache,
                        SInt64			inStartingByte, 
                        UInt32			*ioNumBytes, 
                        void			*outBuffer);

/*----------------------------------------------------------------------------------
    AudioFileWriteBytes - Read bytes of audio data from the audio file. 
     
    inUseCache 		- true if it is desired to cache the data upon read, else false
    inStartingByte 	- the byte offset where the audio data should be written
    ioNumBytes 		- on input, the number of bytes to write, on output, the number of
                      bytes actually written.
    inBuffer 		- inBuffer should be a void * containing the bytes to be written
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileWriteBytes (	AudioFileID  	inAudioFile,  
                        Boolean			inUseCache,
                        SInt64			inStartingByte, 
                        UInt32			*ioNumBytes, 
                        void			*inBuffer);

/*----------------------------------------------------------------------------------
    AudioFileReadPackets - Read packets of audio data from the audio file. For all 
                           uncompressed formats, packet = frame.

    inUseCache 				- true if it is desired to cache the data upon read, else false
    outNumBytes 			- on output, the number of bytes actually returned
    outPacketDescriptions 	- on output, an array of packet descriptions describing
                              the packets being returned. NULL may be passed for this
                              parameter. Nothing will be returned for linear pcm data.   
    inStartingPacket 		- the packet index of the first packet desired to be returned
    ioNumPackets 			- on input, the number of packets to read, on output, the number of
                              packets actually read.
    outBuffer 				- outBuffer should be a void * to user allocated memory of size: 
                              number of bytes requested.
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileReadPackets (	AudioFileID  					inAudioFile, 
                        Boolean							inUseCache,
                        UInt32							*outNumBytes,
                        AudioStreamPacketDescription	*outPacketDescriptions,
                        SInt64							inStartingPacket, 
                        UInt32  						*ioNumPackets, 
                        void							*outBuffer);

/*----------------------------------------------------------------------------------
    AudioFileWritePackets - Write packets of audio data to the audio file. For all 
                            uncompressed formats, packet = frame
							
    inUseCache 				- true if it is desired to cache the data upon read, else false
    inNumBytes 				- the number of bytes being provided for write
    inPacketDescriptions 	- an array of packet descriptions describing the packets being 
                              provided. Not all formats require packet descriptions to be 
                              provided. NULL may be passed if no descriptions are required.
    inStartingPacket 		- the packet index of where the first packet provided should be placed
    ioNumPackets 			- on input, the number of packets to write, on output, the number of
                              packets actually written.
    inBuffer 				- a void * to user allocated memory containing the packets to write
//----------------------------------------------------------------------------------*/
extern OSStatus	
AudioFileWritePackets (	AudioFileID  					inAudioFile,  
                        Boolean							inUseCache,
                        UInt32							inNumBytes,
                        AudioStreamPacketDescription	*inPacketDescriptions,
                        SInt64							inStartingPacket, 
                        UInt32  						*ioNumPackets, 
                        void							*inBuffer);

//=============================================================================
//	Audio File Properties
//=============================================================================

enum
{
	kAudioFilePropertyFileFormat			=	'ffmt',
		// A UInt32 that identifies the format of the file
	kAudioFilePropertyDataFormat			=	'dfmt',
		// An AudioStreamBasicDescription describing the format of the audio data
	kAudioFilePropertyDataFormatName		=	'fnme',
		// An c-string representing a plain language name of the format.
        // Not all audio file types have a place to store this string.
        // You must provide enough memory to write the string into when getting the property.
	kAudioFilePropertyIsOptimized			=	'optm',
		// A UInt32 indicating whether an Audio File has been optimized.
        // Optimized meaning it is ready to start having sound data written
        // to it. A value of 0 indicates the file needs to be optimized.
        // A value of 1 indicates the file is currently optimized
	kAudioFilePropertyMagicCookieData		=	'mgic',
		// A void * pointing to memory set up by the caller.
	kAudioFilePropertyAudioDataByteCount	=	'bcnt',
		// a UInt64 that indicates the number of bytes of audio data contained in the file
	kAudioFilePropertyAudioDataPacketCount	=	'pcnt',
		// a UInt64 that indicates the number of packets of audio data contained in the file
	kAudioFilePropertyMaximumPacketSize		=	'psze'
		// a UInt32 that indicates the maximum size of a packet for the data contained in the file
};

//-----------------------------------------------------------------------------
//	AudioFileGetPropertyInfo
//-----------------------------------------------------------------------------
extern OSStatus
AudioFileGetPropertyInfo	(	AudioFileID				inAudioFile,
                                AudioFilePropertyID		inPropertyID,
                                UInt32					*outDataSize,
                                UInt32					*isWritable);
                                
//-----------------------------------------------------------------------------
//	AudioFileGetProperty
//-----------------------------------------------------------------------------
extern OSStatus
AudioFileGetProperty(	AudioFileID				inAudioFile,
                        AudioFilePropertyID		inPropertyID,
                        UInt32					*ioDataSize,
                        void					*outPropertyData);
                        
//-----------------------------------------------------------------------------
//	AudioFileSetProperty
//-----------------------------------------------------------------------------
extern OSStatus
AudioFileSetProperty(	AudioFileID				inAudioFile,
                        AudioFilePropertyID		inPropertyID,
                        UInt32					inDataSize,
                        const void				*inPropertyData);


#if defined(__cplusplus)
}
#endif

#endif
