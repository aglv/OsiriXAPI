/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2020 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/


/*************
The networking code of the DCMFramework is predominantly a port of the 11/4/04 version of the java pixelmed toolkit by David Clunie.
htt://www.pixelmed.com   
**************/

#import <Cocoa/Cocoa.h>


@interface DCMAbstractSyntaxUID : NSObject {
	NSString *_uid;
	NSString *_name;
	NSString *_type;
}
+ (NSArray*) allSupportedSyntaxes;

+ (NSString *)verificationClassUID;
+ (BOOL)isVerification:(NSString *)sopClassUID ;
+ (BOOL)isMultiframe:(NSString*)sopClassUID;

+ (NSString *)computedRadiographyImageStorage;
+ (NSString *)digitalXRayImageStorageForPresentation;
+ (NSString *)digitalXRayImageStorageForProcessing;
+ (NSString *)digitalMammographyXRayImageStorageForPresentation;
+ (NSString *)digitalMammographyXRayImageStorageForProcessing;
+ (NSString *)digitalIntraoralXRayImageStorageForPresentation;
+ (NSString *)digitalIntraoralXRayImageStorageForProcessing;
+ (NSString *)CTImageStorage;
+ (NSString *)enhancedCTImageStorage;
+ (NSString *)legacyConvertedEnhancedCTImageStorage;
+ (NSString *)enhancedPETImageStorage;
+ (NSString *)legacyConvertedEnhancedPETImageStorage;
+ (NSString *)ultrasoundMultiframeImageStorageRetired;
+ (NSString *)ultrasoundMultiframeImageStorage;
+ (NSString *)MRImageStorage;
+ (NSString *)enhancedMRImageStorage;
+ (NSString *)enhancedMRColorImageStorage;
+ (NSString *)legacyConvertedEnhancedMRImageStorage;
+ (NSString *)nuclearMedicineImageStorageRetired;
+ (NSString *)ultrasoundImageStorageRetired;
+ (NSString *)ultrasoundImageStorage;
+ (NSString *)parametricMapStorage;
+ (NSString *)enhancedUSVolumeStorage;
+ (NSString *)secondaryCaptureImageStorage;
+ (NSString *)multiframeSingleBitSecondaryCaptureImageStorage;
+ (NSString *)multiframeGrayscaleByteSecondaryCaptureImageStorage;
+ (NSString *)multiframeGrayscaleWordSecondaryCaptureImageStorage;
+ (NSString *)multiframeTrueColorSecondaryCaptureImageStorage;
+ (NSString *)xrayAngiographicImageStorage;
+ (NSString *)xrayRadioFlouroscopicImageStorage;
+ (NSString *)xrayAngiographicBiplaneImageStorage;
+ (NSString *)nuclearMedicineImageStorage;
+ (NSString *)visibleLightDraftImageStorage;
+ (NSString *)visibleLightMultiFrameDraftImageStorage;
+ (NSString *)visibleLightEndoscopicImageStorage;
+ (NSString *)videoEndoscopicImageStorage;
+ (NSString *)visibleLightMicroscopicImageStorage;
+ (NSString *)videoMicroscopicImageStorage;
+ (NSString *)visibleLightSlideCoordinatesMicroscopicImageStorage;
+ (NSString *)visibleLightPhotographicImageStorage;
+ (NSString *)videoPhotographicImageStorage;
+ (NSString *)EnhancedXAImageStorage;
+ (NSString *)XrayAngiographicImageStorage;
+ (NSString *)XrayRadioFlouroscopicImageStorage;
+ (NSString *)EnhancedXRFImageStorage;
+ (NSString *)XrayAngiographicBiplaneImageStorage;
+ (NSString *)XRay3DAngiographicImageStorage;
+ (NSString *)XRay3DCraniofacialImageStorage;
+ (NSString *)PETImageStorage;
+ (NSString *)RTImageStorage;
+ (NSString *)SRStoragePrefix;
+ (BOOL)isImageStorage:(NSString *)sopClassUID;
+ (NSArray *)imageSyntaxes;
+ (NSArray *)hiddenImageSyntaxes;
+ (BOOL) isHiddenImageStorage:(NSString *)sopClassUID;
+ (BOOL) isSupportedPrivateClasses:(NSString *)sopClassUID;
+ (NSArray*) supportedPrivateClasses;
+ (NSString *)mediaStorageDirectoryStorage;
+ (BOOL) isDirectory:(NSString *) sopClassUID;

+ (NSString *)basicTextSRStorage;
+ (NSString *)enhancedSRStorage;
+ (NSString *)comprehensiveSRStorage;
+ (NSString *)mammographyCADSRStorage;
+ (NSString *)keyObjectSelectionDocumentStorage;
+ (BOOL) isKeyObjectDocument:(NSString *)sopClassUID;
+ (BOOL) isStructuredReport:(NSString *)sopClassUID;
+ (NSArray*) structuredReportSyntaxes;

+ (NSString *)grayscaleSoftcopyPresentationStateStorage;
+(NSArray*) presentationStateSyntaxes;
+ (BOOL) isPresentationState:(NSString *)sopClassUID;

+ (NSString *)twelveLeadECGStorage;
+ (NSString *)generalECGStorage;
+ (NSString *)ambulatoryECGStorage;
+ (NSString *)hemodynamicWaveformStorage;
+ (NSString *)cardiacElectrophysiologyWaveformStorage;
+ (NSString *)basicVoiceStorage;
+ (NSArray*) waveformSyntaxes;
+ (BOOL) isWaveform:(NSString *)sopClassUID;

+ (NSString *)standaloneOverlayStorage;
+ (NSString *)standaloneCurveStorage;
+ (NSString *)standaloneModalityLUTStorage;
+ (NSString *)standaloneVOILUTStorage;
+ (NSString *)standalonePETCurveStorage;
+ (BOOL) isStandalone:(NSString *)sopClassUID;

+ (NSString *)RTDoseStorage;
+ (NSString *)RTStructureSetStorage;
+ (NSString *)RTBeamsTreatmentRecordStorage;
+ (NSString *)RTPlanStorage;
+ (NSString *)RTBrachyTreatmentRecordStorage;
+ (NSString *)RTTreatmentSummaryRecordStorage;
+ (BOOL)  isRadiotherapy:(NSString *)sopClassUID;
+(NSArray*) radiotherapySyntaxes;

+ (NSString *)MRSpectroscopyStorage;
+ (BOOL) isSpectroscopy:(NSString *)sopClassUID;
+ (BOOL) isSiemensCSAPrivateNonImageStorage:(NSString *)sopClassUID;
+ (NSString *)rawDataStorage;
+ (BOOL) isRawData:(NSString *)sopClassUID ;

+ (BOOL) isNonImageStorage:(NSString *)sopClassUID;

+ (BOOL) isQuery:(NSString *)sopClassUID;

+ (NSString *)studyRootQueryRetrieveInformationModelFind;
+ (NSString *)studyRootQueryRetrieveInformationModelMove;

+ (NSString *)pdfStorageClassUID;
+ (NSString *)EncapsulatedCDAStorage;
+ (NSString *)EncapsulatedSTLStorage;

- (id)initWithUID:(NSString *)uid  name:(NSString *)name  type:(NSString *)type;
- (NSString *)uid;
- (NSString *)name;
- (NSString *)type;
- (BOOL)isImageStorage;
- (BOOL) isDirectory;
- (BOOL) isStructuredReport;
- (BOOL) isPresentationState;
- (BOOL) isWaveform;
- (BOOL) isStandalone;
- (BOOL) isRadiotherapy;
- (BOOL) isSpectroscopy;
- (BOOL) isRawData;
- (BOOL) isNonImageStorage;
+ (BOOL)isPDF:(NSString *)sopClassUID;
+ (NSString *)basicGrayscalePrintManagementMetaSOPClassUID;
+ (NSString *)basicColorPrintManagementMetaSOPClassUID;
@end
