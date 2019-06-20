#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommandSystem.h>)
//
//  UICommandSystem.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// The command system to build or rebuild.
UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UICommandSystem : NSObject

/// The main command system.
@property (class, nonatomic, readonly) UICommandSystem *mainSystem;

/// The context command system.
@property (class, nonatomic, readonly) UICommandSystem *contextSystem;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// Trigger a rebuild of this system at a suitable time.
- (void)setNeedsRebuild;

/// Trigger a revalidate of this system at a suitable time.
- (void)setNeedsRevalidate;

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommandSystem.h>
#endif
