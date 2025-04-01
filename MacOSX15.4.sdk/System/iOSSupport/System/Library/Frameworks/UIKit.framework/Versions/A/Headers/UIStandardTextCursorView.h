#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIStandardTextCursorView.h>)
//
//  UIStandardTextCursorView.h
//  UIKit
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <UIKit/UIKitCore.h>
#import <UIKit/UITextCursorView.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// @class      @c UIStandardTextCursorView
/// @abstract   Displays a flashing cursor (aka "caret") view. Concrete implementation of UITextCursorView.
/// @discussion When a selection is not ranged (or has a zero-length), a cursor view is displayed.
UIKIT_EXTERN API_AVAILABLE(ios(17.4)) API_UNAVAILABLE(watchos)
@interface UIStandardTextCursorView : UIView <UITextCursorView>
@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UIStandardTextCursorView.h>
#endif
