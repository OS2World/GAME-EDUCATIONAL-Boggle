#ifndef  EXCEPT_H
#define  EXCEPT_H
 
#include  "common.hpp"

class myExceptionHandler;

class myExceptionHandler : public IMessageBox
{
   private:

   public :
      myExceptionHandler  (IString* title,
                           IString* Message);
} ;

#endif

