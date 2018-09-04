/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>
#import <Carbon/Carbon.h>

enum {kMicrosoftWordReport = 0,
    kRTFReport = 1,
    kPagesReport = 2,
    kPluginReport = 3,
    kOpenOfficeReport = 5,
    kHTMLReport = 6};

@class DicomStudy;

/** \brief reports */
@interface Reports : NSObject
{
	NSMutableString *templateName;
    NSString *templateFilename;
}

@property (retain) NSString *templateFilename;

+ (NSString*) getUniqueFilename:(DicomStudy*) study;
+ (NSString*) getOldUniqueFilename:(NSManagedObject*) study;

- (BOOL)createNewReport:(DicomStudy*) study destination:(NSString*)path type:(int)type;

+(NSString*)databaseWordTemplatesDirPath;
+(NSString*)resolvedDatabaseWordTemplatesDirPath;

- (BOOL) createNewPagesReportForStudy:(NSManagedObject*)aStudy toDestinationPath:(NSString*)aPath;
- (BOOL) createNewOpenDocumentReportForStudy:(NSManagedObject*)aStudy toDestinationPath:(NSString*)aPath;
+ (NSArray*)pagesTemplatesList;
+ (NSArray*)wordTemplatesList;
- (NSMutableString *)templateName;
- (void)setTemplateName:(NSString *)aName;
+ (int) Pages5orHigher;
+ (void)checkForPagesTemplate;
+ (void)checkForWordTemplates;
+ (NSDictionary*) searchAndReplaceFieldsFromStudy:(DicomStudy*)aStudy inString:(NSMutableString*)aString;
+ (NSDictionary*) searchAndReplaceFieldsFromStudy:(DicomStudy*)aStudy inString:(NSMutableString*)aString testValidFields: (BOOL) testValidFields htmlEncoding: (BOOL) htmlEncoding;
+ (NSString*) getDICOMStringValueForField: (NSString*) rawField inDICOMFile: (NSString*) path;
@end
