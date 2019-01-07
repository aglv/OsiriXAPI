/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>

enum _PixmeoSessionState {
    PixmeoSessionStateInvalidSession = 0,
    PixmeoSessionStateValidSession,
    PixmeoSessionStateNoSession,
    PixmeoSessionStateServerUnavailable,
    PixmeoSessionStateOtherError
};
typedef NSInteger PixmeoSessionState;

@interface Subscriptions : NSObject
{
    NSString *password, *username, *session_uuid;
    NSMutableArray *subscriptions;
    BOOL logged, SMSCodeAsked, SMSCodeCancelled, hideError;
    int passwordErrorCount;
    NSTimeInterval lastCheckSession;
    NSTimer *checkSessionTimer;
    PixmeoSessionState lastPixmeoSessionState;
}

@property (retain, nonatomic) NSArray *subscriptions;
@property (retain) NSTimer *checkSessionTimer;
@property (readonly) NSString *session_uuid;
@property (readonly) BOOL logged;
@property BOOL hideError;

+ (Subscriptions*) sharedInstance;
+ (void) displayErrorOnMainThread: (NSDictionary*) error;
+ (BOOL) displayErrorIfInvalidSession;

- (id) initWithUsername: (NSString*) usr;
- (void) downloadSubcriptions;
- (BOOL) login;
- (BOOL) loginBlocking: (BOOL) blocking;
- (BOOL) loginBlocking: (BOOL) blocking password: (NSString*) pwd;
- (BOOL) isSignedInForUUID:(NSString*) uuid;
- (BOOL) checkSessionForUUID:(NSString*) uuid;
- (PixmeoSessionState) checkPixmeoSession;
- (BOOL) logout;
- (void) resetPasswordErrorCount;
- (NSMutableDictionary*) subscriptionForCloudStorageUUID: (NSString*) uuid;
- (NSMutableDictionary*) subscriptionForUUID: (NSString*) uuid;
- (void) setLocalPrefTo: (id) value forKey: (id) key forUUID: (NSString*) uuid;
- (NSString*) cTokenForUUID:(NSString*) uuid;
- (NSString*) cTokenForUUID:(NSString*) uuid showError: (BOOL) showError;
- (NSString*) gTokenForUUID:(NSString*) uuid;
- (NSString*) gTokenForUUID:(NSString*) uuid showError: (BOOL) showError;
- (NSString*) refreshgTokenForUUID: (NSString*) uuid showError:(BOOL) showError;
+ (BOOL) signinWithgToken: (NSString*) gToken UUID:(NSString*) uuid baseURL:(NSString*) baseURL showError:(BOOL) showError;
@end
