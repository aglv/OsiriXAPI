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
#import <IOKit/pwr_mgt/IOPMLib.h>

/** \brief Window Controller for Wait rendering */
@interface WaitRendering : NSWindowController <NSWindowDelegate>
{
    IBOutlet NSProgressIndicator *progress;
	IBOutlet NSButton		     *abort;
	IBOutlet NSTextField		 *message, *currentTimeText, *lastTimeText;
	
    NSRect                      windowFrameRect;
	NSString					*string;
	NSTimeInterval				lastDuration, lastTimeFrame;
	NSTimeInterval              startTime;
	
	BOOL						aborted, eventsClear;
	volatile BOOL				stop;
	BOOL						supportCancel;
	
	id							cancelDelegate;
	
	NSTimeInterval				displayedTime;
    
    IOPMAssertionID assertionID;
    
    BOOL closed, ticktack;
    
    NSTimeInterval lastDisplay;
}

@property (retain, nonatomic) NSString *string;

+(id) showWithString:(NSString*) str cancel:(BOOL) cancel;

- (id) init:(NSString*) s;
- (id) initWithString:(NSString*) str;
- (BOOL) run;
- (void) start __deprecated;
- (BOOL) started;
- (void) end;
- (IBAction) abort:(id) sender;
- (void) setCancel :(BOOL) val;
- (BOOL) aborted;
- (void) setCancelDelegate:(id) object;
- (void) resetLastDuration;
@end
