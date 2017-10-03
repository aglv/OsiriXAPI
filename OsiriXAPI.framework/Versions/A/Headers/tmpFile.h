//
//  tmpFile.h
//  OsiriX_Lion
//
//  Created by antoinerosset on 27.07.17.
//  Copyright © 2017 OsiriX Team. All rights reserved.
//

#ifndef tmpFile_h
#define tmpFile_h

#include <stdio.h>
#include <string.h>

#ifdef  __cplusplus
extern "C" {
#endif
    
    void resetTmpFile( const char* filename);
    unsigned int isTmpFileActivated( const char* filename);
    void activateTmpFile( const char* filename);
    
    extern unsigned int tmpFileLock;

#ifdef  __cplusplus
}
#endif
    
#endif /* tmpFile_h */
