/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>

@interface NSDictionary (N2)

-(id)objectForKey:(id)k ofClass:(Class)cl;
-(id)keyForObject:(id)obj;
-(id)deepMutableCopy;
-(NSDictionary*)dictionaryWithLowercaseKeys;
-(id)objectForCaseInsensitiveKey:(NSString *)key;
-(NSDictionary*)dictionaryByAddingObject:(id) obj forKey:(id) key;
-(NSDictionary *)dictionaryByRemovingKey:(id) key;
+(NSDictionary*)dictionaryWithContentsOfData:(NSData *)data;

+ (NSDictionary*) dictionaryWithContentsOfFile:(NSString*) file cipher: (NSString*) cipher;
- (BOOL) writeToFile: (NSString*) file atomically:(BOOL)useAuxiliaryFile cipher: (NSString*) cipher;

- (NSString*) dictionaryAsString;
+ (NSDictionary*) dictionaryFromString: (NSString*) s;
@end
