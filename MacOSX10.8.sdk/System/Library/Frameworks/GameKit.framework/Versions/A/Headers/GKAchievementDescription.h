//
//  GKAchievementDescription.h
//  GKAPI
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// GKAchievementDescription is a full description of the achievement as defined before app submission in iTunes Connect.
NS_CLASS_AVAILABLE(10_8, 4_1)
@interface GKAchievementDescription : NSObject <NSCoding> {
@private
	id _internal;
}

// Asynchronously load all achievement descriptions
+ (void)loadAchievementDescriptionsWithCompletionHandler:(void(^)(NSArray *descriptions, NSError *error))completionHandler;
#if TARGET_OS_IPHONE
+ (UIImage *)incompleteAchievementImage; // The default image for any incomplete achievement
+ (UIImage *)placeholderCompletedAchievementImage; // A placeholder image to be used for any completed achievement until the description image has loaded.
#else
+ (NSImage *)incompleteAchievementImage; // The default image for any incomplete achievement
+ (NSImage *)placeholderCompletedAchievementImage; // A placeholder image to be used for any completed achievement until the description image has loaded.
#endif

@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSString *identifier;
@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSString *title;                 // The title of the achievement.
@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSString *achievedDescription;   // The description for an unachieved achievement.
@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSString *unachievedDescription; // The description for an achieved achievement.
@property(assign, readonly, NS_NONATOMIC_IOSONLY) NSInteger maximumPoints;         // Maximum points available for completing this achievement.
@property(getter = isHidden, assign, readonly, NS_NONATOMIC_IOSONLY) BOOL hidden;  // Whether or not the achievement should be listed or displayed if not yet unhidden by the game.
@end

#if TARGET_OS_IPHONE

@class UIImage;
@interface GKAchievementDescription (UIKitExtensions)

// Image for completed achievement. Not valid until loadImage: has completed.
@property(retain, readonly, NS_NONATOMIC_IOSONLY) UIImage *image;

// Asynchronously load the image. Error will be nil on success.
- (void)loadImageWithCompletionHandler:(void(^)(UIImage *image, NSError *error))completionHandler;
@end

#else // !TARGET_OS_IPHONE

@class NSImage;
@interface GKAchievementDescription (AppKitExtensions)

// Image for completed achievement. Not valid until loadImage: has completed.
@property(retain, readonly, NS_NONATOMIC_IOSONLY) NSImage *image;

// Asynchronously load the image. Error will be nil on success.
- (void)loadImageWithCompletionHandler:(void(^)(NSImage *image, NSError *error))completionHandler;
@end

#endif
                                          
