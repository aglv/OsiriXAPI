/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

@class DicomDatabase;
@class DicomStudy;

/** \brief Managed network logging */
@interface LogManager : NSObject
{
	NSMutableDictionary *_currentLogs;
}

+ (void) logToFileNetworkEvent: (NSManagedObject*) logEntry;
+ (id) currentLogManager;
- (void) resetLogs;
- (void) addLogLine: (NSDictionary*) dict;
- (void) addDisplayLogLineForStudy: (DicomStudy*) study;
- (void) addLogLineForStudy: (DicomStudy*) study message: (NSString*) message;
@end
