/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

extern NSString* const SessionIPAddressKey;
extern NSString* const SessionUsernameKey; // NSString
extern NSString* const SessionCookieName;
extern NSString* const SessionLastActivityDateKey; // NSDate
extern NSString* const SessionUserIDKey;
extern NSString* const SessionDontDisplayUser;

@interface WebPortalSession : NSObject {
@private
	NSMutableDictionary* dict;
	NSString* sid, *ipAddr;
	NSLock* dictLock;
    
    BOOL requireDoubleAuthentication, doubleAuthenticated;
    NSString *doubleAuthenticationToken;
    NSString *usernameForDoubleAuthentication;
    NSTimeInterval timeStampForDoubleAuthentication;
    
    NSTimeInterval sessionCreationDateTimeInterval;
}

@property(readonly) NSString* sid;
@property(readonly) NSMutableDictionary* dict;
@property BOOL requireDoubleAuthentication, doubleAuthenticated;
@property(retain) NSString *doubleAuthenticationToken, *usernameForDoubleAuthentication;
@property NSTimeInterval timeStampForDoubleAuthentication, sessionCreationDateTimeInterval;

-(id)initWithId:(NSString*)isid;

-(void)setObject:(id)o forKey:(NSString*)k;
-(id)objectForKey:(NSString*)k;

-(NSString*)createToken;
-(BOOL)consumeToken:(NSString*)token;
-(BOOL)containsToken:(NSString*)token;
-(NSString*)newChallenge;
-(NSString*)challenge;
-(void)deleteChallenge;

@end

