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
#import "HTTPConnection.h"
#import "WebPortalUser.h"

@class WebPortal, WebPortalDatabase, WebPortalServer, WebPortalSession, WebPortalResponse, DicomDatabase;

@interface WebPortalConnection : HTTPConnection
{
    BOOL dealloc;
    
	NSLock *sendLock, *running;
	WebPortalUser* user;
	WebPortalSession* session;
	
	NSString* requestedPath;
	NSString* GETParams;
    NSURL* requestedURL;
	NSDictionary* parameters; // GET and POST params
	
	WebPortalResponse* response;
	
    DicomDatabase* _independentDicomDatabase;
    NSThread* _independentDicomDatabaseThread;
    
    WebPortalDatabase* _independentDatabase;
    NSThread* _independentDatabaseThread;
    
    // POST / PUT support
    NSMutableData *STOWRSData;
    NSMutableArray *STOWRSDicomFiles;
    NSMutableDictionary *STOWRSLogEntry;
	NSArray *partsFromPOSTData;
    
#ifndef NDEBUG
    NSThread *initThread;
#endif
}

-(CFHTTPMessageRef)request;

@property(retain,readonly) WebPortalResponse* response;
@property(retain, nonatomic) WebPortalSession* session;
@property(retain) WebPortalUser* user;
@property(retain) NSDictionary* parameters;
@property(retain) NSString* GETParams;
@property(retain) NSURL* requestedURL;
@property(readonly) DicomDatabase* independentDicomDatabase;
@property(readonly) WebPortalDatabase* independentDatabase;

@property(assign,readonly) WebPortalServer* server;
@property(assign,readonly) WebPortal* portal;
@property(assign,readonly) AsyncSocket* asyncSocket;

@property(readonly) NSArray *partsFromPOSTData;

+(NSString*)FormatParams:(NSDictionary*)dict;
+(NSDictionary*)ExtractParams:(NSString*)paramsString;
+(NSString*) cleanUsername: (NSString*) username;

-(BOOL)requestIsIPhone;
-(BOOL)requestIsIPad;
-(BOOL)requestIsIPod;
-(BOOL)requestIsIOS;
-(BOOL)requestIsMacOS;
-(NSString*)contentType;
-(NSString*)acceptHeader;
-(NSString*)requestMethod;

-(NSString*)portalURL;
-(NSString*)dicomCStorePortString;
- (void) resetPOST;
- (void) fillSessionAndUserVariables;

@end

