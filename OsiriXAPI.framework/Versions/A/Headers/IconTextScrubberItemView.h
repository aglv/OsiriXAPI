//
//  IconTextScrubberItemView.h
//  OsiriX
//
//  Created by Joris Heuberger on 08.11.16.
//  Copyright © 2016 Pixmeo. All rights reserved.
//

@interface IconTextScrubberItemView : NSScrubberItemView

@property (retain) NSImageView *imageView;
@property (retain) NSTextField *textField;

+ (int)horizontalMargin;

@end
