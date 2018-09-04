/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


#import <Cocoa/Cocoa.h>


enum Compression {
	CompressionDont = 0,
	CompressionCompress = 1,
	CompressionDecompress = 2
};

@interface DicomCompressor : NSObject

+(void)decompressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath;
+(void)decompressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath withOptions:(NSDictionary*)options;
+(void)decompressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath withOptionsPath:(NSString*)optionsPlistPath;

+(void)compressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath;
+(void)compressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath withOptions:(NSDictionary*)options;
+(void)compressFiles:(NSArray*)filePaths toDirectory:(NSString*)dirPath withOptionsPath:(NSString*)optionsPlistPath;

@end
