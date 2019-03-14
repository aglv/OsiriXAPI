/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

// WARNING: If you add or modify this list, check ViewerController.m, DCMView.h and HotKey Pref Pane

typedef enum HotKeyActions {DefaultWWWLHotKeyAction = 0, FullDynamicWWWLHotKeyAction,
	Preset1WWWLHotKeyAction, Preset2WWWLHotKeyAction, Preset3WWWLHotKeyAction, 
	Preset4WWWLHotKeyAction, Preset5WWWLHotKeyAction, Preset6WWWLHotKeyAction, 
	Preset7WWWLHotKeyAction, Preset8WWWLHotKeyAction, Preset9WWWLHotKeyAction,
	FlipVerticalHotKeyAction, FlipHorizontalHotKeyAction,
	WWWLToolHotKeyAction, MoveHotKeyAction, ZoomHotKeyAction, RotateHotKeyAction,
	ScrollHotKeyAction, LengthHotKeyAction, AngleHotKeyAction, RectangleHotKeyAction,
	OvalHotKeyAction, TextHotKeyAction, ArrowHotKeyAction, OpenPolygonHotKeyAction,
	ClosedPolygonHotKeyAction, PencilHotKeyAction, ThreeDPointHotKeyAction, PlainToolHotKeyAction,
    BoneRemovalHotKeyAction, Rotate3DHotKeyAction, Camera3DotKeyAction, scissors3DHotKeyAction, RepulsorHotKeyAction, SelectorHotKeyAction, EmptyHotKeyAction, UnreadHotKeyAction, ReviewedHotKeyAction, DictatedHotKeyAction, ValidatedHotKeyAction, OrthoMPRCrossHotKeyAction, Preset1OpacityHotKeyAction, Preset2OpacityHotKeyAction, Preset3OpacityHotKeyAction, Preset4OpacityHotKeyAction, Preset5OpacityHotKeyAction, Preset6OpacityHotKeyAction, Preset7OpacityHotKeyAction, Preset8OpacityHotKeyAction, Preset9OpacityHotKeyAction, FullScreenAction, Sync3DAction, SetKeyImageAction, ThreeDBallHotKeyAction, OvalAngleHotKeyAction, PreviousROIsOrKeyImageAction, NextROIsOrKeyImageAction, FuseDeFusePETSPECTCTAction, AxialResliceAction, CoronalResliceAction,SagittalResliceAction,ActivateInactivateThickSlabAction,
    
    Preset1CLUTHotKeyAction, Preset2CLUTHotKeyAction, Preset3CLUTHotKeyAction, Preset4CLUTHotKeyAction, Preset5CLUTHotKeyAction, Preset6CLUTHotKeyAction, Preset7CLUTHotKeyAction, Preset8CLUTHotKeyAction, Preset9CLUTHotKeyAction, Preset3DPositionHotKeyAction,
    
    FirstImageHotKeyAction, LastImageHotKeyAction,
    
    ActivateInactivateThickSlabActionInMIP, ActivateInactivateThickSlabActionInMean, ActivateInactivateThickSlabActionInMinIP,
    
    ActivateInactivatePropagateAction, ActivateInactivateSyncSlabAction,ShowHideReferenceLinesAction,
    
    Fuse100PercentPETSPECTCTAction,
    Fuse0PercentPETSPECTCTAction,
    
    PresetConvolutionBlur3x3HotKeyAction,
    PresetConvolutionBlur5x5HotKeyAction,
    PresetConvolutionSharpen3x3HotKeyAction,
    PresetConvolutionSharpen5x5HotKeyAction,
    
    Copy3DCoordinatesToClipboardAction,
    
    LastAction // Key this enum ALWAYS as last enum !
} HotKeyActions;

/** \brief Sets up user defaults */
@interface DefaultsOsiriX : NSObject {

}

+ (NSMutableDictionary*) getDefaults;
+ (void) addCLUT: (NSString*) filename dictionary: (NSMutableDictionary*) clutValues;
+ (long) vramSize;
@end
