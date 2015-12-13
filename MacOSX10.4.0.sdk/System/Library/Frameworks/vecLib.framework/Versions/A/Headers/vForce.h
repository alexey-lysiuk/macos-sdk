/*
Copyright (c) 1999-2004 Apple Computer, Inc.  All rights reserved.

@APPLE_LICENSE_HEADER_START@

This file contains Original Code and/or Modifications of Original Code
as defined in and that are subject to the Apple Public Source License
Version 2.0 (the 'License'). You may not use this file except in
compliance with the License. Please obtain a copy of the License at
http://www.opensource.apple.com/apsl/ and read it before using this
file.

The Original Code and all software distributed under the License are
distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
Please see the License for the specific language governing rights and
limitations under the License.

@APPLE_LICENSE_HEADER_END@
*/

#ifndef __VFORCE_H
#define __VFORCE_H

#ifdef __cplusplus
#include <complex>
typedef std::complex<float> __float_complex_t;
typedef std::complex<double> __double_complex_t;
#else
#include "complex.h" /* included before math.h in order to get modern cabs() prototype */
typedef complex float __float_complex_t;
typedef complex double __double_complex_t;
#endif

#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 
When the float versions of the vector functions (vvrecf(), vvdivf(), etc.) are invoked on platforms equipped
with the AltiVec SIMD unit, they expect that "Java Mode" has been established in the AltiVec VSCR register.
"Java Mode" entails flushing de-normal vector floating point values to zero. Mac OS X sets the AltiVec VSCR
register to "Java Mode" by default when a new process is created. A process running in "Java Mode" enjoys 
performance advantages when executing AltiVec floating point instructions.

The double versions of the vector functions must be called with the IEEE rounding mode set to round-to-nearest and with exceptions masked off. 

The accuracy of the vector functions is comparable to that of the corresponding scalar functions in libm, though results may not be bit-wise identical. 
*/

/* Set y[i] to the reciprocal of x[i], for i=0,..,n-1 */
void vvrecf (float * /* y */, const float * /* x */, const int * /* n */); 
void vvrec (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set z[i] to y[i]/x[i], for i=0,..,n-1 */
void vvdivf (float * /* z */, const float * /* y */, const float * /* x */, const int *  /* n */); 
void vvdiv (double * /* z */, const double * /* y */, const double * /* x */, const int *  /* n */); 

/* Set y[i] to the square root of x[i], for i=0,..,n-1 */
void vvsqrtf (float * /* y */, const float * /* x */, const int * /* n */); 
void vvsqrt (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set y[i] to the reciprocal of the square root of x[i], for i=0,..,n-1 */
void vvrsqrtf (float * /* y */, const float * /* x */, const int * /* n */); 
void vvrsqrt (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set y[i] to the exponential function of x[i], for i=0,..,n-1 */
void vvexpf (float * /* y */, const float * /* x */, const int * /* n */); 
void vvexp (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set y[i] to the natural logarithm of x[i], for i=0,..,n-1 */
void vvlogf (float * /* y */, const float * /* x */, const int * /* n */); 
void vvlog (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set y[i] to the base 10 logarithm of x[i], for i=0,..,n-1 */
void vvlog10f (float * /* y */, const float * /* x */, const int * /* n */); 
void vvlog10 (double * /* y */, const double * /* x */, const int * /* n */); 

/* Set z[i] to x[i] ** y[i], for i=0,..,n-1 */
void vvpowf (float * /* z */, const float * /* y */, const float * /* x */, const int *  /* n */); 
void vvpow (double * /* z */, const double * /* y */, const double * /* x */, const int *  /* n */); 

/* Set y[i] to the sine of x[i], for i=0,..,n-1 */
void vvsinf (float * /* y */, const float * /* x */, const int * /* n */);
void vvsin (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the cosine of x[i], for i=0,..,n-1 */
void vvcosf (float * /* y */, const float * /* x */, const int * /* n */);
void vvcos (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the tangent of x[i], for i=0,..,n-1 */
void vvtanf (float * /* y */, const float * /* x */, const int * /* n */);
void vvtan (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the arcsine of x[i], for i=0,..,n-1 */
void vvasinf (float * /* y */, const float * /* x */, const int * /* n */);
void vvasin (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the arccosine of x[i], for i=0,..,n-1 */
void vvacosf (float * /* y */, const float * /* x */, const int * /* n */);
void vvacos (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the arctangent of x[i], for i=0,..,n-1 */
void vvatanf (float * /* y */, const float * /* x */, const int * /* n */);
void vvatan (double * /* y */, const double * /* x */, const int * /* n */);

/* Set z[i] to the arctangent of y[i]/x[i], for i=0,..,n-1 */
void vvatan2f (float * /* z */, const float * /* y */, const float * /* x */, const int * /* n */);
void vvatan2 (double * /* z */, const double * /* y */, const double * /* x */, const int * /* n */);

/* Set z[i] to the sine of x[i] and y[i] to the cosine of x[i], for i=0,..,n-1 */
void vvsincosf (float * /* z */, float * /* y */, const float * /* x */, const int * /* n */);
void vvsincos (double * /* z */, double * /* y */, const double * /* x */, const int * /* n */);

/* Set the real part of C[i] to the cosine of x[i] and the imaginary part of C[i] to the 
   sine of x[i], for i=0,..,n-1 */
void vvcosisinf (__float_complex_t * /* C */, const float * /* x */, const int * /* n */);
void vvcosisin (__double_complex_t * /* C */, const double * /* x */, const int * /* n */);

/* Set y[i] to the hyperbolic sine of x[i], for i=0,..,n-1 */
void vvsinhf (float * /* y */, const float * /* x */, const int * /* n */);
void vvsinh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the hyperbolic cosine of x[i], for i=0,..,n-1 */
void vvcoshf (float * /* y */, const float * /* x */, const int * /* n */);
void vvcosh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the hyperbolic tangent of x[i], for i=0,..,n-1 */
void vvtanhf (float * /* y */, const float * /* x */, const int * /* n */);
void vvtanh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the inverse hyperbolic sine of x[i], for i=0,..,n-1 */
void vvasinhf (float * /* y */, const float * /* x */, const int * /* n */);
void vvasinh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the inverse hyperbolic  cosine of x[i], for i=0,..,n-1 */
void vvacoshf (float * /* y */, const float * /* x */, const int * /* n */);
void vvacosh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the inverse hyperbolic  tangent of x[i], for i=0,..,n-1 */
void vvatanhf (float * /* y */, const float * /* x */, const int * /* n */);
void vvatanh (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the integer truncation of x[i], for i=0,..,n-1 */
void vvintf (float * /* y */, const float * /* x */, const int * /* n */);
void vvint (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the nearest integer to x[i], for i=0,..,n-1 */
void vvnintf (float * /* y */, const float * /* x */, const int * /* n */);
void vvnint (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the ceiling of x[i], for i=0,..,n-1 */
void vvceilf (float * /* y */, const float * /* x */, const int * /* n */);
void vvceil (double * /* y */, const double * /* x */, const int * /* n */);

/* Set y[i] to the floor of x[i], for i=0,..,n-1 */
void vvfloorf (float * /* y */, const float * /* x */, const int * /* n */);
void vvfloor (double * /* y */, const double * /* x */, const int * /* n */);

#ifdef __cplusplus
}
#endif
#endif /* __VFORCE_H */
