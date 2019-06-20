//
//  FPUIActionExtensionController.h
//  FileProviderUI
//
//  Created by Rony Fadel on 3/21/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FileProvider/FileProvider.h>
#import <FileProviderUI/FPUIBase.h>
#import <FileProviderUI/FPUIActionExtensionContext.h>

@class FPUIActionExtensionContext;

NS_ASSUME_NONNULL_BEGIN

FPUI_AVAILABLE(ios(13.0), macos(10.15))
@interface FPUIActionExtensionController : NSObject

@property (nonatomic, readonly, strong) FPUIActionExtensionContext *extensionContext;

// To be overridden by the subclass
- (NSProgress *_Nullable)performActionWithIdentifier:(FPUIActionIdentifier)actionIdentifier itemIdentifiers:(NSArray <NSFileProviderItemIdentifier> *)itemIdentifiers NS_SWIFT_NAME( perform(_:itemIdentifiers:) );

@end

NS_ASSUME_NONNULL_END
