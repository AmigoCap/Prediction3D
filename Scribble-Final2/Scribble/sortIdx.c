/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "sortIdx.h"

/* Function Declarations */
static void merge(int idx[1001], double x[1001], int offset, int np, int nq, int
                  iwork[1001], double xwork[1001]);

/* Function Definitions */

/*
 * Arguments    : int idx[1001]
 *                double x[1001]
 *                int offset
 *                int np
 *                int nq
 *                int iwork[1001]
 *                double xwork[1001]
 * Return Type  : void
 */
static void merge(int idx[1001], double x[1001], int offset, int np, int nq, int
                  iwork[1001], double xwork[1001])
{
  int n;
  int qend;
  int p;
  int iout;
  int exitg1;
  if ((np == 0) || (nq == 0)) {
  } else {
    n = np + nq;
    for (qend = 0; qend + 1 <= n; qend++) {
      iwork[qend] = idx[offset + qend];
      xwork[qend] = x[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[n]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = iout - p;
          while (p + 1 <= np) {
            idx[(n + p) + 1] = iwork[p];
            x[(n + p) + 1] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : int idx[1001]
 *                double x[1001]
 *                int offset
 *                int n
 *                int preSortLevel
 *                int iwork[1001]
 *                double xwork[1001]
 * Return Type  : void
 */
void merge_block(int idx[1001], double x[1001], int offset, int n, int
                 preSortLevel, int iwork[1001], double xwork[1001])
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : int idx[1001]
 *                double x[1001]
 *                int offset
 * Return Type  : void
 */
void merge_pow2_block(int idx[1001], double x[1001], int offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int q;
  int p;
  int iwork[256];
  double xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 1; k <= nPairs; k++) {
      blockOffset = (offset + (k - 1) * bLen2) - 1;
      for (q = 1; q <= bLen2; q++) {
        iwork[q - 1] = idx[blockOffset + q];
        xwork[q - 1] = x[blockOffset + q];
      }

      p = 0;
      q = bLen;
      do {
        exitg1 = 0;
        blockOffset++;
        if (xwork[p] >= xwork[q]) {
          idx[blockOffset] = iwork[p];
          x[blockOffset] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[blockOffset] = iwork[q];
          x[blockOffset] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            q = blockOffset - p;
            while (p + 1 <= bLen) {
              idx[(q + p) + 1] = iwork[p];
              x[(q + p) + 1] = xwork[p];
              p++;
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
