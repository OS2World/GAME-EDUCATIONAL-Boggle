#ifndef  BOGBOARD_H
#define  BOGBOARD_H
 
class TBogBoard;     //forward declare the class

#include  "bogwin.hpp"
#include  "square.hpp"
#include  "random.hpp"
#include  "dice.hpp"
#include  "wlist.hpp"
#include  "score.hpp"
#include  "dict.hpp"
#include  "sound.hpp"


class TBogBoard : public ICanvas, public ICommandHandler,
                  public IPaintHandler, public IMouseClickHandler
{
   private:
//      TBogWindow    *PBWindow;
   ICanvas       *pboard;
   int NX, stack[20], chflag[20];

   TBogWIP       *pbwip;
   TBogWordList  *pblist;
   TBogSquare    *PBSquare[16];
   LastSquare    *PBLastSquare;
   Dice          *Cubes[16];
   Random        rLetter;
   char          fndall_str[17];
   char          *Index[MAX];
   streampos     loc[MAX];
   ifstream      ndx;
   ifstream      dict;
   Dictionary    *brd_words;

   protected:
   /* -------------------------------------------------------- */
   /* declare the event handlers. These event handlers are all */
   /* pure virtual functions in their respective base classes  */
   /* -------------------------------------------------------- */
   virtual Boolean command(ICommandEvent&);
   virtual Boolean paintWindow(IPaintEvent &);
   virtual Boolean mouseClicked(IMouseClickEvent &);
   void Search(char *, int);
        
   public :
      TBogBoard (unsigned long id, IWindow* parentAndOwner, 
                  TBogWindow* PBWindow, TBogWIP* PBWIP,
                  TBogWordList* PBList, TBogScore* PBScore,
                  Sound* pSound);
      ~TBogBoard ();
      ICanvas *CanvasPointer();
      void InitBoard ();
      void ClearBoard ();
      void FindAll();
} ;
#endif


