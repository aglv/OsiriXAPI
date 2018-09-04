/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>

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
+(BOOL)isMPEGTransferSyntax: (NSString*) s;
+(BOOL)isCompressed: (NSString*) s;

- (id)initWithTS:(NSString *)ts;
- (id)initWithTS:(NSString *)ts isEncapsulated:(BOOL)encapsulated  isLittleEndian:(BOOL)endian  isExplicit:(BOOL)explicitValue name:(NSString *)aName;
- (id)initWithTransferSyntax:(DCMTransferSyntax *)ts;


- (BOOL)isEqualToTransferSyntax:(DCMTransferSyntax *)ts;

@end
