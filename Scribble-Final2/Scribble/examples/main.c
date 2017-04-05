/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "main.h"
#include "modelCreation_terminate.h"
#include "modelCreation_initialize.h"

/* Function Declarations */
static void argInit_31x25_uint8_T(unsigned char result[775]);
static unsigned char argInit_uint8_T(void);
static void main_modelCreation(void);

/* Function Definitions */

/*
 * Arguments    : unsigned char result[775]
 * Return Type  : void
 */
static void argInit_31x25_uint8_T(unsigned char result[775])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 31; idx0++) {
    for (idx1 = 0; idx1 < 25; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 31 * idx1] = argInit_uint8_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_modelCreation(void)
{
  unsigned char uv0[775];
  unsigned char uv1[775];
  unsigned char uv2[775];
  unsigned char uv3[775];
  unsigned char uv4[775];
  unsigned char uv5[775];
  unsigned char uv6[775];
  unsigned char uv7[775];
  unsigned char uv8[775];
  double MPoids[6975];
  double verif[81];
  double err;
  double it;

  /* Initialize function 'modelCreation' input arguments. */
  /* Initialize function input argument 'Im1'. */
  /* Initialize function input argument 'Im2'. */
  /* Initialize function input argument 'Im3'. */
  /* Initialize function input argument 'Im4'. */
  /* Initialize function input argument 'Im5'. */
  /* Initialize function input argument 'Im6'. */
  /* Initialize function input argument 'Im7'. */
  /* Initialize function input argument 'Im8'. */
  /* Initialize function input argument 'Im9'. */
  /* Call the entry-point 'modelCreation'. */
  argInit_31x25_uint8_T(uv0);
  argInit_31x25_uint8_T(uv1);
  argInit_31x25_uint8_T(uv2);
  argInit_31x25_uint8_T(uv3);
  argInit_31x25_uint8_T(uv4);
  argInit_31x25_uint8_T(uv5);
  argInit_31x25_uint8_T(uv6);
  argInit_31x25_uint8_T(uv7);
  argInit_31x25_uint8_T(uv8);
  modelCreation(uv0, uv1, uv2, uv3, uv4, uv5, uv6, uv7, uv8, MPoids, verif, &err,
                &it);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  modelCreation_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_modelCreation();

  /* Terminate the application.
     You do not need to do this more than one time. */
  modelCreation_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
