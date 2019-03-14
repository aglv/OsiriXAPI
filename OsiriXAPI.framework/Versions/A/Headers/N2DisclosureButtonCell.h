/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

@interface N2DisclosureButtonCell : NSButtonCell {
	NSMutableDictionary* _attributes;
}

@property(readonly) NSMutableDictionary* attributes;

-(NSSize)textSize;

@end
