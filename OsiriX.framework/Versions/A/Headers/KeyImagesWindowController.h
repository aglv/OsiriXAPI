/*=========================================================================
 Program:   OsiriX
 
 Copyright (c) OsiriX Team
 All rights reserved.
 Distributed under GNU - LGPL
 
 See http://www.osirix-viewer.com/copyright.html for details.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.
 =========================================================================*/

#import <Cocoa/Cocoa.h>
#import "ViewerController.h"

__deprecated_msg("only in OsiriX")
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

@end
