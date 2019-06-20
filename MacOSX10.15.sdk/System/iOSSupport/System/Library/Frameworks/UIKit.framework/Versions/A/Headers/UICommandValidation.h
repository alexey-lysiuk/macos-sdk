#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommandValidation.h>)
//
//  UICommandValidation.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UICommand.h>
#import <UIKit/UIKitDefines.h>

@class UIResponder;

NS_ASSUME_NONNULL_BEGIN

/** START OF V1 API, TO REMOVE **/

/// Validation for a command
UIKIT_EXTERN API_DEPRECATED_WITH_REPLACEMENT("UIMutableCommand", ios(13.0, 13.0)) @interface UICommandValidation : NSObject

/// Whether to enable or disable the command.
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/// New target for command. nil to accept original target.
@property (nonatomic, nullable, weak) UIResponder *preferredTarget;

/// Preferred visible state for command, if supportedStates contains this. 0 to clear state.
@property (nonatomic, assign) UICommandState preferredState;

/// Preferred title for command. nil to accept original title.
@property (nonatomic, nullable, copy) NSString *preferredTitle;

@end

/** END OF V1 API, TO REMOVE **/

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommandValidation.h>
#endif
