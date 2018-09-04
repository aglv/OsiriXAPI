//
//  HorizontalPanTouchBarItem.h
//  OsiriX
//
//  Created by Joris Heuberger on 22.11.16.
//  Copyright © 2016 Pixmeo. All rights reserved.
//

#import "HorizontalPanTouchBarItemView.h"

@protocol HorizontalPanTouchBarItemDelegate <NSObject>
@optional
- (void)horizontalPanTouchBarItemDidPanOfPercentage:(CGFloat)percentage;
@end

@interface HorizontalPanTouchBarItem : NSCustomTouchBarItem
@property (nonatomic, assign) id <HorizontalPanTouchBarItemDelegate> delegate;
@property CGFloat previousPanTranslation;
- (void)setTintColor:(NSColor*)tintColor;
- (void)setTitle:(NSString*)title;
@end
