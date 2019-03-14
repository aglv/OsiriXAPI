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

 
@interface DCMPixelDataAttribute (DCMPixelDataAttributeJPEG8)

- (NSMutableData *)convertJPEG8LosslessToHost:(NSData *)jpegData;
- (NSMutableData *)compressJPEG8:(NSMutableData *)data  compressionSyntax:(DCMTransferSyntax *)compressionSyntax quality:(float)quality;


@end
