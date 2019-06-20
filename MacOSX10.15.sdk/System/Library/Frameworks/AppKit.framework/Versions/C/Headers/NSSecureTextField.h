/*
        NSSecureTextField.h
        Application Kit
        Copyright (c) 1995-2018, Apple Inc.
        All rights reserved.
*/

#import <AppKit/NSTextField.h>
#import <AppKit/NSTextFieldCell.h>

API_UNAVAILABLE_BEGIN(ios)

@interface NSSecureTextField : NSTextField
@end

@interface NSSecureTextFieldCell : NSTextFieldCell

@property BOOL echosBullets;

@end

API_UNAVAILABLE_END
