/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import "DicomDatabase.h"


@interface DicomDatabase (Scan)

-(BOOL)scanAtPath:(NSString*)path;
+(NSString*)_findDicomdirIn:(NSArray*)allpaths;
-(NSArray*)scanDicomdirAt:(NSString*)path withPaths:(NSArray*)allpaths pathsToScanAnyway:(NSMutableArray*)pathsToScanAnyway;
@end
