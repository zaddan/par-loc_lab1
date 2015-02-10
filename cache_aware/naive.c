#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
// define the matrix dimensions A is MxP, B is PxN, and C is MxN
#include "config.h"
#include "naive.h"

void naive_matmul(float **A, float **B, float **C) {
  float sum;
  int   i;
  int   j;
  int   k;

  for (i=0; i<M; i++) {
    // for each row of C
    for (j=0; j<N; j++) {
      // for each column of C
      sum = 0.0f; // temporary value
      for (k=0; k<P; k++) {
        // dot product of row from A and column from B
        sum +=  A[i][k]*B[k][j];
      }
      C[i][j] = sum;
    }
  }
}
 
