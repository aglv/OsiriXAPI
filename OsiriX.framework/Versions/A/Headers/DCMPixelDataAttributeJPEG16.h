/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>
#import "DCMPixelDataAttribute.h"



@interface DCMPixelDataAttribute (DCMPixelDataAttributeJPEG16) 

- (NSData *)convertJPEG16ToHost:(NSData *)jpegData;

@end
