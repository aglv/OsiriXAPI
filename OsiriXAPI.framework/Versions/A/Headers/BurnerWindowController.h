/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>
#import <DiscRecordingUI/DRSetupPanel.h>
#import <DiscRecordingUI/DRBurnSetupPanel.h>
#import <DiscRecordingUI/DRBurnProgressPanel.h>

enum burnerDestination
{
    CDDVD = 0,
    USBKey = 1,
    DMGFile = 2
};

@class DRTrack;
@class DicomDatabase;
@class DicomImage;

/** \brief Window Controller for DICOM disk burning */
@interface BurnerWindowController : NSWindowController <NSWindowDelegate>
{
	volatile BOOL burning;
	NSMutableArray *files, *anonymizedFiles, *dbObjectsID, *originalDbObjectsID;
	float burnSize;
	IBOutlet NSTextField *sizeField;
	IBOutlet NSMatrix	 *compressionMode;
	IBOutlet NSButton *burnButton;
	IBOutlet NSButton *anonymizedCheckButton;
	NSString *cdName;
	NSTimer *burnAnimationTimer;
	volatile BOOL runBurnAnimation, isExtracting, isSettingUpBurn, isThrobbing, windowWillClose;
	BOOL _multiplePatients;
	BOOL cancelled;
    NSString *writeDMGPath, *writeVolumePath;
    NSUInteger selectedUSB;
	NSArray *anonymizationTags;
    int sizeInMb;
	NSString *password;
	IBOutlet NSWindow *passwordWindow;
	
	BOOL buttonsDisabled;
	BOOL burnSuppFolder, burnOsiriX, burnHtml;
    
	int burnAnimationIndex;
    int irisAnimationIndex;
    NSTimer *irisAnimationTimer;
    
    DRBurn *drburn;
}

@property BOOL buttonsDisabled, burning;
@property NSUInteger selectedUSB;
@property (retain, nonatomic) NSString *password, *cdName;
@property (retain) DRBurn *drburn;

+ (void) writeJSViewerImages: (NSArray<DicomImage*>*) dbObjects filesForSOPInstanceUID: (NSDictionary*) filesForSOPInstanceUID toFolder: (NSString *) burnFolder anonymized: (BOOL) anonymized;

- (NSArray*) volumes;
- (IBAction) ok:(id)sender;
- (IBAction) cancel:(id)sender;
- (IBAction) setAnonymizedCheck: (id) sender;
- (id)initWithObjects:(NSArray *)managedObjects;
- (id)initWithFiles:(NSArray *)theFiles managedObjects:(NSArray *)managedObjects;
- (IBAction)burn:(id)sender;
- (NSString *)folderToBurn;
- (void)burnCD:(id)object;
- (NSArray *)extractFileNames:(NSArray *)filenames;
- (void)importFiles:(NSArray *)fileNames;
- (void)setup:(id)sender;
- (void) prepareCDContent: (NSMutableArray*) dbObjects :(NSMutableArray*) originalDbObjects;
- (IBAction)estimateFolderSize:(id)object;
- (void)performBurn:(id)object;
- (void)irisAnimation:(NSTimer*)object;
- (NSString*) defaultTitle;
- (void)saveOnVolume;
@end
