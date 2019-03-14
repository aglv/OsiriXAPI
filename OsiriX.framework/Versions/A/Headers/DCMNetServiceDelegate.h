/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

enum
{
	CMOVERetrieveMode = 0,
	CGETRetrieveMode = 1,
	WADORetrieveMode = 2,
    WADORSRetrieveMode = 3
};

enum
{
    kHostNotReachable = -2,
    kServiceNotReachable = -1,
    kUnknownHostState = 0,
    kServiceReachable = 1
};

#import <Cocoa/Cocoa.h>

/** \ brief Eanbles DICOM Bonjour */
@interface DCMNetServiceDelegate : NSObject <NSNetServiceDelegate, NSNetServiceBrowserDelegate>
{
	NSNetServiceBrowser *_dicomNetBrowser;
	NSMutableArray *_dicomServices;
	NSNetService *publisher;
    BOOL browserRunning;
}

+ (NSString*) gethostnameAndPort: (int*) port forService:(NSNetService*) sender;
+ (NSArray *) DICOMServersList;
+ (NSMutableDictionary*)DICOMNodeInfoFromTXTRecordData:(NSData*)data;
+ (NSString*) emojiForState:(int) state;
+ (NSArray *) DICOMServersListSendOnly: (BOOL) send QROnly:(BOOL) QR;
+ (NSDictionary*) serverForHostname:(NSString*) hostname port: (int) port;
+ (NSString*) getIPAddress: (NSString*) address;
+ (id)sharedNetServiceDelegate;
- (void) setPublisher: (NSNetService*) p;
- (void)update;
- (NSArray *)dicomServices;
- (int)portForNetService:(NSNetService *)netService;

- (NSMutableArray *) cachedDICOMServersList;
- (NSTimeInterval) lastCachedDICOMServersList;

@end
