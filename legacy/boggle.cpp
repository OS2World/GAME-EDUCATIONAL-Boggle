/*****************************************************************************
* Program:  BOGGLE.CPP
* Purpose:  This begins the game by instantiating TBogWindow
*****************************************************************************/
#include  <iapp.hpp>
#include  "bogwin.hpp"
 
/************************
* Main Program      
************************/
void main ()
{
   try {
      TBogWindow tbog("Boggle Game", WND_MAINWIN);

      /******************************************
      * Load the accelerators from the .rc file
      ******************************************/
      IAccelerator accelTable(WND_MAINWIN, &tbog);

      tbog.setFocus();
      tbog.show();

      IApplication::current().run();
   }
   catch(IException& exc)
   {
      IMessageBox abortIt(IWindow::desktopWindow());
      abortIt.setTitle("Exception Caught in Boggle.cpp");
      abortIt.show(exc.text(), IMessageBox::okButton);
   }
   return;
}
