//
//  AppController+TouchBar.h
//  OsiriX
//
//  Created by Joris Heuberger on 08.11.16.
//  Copyright © 2016 Pixmeo. All rights reserved.
//

#import "AppController.h"

@interface AppController (TouchBar) <NSTouchBarDelegate>

+ (NSTouchBar*)defaultTouchBar;
+ (BOOL) isTouchBarAvailable;
+ (NSTouchBarItem*)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier title:(NSString*)title customizationLabel:(NSString*)customizationLabel image:(NSImage*)image target:(id)target action:(SEL)action;
+ (NSTouchBarItem*)buttonTouchBarItemWithIdentifier:(NSTouchBarItemIdentifier)identifier type:(NSButtonType)type title:(NSString*)title customizationLabel:(NSString*)customizationLabel image:(NSImage*)image target:(id)target action:(SEL)action;

@end
