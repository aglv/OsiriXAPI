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
#import <WebKit/WebKit.h>

#include <Accelerate/Accelerate.h>


#define ALPHASTATECOLOR 0.5

@class DicomDatabase;
@class MPR2DController,NSCFDate, DicomStudy, DicomSeries;
@class ViewerController, DicomImage;
@class BonjourBrowser;
@class AnonymizerWindowController,QueryController;
@class LogWindowController,PreviewView;
@class MyOutlineView,DCMView,DCMPix;
@class StructuredReportController,BrowserMatrix;
@class PluginManagerController,WaitRendering, Wait, ActivityWindowController;
@class WebPortalUser, DCMTKStudyQueryNode, DCMTKQueryNode;

enum dbObjectSelection {oAny,oMiddle,oFirstForFirst};
enum searchDatabaseTypes { patientNameSearch = 0, patientIDSearch, studyIDSearch, commentsSearch, studyDescriptionSearch, modalitySearch, accessionNumberSearch, allFieldsSearch};

extern NSString* O2AlbumDragType;

@interface NSString (BrowserController)
-(NSMutableString*)filenameString;
@end

/** \brief Window controller for Browser
*
*   This is a large class with a lot of functions.
*   Along with managing the Browser Window it manages all the view in the browser
*	and manages the database
*/

@interface BrowserController : NSWindowController
#if (MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5)
<NSTableViewDelegate, NSDrawerDelegate, NSMatrixDelegate, NSToolbarDelegate, NSMenuDelegate, NSSplitViewDelegate, WebPolicyDelegate, WKNavigationDelegate>   //NSObject
#endif
{
	DicomDatabase*					_database;
	NSMutableDictionary				*databaseIndexDictionary;
	
	NSDateFormatter			*TimeFormat, *TimeWithSecondsFormat, *DateTimeWithSecondsFormat;
	
#define MAXSCREENS 40
	NSRect					visibleScreenRect[ MAXSCREENS];
	NSString				*transferSyntax;
    NSArray                 *dirArray;
    NSToolbar               *toolbar;
	
	NSMutableArray			*sendQueue;
	NSMutableDictionary		*reportFilesToCheck;
	
    NSMutableArray          *previewPix, *previewPixThumbnails;
		
	NSMutableDictionary		*activeSends;
	NSMutableArray			*sendLog;
	NSMutableDictionary		*activeReceives;
	NSMutableArray			*receiveLog;
	
	LogWindowController		*logWindowController;
	
    DCMPix                  *curPreviewPix;
    
    NSTimer                 *refreshTimer;
//    NSTimer                 *timer, *refreshTimer, *databaseCleanerTimer, *deleteQueueTimer;
	long					loadPreviewIndex, previousNoOfFiles, previousDistantNoOfFiles;
	NSManagedObject			*previousItem;
    
	long					previousBonjourIndex;
	
	IBOutlet NSSplitView	*splitViewHorz, *splitViewVert, *splitAlbums, *splitDrawer, *splitComparative;
    CGFloat _splitViewVertDividerRatio;
    
	BOOL					setDCMDone, dontUpdatePreviewPane;
	
    NSTimeInterval          lastComputeAlbumsForDistantStudies;
    NSMutableDictionary     *_distantAlbumNoOfStudiesCache;
    NSThread                *distantSearchThread;
	NSMutableArray*         _albumNoOfStudiesCache;
    NSMutableDictionary*    _albumCachedStudyInstanceArray;
    NSArray*                _cachedAlbums, *_cachedAlbumsIDs;
    NSManagedObjectContext* _cachedAlbumsContext;
    NSString                *selectedAlbumName;
	
	NSArray							*outlineViewArray, *originalOutlineViewArray, *outlineViewArrayStudyInstanceUIDs;
	NSArray							*matrixViewArray;
	
	NSString						*_searchString;
	
	IBOutlet NSTextField			*databaseDescription;
	IBOutlet MyOutlineView          *databaseOutline;
	NSMenu							*columnsMenu, *contextualReportMenu;
	IBOutlet BrowserMatrix			*oMatrix;
	IBOutlet NSTableView			*albumTable;
	
	IBOutlet NSBox					*bonjourSourcesBox;
	
	IBOutlet NSArrayController*		_sourcesArrayController;
	IBOutlet NSTableView*			_sourcesTableView;
	id								_sourcesHelper;
	BonjourBrowser					*bonjourBrowser;
	
	IBOutlet NSSlider				*animationSlider;
	IBOutlet NSButton				*animationCheck;
    IBOutlet NSSplitView*           _bottomSplit;
    
    IBOutlet PreviewView			*imageView;
    IBOutlet NSView                 *matrixView;
    IBOutlet NSView                 *comparativeScrollView;
	
	int								subFrom, subTo, subInterval, subMax;
	
	IBOutlet NSWindow				*subOpenWindow;
	IBOutlet NSMatrix				*subOpenMatrix3D, *subOpenMatrix4D;
	
	IBOutlet NSWindow				*subSeriesWindow;
	IBOutlet NSButton				*subSeriesOKButton;
	
	IBOutlet NSWindow				*bonjourPasswordWindow;
	IBOutlet NSTextField			*password;
	
	IBOutlet NSWindow				*newAlbum;
	IBOutlet NSTextField			*newAlbumName;
	
	IBOutlet NSWindow				*rebuildWindow;
	IBOutlet NSMatrix				*rebuildType;
	IBOutlet NSTextField			*estimatedTime, *noOfFilesToRebuild, *warning;
	
    int								timeIntervalType;
    NSDate							*timeIntervalStart, *timeIntervalEnd;
    IBOutlet NSView					*timeIntervalView;

    NSString						*modalityFilter;
    IBOutlet NSPopUpButton          *modalityFilterMenu;
    IBOutlet NSView					*modalityFilterView;
    
	IBOutlet NSView					*searchView;
	IBOutlet NSSearchField			*searchField;
    IBOutlet NSButton               *searchInEntireDBResult;
	NSToolbarItem					*toolbarSearchItem;
	int								searchType;
	
	IBOutlet NSMenu					*imageTileMenu;
	IBOutlet NSWindow				*urlWindow, *CDpasswordWindow, *ZIPpasswordWindow;
	IBOutlet NSTextField			*urlString;
	
	IBOutlet NSForm					*rdPatientForm, *rdPixelForm, *rdVoxelForm, *rdOffsetForm;
	IBOutlet NSMatrix				*rdPixelTypeMatrix;
	IBOutlet NSView					*rdAccessory;
	
	IBOutlet NSView					*exportQuicktimeView;
	IBOutlet NSButton				*exportHTMLButton;
	
	IBOutlet NSView					*exportAccessoryView;
	
	NSPredicate						*testPredicate;
	
    BOOL							showAllImages, isNetworkLogsActive;
	NSConditionLock					*queueLock;
	
	IBOutlet NSScrollView			*thumbnailsScrollView;
	
	NSPredicate						*_fetchPredicate, *_filterPredicate;
	NSString						*_filterPredicateDescription;
	
	NSString						*CDpassword, *pathToEncryptedFile, *passwordForExportEncryption;
	
	NSUInteger						previousFlags;
    
	NSMutableArray					*deleteQueueArray;
	NSRecursiveLock					*deleteQueue, *deleteInProgress;
	
	NSConditionLock					*processorsLock;
	
	NSMutableString					*pressedKeys;
	
	IBOutlet NSView					*reportTemplatesView;
	IBOutlet NSImageView			*reportTemplatesImageView;
	IBOutlet NSPopUpButton			*reportTemplatesListPopUpButton;
	int								reportToolbarItemType;
	
	IBOutlet NSWindow				*addStudiesToUserWindow;
	IBOutlet NSWindow				*notificationEmailWindow;
	IBOutlet NSArrayController		*notificationEmailArrayController;
	NSString						*temporaryNotificationEmail, *customTextNotificationEmail;
	
	NSImage							*notFoundImage;
	
	BOOL							ROIsAndKeyImagesButtonAvailable;
	
	BOOL							rtstructProgressBar;
	float							rtstructProgressPercent;
	
	BOOL							avoidRecursive, openSubSeriesFlag, openReparsedSeriesFlag;
	
	IBOutlet PluginManagerController *pluginManagerController;
	
	WaitRendering					*waitOpeningWindow;
	BOOL							waitCompressionAbort;
	
	NSMutableArray					*cachedFilesForDatabaseOutlineSelectionSelectedFiles;
	NSMutableArray					*cachedFilesForDatabaseOutlineSelectionCorrespondingObjects;
    NSMutableSet                    *cachedFilesForDatabaseOutlineSelectionTreeObjects;
	NSIndexSet						*cachedFilesForDatabaseOutlineSelectionIndex;
	
    id                              lastROIsAndKeyImagesSelectedFiles, lastROIsImagesSelectedFiles, lastKeyImagesSelectedFiles;
    NSArray                         *ROIsAndKeyImagesCache, *ROIsImagesCache, *KeyImagesCache;
    BOOL                            ROIsAndKeyImagesCacheSameSeries, ROIsImagesCacheSameSeries;
    
    NSLock                          *computingNumberOfStudiesForAlbumsLock;
	
	IBOutlet NSTableView* _activityTableView;
	id _activityHelper;
    
    IBOutlet NSSplitView *bannerSplit;
    IBOutlet WebView *bannerWebView;
    NSDictionary *bannerDict;
    NSSize bannerWebViewSize;
    int bannerIndex;
    
    
    NSTimeInterval _timeIntervalOfLastLoadIconsDisplayIcons;
    NSThread *matrixLoadIconsThread;
    
    BOOL subSeriesWindowIsOn;
    
    NSRecursiveLock *searchForComparativeStudiesLock;
    NSString *comparativePatientUID; //Current patient history displayed
    NSMutableArray *comparativeStudySearchArray; //The queue of patient history to be searched
    NSArray *comparativeStudies; //Studies for the NSTableView
    IBOutlet NSOutlineView *comparativeTable;
    BOOL dontSelectStudyFromComparativeStudies;
    NSTimeInterval lastRefreshComparativeStudies; //Refresh the studies after X minutes
    
    NSMutableArray *comparativeRetrieveQueue, *comparativeSeriesRetrieveQueue; //Retrieve Queue: don't retrieve the same study multiple times
    DCMTKStudyQueryNode *comparativeStudyWaited; //The study to be selected or opened
    ViewerController *comparativeStudyWaitedViewer; //The destination viewer
    NSTimeInterval comparativeStudyWaitedTime; //The time when the study to be selected or opened was activated
    BOOL comparativeStudyWaitedToOpen; // for retrieveStudy: function
    BOOL comparativeStudyWaitedToSelect; // for retrieveStudy: function
    
    NSString *smartAlbumDistantName;
    NSArray *smartAlbumDistantArray;
    NSMutableArray *smartAlbumDistantSearchArray; //The queue of smart albums to be searched
    NSTimeInterval lastRefreshSmartAlbumDistantStudies;
    NSString *distantStudyMessage; // The text displayed in the matrix thumbnails
    
    NSDate *distantTimeIntervalStart, *distantTimeIntervalEnd;
    NSString *distantSearchString;
    int distantSearchType;
    int distantEntireDBResultCount, localEntireDBResultCount;
    
    BOOL autoretrievingPACSOnDemandSmartAlbum;
    
    IBOutlet NSWindow *unifyWindow;
    BOOL unifyPatientID, unifyStudyID, unifyNewStudyInstanceUID, unifyNewSeriesInstanceUIDs, unifyNewSOPInstanceUIDs, unifyMultipleStudies;
//    int unifyModifyFieldsTag;
    NSArray *unifyStudiesMenu;
    NSMutableArray *unifyListOfStudies;
    NSString *unifyFromList, *unifyTo;
    
    IBOutlet NSWindow *editStateMenuWindow;
    IBOutlet NSTableView *stateMenuTableView;
    IBOutlet NSArrayController *stateMenuArrayController;
    BOOL needToRebuildColorStudy;
    
    NSString *openedStudyInstanceUID;
}

@property(retain) NSArray *unifyStudiesMenu;
@property(retain, nonatomic) NSString *unifyFromList, *unifyTo;
@property(nonatomic) BOOL unifyPatientID, unifyStudyID, unifyNewStudyInstanceUID, unifyNewSeriesInstanceUIDs, unifyNewSOPInstanceUIDs, unifyMultipleStudies;
//@property int unifyModifyFieldsTag;
@property(retain,nonatomic) DicomDatabase* database;
@property(readonly) NSArrayController* sources;

@property(readonly) NSDateFormatter *DateTimeFormat __deprecated, *DateOfBirthFormat __deprecated, *TimeFormat, *TimeWithSecondsFormat, *DateTimeWithSecondsFormat;
@property(readonly) NSArray *matrixViewArray;
@property(readonly) NSMatrix *oMatrix;
@property(readonly) BOOL is2DViewer, isCurrentDatabaseBonjour;
@property(readonly) MyOutlineView *databaseOutline;
@property(readonly) NSTableView *albumTable, *sourcesTableView;
@property(readonly) NSString *currentDatabasePath __deprecated, *localDatabasePath __deprecated, *documentsDirectory __deprecated, *fixedDocumentsDirectory __deprecated;

@property(readonly) NSBox *bonjourSourcesBox;
@property(readonly) BonjourBrowser *bonjourBrowser;
@property(readonly) const char *cfixedDocumentsDirectory __deprecated, *cfixedIncomingDirectory __deprecated, *cfixedTempNoIndexDirectory __deprecated, *cfixedIncomingNoIndexDirectory __deprecated;

@property(retain) NSString *searchString, *CDpassword, *pathToEncryptedFile, *passwordForExportEncryption, *temporaryNotificationEmail, *customTextNotificationEmail, *comparativePatientUID, *smartAlbumDistantName, *distantStudyMessage, *distantSearchString, *selectedAlbumName, *openedStudyInstanceUID;
@property(retain) NSPredicate *fetchPredicate, *testPredicate;
@property(retain) NSArray *comparativeStudies;
@property(readonly) NSPredicate *filterPredicate;
@property(readonly) NSString *filterPredicateDescription;
@property(retain) NSDate *distantTimeIntervalStart, *distantTimeIntervalEnd;
@property(retain) NSDate *timeIntervalStart, *timeIntervalEnd;
@property(nonatomic, retain) NSString *modalityFilter;
@property(nonatomic) int timeIntervalType;
@property(readonly) NSMutableDictionary *databaseIndexDictionary;
@property(readonly) PluginManagerController *pluginManagerController;
@property int distantSearchType;
@property(readonly) NSMutableArray *comparativeRetrieveQueue, *comparativeSeriesRetrieveQueue;

// NSTouchBar
@property(retain) NSPopoverTouchBarItem *modalityFilterPopoverTouchBarItem;
@property(retain) NSPopoverTouchBarItem *timeIntervalFilterPopoverTouchBarItem;
@property(retain) NSPopoverTouchBarItem *statusPopoverTouchBarItem;
@property(retain) NSScrubber *modalityScrubber;
@property(retain) NSScrubber *timeIntervalScrubber;
@property(retain) NSScrubber *statusScrubber;
@property(retain) NSScrubber *thumbnailsScrubber;

+ (void) buildReportsMenu: (NSPopUpButton*) reportTemplatesListPopUpButton;
+ (void) resetPreferences;
+ (NSMenu*) buildStateTextMenu;
+ (NSMenu*) buildStateTextMenuWithEdit: (BOOL) editItem;
+ (void)initializeBrowserControllerClass;
+ (unsigned int)_currentModifierFlags;
+ (BrowserController*) currentBrowser;
+ (NSMutableString*) replaceNotAdmitted: (NSMutableString*) name __deprecated;
+ (NSString*) stringByReplaceNotAdmitted: (NSString*) name;
+ (NSDictionary*) statesDictionary;
+ (NSImage *)createStateDotWithColor:(NSColor *)c alpha: (float) alpha;
+ (void) updateActivity;
+ (BOOL) horizontalHistory;
+ (BOOL) isHardDiskFull __deprecated;
+ (NSData*) produceJPEGThumbnail:(NSImage*) image;
+ (int) DefaultFolderSizeForDB;
+ (long) computeDATABASEINDEXforDatabase:(NSString*) path __deprecated;
+ (void) encryptFileOrFolder: (NSString*) srcFolder inZIPFile: (NSString*) destFile password: (NSString*) password;
+ (void) encryptFileOrFolder: (NSString*) srcFolder inZIPFile: (NSString*) destFile password: (NSString*) password deleteSource: (BOOL) deleteSource;
+ (void) encryptFileOrFolder: (NSString*) srcFolder inZIPFile: (NSString*) destFile password: (NSString*) password deleteSource: (BOOL) deleteSource showGUI: (BOOL) showGUI;
+ (void) encryptFiles: (NSArray*) srcFiles inZIPFile: (NSString*) destFile password: (NSString*) password;
+ (int) localTotalNumberOfRawFiles: (NSArray*) localStudies;
- (IBAction) createDatabaseFolder:(id) sender;
- (IBAction) addAlbum:(id)sender;
- (IBAction) deleteAlbum: (id)sender;
- (IBAction) saveAlbums:(id) sender;
- (IBAction) addAlbums:(id) sender;
- (IBAction) defaultAlbums: (id) sender;
- (IBAction) clickBanner:(id) sender;
- (IBAction) refreshPACSOnDemandResults:(id)sender;
- (IBAction) drawerToggle: (id)sender;
- (void) openDatabasePath: (NSString*) path __deprecated;
- (NSArray*) albums;
- (NSManagedObjectID*) currentAlbumID: (DicomDatabase*) d;
- (DicomStudy*) selectedStudy;
- (NSArray*) selectedStudies;
- (DicomSeries*) selectedSeries;
- (BOOL) shouldTerminate: (id) sender;
- (void) databaseOpenStudy: (NSManagedObject*) item;
- (void) databaseOpenStudy: (NSManagedObject*) item useWindowsState: (BOOL) useWindowsState;
- (void) databaseOpenStudy:(DicomStudy*) currentStudy withProtocol:(NSDictionary*) currentHangingProtocol;
- (IBAction) databaseDoublePressed:(id)sender;
- (void) setDBDate;
- (void) emptyDeleteQueueNow: (id) sender;
- (void) saveDeleteQueue;
- (void) closeWaitWindowIfNecessary;
- (void) displayWaitWindowIfNecessary;
- (void) showEntireDatabase;
- (void) subSelectFilesAndFoldersToAdd: (NSArray*) filenames;
- (void)matrixNewIcon:(long) index : (NSManagedObject*)curFile;
- (NSPredicate*) smartAlbumPredicate:(NSManagedObject*) album;
- (NSPredicate*) smartAlbumPredicateString:(NSString*) string;
- (void) executeActionsForState: (NSNumber*) c;
- (void) pressCellForRow: (int) clickedRow column: (int) clickedColumn event: (NSEvent*) event identifier:(NSString*) identifier;
- (void) rightClickCommentCellForRow: (int) clickedRow column: (int) clickedColumn event: (NSEvent*) event;
- (void) emptyDeleteQueueThread;
- (void) emptyDeleteQueue:(id) sender;
- (BOOL)isUsingExternalViewer: (NSManagedObject*) item;
- (void) addFileToDeleteQueue:(NSString*) file;
- (NSString*) getNewFileDatabasePath: (NSString*) extension __deprecated;
- (NSString*) getNewFileDatabasePath: (NSString*) extension dbFolder: (NSString*) dbFolder __deprecated;
- (NSManagedObjectModel *) managedObjectModel __deprecated;

- (NSManagedObject*) findStudyUID: (NSString*) uid;
- (NSManagedObject*) findSeriesUID: (NSString*) uid;

- (NSManagedObjectContext *) localManagedObjectContext __deprecated;
- (NSManagedObjectContext *) localManagedObjectContextIndependentContext: (BOOL) independentContext __deprecated;

- (NSManagedObjectContext *) managedObjectContext __deprecated;
- (NSManagedObjectContext *) managedObjectContextIndependentContext:(BOOL) independentContext __deprecated;
- (NSManagedObjectContext *) managedObjectContextIndependentContext:(BOOL) independentContext path: (NSString *) path __deprecated;

- (NSManagedObjectContext *) defaultManagerObjectContext __deprecated;
- (NSManagedObjectContext *) defaultManagerObjectContextIndependentContext: (BOOL) independentContext __deprecated;

- (BOOL) isBonjour: (NSManagedObjectContext*) c __deprecated;
- (NSString *) localDocumentsDirectory __deprecated;
- (void) alternateButtonPressed: (NSNotification*)n;
- (NSArray*) childrenArray: (id) item __deprecated;
- (NSArray*) childrenArray: (id) item onlyImages:(BOOL) onlyImages __deprecated;
- (NSArray*) imagesArray: (id) item __deprecated;
- (NSArray*) imagesArray: (id) item preferredObject: (int) preferredObject __deprecated;
- (NSArray*) imagesArray: (id) item onlyImages:(BOOL) onlyImages __deprecated;
- (NSArray*) imagesArray: (id) item preferredObject: (int) preferredObject onlyImages:(BOOL) onlyImages __deprecated;
- (NSArray*) imagesPathArray: (NSManagedObject*) item __deprecated;
- (void) setNetworkLogs;
- (BOOL) isNetworkLogsActive;
- (void) computeTimeInterval;
- (IBAction) print: (id) sender;
- (void) ReadDicomCDRom:(id) sender __deprecated;
- (NSString*) INCOMINGPATH __deprecated;
- (NSString*) TEMPPATH __deprecated;
- (IBAction) matrixDoublePressed:(id)sender;
- (void) addURLToDatabaseEnd:(id) sender;
- (void) addURLToDatabase:(id) sender;
- (NSArray*) addURLToDatabaseFiles:(NSArray*) URLs;
- (BOOL) findAndSelectFile: (NSString*) path image: (DicomImage*) curImage shouldExpand: (BOOL) expand;
- (BOOL) findAndSelectFile: (NSString*) path image: (DicomImage*) curImage shouldExpand: (BOOL) expand extendingSelection: (BOOL) extendingSelection;
- (void) selectServer: (NSArray*) files;
- (long) saveDatabase __deprecated;
- (long) saveDatabase:(NSString*) path __deprecated;
- (long) saveDatabase: (NSString*)path context: (NSManagedObjectContext*) context __deprecated;
- (void) addDICOMDIR:(NSString*) dicomdir :(NSMutableArray*) files;
- (void) copyFilesIntoDatabaseIfNeeded: (NSMutableArray*)filesInput options: (NSDictionary*) options;
- (ViewerController*) loadSeries :(NSManagedObject *)curFile :(ViewerController*) viewer :(BOOL) firstViewer keyImagesOnly:(BOOL) keyImages;
- (void) loadNextPatient:(DicomImage *) curImage :(long) direction :(ViewerController*) viewer :(BOOL) firstViewer keyImagesOnly:(BOOL) keyImages;
- (void) loadNextSeries:(DicomImage *) curImage :(long) direction :(ViewerController*) viewer :(BOOL) firstViewer keyImagesOnly:(BOOL) keyImages;
- (ViewerController*) openViewerFromImages:(NSArray*) toOpenArray movie:(BOOL) movieViewer viewer:(ViewerController*) viewer keyImagesOnly:(BOOL) keyImages;
- (ViewerController*) openViewerFromImages:(NSArray*) toOpenArray movie:(BOOL) movieViewer viewer:(ViewerController*) viewer keyImagesOnly:(BOOL) keyImages tryToFlipData:(BOOL) tryToFlipData;
- (void) export2PACS:(id) sender;
+ (void)setPath:(NSString*)path relativeTo:(NSString*)dirPath forSeriesId:(int)seriesId kind:(NSString*)kind toSeriesPaths:(NSMutableDictionary*)seriesPaths; // used by +exportQuicktime
+ (void) exportQuicktime:(NSArray*)dicomFiles2Export :(NSString*)path :(BOOL)html :(BrowserController*)browser :(NSMutableDictionary*)seriesPaths;
- (void) exportQuicktimeInt:(NSArray*) dicomFiles2Export :(NSString*) path :(BOOL) html;
+ (void) multiThreadedImageConvert: (NSString*) what :(vImage_Buffer*) src :(vImage_Buffer *) dst :(float) offset :(float) scale;
- (IBAction) delItem:(id) sender;
- (void) proceedDeleteObjects: (NSArray*) objectsToDelete;
- (void) proceedDeleteObjectIDs: (NSArray*) objectIDsToDelete;
- (void) delObjects:(NSMutableArray*) objectsToDelete;
- (IBAction) selectFilesAndFoldersToAdd:(id) sender;
- (void) showDatabase:(id)sender;
- (BOOL) displayStudy: (DicomStudy*) study object:(NSManagedObject*) element command:(NSString*) execute;
- (IBAction) matrixPressed:(id)sender;
- (void) loadDatabase:(NSString*) path __deprecated;
- (void) viewerDICOMInt:(BOOL) movieViewer dcmFile:(NSArray *)selectedLines viewer:(ViewerController*) viewer;
- (void) viewerDICOMInt:(BOOL) movieViewer dcmFile:(NSArray *)selectedLines viewer:(ViewerController*) viewer tileWindows: (BOOL) tileWindows;
- (NSToolbarItem *) toolbar: (NSToolbar *)toolbar itemForItemIdentifier: (NSString *) itemIdent willBeInsertedIntoToolbar:(BOOL) willBeInserted;
- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar*)toolbar;
- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar*)toolbar;
- (BOOL) validateToolbarItem: (NSToolbarItem *) toolbarItem;
- (NSArray*) exportDICOMFileInt:(NSString*) location files:(NSMutableArray*) filesToExport objects:(NSMutableArray*) dicomFiles2Export;
- (NSArray*) exportDICOMFileInt: (NSDictionary*) parameters;

- (void) processOpenViewerDICOMFromArray:(NSArray*) toOpenArray movie:(BOOL) movieViewer viewer: (ViewerController*) viewer;
- (void) setDatabaseValue:(id) object item:(id) item forKey:(NSString*) key;
- (void) setupToolbar;
- (float) fontSize: (NSString*) type;
- (void) setTableViewRowHeight;
- (void) addAlbumsFile: (NSString*) file;
- (void) sendFilesToCurrentBonjourDB: (NSArray*) files __deprecated;
- (NSString*) getDatabaseFolderFor: (NSString*) path __deprecated;
- (NSString*) getDatabaseIndexFileFor: (NSString*) path __deprecated;
- (IBAction) copyToDBFolder: (id) sender;
- (IBAction)customize:(id)sender;
- (IBAction)showhide:(id)sender;
- (IBAction) selectAll3DSeries:(id) sender;
- (IBAction) selectAll4DSeries:(id) sender;
- (IBAction) switchSoundex: (id)sender;
- (void) exportDICOMFile:(id) sender;
- (void) viewerDICOM:(id) sender;
- (void)newViewerDICOM:(id) sender;
- (void) viewerDICOMKeyImages:(id) sender;
- (void) viewerDICOMMergeSelection:(id) sender;
- (NSPredicate*) patientsnamePredicate: (NSString*) s;
- (NSPredicate*) patientsnamePredicate: (NSString*) s soundex:(BOOL) soundex;
- (NSPredicate*) patientsnamePredicate: (NSString*) s soundex:(BOOL) soundex level: (NSString*) level;
- (IBAction)addSmartAlbum: (id)sender;
- (IBAction)search: (id)sender;
- (void) waitForDistantSearchThread;
- (void)_refreshDatabaseDisplay;
- (void) setSearchTypeTo: (NSNumber*) tag;
- (IBAction)setSearchType: (id)sender;
- (IBAction) saveDBListAs:(id) sender;
- (IBAction) openDatabase:(id) sender;
- (void) checkReportsDICOMSRConsistency __deprecated;
- (void) openDatabaseIn:(NSString*) a Bonjour:(BOOL) isBonjour __deprecated;
- (void) openDatabaseIn: (NSString*)a Bonjour: (BOOL)isBonjour refresh: (BOOL) refresh __deprecated;
- (void) browserPrepareForClose;
- (IBAction) endReBuildDatabase:(id) sender;
- (IBAction) ReBuildDatabaseSheet: (id)sender;
- (IBAction)rebuildSQLFile:(id)sender;
- (void) previewSliderAction:(id) sender;
- (void) addHelpMenu;
+ (NSString*) _findFirstDicomdirOnCDMedia: (NSString*)startDirectory __deprecated;
+ (BOOL)isItCD:(NSString*) path;
+ (NSArray*) zipExtensions;
- (void)storeSCPComplete:(id)sender;
- (void) changeStateValueTo: (int) tag forStudies: (NSArray*) studies;
- (NSMutableArray *) filesForDatabaseOutlineSelection :(NSMutableArray*) correspondingDicomFile;
- (NSMutableArray *) filesForDatabaseOutlineSelection :(NSMutableArray*) correspondingManagedObjects onlyImages:(BOOL) onlyImages;
- (NSMutableArray *) filesForDatabaseMatrixSelection :(NSMutableArray*) correspondingManagedObjects;
- (NSMutableArray *) filesForDatabaseMatrixSelection :(NSMutableArray*) correspondingManagedObjects onlyImages:(BOOL) onlyImages;
- (void)setToolbarReportIconForItem: (NSToolbarItem *)item;
- (void) addFiles: (NSArray*) files withRule:(NSDictionary*) routingRule __deprecated;
- (void) resetListenerTimer __deprecated;
- (IBAction) editAlbum: (id)sender;
//- (IBAction) smartAlbumHelpButton:(id) sender;
- (IBAction) regenerateAutoComments:(id) sender;
- (DCMPix *)previewPix:(int)i;
- (NSArray*) addFilesToDatabase:(NSArray*) newFilesArray __deprecated;
- (void) addFilesAndFolderToDatabase:(NSArray*) filenames __deprecated;
- (NSArray*) addFilesToDatabase:(NSArray*) newFilesArray onlyDICOM:(BOOL) onlyDICOM  produceAddedFiles:(BOOL) produceAddedFiles __deprecated;
- (NSArray*) addFilesToDatabase:(NSArray*) newFilesArray onlyDICOM:(BOOL) onlyDICOM  produceAddedFiles:(BOOL) produceAddedFiles parseExistingObject:(BOOL) parseExistingObject __deprecated;
- (NSArray*) addFilesToDatabase:(NSArray*) newFilesArray onlyDICOM:(BOOL) onlyDICOM  produceAddedFiles:(BOOL) produceAddedFiles parseExistingObject:(BOOL) parseExistingObject context: (NSManagedObjectContext*) context dbFolder:(NSString*) dbFolder __deprecated;
- (NSArray*) addFilesToDatabase:(NSArray*) newFilesArray onlyDICOM:(BOOL) onlyDICOM  safeRebuild:(BOOL) safeRebuild produceAddedFiles:(BOOL) produceAddedFiles __deprecated;
+(NSArray*)addFiles:(NSArray*)newFilesArray toContext:(NSManagedObjectContext*)context onlyDICOM:(BOOL)onlyDICOM  notifyAddedFiles:(BOOL)notifyAddedFiles parseExistingObject:(BOOL)parseExistingObject dbFolder:(NSString*)dbFolder __deprecated;
+(NSArray*)addFiles:(NSArray*)newFilesArray toContext:(NSManagedObjectContext*)context toDatabase:(BrowserController*)browserController onlyDICOM:(BOOL)onlyDICOM  notifyAddedFiles:(BOOL)notifyAddedFiles parseExistingObject:(BOOL)parseExistingObject dbFolder:(NSString*)dbFolder __deprecated;
+(NSArray*)addFiles:(NSArray*)newFilesArray toContext:(NSManagedObjectContext*)context toDatabase:(BrowserController*)browserController onlyDICOM:(BOOL)onlyDICOM  notifyAddedFiles:(BOOL)notifyAddedFiles parseExistingObject:(BOOL)parseExistingObject dbFolder:(NSString*)dbFolder generatedByOsiriX:(BOOL)generatedByOsiriX __deprecated;
+(NSArray*) addFiles:(NSArray*) newFilesArray toContext: (NSManagedObjectContext*) context toDatabase: (BrowserController*) browserController onlyDICOM: (BOOL) onlyDICOM  notifyAddedFiles: (BOOL) notifyAddedFiles parseExistingObject: (BOOL) parseExistingObject dbFolder: (NSString*) dbFolder generatedByOsiriX: (BOOL) generatedByOsiriX mountedVolume: (BOOL) mountedVolume __deprecated;
+ (BOOL) unzipFile: (NSString*) file withPassword: (NSString*) pass destination: (NSString*) destination;
+ (BOOL) unzipFile: (NSString*) file withPassword: (NSString*) pass destination: (NSString*) destination showGUI: (BOOL) showGUI;
- (int) askForZIPPassword: (NSString*) file destination: (NSString*) destination;
- (IBAction) reparseIn3D:(id) sender;
- (IBAction) reparseIn4D:(id) sender;
- (void)selectStudyWithObjectID:(NSManagedObjectID*)oid;
- (BOOL) selectThisStudy: (id)study;
- (BOOL) selectThisStudy: (NSManagedObject*)study changeAlbumIfNecessary: (BOOL) changeAlbumIfNecessary;
- (NSArray*) outlineViewArray;
- (void) previewPerformAnimation:(id) sender;
- (void) matrixDisplayIcons:(id) sender;
- (void) selectDatabaseOutline;
- (IBAction) loadWindowsState:(id) sender;
- (NSArray*) KeyImages: (id) sender;
- (NSArray*) ROIImages: (id) sender;
- (NSArray*) ROIsAndKeyImages: (id) sender;
- (NSArray*) ROIsAndKeyImages: (id) sender sameSeries: (BOOL*) sameSeries;

- (void) refreshColumns;
- (NSString*) outlineViewRefresh;
- (void) matrixInit:(long) noOfImages;
- (void)matrixLoadIcons: (NSDictionary*)dict;
- (NSArray*) albumArray;
- (void) refreshAlbums;
- (void) waitForRunningProcesses;

- (void) autoCleanDatabaseFreeSpace:(id) sender __deprecated;
- (void) autoCleanDatabaseDate:(id) sender __deprecated;

- (void) refreshDatabase:(id) sender;
- (void) syncReportsIfNecessary;

//bonjour
-(NSManagedObjectContext*)bonjourManagedObjectContext __deprecated;
- (void) setBonjourDatabaseValue:(NSManagedObject*) obj value:(id) value forKey:(NSString*) key __deprecated;
- (NSString*) getLocalDCMPath: (NSManagedObject*) obj :(long) no;
- (void) displayBonjourServices;
- (NSString*) askPassword;
- (void) resetToLocalDatabase;
- (void) switchToDefaultDBIfNeeded __deprecated;
- (void) checkIncomingThread:(id) sender __deprecated;
- (void) checkIncoming:(id) sender __deprecated;
- (void) checkIncomingNow:(id) sender __deprecated;
- (NSArray*) openSubSeries: (NSArray*) toOpenArray;
- (IBAction) checkMemory:(id) sender;
- (IBAction) buildAllThumbnails:(id) sender;

//DB plugins
- (void)executeFilterDB:(id)sender;

+ (NSString*) defaultDocumentsDirectory  __deprecated;
- (NSString *)documentsDirectoryFor:(int) mode url:(NSString*) url  __deprecated;
- (IBAction)showLogWindow: (id)sender;
- (void) resetLogWindowController;

- (NSString *)folderPathResolvingAliasAndSymLink:(NSString *)path __deprecated;
- (void) testDatabaseWindowResolution;
- (void)setFilterPredicate:(NSPredicate *)predicate description:(NSString*) desc;
- (NSPredicate *)createFilterPredicate;
- (NSString *)createFilterDescription;
- (void) willChangeContext;

- (IBAction) deleteReport: (id) sender;
- (IBAction) convertReportToPDF: (id)sender;
- (IBAction) convertReportToDICOMSR: (id)sender;

- (IBAction) rebuildThumbnails:(id) sender;
- (IBAction)selectNoAlbums:(id)sender;
- (BOOL) selectAlbumWithName: (NSString*) name;
- (NSArray *)databaseSelection;

+ (BOOL) asyncWADOXMLDownloadURL:(NSURL*) url;

- (void) refreshMatrixThumbnail: (NSManagedObject*) object;
- (void) refreshMatrix:(id) sender;
- (void)updateReportToolbarIcon:(NSNotification *)note;

#ifndef OSIRIX_LIGHT
- (IBAction) exportROIAndKeyImagesAsDICOMSeries: (id) sender;
- (IBAction) paste: (id)sender;
- (IBAction) pasteImageForDicomImage: (DicomImage*) image;
- (void) decompressDICOMJPEG: (NSArray*) array __deprecated;
- (void) compressDICOMJPEG:(NSArray*) array __deprecated;
- (void) decompressArrayOfFiles: (NSArray*) array work:(NSNumber*) work __deprecated;
- (IBAction) compressSelectedFiles:(id) sender;
- (IBAction) decompressSelectedFiles:(id) sender;
- (void) importReport:(NSString*) path UID: (NSString*) uid;
- (IBAction) generateReport: (id) sender;
- (IBAction) attachReport: (id) sender;
- (IBAction)importRawData:(id)sender;
- (void) pdfPreview:(id)sender;
- (IBAction) burnDICOM:(id) sender;
- (IBAction) anonymizeDICOM:(id) sender;
- (IBAction)retrieveSelectedPODStudies:(id) sender;
- (void) queryDICOM:(id) sender;
- (IBAction) querySelectedStudy:(id) sender;
- (void) refreshComparativeStudies: (NSArray*) newStudies;
- (NSMutableArray*) comparativeStudiesForStudy: (DicomStudy*) currentStudy protocol: (NSDictionary*) currentHangingProtocol;
+ (NSArray*) comparativeServers;
- (IBAction) viewXML:(id) sender;
- (void) unifyPatientIdentitiesForStudies: (NSArray*) studiesArray dictionary: (NSDictionary*) dict merge: (BOOL)  merge;
#endif

- (BOOL) unifyOKEnabled;
- (void) retrieveComparativeStudy: (DCMTKStudyQueryNode*) study select: (BOOL) select open: (BOOL) open;
- (void) retrieveComparativeStudy: (DCMTKStudyQueryNode*) study select: (BOOL) select open: (BOOL) open showGUI: (BOOL) showGUI viewer: (ViewerController*) viewer;
- (void) refreshComparativeStudiesIfNeeded:(id) timer;
- (NSArray*) distantStudiesForSmartAlbum: (NSString*) albumName;
- (NSDictionary*) PACSOnDemandDictionaryForThisSmartAlbumName: (NSString*) albumName;
- (void) initAnimationSlider;

+ (id) localObjectForDistantObject: (DCMTKQueryNode*) o __deprecated;
+ (NSArray*) localObjectsForDistantObject: (DCMTKQueryNode*) o __deprecated;
- (void) setSearchString: (NSString *)searchString;

+ (NSString*) DateTimeWithSecondsFormat:(NSDate*) t;
+ (NSString*) TimeWithSecondsFormat:(NSDate*) t;
+ (NSString*) DateOfBirthFormat:(NSDate*) d __deprecated;
+ (NSString*) DateTimeFormat:(NSDate*) d __deprecated;
+ (NSString*) TimeFormat:(NSDate*) t;

+ (BOOL) isIdenticalLocalStudy: (DicomStudy*) localStudy toDistantStudy: (DCMTKStudyQueryNode*) distantStudy;
- (int) findObject:(NSString*) request table:(NSString*) table execute: (NSString*) execute elements:(NSString**) elements __deprecated;

// - (void) executeSend :(NSArray*) samePatientArray server:(NSDictionary*) server dictionary:(NSDictionary*) dict __deprecated;

- (void)writeMovie:(NSArray*)imagesArray name:(NSString*)fileName;
- (void) buildThumbnail:(NSManagedObject*) series;

/******Notifactions posted by browserController***********
OsirixNewStudySelectedNotification with userinfo key @"Selected Study" posted when a newStudy is selected in the browser
@"Close All Viewers" posted when close open windows if option key pressed.	
@"DCMImageTilingHasChanged" when image tiling has changed
*/

+(NSInteger)_scrollerStyle:(NSScroller*)scroller;

#pragma mark Deprecated

@property(readonly) NSManagedObjectContext *userManagedObjectContext __deprecated;
@property(readonly) NSManagedObjectModel *userManagedObjectModel __deprecated;

-(long)saveUserDatabase __deprecated;
-(WebPortalUser*)userWithName:(NSString*)name __deprecated;



@end

#import "BrowserController+Sources.h"
