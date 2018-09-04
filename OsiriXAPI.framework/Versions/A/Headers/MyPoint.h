/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/




#import <Foundation/Foundation.h>

/** \brief Wrapper for NSPoint */

@interface MyPoint : NSObject<NSCoding> {
	NSPoint pt;
}

@property(assign) NSPoint point;
@property(readonly) float x, y;

+ (MyPoint*)point:(NSPoint)a;
- (id)initWithPoint:(NSPoint)a;

- (void)setPoint:(NSPoint)a;
- (void)move:(float)x :(float)y;

- (BOOL)isEqualToMyPoint:(MyPoint*)a;
- (BOOL)isEqualToPoint:(NSPoint)a;
- (BOOL)isNearToPoint:(NSPoint)a :(float)scale :(float)ratio;

@end
