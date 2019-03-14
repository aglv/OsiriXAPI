/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Foundation/Foundation.h>


@interface DCMTagDictionary : NSObject {
    NSDictionary *tagDictionary;
}

@property (readonly) NSDictionary *tagDictionary;

+(DCMTagDictionary*)sharedTagDictionary;
-(NSDictionary*) dictionaryForGroupElement: (NSString*) ge;
-(NSDictionary*) dictionaryForGroupElement: (NSString*) ge privateCreatorElement:(NSString*) privateCreatorElement;
-(NSDictionary*) dictionaryForGroup: (int) group element: (int) element privateCreatorElement:(NSString*) privateCreatorElement;

@end
