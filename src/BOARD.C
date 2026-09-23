/*****************************************************************************
* Program:  BOARD.C
* Purpose:  This module handles the 16-cube game board: the cube faces,
*           dice rolling, adjacency testing, and the recursive find-all
*           word search.
*****************************************************************************/
#include "boggle.h"
#include "board.h"
#include "dict.h"

/* These represent the possible letters on each die */
static char cube_faces[16][7] = {
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW",
   "CIMOTU", "DEILRX", "DELRVY", "DISTTY", "EEGHNW",
   "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HLNNRZ",
   "IHMNUQ"
};

/* The adjacency matrix used by the application.  It shows which cubes
 * are valid selections from each cube.  Consider the board:
 *
 *   12 13 14 15
 *    8  9 10 11
 *    4  5  6  7
 *    0  1  2  3
 *
 * The first entry says that from cube 0, cubes 1, 4, or 5 are the only
 * valid selections.  Each row is terminated with a -1.
 */
static int nums[16][9] = {
   {  1,  4,  5, -1 },
   {  0,  2,  4,  5,  6, -1 },
   {  1,  3,  5,  6,  7, -1 },
   {  2,  6,  7, -1 },
   {  0,  1,  5,  8,  9, -1 },
   {  0,  1,  2,  4,  6,  8,  9, 10, -1 },
   {  1,  2,  3,  5,  7,  9, 10, 11, -1 },
   {  2,  3,  6, 10, 11, -1 },
   {  4,  5,  9, 12, 13, -1 },
   {  4,  5,  6,  8, 10, 12, 13, 14, -1 },
   {  5,  6,  7,  9, 11, 13, 14, 15, -1 },
   {  6,  7, 10, 14, 15, -1 },
   {  8,  9, 13, -1 },
   {  8,  9, 10, 12, 14, -1 },
   {  9, 10, 11, 13, 15, -1 },
   { 10, 11, 14, -1 }
};

/* Board state */
static char   board_letter[NUM_SQUARES]; /* single raw letter per cube */
static char   board_qu[NUM_SQUARES];     /* two-char display ("Qu")    */
static BOOL   selected[NUM_SQUARES];     /* selection highlight state  */
static int    lastSquare;                /* last selected cube (-1=hole)*/

/* Find-all search state */
static int    stack[20];                 /* the current letter trail   */
static BOOL   chflag[NUM_SQUARES];       /* visited flags              */
static char   fndall_str[17];            /* letters of the board       */
static FindWordCallback search_cb;       /* callback for the search    */


/*****************************************************************************
* Function: BoardInit
* Parms:    none
* Purpose:  Initialise the board state.
* Returns:  Nothing
*****************************************************************************/
void BoardInit(void)
{
   int i;
   for (i = 0; i < NUM_SQUARES; i++)
   {
      board_letter[i] = ' ';
      board_qu[i] = 0;
      selected[i] = FALSE;
   }
   lastSquare = -1;
   search_cb = NULL;
}


/*****************************************************************************
* Function: BoardShuffle
* Parms:    none
* Purpose:  Roll the dice: shuffle the cube order, roll one face of each
*           cube, and record the resulting board letters.
* Returns:  Nothing
*****************************************************************************/
void BoardShuffle(void)
{
   int order[NUM_SQUARES];
   int i, rand_cube, temp_val, k, cube, face;

   /* Create a random order of the 16 cubes (Fisher-Yates shuffle) */
   for (i = 0; i < NUM_SQUARES; i++)
      order[i] = i;

   srand((unsigned)time(NULL));
   for (i = NUM_SQUARES; i > 0; i--)
   {
      rand_cube = rand() % i;
      temp_val = order[i-1];
      order[i-1] = order[rand_cube];
      order[rand_cube] = temp_val;
   }

   /* Roll each cube in the shuffled order and set the board letters */
   for (k = 0; k < NUM_SQUARES; k++)
   {
      cube = order[k];
      face = rand() % 6;
      board_letter[k] = cube_faces[cube][face];

      /* Present the letter 'Q' as "Qu" on the board */
      if (board_letter[k] == 'Q')
         board_qu[k] = 1;
      else
         board_qu[k] = 0;

      selected[k] = FALSE;
      fndall_str[k] = board_letter[k];
   }
   fndall_str[NUM_SQUARES] = '\0';

   lastSquare = -1;
   memset(stack, 0, sizeof(stack));
   memset(chflag, 0, sizeof(chflag));
}


/*****************************************************************************
* Function: BoardLetter
* Parms:    k - square index 0..15
* Purpose:  Return the displayed letter of the square.
* Returns:  pointer to a static two-character string
*****************************************************************************/
const char *BoardLetter(int k)
{
   static char buf[3];

   if (board_qu[k])
   {
      buf[0] = 'Q';
      buf[1] = 'u';
      buf[2] = '\0';
      return buf;
   }
   buf[0] = board_letter[k];
   buf[1] = '\0';
   return buf;
}


/*****************************************************************************
* Function: BoardLetterChar
* Parms:    k - square index 0..15
* Purpose:  Return the single raw letter of the square.
* Returns:  the letter
*****************************************************************************/
char BoardLetterChar(int k)
{
   return board_letter[k];
}


/*****************************************************************************
* Function: BoardValidNext
* Parms:    k - square index being considered
* Purpose:  Check whether the square is a legal next selection.
* Returns:  TRUE if legal, FALSE otherwise
*****************************************************************************/
int BoardValidNext(int k)
{
   int i;

   /* The very first selection of the game is always valid */
   if (lastSquare < 0)
      return TRUE;

   /* Otherwise the square must be adjacent to the last selected one */
   for (i = 0; nums[lastSquare][i] != -1; i++)
   {
      if (nums[lastSquare][i] == k)
         return TRUE;
   }
   return FALSE;
}


/*****************************************************************************
* Function: BoardSelect
* Parms:    k - square index 0..15
* Purpose:  Mark square k as selected.
* Returns:  Nothing
*****************************************************************************/
void BoardSelect(int k)
{
   if (k >= 0 && k < NUM_SQUARES)
   {
      selected[k] = TRUE;
      lastSquare = k;
   }
}


/*****************************************************************************
* Function: BoardIsSelected
* Parms:    k - square index 0..15
* Purpose:  Query the selection state of a square.
* Returns:  TRUE if selected, FALSE otherwise
*****************************************************************************/
int BoardIsSelected(int k)
{
   if (k < 0 || k >= NUM_SQUARES)
      return FALSE;
   return selected[k];
}


/*****************************************************************************
* Function: BoardClearSelections
* Parms:    none
* Purpose:  Clear all selections and reset the last-square tracking.
* Returns:  Nothing
*****************************************************************************/
void BoardClearSelections(void)
{
   memset(selected, 0, sizeof(selected));
   lastSquare = -1;
}


/*****************************************************************************
* Function: Search
* Parms:    word - the current word being built, n - its length
* Purpose:  Recursively walk every connected path on the board, using
*           dictionary prefix pruning, and report every complete word.
* Returns:  Nothing
*****************************************************************************/
static void Search(char *word, int n)
{
   int r, i, k;
   char PBuf[WORDLENGTH];

   r = DictionaryLookup(word);
   if (r > 0)
   {
      /* A complete dictionary word of three or more letters */
      if (n >= 3)
      {
         strcpy(PBuf, word);
         if (search_cb)
            search_cb(PBuf, n);
      }
   }
   else if (r < 0)
   {
      /* Not a word - prune this branch unless it is a dictionary prefix */
      if (DictionaryPrefix(word, DictionaryBuffer()) == FALSE)
         return;
   }
   else
      return;                              /* sorts beyond the index */

   /* Continue the search through every adjacent, unvisited cube */
   for (i = 0; (k = nums[stack[n-1]][i]) != -1; i++)
   {
      if (!chflag[k])
      {
         word[n] = fndall_str[k];
         word[n+1] = '\0';
         stack[n] = k;
         chflag[k] = TRUE;
         Search(word, n + 1);
         chflag[k] = FALSE;
      }
   }
}


/*****************************************************************************
* Function: BoardFindAll
* Parms:    cb - callback invoked for each discovered word
* Purpose:  Find the words that the user missed - start a search from
*           each square in turn.
* Returns:  Nothing
*****************************************************************************/
void BoardFindAll(FindWordCallback cb)
{
   char word[17];
   int  i;

   search_cb = cb;
   if (!search_cb)
      return;

   for (i = 0; i < NUM_SQUARES; i++)
   {
      word[0] = fndall_str[i];
      word[1] = '\0';
      stack[0] = i;
      chflag[i] = TRUE;
      Search(word, 1);
      chflag[i] = FALSE;
   }

   search_cb = NULL;
}
