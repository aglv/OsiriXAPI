/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

/** \brief Converts DICOM string  to NSString */

#import <Cocoa/Cocoa.h>

@interface NSString  (DICOMToNSString)

- (id) initWithCString:(const char *)cString  DICOMEncoding:(NSString *)encoding;
+ (id) stringWithCString:(const char *)cString  DICOMEncoding:(NSString *)encoding;
+ (NSStringEncoding)encodingForDICOMCharacterSet:(NSString *)characterSet;


@end
