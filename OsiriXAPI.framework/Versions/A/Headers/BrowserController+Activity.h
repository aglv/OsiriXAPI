/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import "browserController.h"
#import "NoVibrancyTableView.h"

@interface BrowserController (Activity)

-(void)awakeActivity;
-(void)deallocActivity;

@end


@interface ThreadsTableView : NoVibrancyTableView
@end
