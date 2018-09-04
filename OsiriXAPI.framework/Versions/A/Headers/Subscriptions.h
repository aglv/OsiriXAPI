/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>

@interface Subscriptions : NSObject
{
    NSString *password, *username, *session_uuid;
    NSMutableArray *subscriptions;
    BOOL logged, SMSCodeAsked, SMSCodeCancelled;
    int passwordErrorCount;
    NSTimeInterval lastCheckSession;
}

@property (retain, nonatomic) NSArray *subscriptions;
@property (readonly) NSString *session_uuid;
@property (readonly) BOOL logged;

+ (Subscriptions*) sharedInstance;
+ (void) displayErrorOnMainThread: (NSDictionary*) error;

- (id) initWithUsername: (NSString*) usr;
- (BOOL) login;
- (BOOL) loginBlocking: (BOOL) blocking;
- (BOOL) isSignedInForUUID:(NSString*) uuid;
- (BOOL) checkForUUID:(NSString*) uuid;
- (BOOL) logout;
- (void) resetPasswordErrorCount;
- (NSMutableDictionary*) subscriptionForUUID: (NSString*) uuid;

- (NSString*) cTokenForUUID:(NSString*) uuid;
- (NSString*) cTokenForUUID:(NSString*) uuid showError: (BOOL) showError;
- (NSString*) gTokenForUUID:(NSString*) uuid;
- (NSString*) gTokenForUUID:(NSString*) uuid showError: (BOOL) showError;
+ (BOOL) signinWithgToken: (NSString*) gToken UUID:(NSString*) uuid baseURL:(NSString*) baseURL showError:(BOOL) showError;
@end
