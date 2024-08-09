/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2024 Pixmeo SARL
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
    NSMutableArray *authenticationsForBonjourServices;
    
	NSNetService *dicomPublisher, *dicomWebPublisher;
    BOOL browserRunning;
}

@property (retain) NSNetService *dicomPublisher, *dicomWebPublisher;

+ (NSString*) gethostnameAndPort: (int*) port forService:(NSNetService*) sender;
+ (NSArray *) DICOMServersList;
+ (NSMutableDictionary*)DICOMNodeInfoFromTXTRecordData:(NSData*)data;
+ (NSString*) emojiForState:(int) state;
+ (NSArray *) DICOMServersListSendOnly: (BOOL) send QROnly:(BOOL) QR;
+ (NSArray *) DICOMServersListSendOnly: (BOOL) send QROnly:(BOOL) QR includeBonjour: (BOOL) includeBonjour;
+ (NSDictionary*) serverForHostname:(NSString*) hostname port: (int) port;
+ (NSString*) getIPAddress: (NSString*) address;
+ (id)sharedNetServiceDelegate;
- (void)update;
- (NSArray *)dicomServices;
- (int)portForNetService:(NSNetService *)netService;

- (NSMutableArray *) cachedDICOMServersList;
- (NSTimeInterval) lastCachedDICOMServersList;

- (NSDictionary*) authenticationForBonjourService: (NSDictionary*) s;
- (void) addAuthenticationForBonjourService: (NSDictionary*) s username: (NSString*) username password: (NSString*) password;
@end
