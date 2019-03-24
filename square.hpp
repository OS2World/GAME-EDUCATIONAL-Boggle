#ifndef  BOGSQUARE_H
#define  BOGSQUARE_H
 
#include  "bogwin.hpp"
#include  "lastsq.hpp"
#include  "wip.hpp"
#include  "wlist.hpp"
#include  "score.hpp"
#include  "sound.hpp"
#include  "ammvehdr.hpp"
#include  <ibmpctl.hpp>

class TBogSquare;

class TBogSquare : public IBitmapControl, public ICommandHandler, 
                   public IPaintHandler, public IMouseHandler,
                   public AMouseMoveHandler
{
 private:
   TBogWindow    *pbwindow; 
   TBogBoard     *pbboard;
   TBogWIP       *pbwip;
   LastSquare    *PBLastSquare;
   TBogWordList  *pblist;
   TBogScore     *pbscore; 
   Sound         *psound;

   IFont   myfont;
   char    Letter[3];
   Boolean HiLite;
   int     rowid, colid;
   IColor::Color selectedColor;
   IColor *normalColor;

  protected :
   
   virtual Boolean 
      paintWindow(IPaintEvent &event),
      mouseClicked(IMouseClickEvent &event),
      motion( IEvent &evt );

     void clearBoard();


  public :
   TBogSquare (unsigned long id,
               IWindow* parent,
               char* letter, 
               TBogWindow* PBWindow,
               TBogBoard* PBBoard,
               LastSquare* PBLastSquare,
               TBogWIP* PBWIP,
               TBogWordList* PBList,
               TBogScore* PBScore,
               Sound* pSound, 
               int row, int col,
               const IRectangle& initial= IRectangle());
   ~TBogSquare();

    void button1Down();
    void button1Up();
    void button2Down();
    void setSquareText(char *SquareLetter);
    void reset();
} ;
#endif

