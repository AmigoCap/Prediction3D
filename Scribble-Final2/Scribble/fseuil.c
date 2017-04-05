/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fseuil.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "fseuil.h"

/* Function Definitions */

/*
 * Arguments    : const double Z[81]
 *                double f
 *                double Ms[81]
 * Return Type  : void
 */
void fseuil(const double Z[81], double f, double Ms[81])
{
  int k;
  if (f == 1.0) {
    for (k = 0; k < 81; k++) {
      Ms[k] = exp(0.01 * Z[k]) / (1.0 + exp(0.01 * Z[k]));
    }
  } else if (f == 2.0) {
    for (k = 0; k < 81; k++) {
      Ms[k] = (Z[k] > 0.0);
    }
  } else {
    for (k = 0; k < 81; k++) {
      Ms[k] = (double)(Z[k] > 0.01) + Z[k] / 0.01 * (double)((0.0 < Z[k]) &&
        (Z[k] < 0.01));
    }
  }
}

/*
 * File trailer for fseuil.c
 *
 * [EOF]
 */
