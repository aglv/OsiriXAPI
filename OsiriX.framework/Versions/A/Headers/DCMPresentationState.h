/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>
#import "DCMObject.h"

/** DCMObject category for dealing with Presentation States */
@interface   DCMObject (DCMPresentationState) 

- (BOOL)isPresentationState;

//- (NSArray *)referencedImageSequenceForObject:(DCMObject *)object;

- (NSArray *)graphicObjectSequence;
- (NSArray *)displayedAreaSelectionSequence;
- (NSArray *)graphicLayerSequence;
- (NSArray *)softcopyVOILUTSequence;
- (int)imageRotation;
- (BOOL)horizontalFlip;

// anchor Point
- (NSPoint)anchorPointForGraphicsObject:(DCMObject *)object;
- (BOOL)anchorPointVisibiltyForGraphicsObject:(DCMObject *)object;
- (BOOL)anchorPointAnnotationUnitsIsPixelForGraphicsObject:(DCMObject *)object;

//BoundingBox
- (NSPoint)boundingBoxTopLeftHandCornerForObject:(DCMObject *)object;
- (NSPoint)boundingBoxBottomRightHandCornerForObject:(DCMObject *)object;

/**Justification Values
*	LEFT
*	RIGHT
*	CENTER
*/
- (NSString *)boundingBoxTextHorizontalJustificationForObject:(DCMObject *)object;


//** graphic annotation sequence info */
- (NSArray *)graphicAnnotationSequence;
- (NSArray *)textObjectSequenceForObject:(DCMObject *)object;
- (NSArray *)graphicObjectSequenceForObject:(DCMObject *)object;
- (NSString *)unformattedTextValueForObject:(DCMObject *)object;
- (int)numberOfGraphicPointsForGraphicsObject:(DCMObject *)object;
- (NSArray *)graphicDataForGraphicsObject:(DCMObject *)object;

//graphic layer module attributes
// do nothing for now.

/** DICOM graphic types
* POINT 
* POLYLINE 
* INTERPOLATED 
* CIRCLE 
* ELLIPSE 
*/
- (NSString *)graphicTypeForGraphicsObject:(DCMObject *)object;
- (BOOL)graphicFilledForGraphicsObject:(DCMObject *)object;

//MODALITY LUT MODULE ATTRIBUTES 
/*
rescaleSlope
rescaleintercpet
LUT Data
Modality LUT Type
*/

//VOI LUT module 
/*
LUT Descriptor 
LUTData
windowCenter
windowWidth
*/





@end
