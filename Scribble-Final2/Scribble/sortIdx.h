/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "modelCreation_types.h"

/* Function Declarations */
extern void merge_block(int idx[1001], double x[1001], int offset, int n, int
  preSortLevel, int iwork[1001], double xwork[1001]);
extern void merge_pow2_block(int idx[1001], double x[1001], int offset);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
