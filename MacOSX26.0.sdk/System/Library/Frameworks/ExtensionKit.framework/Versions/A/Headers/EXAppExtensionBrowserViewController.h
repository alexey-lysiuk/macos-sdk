//
//  EXAppExtensionBrowserViewController.h
//  ExtensionKit
//

#import <ExtensionFoundation/ExtensionFoundation.h>
#import <Foundation/Foundation.h>
#import <TargetConditionals.h>

#if !TARGET_OS_WATCH

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#else
#import <UIKit/UIKit.h>
#endif // TARGET_OS_OSX

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(18))
API_UNAVAILABLE(watchos)
API_UNAVAILABLE(tvos)
API_UNAVAILABLE(visionos)
EXTENSIONKIT_EXPORT
#if TARGET_OS_OSX
/// A view controller that allows users to enable and disable extensions.
@interface EXAppExtensionBrowserViewController : NSViewController
@end
#else
/// A view controller that allows users to enable and disable extensions.
@interface EXAppExtensionBrowserViewController : UIViewController
@end
#endif // TARGET_OS_OSX

NS_ASSUME_NONNULL_END

#endif // !TARGET_OS_WATCH
