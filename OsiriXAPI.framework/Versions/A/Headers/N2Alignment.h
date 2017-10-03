/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See https://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/


#import <Cocoa/Cocoa.h>

typedef uint8_t N2Alignment;

#ifdef  __cplusplus
extern "C" {
#endif

extern const N2Alignment N2Top;
extern const N2Alignment N2Bottom;
extern const N2Alignment N2Left;
extern const N2Alignment N2Right;

extern NSRect NSRectCenteredInRect(NSRect r, NSRect r2);
extern NSRect NSRectCenteredAndScaledInRect(NSRect smallRect, NSRect bigRect);

#ifdef  __cplusplus
}
#endif
