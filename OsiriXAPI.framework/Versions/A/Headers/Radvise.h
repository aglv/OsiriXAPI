//
//  Radvise.h
//  OsiriX_Lion
//
//  Created by antoinerosset on 22.11.17.
//  Copyright © 2017 OsiriX Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Radvise : NSObject <NSURLSessionDelegate>
{
    NSMutableDictionary *tokenDict;
}

+ (id) loginWithEmail: (NSString*) email host:(NSString*) host;

@end
