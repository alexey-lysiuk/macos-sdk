#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIMenuElement.h>)
//
//  UIMenuElement.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UICommandGroupable.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIMenuElement<__covariant T> : NSObject <NSCopying, UICommandGroupable>
#pragma clang diagnostic pop

/// The element's title.
@property (nonatomic, readonly) NSString *title;

/// Image to be displayed alongside the element's title.
@property (nonatomic, nullable, readonly) UIImage *image;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIMenuElement.h>
#endif
