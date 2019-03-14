/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2019 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/



#import <Cocoa/Cocoa.h>

#import "DICOMTLS.h"
#import "DDKeychain.h"

int runStoreSCU(const char *myAET, const char*peerAET, const char*hostname, int port, NSDictionary *extraParameters);

/** \brief  DICOM Send 
*
* DCMTKStoreSCU performs the DICOM send
* based on DCMTK 
*/
@interface DCMTKStoreSCU : NSObject {
	BOOL _threadStatus;
	
	NSString *_callingAET;
	NSString *_calledAET;
	int _port;
	NSString *_hostname;
	NSDictionary *_extraParameters;
	int _transferSyntax;
	float _compression;
    
    int _maxThreads;
	NSMutableArray *_filesToSend;
	int _numberOfFiles;
	int _numberSent;
	int _numberErrors;
	NSString *_patientName, *_patientID;
	NSString *_studyDescription; 
	id _logEntry;
	
	//TLS settings
	BOOL _secureConnection;
	BOOL _doAuthenticate;
	int  _keyFileFormat;
	NSArray *_cipherSuites;
    NSString *_readSeedFile;
    NSString *_writeSeedFile;
	TLSCertificateVerificationType certVerification;
    NSString *_dhparam;
}

@property int maxThreads;
@property (retain) NSString *readSeedFile, *writeSeedFile, *dhparam;

+ (int) sendSyntaxForListenerSyntax: (int) listenerSyntax;
+ (int) sendSyntaxForSyntaxUID: (NSString*) syntaxUID;

- (id) initWithCallingAET:(NSString *)myAET
                calledAET:(NSString *)theirAET
                 hostname:(NSString *)hostname
                     port:(int)port
              filesToSend:(NSArray *)filesToSend
           transferSyntax:(int)transferSyntax
              compression: (float)compression
          extraParameters:(NSDictionary *)extraParameters __deprecated;

- (id) initWithCallingAET:(NSString *)myAET  
			calledAET:(NSString *)theirAET  
			hostname:(NSString *)hostname 
			port:(int)port 
			filesToSend:(NSArray *)filesToSend
			transferSyntax:(int)transferSyntax
			extraParameters:(NSDictionary *)extraParameters;
			
- (void)run;
- (void)run: (id) sender;
- (void)updateLogEntry: (NSMutableDictionary*) userInfo;
@end



