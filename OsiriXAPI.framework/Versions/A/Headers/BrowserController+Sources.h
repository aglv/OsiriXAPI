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

#import "browserController.h"

@class DataNodeIdentifier, DicomDatabase;

@interface BrowserController (Sources)

-(void)awakeSources;
-(void)deallocSources;

-(void)redrawSources;

-(DataNodeIdentifier*)sourceIdentifierAtRow:(int)row;
-(int)rowForDatabase:(DicomDatabase*)database;
-(DataNodeIdentifier*)sourceIdentifierForDatabase:(DicomDatabase*)database;
-(void)selectCurrentDatabaseSource;

-(int)findDBPath:(NSString*)path dbFolder:(NSString*)DBFolderLocation __deprecated;
-(void)removePathFromSources:(NSString*) path;
-(NSArray*) localDatabases;
-(void)setStatus:(int) status forRemoteDatabase:(NSDictionary*) dict;
@end
