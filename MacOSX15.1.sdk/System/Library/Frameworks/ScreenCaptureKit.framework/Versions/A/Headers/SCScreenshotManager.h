//
//  SCScreenshotManager.h
//  ScreenCaptureKit
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ScreenCaptureKit/ScreenCaptureKit.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(14.0))
@interface SCScreenshotManager : NSObject
- (instancetype)init API_UNAVAILABLE(ios, tvos, macCatalyst, macos);
/*!
 @abstract captureSampleBufferWithFilter:configuration:completionHandler:
 @param contentFilter is the filter containing the content to take a screenshot of
 @param config is the stream configuration containing information on how to format the screenshot
 @param completionHandler is the handler that will deliver the screenshot to the user
 @discussion this method takes a screenshot using the filter and configuration passed in and returns it as a CMSampleBuffer
*/
+ (void)captureSampleBufferWithFilter:(SCContentFilter *)contentFilter configuration:(SCStreamConfiguration *)config completionHandler:(nullable void (^)(CMSampleBufferRef _Nullable sampleBuffer, NSError *_Nullable error))completionHandler NS_SWIFT_NAME(captureSampleBuffer(contentFilter:configuration:completionHandler:)) API_AVAILABLE(macos(14.0));

/*!
 @abstract captureImageWithFilter:configuration:completionHandler:
 @param contentFilter is the filter containing the content to take a screenshot of
 @param config is the stream configuration containing information on how to format the screenshot
 @param completionHandler is the handler that will deliver the screenshot to the user
 @discussion this method takes a screenshot using the filter and configuration passed in and returns it as a CGImage in BGRA format if captureDynamicRange is SCCaptureDynamicRangeSDR, in RGhA format if captureDynamicRange is SCCaptureDynamicRangeHDRLocalDisplay/SCCaptureDynamicRangeHDRCanonicalDisplay
*/
+ (void)captureImageWithFilter:(SCContentFilter *)contentFilter configuration:(SCStreamConfiguration *)config completionHandler:(nullable void (^)(CGImageRef _Nullable sampleBuffer, NSError *_Nullable error))completionHandler NS_SWIFT_NAME(captureImage(contentFilter:configuration:completionHandler:)) API_AVAILABLE(macos(14.0));

@end

NS_ASSUME_NONNULL_END
