//
//  NSFileProviderSearchQuery.h
//  FileProvider
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <FileProvider/NSFileProviderDefines.h>
#import <FileProvider/NSFileProviderExtension.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), macos(10.15)) API_UNAVAILABLE(watchos, tvos)
@interface NSFileProviderSearchQuery : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Specify that all result items must have in their filename the provided string
 or some variant thereof.
 */
@property (nonatomic, copy, readonly, nullable) NSString *filename;

/**
 Specify that all result items must be conform to at least one of the provided
 UTI.

 This property will always be nil unless the capability
 NSExtensionFileProviderSearchByContentType is listed in the provider's plist
 under NSExtensionFileProviderSupportedSearchCapabilities.
 */
@property (nonatomic, copy, readonly, nullable) NSSet<NSString*> *allowedContentTypes;

/**
 Returns the extensions corresponding to the allowedContentTypes defined above.

 This property will always be nil unless the capability
 NSExtensionFileProviderSearchByContentType is listed in the provider's plist
 under NSExtensionFileProviderSupportedSearchCapabilities.
*/
@property (nonatomic, copy, readonly, nullable) NSSet<NSString *> *allowedPathExtensions;

/**
 Specify that all result items must have for parent the specified item
 identifier or be one of its descendants. In other words the scope of search is
 all items recursively parented to the provided identifier.

 This property will always be equal to NSFileProviderRootContainerItemIdentifier
 unless the capability NSExtensionFileProviderSearchScopedToDirectory is listed
 in the provider's plist under NSExtensionFileProviderSupportedSearchCapabilities.
 */
@property (nonatomic, copy, readonly) NSFileProviderItemIdentifier scopedToItemIdentifier;

#pragma mark -

/**
 A unique identifier that may be used to signal an update in the list of results
 provided by the search enumerator. This identifier is valid as long as the
 search enumeration is alive. If used afterwards, the update is ignored.

 See signalEnumeratorForContainerItemIdentifier:completionHandler:.
 */
@property (nonatomic, copy, readonly) NSFileProviderItemIdentifier searchContainerItemIdentifier;

@end

@interface NSFileProviderSearchQuery (Deprecated)

// <rdar://problem/50372998> Remove deprecated methods from NSFileProviderSearchQuery.h
@property (nonatomic, copy, readonly, nullable) NSString *searchString API_DEPRECATED("Feature removed", macos(10.15, 10.15), ios(13.0, 13.0));
@property (nonatomic, copy, readonly, nullable) NSString *content API_DEPRECATED("Feature removed", macos(10.15, 10.15), ios(13.0, 13.0));

@end

NS_ASSUME_NONNULL_END
