/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import "DicomDatabase.h"


@interface DicomDatabase (DCMTK)

+(BOOL)fileNeedsDecompression:(NSString*)path;
+(BOOL)compressDicomFilesAtPaths:(NSArray*)paths;
+(BOOL)compressDicomFilesAtPaths:(NSArray*)paths intoDirAtPath:(NSString*)destDir;
+(BOOL)compressDicomFilesAtPaths:(NSArray*)paths intoDirAtPath:(NSString*)dest compression: (int) compression quality: (int) quality;
+(BOOL)decompressDicomFilesAtPaths:(NSArray*)paths;
+(BOOL)decompressDicomFilesAtPaths:(NSArray*)paths intoDirAtPath:(NSString*)destDir;
+(NSString*)extractReportSR:(NSString*)dicomSR contentDate:(NSDate*)date;
+(BOOL)testFiles:(NSArray*)files;

@end
