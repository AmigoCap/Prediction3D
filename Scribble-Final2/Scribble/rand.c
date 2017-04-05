/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rand.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "rand.h"
#include "modelCreation_data.h"

/* Variable Definitions */
static unsigned int c_state[625];

/* Function Declarations */
static double eml_rand_mcg16807(unsigned int *d_state);
static double eml_rand_mt19937ar(unsigned int d_state[625]);
static void twister_state_vector(unsigned int mt[625], unsigned int seed);

/* Function Definitions */

/*
 * Arguments    : unsigned int *d_state
 * Return Type  : double
 */
static double eml_rand_mcg16807(unsigned int *d_state)
{
  int hi;
  unsigned int test1;
  unsigned int test2;
  hi = (int)(*d_state / 127773U);
  test1 = 16807U * (*d_state - hi * 127773U);
  test2 = 2836U * hi;
  if (test1 < test2) {
    *d_state = (test1 - test2) + 2147483647U;
  } else {
    *d_state = test1 - test2;
  }

  return (double)*d_state * 4.6566128752457969E-10;
}

/*
 * Arguments    : unsigned int d_state[625]
 * Return Type  : double
 */
static double eml_rand_mt19937ar(unsigned int d_state[625])
{
  double r;
  int exitg1;
  int k;
  unsigned int u[2];
  unsigned int mti;
  int kk;
  unsigned int y;
  boolean_T isvalid;
  unsigned int b_y;
  unsigned int c_y;
  unsigned int d_y;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = d_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (d_state[kk] & 2147483648U) | (d_state[kk + 1] & 2147483647U);
          if ((int)(y & 1U) == 0) {
            b_y = y >> 1U;
          } else {
            b_y = y >> 1U ^ 2567483615U;
          }

          d_state[kk] = d_state[kk + 397] ^ b_y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (d_state[kk + 227] & 2147483648U) | (d_state[kk + 228] &
            2147483647U);
          if ((int)(y & 1U) == 0) {
            d_y = y >> 1U;
          } else {
            d_y = y >> 1U ^ 2567483615U;
          }

          d_state[kk + 227] = d_state[kk] ^ d_y;
        }

        y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
        if ((int)(y & 1U) == 0) {
          c_y = y >> 1U;
        } else {
          c_y = y >> 1U ^ 2567483615U;
        }

        d_state[623] = d_state[396] ^ c_y;
        mti = 1U;
      }

      y = d_state[(int)mti - 1];
      d_state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[k] = y;
    }

    u[0] >>= 5U;
    u[1] >>= 6U;
    r = 1.1102230246251565E-16 * ((double)u[0] * 6.7108864E+7 + (double)u[1]);
    if (r == 0.0) {
      if ((d_state[624] >= 1U) && (d_state[624] < 625U)) {
        isvalid = true;
      } else {
        isvalid = false;
      }

      if (isvalid) {
        isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (d_state[k - 1] == 0U) {
            k++;
          } else {
            isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!isvalid) {
        twister_state_vector(d_state, 5489U);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/*
 * Arguments    : unsigned int mt[625]
 *                unsigned int seed
 * Return Type  : void
 */
static void twister_state_vector(unsigned int mt[625], unsigned int seed)
{
  unsigned int r;
  int mti;
  r = seed;
  mt[0] = seed;
  for (mti = 0; mti < 623; mti++) {
    r = (r ^ r >> 30U) * 1812433253U + (mti + 1);
    mt[mti + 1] = r;
  }

  mt[624] = 624U;
}

/*
 * Arguments    : double r[6981975]
 * Return Type  : void
 */
void b_rand(double r[6981975])
{
  int k;
  unsigned int u0;
  unsigned int u1;
  if (method == 4U) {
    for (k = 0; k < 6981975; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 6981975; k++) {
      u0 = 69069U * b_state[0] + 1234567U;
      u1 = b_state[1] ^ b_state[1] << 13;
      u1 ^= u1 >> 17;
      u1 ^= u1 << 5;
      b_state[0] = u0;
      b_state[1] = u1;
      r[k] = (double)(u0 + u1) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    for (k = 0; k < 6981975; k++) {
      r[k] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * Arguments    : double r[300]
 * Return Type  : void
 */
void c_rand(double r[300])
{
  int k;
  unsigned int u2;
  unsigned int u3;
  if (method == 4U) {
    for (k = 0; k < 300; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 300; k++) {
      u2 = 69069U * b_state[0] + 1234567U;
      u3 = b_state[1] ^ b_state[1] << 13;
      u3 ^= u3 >> 17;
      u3 ^= u3 << 5;
      b_state[0] = u2;
      b_state[1] = u3;
      r[k] = (double)(u2 + u3) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    for (k = 0; k < 300; k++) {
      r[k] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double d_rand(void)
{
  double r;
  unsigned int u4;
  unsigned int u5;
  if (method == 4U) {
    r = eml_rand_mcg16807(&state);
  } else if (method == 5U) {
    u4 = 69069U * b_state[0] + 1234567U;
    u5 = b_state[1] ^ b_state[1] << 13;
    u5 ^= u5 >> 17;
    u5 ^= u5 << 5;
    b_state[0] = u4;
    b_state[1] = u5;
    r = (double)(u4 + u5) * 2.328306436538696E-10;
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    r = eml_rand_mt19937ar(c_state);
  }

  return r;
}

/*
 * Arguments    : double r[1395000]
 * Return Type  : void
 */
void e_rand(double r[1395000])
{
  int k;
  unsigned int u6;
  unsigned int u7;
  if (method == 4U) {
    for (k = 0; k < 1395000; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 1395000; k++) {
      u6 = 69069U * b_state[0] + 1234567U;
      u7 = b_state[1] ^ b_state[1] << 13;
      u7 ^= u7 >> 17;
      u7 ^= u7 << 5;
      b_state[0] = u6;
      b_state[1] = u7;
      r[k] = (double)(u6 + u7) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    for (k = 0; k < 1395000; k++) {
      r[k] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
