#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "common.h"
#include "version3_cache_aware.h"

//this function uses while loops to add to the readability of the version1 and version2 (which utilize for loops)
// calculate C = AxB
void version3_cache_aware_matmul(float **A, float **B, float **C, int L1Height, int L2Height, int L3Height) {
  float sum;
  int L1BlockSize = (int)(L1Height /3);
  int L2BlockSize = (int)(L2Height /3);
  int L3BlockSize = (int)(L3Height /3);
  int temp; 

  int iiii =0;
  int jjjj =0;
  int kkkk =0;
  while(iiii < N) {
      int jjjj = 0;
      while(jjjj < N) {
          int kkkk = 0;
          while(kkkk < N) {
             int iiiUperBound = min((iiii+L3BlockSize), N);
             int jjjUperBound = min((jjjj+L3BlockSize), N);
             int kkkUperBound = min((kkkk+L3BlockSize), N);
             int iii = iiii;
             while (iii < iiiUperBound){
                 int jjj = jjjj;
                 while (jjj < jjjUperBound){
                     int kkk = kkkk;
                     while (kkk < kkkUperBound){
                         int iiUperBound =  min ((iii+L2BlockSize), min((iiii + L3BlockSize), N)) ;
                         int jjUperBound =  min ((jjj+L2BlockSize), min((jjjj + L3BlockSize), N)) ;
                         int kkUperBound =  min ((kkk+L2BlockSize), min((kkkk + L3BlockSize), N)) ;
                         int ii = iii;
                         while (ii < iiUperBound){
                             int jj = jjj;
                             while (jj < jjUperBound){
                                 int kk = kkk;
                                 while (kk < kkUperBound){
                                     int iUperBound =  min(min ((iii+L2BlockSize), min((iiii + L3BlockSize), N)), ii + L1BlockSize);
                                     int jUperBound =  min(min ((jjj+L2BlockSize), min((jjjj + L3BlockSize), N)), jj + L1BlockSize) ;
                                     int kUperBound =  min(min ((kkk+L2BlockSize), min((kkkk + L3BlockSize), N)), kk + L1BlockSize) ;
                                     int i = ii; 
                                     while (i < iUperBound){
                                         int j = jj; 
                                         while (j < jUperBound){
                                             int k = kk; 
                                             while (k < kUperBound){
                                                 C[i][j] += A[i][k]*B[k][j];
                                                 k++; 
                                             }
                                             j++; 
                                         }
                                         i++ ;
                                     }
                                     kk+= L1BlockSize;
                                 } 
                                 jj+= L1BlockSize;
                             }
                             ii+= L1BlockSize;
                         }
                         kkk+= L2BlockSize;
                     }
                     jjj+= L2BlockSize;
                 }
              iii+= L2BlockSize;
             }
              kkkk+= L3BlockSize;
          } 
          jjjj+= L3BlockSize;
      } 
      iiii+= L3BlockSize;
  }
}                              

