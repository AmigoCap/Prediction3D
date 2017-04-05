/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_modelCreation_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_modelCreation_api.h"
#include "_coder_modelCreation_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "modelCreation",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[775];
static const mxArray *b_emlrt_marshallOut(const real_T u[81]);
static uint8_T (*c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId))[775];
static const mxArray *c_emlrt_marshallOut(const real_T u);
static uint8_T (*emlrt_marshallIn(const mxArray *Im1, const char_T *identifier))
  [775];
static const mxArray *emlrt_marshallOut(const real_T u[6975]);

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T (*)[775]
 */
static uint8_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[775]
{
  uint8_T (*y)[775];
  y = c_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[81]
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const real_T u[81])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 0, 0 };

  static const int32_T iv3[2] = { 9, 9 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv3, 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T (*)[775]
 */
static uint8_T (*c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId))[775]
{
  uint8_T (*ret)[775];
  static const int32_T dims[2] = { 31, 25 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "uint8", false, 2U,
    dims);
  ret = (uint8_T (*)[775])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const mxArray *Im1
 *                const char_T *identifier
 * Return Type  : uint8_T (*)[775]
 */
static uint8_T (*emlrt_marshallIn(const mxArray *Im1, const char_T *identifier))
  [775]
{
  uint8_T (*y)[775];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(Im1), &thisId);
  emlrtDestroyArray(&Im1);
  return y;
}
/*
 * Arguments    : const real_T u[6975]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u[6975])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 9, 775 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 2);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[9]
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void modelCreation_api(const mxArray * const prhs[9], const mxArray *plhs[4])
{
  real_T (*MPoids)[6975];
  real_T (*verif)[81];
  uint8_T (*Im1)[775];
  uint8_T (*Im2)[775];
  uint8_T (*Im3)[775];
  uint8_T (*Im4)[775];
  uint8_T (*Im5)[775];
  uint8_T (*Im6)[775];
  uint8_T (*Im7)[775];
  uint8_T (*Im8)[775];
  uint8_T (*Im9)[775];
  real_T err;
  real_T it;
  MPoids = (real_T (*)[6975])mxMalloc(sizeof(real_T [6975]));
  verif = (real_T (*)[81])mxMalloc(sizeof(real_T [81]));

  /* Marshall function inputs */
  Im1 = emlrt_marshallIn(emlrtAlias(prhs[0]), "Im1");
  Im2 = emlrt_marshallIn(emlrtAlias(prhs[1]), "Im2");
  Im3 = emlrt_marshallIn(emlrtAlias(prhs[2]), "Im3");
  Im4 = emlrt_marshallIn(emlrtAlias(prhs[3]), "Im4");
  Im5 = emlrt_marshallIn(emlrtAlias(prhs[4]), "Im5");
  Im6 = emlrt_marshallIn(emlrtAlias(prhs[5]), "Im6");
  Im7 = emlrt_marshallIn(emlrtAlias(prhs[6]), "Im7");
  Im8 = emlrt_marshallIn(emlrtAlias(prhs[7]), "Im8");
  Im9 = emlrt_marshallIn(emlrtAlias(prhs[8]), "Im9");

  /* Invoke the target function */
  modelCreation(*Im1, *Im2, *Im3, *Im4, *Im5, *Im6, *Im7, *Im8, *Im9, *MPoids,
                *verif, &err, &it);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*MPoids);
  plhs[1] = b_emlrt_marshallOut(*verif);
  plhs[2] = c_emlrt_marshallOut(err);
  plhs[3] = c_emlrt_marshallOut(it);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void modelCreation_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  modelCreation_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void modelCreation_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void modelCreation_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_modelCreation_api.c
 *
 * [EOF]
 */
