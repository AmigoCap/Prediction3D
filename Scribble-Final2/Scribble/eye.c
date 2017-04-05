/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eye.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "eye.h"

/* Function Definitions */

/*
 * Arguments    : double I[81]
 * Return Type  : void
 */
void eye(double I[81])
{
  int k;
  memset(&I[0], 0, 81U * sizeof(double));
  for (k = 0; k < 9; k++) {
    I[k + 9 * k] = 1.0;
  }
}

/*
 * File trailer for eye.c
 *
 * [EOF]
 */
