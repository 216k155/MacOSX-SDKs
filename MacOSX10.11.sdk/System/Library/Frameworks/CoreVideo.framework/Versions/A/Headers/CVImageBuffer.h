/*
 *  CVImageBuffer.h
 *  CoreVideo
 *
 *  Copyright (c) 2004-2015 Apple Inc. All rights reserved.
 *
 */
 
 /*! @header CVImageBuffer.h
	@copyright 2004-2015 Apple Inc. All rights reserved.
	@availability Mac OS X 10.4 or later, and iOS 4.0 or later
    @discussion CVImageBufferRef types are abstract and define various attachments and convenience
		calls for retreiving image related bits of data.
		   
*/

#if !defined(__COREVIDEO_CVIMAGEBUFFER_H__)
#define __COREVIDEO_CVIMAGEBUFFER_H__ 1

#include <TargetConditionals.h>
#include <Availability.h>
#include <AvailabilityMacros.h>

#if TARGET_OS_IPHONE || TARGET_OS_WIN32
#include <CoreGraphics/CoreGraphics.h>
#else
#include <ApplicationServices/ApplicationServices.h>
#endif
#include <CoreVideo/CVBuffer.h>

#if defined(__cplusplus)
extern "C" {
#endif

#pragma mark CVImageBufferRef attachment keys

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferCGColorSpaceKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CGColorSpaceRef

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferCleanApertureKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFDictionary containing the following four keys
CV_EXPORT const CFStringRef CV_NONNULL	kCVImageBufferCleanApertureWidthKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);			// CFNumber
CV_EXPORT const CFStringRef CV_NONNULL	kCVImageBufferCleanApertureHeightKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);			// CFNumber
CV_EXPORT const CFStringRef CV_NONNULL	kCVImageBufferCleanApertureHorizontalOffsetKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFNumber, horizontal offset from center of image buffer
CV_EXPORT const CFStringRef CV_NONNULL	kCVImageBufferCleanApertureVerticalOffsetKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFNumber, vertical offset from center of image buffer
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferPreferredCleanApertureKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);			// CFDictionary containing same keys as kCVImageBufferCleanApertureKey

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldCountKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFNumber
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldDetailKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFString with one of the following four values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldDetailTemporalTopFirst __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldDetailTemporalBottomFirst __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldDetailSpatialFirstLineEarly __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferFieldDetailSpatialFirstLineLate __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFString

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferPixelAspectRatioKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFDictionary with the following two keys
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferPixelAspectRatioHorizontalSpacingKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);	// CFNumber
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferPixelAspectRatioVerticalSpacingKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);	// CFNumber

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferDisplayDimensionsKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFDictionary with the following two keys
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferDisplayWidthKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFNumber
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferDisplayHeightKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFNumber

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferGammaLevelKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFNumber describing the gamma level, used in absence of (or ignorance of) kCVImageBufferTransferFunctionKey

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferICCProfileKey __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);				// CFData representation of the ICC profile

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferYCbCrMatrixKey __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);				// CFString describing the color matrix for YCbCr->RGB. This key can be one of the following values:
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferYCbCrMatrix_ITU_R_709_2 __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);			// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferYCbCrMatrix_ITU_R_601_4 __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);			// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferYCbCrMatrix_SMPTE_240M_1995 __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);		// CFString
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferYCbCrMatrix_ITU_R_2020 __OSX_AVAILABLE_STARTING(__MAC_10_11,__IPHONE_9_0);		// CFString

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimariesKey __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);				// CFString describing the color primaries. This key can be one of the following values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_ITU_R_709_2 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_EBU_3213 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_SMPTE_C __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_P22 __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_6_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_DCI_P3 __OSX_AVAILABLE_STARTING(__MAC_10_11,__IPHONE_9_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_P3_D65 __OSX_AVAILABLE_STARTING(__MAC_10_11,__IPHONE_9_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferColorPrimaries_ITU_R_2020 __OSX_AVAILABLE_STARTING(__MAC_10_11,__IPHONE_9_0);

CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunctionKey __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);				// CFString describing the transfer function. This key can be one of the following values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_ITU_R_709_2 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_SMPTE_240M_1995 __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_UseGamma __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_EBU_3213 __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_6,__IPHONE_NA,__IPHONE_NA);			// Should not be used.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_SMPTE_C __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_6,__IPHONE_NA,__IPHONE_NA);			// Should not be used.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferTransferFunction_ITU_R_2020 __OSX_AVAILABLE_STARTING(__MAC_10_11,__IPHONE_9_0);

/* Chroma siting information. For progressive images, only the TopField value is used. */
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocationTopFieldKey __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			// CFString with one of the following CFString values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocationBottomFieldKey __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);		// CFString with one of the following CFString values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_Left __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Chroma sample is horizontally co-sited with the left column of luma samples, but centered vertically.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_Center __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Chroma sample is fully centered
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_TopLeft __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Chroma sample is co-sited with the top-left luma sample.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_Top __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Chroma sample is horizontally centered, but co-sited with the top row of luma samples.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_BottomLeft __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);		    // Chroma sample is co-sited with the bottom-left luma sample.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_Bottom __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Chroma sample is horizontally centered, but co-sited with the bottom row of luma samples.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaLocation_DV420 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);			    // Cr and Cb samples are alternately co-sited with the left luma samples of the same field.

// These describe the format of the original subsampled data before conversion to 422/2vuy.   In order to use
// these tags, the data must have been converted to 4:2:2 via simple pixel replication.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaSubsamplingKey __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);		// CFString/CFNumber with one of the following values
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaSubsampling_420 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaSubsampling_422 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferChromaSubsampling_411 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);

// Can be set to kCFBooleanTrue as a hint that the alpha channel is fully opaque.  Not used if the pixel format type has no alpha channel.
CV_EXPORT const CFStringRef CV_NONNULL kCVImageBufferAlphaChannelIsOpaque __OSX_AVAILABLE_STARTING(__MAC_10_10,__IPHONE_8_0);
	
#pragma mark CVImageBufferRef

/*!
    @typedef	CVImageBufferRef
    @abstract   Base type for all CoreVideo image buffers

*/
typedef CVBufferRef CVImageBufferRef;

/*!
    @function   CVImageBufferGetEncodedSize
    @abstract   Returns the full encoded dimensions of a CVImageBuffer.  For example, for an NTSC DV frame this would be 720x480
    @param      imageBuffer A CVImageBuffer that you wish to retrieve the encoded size from.
    @result     A CGSize returning the full encoded size of the buffer
		Returns zero size if called with a non-CVImageBufferRef type or NULL.
*/
CV_EXPORT CGSize CVImageBufferGetEncodedSize( CVImageBufferRef CV_NONNULL imageBuffer ) __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);

/*!
    @function   CVImageBufferGetDisplaySize
    @abstract   Returns the nominal output display size (in square pixels) of a CVImageBuffer.  
                For example, for an NTSC DV frame this would be 640x480
    @param      imageBuffer A CVImageBuffer that you wish to retrieve the display size from.
    @result     A CGSize returning the nominal display size of the buffer
		Returns zero size if called with a non-CVImageBufferRef type or NULL.
*/
CV_EXPORT CGSize CVImageBufferGetDisplaySize( CVImageBufferRef CV_NONNULL imageBuffer ) __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);

/*!
    @function   CVImageBufferGetCleanRect
    @abstract   Returns the source rectangle of a CVImageBuffer that represents the clean aperture
		of the buffer in encoded pixels.    For example, an NTSC DV frame would return a CGRect with an
		origin of 8,0 and a size of 704,480.		
		Note that the origin of this rect always the lower left	corner.   This is the same coordinate system as
		used by CoreImage.
    @param      imageBuffer A CVImageBuffer that you wish to retrieve the display size from.
    @result     A CGSize returning the nominal display size of the buffer
		Returns zero rect if called with a non-CVImageBufferRef type or NULL.
*/
CV_EXPORT CGRect CVImageBufferGetCleanRect( CVImageBufferRef CV_NONNULL imageBuffer ) __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);

/*!
    @function   CVImageBufferIsFlipped
    @abstract   Returns whether the image is flipped vertically or not.
    @param      CVImageBuffer target
    @result     True if 0,0 in the texture is upper left, false if 0,0 is lower left.
*/
CV_EXPORT Boolean CVImageBufferIsFlipped( CVImageBufferRef CV_NONNULL imageBuffer ) __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);


#if COREVIDEO_SUPPORTS_COLORSPACE
/*!
    @function   CVImageBufferGetColorSpace
    @abstract   Returns the color space of a CVImageBuffer.
    @param      imageBuffer A CVImageBuffer that you wish to retrieve the color space from.
    @result     A CGColorSpaceRef representing the color space of the buffer.
		Returns NULL if called with a non-CVImageBufferRef type or NULL.
*/
CV_EXPORT CGColorSpaceRef CV_NULLABLE CVImageBufferGetColorSpace( CVImageBufferRef CV_NONNULL imageBuffer ) __OSX_AVAILABLE_STARTING(__MAC_10_4,__IPHONE_4_0);

/*!
   @function   CVImageBufferCreateColorSpaceFromAttachments
   @abstract   Attempts to synthesize a CGColorSpace from an image buffer's attachments.
   @param      attachments A CFDictionary of attachments for an image buffer, obtained using CVBufferGetAttachments().
   @result     A CGColorSpaceRef representing the color space of the buffer.
		Returns NULL if the attachments dictionary does not contain the information required to synthesize a CGColorSpace.
   @discussion
	To generate a CGColorSpace, the attachments dictionary should include values for either:
		1. kCVImageBufferICCProfile
		2. kCVImageBufferColorPrimariesKey, kCVImageBufferTransferFunctionKey, and kCVImageBufferYCbCrMatrixKey (and possibly kCVImageBufferGammaLevelKey)
	The client is responsible for releasing the CGColorSpaceRef when it is done with it (CGColorSpaceRelease() or CFRelease())
		
*/
CV_EXPORT CGColorSpaceRef CV_NULLABLE CVImageBufferCreateColorSpaceFromAttachments( CFDictionaryRef CV_NONNULL attachments ) __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_NA);

#endif

#if defined(__cplusplus)
}
#endif

#endif
