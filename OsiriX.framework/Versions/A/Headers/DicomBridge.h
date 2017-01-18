/*=========================================================================
 Program:   OsiriX
 
 Copyright (c) Pixmeo SARL
 All rights reserved.
  =========================================================================*/

#import <Foundation/Foundation.h>

#ifdef __cplusplus
class DcmDataset;
class DcmMetaInfo;
#else
typedef char* DcmDataset;
typedef char* DcmMetaInfo;
#endif

@interface DicomBridge : NSObject
{
    NSDictionary *dictionary;
    NSArray *encodingArray;
    
    BOOL exportKeyword; // XML or JSON
    BOOL exportPixelData; // XML or JSON
}

@property (retain) NSDictionary *dictionary;
@property (retain) NSArray *encodingArray;
@property BOOL exportKeyword, exportPixelData;

// utilties
+ (int) dcmtkTransferSyntaxForString: (NSString*) ts;
+ (NSString*) stringForDcmtkTransferSyntax: (int) xfer;

+ (NSString*) xmlFromDataset: (DcmDataset*) dataset;
+ (NSString*) jsonFromDataset: (DcmDataset*) dataset;

// instances array
+ (NSArray*) bridgesArrayWithXML: (NSString*) xmlStream;
+ (NSArray*) bridgesArrayWithJSON: (NSString*) jsonStream;

// instances
+ (DicomBridge*) bridgeWithJSON: (NSString*) data;
+ (DicomBridge*) bridgeWithJSONData: (NSData*) data;
+ (DicomBridge*) bridgeWithXML: (NSString*) data;
+ (DicomBridge*) bridgeWithXMLData: (NSData*) data;

+ (DicomBridge*) bridgeWithDictionary: (NSDictionary*) dict;
+ (DicomBridge*) bridgeWithDICOMFile: (NSString*) filePath;
+ (DicomBridge*) bridgeWithDcmDataset: (DcmDataset*) dataset;

// output
- (NSString*) xml;
- (NSString*) json;
- (NSDictionary*) resolvedDictionary;

- (BOOL) saveAsDICOMToFile: (NSString*) file;

- (DcmMetaInfo*) dcmMetaInfo;
- (DcmMetaInfo*) dcmMetaInfo: (DcmMetaInfo *) dataset;
- (DcmDataset*) dcmDataset;
- (DcmDataset*) dcmDataset: (DcmDataset *) dataset;
@end
