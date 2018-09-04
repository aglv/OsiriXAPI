/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import <Cocoa/Cocoa.h>
#import "DCMObject.h"

@interface DCMLimitedObject : DCMObject {

}
+ (id)objectWithData:(NSData *)data lastGroup:(unsigned short)lastGroup;
+ (id)objectWithContentsOfFile:(NSString *)file lastGroup:(unsigned short)lastGroup;
+ (id)objectWithContentsOfURL:(NSURL *)aURL lastGroup:(unsigned short)lastGroup;

- (id)initWithData:(NSData *)data lastGroup:(unsigned short)lastGroup;
- (id)initWithContentsOfFile:(NSString *)file lastGroup:(unsigned short)lastGroup;
- (id)initWithContentsOfURL:(NSURL *)aURL lastGroup:(unsigned short)lastGroup;
- (id)initWithDataContainer:(DCMDataContainer *)data lengthToRead:(int)lengthToRead byteOffset:(int*)byteOffset characterSet:(DCMCharacterSet *)characterSet lastGroup:(unsigned short)lastGroup;

- (int)readDataSet:(DCMDataContainer *)dicomData toGroup:(unsigned short)lastGroup byteOffset:(int *)byteOffset;

@end
