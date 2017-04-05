/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: modelCreation.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

#ifndef MODELCREATION_H
#define MODELCREATION_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "modelCreation_types.h"

/* Function Declarations */
extern void modelCreation(const unsigned char Im1[775], const unsigned char Im2
  [775], const unsigned char Im3[775], const unsigned char Im4[775], const
  unsigned char Im5[775], const unsigned char Im6[775], const unsigned char Im7
  [775], const unsigned char Im8[775], const unsigned char Im9[775], double
  MPoids[6975], double verif[81], double *err, double *it);

#endif

/*
 * File trailer for modelCreation.h
 *
 * [EOF]
 */
