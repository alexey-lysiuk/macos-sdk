#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIToolbarAppearance.h>)
//
//  UIToolbarAppearance.h
//  UIKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <UIKit/UIBarAppearance.h>
#import <UIKit/UIBarButtonItemAppearance.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UIToolbarAppearance : UIBarAppearance

/// The appearance for plain-style bar button items
@property (nonatomic, readwrite, copy) UIBarButtonItemAppearance *buttonAppearance;

/// The appearance for done-style bar button items
@property (nonatomic, readwrite, copy) UIBarButtonItemAppearance *doneButtonAppearance;

@end

// Original names, temporarily left for compatibility
@interface UIToolbarAppearance (Renamed)

@property (nonatomic, readwrite, copy) UIBarButtonItemAppearance *plainButtonAppearance API_DEPRECATED_WITH_REPLACEMENT("buttonAppearance", ios(13.0, 13.0));

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIToolbarAppearance.h>
#endif
