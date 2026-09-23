#ifndef  TIMER_H
#define  TIMER_H
#define  ID_TIMER     200 

class TBogTimer;

#include "bogwin.hpp"
#include <islider.hpp>
#include <itimer.hpp>
#include <iedithdr.hpp>
      
#include  <stdio.h>                 

class TBogTimer;

class TBogTimer : public IProgressIndicator, public ITimer, public IEditHandler
{
   private:
     long          timerDuration;
     TBogWindow*   game;
     Sound*        psound;
                    
   protected:
      void TimerHandler();
      virtual Boolean edit(IControlEvent& event );

   public:
      void resetTimer();
      void startTimer();
      void stopTimer();
      TBogTimer(unsigned long WindowID, IWindow *Parent, 
                TBogWindow* Game, Sound* pSound);
      ~TBogTimer();
};        

#endif

