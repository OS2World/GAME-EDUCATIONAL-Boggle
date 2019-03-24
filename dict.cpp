/*****************************************************************************
* Program:  DICT.CPP
* Purpose:  Handles tasks related to the dictionary - lookup words,  etc.
*****************************************************************************/
#include "common.hpp"
#include "dict.hpp"


/*****************************************************************************
* Function: Dictionary
* Parms:    indx - filename of the index, wrds - filename of the wordlist
* Purpose:  Opens the files necessary for word validation
* Returns:  Nothing
*****************************************************************************/
Dictionary::Dictionary(char *indx, char *wrds)
{
   ndx.open(indx);
   if (!ndx)
   {
   WinMessageBox(HWND_DESKTOP,
                 HWND_DESKTOP,
                "Unable To Find Index File Needed For The Spell Check...",
                "Boggle System Error",
                0,                         /* message box id        */
                MB_NOICON | MB_OK);        /* icon and button flags */
      exit(-1);
   }

   Dictionary::initIndex();

   dict.open(wrds);
   if (!dict)
   {
   WinMessageBox(HWND_DESKTOP,
                 HWND_DESKTOP,
                "Unable To Find Dictionary File Needed For The Spell Check...",
                "Boggle System Error",
                0,                         /* message box id        */
                MB_NOICON | MB_OK);        /* icon and button flags */
      exit(-1);
   }
}

/*****************************************************************************
* Function: initIndex
* Parms:    none
* Purpose:  saves the index file into memory
* Returns:  Nothing
*****************************************************************************/
void Dictionary::initIndex()
{
   char buf[50];

   // initialize the index
   ndx >> NX;
   for (int i=0; i<NX; i++) 
   {
      if (ndx >> buf) 
      {
         Index[i] = new char[strlen(buf) + 1];   //memory leak!!
         strcpy(Index[i], buf);
      }
      ndx >> loc[i];
   }
}

/*****************************************************************************
* Function: Lookup
* Parms:    word - the word to verify in the dictionary
* Purpose:  Find the word in the dictionary
* Returns:  An index into the words file showing where the word is
*           0 if word is not found
*****************************************************************************/
int Dictionary::Lookup(char *word)
{
   //char Buffer[50], *UWord = "";
   char UWord[WORDLENGTH];
   int i, r, found;

   UWord[0] = '\0';
   found = FALSE;
   ToUpper(UWord, word);

   /********************************************************************
   * This section will find the word in the index that is greater
   * than or equal to the word we are looking for.
   ********************************************************************/
   for (i = 0; i < NX; i++)
      if ((r = strcmp(UWord, Index[i]) ) < 0) 
         break;
      else if (r == 0) 
      {
         strcpy(Buffer, Index[i]);
         found = TRUE;
         break;
      }
   if (found)
      return i * 256;
   else
      if (i == NX)
         return 0;
      else 
      {
         /********************************************************************
         * Once the position in the index is found, we will start
         * sequentially searching that file starting at the offset given in
         * the index for 256 words,  looking for our word.
         ********************************************************************/
         i = i - 1;
         dict.clear(0);
         dict.seekg(loc[i]);
         for (int j = 0; j < 256; j++) 
         {
            dict.getline(Buffer, 50);
            if ((r = strcmp(UWord, Buffer)) < 0)
               return -(i * 256) - j;
            else if (r == 0)
               return (i * 256) + j;
         }
         strcpy(Buffer, Index[i+1]);
         return -(i + 1) * 256;
      }
}

/*****************************************************************************
* Function: ToUpper
* Parms:    out - outstring, in - instring
* Purpose:  convert a given string to upper case
* Returns:  Nothing
*****************************************************************************/
void Dictionary::ToUpper (char *out, char *in)
{
   while (*in)
   {
      *out = toupper(*in);

      out++;
      in++;
   }
   *out = '\0';
}

/*****************************************************************************
* Function: Prefix
* Parms:    str
* Purpose:  compares two strings
* Returns:  true - strings are equal, false - otherwise
*****************************************************************************/
int Dictionary::prefix (char *str, char *buf)
{
   while (*str)
   {
      if (*str != *buf)
         return FALSE;
      str++;
      buf++;
   }
   return TRUE;
}


/*****************************************************************************
* Function: setBuffer
* Parms:    str - strings to store
* Purpose:  stores a string in this class
* Returns:  nothing
*****************************************************************************/
void Dictionary::setBuffer(char *str)
{
   strcpy(Buffer, str);
}

/*****************************************************************************
* Function: GetBuffer
* Parms:    none
* Purpose:  returns the current stored string to the caller
* Returns:  The stored string
*****************************************************************************/
char *Dictionary::getBuffer()
{
   return Buffer;
}

