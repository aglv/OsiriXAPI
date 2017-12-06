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
#import "DCMView.h"

#define THUMBNAILSIZE 160

@class DicomStudy, DicomImage;

/** \brief  Core Data Entity for a Series */

@interface DicomSeries : NSManagedObject
{
	NSNumber	*dicomTime;
    NSImage     *thumbnailImage;
    NSArray     *imagesWithROIsCache __deprecated_msg("only in OsiriX");
    int         latestDistantNumberOfImages __deprecated_msg("only in OsiriX");
}

@property(nonatomic, retain, readonly) NSNumber* dicomTime;

@property(nonatomic, retain) NSString* comment;
@property(nonatomic, retain) NSString* comment2;
@property(nonatomic, retain) NSString* comment3;
@property(nonatomic, retain) NSString* comment4;
@property(nonatomic, retain) NSDate* date;
@property(nonatomic, retain) NSDate* dateAdded;
@property(nonatomic, retain) NSDate* dateOpened;
@property(nonatomic, retain) NSNumber* displayStyle;
@property(nonatomic, retain) NSNumber* id;
@property(nonatomic, retain) NSString* modality;
@property(nonatomic, retain) NSNumber* mountedVolume __deprecated;
@property(nonatomic, retain) NSString* name;
@property(nonatomic, retain) NSNumber* numberOfImages;
@property(nonatomic, retain) NSNumber* numberOfKeyImages;
@property(nonatomic, retain) NSNumber* rotationAngle;
@property(nonatomic, retain) NSNumber* scale;
@property(nonatomic, retain) NSNumber* hasROIs __deprecated_msg("only in OsiriX");
@property(nonatomic, retain) NSNumber* hasKeyImages __deprecated_msg("only in OsiriX");
@property(nonatomic, retain) NSString* seriesDescription;
@property(nonatomic, retain) NSString* seriesDICOMUID;
@property(nonatomic, retain) NSString* seriesInstanceUID;
@property(nonatomic, retain) NSString* seriesSOPClassUID;
@property(nonatomic, retain) NSNumber* stateText;
@property(nonatomic, retain) NSData* thumbnail;
@property(nonatomic, retain) NSNumber* windowLevel;
@property(nonatomic, retain) NSNumber* windowWidth;
@property(nonatomic, retain) NSNumber* xFlipped;
@property(nonatomic, retain) NSNumber* xOffset;
@property(nonatomic, retain) NSNumber* yFlipped;
@property(nonatomic, retain) NSNumber* yOffset;
@property(nonatomic, retain) NSSet* images;
@property(nonatomic, retain) DicomStudy* study;
@property int latestDistantNumberOfImages;

- (int) multiframesNumber;
- (NSSet*) paths;
- (NSSet*) keyImages;
- (NSArray*) sortedKeyImages;
- (NSArray*) sortedImages;
- (NSInteger) firstKeyOrROIImage;
- (NSInteger) lastKeyOrROIImage;
- (NSInteger) nextKeyOrROIImageTo: (NSInteger) index;
- (NSInteger) nextKeyOrROIImageTo: (NSInteger) index forward: (BOOL) forward;
- (NSComparisonResult) compareName:(DicomSeries*)series;
- (NSNumber*) noFilesExcludingMultiFrames;
- (NSNumber*) rawNoFiles;
- (DicomSeries*) previousSeries;
- (DicomSeries*) nextSeries;
- (NSArray*) sortDescriptorsForImages;
+ (NSArray*) sortDescriptorsForImages;
- (NSString*) uniqueFilename;
- (BOOL) isDistant;
+ (void) recomputeLocalizersSeriesInstanceUIDForStudies: (NSSet*) studiesSet;
- (NSString*) type;
- (NSImage*) thumbnailImage;
- (NSString*) ROIsDescription;
- (NSArray*) imagesWithROIs __deprecated_msg("only in OsiriX");
- (void) purgeCaches __deprecated_msg("only in OsiriX");
- (NSArray*) imagesAsScreenCapture __deprecated_msg("only in OsiriX");
- (NSArray*) imagesAsScreenCapture:(NSRect)frame __deprecated_msg("only in OsiriX");
- (NSArray*) imagesAsScreenCapture:(NSRect)frame dicomImages:(NSArray*) dcmImages __deprecated_msg("only in OsiriX");
- (NSArray*) imagesAsScreenCapture:(NSRect)frame dicomImages:(NSArray*) dcmImages annotationsLevel: (annotationsLevel) annotationsLevel __deprecated_msg("only in OsiriX");
+ (NSRect) frameForImageAsScreenCapture __deprecated_msg("only in OsiriX");
@end

@interface DicomSeries (CoreDataGeneratedAccessors)

- (NSArray*) presentationStates;
- (void) addImagesObject:(DicomImage *)value;
- (void) removeImagesObject:(DicomImage *)value;
- (void) addImages:(NSSet *)value;
- (void) removeImages:(NSSet *)value;
- (void) applyPresentationState;
- (NSString*) callingAET;
- (NSString*) calledAET;
- (NSString *) hostname;
@end
