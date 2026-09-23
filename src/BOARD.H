/*****************************************************************************
* Program:  BOARD.H
* Purpose:  Boggle game board - the 16 cubes, their letters, adjacency
*           testing, and the recursive find-all word search.
*****************************************************************************/
#ifndef BOARD_H
#define BOARD_H

/*****************************************************************************
* Function: BoardInit
* Parms:    none
* Purpose:  Load the cube faces and adjacency matrix.
* Returns:  nothing
*****************************************************************************/
void BoardInit(void);

/*****************************************************************************
* Function: BoardShuffle
* Parms:    none
* Purpose:  Roll the dice: shuffle cube order, roll each die face, and
*           record the resulting board letters.  Resets the selection
*           state.
* Returns:  nothing
*****************************************************************************/
void BoardShuffle(void);

/*****************************************************************************
* Function: BoardLetter
* Parms:    k - square index 0..15
* Purpose:  Return the displayed letter of the square.  For a 'Q' cube a
*           string of two characters ("Qu") is produced.
* Returns:  pointer to a static two-character string
*****************************************************************************/
const char *BoardLetter(int k);

/*****************************************************************************
* Function: BoardLetterChar
* Parms:    k - square index 0..15
* Purpose:  Return the single raw letter of the square (used by the word
*           search, which treats 'Q' as the letter Q).
* Returns:  the letter
*****************************************************************************/
char BoardLetterChar(int k);

/*****************************************************************************
* Function: BoardValidNext
* Parms:    k - the square index being considered
* Purpose:  Check whether square k is a legal next selection: either the
*           very first selection of the game, or adjacent to the last
*           selected square.
* Returns:  TRUE if legal, FALSE otherwise
*****************************************************************************/
int BoardValidNext(int k);

/*****************************************************************************
* Function: BoardSelect
* Parms:    k - square index 0..15
* Purpose:  Mark square k as selected (highlighted).
* Returns:  nothing
*****************************************************************************/
void BoardSelect(int k);

/*****************************************************************************
* Function: BoardIsSelected
* Parms:    k - square index 0..15
* Purpose:  Query whether the square is currently selected.
* Returns:  TRUE/FALSE
*****************************************************************************/
int BoardIsSelected(int k);

/*****************************************************************************
* Function: BoardClearSelections
* Parms:    none
* Purpose:  Clear all square selections and reset the last-square for
*           adjacency testing.
* Returns:  nothing
*****************************************************************************/
void BoardClearSelections(void);

/*****************************************************************************
* Callback for BoardFindAll - called once for every word found on the
* board that exists in the dictionary.
*****************************************************************************/
typedef void (*FindWordCallback)(char *word, int length);

/*****************************************************************************
* Function: BoardFindAll
* Parms:    cb - callback invoked for each discovered word
* Purpose:  Search the current board for every word the dictionary
*           contains (words of 3 or more letters).
* Returns:  nothing
*****************************************************************************/
void BoardFindAll(FindWordCallback cb);

#endif  /* BOARD_H */
