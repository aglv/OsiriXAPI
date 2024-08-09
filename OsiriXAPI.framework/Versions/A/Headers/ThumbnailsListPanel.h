/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <AppKit/AppKit.h>
#import "ViewerController.h"

@class ThumbnailCell;

@interface ThumbnailsListPanel : NSWindowController
{	
	NSScrollView            *thumbnailsView;
	long					screen;
	ViewerController		*viewer;
	BOOL					dontReenter;
    NSTrackingArea *trackingArea;
    ThumbnailCell *mouseOverCell;
    DicomSeries *mouseOverSeries;
}

@property (readonly) ViewerController *viewer;
@property (retain) NSTrackingArea *trackingArea;
@property (retain) ThumbnailCell *mouseOverCell;
@property (retain) DicomSeries *mouseOverSeries;

+ (long) fixedWidth;
+ (void) updateTrackingCells;
+ (void) checkScreenParameters;

- (void) setThumbnailsView :(NSScrollView*) tb viewer:(ViewerController*) v;
- (void) thumbnailsListWillClose :(NSScrollView*) tb;
- (id)initForScreen: (long) s;
- (NSView*) thumbnailsView;

@end
