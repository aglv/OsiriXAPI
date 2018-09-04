//
//  HorizontalPanTouchBarItemView.h
//  OsiriX
//
//  Created by Joris Heuberger on 18.11.16.
//  Copyright © 2016 Pixmeo. All rights reserved.
//

@interface HorizontalPanTouchBarItemView : NSView

@property (nonatomic, retain) IBOutlet NSView *view;
@property (nonatomic, retain) IBOutlet NSTextField *textField;
@property (nonatomic, retain) IBOutlet NSImageView *chevronLeft1, *chevronLeft2, *chevronLeft3;
@property (nonatomic, retain) IBOutlet NSImageView *chevronRight1, *chevronRight2, *chevronRight3;

- (void)setTintColor:(NSColor*)tintColor;
- (void)setTitle:(NSString*)title;

@end
