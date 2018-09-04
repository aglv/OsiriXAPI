/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>


@interface Installer : NSWindowController <NSApplicationDelegate>
{
	IBOutlet	NSTextField		*regKey;
    IBOutlet    NSTextField     *previousRegKey;
    IBOutlet    NSWindow        *license;
    NSAttributedString *licenseText;
    
    IBOutlet NSWindow *previousKeyWindow;
    IBOutlet NSPanel *installingPanel;
    
    NSString *previousKey, *windowTitle, *installText, *pleaseWaitText;
}

@property (readonly) NSAttributedString *licenseText;
@property (retain) NSString *previousKey;
@property (readonly) NSString *windowTitle, *installText, *pleaseWaitText;

- (IBAction) install:(id) sender;
- (IBAction) cancelModal:(id)sender;
- (IBAction) okModal:(id)sender;
- (IBAction) saveModal:(id)sender;

+ (NSString*) installWithRegKey: (NSString*) reg previousKey: (NSString*) previousKey noGUI: (BOOL) noGUI windowController: (Installer*) windowController;
@end
