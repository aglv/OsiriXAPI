/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

#define REGPHPURL @"reg/reg.php"
#define REGPHPOVHURL @"reg/min/index.php"
#define WSPHPURL @"ws/ws.php"

@interface Registration : NSObject
+ (BOOL) isOVHServerRespondingWithParameters: (NSDictionary*) d;
+ (BOOL) isOVHServerRespondingWithParameters: (NSDictionary*) d rootCause:(NSString*) rc;
+ (NSString*) stringFromEncodedArray:(NSArray*) array;
+ (NSString*) stringFromEncodedArray:(NSArray*) array validServerResponse: (BOOL*) validServerResponse;
+ (NSString*) stringFromEncodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSString*) stringFromEncodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters validServerResponse: (BOOL*) validServerResponse;
+ (NSString*) encodedStringWithParameters:(NSDictionary*) parameters;
+ (NSString*) encodedStringWithParameters:(NSDictionary*) parameters urlEncoded: (BOOL) urlEncoded;
+ (NSURL*) encodedURLWithPath:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSArray*) arrayFromEncodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSArray*) POSTJSON:(id) json encodedToURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSArray*) POSTData:(NSData*) dataToPost encodedToURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSString*) stringFromPOSTJSON: (id) json encodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (id) dictionaryOrArrayFromPOSTJSON: (id) json encodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSString*) stringFromPOSTData: (NSData*) dataToPOST encodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (id) dictionaryOrArrayFromEncodedURL:(NSString*) pathURL withParameters:(NSDictionary*) parameters;
+ (NSData*) encodeData:(NSData*) dataIn;
+ (NSData*) decodeData:(NSData*) dataIn;
+ (NSDictionary*) loadRegistrationDictionary;
+ (NSDictionary*) loadRegistrationDictionaryReload:(BOOL) reload;
+ (void) saveRegistrationDictionary: (NSDictionary*) dict;
+ (NSString*) machineModel;
+ (NSString*) OSXVersion;
+ (NSArray*) IPv4Address;
+ (NSString*) IPv4AddressAsString;
+ (NSHost*) currentHost;
+ (void) DNSResolve:(id) o;
+ (NSArray*) currentHostNames;
+ (NSArray*) currentHostAddresses;
+ (NSString*) MACAddress;
+ (NSURL*) baseURL;
+ (NSURL*) baseOVHURL;
@end
