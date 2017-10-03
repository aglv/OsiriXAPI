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
#import "DCMTKQueryNode.h"

#ifndef OSIRIX_LIGHT
/** \brief Study level DCMTKQueryNode */
@interface DCMTKStudyQueryNode : DCMTKQueryNode {
    BOOL _sortChildren;
    BOOL isHidden;
    
    NSString *_studyID;
}

- (NSString*) patientUID;
- (NSNumber*) stateText;
- (NSString*) studyID;
- (NSString*) studyInstanceUID;// Match DicomStudy
- (NSString*) studyName;// Match DicomStudy
- (NSNumber*) numberOfImages;// Match DicomStudy
- (NSDate*) dateOfBirth; // Match DicomStudy
- (NSNumber*) noFiles; // Match DicomStudy
- (BOOL) isHidden;
- (void) setHidden: (BOOL) h;
@end
#endif
