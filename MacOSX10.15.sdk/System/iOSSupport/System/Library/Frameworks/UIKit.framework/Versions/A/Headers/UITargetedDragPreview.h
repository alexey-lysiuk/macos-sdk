#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UITargetedDragPreview.h>)
//
//  UITargetedDragPreview.h
//  UIKit
//
//  Copyright © 2017-2018 Apple Inc. All rights reserved.
//

#import <UIKit/UITargetedPreview.h>

NS_ASSUME_NONNULL_BEGIN

@class UIDragPreviewParameters, UIView;

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos) @interface UIDragPreviewTarget : UIPreviewTarget
@end

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos) @interface UITargetedDragPreview : UITargetedPreview
@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UITargetedDragPreview.h>
#endif
