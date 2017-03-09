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
    BoneRemovalHotKeyAction, Rotate3DHotKeyAction, Camera3DotKeyAction, scissors3DHotKeyAction, RepulsorHotKeyAction, SelectorHotKeyAction, EmptyHotKeyAction, UnreadHotKeyAction, ReviewedHotKeyAction, DictatedHotKeyAction, ValidatedHotKeyAction, OrthoMPRCrossHotKeyAction, Preset1OpacityHotKeyAction, Preset2OpacityHotKeyAction, Preset3OpacityHotKeyAction, Preset4OpacityHotKeyAction, Preset5OpacityHotKeyAction, Preset6OpacityHotKeyAction, Preset7OpacityHotKeyAction, Preset8OpacityHotKeyAction, Preset9OpacityHotKeyAction, FullScreenAction, Sync3DAction, SetKeyImageAction, ThreeDBallHotKeyAction, OvalAngleHotKeyAction, PreviousROIsOrKeyImageAction __deprecated_msg("only in OsiriX"), NextROIsOrKeyImageAction __deprecated_msg("only in OsiriX"), FuseDeFusePETSPECTCTAction __deprecated_msg("only in OsiriX"), AxialResliceAction __deprecated_msg("only in OsiriX"), CoronalResliceAction __deprecated_msg("only in OsiriX"),SagittalResliceAction __deprecated_msg("only in OsiriX"),ActivateInactivateThickSlabAction __deprecated_msg("only in OsiriX"),
    
    Preset1CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset2CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset3CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset4CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset5CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset6CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset7CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset8CLUTHotKeyAction __deprecated_msg("only in OsiriX"), Preset9CLUTHotKeyAction __deprecated_msg("only in OsiriX"),
    
    LastAction // Key this enum ALWAYS as last enum !
} HotKeyActions;

/** \brief Sets up user defaults */
@interface DefaultsOsiriX : NSObject {

}

//+ (BOOL) isHUG;
//+ (BOOL) isUniGE;
//+ (BOOL) isLAVIM;
+ (NSMutableDictionary*) getDefaults;
//+ (NSString*) hostName;
+ (NSHost*) currentHost;
+ (void) DNSResolve:(id) o;
+ (NSArray*) currentHostNames;
+ (NSArray*) currentHostAddresses;
@end
