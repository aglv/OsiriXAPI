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

// This will be added to the main inded page of the Doxygen documentation
/** \mainpage OsiriX index page
*  <img src= "../../../osirix/Binaries/Icons/SmallLogo.tif">
* \section Intro OsiriX DICOM workstation
*  Osirix is a free open source DICOM workstation with full 64 bit support.
*
*  We extend out thanks to other in the open source community.
*
*  VTK, ITK, and DCMTK open source projects are extensively used in OsiriX.
*
*  The OsiriX team.
*/

#ifdef OSIRIX_VIEWER
#ifndef OSIRIX_LIGHT
#ifndef MACAPPSTORE
#import <Growl/Growl.h>
#endif
#endif
#endif

#import <AppKit/AppKit.h>
#import "XMLRPCMethods.h"

//@class ThreadPoolServer;
//@class ThreadPerConnectionServer;

//#import "IChatTheatreDelegate.h"

@class PreferenceController;
@class BrowserController;
@class SplashScreen;
@class DCMNetServiceDelegate;
@class WebPortal;
@class DCMPix;

typedef enum
{
    linearIntegerGA,
    log4GA,
    log2GA
    
} GAMode;

enum
{
	compression_sameAsDefault = 0,
	compression_none = 1,
	compression_JPEG = 2,
	compression_JPEG2000 = 3,
    compression_JPEGLS = 4
};

enum
{
	always = 0,
	cdOnly = 1,
	notMainDrive = 2,
	ask = 3
};

@class PluginFilter;

#ifdef __cplusplus
extern "C"
{
#endif
	NSRect screenFrame();
	NSString * documentsDirectoryFor( int mode, NSString *url) __deprecated;
	NSString * documentsDirectory() __deprecated;
    extern BOOL hideListenerError;
    extern BOOL gDarkAppearance;
#ifdef __cplusplus
}
#endif


/** \brief  NSApplication delegate
*
*  NSApplication delegate 
*  Primarily manages the user defaults and server
*  Also controls some general main items
*
*
*/

//#if defined(OSIRIX_VIEWER) && !defined(OSIRIX_LIGHT) && !defined(MACAPPSTORE)
//#else
//@protocol GrowlApplicationBridgeDelegate
//@end
//#endif

#define REGPHPURL @"reg/reg.php"

@class AppController, ToolbarPanelController, ThumbnailsListPanel, BonjourPublisher;

extern AppController* OsiriX;
extern NSString* getMacAddress(void);

@interface AppController : NSObject	<NSNetServiceBrowserDelegate, NSNetServiceDelegate, NSSoundDelegate, NSMenuDelegate> // GrowlApplicationBridgeDelegate
{
	IBOutlet BrowserController		*browserController;

    IBOutlet NSMenu					*filtersMenu;
	IBOutlet NSMenu					*roisMenu;
	IBOutlet NSMenu					*othersMenu;
	IBOutlet NSMenu					*dbMenu;
    IBOutlet NSMenu					*reportMenu;
	IBOutlet NSWindow				*dbWindow;
    IBOutlet NSWindow				*emailAddressWindow __deprecated_msg("only in OsiriX");
	IBOutlet NSMenu					*windowsTilingMenuRows, *windowsTilingMenuColumns;
    IBOutlet NSMenu                 *recentStudiesMenu;
	
	NSDictionary					*previousDefaults;
	
	BOOL							showRestartNeeded;
		
    SplashScreen					*splashController;
	
    volatile BOOL					quitting;
	BOOL							verboseUpdateCheck;
	NSNetService					*BonjourDICOMService;
	
	NSTimer							*updateTimer;
	XMLRPCInterface					*XMLRPCServer;
	
	BOOL							checkAllWindowsAreVisibleIsOff, isSessionInactive;
	
	int								lastColumns, lastRows, lastCount, lastColumnsPerScreen;
    
    BonjourPublisher* _bonjourPublisher;
    
    long updateTotalData, updateReceivedData;
    NSMutableData *updateData;

    id appNapActivity __deprecated_msg("only in OsiriX");
    
    // DICOM Definition parser
    BOOL getCurrentModule, applicationDidFinishLaunching __deprecated_msg("only in OsiriX");
    NSString *previousContent, *previousOriginal, *currentFile, *currentModule;
    NSMutableDictionary *DICOMDefinitionDict;
    NSDictionary *currentAttribute;
    NSMutableDictionary *currentIDElements;
}

@property BOOL checkAllWindowsAreVisibleIsOff, isSessionInactive, showRestartNeeded, applicationDidFinishLaunching __deprecated_msg("only in OsiriX");
@property(readonly) NSMenu *filtersMenu, *recentStudiesMenu, *windowsTilingMenuRows, *windowsTilingMenuColumns;
@property(readonly) NSNetService* dicomBonjourPublisher;
@property(readonly) XMLRPCInterface *XMLRPCServer;
@property(readonly) BonjourPublisher* bonjourPublisher;
@property(readonly) int lastColumns, lastRows, lastCount;
@property(retain) id appNapActivity __deprecated_msg("only in OsiriX");

+ (void) thisFeatureIsNotAvailable: (NSString*) stringUrl __deprecated_msg("only in OsiriX");
+ (BOOL) isFDACleared;
+ (BOOL) willExecutePlugin;
+ (BOOL) willExecutePlugin:(id) filter;
+ (BOOL) hasMacOSXLion;
+ (BOOL) hasMacOSXSnowLeopard;
+ (BOOL) hasMacOSXLeopard;
+ (BOOL) hasOSXElCapitan;
+ (BOOL) hasOSXYosemite;
+ (BOOL) hasMacOSSierra __deprecated_msg("only in OsiriX");
+ (BOOL) hasMacOSSierra10122 __deprecated_msg("only in OsiriX");
+ (BOOL) hasMacOSX: (NSString*) vers __deprecated_msg("only in OsiriX");
+ (int) isUnsupportedOS;
+ (BOOL) hasMacOSXMaverick;
+ (NSArray*) IPv4Address;
+ (NSString*) UID;
+ (NSString*) getRK;
+ (void) restartOsiriX;
+ (NSDictionary*) loadRegistrationDictionary;
+ (NSImage*) webBrowserIcon __deprecated_msg("only in OsiriX");
+ (NSData*) encodeData:(NSData*) dataIn __deprecated_msg("only in OsiriX");
+ (NSData*) decodeData:(NSData*) dataIn __deprecated_msg("only in OsiriX");

#pragma mark-
#pragma mark initialization of the main event loop singleton

+ (void) createNoIndexDirectoryIfNecessary:(NSString*) path __deprecated;
#ifndef OSIRIXLITE
+ (int) displayVeryImportantNotice64:(id) sender;
#else
+ (int) displayVeryImportantNotice32:(id) sender;
#endif
+ (NSURL*) baseURL;
+ (AppController*) sharedAppController; /**< Return the shared AppController instance */
+ (void) resizeWindowWithAnimation:(NSWindow*) window newSize: (NSRect) newWindowFrame;
+ (void) pause __deprecated;
+ (ThumbnailsListPanel*)thumbnailsListPanelForScreen:(NSScreen*)screen;
+ (NSString*)printStackTrace:(NSException*)e __deprecated; // use -[NSException printStackTrace] form NSException+N2
+ (BOOL) isKDUEngineAvailable;
+ (void) binpdf: (NSString*) file toFile: (NSString*) toFile;
+ (void) sendGAWithAction: (NSString*) action label:(NSString*) label;
+ (void) sendGAWithCategory:(NSString*) category action: (NSString*) action label:(NSString*) label;
+ (void) sendGAWithAction:(NSString*) action value:(int) intValue mode:(GAMode) gaMode;
+ (void) sendGAWithCategory:(NSString*) category action: (NSString*) action label:(NSString*) label value:(int) intValue mode:(GAMode) gaMode;
#pragma mark-
#pragma mark HTML Templates
+ (void)checkForHTMLTemplates __deprecated;
+ (BOOL) FPlistForKey: (NSString*) k;
+ (long) longForFPlistForKey: (NSString*) k __deprecated_msg("only in OsiriX");

#pragma mark-
#pragma mark  Server management
- (void) terminate :(id) sender; /**< Terminate listener (Q/R SCP) */
- (void) restartSTORESCP; /**< Restart listener (Q/R SCP) */
- (void) startSTORESCP:(id) sender; /**< Start listener (Q/R SCP) */
- (void) startSTORESCPTLS:(id) sender; /**< Start TLS listener (Q/R SCP) */
- (void) installPlugins: (NSArray*) pluginsArray;
- (BOOL) isStoreSCPRunning;

#pragma mark-
#pragma mark static menu items
//===============OSIRIX========================
- (IBAction) about:(id)sender; /**< Display the about window */
- (IBAction) showPreferencePanel:(id)sender; /**< Show Preferences window */
#ifndef OSIRIX_LIGHT
#ifndef MACAPPSTORE
- (IBAction) checkForUpdates:(id) sender;  /**< Check for update */
#endif
- (IBAction) autoQueryRefresh:(id)sender;
#endif
//===============WINDOW========================
- (IBAction) setFixedTilingRows: (id) sender;
- (IBAction) setFixedTilingColumns: (id) sender;
- (void) initTilingWindows;
- (IBAction) tileWindows:(id)sender;  /**< Tile open window */
- (IBAction) tile3DWindows:(id)sender; /**< Tile 3D open window */
- (void) tileWindows:(id)sender windows: (NSMutableArray*) viewersList display2DViewerToolbar: (BOOL) display2DViewerToolbar displayThumbnailsList: (BOOL) displayThumbnailsList;
- (void) checkWindowDisplay;
- (void) scaleToFit:(id)sender;    /**< Scale opened windows */
- (IBAction) closeAllViewers: (id) sender;  /**< Close All Viewers */
- (void) checkAllWindowsAreVisible:(id) sender;
- (void) checkAllWindowsAreVisible:(id) sender makeKey: (BOOL) makeKey;
//- (IBAction)toggleActivityWindow:(id)sender;
//===============HELP==========================
- (IBAction) sendEmail: (id) sender;   /**< Send email to lead developer */
- (IBAction) openOsirixWebPage: (id) sender;  /**<  Open OsiriX web page */
//- (IBAction) openOsirixDiscussion: (id) sender; /**< Open OsiriX discussion web page */
- (IBAction) osirix64bit: (id) sender;
//---------------------------------------------
- (IBAction) help: (id) sender;  /**< Open help window */
//=============================================

- (IBAction) killAllStoreSCU:(id) sender;

- (id) splashScreen;

#pragma mark-
#pragma mark window routines
- (IBAction) updateViews:(id) sender;  /**< Update Viewers */
- (NSScreen *)dbScreen;  /**< Return monitor with DB */
- (NSArray *)viewerScreens; /**< Return array of monitors for displaying viewers */

 /** 
 * Find the WindowController with the named nib and using the pixList
 * This is commonly used to find the 3D Viewer associated with a ViewerController.
 * Conversely this could be used to find the ViewerController that created a 3D Viewer
 * Each 3D Viewer has its own distinctly named nib as does the ViewerController.
 * The pixList is the Array of DCMPix that the viewer uses.  It should uniquely identify related viewers
*/
- (id) FindViewer:(NSString*) nib :(NSArray*) pixList;
- (NSArray*) FindRelatedViewers:(NSArray*) pixList; /**< Return an array of all WindowControllers using the pixList */
- (IBAction) cancelModal: (id) sender;
- (IBAction) okModal: (id) sender;
- (IBAction)alternateModal:(id)sender;
- (NSString*) privateIP;
- (void) killDICOMListenerWait:(BOOL) w;
- (void) runPreferencesUpdateCheck:(NSTimer*) timer;
+ (void) resetThumbnailsList;
+ (void) checkForPreferencesUpdate: (BOOL) b;
+ (BOOL) USETOOLBARPANEL;
+ (void) setUSETOOLBARPANEL: (BOOL) b;
+ (NSRect) usefullRectForScreen: (NSScreen*) screen;
+ (NSArray*) sortObjects: (NSArray*) objects accordingToSeriesDescriptionsArray: (NSArray*) seriesDescriptionsOrder;
+ (NSArray*) sortObjects: (NSArray*) objects accordingToSeriesDescriptionsArray: (NSArray*) seriesDescriptionsOrder oneSeriesPerSeriesDescription: (BOOL) oneSeriesPerSeriesDescription __deprecated_msg("only in OsiriX");
- (NSMutableArray*) orderedWindowsAccordingToPositionByRows: (NSArray*) a;
- (void) addStudyToRecentStudiesMenu: (NSManagedObjectID*) studyID;
- (void) loadRecentStudy: (id) sender;
- (void) buildRecentStudiesMenu;
- (NSMenu*) viewerMenu;
- (NSMenu*) fileMenu;
- (NSMenu*) exportMenu;
- (NSMenu*) imageTilingMenu;
- (NSMenu*) applyWindowProtocolMenu;
- (NSMenu*) VOILutMenu;
- (NSMenu*) orientationMenu;
- (NSMenu*) opacityMenu;
- (NSMenu*) wlwwMenu;
- (NSMenu*) convMenu;
- (NSMenu*) clutMenu;
+ (NSImage*) clutIconForClutName: (NSString*) clutName __deprecated_msg("only in OsiriX");
+ (NSImage*) clutIconForRed: (unsigned char*) redT green:(unsigned char*) greenT blue:(unsigned char*) blueT __deprecated_msg("only in OsiriX");
+ (void) setPopupMenuFont: (NSMenu*) menu __deprecated_msg("only in OsiriX");
+ (void) setPopupMenuFont: (NSMenu*) menu allItems: (BOOL) allItems __deprecated_msg("only in OsiriX");
+ (void) resetPopupMenuFont: (NSMenu*) menu __deprecated_msg("only in OsiriX");
+ (void) resetClutIcons __deprecated_msg("only in OsiriX");
+ (void) resetOpacityIcons __deprecated_msg("only in OsiriX");
+ (NSImage*) opacityIconForOpacityName: (NSString*) opacityName __deprecated_msg("only in OsiriX");
- (NSMenu*) workspaceMenu;
+ (NSImage*) wwwlIconForDcmPix: (DCMPix*) pix ww: (float) ww wl: (float) wl __deprecated_msg("only in OsiriX");
//+ (NSImage*) fusionIconForDcmPix: (DCMPix*) pix mode: (int) mode stack: (int) stack direction: (int) direction __deprecated_msg("only in OsiriX");
+ (NSImage*) convolutionIconForDcmPix: (DCMPix*) pix name: (NSString*) name __deprecated_msg("only in OsiriX");
+ (NSImage*) resizeImageForIcon: (NSImage*) im __deprecated_msg("only in OsiriX");
+ (NSRect) visibleFrameForScreen: (NSScreen*) screen __deprecated_msg("only in OsiriX");

#pragma mark-
#pragma mark growl
- (void) growlTitle:(NSString*) title description:(NSString*) description name:(NSString*) name;
//- (NSDictionary *) registrationDictionaryForGrowl;

//#pragma mark-
//#pragma mark display setters and getters
//- (IBAction) saveLayout: (id)sender;

#pragma mark-
#pragma mark 12 Bit Display support.
+ (BOOL)canDisplay12Bit;
+ (void)setCanDisplay12Bit:(BOOL)boo;
+ (void)setLUT12toRGB:(unsigned char*)lut;
+ (unsigned char*)LUT12toRGB;
+ (void)set12BitInvocation:(NSInvocation*)invocation;
+ (NSInvocation*)fill12BitBufferInvocation;

#pragma mark -
-(WebPortal*)defaultWebPortal;
-(BOOL) processOsiriXSchemeURL: (NSURL*) url;

#ifndef OSIRIX_LIGHT
-(NSString*)weasisBasePath;
#endif

-(void)setReceivingIcon;
-(void)unsetReceivingIcon;
-(void)setBadgeLabel:(NSString*)label;
- (void)playGrabSound;

@end

