/*
 JNFRunLoop.h
 Java Native Foundation
 Copyright (c) 2009-2010, Apple Inc.
 All rights reserved.
 
 Used to perform selectors and blocks in the Java runloop mode.
 */

#import <Foundation/Foundation.h>

@interface JNFRunLoop : NSObject { }

+ (NSString *)javaRunLoopMode;
+ (void)performOnMainThread:(SEL)aSelector on:(id)target withObject:(id)arg waitUntilDone:(BOOL)wait;
#if __BLOCKS__
+ (void)performOnMainThreadWaiting:(BOOL)waitUntilDone withBlock:(void (^)())block;
#endif

@end
