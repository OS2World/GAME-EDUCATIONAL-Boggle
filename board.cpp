/*****************************************************************************
* Program:  BOARD.CPP
* Purpose:  This module handles the events associated with the game board
*           itself.
*****************************************************************************/
#include  "bogwin.hpp"

const int  ID_SQUARE  = 101;
const int  BSWidth    = 40;
const int  BSHeight   = 40;

//these represent the possible letters on each die
char *cube_faces[] = { "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW",
   "CIMOTU", "DEILRX", "DELRVY", "DISTTY", "EEGHNW",
   "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HLNNRZ",
"IHMNUQ" };


// The following array defines the adjacency matrix used by
//  the application.  It shows which cubes are valid selections
//  Consider the following diagram of cubes on the board:
//
// 12 13 14 15
//  8  9 10 11
//  4  5  6  7
//  0  1  2  3
//
// The first array element says that from cube 0,  cubes one,  four,
// or cube five are the only valid selections.

int nums[][9] = { { 1,  4,  5, -1 },
   { 0,  2,  4,  5,  6, -1 },
   { 1,  3,  5,  6,  7, -1 },
   { 2,  6,  7, -1 },
   { 0,  1,  5,  8,  9, -1 },
   { 0,  1,  2,  4,  6,  8,  9, 10, -1 },
   { 1,  2,  3,  5,  7,  9, 10, 11, -1 },
   { 2,  3,  6, 10, 11, -1 },
   { 4,  5,  9, 12, 13, -1 },
   { 4,  5,  6,  8, 10, 12, 13, 14, -1 },
   { 5,  6,  7,  9, 11, 13, 14, 15, -1 },
   { 6,  7, 10, 14, 15, -1 },
   { 8,  9, 13, -1 },
   { 8,  9, 10, 12, 14, -1 },
   { 9, 10, 11, 13, 15, -1 },
   {10, 11, 14, -1 }
} ;


/*****************************************************************************
* Function: TBogBoard
* Parms:    Pointers to other objects it needs to talk to
* Purpose:  Instantiate the squares
* Returns:  Nothing
*****************************************************************************/
TBogBoard::TBogBoard (unsigned long id, IWindow* parentAndOwner, 
                      TBogWindow* PBWindow, TBogWIP* PBWIP, 
                      TBogWordList* PBList, TBogScore* PBScore,
                       Sound *pSound)
    : ICanvas(id, parentAndOwner, parentAndOwner)
{
   int row, col, k = 0;

   addHandler((ICommandHandler *)this);
   addHandler((IPaintHandler *)this);
   addHandler((IMouseClickHandler *)this);

   /**************************************************
   * Instantiate the dictionary
   **************************************************/
   brd_words = new Dictionary("INDEX", "WORDS");

   /**************************************************
   * This will keep track of the last selected
   * square so only adjacent squares can be chosen
   * next.
   **************************************************/
   PBLastSquare = new LastSquare();
   pbwip = PBWIP;
   pblist = PBList;

   /**************************************************
   * Draw the board using a canvas as a rectangle on
   * canvas client area.
   **************************************************/
   pboard = this;
   pboard->setColor(ICanvas::background, IColor::yellow);

   /********************************************************
   * Instantiate the cubes with their appropriate letters
   ********************************************************/
   for (row = 0; row < 4; row++)
   {
      for (col = 0; col < 4; col++)
      {
      try{
         PBSquare[k] = new TBogSquare(k, this,
                                      " ",
                                      PBWindow,
                                      (TBogBoard*)this,
                                      PBLastSquare,
                                      PBWIP,
                                      PBList,
                                      PBScore,
                                      pSound,
                                      row, col, 
                                      IRectangle(IPoint(col*(40+2)+15, row*(40+2)+15),
                                                 ISize(40,40)));
      }
      catch(IException& exc)
      {
         IMessageBox abortIt(IWindow::desktopWindow());
         abortIt.setTitle("Exception Caught in Boggle.cpp");
         abortIt.show(exc.text(), IMessageBox::okButton);
      }

         Cubes[k] = new Dice(cube_faces[k]);
         k++;
      }
   }

}


/*****************************************************************************
* Function: ~TBogBoard
* Parms:    none
* Purpose:  destructor
* Returns:  Nothing
*****************************************************************************/
TBogBoard::~TBogBoard ()
{
   int k;
   delete brd_words;
   delete PBLastSquare;

   for(k=0; k<16; k++)
      delete Cubes[k];
}

/*****************************************************************************
* Function: paintWindow
* Parms:    none
* Purpose:  Process paint messages if you need to
* Returns:  Nothing
*****************************************************************************/
Boolean TBogBoard::paintWindow(IPaintEvent &event)
{
   return false;
}


/*****************************************************************************
* Function: mouseClicked
* Parms:    evt
* Purpose:  Process mouse clicked messages
* Returns:  Nothing
*****************************************************************************/
Boolean TBogBoard :: mouseClicked(IMouseClickEvent &evt)
{
   return false;
}


/*****************************************************************************
* Function: command
* Parms:    event
* Purpose:  process the command event
* Returns:  false
*****************************************************************************/
Boolean TBogBoard::command(ICommandEvent& event)
{
   Boolean stopProcessingEvent = false;

   switch (event.commandId())
   {
      default:
         break;
   }
   return stopProcessingEvent;
}

/*****************************************************************************
* Function: CanvasPointer
* Parms:    none
* Purpose:  return a pointer to the canvas for those who need it
* Returns:  pointer to the board
*****************************************************************************/
ICanvas *TBogBoard::CanvasPointer()
{
   return pboard;
}

/*****************************************************************************
* Function: InitBoard
* Parms:    none
* Purpose:  Roll the dice and put some squares on the board
* Returns:  nothing
*****************************************************************************/
void TBogBoard::InitBoard ()
{
   int iIndex, i, j, k=0;
   char *szFace;
   char SquareText[3] = "\0\0";
  
   rLetter.perm();                                         //create random order of cubes
   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
         iIndex = rLetter.getValue(k);    //determine which cube to use
  
         szFace = Cubes[iIndex]->Roll();
  
         SquareText[0] = *szFace;                  //check for Q!!!
         if (*szFace == 'Q') SquareText[1] = 'u';
  
         /*******************************************
         ** Tell the square what letter to display.
         *******************************************/
         PBSquare[k]->setSquareText(SquareText);
  
         fndall_str[k] = *szFace;
         k++;
         SquareText[1] = '\0';                                  //Reset the Q text!!
      }
   }
   fndall_str[k] = '\0';
   memset(stack, 0, sizeof(stack));    //set these to zero so
   memset(chflag, 0, sizeof(chflag));  // the findall function can keep track
}                                      // of what it has searched thus far
  
/*****************************************************************************
* Function: ClearBoard
* Parms:    none
* Purpose:  set the squares back to an initial state
* Returns:  nothing
*****************************************************************************/
void TBogBoard::ClearBoard ()
{
   for (int i = 0; i < 16; i++)
      PBSquare[i]->reset();
  
   pbwip->resetString();
   PBLastSquare->reSetSquare();
}
  

/*****************************************************************************
* Function: FindAll
* Parms:    none
* Purpose:  Find the words that the user missed
* Returns:  nothing
*****************************************************************************/
void TBogBoard::FindAll ()
{

   char word[17];

   //This is used for debugging purposes!! TAKE IT OUT!!
   //memcpy(fndall_str,"BOGGLEGAMEMASTER", 16);
   for (int i = 0; i < 16; i++) 
   {
      word[0] = fndall_str[i];  //this function kicks of the process
      word[1] = '\0';           // by calling the search function with
      stack[0] = i;             // a starting point of the current letter
      chflag[i] = TRUE;
      Search(word, 1);
      chflag[i] = FALSE;
   }
}


/*****************************************************************************
* Function: Search
* Parms:    word, n
* Purpose:  This recursive function will look up all the words you missed
* Returns:  nothing
*****************************************************************************/
void TBogBoard::Search (char *word, int n)
{
   int r, k;
   char  PBuf[50];
  
   r = brd_words->Lookup(word);
   if (r > 0)
   {
      int irc = (int)pblist->locateText(word, false);
  
      /*****************************************************************
      * Move the word over if it is more than two characters,  is
      * not in the list,  and is found in the dictionary.
      *****************************************************************/
      if ((n > 2) && (strcmp(brd_words->getBuffer(), PBuf) != 0) && (irc < 0))
      {
         pblist->addString(word);
         strcpy(PBuf, brd_words->getBuffer());
      }
   }
   else if (r < 0) 
        {
           if ( (brd_words->prefix(word, brd_words->getBuffer())) == FALSE)
              return;
        }
        else
           return;

   /**************************************************
   * This is the section that recursively looks up
   * all possible words from a given starting point
   **************************************************/
   //Starting figures are as follows:
   //  k=1, i=0, n=1        
   for (int i = 0; (k = nums[stack[n-1]][i]) != -1; i++)
   {
      if (chflag[k] == FALSE) 
      {
         word[n] = fndall_str[k];   //add the next letter in the string to try
         word[n+1] = '\0';          //BO the first time (debug mode)
         stack[n] = k;
         chflag[k] = TRUE;          //We were here already
         Search(word, n+1);         //recursively call yourself
         chflag[k] = FALSE;         //We are done with this recursive loop
      }
   }
}
