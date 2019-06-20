/*
    NSPersistentCloudKitContainer.h
    Core Data
    Copyright (c) 2018-2019, Apple Inc.
    All rights reserved.
*/



#import <CoreData/NSPersistentContainer.h>

NS_ASSUME_NONNULL_BEGIN

/*
 NSPersistentCloudKitContainer managed one or more persistent stores that are backed by a CloudKit private database.
 
 By default, NSPersistentContainer contains a single store description which, if not customized otherwise, is assigned
 to the first CloudKit container identifier in an application's entitlements.
 
 Instances of NSPersistentCloudKitContainerOptions can be used to customize this behavior or create additional instances of
 NSPersistentStoreDescription backed by different containers.
 
 As NSPersistentCloudKitContainer is a subclass of NSPersistentContainer, it can manage both CloudKit backed and non-cloud stores.
 */
@class CKRecord;
@class CKRecordID;
API_AVAILABLE(macosx(10.15),ios(13.0),tvos(13.0),watchos(6.0))
@interface NSPersistentCloudKitContainer : NSPersistentContainer

/**
 These methods provide access to the underlying CKRecord, or CKRecordID, backing a given NSManagedObjectID.
 */
- (nullable CKRecord *)recordForManagedObjectID:(NSManagedObjectID *)managedObjectID;
- (NSDictionary<NSManagedObjectID *, CKRecord *> *)recordsForManagedObjectIDs:(NSArray<NSManagedObjectID *> *)managedObjectIDs;
- (nullable CKRecordID *)recordIDForManagedObjectID:(NSManagedObjectID *)managedObjectID;
- (NSDictionary<NSManagedObjectID *, CKRecordID *> *)recordIDsForManagedObjectIDs:(NSArray<NSManagedObjectID *> *)managedObjectIDs;

@end

NS_ASSUME_NONNULL_END

