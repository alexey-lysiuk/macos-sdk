/*
    NSCollectionViewTransitionLayout.h
    Application Kit
    Copyright (c) 2015-2024, Apple Inc.
    All rights reserved.
*/

#import <AppKit/NSCollectionViewLayout.h>
#import <AppKit/AppKitDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)
APPKIT_API_UNAVAILABLE_BEGIN_MACCATALYST

typedef NSString * NSCollectionViewTransitionLayoutAnimatedKey NS_SWIFT_BRIDGED_TYPEDEF;

API_AVAILABLE(macos(10.11))
@interface NSCollectionViewTransitionLayout : NSCollectionViewLayout

@property (assign) CGFloat transitionProgress;
@property (readonly) NSCollectionViewLayout *currentLayout;
@property (readonly) NSCollectionViewLayout *nextLayout;

// Designated initializer
- (instancetype)initWithCurrentLayout:(NSCollectionViewLayout *)currentLayout nextLayout:(NSCollectionViewLayout *)newLayout;

- (void)updateValue:(CGFloat)value forAnimatedKey:(NSCollectionViewTransitionLayoutAnimatedKey)key;
- (CGFloat)valueForAnimatedKey:(NSCollectionViewTransitionLayoutAnimatedKey)key;

@end

API_UNAVAILABLE_END
NS_HEADER_AUDIT_END(nullability, sendability)
