/*
     File:       vecLib/vDSP.h
 
     Contains:   AltiVec DSP Interfaces
 
     Version:    vecLib-380.10
 
     Copyright:  � 2000-2013 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __VDSP__
#define __VDSP__

/*  For documentation on vDSP, search for "vDSP" at http://developer.apple.com,
	or search for one of the routine names below.
*/


#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=power


/*	These symbols describe the vecLib version associated with this header.

	vDSP_Version0 is a major version number.
	vDSP_Version1 is a minor version number.
*/
#define	vDSP_Version0	380
#define	vDSP_Version1	10


typedef unsigned long                   vDSP_Length;
/*    vDSP_Length is for numbers of elements in arrays and indices of
    elements in arrays.

    (It is also used for the base-two logarithm of numbers of elements,
    although a much smaller type is suitable for that.)
    */
typedef long                            vDSP_Stride;
/*    vDSP_Stride is for differences of indices of elements (which of
    course includes strides).
    */

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

typedef int                             FFTDirection;
typedef int                             FFTRadix;
enum {
  kFFTDirection_Forward         = 1,
  kFFTDirection_Inverse         = -1
};

enum {
  kFFTRadix2                    = 0,
  kFFTRadix3                    = 1,
  kFFTRadix5                    = 2
};

enum {
  vDSP_HALF_WINDOW              = 1,
  vDSP_HANN_DENORM              = 0,
  vDSP_HANN_NORM                = 2
};



/*  create_fftsetup and create_ffsetupD allocate memory and prepare constants
    used by single- and double-precision FFT routines, respectively.

    destroy_fftsetup and destroy_fftsetupD free the memory.
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
  vDSP_Length   __vDSP_log2n,
  FFTRadix      __vDSP_radix) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


/*
 *  vDSP_destroy_fftsetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with CarbonLib
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vDSP_destroy_fftsetup(FFTSetup __vDSP_setup) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


/*  ctoz and ctozD convert a complex array to a complex-split array.
    ztoc and ztocD convert a complex-split array to a complex array.
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
  const DSPComplex   __vDSP_C[],
  vDSP_Stride        __vDSP_strideC,
  DSPSplitComplex *  __vDSP_Z,
  vDSP_Stride        __vDSP_strideZ,
  vDSP_Length        __vDSP_size) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


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
  const DSPSplitComplex *  __vDSP_Z,
  vDSP_Stride              __vDSP_strideZ,
  DSPComplex               __vDSP_C[],
  vDSP_Stride              __vDSP_strideC,
  vDSP_Length              __vDSP_size) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


/*  In-place real-to-complex Discrete Fourier Transform routines.

    fft_zrip    Single-precision without temporary memory.
    fft_zript   Single-precision with temporary memory.
    fft_zripD   Double-precision without temporary memory.
    fft_zriptD  Double-precision with temporary memory.
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
  FFTSetup           __vDSP_setup,
  DSPSplitComplex *  __vDSP_ioData,
  vDSP_Stride        __vDSP_stride,
  vDSP_Length        __vDSP_log2n,
  FFTDirection       __vDSP_direction) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


/* Vector add, single-precision.*/
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
  const float   __vDSP_input1[],
  vDSP_Stride   __vDSP_stride1,
  const float   __vDSP_input2[],
  vDSP_Stride   __vDSP_stride2,
  float         __vDSP_result[],
  vDSP_Stride   __vDSP_strideResult,
  vDSP_Length   __vDSP_size) __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_4_0);


/* Complex-split vector absolute value, single-precision.*/
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
  DSPSplitComplex *  __vDSP_A,
  vDSP_Stride        __vDSP_I,
  float *            __vDSP_C,
  vDSP_Stride        __vDSP_K,
  vDSP_Length        __vDSP_N) __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_4_0);


/* Vector clip, single-precision.*/
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
  float *       __vDSP_A,
  vDSP_Stride   __vDSP_I,
  float *       __vDSP_B,
  float *       __vDSP_C,
  float *       __vDSP_D,
  vDSP_Stride   __vDSP_L,
  vDSP_Length   __vDSP_N) __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_4_0);


/* Vector clear, single-precision.*/
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
  float *       __vDSP_C,
  vDSP_Stride   __vDSP_K,
  vDSP_Length   __vDSP_N) __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_4_0);


/* Vector convert to decibels, power, or amplitude, single-precision.*/
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
  float *        __vDSP_A,
  vDSP_Stride    __vDSP_I,
  float *        __vDSP_B,
  float *        __vDSP_C,
  vDSP_Stride    __vDSP_K,
  vDSP_Length    __vDSP_N,
  unsigned int   __vDSP_F) __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_4_0);


/* Vector maxima, single-precision.*/
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
  const float * __vDSP_A,
  vDSP_Stride   __vDSP_I,
  const float * __vDSP_B,
  vDSP_Stride   __vDSP_J,
  float *       __vDSP_C,
  vDSP_Stride   __vDSP_K,
  vDSP_Length   __vDSP_N) __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_4_0);


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
