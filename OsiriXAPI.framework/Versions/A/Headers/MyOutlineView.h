/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import <Cocoa/Cocoa.h>
#import "OSIOutlineView.h"

@class DatabaseOverWindow;

/** \brief OutlineView for BrowserController */
@interface MyOutlineView : OSIOutlineView
{
    NSInteger mouseRow;
    DatabaseOverWindow *thumbnailWindow;
    id previousItem;
    NSTimeInterval faderCreationTime;
}
@property (retain) NSTimer *faderTimer;
@property (readonly) NSInteger mouseRow;

- (void)hideAllColumns;
- (BOOL)isColumnWithIdentifierVisible:(id)identifier;
- (void)setColumnWithIdentifier:(id)identifier visible:(BOOL)visible;
- (void)setColumnWithIdentifier:(id)identifier visible:(BOOL)visible position: (int) position;
- (void)restoreColumnState:(NSObject *)columnState;
- (NSObject<NSCoding>*)columnState;

@end
