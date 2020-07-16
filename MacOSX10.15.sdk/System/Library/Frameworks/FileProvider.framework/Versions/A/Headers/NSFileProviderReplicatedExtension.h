//
//  NSFileProviderReplicatedExtension.h
//
//  Copyright © 2019-2020 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FileProvider/NSFileProviderDefines.h>
#import <FileProvider/NSFileProviderItem.h>
#import <FileProvider/NSFileProviderExtension.h>
#import <FileProvider/NSFileProviderEnumerating.h>
#import <FileProvider/NSFileProviderService.h>
#import <FileProvider/NSFileProviderActions.h>
#import <FileProvider/NSFileProviderRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class NSFileProviderDomain;

#pragma mark - Options

/**
 Options passed on item creation.
 */
typedef NS_OPTIONS(NSUInteger, NSFileProviderCreateItemOptions) {
    /**
     The imported item may already exists.

     This can happen because:

     1. The imported item was found on disk after the synchronisation state was
     lost, for example following the restoration of a backup, or the migration
     to a new device.

     2. Two directories are merged together. Each child resulting of the merge
     may be recreated with the mayAlreadyExist option. This allows the
     extension to recursively merge directories.

     The Extension should assess whether the item could actually be a disk
     representation of an already existing item.

     Since this can happens when the system has to reimport all the existing
     item from disk, it is advised that the assessment method avoids
     computational intensive tasks, such as checksumming the item.

     When all the items pending reimport have been processed, the system
     will call -[NSFileProviderExtension importDidFinishWithCompletionHandler:].
     */
    NSFileProviderCreateItemOptionsItemMayAlreadyExist = 1 << 0,
} FILEPROVIDER_API_AVAILABILITY_V3;

/**
 Options passed on item deletion.
 */
typedef NS_OPTIONS(NSUInteger, NSFileProviderDeleteItemOptions) {
    /**
     The deletion of the item is recursive.
     */
    NSFileProviderDeleteItemOptionsRecursive = 1 << 0
} FILEPROVIDER_API_AVAILABILITY_V3;

typedef NS_OPTIONS(NSUInteger, NSFileProviderModifyItemOptions) {
    /**
     We're moving the item to a location where it may refer to an item that already exists. This may happen
     when two directories are being merged together. When this happens some items may be merged to the
     same directory and we end up in a situation where the merged contains may also exist.

     This is similar to NSFileProviderCreateItemOptionsItemMayAlreadyExist
     */
    NSFileProviderModifyItemOptionsItemMayAlreadyExist = 1 << 0,
} FILEPROVIDER_API_AVAILABILITY_V3;

/**
 NSFileProviderItemFieldContents corresponds to the item's contents.

 Each subsequent field corresponds to a property on NSFileProviderItem that can
 change.
 */
typedef NS_OPTIONS(NSUInteger, NSFileProviderItemField) {
    NSFileProviderItemFieldContents = 1 << 0,
    NSFileProviderItemFieldFilename = 1 << 1,
    NSFileProviderItemFieldParentItemIdentifier = 1 << 2,
    NSFileProviderItemFieldLastUsedDate = 1 << 3,
    NSFileProviderItemFieldTagData = 1 << 4,
    NSFileProviderItemFieldFavoriteRank = 1 << 5,
    NSFileProviderItemFieldCreationDate = 1 << 6,
    NSFileProviderItemFieldContentModificationDate = 1 << 7,
    NSFileProviderItemFieldFlags = 1 << 8,
    NSFileProviderItemFieldExtendedAttributes = 1 << 9,
} FILEPROVIDER_API_AVAILABILITY_V3;

#pragma mark - Extension with FPFS support

FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderEnumerating <NSObject>

/**
 Create an enumerator for an item.

 When the user opens the browse tab of the UIDocumentsBrowserViewController and
 selects a file provider, this is called with
 NSFileProviderRootContainerItemIdentifier, and -[NSFileProviderEnumerator
 enumerateItemsForObserver:startingAtPage:] is immediately called to list the
 first items available under at the root level of the file provider.

 As the user navigates down into directories, new enumerators are created with
 this method, passing in the itemIdentifier of those directories.  Past
 enumerators are then invalidated.

 This method is also called with
 NSFileProviderWorkingSetContainerItemIdentifier, which is enumerated with
 -[NSFileProviderEnumerator enumerateChangesForObserver:fromSyncAnchor:].  That
 enumeration is special in that it isn't driven by the
 UIDocumentsBrowserViewController.  It happens in the background to sync the
 working set down to the device.

 This is also used to subscribe to live updates for a single document.  In that
 case, -[NSFileProviderEnumerator enumerateChangesToObserver:fromSyncAnchor:]
 will be called and the enumeration results shouldn't include items other than
 the very item that the enumeration was started on.

 If returning nil, you must set the error out parameter.
 */
- (nullable id<NSFileProviderEnumerator>)enumeratorForContainerItemIdentifier:(NSFileProviderItemIdentifier)containerItemIdentifier
                                                                      request:(nullable NSFileProviderRequest *)request
                                                                        error:(NSError **)error
    NS_SWIFT_NAME(enumerator(for:request:));

@end

/**
 FileProvider extension for which the system replicates the content on disk.
 */
FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderReplicatedExtension <NSObject, NSFileProviderEnumerating>

/**
 Create a new instance of the replicated provider for the specified domain.
 */
- (instancetype)initWithDomain:(NSFileProviderDomain *)domain;

/**
 Called before the instance is discarded.

 Several instances of a replicated provider can be hosted by the same process, either because
 the user has several active domains, or because an instance got discarded and a new one
 is created by the system. This method is called before an instance is discarded and should
 make sure that all references to the instance are released so that the instance can be
 deallocated.
 */
- (void)invalidate;

/**
 Fetch the metadata for the item with the provider identifier.
 */
- (NSProgress *)itemForIdentifier:(NSFileProviderItemIdentifier)identifier
                completionHandler:(void(^)(NSFileProviderItem _Nullable, NSError * _Nullable))completionHandler
    NS_SWIFT_NAME(item(for:completionHandler:));

/**
 Download the item for the given identifier and return it via the completion handler.

 The system learns of items through enumerations. Initially, this means that the
 system is aware that an item (with a specific version) exists on the device.

 When the user accesses the item, the system makes a request for the contents of
 the item. The provider can then fulfill the request by providing the item.

 The system takes ownership of the item and will move it out of the sandbox of
 the provider.

 The requestedVersion parameter specifies which version should be returned. A nil value
 means that the latest known version should be returned. Except for the error case, the
 version of the returned item is assumed to be identical to what was requested.
 */
- (NSProgress *)fetchContentsForItemWithIdentifier:(NSFileProviderItemIdentifier)itemIdentifier
                                           version:(nullable NSFileProviderItemVersion *)requestedVersion
                                           request:(nullable NSFileProviderRequest *)request
                                 completionHandler:(void(^)(NSURL * _Nullable fileContents, NSFileProviderItem _Nullable item, NSError * _Nullable error))completionHandler
    NS_SWIFT_NAME(fetchContents(for:version:request:completionHandler:));

/**
 Create a new item.

 The itemTemplate object describes the expected state of the newly created item,
 including its location provided by parentItemIdentifier and filename. The list
 of fields to conside in that object is defined by the fields parameter. Fields
 not listed should be considered as not being defined.

 If the item is a document, the contents should be fetched from provided
 URL. Otherwise url will be nil. If the item is a symbolic link, the target
 path is provided by the symlinkTargetPath of the itemTemplate.

 The system is setting the itemIdentifier of the itemTemplate to a unique value that
 is guaranteed to stay the same for a given item in case the creation is replayed
 after a crash. That itemIdentifier is not intended to be the identifier assigned
 to the item by the provider. In the completion block, the createdItem is expected
 to have its properties matching the values of the item properties with the exception
 of the itemIdentifier which should be the identifier assigned to that item by the
 provider. If the provider reuses an existing identifier, the item that used that
 identifier will be removed from disk, replaced by the createdItem. If the item is
 directory, the two directories will be merged and the items from the existing one
 will be modified with the NSFileProviderModifyItemOptionsItemMayAlreadyExist option set.

 If the provider is not able to apply all the fields at once, it should return a
 set of stillPendingFields in its completion handler. In that case, the system will
 attempt to modify the item later by calling modifyItem with those fields.

 If a field in the returned createdItem does not match the itemTemplate, and is
 not in the list of stillPendingFields, the value from the createdItem will be
 propagated to the disk. If the content of the item as described by createdItem
 does not match the content from url, the provider should set shouldFetchContent
 in the completion handler. The content from the provider will then be fetched
 and propagated to disk.

 In case the NSFileProviderCreateItemOptionsItemMayAlreadyExist option
 is passed, the content may be nil if the item is found by the system without any
 associated content. In that case, you should return a nil item if you are not
 able to match the created item with an existing item from the provider.

 In case of path collision with an already existing item, the provider
 can either fail using -[NSError (NSFileProviderError) fileProviderErrorForCollisionWithItem:]
 or resolve the collision by itself (e.g. by returning an item with a different name).
 If the error is returned, the system will try to resolve the collision by itself by bouncing
 away one of the items (renaming the item).

 If the imported item is refused by the extension, it should return nil for the
 createdItem without any error. In that case, the source item will be deleted
 from disk. If the extension does not wish to synchronise the item, while still
 keeping it on disk, it should still import it locally, but not sync it to its
 server, and return a valid createItem object.

 The progress returned by createItemBasedOnTemplate is expected to include the
 upload progress if any, even if the provider chose to call the completion handler
 before the upload finishes. For example, the provider might decide to call the
 completion handler as soon as the metadata have been stored in a local database.

 Upload errors (such as NSFileProviderErrorInsufficientQuota) should be handled
 with a subsequent update to the item, setting its uploadingError property.
 Upload errors should not prevent creating or importing a document, because they
 can be resolved at a later date (for example, when the user has quota again.)

 Other errors will be presented to the user, but are unexpected.  If you want to
 prevent creation in a given directory, then the directory item's capacities
 should exclude NSFileProviderItemCapabilitiesAllowsAddingSubItems.
 */
- (NSProgress *)createItemBasedOnTemplate:(NSFileProviderItem)itemTemplate
                                   fields:(NSFileProviderItemField)fields
                                 contents:(nullable NSURL *)url
                                  options:(NSFileProviderCreateItemOptions)options
                        completionHandler:(void (^)(NSFileProviderItem _Nullable createdItem,
                                                    NSFileProviderItemField stillPendingFields,
                                                    BOOL shouldFetchContent,
                                                    NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(createItem(basedOn:fields:contents:options:completionHandler:));

/**
 Informs the provider that an item or its metadata have changed. More than one
 property may have changed, e.g.  an item may have been renamed, moved and also
 changed contents, in which case changedFields might contain [.contents,
 .filename, .parentItemIdentifier, .contentModificationDate].

 If the provider is not able to apply all the fields at once, it should return a
 set of stillPendingFields in its completion handler. In that case, the system will
 attempt to modify the item later by calling modifyItem with those fields.

 If a field in the returned item does not match the itemTemplate, and is
 not in the list of stillPendingFields, the value from the item will be
 propagated to the disk. In case there is a content change and the content of
 the returned item as described by item does not match the content from url,
 the provider should set shouldFetchContent in the completion handler. The
 content from the provider will then be fetched and propagated to disk.

 If the item modification results from the parent directory being merged into another
 directory, the NSFileProviderModifyItemOptionsItemMayAlreadyExist flag will be passed
 to the call.

 The provider can chose to merge two existing items when receiving modifyItem. In that
 case, the item returned should carry the itemIdentifier of the item with which the
 item will be merged and well as the resulting state of the item. The system will then
 keep one of the items (the one whose itemIdentifier was returned) and remove
 the other one from disk. In case of directories, the content of the two directories
 is merged and sub-items will be modified with the
 NSFileProviderModifyItemOptionsItemMayAlreadyExist flag set.

 The progress returned by modifyItem is expected to include the upload progress if any,
 even if the provider chose to call the completion handler before the upload finishes.
 For example, the provider might decide to call the completion handler as soon as the
 metadata have been stored in a local database.
 */
- (NSProgress *)modifyItem:(NSFileProviderItem)item
               baseVersion:(NSFileProviderItemVersion *)version
             changedFields:(NSFileProviderItemField)changedFields
                  contents:(nullable NSURL *)newContents
                   options:(NSFileProviderModifyItemOptions)options
         completionHandler:(void(^)(NSFileProviderItem _Nullable item,
                                    NSFileProviderItemField stillPendingFields,
                                    BOOL shouldFetchContent,
                                    NSError * _Nullable error))completionHandler;

/**
 Delete an item forever.

 This is called when the user deletes an item that was already in the Trash and
 the item should no longer appear there after this call.  This call should
 remove the item from the working set.

 This call receives an optional baseVersion which represent the version of the
 item we are trying to delete.  The extension may fail with
 NSFileProviderErrorVersionOutOfDate if the item does not match the provided
 baseVersion.

 Unless the NSFileProviderDeleteItemOptionsRecursive options is passed, the
 deletion of a directory should be non-recursive and the call must fail with
 NSFileProviderErrorDirectoryNotEmpty if the directory contains some children.

 Delete is gated by the capabilities of the removed item with
 NSFileProviderItemCapabilitiesAllowsDeleting.
 */
- (NSProgress *)deleteItemWithIdentifier:(NSFileProviderItemIdentifier)identifier
                             baseVersion:(NSFileProviderItemVersion *)version
                                 options:(NSFileProviderDeleteItemOptions)options
                       completionHandler:(void (^)(NSError * _Nullable))completionHandler
    NS_SWIFT_NAME(deleteItem(with:baseVersion:options:completionHandler:));


#pragma mark - Optional selectors

@optional

/** Signal the end of import of on-disk items.

 This is called after an import of on-disk items has been triggered by either
 -[NSFileProviderManager reimportItemsBelowItemWithIdentifier:completionHandler:] or
 +[NSFileProviderManager importDomain:fromDirectoryAtURL:completionHandler:]. A
 reimport can also be started by the system independently from any request by the
 provider.

 During import, found items will be created via the
 -[NSFileProviderExtension createItemBasedOnTemplate:fields:contents:options:completionHandler:]
 call with the NSFileProviderCreateItemOptionsItemMayAlreadyExist flag set.
 At the end of an import the -[NSFileProviderExtension importDidFinishWithCompletionHandler:]
 is called.
 */
- (void)importDidFinishWithCompletionHandler:(void (^)(void))completionHandler;

/**
 Called by the system if the set of materialized items changes.

 Materialized items are items that have synced to disk and are not
 dataless.  They may contain a mix of dataless and materialized files and
 directories, but in any case, all their children are represented on disk.
 Traversals of dataless directories by applications trigger an enumeration
 against the file provider extension; traversals of materialized directories
 do not.  It is the responsability of the file provider extension to notify
 the system on remote changes of these files: there is no alternative cache
 invalidation mechanism.

 If the extension doesn't keep track of the materialized set, it will have to
 notify the system of all remote changes.  In that case the working set is the
 entire dataset.  The system may drop items whose parent isn't materialized, to
 avoid unnecessary disk usage.  This saves some I/O, but isn't optimal.  The
 filtering by parentItemIdentifier is better done in the extension;  ideally,
 it would even be done server-side.  A hybrid model is possible, where some
 filtering is done server-side, and some finer filtering is done client-side.

 The file provider extension should therefore keep a list of the identifiers of
 the materialized directories.  This method is called when a new directory is
 materialized or when a materialized directory is rendered dataless.

 To enumerate the set of materialized containers,
 - Call -enumeratorForMaterializedItems on the instance of
   NSFileProviderManager corresponding to your domain;
 - Implement the NSFileProviderEnumerationObserver and
   NSFileProviderChangeObserver on an object;
 - Pass that object to the enumerator;
 - Use the identifiers of items or changes you receive to note the
   materialization status in your database.

 When an item is created, modified or deleted remotely, the file provider
 extension should check whether its parentItemIdentifier is in the materialized
 set.  If it is, the extension needs to inform the system so the system may
 create, modify or delete the file or directory (initially dataless) on disk.
 In the case when an item is reparented, the test should be that either the new
 or the old parentItemIdentifier is in the materialized set.  No need to pretend
 that the iten was deleted if the new parentItemIdentifier is no longer in the
 materialized set: the system will know what to do with an unknown parent
 identifier.

 To notify the system of this created, modified or deleted item,
 - Call -signalEnumeratorForContainerItemIdentifier: on the working set, i.e the
   container identified by NSFileProviderWorkingSetContainerItemIdentifier;
 - Include this item in the next enumeration of the working set.
 */
- (void)materializedItemsDidChangeWithCompletionHandler:(void (^)(void))completionHandler;

@end

#pragma mark - Additional protocols

/**
 Protocol to implement if the provider instance supports fetching incremental content changes.
 */
FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderIncrementalContentFetching <NSObject>

/**
 Update a previously provided item to a new version.

 If the system already has a version of an item and learns that a new version is
 available, it may call this method to update the existing version to a new
 version.

 The semantics of the requestedVersion parameter are the same as for the non-delta update method above.
 */
- (NSProgress *)fetchContentsForItemWithIdentifier:(NSFileProviderItemIdentifier)itemIdentifier
                                           version:(nullable NSFileProviderItemVersion *)requestedVersion
                        usingExistingContentsAtURL:(NSURL *)existingContents
                                   existingVersion:(NSFileProviderItemVersion *)existingVersion
                                           request:(nullable NSFileProviderRequest *)request
                                 completionHandler:(void(^)(NSURL * _Nullable fileContents, NSFileProviderItem _Nullable item, NSError * _Nullable error))completionHandler
    NS_SWIFT_NAME(fetchContents(for:version:usingExistingContentsAt:existingVersion:request:completionHandler:));

@end

FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderServicing <NSObject>

/**
 A file provider can implemement this method to return service sources that provide custom
 communication channels to client applications.

 The service sources must be tied to the item identified by @c itemIdentifier.
 Client applications can retrieve the list of supported services by calling
 @c -[NSFileManager getFileProviderServicesForItemAtURL:] for a specific item URL.
*/
- (NSProgress *)supportedServiceSourcesForItemIdentifier:(NSFileProviderItemIdentifier)itemIdentifier
                                       completionHandler:(void (^)(NSArray <id <NSFileProviderServiceSource>> * _Nullable, NSError * _Nullable))completionHandler;

@end

/**
 Protocol to implement if the provider supports fetching thumbnails for its items.
 */
FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderThumbnailing <NSObject>

/**
 The system calls this method to fetch thumbnails.

 The @p perThumbnailCompletionHandler should be called for each thumbnail, and
 @p completionHandler only after all the per thumbnail completion blocks.

 In the event of a global error, the implementation is allowed to skip calling
 the @p perThumbnailCompletionHandler for individual thumbnails. In that case,
 the @p completionHandler's error parameter would apply to all item identifiers
 for which @p perThumbnailCompletionHandler had not been called.

 If there is no thumbnail for a given item, the @p perThumbnailCompletionHandler
 should be called with its @p imageData and @p error parameters both
 set to nil.

 If the system decides that an in-flight thumbnail request is not needed anymore,
 it will call the returned @p NSProgress object's @p -cancel method,
 at which time the implementation should clean up any held resources.

 The system will cache the thumbnail for the item, and the cache will be
 invalidated when itemVersion.contentVersion changes.
 */
- (NSProgress *)fetchThumbnailsForItemIdentifiers:(NSArray<NSFileProviderItemIdentifier> *)itemIdentifiers
                                    requestedSize:(CGSize)size
                    perThumbnailCompletionHandler:(void (^)(NSFileProviderItemIdentifier identifier, NSData * _Nullable imageData, NSError * _Nullable error))perThumbnailCompletionHandler
                                completionHandler:(void (^)(NSError * _Nullable error))completionHandler
    NS_SWIFT_NAME(fetchThumbnails(for:requestedSize:perThumbnailCompletionHandler:completionHandler:));

@end

FILEPROVIDER_API_AVAILABILITY_V3
@protocol NSFileProviderCustomAction  <NSObject>

/**
 Perform a custom action identified by `actionIdentifier`, on items identified by
 `itemIdentifiers`.

 Custom actions are defined in the File Provider Extension's Info.plist.
 */
- (NSProgress *)performActionWithIdentifier:(NSFileProviderExtensionActionIdentifier)actionIdentifier
                     onItemsWithIdentifiers:(NSArray <NSFileProviderItemIdentifier> *)itemIdentifiers
                          completionHandler:(void (^)(NSError * _Nullable error))completionHandler
    NS_SWIFT_NAME(performAction(with:onItemsWithIdentifiers:completionHandler:));

@end


NS_ASSUME_NONNULL_END
