#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "naive.h"
#include "config.h"
#include "version1_cache_aware.h"
#include "version2_cache_aware.h"
#include "version3_cache_aware.h"

// define the matrix dimensions A is MxP, B is PxN, and C is MxN

// function to allocate a matrix on the heap
// creates an mXn matrix and returns the pointer.
//
// the matrices are in row-major order.
void create_matrix(float*** A, int m, int n) {
  float **T = 0;
  int i;

  T = (float**)malloc( m*sizeof(float*));
  for ( i=0; i<m; i++ ) {
     T[i] = (float*)malloc(n*sizeof(float));
  }
  *A = T;
}


void printMatrixMultiply(float**C) {
    for (int i=0; i<M; i++) {
        // for each row of C
        for (int j=0; j<N; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");    
    }
}

void initializeMatrix(float **A) {
    for (int i=0; i<M; i++) {
        // for each row of C
        for (int j=0; j<N; j++) {
            *(*(A + i) + j) = (rand() % 20); 
        }
    }
}
int matricesAreEqual(float **A, float** B) {
    for (int i=0; i<M; i++) {
        // for each row of C
        for (int j=0; j<N; j++) {
            if (*(*(A + i) + j) !=  *(*(B + i) + j)) {
                    return 0;
            }
        }
    }
    return 1;
}
void copyMatrix(float **input, float **output) {
    for (int i=0; i<M; i++) {
        // for each row of C
        for (int j=0; j<N; j++) {
            (*(*(output + i) + j) =  *(*(input + i) + j));
        }
    }
}

int main ( int argc, char *argv[] ){
  float** A;
  float** B;
  float** C;
  float** D;
  
  create_matrix(&A, M, P);
  create_matrix(&B, P, N);
  create_matrix(&C, M, N);
  create_matrix(&D, M, N);
  
  initializeMatrix(A);
  initializeMatrix(B);
  
  
  /* 
  if (strcmp(argv[1], "naive") == 0) {
      matmulNaive(A, B, C);
      printMatrixMultiply(C);
  }else if (strcmp(argv[1], "Aware") == 0) {
      matmulCacheAware(A, B, C);
      printMatrixMultiply(C);
  }else {
      matmulNaive(A, B, C);
      copyMatrix(C, D); 
      printMatrixMultiply(D);
      printf("done\n"); 
      create_matrix(&C, M, N);
      matmulCacheAware(A, B, C);
      printMatrixMultiply(C);
  }
 */ 

      naive_matmul(A, B, C);
      copyMatrix(C, D); 
      //printMatrixMultiply(D);
      create_matrix(&C, M, N);
      printf("which version do you want to verify: \n");
      char version[30]; 
      scanf("%s", version);
      if (strcmp(version, "version1") == 0 ){
          version1_cache_aware_matmul(A, B, C, 3, 8 , 12);
      } else if (strcmp(version, "version2") == 0 ){
          printf("now\n"); 
          version1_cache_aware_matmul(A, B, C, 3, 8 , 12);
      } else if (strcmp(version, "version3") == 0 ){
          version3_cache_aware_matmul(A, B, C, 3, 8 , 12);
      } 
      //printMatrixMultiply(C);
      //verify the correctnessof cacheAware
      printf("accoding to the results, naive and cache aware return the same results %d\n", matricesAreEqual(C, D)); 
  return (0);
}
