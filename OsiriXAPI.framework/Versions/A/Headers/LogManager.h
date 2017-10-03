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

@class DicomDatabase;

/** \brief Managed network logging */
@interface LogManager : NSObject
{
	NSMutableDictionary *_currentLogs;
}

+ (void) logToFileNetworkEvent: (NSManagedObject*) logEntry;
+ (id) currentLogManager;
- (void) resetLogs;
- (void) addLogLine: (NSDictionary*) dict;

@end
