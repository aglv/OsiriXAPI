/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import "DCMPix.h"

@interface DCMPix (DCMPix_DCMTK)

- (BOOL) isHologicTomosynthesis;
- (void*) readHologicTomosynthesis: (int) frame;

@end
