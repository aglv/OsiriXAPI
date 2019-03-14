/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <AppKit/AppKit.h>
#import "ROI.h"

/** \brief Window Controller for histogram display */

@interface ROI3DSettingsWindow : NSWindowController {
    IBOutlet NSPopover *popoverPeak, *popoverIso;
    NSColor *isoContourColor, *peakValueColor;
}

@property (retain, nonatomic) NSColor *isoContourColor, *peakValueColor;
@property (retain) NSSliderTouchBarItem *isoContourMinTouchBarItem, *isoContourMaxTouchBarItem;

- (IBAction)togglePopover:(NSButton*)sender;
- (id) init;

-(float) minValueOfSeries;
-(float) maxValueOfSeries;

@end
