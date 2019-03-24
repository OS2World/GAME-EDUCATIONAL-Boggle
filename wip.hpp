#ifndef  BOGWIP_H
#define  BOGWIP_H

#include  "bogwin.hpp"
#include  <ientryfd.hpp>
#include  "dict.hpp"

//
//  Boggle WIP class
//

const BOOL LOOKUP =   1;
const BOOL NOLOOKUP = 0;

class TBogWIP;

class TBogWIP : public IEntryField
{
   private:
     char sWIPString[WORDLENGTH]; 
     Dictionary *WordChk;

  public :

     TBogWIP (unsigned long id, IWindow* parent);
     ~TBogWIP();

     void addLetter(char *sLetter);
     int checkWord(char *word) { return (WordChk->Lookup(word)); }
     void resetString();
     void upString(char *, char *);
     char *getWIPString() {return sWIPString;}
} ;

#endif

