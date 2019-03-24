/*****************************************************************************
* Program:  LASTSQ.CPP
*
* This class is used to determine whether a newly selected
* square is adjacent to the last selected square.  It does this
* by comparing the row and column number of the new one against
* the old.  Legal values are as follows (assume values are >0):
*
*       (row, col-1)  (row, col-1)
*       (row+1, col)  (row+1, col+1)  (row+1, col-1)
*       (row-1, col)  (row-1, col+1)  (row-1, col-1)
*
******************************************************************/
#include "lastsq.hpp"

/*****************************************************************************
* Function: LastSquare
* Parms:    none
* Purpose:  constructor - will set the last square values to zero
* Returns:  Nothing
*****************************************************************************/
LastSquare::LastSquare()
{
   reSetSquare ();
}


/*****************************************************************************
* Function: isValidSquare
* Parms:    row and column of square to check
* Purpose:  checks for adjacency of the the new square against values
*           stored for the last square
* Returns:  true - if it is a valid square,  false - otherwise
*****************************************************************************/
int LastSquare::isValidSquare (int newrow, int newcol)
{
   /*******************************************************************
   ** This condition implies that this is the first square selected.
   *******************************************************************/
   if (row == 0)  return TRUE;

   if(newrow == row)
   {
      if (newcol == col-1 || newcol == col+1)
         return TRUE;
   }
   if(newrow == row+1)
   {
      if (newcol == col || newcol == col-1 || newcol == col+1)
         return TRUE;
   }
   if(newrow == row-1)
   {
      if (newcol == col || newcol == col-1 || newcol == col+1)
         return TRUE;
   }
   return FALSE;
}


/*****************************************************************************
* Function: setSquare
* Parms:    row and column of square to check
* Purpose:  will store the values for current square so we can perform
*           adjacency checking later on
* Returns:  nothing
*****************************************************************************/
void LastSquare::setSquare (int x, int y)
{
   row = x;  col = y;
}

/*****************************************************************************
* Function: reSetSquare
* Parms:    none
* Purpose:  initialize our values to zero
* Returns:  nothing
*****************************************************************************/
void LastSquare::reSetSquare ()
{
   row = 0;  col = 0;
}
