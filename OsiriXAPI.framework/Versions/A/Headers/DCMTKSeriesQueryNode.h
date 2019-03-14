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
#import "DCMTKStudyQueryNode.h"

#ifndef OSIRIX_LIGHT
/** \brief Series level DCMTKQueryNode */
@interface DCMTKSeriesQueryNode : DCMTKQueryNode <NSCopying>
{
	NSString *_studyInstanceUID, *_seriesNumber;
    DCMTKStudyQueryNode *study;
}

@property (assign) DCMTKStudyQueryNode *study;

- (NSString*) studyInstanceUID;
- (NSString*) seriesInstanceUID;
- (NSString*) seriesDescription;
- (NSString*) seriesDICOMUID;

@end
#endif
