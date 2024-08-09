//
//  DatabaseOverWindow.h
//  OsiriX
//
//  Created by Antoine Rosset on 29.03.23.
//  Copyright © 2023 OsiriX Team. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface DatabaseOverWindow : NSWindowController
{
    IBOutlet NSImageView *imageView;
}
@property (readonly) NSImageView *imageView;
@property (retain) NSString *modality, *name, *studyDescription, *numberOfImages, *studyDate;
@end
