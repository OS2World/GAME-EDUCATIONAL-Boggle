#ifndef  RANDOM_H
#define  RANDOM_H
 
#include <time.h>
#include <stdlib.h>
#include <string.h>


//_CLASSDEF(Random)
class Random {
   int cube_array[16];

   public:
      void perm();
      int  getValue(int);        //return the value at the ith index of
};                               //   cube_array.



#endif

