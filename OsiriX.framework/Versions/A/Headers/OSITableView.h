//
//  OSITableView.h
//  OsiriX_Lion
//
//  Created by antoinerosset on 16.10.16.
//  Copyright © 2016 OsiriX Team. All rights reserved.
//

#import <Cocoa/Cocoa.h>

__deprecated_msg("only in OsiriX")
@interface OSITableView : NSTableView
{
    BOOL protectRecursiveReloadData;
}
@end
