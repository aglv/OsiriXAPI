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

@interface O2ViewerThumbnailsMatrix : NSMatrix {
    NSPoint draggingStartingPoint;
    NSTimeInterval doubleClick;
    NSCell *doubleClickCell;
}

@end

@interface O2ViewerThumbnailsMatrixRepresentedObject : NSObject {
    id _object;
    NSArray* _children;
    int curStudyIndexAll;
}

@property(retain) id object;
@property(retain) NSArray* children;
@property int curStudyIndexAll;

+ (id)object:(id)object __deprecated;
+ (id)object:(id)object children:(NSArray*)children studyIndex: (int) sI;

@end
