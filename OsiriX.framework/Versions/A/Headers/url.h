//
//  url.h
//  OsiriX_Lion
//
//  Created by Alex Bettarini on 22 Nov 2014.
//  Copyright (c) 2014 Osiri-LXIV Team. All rights reserved.
//

#ifndef URL_H_INCLUDED
#define URL_H_INCLUDED

// search for URLWithString
#define URL_HOROS_VIEWER           @"http://horosproject.org"
#define URL_HOROS_WEB_PAGE         @"http://horosproject.org"
#define URL_VENDOR                  @"http://horosproject.org"
#define URL_EMAIL                   @"horos@horosproject.org"

#define URL_VENDOR_NOTICE           URL_VENDOR@"/products.html#OsiriXMD"
#define URL_VENDOR_USER_MANUAL      URL_VENDOR@"/products.html#OsiriXUserManual"

#define URL_HOROS_BANNER           URL_HOROS_VIEWER@"wp-content/uploads/2015/01/horus-blue-bg-JPG2048x2048px-150DPI-1-300x300.png"
#define URL_CLICK_BANNER            URL_HOROS_VIEWER@"/Banner.html"

#define URL_HOROS_DOC_SECURITY     URL_HOROS_VIEWER@"/Documentation/Guides/Security/index.html"
#define URL_HOROS_LEARNING         URL_HOROS_VIEWER@"/community/communicate/"
#define URL_HOROS_UPDATE           URL_HOROS_VIEWER@"/adaa7f5d1f33cb8ddd89fe300da7c2cd/"
#define URL_HOROS_UPDATE_CRASH     URL_HOROS_VIEWER@"/adaa7f5d1f33cb8ddd89fe300da7c2cd/"
#define URL_HOROS_VERSION          URL_HOROS_VIEWER@"/version.xml"
#define URL_HOROS_VERSION_OLD_OS   URL_HOROS_VIEWER@"/version.xml"
#define URL_HOROS_PLUGINS          URL_HOROS_VIEWER@"/Plugins.html"


////////////////////////////////////////////////////////////////////////////////
// We want our own Defaults plist saved in ~/Library/Preferences/
// Make sure it matches "Bundle Identifier" in Deployment-Info.plist

#define BUNDLE_IDENTIFIER_PREFIX    "com.horosproject"
#define BUNDLE_IDENTIFIER           "com.horosproject.horos"

////////////////////////////////////////////////////////////////////////////////
// This is the address of the plist containing the list of the available plugins.
// the alternative link will be used if the first one doesn't reply...

#define PLUGIN_LIST_URL                     @"http://www.osirix-viewer.com/osirix_plugins/plugins.plist"
#define PLUGIN_LIST_ALT_URL                 @"http://www.osirixviewer.com/osirix_plugins/plugins.plist"

#define PLUGIN_SUBMISSION_URL               @"http://www.osirix-viewer.com/osirix_plugins/submit_plugin/index.html"
#define PLUGIN_SUBMISSION_NO_MAIL_APP_URL   @"http://www.osirix-viewer.com/osirix_plugins/submit_plugin/index_no_mail_app.html"


#endif
