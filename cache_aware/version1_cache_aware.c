#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "common.c"
#include "version1_cache_aware.h"
//min of two values

// calculate C = AxB
/**
 * @brief 
 *this version only simply uses the for loops(it also uses a min function)
 * @param A 
 * @param B
 * @param C
 * @param L1Height
 * @param L2Height
 * @param L3Height
 */
void version1_cache_aware_matmul(float **A, float **B, float **C, int L1Height, int L2Height, int L3Height) {
  float sum;
  int L1BlockSize = (int)(L1Height /3);
  int L2BlockSize = (int)(L2Height /3);
  int L3BlockSize = (int)(L3Height /3);
  int temp; 

  for(int iiii=0;iiii<N;iiii+= L3BlockSize){
      for(int jjjj=0;jjjj<N;jjjj+= L3BlockSize){
          for(int kkkk=0;kkkk<N;kkkk+= L3BlockSize){
              for(int iii = iiii; iii<((iiii+L3BlockSize)>N?N:(iiii+L3BlockSize)); iii+=L2BlockSize){
                  for(int jjj = jjjj; jjj<((jjjj+L3BlockSize)>N?N:(jjjj+L3BlockSize)); jjj+=L2BlockSize){
                      for(int kkk = kkkk; kkk<((kkkk+L3BlockSize)>N?N:(kkkk+L3BlockSize)); kkk+=L2BlockSize){
                          for(int ii = iii; ii<((iii+L2BlockSize)>min((iiii + L3BlockSize), N)?min((iiii + L3BlockSize), N):(iii+L2BlockSize)); ii+=L1BlockSize){
                              for(int jj = jjj; jj<((jjj+L2BlockSize)>min((jjjj + L3BlockSize), N)?min((jjjj + L3BlockSize), N):(jjj+L2BlockSize)); jj+=L1BlockSize){
                                  for(int kk = kkk; kk<((kkk+L2BlockSize)>min((kkkk + L3BlockSize), N)?min((kkkk + L3BlockSize), N):(kkk+L2BlockSize)); kk+=L1BlockSize){
                                      for(int i = ii; i<((ii+L1BlockSize)> min(min(iii + L2BlockSize, N),iiii + L3BlockSize)?min(min((iii + L2BlockSize), N), iiii + L3BlockSize):(ii+L1BlockSize)); i++){
                                          for(int j = jj; j<((jj+L1BlockSize)>min(min(jjj + L2BlockSize, N), jjjj + L3BlockSize)?min(min((jjj + L2BlockSize), N), jjjj + L3BlockSize):(jj+L1BlockSize)); j++){
                                              for(int k = kk; k<((kk+L1BlockSize)>min(min(kkk + L2BlockSize, N), kkkk + L3BlockSize)?min(min((kkk + L2BlockSize), N), kkkk + L3BlockSize):(kk+L1BlockSize)); k++){
                                                  C[i][j] += A[i][k]*B[k][j];
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
}  
  
