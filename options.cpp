/*****************************************************************************
* Program:  OPTIONS.CPP
* Purpose:  This module handles the support of the options/settings dialog 
*           box that is in the system.
*****************************************************************************/
#include <os2.h>
#include <icmdevt.hpp>                  //ICommandEvent
#include <istring.hpp>                  //IString Class
#include <ireslib.hpp>                  //IResourceLibrary/IResourceId Class
#include <stdlib.h>

#include "options.h"                    
#include "Aoptions.hpp"                 //AOptionsDialog Class

/*****************************************************************************
* Function: AOptionsDialog
* Parms:    ownerWnd - the owner of this window
*           rid - ID of window in resource file
*           pbwindow - a pointer to the TBogWindow class so we can check 
            game options
* Purpose:  Constructor for text dialog window
* Returns:  Nothing
*****************************************************************************/
AOptionsDialog :: AOptionsDialog(IWindow * ownerWnd, unsigned long rid, TBogWindow* pbwindow)
             : IFrameWindow(IResourceId(rid), ownerWnd)
{
   ICommandHandler::handleEventsFor(this); //Set self as command event handler
   pbwin = pbwindow;

//define the entryfield so I can work with it
   timerDuration = new IEntryField(sle_timerduration, this);
   soundCheckBox = new ICheckBox(cb_sound, this);

// Get the number stored in the game variable and display it here.
   IString ls_tickduration;
   sprintf(ls_tickduration, "%.2f", pbwin->GetTickDuration() / 1000.00);   

   timerDuration->setText(ls_tickduration);

//Set the checkbox by what is set in the game
   Boolean flag = pbwin->GetSoundFlag();
   soundCheckBox->select(flag);
} 

/*****************************************************************************
* Function: ~AOptionsDialog
* Parms:    None
* Purpose:  Destructor - will delete instantiated items
* Returns:  Nothing
*****************************************************************************/
AOptionsDialog :: ~AOptionsDialog()
{
//  ICommandHandler::stopHandlingEventsFor(this);  
   delete timerDuration;
   delete soundCheckBox;
} 

/*****************************************************************************
* Function: command
* Parms:    cmdevt - info about what was selected in the window
* Purpose:  Process Commands from the window
* Returns:  true - if OK button was pressed,  false otherwise
*****************************************************************************/
Boolean AOptionsDialog :: command(ICommandEvent& cmdevt)
{
   //Get the value entered into the edit field and convert it to
   // a number
   float duration;
   sscanf(timerDuration->text(), "%f", &duration);

   //Save the state of the checkBox
   Boolean flag = soundCheckBox->isSelected();

   switch(cmdevt.commandId()) 
   {
   case DID_OK:
      //We will set the number of milliseconds for the clock tick
      // based on the number of seconds entered by the user.
      pbwin->SetTickDuration(duration * 1000);

       //Save the value of the sound variable to the game
       pbwin->SetSoundFlag(flag);

      dismiss(DID_OK);                 //Dismiss Dialog - Allow focus to main
      return(true);                    //Return Processing Completed
      break;

   }
   return(false);                       //Allow Default Processing to occur
}