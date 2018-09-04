/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import "DCMValueRepresentation.h"
#import "DCMAttributeTag.h"
#import "DCMAttribute.h"
#import "DCMSequenceAttribute.h"
#import "DCMDataContainer.h"
#import "DCMObject.h"
#import "DCMTransferSyntax.h"
#import "DCMTagDictionary.h"
#import "DCMTagForNameDictionary.h"
#import "DCMCharacterSet.h"
#import "DCMPixelDataAttribute.h"
#import "DCMCalendarDate.h"
#import "DCMLimitedObject.h"
#import "DCMNetServiceDelegate.h"
#import "DCMEncapsulatedPDF.h"

#define DCMDEBUG 0
#define DCMFramework_compile YES

#import <Accelerate/Accelerate.h>

typedef enum DCM_CompressionQuality_ {DCMLosslessQuality = 0, DCMHighQuality, DCMMediumQuality, DCMLowQuality} DCM_CompressionQuality;


@protocol MoveStatusProtocol
	- (void)setStatus:(unsigned short)moveStatus  numberSent:(int)numberSent numberError:(int)numberErrors;
@end


