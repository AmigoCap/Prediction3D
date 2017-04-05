/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: modelCreation.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 26-Mar-2017 18:23:01
 */

/* Include Files */
#include <stdio.h>
#include "rt_nonfinite.h"
#include "modelCreation.h"
#include "sum.h"
#include "power.h"
#include "eye.h"
#include "fseuil.h"
#include "rand.h"
#include "ceil.h"
#include "sort1.h"

/* Function Definitions */

/*
 * Donnees
 * Arguments    : const unsigned char Im1[775]
 *                const unsigned char Im2[775]
 *                const unsigned char Im3[775]
 *                const unsigned char Im4[775]
 *                const unsigned char Im5[775]
 *                const unsigned char Im6[775]
 *                const unsigned char Im7[775]
 *                const unsigned char Im8[775]
 *                const unsigned char Im9[775]
 *                double MPoids[6975]
 *                double verif[81]
 *                double *err
 *                double *it
 * Return Type  : void
 */
void modelCreation(const unsigned char Im1[775], const unsigned char Im2[775],
                   const unsigned char Im3[775], const unsigned char Im4[775],
                   const unsigned char Im5[775], const unsigned char Im6[775],
                   const unsigned char Im7[775], const unsigned char Im8[775],
                   const unsigned char Im9[775], double MPoids[6975], double
                   verif[81], double *err, double *it)
{
  int i0;
  int i1;
  signed char M[6975];
  signed char b_Im1[775];
  signed char b_Im2[775];
  signed char b_Im3[775];
  signed char b_Im4[775];
  signed char b_Im5[775];
  signed char b_Im6[775];
  signed char b_Im7[775];
  signed char b_Im8[775];
  signed char b_Im9[775];
  static double Pop[6981975];
  double MeilleurErr;
  int i;
  double Merr[1000];
  int j;
  double b_err[1001];
  int iidx[1001];
  double Ident[81];
  static double Ms[81081];
  static double PopTemp[6981975];
  int k;
  double b_Ms[81];
  double dv0[81];
  double dv1[9];
  double elemPM[300];
  int J[300];
  static double b[1395000];
  double b_Pop[6975];

  /*  UInt8 to binary */
  /*  On les transforme en vecteur */
  /*  On les met ensemble dans une matrice */
  for (i0 = 0; i0 < 25; i0++) {
    for (i1 = 0; i1 < 31; i1++) {
      b_Im1[i1 + 31 * i0] = (signed char)(Im1[i1 + 31 * i0] >= 128);
      b_Im2[i1 + 31 * i0] = (signed char)(Im2[i1 + 31 * i0] >= 128);
      b_Im3[i1 + 31 * i0] = (signed char)(Im3[i1 + 31 * i0] >= 128);
      b_Im4[i1 + 31 * i0] = (signed char)(Im4[i1 + 31 * i0] >= 128);
      b_Im5[i1 + 31 * i0] = (signed char)(Im5[i1 + 31 * i0] >= 128);
      b_Im6[i1 + 31 * i0] = (signed char)(Im6[i1 + 31 * i0] >= 128);
      b_Im7[i1 + 31 * i0] = (signed char)(Im7[i1 + 31 * i0] >= 128);
      b_Im8[i1 + 31 * i0] = (signed char)(Im8[i1 + 31 * i0] >= 128);
      b_Im9[i1 + 31 * i0] = (signed char)(Im9[i1 + 31 * i0] >= 128);
    }
  }

  for (i0 = 0; i0 < 775; i0++) {
    M[i0] = b_Im1[i0];
    M[775 + i0] = b_Im2[i0];
    M[1550 + i0] = b_Im3[i0];
    M[2325 + i0] = b_Im4[i0];
    M[3100 + i0] = b_Im5[i0];
    M[3875 + i0] = b_Im6[i0];
    M[4650 + i0] = b_Im7[i0];
    M[5425 + i0] = b_Im8[i0];
    M[6200 + i0] = b_Im9[i0];
  }

  /*  Parametres */
  /*  Tailles de la matrice M */
  /*  Nombre maximal d'iterations */
  /*  Precision attendue */
  /*  Taille de la population */
  /*  Parametre pour les valeurs limites initiales dans la matrice de poids. */
  /*  [-Lim;Lim] */
  /*  Parametre pour la fonction de seuil */
  /*  Parametre pour l'intervalle de la petite mutation [x-e;x+e] */
  /*  Proportion de mutations et croisements */
  /*  Fonction de seuil utilisee */
  /*  Algorithme */
  /*  Creation des variables */
  /*  Population de matrices de poids */
  b_rand(Pop);
  for (i0 = 0; i0 < 6981975; i0++) {
    Pop[i0] = -10.0 + 20.0 * Pop[i0];
  }

  /*  Initialisation de la matrice resultat de l'application de la fonction  */
  /*  de seuil */
  /*  Initialisation du vecteur d'enregistrement des erreurs par iteration */
  /*  Initialisation de la premier valeur de meilleur erreur */
  /*  Comme on cherche la minimisation, on l'affecte la valeur infini  */
  MeilleurErr = 100.0;

  /*  Initialisation du vecteur des meilleurs erreurs de chaque iteration  */
  for (i = 0; i < 1000; i++) {
    Merr[i] = 100.0;
  }

  /*  Matrice identite pour le calcul de l'erreur */
  /*  Boucle de l'algorithme */
  j = 1;
  while ((MeilleurErr > 0.001) && (j < 1000)) {
      
      if (j % 50 == 0) {printf("it %d\n", j);}
      
    /*     %% Recherche du meilleur */
    /*  Application de la fonction de seuil aux matrices de poids dans la */
    /*  population */
    for (i = 0; i < 1001; i++) {
      for (i0 = 0; i0 < 9; i0++) {
        for (i1 = 0; i1 < 9; i1++) {
          Ident[i0 + 9 * i1] = 0.0;
          for (k = 0; k < 775; k++) {
            Ident[i0 + 9 * i1] += Pop[(i0 + 9 * k) + 6975 * i] * (double)M[k +
              775 * i1];
          }
        }
      }

      fseuil(Ident, 1.0, *(double (*)[81])&Ms[81 * i]);
      eye(Ident);
      for (i0 = 0; i0 < 9; i0++) {
        for (i1 = 0; i1 < 9; i1++) {
          b_Ms[i1 + 9 * i0] = Ms[(i1 + 9 * i0) + 81 * i] - Ident[i1 + 9 * i0];
        }
      }

      power(b_Ms, dv0);
      sum(dv0, dv1);
      b_err[i] = b_sum(dv1);
    }

    /*  Tri descendant des erreurs trouves et aussi leurs respectives */
    /*  matrices de poids */
    sort(b_err, iidx);
    for (i = 0; i < 1001; i++) {
      for (i0 = 0; i0 < 775; i0++) {
        for (i1 = 0; i1 < 9; i1++) {
          PopTemp[(i1 + 9 * i0) + 6975 * i] = Pop[(i1 + 9 * i0) + 6975 * (iidx[i]
            - 1)];
        }
      }
    }

    memcpy(&Pop[0], &PopTemp[0], 6981975U * sizeof(double));
    Merr[j - 1] = b_err[1000];
    MeilleurErr = b_err[1000];
    if (b_err[1000] > 0.001) {
      /*         %% Mutations */
      /*  Petite mutation */
      /*  On applique les mutations et croisements aux autres elements */
      /*  de la population */
      /*  Nombre d'elements de la population a subir les petites mutations */
      /*  Choix aleatoire des elements dans les matrices a subir les petites  */
      /*  mutations */
      /*  On applique les petites mutations au meilleur */
      c_rand(elemPM);
      for (i0 = 0; i0 < 300; i0++) {
        elemPM[i0] *= 6975.0;
      }

      b_ceil(elemPM);
      for (i = 0; i < 300; i++) {
        k = ((int)elemPM[i] - 1) / 9;
        J[i] = k + 1;
        elemPM[i] = (int)elemPM[i] - k * 9;
      }

      /*  Execution de la petite mutation */
      for (k = 0; k < 300; k++) {
        Pop[(((int)elemPM[k] + 9 * (J[k] - 1)) + 6975 * (999 - k)) - 1] = (Pop
          [((int)elemPM[k] + 9 * (J[k] - 1)) + 6974999] - 100.0) + 200.0 *
          d_rand();
      }

      /*  Grande mutation */
      /*  Nombre d'elements de la population a subir les grandes mutations */
      e_rand(b);
      for (i0 = 0; i0 < 200; i0++) {
        for (i1 = 0; i1 < 775; i1++) {
          for (k = 0; k < 9; k++) {
            Pop[(k + 9 * i1) + 6975 * i0] = -10.0 + 20.0 * b[(k + 9 * i1) + 6975
              * i0];
          }
        }
      }

      /*  Croisements */
      /*  Nombre d'elements de la population a subir des croisements */
      /*  Execution des croisements */
      for (k = 0; k < 501; k++) {
        for (i0 = 0; i0 < 775; i0++) {
          for (i1 = 0; i1 < 9; i1++) {
            b_Pop[i1 + 9 * i0] = (Pop[(i1 + 9 * i0) + 6975 * (k + 199)] + Pop
                                  [6975000 + (i1 + 9 * i0)]) / 2.0;
          }
        }

        for (i0 = 0; i0 < 775; i0++) {
          memcpy(&Pop[(k * 6975 + i0 * 9) + 1388025], &b_Pop[i0 * 9], 9U *
                 sizeof(double));
        }
      }
    }

    /*  Incrementation */
    j++;
  }

  /*  Verification des iterations */
  *it = (double)j - 1.0;

  /*  Verification de l'erreur */
  *err = Merr[j - 2];

  /*  Verification */
  for (i0 = 0; i0 < 775; i0++) {
    memcpy(&MPoids[i0 * 9], &Pop[i0 * 9 + 6975000], 9U * sizeof(double));
  }

  for (i0 = 0; i0 < 9; i0++) {
    for (i1 = 0; i1 < 9; i1++) {
      Ident[i0 + 9 * i1] = 0.0;
      for (k = 0; k < 775; k++) {
        Ident[i0 + 9 * i1] += Pop[6975000 + (i0 + 9 * k)] * (double)M[k + 775 *
          i1];
      }
    }
  }

  fseuil(Ident, 1.0, verif);
}

/*
 * File trailer for modelCreation.c
 *
 * [EOF]
 */
