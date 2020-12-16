/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>
#import "DCMObject.h"

/** Category of DCMObject for creating DICOM encapsulated PDFs */
@interface   DCMObject (DCMEncapsulatedPDF) 


/** Encapsulates a pdf in a DICOM file */
+ (DCMObject*) encapsulatedPDF:(NSData *)pdf;
+ (DCMObject*) encapsulatedSTL:(NSData *)stl;

@end
