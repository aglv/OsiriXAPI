/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/



#import <Cocoa/Cocoa.h>
#import "N3Geometry.h"

/** \brief  Represents a 3D Point
*
*  Represents a 3D Point
*  Has x, y, and z positions as float
*/


@interface Point3D : NSObject <NSCoding> {
	float x, y, z;
}

@property float x;
@property float y;
@property float z;

+ (id) point;
+ (id) pointWithX:(float)x1 y:(float)y1 z:(float)z1;
+ (id) pointWithDictionary: (NSDictionary*) d;

-(id) init; // initiatize to origin
-(id) initWithValues:(float)x :(float)y :(float)z;
-(id) initWithPoint3D: (Point3D*)p;
-(id) initWithX:(float)x  y:(float)y  z:(float)z;
- (id)copyWithZone:(NSZone *)zone;

-(void) setPoint3D: (Point3D*)p;

-(void) add: (Point3D*)p;
-(void) subtract: (Point3D*)p;
-(void) multiply: (float)a;

-(NSMutableDictionary*) exportToXML;
-(id) initWithDictionary: (NSDictionary*)xml;

@end

@interface Point3D (N3GeometryAdditions)

+ (id)pointWithN3Vector:(N3Vector)vector;
- (id)initWithN3Vector:(N3Vector)vector;
- (N3Vector)N3VectorValue;

@end
