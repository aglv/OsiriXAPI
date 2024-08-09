/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2024 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>


@interface DCMCharacterSet : NSObject {
	NSStringEncoding encoding;
	NSStringEncoding *encodings;
	NSString *_characterSet;
}

@property(readonly) NSStringEncoding* encodings;
@property(readonly) NSStringEncoding encoding;
@property(readonly) NSString *characterSet, *description;

- (id)initWithCode:(NSString *)characterSet;
- (id)initWithCharacterSet:(DCMCharacterSet *)characterSet;

+ (NSString *) stringWithBytes:(char *) str length:(unsigned) length encodings: (NSStringEncoding*) encodings;
+ (NSStringEncoding)encodingForDICOMCharacterSet:(NSString *)characterSet;

@end
