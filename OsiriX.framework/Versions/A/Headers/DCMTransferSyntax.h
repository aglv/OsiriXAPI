/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2024 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>

static NSString *DCM_ExplicitVRBigEndian = @"1.2.840.10008.1.2.2";
static NSString *DCM_ExplicitVRLittleEndian = @"1.2.840.10008.1.2.1";
static NSString *DCM_ImplicitVRLittleEndian = @"1.2.840.10008.1.2";
static NSString *DCM_JPEG1012Retired = @"1.2.840.10008.1.2.4.55";
static NSString *DCM_JPEG1113Retired = @"1.2.840.10008.1.2.4.56";
static NSString *DCM_JPEG1618Retired = @"1.2.840.10008.1.2.4.59";
static NSString *DCM_JPEG1719Retired = @"1.2.840.10008.1.2.4.60";
static NSString *DCM_JPEG2000Lossless = @"1.2.840.10008.1.2.4.90";
static NSString *DCM_JPEG2000Lossy = @"1.2.840.10008.1.2.4.91";
static NSString *DCM_JPEG2022Retired = @"1.2.840.10008.1.2.4.61";
static NSString *DCM_JPEG2123Retired = @"1.2.840.10008.1.2.4.62";
static NSString *DCM_JPEG2426Retired = @"1.2.840.10008.1.2.4.63";
static NSString *DCM_JPEG2527Retired = @"1.2.840.10008.1.2.4.64";
static NSString *DCM_JPEG29Retired = @"1.2.840.10008.1.2.4.66";
static NSString *DCM_JPEG68Retired = @"1.2.840.10008.1.2.4.53";
static NSString *DCM_JPEG79Retired = @"1.2.840.10008.1.2.4.54";
static NSString *DCM_JPEGBaseline = @"1.2.840.10008.1.2.4.50";
static NSString *DCM_JPEGExtended = @"1.2.840.10008.1.2.4.51";
static NSString *DCM_JPEGExtended35Retired = @"1.2.840.10008.1.2.4.52";
static NSString *DCM_JPEGLoRetired = @"1.2.840.10008.1.2.4.65";
static NSString *DCM_JPEGLossless = @"1.2.840.10008.1.2.4.70";
static NSString *DCM_JPEGLossless14 = @"1.2.840.10008.1.2.4.57";
static NSString *DCM_JPEGLossless15Retired = @"1.2.840.10008.1.2.4.58";
static NSString *DCM_JPEGLSLossless = @"1.2.840.10008.1.2.4.80";
static NSString *DCM_JPEGLSLossy = @"1.2.840.10008.1.2.4.81";
static NSString *DCM_RLELossless = @"1.2.840.10008.1.2.5";

static NSString *DCM_MPEG2MainProfileAtMainLevel = @"1.2.840.10008.1.2.4.100";
static NSString *DCM_MPEG2MainProfileAtHighLevel = @"1.2.840.10008.1.2.4.101";
static NSString *DCM_MPEG4HighProfileLevel = @"1.2.840.10008.1.2.4.102";
static NSString *DCM_MPEG4BDCompatibleHighProfile = @"1.2.840.10008.1.2.4.103";
static NSString *DCM_MPEG4HighProfileLevelFor2D = @"1.2.840.10008.1.2.4.104";
static NSString *DCM_MPEG4HighProfileLevelFor3D = @"1.2.840.10008.1.2.4.105";
static NSString *DCM_MPEG4StereoHighProfile = @"1.2.840.10008.1.2.4.106";

static NSString *DCM_JPEG2000Part2MulticomponentLosslessOnly = @"1.2.840.10008.1.2.4.92";
static NSString *DCM_JPEG2000Part2Multicomponent = @"1.2.840.10008.1.2.4.93";
static NSString *DCM_CTPrivateELE = @"1.3.46.670589.33.1.4.1";

@interface DCMTransferSyntax : NSObject {

NSString	*transferSyntax;
BOOL		isEncapsulated;
BOOL		isLittleEndian;
BOOL		isExplicit;
NSString	*name;
NSMutableDictionary *transferSyntaxDict;

}
@property(readonly) NSString *transferSyntax;
@property(readonly) NSString *name;
@property(readonly )BOOL isEncapsulated;
@property(readonly) BOOL isLittleEndian;
@property(readonly) BOOL isExplicit;

+(id)ExplicitVRLittleEndianTransferSyntax;
+(id)ImplicitVRLittleEndianTransferSyntax;
+(id)ExplicitVRBigEndianTransferSyntax;

+(id)JPEG2000LosslessTransferSyntax;
+(id)JPEG2000LossyTransferSyntax;
+(id)JPEGBaselineTransferSyntax;
+(id)JPEGExtendedTransferSyntax;
+(id)JPEGLosslessTransferSyntax;
+(id)JPEGLossless14TransferSyntax;
+(id)JPEGLSLosslessTransferSyntax;
+(id)JPEGLSLossyTransferSyntax;
+(id)RLETransferSyntax;
+(id)MPEG2TransferSyntax;
+(id)MPEG4TransferSyntax;
+(id)MPEG4BDTransferSyntax;
+(BOOL)isMPEG2TransferSyntax: (NSString*) s;
+(BOOL)isMPEG4TransferSyntax: (NSString*) s;
+(BOOL)isCompressed: (NSString*) s;

- (id)initWithTS:(NSString *)ts;
- (id)initWithTS:(NSString *)ts isEncapsulated:(BOOL)encapsulated  isLittleEndian:(BOOL)endian  isExplicit:(BOOL)explicitValue name:(NSString *)aName;
- (id)initWithTransferSyntax:(DCMTransferSyntax *)ts;


- (BOOL)isEqualToTransferSyntax:(DCMTransferSyntax *)ts;

@end
