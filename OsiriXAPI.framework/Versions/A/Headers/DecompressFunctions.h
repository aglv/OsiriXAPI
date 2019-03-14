#import "DCM Framework/DCMFramework.h"
#import "AppController.h"

@interface DecompressFunctions : NSObject
{
}

+(void) compressPaths:(NSArray*) paths destination:(NSString*) destination settings: (id) dict;
+(void) compressPaths:(NSArray*) paths destination:(NSString*) destination;

+(void) compressPaths:(NSArray*) paths destination:(NSString*) destination compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality settings: (id) dict;
+(void) compressPaths:(NSArray*) paths destination:(NSString*) destination compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality;

+(void) compressPaths:(NSArray*) paths compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality settings: (id) dict;
+(void) compressPaths:(NSArray*) paths compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality;

+(void) compressConcurrentlyPaths:(NSArray*)allPaths compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality;
+(void) compressConcurrentlyPaths:(NSArray*)allPaths destination:(NSString*)dest compression: (compressionTechniqueType) compression quality: (DCM_CompressionQuality) quality;

+ (compressionTechniqueType) compressionForModality: (NSString*) mod quality:(DCM_CompressionQuality*) quality resolution: (int) resolution;
+ (compressionTechniqueType) compressionForModality: (NSString*) mod quality:(DCM_CompressionQuality*) quality resolution: (int) resolution settings: (id) dict;

@end
