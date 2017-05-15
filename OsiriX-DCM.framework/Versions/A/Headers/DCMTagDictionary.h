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
