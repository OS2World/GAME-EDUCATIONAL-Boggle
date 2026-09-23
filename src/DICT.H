/*****************************************************************************
* Program:  DICT.H
* Purpose:  Dictionary look-up for Boggle - word validation for the
*           spell check and the board word search.
*****************************************************************************/
#ifndef DICT_H
#define DICT_H

/*****************************************************************************
* Function: DictionaryInit
* Parms:    none
* Purpose:  Open/reload the index and word-list files ("INDEX", "WORDS"
*           in the working directory).  Displays a system-error message
*           box and exits if either file cannot be found.
* Returns:  nothing
*****************************************************************************/
void DictionaryInit(void);

/*****************************************************************************
* Function: DictionaryLookup
* Parms:    word - word to verify (mixed case is accepted)
* Purpose:  Locate the word in the dictionary.
* Returns:  > 0  index into the words file where the word is
*            0   word sorts beyond the last index entry (not found)
*           < 0  not found (magnitude identifies sort position)
*****************************************************************************/
int DictionaryLookup(const char *word);

/*****************************************************************************
* Function: DictionaryPrefix
* Parms:    str - prefix to test, buf - string to compare against
* Purpose:  Returns TRUE if the leading characters of buf equal str.
* Returns:  TRUE/FALSE
*****************************************************************************/
int DictionaryPrefix(const char *str, const char *buf);

/*****************************************************************************
* Function: DictionaryToUpper
* Parms:    out - output string, in - input string
* Purpose:  Copy `in` to `out` converting every character to upper case.
* Returns:  nothing
*****************************************************************************/
void DictionaryToUpper(char *out, const char *in);

/*****************************************************************************
* Function: DictionaryBuffer
* Parms:    none
* Purpose:  Return the most recent word fetched/comparison string from the
*           dictionary (used by the board search for prefix pruning).
* Returns:  pointer to the internal buffer
*****************************************************************************/
const char *DictionaryBuffer(void);

#endif  /* DICT_H */
