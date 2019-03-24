/*****************************************************************************
* Program:  TIMER.CPP
* Purpose:  Handles the timer on the bottom of the game board
*****************************************************************************/
#include  "timer.hpp"                 

                      
/*****************************************************************************
* Function: TBogTimer
* Parms:    Pointers to parent windows, the game and sound objects
* Purpose:  Instantiate the timer object
* Returns:  Nothing
*****************************************************************************/
TBogTimer::TBogTimer(unsigned long WindowID, IWindow *Parent, 
                     TBogWindow* Game, Sound* pSound)
          : IProgressIndicator(5001, Parent, Parent, IRectangle(), 101, 4, 
              IProgressIndicator::horizontal | IProgressIndicator::alignBottom | IProgressIndicator::homeLeft
              | IProgressIndicator::primaryScale1 | IProgressIndicator::snapToTickMark
              | IProgressIndicator::ribbonStrip | IWindow::visible)
{
   IFont myfont;

   game = Game;
   psound = pSound;

   //  Set the size of the progress indicator shaft and enable owner draw
   setShaftBreadth(10);
   enableDrawItem();

   setTickLength(0,10);
   setTickText(0, IString(0));

  //  Set the length and text for the slider's ticks.
  for ( int i=1; i<101; i+=1) 
  {
       if((i % 10) == 0)  
       {
          setTickLength(i,10);
          setTickLength(i-5,5);
          setTickText(i, IString(i));
       }
       else
          setTickLength(i,2);
   }

//  Get the pixel offset for pixel 0 to use as a base.
   IPoint base(tickPosition(0));

//Set the font for the control
   myfont.setName("Helvetica")
         .setPointSize(8);

   setFont((myfont));

//Set the colors
   setForegroundColor(IColor::black);
   setBackgroundColor(IColor::darkGray);

  IEditHandler::handleEventsFor(this);
}

/*****************************************************************************
* Function: ~TBogTimer
* Parms:    none
* Purpose:  destructor
* Returns:  Nothing
*****************************************************************************/
TBogTimer::~TBogTimer()
{
}

/*****************************************************************************
* Function: TimerHandler
* Parms:    none
* Purpose:  On every click of the timer,  this gets fired.  Move the 
*           progress indicator and maybe play some sound.
* Returns:  Nothing
*****************************************************************************/
void TBogTimer::TimerHandler()
{
   unsigned long ulOffset;
  
// Play the tick sound
   if(game->GetSoundFlag())
      DosBeep(BEEPFREQ, BEEPDURATION);
   
   ulOffset = armTickOffset();
   if (ulOffset < 100)
      moveArmToTick(++ulOffset);
   else                                //game over
      game->gameOver();
}

/*****************************************************************************
* Function: startTimer
* Parms:    none
* Purpose:  Start the timer.  It is my understanding that the destruction
*           of this timer is automatic by the class library but I am not
*           sure.
* Returns:  Nothing
*****************************************************************************/
void TBogTimer::startTimer()
{
//Set the duration based on the settings in the game
   timerDuration = game->GetTickDuration();

//Start the timer
   start(new ITimerMemberFn0<TBogTimer>
                 (*this, TBogTimer::TimerHandler), timerDuration);
}

/*****************************************************************************
* Function: stopTimer
* Parms:    none
* Purpose:  Stop the timer.  It is my understanding that the destruction
*           of this timer is automatic by the class library but I am not
*           sure.
* Returns:  Nothing
*****************************************************************************/
void TBogTimer::stopTimer()
{
    stop();  // class library function
}


/*****************************************************************************
* Function: resetTimer
* Parms:    none
* Purpose:  Bring the progress indicator back to its starting state
*           and stop the timer
* Returns:  Nothing
*****************************************************************************/
void TBogTimer::resetTimer()
{
//Stop the timer
   stopTimer();
   
// Set the arm back to zero
   moveArmToTick(0);
}


/*****************************************************************************
* Function: edit
* Parms:    none
* Purpose:  defined as a virtual function in the class lib so I must
*           declare it here.
* Returns:  Nothing
*****************************************************************************/
Boolean TBogTimer::edit ( IControlEvent& event )
{
   return true;
}