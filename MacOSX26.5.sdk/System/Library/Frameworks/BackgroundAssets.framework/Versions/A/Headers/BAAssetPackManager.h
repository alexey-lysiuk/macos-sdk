//
//  BAAssetPackManager.h
//  Background Assets
//
//  Created by Gabriel Jacoby-Cooper on 3/10/25.
//

#import <BackgroundAssets/BAAssetPackStatus.h>
#import <BackgroundAssets/BAManagedAssetPackDownloadDelegate.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// A class that manages asset packs.
///
/// The first time that your code refers to the shared manager, Background Assets considers that your application is opting into automatic system management of your asset packs.
/// - Important: When using the asset-pack manager, make sure that you also adopt the corresponding managed extension protocol. For applications that use Apple hosting, the corresponding protocol is `SKDownloaderExtension` from StoreKit. For other applications, the corresponding protocol is ``BAManagedDownloaderExtension``. Not adopting the right protocol is a programmer error.
API_AVAILABLE(ios(26), macos(26), tvos(26), visionos(26))
API_UNAVAILABLE(watchos)
NS_REFINED_FOR_SWIFT
@interface BAAssetPackManager : NSObject

/// The shared asset-pack manager.
@property (class, readonly, strong) BAAssetPackManager* sharedManager NS_SWIFT_NAME(shared);

/// An object that receives notifications about events that occur as an asset pack is downloaded.
@property (nullable, readwrite, weak) id<BAManagedAssetPackDownloadDelegate> delegate;

- (null_unspecified instancetype)init NS_UNAVAILABLE;

+ (null_unspecified instancetype)new NS_UNAVAILABLE;

/// Gets the asset packs that are available to download.
///
/// This method might attempt to get the latest asset-pack information from the server.
/// - Parameter completionHandler: A block that receives the asset packs or an error if one occurs.
- (void)getAllAssetPacksWithCompletionHandler:(void (^)(NSSet<BAAssetPack*>* _Nullable assetPacks, NSError* _Nullable error))completionHandler
NS_SWIFT_ASYNC_NAME(allAssetPacks());

/// Gets the asset pack with the given identifier.
///
/// If no asset pack with the given identifier is found, then the block will receive an `NSError` object with ``BAManagedErrorCode/BAManagedErrorCodeAssetPackNotFound`` as its code for the `error` parameter. This method might attempt to get the latest asset-pack information from the server. To force the system to get the latest information from the server unconditionally, send ``checkForUpdatesWithCompletionHandler:`` to the shared asset-pack manager.
/// - Parameters:
///   - assetPackIdentifier: The asset pack’s identifier.
///   - completionHandler: A block that receives the asset pack or an error if one occurs.
- (void)getAssetPackWithIdentifier:(NSString*)assetPackIdentifier
                 completionHandler:(void (^)(BAAssetPack* _Nullable assetPack, NSError* _Nullable error))completionHandler
NS_SWIFT_ASYNC_NAME(assetPack(withID:));

/// Gets an asset pack’s status.
///
/// This method checks whether any version of the specified asset pack is currently downloaded. If one is, then it determines the version relationship between the downloaded asset pack and the specified asset pack. If they have different version numbers, then the status value that it passes to `completionHandler` will contain ``BAAssetPackStatus/BAAssetPackStatusOutOfDate``. The status value will contain ``BAAssetPackStatus/BAAssetPackStatusUpdateAvailable`` only if the relevant asset pack on the server hasn’t been further updated since the initialization of the provided ``BAAssetPack`` instance.
///
/// For example, consider the following sequence of events, assuming that version 1 of the relevant asset pack is already available locally:
/// 1.	Your application calls ``getAssetPackWithIdentifier:completionHandler:`` to obtain a ``BAAssetPack`` instance.
/// 2.	The asset pack is updated to version 2 on the server.
/// 3.	Your application calls this method, passing the ``BAAssetPack`` instance from step 1.
///
/// In this case, the status value will indicate that the downloaded asset pack is up to date. Generally, you shouldn’t need to handle this type of situation explicitly because the system automatically polls for updates periodically in the background.
///
/// This method doesn’t automatically trigger any downloads, updates, or removals.
/// - Parameters:
///   - assetPack: The asset pack.
///   - completionHandler: A block that receives the asset pack’s status or an error if one occurs.
- (void)getStatusRelativeToAssetPack:(BAAssetPack*)assetPack
                   completionHandler:(void (^)(BAAssetPackStatus status, NSError* _Nullable error))completionHandler
API_AVAILABLE(ios(26.4), macos(26.4), tvos(26.4), visionos(26.4));

/// Gets an asset pack’s local status.
///
/// This method checks only status values that are determinable offline. It doesn’t induce any network traffic or automatically trigger any downloads, updates, or removals. The following status values are determinable offline:
/// - ``BAAssetPackStatus/BAAssetPackStatusOutOfDate`` (in some situations)
/// - ``BAAssetPackStatus/BAAssetPackStatusObsolete`` (in some situations)
/// - ``BAAssetPackStatus/BAAssetPackStatusDownloaded``
///
/// Because this method doesn’t communicate with the server, it can’t determine whether a particular asset pack exists in the first place. Instead, it returns an empty status value when provided a nonexistent asset-pack ID, which is indistinguishable from the situation in which the asset pack does indeed exist but hasn’t yet been downloaded. Use ``getStatusOfAssetPackWithIdentifier:completionHandler:`` to get a full view of an asset pack’s status.
/// - Parameters:
///   - assetPackIdentifier: The asset pack’s identifier.
///   - completionHandler: A block that receives the asset pack’s local status.
- (void)getLocalStatusOfAssetPackWithIdentifier:(NSString*)assetPackIdentifier
                              completionHandler:(void (^)(BAAssetPackStatus status))completionHandler
API_AVAILABLE(ios(26.4), macos(26.4), tvos(26.4), visionos(26.4));

/// Checks whether the asset pack with the specified identifier is available locally.
/// - Parameter assetPackIdentifier: The asset pack’s identifier.
/// - Returns: Whether the asset pack is available locally.
- (BOOL)assetPackIsAvailableLocallyWithIdentifier:(NSString*)assetPackIdentifier
API_AVAILABLE(ios(26.4), macos(26.4), tvos(26.4), visionos(26.4))
NS_SWIFT_NAME(assetPackIsAvailableLocally(withID:));

/// Ensures that the specified asset pack be available locally.
///
/// This method checks if the asset pack is currently downloaded. If it isn’t, then it schedules it to be downloaded and calls the block with `nil` for the block’s `error` parameter when the download completes. It’s guaranteed that the requested asset pack will be available locally once the block is called with `nil` for its `error` parameter. If a non-`nil` value is provided to the block’s `error` parameter, then the asset pack is **not** guaranteed to be available locally. You can optionally monitor download progress by attaching a delegate object to ``delegate``.
/// - Parameters:
///   - assetPack: The asset pack the local availability of which to ensure.
///   - completionHandler: A block that’s called when the asset pack is available locally or that receives an error if one occurs.
- (void)ensureLocalAvailabilityOfAssetPack:(BAAssetPack*)assetPack
                         completionHandler:(void (^)(NSError* _Nullable error))completionHandler;

/// Ensures that the specified asset pack be available locally.
///
/// This method checks if the asset pack is currently downloaded. If it isn’t, then it schedules it to be downloaded and calls the block with `nil` for the block’s `error` parameter when the download completes. It’s guaranteed that the requested asset pack will be available locally once the block is called with `nil` for its `error` parameter. If a non-`nil` value is provided to the block’s `error` parameter, then the asset pack is **not** guaranteed to be available locally. You can optionally monitor download progress by attaching a delegate object to ``delegate``.
/// - Parameters:
///   - assetPack: The asset pack the local availability of which to ensure.
///   - shouldUpdate: Whether to require that the latest version be available locally. When `YES` is passed to this parameter, the method will wait for the update (if there indeed is one available) to be downloaded before returning. When `NO` is passed, the method won’t check for updates and won’t attempt to download any.
///   - completionHandler: A block that’s called when the asset pack is available locally or that receives an error if one occurs.
- (void)ensureLocalAvailabilityOfAssetPack:(BAAssetPack*)assetPack
                      requireLatestVersion:(BOOL)shouldUpdate
                         completionHandler:(void (^)(NSError* _Nullable error))completionHandler
API_AVAILABLE(ios(26.4), macos(26.4), tvos(26.4), visionos(26.4));

/// Gets the latest asset-pack information from the server, updates outdated asset packs, and removes obsolete asset packs.
/// - Parameter completionHandler: A block that receives a set of identifiers of asset packs that are being updated and a set of identifiers of removed asset packs or an error if one occurs.
- (void)checkForUpdatesWithCompletionHandler:(nullable void (^)(NSSet<NSString*>* _Nullable updatingIdentifiers, NSSet<NSString*>* _Nullable removedIdentifiers, NSError* _Nullable error))completionHandler;

/// Returns the contents of an asset file at the specified relative path.
///
/// All asset packs share the same namespace, so you can treat the overall collection of downloaded asset packs as if it were a single root directory that contains all of your subdirectories and asset files, regardless of the specific asset pack in which any particular file resides. If there’s a file-path collision across multiple asset packs, then it’s undefined from which asset pack the file will be read unless you explicitly limit the search to a particular asset pack by passing a non-`nil` identifier to the `assetPackIdentifier` parameter.
/// - Parameters:
///   - path: The relative file path.
///   - assetPackIdentifier: The identifier of the asset pack in which you want to search for the file or `nil` if you want to search in all asset packs.
///   - options: Options for how to read the contents of the file into a data object.
///   - error: A pointer to an error that will be set if an error occurs. If no file is found at `path`, then `error` will point to an `NSError` object with ``BAManagedErrorCode/BAManagedErrorCodeFileNotFound`` as its code.
/// - Returns: The file’s contents.
- (nullable NSData*)contentsAtPath:(NSString*)path
searchingInAssetPackWithIdentifier:(nullable NSString*)assetPackIdentifier
                           options:(NSDataReadingOptions)options
                             error:(NSError* _Nullable *)error
NS_SWIFT_NAME(contents(atPath:searchingInAssetPackWithID:options:));

/// Opens and returns a file descriptor for the asset file at the specified relative path.
///
/// All asset packs share the same namespace, so you can treat the overall collection of downloaded asset packs as if it were a single root directory that contains all of your subdirectories and asset files, regardless of the specific asset pack in which any particular file resides. If there’s a file-path collision across multiple asset packs, then it’s undefined from which asset pack the file will be opened unless you explicitly limit the search to a particular asset pack by passing a non-`nil` identifier to the `assetPackIdentifier` parameter. A return value of `-1` indicates that an error occurred.
/// - Parameters:
///   - path: The relative file path.
///   - assetPackIdentifier: The identifier of the asset pack in which you want to search for the file or `nil` if you want to search in all asset packs.
///   - error: A pointer to an error that will be set if an error occurs. If no file is found at `path`, then it will point to an `NSError` object with ``BAManagedErrorCode/BAManagedErrorCodeFileNotFound`` as its code.
/// - Returns: A descriptor for the opened file.
/// - Important: It’s your responsibility to close the file descriptor when you’re done using it.
/// - Remark: Use this method if you need low-level access to the file descriptor. If you don’t, then use ``BAAssetPackManager/contentsAtPath:searchingInAssetPackWithIdentifier:options:error:`` instead.
- (signed int)fileDescriptorForPath:(NSString*)path
 searchingInAssetPackWithIdentifier:(nullable NSString*)assetPackIdentifier
                              error:(NSError* _Nullable *)error
NS_SWIFT_NAME(descriptor(forPath:searchingInAssetPackWithID:error:));

/// Returns a URL for the specified relative path.
///
/// All asset packs share the same namespace, so you can treat the overall collection of downloaded asset packs as if it were a single root directory that contains all of your subdirectories and asset files, regardless of the specific asset pack in which any particular file resides. Unlike ``BAAssetPackManager/contentsAtPath:searchingInAssetPackWithIdentifier:options:error:`` and ``BAAssetPackManager/fileDescriptorForPath:searchingInAssetPackWithIdentifier:error:``, this method supports retrieving entire directories—including packages—in which case it merges the corresponding slices of the shared logical directory from all downloaded asset packs that contain such slices. If there’s a file-path collision across multiple asset packs, then it’s undefined from which asset pack an individual file will be resolved.
/// - Parameters:
///   - path: The relative file path.
///   - error: A pointer to an error that will be set if an error occurs.
/// - Warning: Don’t persist the returned URL beyond the lifetime of the current process.
/// - Warning: This method is less efficient than are ``BAAssetPackManager/contentsAtPath:searchingInAssetPackWithIdentifier:options:error:`` and ``BAAssetPackManager/fileDescriptorForPath:searchingInAssetPackWithIdentifier:error:``; use those methods instead if you can do so. In particular, this method shouldn’t be used to get the URL to the root of the shared asset-pack namespace. Don’t use this method to block the main thread.
/// - Note: This method will return a well formed URL even if no item exists at the specified relative path in any asset pack, in which case any attempts to get its contents—whether it’s a file or a directory—will fail.
- (nullable NSURL*)URLForPath:(NSString*)path error:(NSError* _Nullable *)error
NS_SWIFT_NAME(url(forPath:));

/// Removes the specified asset pack from the device.
/// - Parameters:
///   - assetPackIdentifier: The asset pack’s identifier.
///   - completionHandler: A block that receives an error if one occurs.
- (void)removeAssetPackWithIdentifier:(NSString*)assetPackIdentifier
                    completionHandler:(nullable void (^)(NSError* _Nullable error))completionHandler
NS_SWIFT_ASYNC_NAME(remove(assetPackWithID:));

// MARK: Deprecated

/// Gets an asset pack’s status.
///
/// If no asset pack with the specified identifier is found, then the block will receive an `NSError` object with ``BAManagedErrorCode/BAManagedErrorCodeAssetPackNotFound`` as its code for the `error` parameter. This method attempts to get the latest asset-pack information from the server. It doesn’t automatically trigger any downloads, updates, or removals.
/// - Parameters:
///   - assetPackIdentifier: The asset pack’s identifier.
///   - completionHandler: A block that receives the asset pack’s status or an error if one occurs.
- (void)getStatusOfAssetPackWithIdentifier:(NSString*)assetPackIdentifier
                         completionHandler:(void (^)(BAAssetPackStatus status, NSError* _Nullable error))completionHandler
API_DEPRECATED_WITH_REPLACEMENT("-getStatusRelativeToAssetPack:completionHandler:", ios(26, 26.4), macos(26, 26.4), tvos(26, 26.4), visionos(26, 26.4));

@end

NS_HEADER_AUDIT_END(nullability, sendability)
