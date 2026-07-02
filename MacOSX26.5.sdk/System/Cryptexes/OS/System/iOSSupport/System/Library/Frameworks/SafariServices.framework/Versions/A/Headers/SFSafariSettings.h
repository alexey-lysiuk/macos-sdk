// Copyright © 2025 Apple Inc. All rights reserved.


#import <Foundation/Foundation.h>
#import <SafariServices/SFFoundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_SENDABLE
SF_EXTERN API_AVAILABLE(ios(26.0), visionos(26.0)) API_UNAVAILABLE(macCatalyst, tvos, watchos)
@interface SFSafariSettings : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// Launches Settings and opens Safari's export browsing data sheet
/// - Parameters:
///   - completionHandler: The block the system calls after the operation completes, with an optional error parameter if an error occurs.
///     - term error: An error object indicating the reason for the failure, or `nil` if the system successfully opens the sheet.
/// @discussion Call this method when your app is in the foreground, otherwise it returns an error.
+ (void)openExportBrowsingDataSettingsWithCompletionHandler:(nullable NS_SWIFT_UI_ACTOR void (^)(NSError * _Nullable error))completionHandler;

/// Launches Settings to Safari Extensions Settings
/// - Parameters:
///   - extensionIdentifiers: An array of extension identifiers. If you specify one identifier, Settings opens to that extension's detail view. If you specify multiple identifiers, Settings opens to the Safari Extensions pane and highlights those extensions.
///   - completionHandler: The block the system calls after the operation completes, with an optional error parameter if an error occurs.
///     - term error: An error object indicating the reason for the failure, or `nil` if the system successfully opens to Safari Extensions Settings.
/// @discussion Call this method when your app is in the foreground, otherwise it returns an error.
+ (void)openExtensionsSettingsForIdentifiers:(NSArray<NSString *> *)extensionIdentifiers completionHandler:(nullable NS_SWIFT_UI_ACTOR void (^)(NSError * _Nullable error))completionHandler API_AVAILABLE(ios(26.2), visionos(26.2));
@end

NS_ASSUME_NONNULL_END

