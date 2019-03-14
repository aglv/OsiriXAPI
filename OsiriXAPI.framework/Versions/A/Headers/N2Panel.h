/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import <Cocoa/Cocoa.h>
@class N2View;

@interface N2Panel : NSPanel {
	BOOL _canBecomeKeyWindow;
}

@property BOOL canBecomeKeyWindow;

@end
