//
//  GCMicroGamepadSnapshot.h
//  GameController
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <GameController/GCMicroGamepad.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A GCMicroGamepadSnapshot snapshot is a concrete GCMicroGamepad implementation. It can be used directly in an
 application to implement controller input replays. It is also returned as the result of polling
 a controller.
 
 The current snapshotData is readily available to access as NSData. A developer can serialize this to any
 destination necessary using the NSData API.
 
 The data contains some version of a GCMicroGamepadSnapShotData structure.
 
 @see -[GCMicroGamepad saveSnapshot]
 */
API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.11, 10.15), ios(9.0, 13.0), tvos(9.0, 13.0))
@interface GCMicroGamepadSnapshot : GCMicroGamepad

@property (atomic, copy) NSData *snapshotData;

- (instancetype)initWithSnapshotData:(NSData *)data;
- (instancetype)initWithController:(GCController *)controller snapshotData:(NSData *)data;

@end


typedef NS_ENUM(NSInteger, GCMicroGamepadSnapshotDataVersion) {
    GCMicroGamepadSnapshotDataVersion1 = 0x0100
} API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.15, 10.15), ios(13.0, 13.0), tvos(13.0, 13.0));

extern const GCMicroGamepadSnapshotDataVersion GCCurrentMicroGamepadSnapshotDataVersion API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.15, 10.15), ios(13.0, 13.0), tvos(13.0, 13.0));

#pragma pack(push, 1)
typedef struct {
    
#pragma mark - GCMicroGamepadSnapshotDataVersion1+
    uint16_t version;
    uint16_t size;
    
    // Standard gamepad data
    // Axes in the range [-1.0, 1.0]
    float dpadX;
    float dpadY;
    
    // Buttons in the range [0.0, 1.0]
    float buttonA;
    float buttonX;
    
} GCMicroGamepadSnapshotData API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.15, 10.15), ios(13.0, 13.0), tvos(13.0, 13.0));
#pragma pack(pop)

/**Fills out a snapshot from any compatible NSData source
 
 @return NO if data is nil, snapshotData is nil or the contents of data does not contain a compatible snapshot. YES for all other cases.
 */
BOOL GCMicroGamepadSnapshotDataFromNSData(GCMicroGamepadSnapshotData * _Nullable snapshotData, NSData * _Nullable data) API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.15, 10.15), ios(13.0, 13.0), tvos(13.0, 13.0));

/**Creates an NSData object from a snapshot.
 If the version and size is not set in the snapshot the data will automatically have version GCCurrentMicroGamepadSnapshotDataVersion and sizeof(GCMicroGamepadSnapshotData) set as the values implicitly.
 
 @return nil if the snapshot is NULL, otherwise an NSData instance compatible with GCGamepadSnapshot.snapshotData
 */
NSData * _Nullable NSDataFromGCMicroGamepadSnapshotData(GCMicroGamepadSnapshotData * _Nullable snapshotData) API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.15, 10.15), ios(13.0, 13.0), tvos(13.0, 13.0));



#pragma mark - Deprecated Versioning System

#pragma pack(push, 1)
typedef struct {
    // Standard information
    uint16_t version; //0x0100
    uint16_t size;    //sizeof(GCMicroGamepadSnapShotDataV100) or larger
    
    // Standard gamepad data
    // Axes in the range [-1.0, 1.0]
    float dpadX;
    float dpadY;
    
    // Buttons in the range [0.0, 1.0]
    float buttonA;
    float buttonX;
    
} GCMicroGamepadSnapShotDataV100 API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.11, 10.15), ios(9.0, 13.0), tvos(9.0, 13.0));
#pragma pack(pop)

/**Fills out a v100 snapshot from any compatible NSData source
 
 @return NO if data is nil, snapshotData is nil or the contents of data does not contain a compatible snapshot. YES for all other cases.
 */
BOOL GCMicroGamepadSnapShotDataV100FromNSData(GCMicroGamepadSnapShotDataV100 * _Nullable snapshotData, NSData * _Nullable data) API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.11, 10.15), ios(9.0, 13.0), tvos(9.0, 13.0));

/**Creates an NSData object from a v100 snapshot.
 If the version and size is not set in the snapshot the data will automatically have version 0x100 and sizeof(GCMicroGamepadSnapShotDataV100) set as the values implicitly.
 
 @return nil if the snapshot is NULL, otherwise an NSData instance compatible with GCGamepadSnapshot.snapshotData
 */
NSData * _Nullable NSDataFromGCMicroGamepadSnapShotDataV100(GCMicroGamepadSnapShotDataV100 * _Nullable snapshotData) API_DEPRECATED("Use the -[GCController controllerWithMicroGamepad] method instead", macos(10.11, 10.15), ios(9.0, 13.0), tvos(9.0, 13.0));

NS_ASSUME_NONNULL_END
