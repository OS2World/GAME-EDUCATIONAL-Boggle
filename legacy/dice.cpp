/*****************************************************************************
* Program:  DICE.CPP
* Purpose:  Handles the rolling of the dice and setting of the square letter
*           based on the letters defined for that cube
*****************************************************************************/
#include  "bogwin.hpp"
#include  "dice.hpp"

/*****************************************************************************
* Function: Dice
* Parms:    facestring - the sequence of letters defines for a particular die
* Purpose:  Constructor
* Returns:  Nothing
*****************************************************************************/
Dice::Dice(const char *facestring)
{
   for (int i=0; i<7; i++)
      faces[i] = *facestring++;
}

/*****************************************************************************
* Function: Roll
* Parms:    none
* Purpose:  simulate the rolling of the dice
* Returns:  a particular letter to show on the cube face
*****************************************************************************/
char *Dice::Roll()
{
   return( &faces[(rand() % 6)] );
}

