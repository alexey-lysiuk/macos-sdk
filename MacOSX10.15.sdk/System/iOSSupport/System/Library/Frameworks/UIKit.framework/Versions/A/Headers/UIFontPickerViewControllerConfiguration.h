#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIFontPickerViewControllerConfiguration.h>)
//
//  UIFontPickerViewControllerConfiguration.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) API_UNAVAILABLE(tvos, watchos) @interface UIFontPickerViewControllerConfiguration : NSObject <NSCopying>

@property (nonatomic) BOOL includeFaces; // Indicates if individual faces can be selected instead of just families.

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIFontPickerViewControllerConfiguration.h>
#endif
