/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>
#import "DCMPixelDataAttribute.h"



@interface DCMPixelDataAttribute (DCMPixelDataAttributeJPEG12)  

- (NSData *)convertJPEG12ToHost:(NSData *)jpegData;
//- (NSMutableData *)compressJPEG12:(NSMutableData *)data  compressionSyntax:(DCMTransferSyntax *)compressionSyntax  quality:(float)quality;

@end
