#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/NSToolbar+UIKitAdditions.h>)
#if TARGET_OS_UIKITFORMAC
//
//  NSToolbar+UIKitAdditions.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIWindowScene.h>
#import <AppKit/NSToolbarItem.h>

@class UITitlebar, NSToolbar, UIBarButtonItem;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UITitlebarTitleVisibility) {
    UITitlebarTitleVisibilityVisible,   // The title will be visible on top of the toolbar if there is one
    UITitlebarTitleVisibilityHidden     // No title will be visible. Window chrome will only appear if there is a toolbar
} API_AVAILABLE(uikitformac(13.0));

@interface UIWindowScene (NSToolbarAdditions)
@property (nonatomic, readonly, nullable) UITitlebar *titlebar API_AVAILABLE(uikitformac(13.0));
@end

API_AVAILABLE(uikitformac(13.0))
@interface UITitlebar : NSObject

/*
 The visible state of the title of the titlebar.
 If the value is UITitlebarVisiblityHidden and there is no toolbar, the result will hide any window chrome at the top of the window.
 Defaults to UITitlebarVisiblityVisible.
 */
@property UITitlebarTitleVisibility titleVisibility;

/*
 Sets and gets the NSToolbar displayed at the top of the NSWindow associated with this scene
 */
@property (nonatomic, nullable, strong) NSToolbar *toolbar;

/*
 When set and the window enters fullscreen mode, the toolbar is detached from the window and hides and shows with the menu bar.
 */
@property (nonatomic) BOOL autoHidesToolbarInFullScreen;

@end

@interface NSToolbarItem (NSToolbarAdditions)
/*
 Constructs a standard NSToolbarItem as a button with values from a UIBarButtonItem.
 UIBarButtonItems configured with custom views will not be honored.
 The NSToolbarItem will be populated with the -title and/or -image from the UIBarButtonItem.
 UIBarButtonItems with a UIBarButtonSystemItem will be appropriately configured as well.
 */
+ (instancetype)itemWithItemIdentifier:(NSToolbarItemIdentifier)itemIdentifier barButtonItem:(UIBarButtonItem *)barButtonItem API_AVAILABLE(uikitformac(13.0));
@end

NS_ASSUME_NONNULL_END

#endif

#else
#import <UIKitCore/NSToolbar+UIKitAdditions.h>
#endif
