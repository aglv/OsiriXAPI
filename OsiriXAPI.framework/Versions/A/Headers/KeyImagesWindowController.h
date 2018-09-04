/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>
#import "ViewerController.h"

@interface KeyImagesWindowController : NSWindowController
{
    IBOutlet NSScrollView *scrollView;
    IBOutlet NSMatrix *matrix;
    NSArray *previousThumbnails;
    ViewerController *viewer;
    int previousIndex;
    NSString *previousStudyInstanceUID;
    BOOL hidden;
}

@property (retain) ViewerController *viewer;
@property (retain) NSString *previousStudyInstanceUID;

- (id) initForViewer:(ViewerController*) v;
- (BOOL) buildThumbnailMatrix;
- (BOOL) isVisible;

@end
