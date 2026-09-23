/*****************************************************************************
* Program:  SCORE.CPP
* Purpose:  responsible for maintaining the score of the game
*****************************************************************************/
#include "score.hpp"
#include  <stdio.h>                 
 
/*****************************************************************************
* Function: TBogScore
* Parms:    parent windows 
* Purpose:  Constructor - set up the static text field for the score
* Returns:  nothing
*****************************************************************************/
TBogScore::TBogScore(unsigned long id,
                      IWindow* parent,
                      IWindow* owner)
         :  IStaticText(id, parent, owner),
            myFont(this)
{
   score_value = 0;
   sprintf(sScore, "%d", score_value);

//Set up the font for the text control
   setAlignment(IStaticText::centerCenter);
   myFont.setName("Swiss")
         .setPointSize(10)
         .setBold()
         .setItalic();
   setFont((myFont));

//Set the color
   setColor(background, IColor::darkGray);

//Display the actual score
   setText(sScore);
}

/*****************************************************************************
* Function: ~TBogScore
* Parms:    none
* Purpose:  Destructor
* Returns:  nothing
*****************************************************************************/
TBogScore::~TBogScore()
{
}

/*****************************************************************************
* Function: clearScore
* Parms:    none
* Purpose:  Set the score back to zero
* Returns:  nothing
*****************************************************************************/
void TBogScore::clearScore()
{
   score_value = 0;

//Display the actual score
   displayScore();
}

/*****************************************************************************
* Function: calcScore
* Parms:    nLetters - number of letters in word to score
* Purpose:  based on the # of letters - increment the score
* Returns:  nothing
*****************************************************************************/
void TBogScore::calcScore(int nLetters)
{
   if ((nLetters > 2) && (nLetters <= 4))
      score_value += 1;
   else if (nLetters == 5)
      score_value += 2;
   else if (nLetters == 6)
      score_value += 3;
   else if (nLetters == 7)
      score_value += 5;
   else if (nLetters > 7)
      score_value += 11;
}

/*****************************************************************************
* Function: displayScore
* Parms:    none
* Purpose:  show the current score on the screen
* Returns:  nothing
*****************************************************************************/
void TBogScore::displayScore()
{
   char score_str[4];
   static int last_score;

   sprintf(sScore, "%d", score_value);
   setText(sScore);

   sprintf(score_str,"%-3.1d", score_value);

   last_score = score_value;  
}
