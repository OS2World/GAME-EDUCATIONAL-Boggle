#ifndef  BOGLIST_H
#define  BOGLIST_H
 
#include  "bogwin.hpp"

//
//  Boggle WList class
//

class TBogWordList;

class TBogWordList : public IListBox
{
   private:
     char sWIPString[WORDLENGTH]; 

   public :
      TBogWordList (unsigned long id, IWindow* parent);
      void selectWord(int index);
      void addString(char *sString);
      void clearList();
      void selectAllWords();
} ;

#endif

