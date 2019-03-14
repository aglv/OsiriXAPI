/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
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
- (void) queryChildrenAtIMAGELevel;

@end
#endif
