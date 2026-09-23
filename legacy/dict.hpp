#ifndef  DICTIONARY_H
#define  DICTIONARY_H

#include <iwindow.hpp>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const int myMAX = 150;

class Dictionary;

class Dictionary {

   streampos loc[myMAX];
   ifstream  dict;
   ifstream  ndx;
   char *Index[myMAX];
   int NX;
   char Buffer[50];

   protected:
      void initIndex();
      void setBuffer(char *str);

   public:
      Dictionary(char *, char *);
      void ToUpper(char *, char *);  // converts string to upper case

      int Lookup(char *);  // lookup word given and return a positive
                           //   'found' condition, or a negative
                           //   'not found'
      int prefix (char *str, char *buf);
      char *getBuffer();
};

#endif
