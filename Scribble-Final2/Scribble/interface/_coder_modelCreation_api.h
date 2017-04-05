/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_modelCreation_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

#ifndef _CODER_MODELCREATION_API_H
#define _CODER_MODELCREATION_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_modelCreation_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void modelCreation(uint8_T Im1[775], uint8_T Im2[775], uint8_T Im3[775],
  uint8_T Im4[775], uint8_T Im5[775], uint8_T Im6[775], uint8_T Im7[775],
  uint8_T Im8[775], uint8_T Im9[775], real_T MPoids[6975], real_T verif[81],
  real_T *err, real_T *it);
extern void modelCreation_api(const mxArray * const prhs[9], const mxArray *
  plhs[4]);
extern void modelCreation_atexit(void);
extern void modelCreation_initialize(void);
extern void modelCreation_terminate(void);
extern void modelCreation_xil_terminate(void);

#endif

/*
 * File trailer for _coder_modelCreation_api.h
 *
 * [EOF]
 */
