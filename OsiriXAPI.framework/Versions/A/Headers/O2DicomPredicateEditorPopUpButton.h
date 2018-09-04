/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

@interface O2DicomPredicateEditorPopUpButton : NSPopUpButton {
    NSMenu* _contextualMenu;
	NSString* _noSelectionLabel;
    NSWindow* _menuWindow;
    BOOL _n2mode;
}

@property(retain) NSMenu* contextualMenu;
@property(retain,nonatomic) NSString* noSelectionLabel;
@property BOOL n2mode;

@end
