#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommandGroupable.h>)
//
//  UICommandGroupable.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Object that can be grouped i.e. as a child of UICommandGroup.
///
/// @note Implementations other than UICommand or UICommandGroup are not supported.
API_DEPRECATED_WITH_REPLACEMENT("UIMenuElement", ios(13.0, 13.0)) @protocol UICommandGroupable
@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommandGroupable.h>
#endif
