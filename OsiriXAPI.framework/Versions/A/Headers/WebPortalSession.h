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

extern NSString* const SessionUsernameKey; // NSString
extern NSString* const SessionCookieName;
extern NSString* const SessionLastActivityDateKey; // NSDate
extern NSString* const SessionUserIDKey;
extern NSString* const SessionDontDisplayUser;

@interface WebPortalSession : NSObject {
@private
	NSMutableDictionary* dict;
	NSString* sid;
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

