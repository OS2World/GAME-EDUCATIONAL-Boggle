/*****************************************************************************
* Program:  LANG.H
* Purpose:  Language support tables and accessor macros for Boggle.
*
* The translated strings live in a two-dimensional table
*   langStr[ language ][ string id ]
* which is INSTANTIATED in BOGGLE.C by defining LANG_MAIN before
* including this header.  Menu text and dialog text are swapped at
* run time by the Preferences handler.
*
* All translated text is pure ASCII (no accented characters) so that
* the sources remain buildable with the stock Open Watcom tool chain.
*****************************************************************************/
#ifndef LANG_H
#define LANG_H

#define LANG_EN  0
#define LANG_ES  1
#define LANG_NL  2
#define LANG_DE  3
#define LANG_FR  4
#define LANG_IT  5
#define LANG_COUNT  6

/* The names of the languages in their own language - used for the
 * Language menu entries and the preferences dialog. */
#define LANG_NAME_EN  "English"
#define LANG_NAME_ES  "Espanol"
#define LANG_NAME_NL  "Nederlands"
#define LANG_NAME_DE  "Deutsch"
#define LANG_NAME_FR  "Francais"
#define LANG_NAME_IT  "Italiano"

/*****************************************************************************
* String IDs
*****************************************************************************/
enum {
   STR_GAME,          /* main menu heading                     */
   STR_NEW,           /* game > new game                       */
   STR_FINDALL,       /* game > find all words                 */
   STR_PAUSE,         /* game > pause game                     */
   STR_QUIT,          /* game > quit game                      */
   STR_EXIT,          /* game > exit                           */
   STR_OPTIONS,       /* options menu heading                  */
   STR_DETAIL,        /* options > detail submenu heading      */
   STR_HIGHDET,       /* options > detail > high               */
   STR_MEDIUMDET,     /* options > detail > medium             */
   STR_LOWDET,        /* options > detail > low                */
   STR_LANGUAGE,      /* options > language submenu heading    */
   STR_SAVEONEXIT,    /* options > save settings on exit       */
   STR_BACKGRND,      /* options > background run              */
   STR_FRAME,         /* options > frame controls              */
   STR_SETTINGS,      /* options > settings...                 */
   STR_HELP,          /* help menu heading                     */
   STR_HELP_CONTENTS, /* help > help contents (F1)             */
   STR_ABOUT,         /* help > about boggle                   */
   STR_TITLE,         /* window title                          */
   STR_OPTTITLE,      /* settings dialog title                 */
   STR_OPT_TIMER,     /* settings: game-length label           */
   STR_OPT_SOUND,     /* settings: sound checkbox              */
   STR_OK,            /* settings: ok button                   */
   STR_CANCEL,        /* settings: cancel button               */
   STR_SCORE,         /* score label on the client            */
   STR_TIME,          /* time/level label on the client       */
   STR_WORD,          /* word label on the client             */
   STR_WIP,           /* word-in-progress label on the client */
   STR_LIST,          /* word list label on the client        */
   STR_MSG_TITLE,     /* message box title                     */
   STR_MSG_WELCOME,   /* game-start message                    */
   STR_MSG_TIMESUP,   /* end-of-game message                   */
   STR_COUNT
};

/* The language currently in use.  Declared in global.c. */
extern int current_lang;

/*****************************************************************************
* The string table.  Instantiated in BOGGLE.C:
*
*      #define LANG_MAIN
*      #include "lang.h"
*
*****************************************************************************/
#ifdef LANG_MAIN
#define LANG_EXTERN
#else
#define LANG_EXTERN extern
#endif

LANG_EXTERN const char *const langStr[LANG_COUNT][STR_COUNT];

/* Convenience accessor - returns the current-language string. */
#define tr(id)   (langStr[current_lang][id])

#endif  /* LANG_H */
