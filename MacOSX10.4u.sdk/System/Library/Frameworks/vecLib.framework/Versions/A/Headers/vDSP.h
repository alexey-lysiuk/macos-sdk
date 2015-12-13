/*
     File:       vecLib/vDSP.h
 
     Contains:   AltiVec DSP Interfaces
 
     Version:    vecLib-182.18~156
 
     Copyright:  © 2000-2005 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __VDSP__
#define __VDSP__

#include <CoreServices/../Frameworks/CarbonCore.framework/Headers/MacTypes.h>
#include "vDSP_translate.h"


#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

struct DSPComplex {
  float               real;
  float               imag;
};
typedef struct DSPComplex               DSPComplex;
struct DSPSplitComplex {
  float *             realp;
  float *             imagp;
};
typedef struct DSPSplitComplex          DSPSplitComplex;
struct DSPDoubleComplex {
  double              real;
  double              imag;
};
typedef struct DSPDoubleComplex         DSPDoubleComplex;
struct DSPDoubleSplitComplex {
  double *            realp;
  double *            imagp;
};
typedef struct DSPDoubleSplitComplex    DSPDoubleSplitComplex;
typedef struct OpaqueFFTSetup*          FFTSetup;
typedef struct OpaqueFFTSetupD*         FFTSetupD;
typedef SInt32 FFTDirection;
enum {
  kFFTDirection_Forward         = 1,
  kFFTDirection_Inverse         = -1
};

typedef SInt32 FFTRadix;
enum {
  kFFTRadix2                    = 0,
  kFFTRadix3                    = 1,
  kFFTRadix5                    = 2
};

/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    The criteria to invoke the PowerPC vector implementation is subject to     
    change and become less restrictive in the future.                          
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/





/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions create_fftsetup and destroy_fftsetup.
              create_fftsetupD and destroy_fftsetupD.
              
    create_fftsetup will allocate memory and setup a weight array used by      
    the FFT. The call destroy_fftsetup will free the array.                    
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_create_fftsetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern FFTSetup 
vDSP_create_fftsetup(
  UInt32     log2n,
  FFTRadix   radix)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_destroy_fftsetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_destroy_fftsetup(FFTSetup setup)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_create_fftsetupD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern FFTSetupD 
vDSP_create_fftsetupD(
  UInt32     log2n,
  FFTRadix   radix)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_destroy_fftsetupD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_destroy_fftsetupD(FFTSetupD setup)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions ctoz and ztoc.
              ctozD and ztocD.
    
    ctoz converts a complex array to a complex-split array
    ztoc converts a complex-split array to a complex array
    
    Criteria to invoke PowerPC vector code:    
        1. size > 3
        2. strideC = 2
        3. strideZ = 1
        4. C is 16-byte aligned and Z.realp and Z.imagp are 16-byte aligned.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_ctoz()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_ctoz(
  const DSPComplex   C[],
  SInt32             strideC,
  DSPSplitComplex *  Z,
  SInt32             strideZ,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_ztoc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_ztoc(
  const DSPSplitComplex *  Z,
  SInt32                   strideZ,
  DSPComplex               C[],
  SInt32                   strideC,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_ctozD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_ctozD(
  const DSPDoubleComplex   C[],
  SInt32                   strideC,
  DSPDoubleSplitComplex *  Z,
  SInt32                   strideZ,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_ztocD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_ztocD(
  const DSPDoubleSplitComplex *  Z,
  SInt32                         strideZ,
  DSPDoubleComplex               C[],
  SInt32                         strideC,
  UInt32                         size)                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft_zip and fft_zipt 
              fft_zipD and fft_ziptD
              
    In-place Split Complex Fourier Transform with or without temporary memory.
            
      Criteria to invoke PowerPC vector code:    
        
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. stride = 1
        3. 2 <= log2n <= 20
        4. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft_zip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zipt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zipt(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zipD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zipD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   stride,
  UInt32                   log2n,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft_ziptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_ziptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   stride,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2n,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
     Functions fft_zop and fft_zopt
               fft_zopD and fft_zoptD
     
     Out-of-place Split Complex Fourier Transform with or without temporary
     memory
            
      Criteria to invoke PowerPC vector code:  
        
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStride = 1
        3. result.realp and result.imagp must be 16-byte aligned.
        4. strideResult = 1
        5. 2 <= log2n <= 20
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zopt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zopt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zopD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zopD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   log2n,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft_zoptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zoptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2n,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft_zrip and fft_zript
              fft_zripD and fft_zriptD
              
    In-Place Real Fourier Transform with or without temporary memory,
    split Complex Format
            
      Criteria to invoke PowerPC vector code:    
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. stride = 1
        3. 3 <= log2n <= 13
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft_zrip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zrip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zript()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zript(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zripD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zripD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   stride,
  UInt32                   log2n,
  FFTDirection             flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft_zriptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zriptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   stride,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2n,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft_zrop and fft_zropt
              fft_zropD and fft_zroptD
              
    Out-of-Place Real Fourier Transform with or without temporary memory,
    split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStride = 1
        3. result.realp and result.imagp must be be 16-byte aligned.
        4. strideResult = 1
        5. 3 <= log2n <= 13
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft_zrop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zrop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zropt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft_zropt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft_zropD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zropD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   log2n,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft_zroptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft_zroptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2n,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft2d_zip and fft2d_zipt
              fft2d_zipD and fft2d_ziptD
              
    In-place two dimensional Split Complex Fourier Transform with or without
    temporary memory
            
      Criteria to invoke PowerPC vector code:  
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. strideInRow = 1;
        3. strideInCol must be a multiple of 4
        4. 2 <= log2nInRow <= 12
        5. 2 <= log2nInCol <= 12
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft2d_zip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zipt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zipt(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zipD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zipD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   strideInRow,
  SInt32                   strideInCol,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft2d_ziptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_ziptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   strideInRow,
  SInt32                   strideInCol,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  FFTDirection             direction)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft2d_zop and fft2d_zopt
              fft2d_zopD and fft2d_zoptD
              
    Out-of-Place two dimemsional Split Complex Fourier Transform with or
    without temporary memory
            
      Criteria to invoke PowerPC vector code:  
        
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStrideInRow = 1;
        3. signalStrideInCol must be a multiple of 4
        4. result.realp and result.imagp must be 16-byte aligned.
        5. strideResultInRow = 1;
        6. strideResultInCol must be a multiple of 4
        7. 2 <= log2nInRow <= 12
        8. 2 <= log2nInCol <= 12
        9. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft2d_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zopt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zopt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zopD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zopD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStrideInRow,
  SInt32                   signalStrideInCol,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResultInRow,
  SInt32                   strideResultInCol,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft2d_zoptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zoptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStrideInRow,
  SInt32                   signalStrideInCol,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResultInRow,
  SInt32                   strideResultInCol,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft2d_zrip and fft2d_zript
              fft2d_zripD and fft2d_zriptD
              
    In-place two dimensional Real Fourier Transform with or without temporary
    memory, Split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. strideInRow = 1;
        3. strideInCol must be a multiple of 4
        4. 3 <= log2nInRow <= 12
        5. 3 <= log2nInCol <= 13
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft2d_zrip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zrip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zript()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zript(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zripD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zripD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   strideInRow,
  SInt32                   strideInCol,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft2d_zriptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zriptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   strideInRow,
  SInt32                   strideInCol,
  DSPDoubleSplitComplex *  bufferTemp,
  UInt32                   log2nInCol,
  UInt32                   log2nInRow,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Functions fft2d_zrop and fft2d_zropt
              fft2d_zropD and fft2d_zroptD
              
    Out-of-Place Two-Dimemsional Real Fourier Transform with or without
    temporary memory, Split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStrideInRow = 1;
        3. signalStrideInCol must be a multiple of 4
        4. result.realp and result.imagp must be 16-byte aligned.
        5. strideResultInRow = 1;
        6. strideResultInCol must be a multiple of 4
        7. 3 <= log2nInRow <= 12
        8. 3 <= log2nInCol <= 13
        9. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_fft2d_zrop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zrop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zropt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_fft2d_zropt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_fft2d_zropD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zropD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   Kr,
  SInt32                   Kc,
  DSPDoubleSplitComplex *  ioData2,
  SInt32                   Ir,
  SInt32                   Ic,
  UInt32                   log2nc,
  UInt32                   log2nr,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft2d_zroptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft2d_zroptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   Kr,
  SInt32                   Kc,
  DSPDoubleSplitComplex *  ioData2,
  SInt32                   Ir,
  SInt32                   Ic,
  DSPDoubleSplitComplex *  temp,
  UInt32                   log2nc,
  UInt32                   log2nr,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
________________________________________________________________________________
      Functions fftm_zip and fftm_zipt
                fftm_zipD and fftm_ziptD
                
      In-Place multiple One_Dimensional Complex Fourier Transform with or 
      without temporary memory, Split Complex Format
      
         Criteria to invoke PowerPC vector code:
            1. signal.realp and signal.imagp must be 16-byte aligned.
            2. signalStride = 1;
            3. fftStride must be a multiple of 4
            4. 2 <= log2n <= 12
            5. temp.realp and temp.imagp must be 16-byte aligned.
         
         If any of the above criteria are not satisfied, the PowerPC scalar code
         implementation will be used.
________________________________________________________________________________
*/
/*
 *  vDSP_fftm_zip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zip(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zipt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zipt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  temp,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zipD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zipD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_ziptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_ziptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  temp,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
________________________________________________________________________________
      Functions fftm_zop and fftm_zopt
                fftm_zopD and fftm_zoptD
                
      Out-Of-Place multiple One_Dimensional Complex Fourier Transform with or 
      without temporary memory, Split Complex Format
      
         Criteria to invoke PowerPC vector code:
            1. signal.realp and signal.imagp must be 16-byte aligned.
            2. signalStride = 1;
            3. fftStride must be a multiple of 4
            4. result.realp and result.imagp must be 16-byte aligned.
            5. resultStride = 1;
            6. rfftStride must be a multiple of 4
            7. 2 <= log2n <= 12
            8. temp.realp and temp.imagp must be 16-byte aligned.
        
        If any of the above criteria are not satisfied, the PowerPC scalar code
        implementation will be used.
________________________________________________________________________________
*/
/*
 *  vDSP_fftm_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  SInt32             rfftStride,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zopt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zopt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  SInt32             rfftStride,
  DSPSplitComplex *  temp,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zopD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zopD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   resultStride,
  SInt32                   rfftStride,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zoptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zoptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   resultStride,
  SInt32                   rfftStride,
  DSPDoubleSplitComplex *  temp,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
________________________________________________________________________________
      Functions fftm_zrip and fftm_zript
                fftm_zripD and fftm_zriptD
                
      In-Place multiple One_Dimensional Real Fourier Transform with or 
      without temporary memory, Split Complex Format
      
         Criteria to invoke PowerPC vector code:
            1. signal.realp and signal.imagp must be 16-byte aligned.
            2. signalStride = 1;
            3. fftStride must be a multiple of 4
            4. 3 <= log2n <= 13
            5. temp.realp and temp.imagp must be 16-byte aligned.
        If any of the above criteria are not satisfied, the PowerPC scalar code
        implementation will be used.
________________________________________________________________________________
*/
/*
 *  vDSP_fftm_zrip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zrip(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zript()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zript(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  temp,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zripD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zripD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zriptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zriptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  temp,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
________________________________________________________________________________
      Functions fftm_zrop and fftm_zropt
                fftm_zropD and fftm_zroptD
                
      Out-Of-Place multiple One_Dimensional Real Fourier Transform with or 
      without temporary memory, Split Complex Format
      
         Criteria to invoke PowerPC vector code:
            1. signal.realp and signal.imagp must be 16-byte aligned.
            2. signalStride = 1;
            3. fftStride must be a multiple of 4
            4. result.realp and result.imagp must be 16-byte aligned.
            5. resultStride = 1;
            6. rfftStride must be a multiple of 4
            7. 3 <= log2n <= 13
            8. temp.realp and temp.imagp must be 16-byte aligned.
         
         If any of the above criteria are not satisfied, the PowerPC scalar code
         implementation will be used.
________________________________________________________________________________
*/
/*
 *  vDSP_fftm_zrop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zrop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  SInt32             rfftStride,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zropt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zropt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  SInt32             fftStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  SInt32             rfftStride,
  DSPSplitComplex *  temp,
  UInt32             log2n,
  UInt32             numFFT,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zropD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zropD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   resultStride,
  SInt32                   rfftStride,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fftm_zroptD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fftm_zroptD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  SInt32                   fftStride,
  DSPDoubleSplitComplex *  result,
  SInt32                   resultStride,
  SInt32                   rfftStride,
  DSPDoubleSplitComplex *  temp,
  UInt32                   log2n,
  UInt32                   numFFT,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
________________________________________________________________________________
      Functions fft3_zop and fft5_zop
                fft3_zopD and fft5_zopD
                
      Out-Of-Place One_Dimensional Complex Fourier Transform in base-3 and 
      base-5 with or without temporary memory, Split Complex Format 
      
         Criteria to invoke PowerPC vector code:
            1. signal.realp and signal.imagp must be 16-byte aligned.
            2. signalStride = 1;
            3. result.realp and result.imagp must be 16-byte aligned.
            4. resultStride = 1;
            5. 3 <= log2n 
         
         If any of the above criteria are not satisfied, the PowerPC scalar code
         implementation will be used.
________________________________________________________________________________
*/
/*
 *  vDSP_fft3_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft3_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  UInt32             log2n,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft5_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft5_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             resultStride,
  UInt32             log2n,
  SInt32             flag)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft3_zopD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft3_zopD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   K,
  DSPDoubleSplitComplex *  ioData2,
  SInt32                   L,
  UInt32                   log2n,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_fft5_zopD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_fft5_zopD(
  FFTSetupD                setup,
  DSPDoubleSplitComplex *  ioData,
  SInt32                   K,
  DSPDoubleSplitComplex *  ioData2,
  SInt32                   L,
  UInt32                   log2n,
  SInt32                   flag)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function conv
             convD
             
    Floating Point Convolution and Correlation in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. signal and result must have relative alignement.
        2. 4 <= lenFilter <= 256
        3. lenResult > 36
        4. signalStride = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  strideFilter can be positive for
      correlation or negative for convolution.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_conv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_conv(
  const float   signal[],
  SInt32        signalStride,
  const float   filter[],
  SInt32        strideFilter,
  float         result[],
  SInt32        strideResult,
  SInt32        lenResult,
  SInt32        lenFilter)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_convD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_convD(
  const double   signal[],
  SInt32         signalStride,
  const double   filter[],
  SInt32         strideFilter,
  double         result[],
  SInt32         strideResult,
  SInt32         lenResult,
  SInt32         lenFilter)                                   AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
_______________________________________________________________________________
     Functions f3x3, f5x5, and imgfir
               f3x3D, f5x5D and imgfirD
               
     Filter, 3x3, 5x5, MxN Single and Double Precision Convolution
     
       Criteria to invoke PowerPC vector code:
         1. signal, filter, and result must have relative alignment and
            be 16-byte aligned.
         2. for f3x3, NC >= 18
         3. for f5x5, NC >= 20
         4. for imgfir, NC >= 20
       
       If any of the above criteria are not satisfied, the PowerPC scalar code
       implementation will be used.
_______________________________________________________________________________
*/
/*
 *  vDSP_f3x3()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_f3x3(
  float *  signal,
  SInt32   rowStride,
  SInt32   colStride,
  float *  filter,
  float *  result)                                            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_f3x3D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_f3x3D(
  double *  signal,
  SInt32    rowStride,
  SInt32    colStride,
  double *  filter,
  double *  result)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_f5x5()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_f5x5(
  float *  signal,
  SInt32   rowStride,
  SInt32   colStride,
  float *  filter,
  float *  result)                                            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_f5x5D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_f5x5D(
  double *  signal,
  SInt32    rowStride,
  SInt32    colStride,
  double *  filter,
  double *  result)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_imgfir()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_imgfir(
  float *  signal,
  SInt32   numRow,
  SInt32   numCol,
  float *  filter,
  float *  result,
  SInt32   fnumRow,
  SInt32   fnumCol)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_imgfirD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_imgfirD(
  double *  signal,
  SInt32    numRow,
  SInt32    numCol,
  double *  filter,
  double *  result,
  SInt32    fnumRow,
  SInt32    fnumCol)                                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
_______________________________________________________________________________
     Function mtrans
              mtransD
              
     Single and Double Precision Matrix Transpose
     
       Criteria to invoke PowerPC vector code:
         1. a = c
         2. a and c must be 16-byte aligned.
         3. M must be a multiple of 8.
       
       If any of the above criteria are not satisfied, the PowerPC scalar code
       implementation will be used.
_______________________________________________________________________________
*/
/*
 *  vDSP_mtrans()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mtrans(
  float *  a,
  SInt32   aStride,
  float *  c,
  SInt32   cStride,
  SInt32   M,
  SInt32   N)                                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_mtransD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mtransD(
  double *  a,
  SInt32    aStride,
  double *  c,
  SInt32    cStride,
  SInt32    M,
  SInt32    N)                                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
_______________________________________________________________________________
      Function mmul
               mmulD
               
      Single and Double Precision Matrix Multiply
      
        Criteria to invoke PowerPC vector code:
          1. a, b, c must be 16-byte aligned.
          2. M >= 8.
          3. N >= 32.
          4. P is a multiple of 8.
        
        If any of the above criteria are not satisfied, the PowerPC scalar code
        implementation will be used.
_______________________________________________________________________________
*/
/*
 *  vDSP_mmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mmul(
  float *  a,
  SInt32   aStride,
  float *  b,
  SInt32   bStride,
  float *  c,
  SInt32   cStride,
  SInt32   M,
  SInt32   N,
  SInt32   P)                                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_mmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mmulD(
  double *  a,
  SInt32    aStride,
  double *  b,
  SInt32    bStride,
  double *  c,
  SInt32    cStride,
  SInt32    M,
  SInt32    N,
  SInt32    P)                                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
_______________________________________________________________________________
      Function zmma, zmms, zmsm, and zmmul
               zmmaD, zmmsD, zmsmD, and zmmulD
               
      Single and Double Precision Complex Split Matrix mul/add, mul/sub, sub/mul, 
                                                       and mul
      
        Criteria to invoke PowerPC vector code:
          1. a, b, c, and d must be 16-byte aligned.
          2. N is a multiple of 4.
          3. P is a multiple of 4.
          4. I, J, K, L = 1;
          
       If any of the above criteria are not satisfied, the PowerPC scalar code
       implementation will be used.
_______________________________________________________________________________
*/
/*
 *  vDSP_zmma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmma(
  DSPSplitComplex *  a,
  SInt32             i,
  DSPSplitComplex *  b,
  SInt32             j,
  DSPSplitComplex *  c,
  SInt32             k,
  DSPSplitComplex *  d,
  SInt32             l,
  SInt32             M,
  SInt32             N,
  SInt32             P)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmmaD(
  DSPDoubleSplitComplex *  a,
  SInt32                   i,
  DSPDoubleSplitComplex *  b,
  SInt32                   j,
  DSPDoubleSplitComplex *  c,
  SInt32                   k,
  DSPDoubleSplitComplex *  d,
  SInt32                   l,
  SInt32                   M,
  SInt32                   N,
  SInt32                   P)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmms()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmms(
  DSPSplitComplex *  a,
  SInt32             i,
  DSPSplitComplex *  b,
  SInt32             j,
  DSPSplitComplex *  c,
  SInt32             k,
  DSPSplitComplex *  d,
  SInt32             l,
  SInt32             M,
  SInt32             N,
  SInt32             P)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmmsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmmsD(
  DSPDoubleSplitComplex *  a,
  SInt32                   i,
  DSPDoubleSplitComplex *  b,
  SInt32                   j,
  DSPDoubleSplitComplex *  c,
  SInt32                   k,
  DSPDoubleSplitComplex *  d,
  SInt32                   l,
  SInt32                   M,
  SInt32                   N,
  SInt32                   P)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmsm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmsm(
  DSPSplitComplex *  a,
  SInt32             i,
  DSPSplitComplex *  b,
  SInt32             j,
  DSPSplitComplex *  c,
  SInt32             k,
  DSPSplitComplex *  d,
  SInt32             l,
  SInt32             M,
  SInt32             N,
  SInt32             P)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmsmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmsmD(
  DSPDoubleSplitComplex *  a,
  SInt32                   i,
  DSPDoubleSplitComplex *  b,
  SInt32                   j,
  DSPDoubleSplitComplex *  c,
  SInt32                   k,
  DSPDoubleSplitComplex *  d,
  SInt32                   l,
  SInt32                   M,
  SInt32                   N,
  SInt32                   P)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmmul(
  DSPSplitComplex *  a,
  SInt32             i,
  DSPSplitComplex *  b,
  SInt32             j,
  DSPSplitComplex *  c,
  SInt32             k,
  SInt32             M,
  SInt32             N,
  SInt32             P)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  vDSP_zmmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zmmulD(
  DSPDoubleSplitComplex *  a,
  SInt32                   i,
  DSPDoubleSplitComplex *  b,
  SInt32                   j,
  DSPDoubleSplitComplex *  c,
  SInt32                   k,
  SInt32                   M,
  SInt32                   N,
  SInt32                   P)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vadd
             vaddD
    
    Floating Point Add in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vadd(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vaddD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vaddD(
  const double   input1[],
  SInt32         stride1,
  const double   input2[],
  SInt32         stride2,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vsub
             vsubD
             
     Floating Point Substract in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vsub(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vsubD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsubD(
  const double   input1[],
  SInt32         stride1,
  const double   input2[],
  SInt32         stride2,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vmul
             vmulD
             
    Floating Point Multiply in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vmul(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmulD(
  const double   input1[],
  SInt32         stride1,
  const double   input2[],
  SInt32         stride2,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vsmul
             vsmulD
    
    Floating Point - Scalar Multiply in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vsmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vsmul(
  const float    input1[],
  SInt32         stride1,
  const float *  input2,
  float          result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vsmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmulD(
  const double    input1[],
  SInt32          stride1,
  const double *  input2,
  double          result[],
  SInt32          strideResult,
  UInt32          size)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vsq
             vsqD
    
    Floating Point Square in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input and result are relatively aligned.
        2. size >= 8
        3. strideInput = 1
        4. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vsq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vsq(
  const float   input[],
  SInt32        strideInput,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vsqD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsqD(
  const double   input[],
  SInt32         strideInput,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vssq
             vssqD
             
    Floating Point Signed Square in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input and result must be all relatively aligned.
        2. size >= 8
        3. strideInput = 1
        4. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vssq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vssq(
  const float   input[],
  SInt32        strideInput,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vssqD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vssqD(
  const double   input[],
  SInt32         strideInput,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function dotpr
             dotprD
    
    Floating Point Dot product in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 are relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_dotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_dotpr(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float *       result,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_dotprD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_dotprD(
  const double   input1[],
  SInt32         stride1,
  const double   input2[],
  SInt32         stride2,
  double *       result,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function vam
             vamD
             
    Floating Point vadd and Multiply in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1, input2, input_3 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. stride_3 = 1
        6. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_vam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_vam(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  const float   input3[],
  SInt32        stride3,
  float         result[],
  SInt32        strideResult,
  UInt32        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_vamD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vamD(
  const double   input1[],
  SInt32         stride1,
  const double   input2[],
  SInt32         stride2,
  const double   input3[],
  SInt32         stride3,
  double         result[],
  SInt32         strideResult,
  UInt32         size)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zconv
             zconvD
                
    Split Complex Convolution and Correlation in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. signal->realp, signal->imagp, result->realp, result->imagp
           must be relatively aligned.
        2. 4 <= lenFilter <= 128
        3. lenResult > 20
        4. signalStride = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  strideFilter can be positive for correlation
      or negative for convolution
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zconv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zconv(
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  filter,
  SInt32             strideFilter,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  SInt32             lenResult,
  SInt32             lenFilter)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zconvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zconvD(
  DSPDoubleSplitComplex *  signal,
  SInt32                   signalStride,
  DSPDoubleSplitComplex *  filter,
  SInt32                   strideFilter,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  SInt32                   lenResult,
  SInt32                   lenFilter)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zvadd
             zvaddD
    
    Split Complex vadd in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zvadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zvadd(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zvaddD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvaddD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zvsub
             zvsubD
             
    Split Complex Substract in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zvsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zvsub(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zvsubD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvsubD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zvmul
             zvmulD
             
    Split Complex Multiply in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1

      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.  The conjugate value can be 1 or -1.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zvmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zvmul(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size,
  SInt32             conjugate)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zvmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmulD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size,
  SInt32                   conjugate)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zdotpr
             zdotprD
             
    Split Complex Dot product in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp are all
           relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zdotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zdotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zdotprD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zdotprD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zidotpr
             zidotprD
             
    Split Complex Inner Dot product in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp must be
           all relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zidotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zidotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zidotprD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zidotprD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zrdotpr
             zrdotprD
                
    Split Complex - Real Dot product in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2 are must be relatively aligned.
        2. size >= 16
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zrdotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zrdotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zrdotprD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrdotprD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  const double             input2[],
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zvcma
             zvcmaD
             
    Split Complex Conjugate Multiply And vadd in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
          input_3.realp, input_3.imagp, result.realp, result.imagp
          must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. stride_3 = 1
        6. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zvcma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zvcma(
  const DSPSplitComplex *  input1,
  SInt32                   stride1,
  const DSPSplitComplex *  input2,
  SInt32                   stride2,
  DSPSplitComplex *        input3,
  SInt32                   stride3,
  DSPSplitComplex *        result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zvcmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvcmaD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  DSPDoubleSplitComplex *  input2,
  SInt32                   stride2,
  DSPDoubleSplitComplex *  input3,
  SInt32                   stride3,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zrvadd
             zrvaddD
             
    Split Complex - Real Add in Single and Double Precision
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zrvadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zrvadd(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zrvaddD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrvaddD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  const double             input2[],
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zrvsub
             zrvsubD
                
    Split Complex - Real Substract in Single and Double Precision
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zrvsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zrvsub(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zrvsubD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrvsubD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  const double             input2[],
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
    Function zrvmul
             zrvmulD
             
    Split Complex - Real Multiply
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalar code
      implementation will be used.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
*/
/*
 *  vDSP_zrvmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_zrvmul(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  vDSP_zrvmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrvmulD(
  DSPDoubleSplitComplex *  input1,
  SInt32                   stride1,
  const double             input2[],
  SInt32                   stride2,
  DSPDoubleSplitComplex *  result,
  SInt32                   strideResult,
  UInt32                   size)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;




/*Vector Double Precision to Single Precision Convert*/
/*
 *  vDSP_vdpsp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdpsp(
  double *       A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to Double Precision Convert*/
/*
 *  vDSP_vspdp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vspdp(
  float *        A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer Absolute Value*/
/*
 *  vDSP_vabsi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vabsi(
  int *          A,
  int            I,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Equivalence, 32-bit Logical*/
/*
 *  vDSP_veqvi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_veqvi(
  unsigned int *  A,
  int             I,
  unsigned int *  B,
  int             J,
  unsigned int *  C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer Divide*/
/*
 *  vDSP_vdivi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdivi(
  int *          A,
  int            I,
  int *          B,
  int            J,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer Fill*/
/*
 *  vDSP_vfilli()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfilli(
  int *          A,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer Scalar Add*/
/*
 *  vDSP_vsaddi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsaddi(
  int *          A,
  int            I,
  int *          B,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer Scalar Divide*/
/*
 *  vDSP_vsdivi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsdivi(
  int *          A,
  int            I,
  int *          B,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*
  ////////////////////////////////////////
                                        // 
    New Single Precision Functions      //
                                        //
  ////////////////////////////////////////
*/

/*Accumulating Autospectrum*/
/*
 *  vDSP_zaspec()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zaspec(
  DSPSplitComplex *  A,
  float *            C,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Blackman Window*/
/*
 *  vDSP_blkman_window()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_blkman_window(
  float *        C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Coherence Function*/
/*
 *  vDSP_zcoher()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zcoher(
  float *            A,
  float *            B,
  DSPSplitComplex *  C,
  float *            D,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex/Real Down Sample with Anti-aliasing*/
/*
 *  vDSP_zrdesamp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrdesamp(
  DSPSplitComplex *  A,
  int                I,
  float *            B,
  DSPSplitComplex *  C,
  int                N,
  int                M)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Divide by Real Vector*/
/*
 *  vDSP_zrvdiv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrvdiv(
  DSPSplitComplex *  A,
  int                I,
  float *            B,
  int                J,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Transfer Function*/
/*
 *  vDSP_ztrans()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_ztrans(
  float *            A,
  DSPSplitComplex *  B,
  DSPSplitComplex *  C,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Divide by Complex Vector*/
/*
 *  vDSP_zvdiv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvdiv(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  B,
  int                J,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Number Accumulating Cross-Spectrum*/
/*
 *  vDSP_zcspec()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zcspec(
  DSPSplitComplex *  A,
  DSPSplitComplex *  B,
  DSPSplitComplex *  C,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Absolute Value*/
/*
 *  vDSP_zvabs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvabs(
  DSPSplitComplex *  A,
  int                I,
  float *            C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Conjugate and Multiply*/
/*
 *  vDSP_zvcmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvcmul(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  B,
  int                J,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Conjugate */
/*
 *  vDSP_zvconj()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvconj(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Scalar Multiply*/
/*
 *  vDSP_zvzsml()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvzsml(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  B,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Fill */
/*
 *  vDSP_zvfill()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvfill(
  DSPSplitComplex *  A,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Magnitudes Squared*/
/*
 *  vDSP_zvmags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmags(
  DSPSplitComplex *  A,
  int                I,
  float *            C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Magnitudes Square and Add*/
/*
 *  vDSP_zvmgsa()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmgsa(
  DSPSplitComplex *  A,
  int                I,
  float *            B,
  int                J,
  float *            C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Move*/
/*
 *  vDSP_zvmov()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmov(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Negate*/
/*
 *  vDSP_zvneg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvneg(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Phase*/
/*
 *  vDSP_zvphas()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvphas(
  DSPSplitComplex *  A,
  int                I,
  float *            C,
  int                K,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Scalar Multiply Add*/
/*
 *  vDSP_zvsma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvsma(
  DSPSplitComplex *  A,
  int                I,
  DSPSplitComplex *  B,
  DSPSplitComplex *  C,
  int                K,
  DSPSplitComplex *  D,
  int                L,
  unsigned int       N)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Difference Equation, 2 Poles, 2 Zeros*/
/*
 *  vDSP_deq22()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_deq22(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Convolution with Decimation*/
/*
 *  vDSP_desamp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_desamp(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Hamming Window*/
/*
 *  vDSP_hamm_window()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_hamm_window(
  float *        C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Hanning Window*/
/*
 *  vDSP_hann_window()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_hann_window(
  float *        C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude*/
/*
 *  vDSP_maxmgv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxmgv(
  const float *  A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude with Index*/
/*
 *  vDSP_maxmgvi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxmgvi(
  float *        A,
  int            I,
  float *        C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Value*/
/*
 *  vDSP_maxv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Value with Index*/
/*
 *  vDSP_maxvi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxvi(
  float *        A,
  int            I,
  float *        C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Magnitude*/
/*
 *  vDSP_meamgv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_meamgv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Value*/
/*
 *  vDSP_meanv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_meanv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Square Value*/
/*
 *  vDSP_measqv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_measqv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude*/
/*
 *  vDSP_minmgv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minmgv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude with Index*/
/*
 *  vDSP_minmgvi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minmgvi(
  float *        A,
  int            I,
  float *        C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Value*/
/*
 *  vDSP_minv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Value with Index*/
/*
 *  vDSP_minvi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minvi(
  float *        A,
  int            I,
  float *        C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Out-Of-Place Real Matrix Move*/
/*
 *  vDSP_mmov()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mmov(
  float *        A,
  float *        C,
  unsigned int   NC,
  unsigned int   NR,
  unsigned int   TCA,
  unsigned int   TCC)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean of Signed Squares*/
/*
 *  vDSP_mvessq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mvessq(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Find Zero Crossing*/
/*
 *  vDSP_nzcros()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_nzcros(
  float *         A,
  int             I,
  unsigned int    B,
  int *           C,
  unsigned int *  D,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Retangular to Polar*/
/*
 *  vDSP_polar()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_polar(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Polar to Rectangular*/
/*
 *  vDSP_rect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_rect(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Root-Mean-Square*/
/*
 *  vDSP_rmsqv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_rmsqv(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Scalar Vector Divide*/
/*
 *  vDSP_svdiv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svdiv(
  float *        A,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum*/
/*
 *  vDSP_sve()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_sve(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Magnitude*/
/*
 *  vDSP_svemg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svemg(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Square*/
/*
 *  vDSP_svesq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svesq(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Signed Square*/
/*
 *  vDSP_svs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svs(
  float *        A,
  int            I,
  float *        C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add, Add, and Multiply*/
/*
 *  vDSP_vaam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vaam(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Absolute Value*/
/*
 *  vDSP_vabs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vabs(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add, Subtract, and Multiply*/
/*
 *  vDSP_vasbm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vasbm(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add and Scalar Multiply*/
/*
 *  vDSP_vasm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vasm(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Linear Average*/
/*
 *  vDSP_vavlin()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vavlin(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clip and Count*/
/*
 *  vDSP_vclipc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclipc(
  float *         A,
  int             I,
  float *         B,
  float *         C,
  float *         D,
  int             L,
  unsigned int    N,
  unsigned int *  NLOW,
  unsigned int *  NHI)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clip*/
/*
 *  vDSP_vclip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclip(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clear*/
/*
 *  vDSP_vclr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclr(
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Compress*/
/*
 *  vDSP_vcmprs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vcmprs(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Convert to Decibels, Power, or Amplitude*/
/*
 *  vDSP_vdbcon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdbcon(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   F)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Distance*/
/*
 *  vDSP_vdist()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdist(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Divide*/
/*
 *  vDSP_vdiv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdiv(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Envelope*/
/*
 *  vDSP_venvlp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_venvlp(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Fill*/
/*
 *  vDSP_vfill()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfill(
  float *        A,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 8-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix8(
  float *        A,
  int            I,
  char *         C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 16-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix16(
  float *        A,
  int            I,
  short *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 32-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix32(
  float *        A,
  int            I,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 8-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr8(
  float *        A,
  int            I,
  char *         C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 16-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr16(
  float *        A,
  int            I,
  short *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 32-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr32(
  float *        A,
  int            I,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 8-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu8(
  float *          A,
  int              I,
  unsigned char *  C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 16-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu16(
  float *           A,
  int               I,
  unsigned short *  C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 32-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu32(
  float *         A,
  int             I,
  unsigned int *  C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 8-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru8(
  float *          A,
  int              I,
  unsigned char *  C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 16-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru16(
  float *           A,
  int               I,
  unsigned short *  C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Single Precision to 32-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru32(
  float *         A,
  int             I,
  unsigned int *  C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 8-bit Integer to Single Precision Convert*/
/*
 *  vDSP_vflt8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt8(
  char *         A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 16-bit Integer to Single Precision Convert*/
/*
 *  vDSP_vflt16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt16(
  short *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 32-bit Integer to Single Precision Convert*/
/*
 *  vDSP_vflt32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt32(
  int *          A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 8-bit Unsigned Integer to Single Precision Convert*/
/*
 *  vDSP_vfltu8()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu8(
  unsigned char *  A,
  int              I,
  float *          C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 16-bit Unsigned Integer to Single Precision Convert*/
/*
 *  vDSP_vfltu16()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu16(
  unsigned short *  A,
  int               I,
  float *           C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 32-bit Unisgned Integer to Single Precision Convert*/
/*
 *  vDSP_vfltu32()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu32(
  unsigned int *  A,
  int             I,
  float *         C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Truncate to Fraction*/
/*
 *  vDSP_vfrac()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfrac(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Gather*/
/*
 *  vDSP_vgathr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgathr(
  float *        A,
  int *          B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Gather, Absolute Pointers*/
/*
 *  vDSP_vgathra()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgathra(
  float **       A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Tapered Ramp*/
/*
 *  vDSP_vgen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgen(
  float *        A,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Generate by Extrapolation and Interpolation*/
/*
 *  vDSP_vgenp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgenp(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Inverted Clip*/
/*
 *  vDSP_viclip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_viclip(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Index  */
/*
 *  vDSP_vindex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vindex(
  float *        A,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Interpolation*/
/*
 *  vDSP_vintb()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vintb(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Test Limit*/
/*
 *  vDSP_vlim()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vlim(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Linear Interpolation */
/*
 *  vDSP_vlint()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vlint(
  float *        A,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mulitply and Add*/
/*
 *  vDSP_vma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vma(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maxima*/
/*
 *  vDSP_vmax()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmax(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude */
/*
 *  vDSP_vmaxmg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmaxmg(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minima*/
/*
 *  vDSP_vmin()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmin(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude*/
/*
 *  vDSP_vminmg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vminmg(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply, Multiply, and Add*/
/*
 *  vDSP_vmma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmma(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply, Multiply, and Subtract*/
/*
 *  vDSP_vmmsb()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmmsb(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply and Scalar Add*/
/*
 *  vDSP_vmsa()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmsa(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply and Subtract*/
/*
 *  vDSP_vmsb()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmsb(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Negative Absolute Value */
/*
 *  vDSP_vnabs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vnabs(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector negate*/
/*
 *  vDSP_vneg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vneg(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Polynomial*/
/*
 *  vDSP_vpoly()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vpoly(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   P)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Pythagoras */
/*
 *  vDSP_vpythg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vpythg(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Quadratic Interpolation*/
/*
 *  vDSP_vqint()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vqint(
  float *        A,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Build Ramped Vector*/
/*
 *  vDSP_vramp()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vramp(
  float *        A,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Running Sum Integration*/
/*
 *  vDSP_vrsum()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vrsum(
  float *        A,
  int            I,
  float *        S,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Reverse Order In-Place*/
/*
 *  vDSP_vrvrs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vrvrs(
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Add*/
/*
 *  vDSP_vsadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsadd(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract and Multiply*/
/*
 *  vDSP_vsbm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbm(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract, Subtract, and Multiply*/
/*
 *  vDSP_vsbsbm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbsbm(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  float *        D,
  int            L,
  float *        E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract and Scalar Multiply*/
/*
 *  vDSP_vsbsm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbsm(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Divdie*/
/*
 *  vDSP_vsdiv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsdiv(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Simpson Integration*/
/*
 *  vDSP_vsimps()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsimps(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Vector Add*/
/*
 *  vDSP_vsma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsma(
  const float *  A,
  int            I,
  const float *  B,
  const float *  C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Scalar Add */
/*
 *  vDSP_vsmsa()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmsa(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Vector Subtract */
/*
 *  vDSP_vsmsb()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmsb(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector In-Place Sort */
/*
 *  vDSP_vsort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsort(
  float *        C,
  unsigned int   N,
  int            OFLAG)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer In-Place Sort*/
/*
 *  vDSP_vsorti()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsorti(
  float *        C,
  int *          IC,
  int *          List_addr,
  unsigned int   N,
  int            OFLAG)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Swap */
/*
 *  vDSP_vswap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vswap(
  float *        A,
  int            I,
  float *        B,
  int            J,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sliding Window Sum */
/*
 *  vDSP_vswsum()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vswsum(
  float *        A,
  int            I,
  float *        C,
  int            K,
  unsigned int   N,
  unsigned int   P)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Interpolation, Table Lookup*/
/*
 *  vDSP_vtabi()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtabi(
  float *        A,
  int            I,
  float *        S1,
  float *        S2,
  float *        C,
  unsigned int   M,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold*/
/*
 *  vDSP_vthr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthr(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold with Zero Fill*/
/*
 *  vDSP_vthres()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthres(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold with Signed Constant*/
/*
 *  vDSP_vthrsc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthrsc(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  float *        D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Tapered Merge of Two Vectors*/
/*
 *  vDSP_vtmerg()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtmerg(
  float *        A,
  int            I,
  float *        B,
  int            J,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Trapezoidal Integration*/
/*
 *  vDSP_vtrapz()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtrapz(
  float *        A,
  int            I,
  float *        B,
  float *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Wiener Levinson*/
/*
 *  vDSP_wiener()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_wiener(
  int      L,
  float *  A,
  float *  C,
  float *  F,
  float *  P,
  int      IFLG,
  int *    IERR)                                              AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;




/*
  ////////////////////////////////////////
                                        // 
    New Double Precision Functions      //
                                        //
  ////////////////////////////////////////
*/

/*Autocorrelation*/
/*
 *  vDSP_acorD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_acorD(
  double *  A,
  double *  C,
  int       N,
  int       M)                                                AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*
 *  vDSP_acorfD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_acorfD(
  double *  A,
  double *  C,
  int       N,
  int       M)                                                AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*
 *  vDSP_acortD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_acortD(
  double *  A,
  double *  C,
  int       N,
  int       M)                                                AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Accumulating Autospectrum*/
/*
 *  vDSP_zaspecD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zaspecD(
  DSPDoubleSplitComplex *  A,
  double *                 C,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Blackman Window*/
/*
 *  vDSP_blkman_windowD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_blkman_windowD(
  double *       C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Coherence Function*/
/*
 *  vDSP_zcoherD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zcoherD(
  double *                 A,
  double *                 B,
  DSPDoubleSplitComplex *  C,
  double *                 D,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex/Real Down Sample with Anti-aliasing*/
/*
 *  vDSP_zrdesampD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrdesampD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 B,
  DSPDoubleSplitComplex *  C,
  int                      N,
  int                      M)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Divide by Real Vector*/
/*
 *  vDSP_zrvdivD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zrvdivD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 B,
  int                      J,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Divide by Complex Vector*/
/*
 *  vDSP_zvdivD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvdivD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  B,
  int                      J,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Number Accumulating Cross-Spectrum*/
/*
 *  vDSP_zcspecD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zcspecD(
  DSPDoubleSplitComplex *  A,
  DSPDoubleSplitComplex *  B,
  DSPDoubleSplitComplex *  C,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Transfer Function*/
/*
 *  vDSP_ztransD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_ztransD(
  double *                 A,
  DSPDoubleSplitComplex *  B,
  DSPDoubleSplitComplex *  C,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Absolute Value*/
/*
 *  vDSP_zvabsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvabsD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Conjugate and Multiply*/
/*
 *  vDSP_zvcmulD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvcmulD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  B,
  int                      J,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Conjugate */
/*
 *  vDSP_zvconjD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvconjD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Scalar Multiply*/
/*
 *  vDSP_zvzsmlD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvzsmlD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  B,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Fill */
/*
 *  vDSP_zvfillD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvfillD(
  DSPDoubleSplitComplex *  A,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Magnitudes Squared*/
/*
 *  vDSP_zvmagsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmagsD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Magnitudes Square and Add*/
/*
 *  vDSP_zvmgsaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmgsaD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 B,
  int                      J,
  double *                 C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Move*/
/*
 *  vDSP_zvmovD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvmovD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Negate*/
/*
 *  vDSP_zvnegD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvnegD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Phase*/
/*
 *  vDSP_zvphasD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvphasD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  double *                 C,
  int                      K,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Complex Vector Scalar Multiply Add*/
/*
 *  vDSP_zvsmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_zvsmaD(
  DSPDoubleSplitComplex *  A,
  int                      I,
  DSPDoubleSplitComplex *  B,
  DSPDoubleSplitComplex *  C,
  int                      K,
  DSPDoubleSplitComplex *  D,
  int                      L,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Difference Equation, 2 Poles, 2 Zeros*/
/*
 *  vDSP_deq22D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_deq22D(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Convolution with Decimation*/
/*
 *  vDSP_desampD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_desampD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Hamming Window*/
/*
 *  vDSP_hamm_windowD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_hamm_windowD(
  double *       C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Create Hanning Window*/
/*
 *  vDSP_hann_windowD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_hann_windowD(
  double *       C,
  unsigned int   N,
  int            FLAG)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude*/
/*
 *  vDSP_maxmgvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxmgvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude with Index*/
/*
 *  vDSP_maxmgviD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxmgviD(
  double *       A,
  int            I,
  double *       C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Value*/
/*
 *  vDSP_maxvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Value with Index*/
/*
 *  vDSP_maxviD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_maxviD(
  double *       A,
  int            I,
  double *       C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Magnitude*/
/*
 *  vDSP_meamgvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_meamgvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Value*/
/*
 *  vDSP_meanvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_meanvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean Square Value*/
/*
 *  vDSP_measqvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_measqvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude*/
/*
 *  vDSP_minmgvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minmgvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude with Index*/
/*
 *  vDSP_minmgviD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minmgviD(
  double *       A,
  int            I,
  double *       C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Value*/
/*
 *  vDSP_minvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Value with Index*/
/*
 *  vDSP_minviD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_minviD(
  double *       A,
  int            I,
  double *       C,
  int *          IC,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Out-Of-Place Real Matrix Move*/
/*
 *  vDSP_mmovD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mmovD(
  double *       A,
  double *       C,
  unsigned int   NC,
  unsigned int   NR,
  unsigned int   TCA,
  unsigned int   TCC)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mean of Signed Squares*/
/*
 *  vDSP_mvessqD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_mvessqD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Find Zero Crossing*/
/*
 *  vDSP_nzcrosD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_nzcrosD(
  double *        A,
  int             I,
  unsigned int    B,
  int *           C,
  unsigned int *  D,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Retangular to Polar*/
/*
 *  vDSP_polarD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_polarD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Polar to Rectangular*/
/*
 *  vDSP_rectD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_rectD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Root-Mean-Square*/
/*
 *  vDSP_rmsqvD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_rmsqvD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Scalar Vector Divide*/
/*
 *  vDSP_svdivD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svdivD(
  double *       A,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum*/
/*
 *  vDSP_sveD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_sveD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Magnitude*/
/*
 *  vDSP_svemgD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svemgD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Square*/
/*
 *  vDSP_svesqD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svesqD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sum of Signed Square*/
/*
 *  vDSP_svsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_svsD(
  double *       A,
  int            I,
  double *       C,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Transfer Function*/
/*
 *  vDSP_ztransD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_ztransD(
  double *                 A,
  DSPDoubleSplitComplex *  B,
  DSPDoubleSplitComplex *  C,
  unsigned int             N)                                 AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add, Add, and Multiply*/
/*
 *  vDSP_vaamD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vaamD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Absolute Value*/
/*
 *  vDSP_vabsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vabsD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add, Subtract, and Multiply*/
/*
 *  vDSP_vasbmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vasbmD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Add and Scalar Multiply*/
/*
 *  vDSP_vasmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vasmD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Linear Average*/
/*
 *  vDSP_vavlinD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vavlinD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clip and Count*/
/*
 *  vDSP_vclipcD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclipcD(
  double *        A,
  int             I,
  double *        B,
  double *        C,
  double *        D,
  int             L,
  unsigned int    N,
  unsigned int *  NLOW,
  unsigned int *  NHI)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clip*/
/*
 *  vDSP_vclipD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclipD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Clear*/
/*
 *  vDSP_vclrD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vclrD(
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Compress*/
/*
 *  vDSP_vcmprsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vcmprsD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Convert to Decibels, Power, or Amplitude*/
/*
 *  vDSP_vdbconD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdbconD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   F)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Distance*/
/*
 *  vDSP_vdistD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdistD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Divide*/
/*
 *  vDSP_vdivD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vdivD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Envelope*/
/*
 *  vDSP_venvlpD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_venvlpD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Fill*/
/*
 *  vDSP_vfillD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfillD(
  double *       A,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 8-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix8D(
  double *       A,
  int            I,
  char *         C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 16-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix16D(
  double *       A,
  int            I,
  short *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 32-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfix32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfix32D(
  double *       A,
  int            I,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 8-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr8D(
  double *       A,
  int            I,
  char *         C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 16-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr16D(
  double *       A,
  int            I,
  short *        C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 32-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixr32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixr32D(
  double *       A,
  int            I,
  int *          C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 8-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu8D(
  double *         A,
  int              I,
  unsigned char *  C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 16-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu16D(
  double *          A,
  int               I,
  unsigned short *  C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 32-bit Integer Convert with Round towards Zero*/
/*
 *  vDSP_vfixu32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixu32D(
  double *        A,
  int             I,
  unsigned int *  C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 8-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru8D(
  double *         A,
  int              I,
  unsigned char *  C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 16-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru16D(
  double *          A,
  int               I,
  unsigned short *  C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Double Precision to 32-bit Integer Convert with Round to Nearest*/
/*
 *  vDSP_vfixru32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfixru32D(
  double *        A,
  int             I,
  unsigned int *  C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 8-bit Integer to Double Precision Convert*/
/*
 *  vDSP_vflt8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt8D(
  char *         A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 16-bit Integer to Double Precision Convert*/
/*
 *  vDSP_vflt16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt16D(
  short *        A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 32-bit Integer to Double Precision Convert*/
/*
 *  vDSP_vflt32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vflt32D(
  int *          A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 8-bit Unsigned Integer to Double Precision Convert*/
/*
 *  vDSP_vfltu8D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu8D(
  unsigned char *  A,
  int              I,
  double *         C,
  int              K,
  unsigned int     N)                                         AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 16-bit Unsigned Integer to Double Precision Convert*/
/*
 *  vDSP_vfltu16D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu16D(
  unsigned short *  A,
  int               I,
  double *          C,
  int               K,
  unsigned int      N)                                        AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector 32-bit Unisgned Integer to Double Precision Convert*/
/*
 *  vDSP_vfltu32D()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfltu32D(
  unsigned int *  A,
  int             I,
  double *        C,
  int             K,
  unsigned int    N)                                          AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Truncate to Fraction*/
/*
 *  vDSP_vfracD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vfracD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Gather*/
/*
 *  vDSP_vgathrD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgathrD(
  double *       A,
  int *          B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Gather, Absolute Pointers*/
/*
 *  vDSP_vgathraD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgathraD(
  double **      A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Tapered Ramp*/
/*
 *  vDSP_vgenD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgenD(
  double *       A,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Generate by Extrapolation and Interpolation*/
/*
 *  vDSP_vgenpD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vgenpD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Inverted Clip*/
/*
 *  vDSP_viclipD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_viclipD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Index  */
/*
 *  vDSP_vindexD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vindexD(
  double *       A,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Interpolation*/
/*
 *  vDSP_vintbD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vintbD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Test Limit*/
/*
 *  vDSP_vlimD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vlimD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Linear Interpolation */
/*
 *  vDSP_vlintD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vlintD(
  double *       A,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Mulitply and Add*/
/*
 *  vDSP_vmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmaD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maxima*/
/*
 *  vDSP_vmaxD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmaxD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Maximum Magnitude */
/*
 *  vDSP_vmaxmgD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmaxmgD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minima*/
/*
 *  vDSP_vminD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vminD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Minimum Magnitude*/
/*
 *  vDSP_vminmgD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vminmgD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply, Multiply, and Add*/
/*
 *  vDSP_vmmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmmaD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply, Multiply, and Subtract*/
/*
 *  vDSP_vmmsbD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmmsbD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply and Scalar Add*/
/*
 *  vDSP_vmsaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmsaD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Multiply and Subtract*/
/*
 *  vDSP_vmsbD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vmsbD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Negative Absolute Value */
/*
 *  vDSP_vnabsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vnabsD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector negate*/
/*
 *  vDSP_vnegD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vnegD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Polynomial*/
/*
 *  vDSP_vpolyD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vpolyD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   P)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Pythagoras */
/*
 *  vDSP_vpythgD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vpythgD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Quadratic Interpolation*/
/*
 *  vDSP_vqintD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vqintD(
  double *       A,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   M)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Build Ramped Vector*/
/*
 *  vDSP_vrampD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vrampD(
  double *       A,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Running Sum Integration*/
/*
 *  vDSP_vrsumD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vrsumD(
  double *       A,
  int            I,
  double *       S,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Reverse Order In-Place*/
/*
 *  vDSP_vrvrsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vrvrsD(
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Add*/
/*
 *  vDSP_vsaddD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsaddD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract and Multiply*/
/*
 *  vDSP_vsbmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbmD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract, Subtract, and Multiply*/
/*
 *  vDSP_vsbsbmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbsbmD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  double *       D,
  int            L,
  double *       E,
  int            M,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Subtract and Scalar Multiply*/
/*
 *  vDSP_vsbsmD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsbsmD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Divdie*/
/*
 *  vDSP_vsdivD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsdivD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Simpson Integration*/
/*
 *  vDSP_vsimpsD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsimpsD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Vector Add*/
/*
 *  vDSP_vsmaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmaD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Scalar Add */
/*
 *  vDSP_vsmsaD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmsaD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Scalar Multiply and Vector Subtract */
/*
 *  vDSP_vsmsbD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsmsbD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector In-Place Sort */
/*
 *  vDSP_vsortD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsortD(
  double *       C,
  unsigned int   N,
  int            OFLAG)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Integer In-Place Sort*/
/*
 *  vDSP_vsortiD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vsortiD(
  double *       C,
  int *          IC,
  int *          List_addr,
  unsigned int   N,
  int            OFLAG)                                       AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Swap */
/*
 *  vDSP_vswapD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vswapD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Sliding Window Sum */
/*
 *  vDSP_vswsumD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vswsumD(
  double *       A,
  int            I,
  double *       C,
  int            K,
  unsigned int   N,
  unsigned int   P)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Interpolation, Table Lookup*/
/*
 *  vDSP_vtabiD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtabiD(
  double *       A,
  int            I,
  double *       S1,
  double *       S2,
  double *       C,
  unsigned int   M,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold*/
/*
 *  vDSP_vthrD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthrD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold with Zero Fill*/
/*
 *  vDSP_vthresD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthresD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Threshold with Signed Constant*/
/*
 *  vDSP_vthrscD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vthrscD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  double *       D,
  int            L,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Tapered Merge of Two Vectors*/
/*
 *  vDSP_vtmergD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtmergD(
  double *       A,
  int            I,
  double *       B,
  int            J,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Vector Trapezoidal Integration*/
/*
 *  vDSP_vtrapzD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_vtrapzD(
  double *       A,
  int            I,
  double *       B,
  double *       C,
  int            K,
  unsigned int   N)                                           AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;


/*Wiener Levinson*/
/*
 *  vDSP_wienerD()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.4 and later in vecLib.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
vDSP_wienerD(
  int       L,
  double *  A,
  double *  C,
  double *  F,
  double *  P,
  int       IFLG,
  int *     IERR)                                             AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;



#ifndef USE_NON_APPLE_STANDARD_DATATYPES
#define USE_NON_APPLE_STANDARD_DATATYPES 1
#endif  /* !defined(USE_NON_APPLE_STANDARD_DATATYPES) */

#if USE_NON_APPLE_STANDARD_DATATYPES
enum {
  FFT_FORWARD                   = kFFTDirection_Forward,
  FFT_INVERSE                   = kFFTDirection_Inverse
};

enum {
  FFT_RADIX2                    = kFFTRadix2,
  FFT_RADIX3                    = kFFTRadix3,
  FFT_RADIX5                    = kFFTRadix5
};


typedef DSPComplex                      COMPLEX;
typedef DSPSplitComplex                 COMPLEX_SPLIT;
typedef DSPDoubleComplex                DOUBLE_COMPLEX;
typedef DSPDoubleSplitComplex           DOUBLE_COMPLEX_SPLIT;
#endif  /* USE_NON_APPLE_STANDARD_DATATYPES */


#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __VDSP__ */

