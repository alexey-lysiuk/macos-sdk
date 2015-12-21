//
//  JRSMenu.h
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSMenu(JavaRuntimeSupport)
- (BOOL) isJavaMenu;
- (void) setJavaMenu:(BOOL)isJavaMenu;
@end
