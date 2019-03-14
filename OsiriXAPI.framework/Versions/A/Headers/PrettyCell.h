/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <AppKit/AppKit.h>

@interface PrettyCell : NSButtonCell {
    NSString* _rightText;
    NSMutableArray* _rightSubviews;
    NSColor* _textColor;
}

@property(retain) NSString* rightText;
@property(readonly,retain) NSMutableArray* rightSubviews;
@property(retain) NSColor* textColor;

+ (void) setWillBeVisible: (BOOL) v;
+ (BOOL) willBeVisible;
@end
