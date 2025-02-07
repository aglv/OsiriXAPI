/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <OpenGL/glu.h>
#include <OpenGL/CGLMacro.h>
#include <OpenGL/CGLCurrent.h>
#include <OpenGL/CGLContext.h>
#import "N3Geometry.h"
#import "NSFont_OpenGL.h"
#import "ROI.h"


#define MINIMUM_WW 0.00001
#define STAT_UPDATE					0.6f
#define IMAGE_COUNT					1
#define IMAGE_DEPTH					32
#define NSRectCenter(r) NSMakePoint(r.origin.x+r.size.width/2, r.origin.y+r.size.height/2)

// Tools.

extern NSString *pasteBoardOsiriX;
extern NSString *pasteBoardOsiriXPlugin;
extern NSString *OsirixPluginPboardUTI;
extern int CLUTBARS, ANNOTATIONS, SOFTWAREINTERPOLATION_MAX, DISPLAYCROSSREFERENCELINES;
extern int intersect3D_SegmentPlane( float *P0, float *P1, float *Pnormal, float *Ppoint, float* resultPt);

typedef enum { annotNone = 0, annotGraphics, annotBase, annotFull} annotationsLevel;
typedef enum { barHide = 0, barOrigin, barFused, barBoth} CLUTBarMode;
typedef enum { syncroOFF = 0, syncroABS = 1, syncroREL = 2, syncroLOC = 3, syncroRatio = 4} SyncMode;

typedef enum {DCMViewTextAlignLeft, DCMViewTextAlignCenter, DCMViewTextAlignRight} DCMViewTextAlign;
typedef enum {NoInterpolation = 0, BiLinear = 1, Lanczos5 = 2, BSplineBicubic = 3} InterpolationMode;

@class GLString;
@class DCMPix;
@class DCMView;
@class ROI;
@class OrthogonalMPRController;
@class DICOMExport;
@class DicomImage, DicomSeries, DicomStudy;
@class DCMObject;
@class ViewerController;

@interface DCMExportPlugin: NSObject
- (void) finalize:(DCMObject*) dcmDst withSourceObject:(DCMObject*) dcmObject;
- (NSString*) seriesName;
@end

/** \brief Image/Frame View for ViewerController */

@interface DCMView: NSOpenGLView
{
	NSInteger		_imageRows;
	NSInteger		_imageColumns;
	NSInteger		_tag;

	BOOL			flippedData;
    BOOL            whiteBackground;
	
	NSString		*yearOld;
	
	ROI				*curROI;
	int				volumicData, areDCMPixParallel;
	BOOL			drawingROI, noScale, mouseDraggedForROIUndo;
	DCMView			*blendingView;
	float			blendingFactor, blendingFactorStart;
	BOOL			colorTransfer;
	unsigned char   *colorBuf, *blendingColorBuf;
	unsigned char   alphaTable[256], opaqueTable[256], redTable[256], greenTable[256], blueTable[256];
	float			redFactor, greenFactor, blueFactor;
	long			blendingMode;
	
	float			sliceFromTo[ 2][ 3], sliceFromToS[ 2][ 3], sliceFromToE[ 2][ 3], sliceFromTo2[ 2][ 3], sliceFromToThickness;
	
	float			sliceVector[ 3];
	float			slicePoint3D[ 3];
	float			syncRelativeDiff;
	long			syncSeriesIndex;
	
	float			mprVector[ 3], mprPoint[ 3];
    
    NSTimeInterval  timeIntervalForDrag, mouseDownStart;
	
	short			thickSlabMode, thickSlabStacks;
	
	NSMutableArray	*rectArray;
	
    NSMutableArray<DCMPix*> *dcmPixList;
    NSArray			*dcmFilesList;
	NSMutableArray  *dcmRoiList, *curRoiList;
    DCMPix			*curDCM;
	DCMExportPlugin	*dcmExportPlugin;
	
    char            listType;
    
    short           curImage, startImage, previousRGB;
    float           previousBWWW, previousBWWL;
    float           previousRGBWW, previousRGBWL;
    
    ToolMode        currentTool, currentToolRight, currentMouseEventTool;
    
	BOOL			mouseDragging;
	BOOL			suppress_labels; // keep from drawing the labels when command+shift is pressed

    NSPoint         start, originStart, previous;
	
    float			startWW, curWW, startMin, startMax;
    float			startWL, curWL;

    float			bdstartWW, bdcurWW, bdstartMin, bdstartMax;
    float			bdstartWL, bdcurWL;
	
	BOOL			curWLWWSUVConverted;
	float			curWLWWSUVFactor;
	
    NSSize          scaleStart, scaleInit;
    
	double			resizeTotal;
    float           scaleValue, startScaleValue;
    float           rotation, rotationStart;
    NSPoint			origin;
	short			crossMove;
    
    NSMatrix        *matrix;
    
    long            count;
	
    BOOL            xFlipped, yFlipped;

    float           fontSize, labelFontSize, labelFontHeight;
	long			fontListGLSize[ FONTGLSIZE + ' '];
	long			labelFontListGLSize[ FONTGLSIZE + ' '];
	NSSize			stringSize;
	NSFont			*labelFont;
	NSFont			*fontGL;
	NSColor			*fontColor;
    GLuint          fontListGL;
	GLuint          labelFontListGL;
	float			fontRasterY;
    
	NSString		*stringID;
	NSSize			previousViewSize;

	float			contextualMenuInWindowPosX;
	float			contextualMenuInWindowPosY;	

	
	float			mouseXPos, mouseYPos;
    BOOL            mouseOnImage, mouseOnView, blendingMouseOnImage;
	float			pixelMouseValue;
	long			pixelMouseValueR, pixelMouseValueG, pixelMouseValueB;
    
	float			blendingMouseXPos, blendingMouseYPos;
	float			blendingPixelMouseValue;
	long			blendingPixelMouseValueR, blendingPixelMouseValueG, blendingPixelMouseValueB;
	
    long			textureX, blendingTextureX;
    long			textureY, blendingTextureY;
    GLuint			* pTextureName;
	GLuint			* blendingTextureName;
    long			textureWidth, blendingTextureWidth;
    long			textureHeight, blendingTextureHeight;
    
	BOOL			f_ext_texture_rectangle; // is texture rectangle extension supported
	BOOL			f_ext_client_storage; // is client storage extension supported
	BOOL			f_ext_packed_pixel; // is packed pixel extension supported
	long			maxTextureSize; // the minimum max texture size across all GPUs
	long			maxNOPTDTextureSize; // the minimum max texture size across all GPUs that support non-power of two texture dimensions
	long			TEXTRECTMODE;
	
	BOOL			isKeyView; //needed for Image View subclass
	NSCursor		*cursor;
	
	BOOL			cursorSet;
	NSTrackingArea	*cursorTracking;
	int             trackPadNumberOfFingers;
    float           trackPadScaleAccumulator;
    BOOL            trackPadMoved;
    
	NSPoint			display2DPoint;
    int             display2DPointIndex;
	
	NSMutableDictionary	*stringTextureCache, *lowPriorityStringTextureCache;
	
	BOOL           _dragInProgress; // Are we drag and dropping
	NSTimer			*_mouseDownTimer; //Timer to check if mouseDown is Persisiting;
	NSTimer			*_rightMouseDownTimer; //Checking For Right hold
	NSImage			*destinationImage; //image will be dropping
	
	BOOL			_hasChanged, needToLoadTexture, showDescriptionInLarge;
	
	BOOL			scaleToFitNoReentry;
	
	GLString		*showDescriptionInLargeText, *flippedNotice, *ROIsHiddenNotice;
    float           previousScalingFactor;
	//Context for rendering to iChat
//	NSOpenGLContext *_alternateContext;
	
	BOOL			drawing;
	
	int				repulsorRadius;
	NSPoint			repulsorPosition;
	NSTimer			*repulsorColorTimer;
	float			repulsorAlpha, repulsorAlphaSign;
	BOOL			repulsorROIEdition;
	long            scrollMode;
	
	NSPoint			ROISelectorStartPoint, ROISelectorEndPoint;
	BOOL			selectorROIEdition;
	NSMutableArray	*ROISelectorSelectedROIList;
	
	BOOL			syncOnLocationImpossible, updateNotificationRunning;
	
	char			*resampledBaseAddr, *blendingResampledBaseAddr;
	BOOL			zoomIsSoftwareInterpolated, firstTimeDisplay;
	float           resampledScale;
	int				resampledBaseAddrSize, blendingResampledBaseAddrSize;
		
	// iChat
//	float			iChatWidth, iChatHeight;
//	unsigned char*	iChatCursorTextureBuffer;
//	GLuint			iChatCursorTextureName;
//	NSSize			iChatCursorImageSize;
//	NSPoint			iChatCursorHotSpot;
//	BOOL			iChatDrawing;
//	GLuint			iChatFontListGL;
//	NSFont			*iChatFontGL;
//	long			iChatFontListGLSize[ 256];
//	NSMutableDictionary	*iChatStringTextureCache;
//	NSSize			iChatStringSize;
	NSRect			drawingFrameRect, screenCaptureRect;
	
	BOOL			exceptionDisplayed;
	BOOL			COPYSETTINGSINSERIES;
	BOOL			is2DViewerCached, is2DViewerValue;
	
	BOOL lensTexture;
	
    BOOL cursorhidden;
	int avoidRecursiveSync;
	BOOL avoidMouseMovedRecursive;
	BOOL avoidChangeWLWWRecursive;
	BOOL TextureComputed32bitPipeline;
    
//    BOOL iChatRunning;
	
    GLuint lutTexture, lutProgram, transferTexture, opacityTexture;
    GLuint blendingLutTexture, blendingTransferTexture, blendingLutProgram;
    
    unsigned char *lutPointer, *blendingLutPointer;
    float *transferPointer, *blendingTransferPointer;
    
	NSImage *loupeImage, *loupeMaskImage;
	GLuint loupeTextureID, loupeTextureWidth, loupeTextureHeight;
	GLubyte *loupeTextureBuffer;
	GLuint loupeMaskTextureID, loupeMaskTextureWidth, loupeMaskTextureHeight;
	GLubyte *loupeMaskTextureBuffer;
	float studyColorR, studyColorG, studyColorB;
    NSUInteger studyDateIndex;
//	LoupeController *loupeController;
    
    GLString *studyDateBox;
    
    annotationsLevel annotationType;
    
    NSArray *cleanedOutDcmPixArray;
    
    NSTimeInterval firstDisplay;
    
    NSString *mousePosUSRegion;
    
    BOOL stickToCenter;
    
    // SeriesLevel
    NSNumber *scaleSeriesToSave, *rotationAngleSeriesToSave, *displayStyleSeriesToSave, *yFlippedSeriesToSave, *xFlippedSeriesToSave;
    NSNumber *xOffsetSeriesToSave, *yOffsetSeriesToSave, *windowWidthSeriesToSave, *windowLevelSeriesToSave;
    id seriesToSave;
    
    // Image Level
    NSNumber *scaleToSave, *rotationAngleToSave, *xOffsetToSave, *yOffsetToSave;
    NSNumber *windowWidthToSave, *windowLevelToSave, *yFlippedToSave, *xFlippedToSave;
    id imageToSave;
    BOOL savedImageParameters, dontSaveImageParameters;
    NSTimeInterval lastBecomeMainWindowTime;
    
    BOOL flippedRendered;
    
#define PBO_COUNT 2
    BOOL pboInitialized;
    GLuint pboIds[ PBO_COUNT];
    unsigned long pboSize;
    int pboIndex;
    
    BOOL sliderDragging;
    BOOL resliceViewDisplayed, displayResliceView;
    float resliceViewSize, resliceViewSizeFactor;
    float *resliceTexture;
    BOOL resliceTextureIsRGBA;
    GLuint resliceTextureID;
    BOOL resliceDirectionIsWidth;
    int resliceTextureWidth, resliceTextureHeight, resliceTexturePosition, resliceFlippedVertically;
    float resliceTexturePixelRatio;
    BOOL displayResliceIndex, mouseDownInResliceView;
    
    NSTimeInterval lastLensShiftPressed;
    BOOL persitentLensMode;
    
    BOOL mouseDownInOpenGLSlider;
    float openGLSliderOffsetClick;
    
    NSMutableArray *texturesToDelete;
    
    BOOL wasScaledToFit;
}

@property BOOL flippedRendered, displayResliceView;
@property (readonly) BOOL needToLoadTexture;
@property (nonatomic) BOOL resliceViewDisplayed;
@property float resliceViewSizeFactor, labelFontSize, labelFontHeight;
@property(retain) NSNumber *scaleToSave, *rotationAngleToSave, *xOffsetToSave, *yOffsetToSave, *yFlippedToSave, *xFlippedToSave, *windowWidthToSave, *windowLevelToSave;
@property(retain) NSNumber *scaleSeriesToSave, *rotationAngleSeriesToSave, *displayStyleSeriesToSave, *yFlippedSeriesToSave, *xFlippedSeriesToSave, *xOffsetSeriesToSave, *yOffsetSeriesToSave, *windowWidthSeriesToSave, *windowLevelSeriesToSave;
@property NSRect drawingFrameRect;
@property(retain) NSArray *cleanedOutDcmPixArray;
@property(readonly) NSMutableArray *rectArray, *curRoiList;
@property BOOL COPYSETTINGSINSERIES, flippedData, showDescriptionInLarge, syncOnLocationImpossible, colorTransfer, stickToCenter, dontSaveImageParameters, wasScaledToFit;
@property(nonatomic) BOOL whiteBackground;
@property(retain) NSMutableArray<DCMPix*> *dcmPixList;
@property(retain) NSMutableArray<NSMutableArray*> *dcmRoiList;
@property(retain) NSArray *dcmFilesList;
@property long syncSeriesIndex;
@property(nonatomic) float syncRelativeDiff, studyColorR, studyColorG, studyColorB;
@property(nonatomic) NSPoint offsetOrigin;
@property(nonatomic) long blendingMode;
@property(nonatomic) NSUInteger studyDateIndex;
@property(retain,setter=setBlending:) DCMView *blendingView;
@property(readonly) float blendingFactor;
@property(nonatomic) BOOL xFlipped, yFlipped;
@property(retain) NSString *stringID, *mousePosUSRegion;
@property(nonatomic) ToolMode currentTool;
@property(setter=setRightTool:) ToolMode currentToolRight;
@property(readonly) short curImage;
@property(retain) NSMatrix *theMatrix;
@property(readonly) BOOL suppressLabels;
@property(nonatomic) float scaleValue, rotation;
@property(nonatomic) NSPoint origin;
@property(readonly) double pixelSpacing, pixelSpacingX, pixelSpacingY;
@property(readonly) DCMPix *curDCM;
@property(retain) DCMExportPlugin *dcmExportPlugin;
@property(readonly) float mouseXPos, mouseYPos;
@property(readonly) float contextualMenuInWindowPosX, contextualMenuInWindowPosY;
@property(readonly) GLuint fontListGL;
@property(readonly) NSFont *fontGL;
@property NSInteger tag;
@property(readonly) float curWW, curWL;
@property NSInteger rows, columns;
@property(readonly) NSCursor *cursor;
@property BOOL drawing;
@property (readonly) BOOL volumicSeries;
@property (nonatomic) NSTimeInterval timeIntervalForDrag;
@property(readonly) BOOL isKeyView, mouseDragging;
@property annotationsLevel annotationType;
@property(readonly) int volumicData;
@property short thickSlabStacks;

+ (CGFloat) getDeltaY: (CGFloat) deltaY event: (NSEvent*) theEvent;
+ (void) setDontListenToSyncMessage: (BOOL) v;
+ (BOOL) noPropagateSettingsInSeriesForModality: (DicomImage*) imageObj;
+ (void) purgeStringTextureCache;
+ (void) setDefaults;
+ (void) setCLUTBARS:(CLUTBarMode) c ANNOTATIONS:(annotationsLevel) a;
+ (void)setPluginOverridesMouse: (BOOL)override DEPRECATED_ATTRIBUTE;
+ (void) computePETBlendingCLUT;
+ (void) computePETBlendingCLUT: (NSString*) clutName;
+ (NSString*) findWLWWPreset: (float) wl :(float) ww :(DCMPix*) pix;
+ (NSSize)sizeOfString:(NSString *)string forFont:(NSFont *)font;
+ (long) lengthOfString:(unichar *) cstr length:(NSUInteger) l forFont:(long *)fontSizeArray;
+ (BOOL) intersectionBetweenTwoLinesA1:(NSPoint) a1 A2:(NSPoint) a2 B1:(NSPoint) b1 B2:(NSPoint) b2 result:(NSPoint*) r;
+ (float) Magnitude:( NSPoint) Point1 :(NSPoint) Point2;
+ (float) angleBetweenVector: (float*) v1 andVector: (float*) v2;
+ (double) angleBetweenVectorD: (double*) v1 andVectorD: (double*) v2;
+ (int) DistancePointLine: (NSPoint) Point :(NSPoint) startPoint :(NSPoint) endPoint :(float*) Distance;
+ (float) pbase_Plane: (float*) point :(float*) planeOrigin :(float*) planeVector :(float*) pointProjection;
+ (double) pbaseDouble_Plane: (double*) point :(double*) planeOrigin :(double*) planeVector :(double*) pointProjection;
+ (short)syncro;
+ (void)setSyncro:(short) s;
+ (DCMView*) viewUnderMouse;
//- (void) applyImageTransformation __deprecated;
- (void) loadOpenGLIdentityForDrawingFrame: (NSRect) r;
- (void) gClickCountSetReset;
- (void) applyROIWLWW;
+ (BOOL) getWL:(float*) wl WW:(float*) ww fromROIs:(NSArray*) rois;
- (int) findPlaneAndPoint:(float*) pt :(float*) location;
- (int) findPlaneForPoint:(float*) pt localPoint:(float*) location distanceWithPlane: (float*) distanceResult;
- (int) findPlaneForPoint:(float*) pt preferParallelTo:(float*)parto localPoint:(float*) location distanceWithPlane: (float*) distanceResult;
- (int) findPlaneForPoint:(float*) pt preferParallelTo:(float*)parto localPoint:(float*) location distanceWithPlane: (float*) distanceResult limitWithSliceThickness: (BOOL) limitWithSliceThickness;
- (unsigned char*) getRawPixels:(long*) width :(long*) height :(long*) spp :(long*) bpp :(BOOL) screenCapture :(BOOL) force8bits;

- (unsigned char*) getRawPixelsWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allTiles:(BOOL) allTiles allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing;
- (unsigned char*) getRawPixelsWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allTiles:(BOOL) allTiles allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned;
- (unsigned char*) getRawPixelsWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allTiles:(BOOL) allTiles allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned views: (NSArray*) views viewsRect: (NSArray*) rects;
- (unsigned char*) getRawPixelsWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allTiles:(BOOL) allTiles allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned limitResolution:(BOOL) limitResolution;
- (unsigned char*) getRawPixelsWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allTiles:(BOOL) allTiles allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned limitResolution:(BOOL) limitResolution alphaChannel:(BOOL) alphaChannel;

- (unsigned char*) getRawPixelsViewWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing;
- (unsigned char*) getRawPixelsViewWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned;
- (unsigned char*) getRawPixelsViewWidth:(long*) width height:(long*) height spp:(long*) spp bpp:(long*) bpp screenCapture:(BOOL) screenCapture force8bits:(BOOL) force8bits removeGraphical:(BOOL) removeGraphical squarePixels:(BOOL) squarePixels allowSmartCropping:(BOOL) allowSmartCropping origin:(float*) imOrigin spacing:(float*) imSpacing offset:(int*) offset isSigned:(BOOL*) isSigned limitResolution: (BOOL) limitResolution alphaChannel:(BOOL) alphaChannel;

- (void) blendingPropagate;
- (void) subtract:(DCMView*) bV;
- (void) subtract:(DCMView*) bV absolute:(BOOL) abs;
- (void) subtractDCMPix:(DCMPix*) pix absolute:(BOOL) abs;
- (void) multiply:(DCMView*) bV;
- (GLuint *) loadTextureIn:(GLuint *) texture blending:(BOOL) blending colorBuf: (unsigned char**) colorBufPtr textureX:(long*) tX textureY:(long*) tY redTable:(unsigned char*) rT greenTable:(unsigned char*) gT blueTable:(unsigned char*) bT textureWidth: (long*) tW textureHeight:(long*) tH resampledBaseAddr:(char**) rAddr resampledBaseAddrSize:(int*) rBAddrSize;
- (short)syncro;
- (void)setSyncro:(short) s;

// checks to see if tool is for ROIs.
+ (BOOL) isToolforROIs:(ToolMode)tool;
- (BOOL) roiTool:(long) tool;
- (void) prepareToRelease;
- (BOOL) orientationCorrectedToView:(float*) correctedOrientation;
#ifndef OSIRIX_LIGHT
- (N3AffineTransform)pixToSubDrawRectTransform; // converst points in DCMPix "Slice Coordinates" to coordinates that need to be passed to GL in subDrawRect
#endif
- (NSPoint) ConvertNSViewCenter2GL;
- (NSPoint) ConvertFromNSView2GL:(NSPoint) a;
- (NSPoint) ConvertFromView2GL:(NSPoint) a;
- (NSPoint) ConvertFromUpLeftView2GL:(NSPoint) a;
- (NSPoint) ConvertFromGL2View:(NSPoint) a;
- (NSPoint) ConvertFromGL2NSView:(NSPoint) a;
- (NSPoint) ConvertFromGL2Screen:(NSPoint) a;
- (NSPoint) ConvertFromGL2GL:(NSPoint) a toView:(DCMView*) otherView;
- (NSRect) smartCrop;
- (void) setWLWW:(float) wl :(float) ww;
- (void) setWLWW:(float) wl :(float) ww saveChanges:(BOOL) saveChanges;
- (void) getWLWW:(float*) wl :(float*) ww;
- (void) getThickSlabThickness:(float*) thickness location:(float*) location;
- (void) setCLUT:( unsigned char*) r :(unsigned char*) g :(unsigned char*) b;
- (NSImage*) nsimage;
- (NSImage*) nsimage:(BOOL) originalSize;
- (NSImage*) nsimage:(BOOL) originalSize allViewers:(BOOL) allViewers;
- (NSImage*) nsimageScaledToFitSquare: (NSPoint*) origin;
//- (CGImageRef) CGImageRef:(BOOL) originalSize allViewers:(BOOL) allViewers;
- (NSDictionary*) exportDCMCurrentImage: (DICOMExport*) exportDCM size:(int) size;
- (NSDictionary*) exportDCMCurrentImage: (DICOMExport*) exportDCM size:(int) size  views: (NSArray*) views viewsRect: (NSArray*) viewsRect;
- (NSDictionary*) exportDCMCurrentImage: (DICOMExport*) exportDCM size:(int) size  views: (NSArray*) views viewsRect: (NSArray*) viewsRect exportSpacingAndOrigin: (BOOL) exportSpacingAndOrigin;
- (NSDictionary*) exportDCMCurrentImage: (DICOMExport*) exportDCM size:(int) size  views: (NSArray*) views viewsRect: (NSArray*) viewsRect exportSpacingAndOrigin: (BOOL) exportSpacingAndOrigin force8bits:(BOOL) force8bits;
- (NSImage*) exportNSImageCurrentImageWithSize:(int) size;
- (void) setIndex:(short) index;
- (void) setIndexWithReset:(short) index :(BOOL)sizeToFit;
- (void) setDCM:(NSMutableArray*) c :(NSArray*)d :(NSMutableArray*)e :(short) firstImage :(char) type :(BOOL) reset;
- (void) setPixels: (NSMutableArray*) pixels files: (NSArray*) files rois: (NSMutableArray*) rois firstImage: (short) firstImage level: (char) level reset: (BOOL) reset;
- (void) sendSyncMessage:(short) inc;
- (void) loadTextures;
- (void)loadTexturesCompute;
- (IBAction) flipVertical:(id) sender;
- (IBAction) flipHorizontal:(id) sender;
- (void) setFusion:(short) mode :(short) stacks;
- (void) FindMinimumOpenGLCapabilities;
- (NSPoint) rotatePoint:(NSPoint) a;
- (void) setOrigin:(NSPoint) x;
- (void) setOriginX:(float) x Y:(float) y;
-(void) addOrigin:(NSPoint) p;
-(void) addOriginX:(float)x Y:(float) y;
- (void) scaleToFit;
- (void) scaleToFitIfNecessary;
- (float) scaleToFitForDCMPix: (DCMPix*) d;
- (BOOL) isScaledFit;
- (void) setBlendingFactor:(float) f;
- (void) createAliasesFor3DMeasure: (ROI*)r;
- (void) roiSet;
- (void) sync3DPosition;
- (void) roiSet:(ROI*) aRoi __deprecated;
- (void) colorTables:(unsigned char **) a :(unsigned char **) r :(unsigned char **)g :(unsigned char **) b;
- (void) blendingColorTables:(unsigned char **) a :(unsigned char **) r :(unsigned char **)g :(unsigned char **) b;
- (IBAction) sliderRGBFactor:(id) sender;
- (IBAction) alwaysSyncMenu:(id) sender;
- (void) getCLUT:( unsigned char**) r : (unsigned char**) g : (unsigned char**) b;
- (void) sync:(NSNotification*)note;
- (id)initWithFrame:(NSRect)frame imageRows:(int)rows  imageColumns:(int)columns;
- (float)getSUV;
- (IBAction) roiLoadFromXMLFiles: (NSArray*) filenames;
- (BOOL)checkHasChanged;
- (void) drawRectIn:(NSRect) size :(GLuint *) texture :(NSPoint) offset :(long) tX :(long) tY :(long) tW :(long) tH;
- (void) DrawNSStringGL: (NSString*) cstrOut :(GLuint) fontL :(long) x :(long) y;
- (void) DrawNSStringGL: (NSString*) str :(GLuint) fontL :(long) x :(long) y rightAlignment: (BOOL) right useStringTexture: (BOOL) stringTex;
- (void)DrawNSStringGL:(NSString*)str :(GLuint)fontL :(long)x :(long)y align:(DCMViewTextAlign)align useStringTexture:(BOOL)stringTex;
- (void) DrawCStringGL: ( char *) cstrOut :(GLuint) fontL :(long) x :(long) y;
- (void) DrawCStringGL: ( char *) cstrOut :(GLuint) fontL :(long) x :(long) y rightAlignment: (BOOL) right useStringTexture: (BOOL) stringTex;
- (void)DrawCStringGL:(char*)cstrOut :(GLuint)fontL :(long)x :(long)y align:(DCMViewTextAlign)align useStringTexture:(BOOL)stringTex;
- (void) drawTextualData:(NSRect) size :(long) annotations;
- (void) drawTextualData:(NSRect) size annotationsLevel:(long) annotations fullText: (BOOL) fullText onlyOrientation: (BOOL) onlyOrientation;
- (void) draw2DPointMarker;
- (void) drawImage:(NSImage *)image inBounds:(NSRect)rect;
- (void) setScaleValueCentered:(float) x;
- (void) updateCurrentImage: (NSNotification*) note;
- (void) setImageParamatersFromView:(DCMView *)aView;
- (void) setRows:(int)rows columns:(int)columns;
- (DCMPix*) middleSliceInThickStack;
- (void) updateTilingViews;
- (void) becomeMainWindow;
- (void) checkCursor;
- (DicomImage *)imageObj;
- (DicomSeries *)seriesObj;
- (DicomStudy *)studyObj;
- (void) updatePresentationStateFromSeries;
- (void) updatePresentationStateFromSeriesOnlyImageLevel: (BOOL) onlyImage;
- (void) updatePresentationStateFromSeriesOnlyImageLevel: (BOOL) onlyImage scale: (BOOL) scale offset: (BOOL) offset;
- (void) setCursorForView: (long) tool;
- (ToolMode) getTool: (NSEvent*) event;
- (void)resizeWindowToScale:(float)resizeScale;
- (OrthogonalMPRController*) controller;
- (void) roiChange:(NSNotification*)note;
- (void) magnifyWithEvent:(NSEvent *)anEvent;
- (void) rotateWithEvent:(NSEvent *)anEvent;
- (void) setStartWLWW;
- (void) stopROIEditing;
- (void) deleteInvalidROIs;
- (NSSize) makeTextureFromImage:(NSImage*)image forTexture:(GLuint*)texName buffer:(GLubyte**)buffer textureUnit:(GLuint)textureUnit;
- (void) stopROIEditingForce:(BOOL) force;
- (void) subDrawRect: (NSRect)aRect;     // Subclassable, default does nothing.
- (void) drawRectAnyway:(NSRect)aRect;   // Subclassable, default does nothing.
- (void) updateImage;
//- (NSPoint) convertFromView2iChat: (NSPoint) a;
//- (NSPoint) convertFromNSView2iChat: (NSPoint) a;
- (void) annotMenu:(id) sender;
- (ROI*) clickInROI: (NSPoint) tempPt;
- (ROI*) clickInROI: (NSPoint) tempPt testTextBox: (BOOL) t;
- (void) switchShowDescriptionInLarge;
- (void) deleteLens;
- (void)getOrientationText:(char *) orientation : (float *) vector :(BOOL) inv;
- (NSArray*) getOrientationStrings; // left, right, top, bottom;
- (NSMutableArray*) selectedROIs;
- (void) computeSliceIntersection: (DCMPix*) oPix sliceFromTo: (float[2][3]) sft vector: (float*) vectorB origin: (float*) originB;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx withShift: (double) shift;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx withShift: (double) shift showPoint: (BOOL) showPoint;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx perpendicular:(BOOL) perpendicular;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx perpendicular:(BOOL) perpendicular withShift:(double) shift;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx perpendicular:(BOOL) perpendicular withShift:(double) shift half:(BOOL) half;
- (void) drawCrossLines:(float[2][3]) sft ctx: (CGLContextObj) cgl_ctx perpendicular:(BOOL) perpendicular withShift:(double) shift half:(BOOL) half showPoint: (BOOL) showPoint;
+ (unsigned char*) PETredTable;
+ (unsigned char*) PETgreenTable;
+ (unsigned char*) PETblueTable;
- (void) startDrag:(NSTimer*)theTimer;
- (void)deleteMouseDownTimer;
- (void) roiLoadFromFilesArray: (NSArray*) filenames;
- (id)windowController;
- (BOOL)is2DViewer;
- (ViewerController*) viewer;
- (NSPoint) positionWithoutRotation: (NSPoint) tPt;
- (IBAction)realSize:(id)sender;
- (IBAction)scaleToFit:(id)sender;
- (IBAction)actualSize:(id)sender;
- (float) drawOrientation:(NSRect) size;
- (void) setCOPYSETTINGSINSERIESdirectly: (BOOL) b;
- (void) switchCopySettingsInSeries:(id) sender;
- (BOOL)actionForHotKey:(NSString *)hotKey;
+ (NSDictionary*) hotKeyDictionary;
+ (NSDictionary*) hotKeyModifiersDictionary;
- (void) delete3DROIsAliases;
- (void) generate3DROIsAliases;
- (void) displayFirstImage: (id) sender;
- (void) displayLastImage: (id) sender;
- (void) displayMiddleImage: (id) sender;

- (void) roiDeleteAll;

- (void)computeContextualMenuForROI:(ROI*)roi;
- (IBAction) roiSaveCurrent:(NSMenuItem*) mi;
- (IBAction) roiXYPlot:(NSMenuItem*) mi;
- (IBAction) roiCopyInfo:(NSMenuItem*) mi;
- (NSArray*) roisWithName:(NSString*)name;
- (IBAction) roiExportMetaData:(NSMenuItem*) mi;
- (IBAction) roiIntDeleteAllROIsWithSameName :(NSString*) name;
- (IBAction) roiEdit3DROISettings:(id)sender;
- (IBAction) roi3DROIConvertIsocontourToBrush:(NSMenuItem*)mi;
- (IBAction) roiGetInfo:(id) sender;
- (IBAction) roiHistogram:(id) sender;
- (int) imageIndexOfROI:(ROI*) c;

//iChat
// New Draw method to allow for IChat Theater
- (void) drawRect:(NSRect)aRect withContext:(NSOpenGLContext *)ctx;
- (BOOL)_checkHasChanged:(BOOL)flag;

// Methods for mouse drag response  Can be modified for subclassing
// This allow the various tools to  have different responses indifferent subclasses.
// Making it easie to modify mouseDragged:
- (BOOL)checkROIsForHitAtPoint:(NSPoint)point forEvent:(NSEvent *)event;
- (BOOL)mouseDraggedForROIs:(NSEvent *)event;
- (void)mouseDraggedCrosshair:(NSEvent *)event;
- (void)mouseDragged3DRotate:(NSEvent *)event;
- (void)mouseDraggedZoom:(NSEvent *)event;
- (void)mouseDraggedTranslate:(NSEvent *)event;
- (void)mouseDraggedRotate:(NSEvent *)event;
- (void)mouseDraggedImageScroll:(NSEvent *)event;
- (void)mouseDraggedBlending:(NSEvent *)event;
- (void)mouseDraggedWindowLevel:(NSEvent *)event;
- (void)mouseDraggedRepulsor:(NSEvent *)event;
- (void)mouseDraggedROISelector:(NSEvent *)event;

- (void) computeColor;
- (void)setIsLUT12Bit:(BOOL)boo;
- (BOOL)isLUT12Bit;

- (void)flagsChanged;

+ (NSArray*)cleanedOutDcmPixArray:(NSArray*)input; // filters the input array of DCMPix by returning only the pix with the most common ImageType in the input array

+ (void) updateLastMouseEvent;
+ (NSTimeInterval) lastMouseEvent;

- (void) forceResliceViewDisplay;

@end
