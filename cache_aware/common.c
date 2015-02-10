#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
int min(int a, int b) {
    if (a < b){
        return a;
    }else {
        return b;
    }
}

//min with unlimited number of arguments
int minOf(int count, ...)
{
   va_list list;
   int j = 0;
   int result = 0;
   va_start(list, count); 
   for(j=0; j<count; j++)
   {
       if (j == 0) {
           result = va_arg(list, int);
       }    else {
           result = min(result, va_arg(list, int));

       }
   }   
   va_end(list);
   return result;
}
