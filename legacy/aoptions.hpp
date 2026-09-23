#ifndef ATEXTDIALOG_HPP
#define ATEXTDIALOG_HPP

#include <iframe.hpp>                   //IFrameWindow Class (Parent)
#include <icmdhdr.hpp>                  //ICommandHandler (Parent)
#include <icheckbx.hpp>                 //ICheckBox Class

#include "bogwin.hpp"

//**************************************************************************
// Class:   AOptionsDialog                                                 *
//                                                                         *
// Purpose: Dialog window for the C++ Hello World sample application.      *
//          It is a subclass of IFrameWindow, ICommandHandler              *
//                                                                         *
//**************************************************************************
class AOptionsDialog : public IFrameWindow, public ICommandHandler
{
public:
  AOptionsDialog (IWindow * ownerWnd, unsigned long rid, TBogWindow* pbwindow) ;
  ~AOptionsDialog();

protected:
  virtual Boolean
  command(ICommandEvent& cmdevt);     //Process the dialog command events

private:
  TBogWindow*       pbwin;
  IEntryField*      timerDuration;
  ICheckBox*        soundCheckBox;
};

#endif


