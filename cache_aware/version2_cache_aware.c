#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "config.h"
#include "common.h"
#include "version2_cache_aware.h"
//this function uses a more clean version of for loops by taking advantage of the minOf function
// calculate C = AxB
void version2_cache_aware_matmul(float **A, float **B, float **C, int L1Height, int L2Height, int L3Height) {
  float sum;
  int L1BlockSize = (int)(L1Height /3);
  int L2BlockSize = (int)(L2Height /3);
  int L3BlockSize = (int)(L3Height /3);
  int temp; 
  for(int iiii=0;iiii<N;iiii+= L3BlockSize){
      for(int jjjj=0;jjjj<N;jjjj+= L3BlockSize){
          for(int kkkk=0;kkkk<N;kkkk+= L3BlockSize){
              for(int iii = iiii; iii < minOf(2, iiii+L3BlockSize, N); iii+=L2BlockSize){
                  for(int jjj = jjjj; jjj <minOf(2, jjjj+L3BlockSize,N); jjj+=L2BlockSize){
                      for(int kkk = kkkk; kkk< minOf(2, kkkk+L3BlockSize,N); kkk+=L2BlockSize){
                          //printf("**********done with L2 block\n"); 
                          for(int ii = iii; ii < minOf(3, iii+L2BlockSize, iiii + L3BlockSize, N); ii+=L1BlockSize){
                              for(int jj = jjj; jj < minOf(3, jjj+L2BlockSize, jjjj + L3BlockSize, N); jj+=L1BlockSize){
                              for(int kk = kkk; kk < minOf(3, kkk+L2BlockSize, kkkk + L3BlockSize, N); kk+=L1BlockSize){
                           //           printf("---------done with L1 block\n"); 
                                      for(int i = ii; i < minOf(4, ii+L1BlockSize, iii + L2BlockSize, N,iiii + L3BlockSize); i++){
                                          for(int j = jj; j < minOf(4, jj+L1BlockSize, jjj + L2BlockSize, N,jjjj + L3BlockSize); j++){
                                              for(int k = kk; k < minOf(4, kk+L1BlockSize, kkk + L2BlockSize, N,kkkk + L3BlockSize); k++){
                                                  C[i][j] += A[i][k]*B[k][j];
                                              }
                                              //C[i][j] += temp;
                                          }
                                      } 
                                  }
                              } 
                          }     
                      }
                  }
              }

          }     
      }
  }
} 

