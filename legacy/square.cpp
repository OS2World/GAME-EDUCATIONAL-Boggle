/*****************************************************************************
* Program:  SQUARE.CPP
* Purpose:  This module handles the events associated with the squares on the 
*           game board.
*****************************************************************************/
#include  "bogwin.hpp"

Boolean isButton1Down=false;  //keep this global for all squares
                              // so that the mouse movement tracking
                              // can tell if the button is down while
                              // you are in "drag mode"


/*****************************************************************************
* Function: TBogSquare
* Parms:    Pointers to objects it needs to communicate with as well as a
*           row and column ID it can associate with this square
* Purpose:  Instantiate the square and save the pointers to other objects
* Returns:  Nothing
*****************************************************************************/
TBogSquare::TBogSquare (unsigned long id,
                        IWindow* parent,
                        char* letter, 
                        TBogWindow* PBWindow,
                        TBogBoard* PBBoard,
                        LastSquare* PBLastSq,
                        TBogWIP* PBWIP,
                        TBogWordList* PBLIST,
                        TBogScore* PBScore,
                        Sound* pSound,
                        int row, int col,
                        const IRectangle& initial)
      : IBitmapControl(id, parent, parent, ID_BLANK, initial),
      myfont(this)
{

   /****************************************************
   * Each square needs to know what row and col it is.
   * The for loop is indexed starting with 0 so we
   * need to add 1 to it.
   ****************************************************/
   rowid = row+1;  colid = col+1;

   /***************************************************
   * Save the address of the LastSquare in the square
   * private data member.  We will use this
   * later to send the square text to the WIP.
   ***************************************************/
   PBLastSquare = PBLastSq;

   /*********************************************
   * Save the address of the WIP in the square
   * private data member.  We will use this
   * later to send the square text to the WIP.
   *********************************************/
   pbwip = PBWIP;
   pbwindow = PBWindow;
   pbboard = PBBoard;
   pblist = PBLIST;
   pbscore = PBScore;
   psound = pSound;

   HiLite = false;
   normalColor = new IColor(204,204,204);
   selectedColor = IColor::white;

   setAlignment(IStaticText::centerCenter);
   myfont.setName("Swiss")
         .setPointSize(10)
         .setBold()
         .setItalic();
  
   setBackgroundColor(*normalColor);
   setFont((myfont));

   strcpy(Letter, "");
   setText(Letter);

   ((IMouseHandler*)this)->handleEventsFor(this);
   ((IPaintHandler*)this)->handleEventsFor(this);
   ((AMouseMoveHandler*)this)->handleEventsFor(this);
}

/*****************************************************************************
* Function: ~TBogSquare
* Parms:    Destructor
* Purpose:  delete any instantiated objects
* Returns:  Nothing
*****************************************************************************/
TBogSquare::~TBogSquare()
{
   delete normalColor;
   return;
}

/*****************************************************************************
* Function: mouseClicked
* Parms:    event - info about which mouse button was pressed
* Purpose:  Process the mouse messages generated from the square
* Returns:  false - so someone else can process the message
*****************************************************************************/
Boolean TBogSquare::mouseClicked(IMouseClickEvent &event)
{
  if ( event.mouseButton() == IMouseClickEvent::button1 &&
       event.mouseAction() == IMouseClickEvent::down )
  {
    button1Down();
  }
  else if ( event.mouseButton() == IMouseClickEvent::button1 &&
            event.mouseAction() == IMouseClickEvent::up )
  {
    button1Up();
  }
  else if ( event.mouseButton() == IMouseClickEvent::button2 &&
            event.mouseAction() == IMouseClickEvent::down )
  {
    button2Down();
  }
  return false;         // Allow someone else to also process.
}


/*****************************************************************************
* Function: button1Down
* Parms:    none
* Purpose:  called when the left mouse button is clicked.  It will hilite the
*           selected square and add the letter to the word in process edit
*           field.  It also will record the letter selected for adjacency 
*           testing later on.
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::button1Down()
{
   isButton1Down = true;

   if (!HiLite && pbwindow->isGameOn())  //game in play mode and not already hilighted
   {
      if (PBLastSquare->isValidSquare(rowid, colid))  //adjaced square??
      {
         HiLite = TRUE;
         setBackgroundColor(selectedColor);

         refresh();  //force a repaint

         /*********************************************
         *  Send Letter to WIP static field 
         *********************************************/
         pbwip->addLetter(Letter);
         PBLastSquare->setSquare(rowid, colid); //keep track of this for adjacency
      }                                         //  testing later on.
      else
      {
         setBackgroundColor(*normalColor);
      }
   }
   return;
}

/*****************************************************************************
* Function: button1Up
* Parms:    none
* Purpose:  called when the left mouse button let go.  This will validate 
*           that you selected a valid square and will play a sound if not.
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::button1Up()
{
   if (!HiLite && pbwindow->isGameOn())
   {
       if (!PBLastSquare->isValidSquare(rowid, colid))
       {
          if(pbwindow->GetSoundFlag())
             psound->playSound("badword.wav");     //Not a valid word
       }
   }

   isButton1Down = false;
   return;
}

/*****************************************************************************
* Function: button2Down
* Parms:    none
* Purpose:  This will try to move the valid word from the word in process 
*           list to the word list listbox.  It will also call the scoring 
*           routines for the valid word.
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::button2Down()
{
   int irc;
   char UString[WORDLENGTH];

   if (!pbwindow->isGameOn())  //if the game if over get out!
       return;

   //convert it to upper case
   pbwip->upString(UString, pbwip->getWIPString());

   /*********************************************
   *  Send Word in Process to list box only if...
   *       1) word is >= 3 letters in length
   *       2) word is not a duplicate
   *       3) word is a real English word
   *********************************************/
   if (strlen(UString) > 2)
   {
      char *prefix;
      /********************************************************
      *  Do not allow duplicate words...search the list box
      ********************************************************/
      irc = pblist->locateText(UString); 
      if (irc >= 0)  //already got this one
      {
         prefix = UString;
         pblist->deselectAll();                           //clear prev error
         pblist->selectWord(irc);                         //show their error

         // Let them know they goofed!
         if(pbwindow->GetSoundFlag())
           psound->playSound("usedword.wav");
      }      
      /*********************************************
      *  And do not allow non-English words
      *********************************************/
      else
         if (pbwip->checkWord(UString) < 0)
         {
           // Let them know they goofed!
           if(pbwindow->GetSoundFlag())
               psound->playSound("boing.wav");
         }
      else
      {  //must be a valid word
         pblist->addString(UString);
         pbscore->calcScore(strlen(UString));
         pbscore->displayScore();
         pblist->deselectAll();                            //take off hilite

         if(pbwindow->GetSoundFlag())
         {
            if(strlen(UString) > 4)
                psound->playSound("excelnt.wav");      //Excellent Word!!
             else
                psound->playSound("goodword.wav");     //Got a good word anyway
         }
      }
   }
   else
   {
      //Must be less than two letters!!
      if(pbwindow->GetSoundFlag())
         psound->playSound("badword.wav");             //Not a valid word
   }
   pbwip->resetString();                           //Clear out WIP
   clearBoard();                                   //Clear entries on board
   return;
}

/*****************************************************************************
* Function: setSquareText
* Parms:    SquareLetter - the letter to display in the box
* Purpose:  This will set up the game so the paint function will display the
*           desired letter.
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::setSquareText(char *SquareLetter)
{
   strcpy(Letter, SquareLetter);
   refresh();
}


/*****************************************************************************
* Function: paintWindow
* Parms:    event
* Purpose:  show the letter in the box
* Returns:  false - let someone else process the message
*****************************************************************************/
Boolean TBogSquare::paintWindow(IPaintEvent &event)
{
   setText(Letter);
   return false;
}


/*****************************************************************************
* Function: clearBoard
* Parms:    none
* Purpose:  tell the board to clear ALL the squares and reset 
*           things back to an initial state
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::clearBoard()
{
   pbboard->ClearBoard ();
   return;
}

/*****************************************************************************
* Function: reset
* Parms:    none
* Purpose:  fix the color of the square
* Returns:  Nothing
*****************************************************************************/
void TBogSquare::reset ()

{
   setBackgroundColor(*normalColor);
   if (HiLite)
      HiLite = FALSE;
}

/*****************************************************************************
* Function: motion
* Parms:    evt
* Purpose:  for the square to be selected during drag mode,  we want the 
*           mouse to be positioned more towards the center of the square.
* Returns:  false - allow standard processing
*****************************************************************************/
Boolean TBogSquare::motion( IEvent &evt )
{
   unsigned short xCoordinate = evt.parameter1().lowNumber();
   unsigned short yCoordinate = evt.parameter1().highNumber();

   /************************************************
   * This ensures that you have to be somewhere near
   * the center of the square to actually select it.
   * It makes it far easier to use the mouse in drag
   * mode this way
   ************************************************/
   if(isButton1Down)
      if (  (xCoordinate > 10 && xCoordinate < 30) && 
            (yCoordinate > 10 && yCoordinate < 30) )
         button1Down();

  return false;  // allow standard processing
}  


