/*****************************************************************************
* Program:  WIP.CPP
* Purpose:  Handles the word in process entry field processing
*****************************************************************************/
#include  "bogwin.hpp"
#include  "dict.hpp"

class TBogWIP;  //forward declare this class to get a compile!

/*****************************************************************************
* Function: TBogWIP
* Parms:    Parms for the parent window
* Purpose:  Create the entry field and instantiate the dictionary
* Returns:  Nothing
*****************************************************************************/
TBogWIP::TBogWIP (unsigned long id,
                  IWindow* parent)
        : IEntryField(id, parent, parent, IRectangle(), defaultStyle() | readOnly)
{
   IFont myfont;

   strset(sWIPString, '\0');
   WordChk = new Dictionary("INDEX", "WORDS");


//Set the font for the control
   myfont.setName("Helvetica")
         .setPointSize(8);

   setFont((myfont));

   setLimit(16);  // no more than 16 chars in field!!
}

/*****************************************************************************
* Function: ~TBogWIP
* Parms:    none
* Purpose:  delete the dictionary
* Returns:  Nothing
*****************************************************************************/
TBogWIP::~TBogWIP()
{
   delete WordChk;
}

/*****************************************************************************
* Function: addLetter
* Parms:    sLetter 
* Purpose:  Add the passed letter to the entry field string and show it
* Returns:  Nothing
*****************************************************************************/
void TBogWIP::addLetter(char *sLetter)
{
   /********************************************************
   ** Here we must add the letter to the static control
   ** and repaint it to make it visible to the user.
   ********************************************************/
   if (strlen(sWIPString) < WORDLENGTH)
   {
      strcat(sWIPString, sLetter); 
      setText(sWIPString);
   }
}

/*****************************************************************************
* Function: resetString
* Parms:    none
* Purpose:  clear out the word in process string
* Returns:  Nothing
*****************************************************************************/
void TBogWIP::resetString()
{
   strset(sWIPString, '\0');          //Clear array in WIP
   setText(sWIPString);
}

/*****************************************************************************
* Function: upString
* Parms:    upword - string to be in upper case,  
* Purpose:  
* Returns:  Nothing
*****************************************************************************/
void TBogWIP::upString(char *upword, char *sDownWord)
{
   /********************************************************
   ** Here we call the ToUpper method in the Dictionary object
   ********************************************************/
   WordChk->ToUpper(upword, sDownWord);
}

