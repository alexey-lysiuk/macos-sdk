//
//  QLThumbnailGeneratorErrors.h
//  Quick Look Thumbnailing
//
//  Copyright (c) 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickLookThumbnailing/QLThumbnailingBase.h>

QLT_EXPORT extern NSErrorDomain const QLThumbnailGeneratorErrorDomain NS_SWIFT_NAME(QLThumbnailGenerator.ErrorDomain) API_AVAILABLE(macos(10.15), ios(13.0));

typedef NS_ERROR_ENUM(QLThumbnailGeneratorErrorDomain, QLThumbnailGeneratorError) {
    QLThumbnailGeneratorErrorGenerationFailed,
    QLThumbnailGeneratorErrorSavingToURLFailed,
    QLThumbnailGeneratorErrorNoCachedThumbnail,
    QLThumbnailGeneratorErrorNoCloudThumbnail,
    QLThumbnailGeneratorErrorRequestInvalid,
    QLThumbnailGeneratorErrorRequestCancelled,
} NS_SWIFT_NAME(QLThumbnailGenerator.Error) API_AVAILABLE(macos(10.15), ios(13.0));
