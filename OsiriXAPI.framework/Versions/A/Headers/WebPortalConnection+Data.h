/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import "WebPortalConnection.h"

@class DicomStudy;

@interface WebPortalConnection (Data)

+(NSArray*)MakeArray:(id)obj;

-(void)getWidth:(CGFloat*)width height:(CGFloat*)height fromImagesArray:(NSArray*)imagesArray;
-(void)getWidth:(CGFloat*)width height:(CGFloat*)height fromImagesArray:(NSArray*)imagesArray minSize:(NSSize)minSize maxSize:(NSSize)maxSize;

-(void)processLoginHtml;
-(void)processDoubleAuthenticationLoginHtml;
-(void)processIndexHtml;
-(void)processMainHtml;
-(void)processStudyListHtml;
-(void)processLogsListHtml;
-(void)processKeyROIsImagesHtml;
-(void)processSeriesHtml;
-(void)processStudyHtml;
-(void)processStudyHtml: (NSString*) xid;
-(void)processPasswordForgottenHtml;
-(void)processAccountHtml;
-(void)processClearCaches;
-(void)processLogHTTPRequest;

-(void)processAdminIndexHtml;
-(void)processAdminUserHtml;

-(void)processStudyListJson;
-(void)processSeriesJson;
-(void)processAlbumsJson;
-(void)processSeriesListJson;
-(void)processHTMLReportTemplate;
-(void)processHTMLReport;
-(void)processHTMLReportFrontMost2DViewerImage;
-(BOOL)processWado;

-(void)processWeasisJnlp;
-(void)processWeasisXml;
-(void) processOHIFJson;
-(void)processThumbnail;
-(void)processReport;
-(void)processSeriesPdf;
-(void)processZip;
-(void)processImage;
-(void)processImageAsScreenCapture: (BOOL) asDisplayed;
-(void)processMovie;

-(id)objectWithXID:(NSString*)xid;
-(id)objectWithXID:(NSString*)xid compareToDistant: (BOOL) compareToDistant checkUserAutorisation: (BOOL) checkUserAutorisation;
-(void)receiveReportHtmlAsPOST;

-(void) addDoubleAuthenticationUserEvent: (NSString*) username;
-(NSTimeInterval) delayForDoubleAuthenticationUser: (NSString*) username;
- (void) resetDoubleAuthenticationEventsForUser:(NSString*) username;

+ (NSDictionary*) processOHIFJsonWithStudies: (NSArray*) requestedStudies series:(NSArray*) requestedSeries baseURL:(NSString*) baseURL mobile:(BOOL) isMobile wadoSyntax: (NSString*) ws filesForInstanceUID: (NSDictionary*) filesDictionary;
+ (NSDictionary*) processOHIFJsonWithStudies: (NSArray*) requestedStudies series:(NSArray*) requestedSeries baseURL:(NSString*) baseURL mobile:(BOOL) isMobile wadoSyntax: (NSString*) ws filesForInstanceUID: (NSDictionary*) filesDictionary anonymized: (BOOL) anonymized;
+ (NSDictionary*) processOHIFJsonWithStudies: (NSArray*) requestedStudies series:(NSArray*) requestedSeries addCommentsAndStatus: (BOOL) addCommentsAndStatus;
@end

