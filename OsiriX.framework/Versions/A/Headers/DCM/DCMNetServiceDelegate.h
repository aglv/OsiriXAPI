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

enum
{
	CMOVERetrieveMode = 0,
	CGETRetrieveMode = 1,
	WADORetrieveMode = 2 __deprecated_msg("only in OsiriX"),
    WADORSRetrieveMode = 3 __deprecated_msg("only in OsiriX")
};

#import <Cocoa/Cocoa.h>

/** \ brief Eanbles DICOM Bonjour */
@interface DCMNetServiceDelegate : NSObject <NSNetServiceDelegate, NSNetServiceBrowserDelegate>
{
	NSNetServiceBrowser *_dicomNetBrowser;
	NSMutableArray *_dicomServices;
	NSNetService *publisher;
    BOOL browserRunning __deprecated_msg("only in OsiriX");
}
+ (NSString*) gethostnameAndPort: (int*) port forService:(NSNetService*) sender;
+ (NSArray *) DICOMServersList;
+ (NSMutableDictionary*)DICOMNodeInfoFromTXTRecordData:(NSData*)data;
+ (NSArray *) DICOMServersListSendOnly: (BOOL) send QROnly:(BOOL) QR;
+ (NSDictionary*) serverForHostname:(NSString*) hostname port: (int) port;
+ (NSString*) getIPAddress: (NSString*) address;
+ (id)sharedNetServiceDelegate;
- (void) setPublisher: (NSNetService*) p;
- (void)update;
- (NSArray *)dicomServices;
- (int)portForNetService:(NSNetService *)netService;

@end
