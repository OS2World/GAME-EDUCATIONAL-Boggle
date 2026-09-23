/*****************************************************************************
* Program:  DICT.C
* Purpose:  Handles tasks related to the dictionary - lookup words, etc.
*
* Port notes:  the original C++ opened the index and word-list files in
* text mode.  The data files use CRLF line endings and the index stores
* raw byte offsets into the word list.  This C port opens the files in
* binary mode and strips the trailing CR/LF itself, which reproduces the
* original lookup semantics exactly and is immune to text-mode seeking.
*****************************************************************************/
#include "boggle.h"
#include "dict.h"

#define NX_MAX      150     /* number of dictionary blocks */
#define BLOCK_WORDS 256     /* words searched per block */
#define WORD_MAX    50      /* longest dictionary line buffer */

static FILE      *fpIndex;                 /* index file handle   */
static FILE      *fpWords;                 /* word list file      */
static int        NX;                      /* number of blocks    */
static char       Index[NX_MAX][WORD_MAX]; /* first word per block*/
static long       loc[NX_MAX];             /* byte offsets/blocks */
static char       Buffer[WORD_MAX];        /* working string      */
static char       g_szDataDir[CCHMAXPATH]; /* "X:\path\to\data\"  */


/*****************************************************************************
* Function: DictionaryInit
* Parms:    none
* Purpose:  Opens the files necessary for word validation and loads the
*           index into memory.  Locates the files in the "data" subdirectory
*           relative to the running EXE.
* Returns:  Nothing
*****************************************************************************/
void DictionaryInit(void)
{
   char  szIndexPath[CCHMAXPATH];
   char  szWordsPath[CCHMAXPATH];
   PTIB  ptib;
   PPIB  ppib;
   char  szExe[CCHMAXPATH];
   char *p;
   int   i;

   /* Determine data directory: ExeDir\data\ */
   g_szDataDir[0] = '\0';
   if (DosGetInfoBlocks(&ptib, &ppib) == 0 &&
       DosQueryModuleName(ppib->pib_hmte, sizeof(szExe), szExe) == 0)
   {
      p = strrchr(szExe, '\\');
      if (p && (strlen(szExe) + 6) < sizeof(g_szDataDir))
      {
         *(p + 1) = '\0';
         sprintf(g_szDataDir, "%sdata\\", szExe);
      }
   }

   if (g_szDataDir[0] != '\0')
   {
      sprintf(szIndexPath, "%sINDEX", g_szDataDir);
      sprintf(szWordsPath, "%sWORDS", g_szDataDir);
   }
   else
   {
      strcpy(szIndexPath, "INDEX");
      strcpy(szWordsPath, "WORDS");
   }

   /* ---------------------------------------------------------------
    * Open and load the index - first value is the block count, then
    * NX pairs of (first word, byte offset of its block).
    * --------------------------------------------------------------- */
   fpIndex = fopen(szIndexPath, "rb");
   if (!fpIndex)
   {
      WinMessageBox(HWND_DESKTOP,
                    HWND_DESKTOP,
                    "Unable To Find Index File Needed For The Spell Check...",
                    "Boggle System Error",
                    0,                         /* message box id        */
                    MB_NOICON | MB_OK);        /* icon and button flags */
      exit(-1);
   }

   if (fscanf(fpIndex, "%d", &NX) != 1)
   {
      WinMessageBox(HWND_DESKTOP,
                    HWND_DESKTOP,
                    "The Index File Is Corrupted...",
                    "Boggle System Error",
                    0,
                    MB_NOICON | MB_OK);
      exit(-1);
   }
   if (NX > NX_MAX)
      NX = NX_MAX;

   for (i = 0; i < NX; i++)
   {
      long n = 0L;
      if (fscanf(fpIndex, "%49s %ld", Index[i], &n) == 2)
         loc[i] = n;
      else
         loc[i] = 0L;
   }
   fclose(fpIndex);

   /* ---------------------------------------------------------------
    * Open the word list.
    * --------------------------------------------------------------- */
   fpWords = fopen(szWordsPath, "rb");
   if (!fpWords)
   {
      WinMessageBox(HWND_DESKTOP,
                    HWND_DESKTOP,
                    "Unable To Find Dictionary File Needed For The Spell Check...",
                    "Boggle System Error",
                    0,                         /* message box id        */
                    MB_NOICON | MB_OK);        /* icon and button flags */
      exit(-1);
   }

   Buffer[0] = '\0';
}


/*****************************************************************************
* Function: DictionaryLookup
* Parms:    word - the word to verify in the dictionary
* Purpose:  Find the word in the dictionary
* Returns:  >0 an index into the words file showing where the word is
*            0 if the word is beyond all index entries
*           <0 if the word was not found (magnitude = sort position)
*****************************************************************************/
int DictionaryLookup(const char *word)
{
   char UWord[WORDLENGTH];
   int  i, r, found;

   DictionaryToUpper(UWord, word);

   found = FALSE;

   /********************************************************************
   * Find the index entry that is greater than or equal to the word
   * we are looking for.
   ********************************************************************/
   for (i = 0; i < NX; i++)
   {
      if ((r = strcmp(UWord, Index[i])) < 0)
         break;
      else if (r == 0)
      {
         strcpy(Buffer, Index[i]);
         found = TRUE;
         break;
      }
   }

   if (found)
      return i * 256;
   else if (i == NX)
      return 0;
   else
   {
      /********************************************************************
      * Once the position in the index is found, sequentially search the
      * block of 256 words starting at the stored byte offset.
      ********************************************************************/
      int j;

      i = i - 1;
      fseek(fpWords, loc[i], SEEK_SET);
      for (j = 0; j < BLOCK_WORDS; j++)
      {
         int len;

         if (!fgets(Buffer, WORD_MAX, fpWords))
            break;                       /* end of file               */

         len = (int)strlen(Buffer);      /* strip CRLF in binary mode */
         while (len > 0 && (Buffer[len-1] == '\n' || Buffer[len-1] == '\r'))
            Buffer[--len] = '\0';

         if ((r = strcmp(UWord, Buffer)) < 0)
            return -(i * 256) - j;       /* sorts before this word    */
         else if (r == 0)
            return (i * 256) + j;        /* found!                    */
      }
      strcpy(Buffer, Index[i+1]);
      return -(i + 1) * 256;             /* sorts before next block   */
   }
}


/*****************************************************************************
* Function: DictionaryToUpper
* Parms:    out - outstring, in - instring
* Purpose:  convert a given string to upper case
* Returns:  Nothing
*****************************************************************************/
void DictionaryToUpper(char *out, const char *in)
{
   while (*in)
   {
      *out = (char)toupper((unsigned char)*in);
      out++;
      in++;
   }
   *out = '\0';
}


/*****************************************************************************
* Function: DictionaryPrefix
* Parms:    str - prefix to test, buf - string to compare against
* Purpose:  compare two strings
* Returns:  TRUE - str is a prefix of buf, FALSE - otherwise
*****************************************************************************/
int DictionaryPrefix(const char *str, const char *buf)
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
* Function: DictionaryBuffer
* Parms:    none
* Purpose:  returns the current stored comparison string
* Returns:  The stored string
*****************************************************************************/
const char *DictionaryBuffer(void)
{
   return Buffer;
}
