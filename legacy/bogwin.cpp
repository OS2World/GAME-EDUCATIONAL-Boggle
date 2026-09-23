/*****************************************************************************
* Program:  BOGWIN.CPP
* Purpose:  The guts of the game.  This instantiates everything else.  This
*           can be considered the game object.
*****************************************************************************/
#include  "bogwin.hpp"
#include  "aoptions.hpp"
#include  "options.h"
#include  "about.h"
#include  "about.hpp"

/*****************************************************************************
* Function: TBogWindow
* Parms:    title and window ID
* Purpose:  Set up the game by instantiating all other objects
* Returns:  Nothing
*****************************************************************************/
TBogWindow::TBogWindow (const char *title, unsigned long id)
      :  IFrameWindow(title, id, 
                      IFrameWindow::defaultStyle() 
                       | IFrameWindow::minimizedIcon),
         help(IResourceId(HLP_BOGGLEAPP), this),
         menuBar(id, this), 
         Client(FID_CLIENT, this, this),
         gameTitle(0, &Client, &Client),
         myfont(&gameTitle),
         color(IColor::darkGray),
         st_wip(104, &Client, &Client),
         st_list(105, &Client, &Client),
         st_timer(106, &Client, &Client),
         st_score(107, &Client, &Client)
{
   /******************************************************************
   * Add the command handlers to this window
   ******************************************************************/
   addHandler((ICommandHandler *)this);
   addHandler((IPaintHandler *)this);
   addHandler((IMouseClickHandler *)this);

   // handle help events
   helpHandler.handleEventsFor(this);

   // set the library name and window title for the help window
   help.addLibraries("boggle.hlp")
       .setTitle(WND_MAINWIN)
       .associateWindow(this);
  
   /******************************************************************
   * We will set the range of the scroll bar to equal the number of
   * seconds that the timer will run.  The scroll bar will decrement
   * one position every second.  When there is no more time,  a
   * message box will pop up announcing Game Over.
   ******************************************************************/
   TickDuration = 1500;

   menuBar.setAutoDestroyWindow(false);
   GameOn = false;
   bSound = true;
                      
   /***********************************************
   * Attach a client area to the frame.
   ***********************************************/
   this->setClient(&Client);
   Client.setColor(color);

   /***************************************
   * Put the title on the client window
   ***************************************/
   unsigned long lineHeight = myfont.maxCharHeight();
   unsigned long alignmentHeight = (lineHeight*3)/2;
  
   myfont.setName("Times New Roman")
         .setPointSize(24)
         .setBold()
         .setItalic();
  
   gameTitle.setAlignment(IStaticText::topLeft)
            .setText("Boggle Game")
            .setFont((myfont));

   myfont.setName("Helv")
         .setPointSize(8)
         .setBold(false)
         .setItalic(false);

   /**************************************
   * Try for some sound!!
   **************************************/
   try
   {
       psound = new Sound();
   }
   catch ( const IString &msg )
   {
      IMessageBox msgBox(this);
      msgBox.show(msg,
                  IMessageBox::okButton  |
                  IMessageBox::errorIcon |
                  IMessageBox::moveable );
      SetSoundFlag(false);
   }

   /**************************************
   * Put the window objects on the screen
   **************************************/
   pscore = new TBogScore(104, &Client, this);
   plist  = new TBogWordList (101, &Client);
   pwip   = new TBogWIP(103, &Client);
   ptimer = new TBogTimer(102, &Client, this, psound); 
   pboard = new TBogBoard(100, &Client, this, pwip, plist, pscore, psound);

   /**********************************
   * Put the text controls on the screen
   **********************************/
   Client.setFont(myfont);

   st_wip.setText("Word in Progress")
         .setAlignment(IStaticText::bottomLeft)
         .setFont((myfont));

   st_list.setText("Word List")
          .setAlignment(IStaticText::bottomLeft)
          .setFont((myfont));

   st_timer.setText("Timer")
           .setAlignment(IStaticText::bottomLeft)
           .setFont((myfont));
 
   st_score.setText("Current Score")
           .setAlignment(IStaticText::bottomLeft)
           .setFont((myfont));

   /***************************************
   * Position the child windows in canvas
   ***************************************/
//   ISize defaultCell = IMultiCellCanvas::defaultCell();

   Client
//      .addToCell(&gameTitle, 3,1,5,1)  //child window,scolumn/row,
      .addToCell(&st_list, 5,1,1,1)      // # of cols and rows

      .addToCell(pboard, 2,2,2,2)      //Board control
      .addToCell(plist, 5,2,2,2)       //Word List

      .addToCell(&st_wip, 2,4,1,1)     //Word in progress static text
      .addToCell(pwip, 2,5,2,1)        //Word in progress entry field

      .addToCell(&st_score, 6,4,1,1)   //Score static text
      .addToCell(pscore, 6,5,1,1)      //Score data field
                                
      .addToCell(&st_timer, 2,7,1,1)    //Timer static text
      .addToCell(ptimer, 2,8,6,1);      //Timer Slider control

   /***************************************
   * Set up the layout of the canvas
   ***************************************/
   Client.setColumnWidth(6, IMultiCellCanvas::defaultCell().width(), false);

   Client
      .setRowHeight(1, 15, false)
      .setRowHeight(2, 100, false)
      .setRowHeight(3, 95, false)
      .setRowHeight(4, 15, false)
      .setRowHeight(5, 25, false)
      .setRowHeight(6, 5, false)
      .setRowHeight(7, 15, false)
      .setRowHeight(8, 35, false);

   pboard->setMinimumSize(ISize(200, 196));
   plist->setMinimumSize(ISize(200, 96));

   /**********************************
   * Size the frame according to the
   * client window.
   **********************************/
   Client.setMinimumSize(ISize(440,330));
   ISize clientSize(Client.minimumSize());
   moveSizeToClient(IRectangle( IPoint(10, 80), clientSize));

   //Don't want this to be available until the end of the game
   menuBar.disableItem(IDM_FIND_ALL);
   menuBar.disableItem(IDM_PAUSE_GAME);
   menuBar.disableItem(IDM_RESUME_GAME);
   menuBar.disableItem(IDM_STOP_GAME);
}


/*****************************************************************************
* Function: ~TBogWindow
* Parms:    none
* Purpose:  delete which thou has newed!
* Returns:  Nothing
*****************************************************************************/
TBogWindow::~TBogWindow ()
{
   if(pscore) 
       delete pscore;
   if(plist) 
       delete plist;
   if(pwip) 
       delete pwip;
   if(ptimer) 
   {
      ptimer->stopTimer();
      delete ptimer;
   } 
   if(pboard) 
       delete pboard;
   if(psound) 
       delete psound;
}


/*****************************************************************************
* Function: paintWindow
* Parms:    event
* Purpose:  In case I need this during a wm_paint message
* Returns:  Nothing
*****************************************************************************/
Boolean TBogWindow::paintWindow(IPaintEvent &event)
{
   return false;
}


/*****************************************************************************
* Function: pauseGame
* Parms:    none
* Purpose:  stop the timer temporarily
* Returns:  Nothing
*****************************************************************************/
void TBogWindow::pauseGame()
{
   ptimer->stopTimer();

   menuBar.disableItem(IDM_PAUSE_GAME);
   menuBar.enableItem(IDM_RESUME_GAME);

   GameOn = false;   
}

/*****************************************************************************
* Function: resumeGame
* Parms:    none
* Purpose:  start the timer again
* Returns:  Nothing
*****************************************************************************/
void TBogWindow::resumeGame()
{
   ptimer->startTimer();

   menuBar.enableItem(IDM_PAUSE_GAME);
   menuBar.disableItem(IDM_RESUME_GAME);

   GameOn = true;   
}


/*****************************************************************************
* Function: command
* Parms:    event
* Purpose:  process the menu items
* Returns:  false
*****************************************************************************/
Boolean TBogWindow::command(ICommandEvent& event)
{
   Boolean stopProcessingEvent = false;

   switch (event.commandId())
   {
      case IDM_GAME_NEW:
         resetGame(event);
         ptimer->startTimer();

         break;
      case IDM_GAME_EXIT:
         ptimer->stopTimer();
         WinPostMsg(handle(), WM_CLOSE, 0L, 0L);
         break;
      case IDM_SETTINGS:
         settings();
         break;

      case IDM_FIND_ALL:
      {
         WinSetPointer(HWND_DESKTOP, SPTR_WAIT);

         //Find all the words that the user should have!
         plist->selectAllWords();
         pboard->FindAll();

         WinSetPointer(HWND_DESKTOP, SPTR_ARROW);
         break;
      }
      case IDM_STOP_GAME:
         gameOver();
         break;
      case IDM_PAUSE_GAME:
         pauseGame();
         break;
      case IDM_RESUME_GAME:
         resumeGame();
         break;
      case IDM_HELP_CONTENTS:
         help.show(IHelpWindow::contents);
      return true;
         break;
      case IDM_HELP_ABOUT:
         aboutBox();
         break;
      default:
         break;
   }
   return stopProcessingEvent;
}


/*****************************************************************************
* Function: mouseClicked
* Parms:    evt
* Purpose:  virtual function to handle the mouse click
* Returns:  false
*****************************************************************************/
Boolean TBogWindow :: mouseClicked(IMouseClickEvent &evt)
{              
   return false;
}


/*****************************************************************************
* Function: resetGame
* Parms:    event
* Purpose:  start a new game
* Returns:  nothing
*****************************************************************************/
void TBogWindow::resetGame(ICommandEvent& event)
{
   pboard->InitBoard();
   pwip->resetString();                     //Clear out WIP
   plist->clearList();                      //Clear list box
   pscore->clearScore();                    //Reset current score
   ptimer->resetTimer();

   menuBar.disableItem(IDM_FIND_ALL);
   menuBar.enableItem(IDM_STOP_GAME);
   menuBar.enableItem(IDM_PAUSE_GAME);
   GameOn = true;   
}


/*****************************************************************************
* Function: GameOver
* Parms:    none
* Purpose:  end of game processing
* Returns:  nothing
*****************************************************************************/
void TBogWindow::gameOver()
{
   //stop the timer and delete the instance of it
   ptimer->stopTimer();

// play an exit wav file!
   psound->playSound("gameover.wav");

   IMessageBox msgBox(this);
   msgBox.show("The game is over.  Thank you for playing Boggle!",
               IMessageBox::okButton  |
               IMessageBox::informationIcon |
               IMessageBox::moveable );

//adjust the menu options
   menuBar.disableItem(IDM_PAUSE_GAME);
   menuBar.disableItem(IDM_STOP_GAME);
   menuBar.disableItem(IDM_RESUME_GAME);
   menuBar.enableItem(IDM_FIND_ALL);

   GameOn = false;   
}


/*****************************************************************************
* Function: settings
* Parms:    none
* Purpose:  Handle the settings dialog box
* Returns:  nothing
*****************************************************************************/
void TBogWindow::settings()
{
   unsigned short value;                 //Return value from dialog

//Create a Text Dialog
   AOptionsDialog * optionsDialog = new AOptionsDialog(this, DLG_BOX, this); 

   optionsDialog->showModally();            //Show this Text Dialog as Modal
   value=optionsDialog->result();           //Get result (eg OK or Cancel)

   delete optionsDialog;                    //Delete textDialog
}

/*****************************************************************************
* Function: aboutBox
* Parms:    none
* Purpose:  Handle the about dialog box
* Returns:  nothing
*****************************************************************************/
void TBogWindow::aboutBox()
{
   unsigned short value;                 //Return value from dialog

//Create a Text Dialog
   AboutDialog* ADlg = new AboutDialog(this, dlg_about, this); 

   ADlg->showModally();            //Show this Text Dialog as Modal
   value=ADlg->result();           //Get result (eg OK or Cancel)

   delete ADlg;                    //Delete textDialog
}

