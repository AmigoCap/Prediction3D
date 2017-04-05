/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ceil.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "ceil.h"

/* Function Definitions */

/*
 * Arguments    : double x[300]
 * Return Type  : void
 */
void b_ceil(double x[300])
{
  int k;
  for (k = 0; k < 300; k++) {
    x[k] = ceil(x[k]);
  }
}

/*
 * File trailer for ceil.c
 *
 * [EOF]
 */
