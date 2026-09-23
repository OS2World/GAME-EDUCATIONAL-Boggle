/*****************************************************************************
* Program:  WLIST.CPP
* Purpose:  This module handles the events associated with the word list 
*           list box.
*****************************************************************************/
#include  "bogwin.hpp"

 
/*****************************************************************************
* Function: TBogWordList 
* Parms:    parms for the parent and style of list box
* Purpose:  Constructor for the list box
* Returns:  Nothing
*****************************************************************************/
TBogWordList::TBogWordList (unsigned long id,
                           IWindow* parent)
      : IListBox(id, parent, parent, 
                   IRectangle(), 
                   defaultStyle() | multipleSelect)
{

}

/*****************************************************************************
* Function: addString
* Parms:    sString - string to add to the list box
* Purpose:  Adds a string to the list box
* Returns:  Nothing
*****************************************************************************/
void TBogWordList::addString(char *sString)
{
   /********************************************************
   * Here we must add the string to the list box.
   ********************************************************/
   addAscending(sString);
}


/*****************************************************************************
* Function: clearList
* Parms:    none
* Purpose:  removes all the words from the list box
* Returns:  Nothing
*****************************************************************************/
void TBogWordList::clearList()
{
   removeAll();
}

/*****************************************************************************
* Function: selectAll
* Parms:    none
* Purpose:  removes all the words from the list box
* Returns:  Nothing
*****************************************************************************/
void TBogWordList::selectAllWords()
{
   if(!isEmpty())
      selectAll();  //part of the IBM class library
}


/*****************************************************************************
* Function: selectWord
* Parms:    index - particular word in the listbox you wish to hilight
* Purpose:  shows whats has been already guessed
* Returns:  Nothing
*****************************************************************************/
void TBogWordList::selectWord(int index)
{

//Show the word that was already selected
   select(index, TRUE);                       //show their error
   setTop(index);
}
