#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UISceneSession.h>)
//
//  UISceneSession.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UISceneDefinitions.h>

NS_ASSUME_NONNULL_BEGIN

@class UIScene, UIStoryboard;

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UISceneConfiguration : NSObject <NSCopying, NSSecureCoding>
// creates a UISceneConfiguration instance from your Info.plist using the name & system type provided.
// If nil is provided for the name, the first matching instance of the provided sessionType is used.
// If no matching name is found, or no descriptions of the provided sessionType exist in your Info.plist,
// then an instance with a nil canvasSubclass, delegateClass, and storyboard is returned.
+ (instancetype)configurationWithName:(nullable NSString *)name sessionRole:(UISceneSessionRole)sessionRole;
- (instancetype)initWithName:(nullable NSString *)name sessionRole:(UISceneSessionRole)sessionRole NS_DESIGNATED_INITIALIZER;

@property (nonatomic, nullable, readonly) NSString *name;
@property (nonatomic, readonly) UISceneSessionRole role;

@property (nonatomic, nullable) Class sceneClass;
@property (nonatomic, nullable) Class delegateClass;
@property (nonatomic, nullable, strong) UIStoryboard *storyboard;
@end

UIKIT_EXTERN API_AVAILABLE(ios(13.0)) @interface UISceneSession : NSObject <NSSecureCoding>
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

// If already instantiated, the UIScene instance that is represented by this definition.
@property (nonatomic, readonly, nullable) UIScene *scene;

@property (nonatomic, readonly) UISceneSessionRole role;
@property (nonatomic, readonly, copy) UISceneConfiguration *configuration;

@property (nonatomic, readonly) NSString *persistentIdentifier;

// depending on the device's current data storage class, the following property may not be immediately available
@property (nonatomic, readonly, nullable) NSUserActivity *stateRestorationActivity;

// objects must be plist types
@property (nonatomic, nullable, copy) NSDictionary<NSString *, id> *userInfo;
@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UISceneSession.h>
#endif
