/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[9]
 * Return Type  : double
 */
double b_sum(const double x[9])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 8; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const double x[81]
 *                double y[9]
 * Return Type  : void
 */
void sum(const double x[81], double y[9])
{
  int i;
  int xoffset;
  double s;
  int k;
  for (i = 0; i < 9; i++) {
    xoffset = i * 9;
    s = x[xoffset];
    for (k = 0; k < 8; k++) {
      s += x[(xoffset + k) + 1];
    }

    y[i] = s;
  }
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
