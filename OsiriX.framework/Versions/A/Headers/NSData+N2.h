/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/

#import <Cocoa/Cocoa.h>


@interface NSData (N2)

+(NSData*)dataWithHex:(NSString*)hex;
-(NSData*)initWithHex:(NSString*)hex;
+(NSData*)dataWithBase64:(NSString*)base64;
-(NSData*)initWithBase64:(NSString*)base64;
-(NSString*)base64;
-(NSString*)hex;
-(NSData*)md5;
+(NSData*)dataWithShort:(unsigned short)s __deprecated_msg("only in OsiriX");
+(NSData*)dataWithLong:(unsigned long)s __deprecated_msg("only in OsiriX");
-(NSString*)dataAsStringWithEncoding: (NSStringEncoding) encoding __deprecated_msg("only in OsiriX");
- (NSArray *)multipartArrayWithBoundary:(NSString *)boundary __deprecated_msg("only in OsiriX");
- (NSArray *)multipartArray __deprecated_msg("only in OsiriX");
@end
