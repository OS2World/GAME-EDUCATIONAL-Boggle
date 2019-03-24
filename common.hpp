#define INCL_WIN
#define INCL_GPILCIDS           /* Font functions               */
#define INCL_GPIPRIMITIVES      /* GPI primitive functions      */

#include <os2.h>

#include <iapp.hpp>                       //Application Class
#include <istattxt.hpp>                   //StaticText Class
#include <istring.hpp>                    //String Class
#include <ifont.hpp>                      //Font Class
#include <iscroll.hpp>                    //Scrollbar Class
#include <Ilistbox.hpp>                   //Listbox Class
#include <imsgbox.hpp>                    //MessageBox Class

#define WORDLENGTH 17    //Max. word length for word in process
#define FALSE 0
#define TRUE  1
#define MAX   150

//#define BEEPFREQ       700L       /* Beep frequency, in hertz          */
//#define BEEPDURATION   200L       /* Duration of beep, in milliseconds */
#define BEEPFREQ       100L       /* Beep frequency, in hertz          */
#define BEEPDURATION   50L        /* Duration of beep, in milliseconds */

