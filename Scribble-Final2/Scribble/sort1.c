/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "sort1.h"
#include "sortIdx.h"

/* Function Declarations */
static void b_sort(double x[1001], int idx[1001]);

/* Function Definitions */

/*
 * Arguments    : double x[1001]
 *                int idx[1001]
 * Return Type  : void
 */
static void b_sort(double x[1001], int idx[1001])
{
  int i;
  double xwork[1001];
  double x4[4];
  int nNaNs;
  short idx4[4];
  int ib;
  int k;
  signed char perm[4];
  int iwork[1001];
  int i2;
  int i3;
  int i4;
  memset(&idx[0], 0, 1001U * sizeof(int));
  for (i = 0; i < 4; i++) {
    x4[i] = 0.0;
    idx4[i] = 0;
  }

  memset(&xwork[0], 0, 1001U * sizeof(double));
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 1001; k++) {
    if (rtIsNaN(x[k])) {
      idx[1000 - nNaNs] = k + 1;
      xwork[1000 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (short)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        i = k - nNaNs;
        if (x4[0] >= x4[1]) {
          ib = 1;
          i2 = 2;
        } else {
          ib = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[ib - 1] >= x4[i3 - 1]) {
          if (x4[i2 - 1] >= x4[i3 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else if (x4[ib - 1] >= x4[i4 - 1]) {
          if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)ib;
          perm[3] = (signed char)i2;
        }

        idx[i - 3] = idx4[perm[0] - 1];
        idx[i - 2] = idx4[perm[1] - 1];
        idx[i - 1] = idx4[perm[2] - 1];
        idx[i] = idx4[perm[3] - 1];
        x[i - 3] = x4[perm[0] - 1];
        x[i - 2] = x4[perm[1] - 1];
        x[i - 1] = x4[perm[2] - 1];
        x[i] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (i = 0; i < 4; i++) {
      perm[i] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 1001; k - 1000 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 1001] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 1001] - 1];
    }
  }

  i = nNaNs >> 1;
  for (k = 1001; k - 1000 <= i; k++) {
    ib = idx[k - nNaNs];
    idx[k - nNaNs] = idx[2001 - k];
    idx[2001 - k] = ib;
    x[k - nNaNs] = xwork[2001 - k];
    x[2001 - k] = xwork[k - nNaNs];
  }

  if ((nNaNs & 1) != 0) {
    x[(i - nNaNs) + 1001] = xwork[(i - nNaNs) + 1001];
  }

  memset(&iwork[0], 0, 1001U * sizeof(int));
  i = 2;
  if (1001 - nNaNs > 1) {
    ib = (1001 - nNaNs) >> 8;
    if (ib > 0) {
      for (i = 1; i <= ib; i++) {
        merge_pow2_block(idx, x, (i - 1) << 8);
      }

      i = ib << 8;
      ib = 1001 - (nNaNs + i);
      if (ib > 0) {
        merge_block(idx, x, i, ib, 2, iwork, xwork);
      }

      i = 8;
    }

    merge_block(idx, x, 0, 1001 - nNaNs, i, iwork, xwork);
  }

  if ((nNaNs > 0) && (1001 - nNaNs > 0)) {
    for (k = 1001; k - 1000 <= nNaNs; k++) {
      xwork[k - 1001] = x[k - nNaNs];
      iwork[k - 1001] = idx[k - nNaNs];
    }

    for (k = 1000 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
      idx[nNaNs + k] = idx[k];
    }

    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = xwork[k];
      idx[k] = iwork[k];
    }
  }
}

/*
 * Arguments    : double x[1001]
 *                int idx[1001]
 * Return Type  : void
 */
void sort(double x[1001], int idx[1001])
{
  b_sort(x, idx);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
