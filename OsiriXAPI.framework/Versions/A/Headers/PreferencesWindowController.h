/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import <Cocoa/Cocoa.h>
#import <PreferencePanes/NSPreferencePane.h>
#import "SFAuthorizationView+OsiriX.h"


@class PreferencesView, PreferencesWindowContext;


/** \brief Window Controller for Preferences */
@interface PreferencesWindowController : NSWindowController <NSWindowDelegate>
{
	IBOutlet NSScrollView* scrollView;
	IBOutlet PreferencesView* panesListView;
	IBOutlet NSButton* authButton;
	IBOutlet SFAuthorizationView* authView;
	PreferencesWindowContext* currentContext;
	NSMutableArray* animations;
	IBOutlet NSView* flippedDocumentView;
    NSSize paneListSize, windowSize;
}

@property(readonly) NSMutableArray* animations;
@property(readonly) SFAuthorizationView* authView;

+ (PreferencesWindowController*) sharedPreferencesWindowController;
+(void) addPluginPaneWithResourceNamed:(NSString*)resourceName inBundle:(NSBundle*)parentBundle withTitle:(NSString*)title image:(NSImage*)image;
+(void) removePluginPaneWithBundle:(NSBundle*)parentBundle;

-(BOOL)isUnlocked;

-(IBAction)showAllAction:(id)sender;
-(IBAction)navigationAction:(id)sender;
-(IBAction)authAction:(id)sender;

-(void)reopenDatabase;
-(void)setCurrentContextWithResourceName: (NSString*) name;
-(void)setCurrentContext:(PreferencesWindowContext*)context;
@end


@interface PreferencesWindowContext : NSObject {
	NSString* _title;
	NSBundle* _parentBundle;
	NSString* _resourceName;
	NSPreferencePane* _pane;
}

@property(retain) NSString* title;
@property(retain) NSBundle* parentBundle;
@property(retain) NSString* resourceName;
@property(nonatomic, retain) NSPreferencePane* pane;

-(id)initWithTitle:(NSString*)title withResourceNamed:(NSString*)resourceName inBundle:(NSBundle*)parentBundle;

@end
