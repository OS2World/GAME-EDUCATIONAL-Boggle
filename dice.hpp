#ifndef  BOGDICE_H
#define  BOGDICE_H
 
#include  "common.hpp"

class Dice;

class Dice {
   char faces[7];

 public:
   Dice(const char *);
   char *Roll();         //return a face based on random # generator
};

#endif
