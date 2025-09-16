/*
        NSSplitViewItemAccessoryViewController.h
        Application Kit
        Copyright (c) 2024, Apple Inc.
        All rights reserved.
*/

#import <AppKit/NSViewController.h>
#import <AppKit/AppKitDefines.h>
#import <AppKit/NSAnimation.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)
APPKIT_API_UNAVAILABLE_BEGIN_MACCATALYST

API_AVAILABLE(macos(26.0))
@interface NSSplitViewItemAccessoryViewController : NSViewController  <NSAnimatablePropertyContainer>

/// When set, this property will collapse the accessory view to 0 height (animatable) but not remove it from the window.
/// Set through the animator object to animate it.
@property (getter=isHidden) BOOL hidden;

/// Whether or not standard content insets should be applied to the view.
/// Defaults to YES.
@property BOOL automaticallyAppliesContentInsets;

- (void)viewWillAppear NS_REQUIRES_SUPER;
- (void)viewDidAppear NS_REQUIRES_SUPER;
- (void)viewWillDisappear NS_REQUIRES_SUPER;
- (void)viewDidDisappear NS_REQUIRES_SUPER;

@end

API_UNAVAILABLE_END
NS_HEADER_AUDIT_END(nullability, sendability)
