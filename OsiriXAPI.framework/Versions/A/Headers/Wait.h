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


@class SendController;

/** \brief Window Controller for the Wait Panel */
@interface Wait : NSWindowController <NSWindowDelegate>
{
    IBOutlet NSProgressIndicator *progress;
	IBOutlet NSTextField		 *text, *elapsed;
	IBOutlet NSButton			 *abort;
	
	NSTimeInterval startTime;
	BOOL	cancel, aborted;
	NSTimeInterval lastTimeFrame, lastTimeFrameUpdate, firstTime, displayedTime;
    IOPMAssertionID assertionID;
    
    NSRect windowFrameRect;
    BOOL closed, ticktack;
    
    NSTimeInterval lastDisplay;
}
+ (Wait*) showWithString: (NSString*) str;
+ (Wait*) showWithString: (NSString*) str maxProgress: (int) maxValue showCancel: (BOOL) showCancel;

- (void)incrementBy:(double)delta;
- (void)increment;
- (NSProgressIndicator*) progress;
- (id) initWithString:(NSString*) str;
- (BOOL) aborted;
- (IBAction) abortButton: (id) sender;
- (void) setCancel :(BOOL) val;
- (void) setElapsedString :(NSString*) str;
@end
