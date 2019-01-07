/*
 *
 *  Copyright (C) 1997-2012, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmjpls
 *
 *  Author:  Uli Schlachter
 *
 *  Purpose: Helper function than converts between CharLS and dcmjpgls errors
 *
 */

#ifndef DJERROR_H
#define DJERROR_H

#include "osconfig.h"
#include "djlsutil.h" /* For the OFCondition codes */
#include "charls.h" /* CharLS include */

/** Helper class for converting between dcmjpls and CharLS error codes
 */
class DJLSError
{
private:
    /// private undefined constructor
    DJLSError();
    
public:
    
    /** This method converts a CharLS error code into a dcmjpls OFCondition
     *  @param error The CharLS error code
     *  @return The OFCondition
     */
    static const OFCondition& convert(charls::ApiResult error)
    {
        static OFCondition cond = EC_Normal;
        
        if( error == charls::ApiResult::OK)
            cond = EC_Normal;
        else if( error == charls::ApiResult::UncompressedBufferTooSmall)
            cond = EC_JLSUncompressedBufferTooSmall;
        else if( error == charls::ApiResult::CompressedBufferTooSmall)
            cond = EC_JLSCompressedBufferTooSmall;
        else if( error == charls::ApiResult::ImageTypeNotSupported)
            cond = EC_JLSCodecUnsupportedImageType;
        else if( error == charls::ApiResult::InvalidJlsParameters)
            cond = EC_JLSCodecInvalidParameters;
        else if( error == charls::ApiResult::ParameterValueNotSupported)
            cond = EC_JLSCodecUnsupportedValue;
        else if( error == charls::ApiResult::InvalidCompressedData)
            cond = EC_JLSInvalidCompressedData;
        else if( error == charls::ApiResult::UnsupportedBitDepthForTransform)
            cond = EC_JLSUnsupportedBitDepthForTransform;
        else if( error == charls::ApiResult::UnsupportedColorTransform)
            cond = EC_JLSUnsupportedColorTransform;
        else if( error == charls::ApiResult::TooMuchCompressedData)
            cond = EC_JLSTooMuchCompressedData;
        else
            cond = EC_IllegalParameter;
        
        return cond;
    }
};

#endif
