//**  bogwin.h  *********************************************************
//
//  Boggle Window class
//
#ifndef  BOGWIN_H
#define  BOGWIN_H

class TBogWindow;          //forward declare this class

#include  "common.hpp"
#include  <iframe.hpp>
#include  <ipainhdr.hpp>         /* IPaintHandler               */
#include  <ipainevt.hpp>         /* IPaintEvent                 */
#include  <imenubar.hpp>         /* IMenu Stuff                 */
#include  <icmdhdr.hpp>          /* ICommandHandler             */
#include  <imchdr.hpp>           /* Mouse commands              */
#include  <imoushdr.hpp>
#include  <imousevt.hpp>
#include  <icanvas.hpp>          /* Canvas class stuff          */
#include  <imcelcv.hpp>          /* Multicell Canvas class      */
#include  <iaccel.hpp>           /* Menu accelerator stuff      */
#include  <ipushbut.hpp>         /* push button stuff           */

#include <ihelp.hpp>
#include <ihelphdr.hpp>

#include  "sound.hpp"
#include  "board.hpp"
#include  "menu.hpp"
#include  "square.hpp"
#include  "wlist.hpp"
#include  "timer.hpp"
#include  "wip.hpp"
  
class TBogWindow : public IFrameWindow, public ICommandHandler,
                   public IPaintHandler, public IMouseClickHandler
{
   private:
     IHelpWindow                         help;
     IHelpHandler                        helpHandler;

     IMenuBar          menuBar;
     IMultiCellCanvas  Client;
     IStaticText       gameTitle;
     IFont             myfont;
     IColor            color;
     TBogBoard         *pboard;
     TBogWordList      *plist;
     TBogTimer         *ptimer;
     TBogWIP           *pwip;
     TBogScore         *pscore;
     Sound             *psound;

     IStaticText       st_wip;
     IStaticText       st_list;
     IStaticText       st_timer;
     IStaticText       st_score;

     Boolean     GameOn;
     long        TickDuration;
     Boolean     bSound;

   protected:
    /* -------------------------------------------------------- */
    /* declare the event handlers. These event handlers are all */
    /* pure virtual functions in their respective base classes  */
    /* -------------------------------------------------------- */
    virtual Boolean command(ICommandEvent&);
    virtual Boolean paintWindow(IPaintEvent &);
    virtual Boolean mouseClicked(IMouseClickEvent &);
    void settings();
    void aboutBox();
    void resumeGame();
    void pauseGame();
    void resetGame(ICommandEvent& event);


   public :
     TBogWindow (const char *title, unsigned long id);
     ~TBogWindow();
     Boolean isGameOn() {return (GameOn); }
     void gameOver();
     void SetTickDuration(long time) {TickDuration = time; }
     long GetTickDuration() {return TickDuration; }

     void SetSoundFlag(Boolean flag) {bSound = flag; }
     Boolean GetSoundFlag() {return bSound; }
} ;
#endif
