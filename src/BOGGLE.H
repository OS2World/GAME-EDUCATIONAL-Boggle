/*****************************************************************************
* Program:  BOGGLE.H
* Purpose:  Common header for the Boggle game - menu IDs, resource IDs,
*           board/layout constants, and shared includes.
*****************************************************************************/
#ifndef BOGGLE_H
#define BOGGLE_H

#define INCL_BASE
#define INCL_WIN
#define INCL_GPI
#define INCL_WINSTDDLGS
#define INCL_HELP
#include <os2.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*****************************************************************************
* Menu IDs - reserved ranges per plan:
*   100-199   Game menu items
*   200-299   Options / detail items
*   300-399   Language items
*   900-999   Help items (999 = About)
*   1000-1099 Submenu cascade IDs
*****************************************************************************/
#define IDM_NEW             101   /* New Game (Ctrl+N) */
#define IDM_FIND_ALL        102   /* Find All (game over only) */
#define IDM_PAUSE           103   /* Pause Game (checkable, Ctrl+P) */
#define IDM_QUIT            104   /* Quit Game (Ctrl+Q) */
#define IDM_EXIT            105   /* Exit (Ctrl+X) */

#define IDM_HIGHDET         201
#define IDM_MEDIUMDET       202
#define IDM_LOWDET          203

#define IDM_SAVEONEXIT      210   /* Save settings on exit (checkable) */
#define IDM_BACKGRND        211   /* Background Run (checkable, Ctrl+B) */
#define IDM_FRAME           212   /* Frame Controls (checkable, Ctrl+F) */
#define IDM_SETTINGS        213   /* Settings dialog (timer + sound) */

#define IDM_LANG_EN         300
#define IDM_LANG_ES         301
#define IDM_LANG_NL         302
#define IDM_LANG_DE         303
#define IDM_LANG_FR         304
#define IDM_LANG_IT         305

#define IDM_HELP            900
#define IDM_HELP_ABOUT      999

#define IDM_SUBMENU_GAME    1000
#define IDM_SUBMENU_OPTIONS 1001
#define IDM_SUBMENU_HELP    1002
#define IDM_SUBMENU_DETAIL  1003
#define IDM_SUBMENU_LANG    1004

/*****************************************************************************
* Dialog and resource IDs
*****************************************************************************/
#define IDD_OPTIONS         100
#define IDD_TIMERLEN        101   /* ENTRYFIELD in options dialog */
#define IDD_SOUND           102   /* AUTOCHECKBOX in options dialog */
#define IDD_ABOUT           200

/* Options dialog control ids */
#define IDC_ST_TLEN         110   /* "Timer Length (secs):" static  */

/* About dialog control ids */
#define IDC_AB_ICON         120
#define IDC_AB_TITLE        121
#define IDC_AB_VERSION      122
#define IDC_AB_RELEASE      123
#define IDC_AB_COPY1        124
#define IDC_AB_COPY2        125
#define IDC_AB_LICENSE      126

#define ID_BLANK            250   /* (unused blank bitmap id) */
#define ID_TIMER            1     /* WinStartTimer id */
#define ID_SLIDER           300   /* timer slider control id */

/* Client area child control ids */
#define IDC_CB_WIP          601   /* word in progress entry field  */
#define IDC_CB_LIST         602   /* word list list box            */
#define IDC_CB_SCORE        603   /* score value static            */
#define IDC_CB_SLIDER       604   /* timer slider control          */
#define IDC_CB_LBL_WIP      605
#define IDC_CB_LBL_LIST     606
#define IDC_CB_LBL_SCORE    607
#define IDC_CB_LBL_TIMER    608
#define IDC_CB_SUBMIT       609   /* submit / validate word button */

#define WND_MAINWIN         1001

/*****************************************************************************
* Board layout constants
*****************************************************************************/
#define SQ_SIZE             80    /* square edge in pels */
#define SQ_GAP              4     /* gap between squares in pels */
#define SQ_STRIDE           (SQ_SIZE + SQ_GAP)
#define SQ_ORIGIN           20    /* board origin offset from client edge */
#define BOARD_ROWS          4
#define BOARD_COLS          4
#define NUM_SQUARES         16

/*****************************************************************************
* Word/dictionary constants
*****************************************************************************/
#define WORDLENGTH          17    /* max 16 chars + null */
#define MAX_WORDLIST        512   /* word list box capacity */

#define TICKDURATION_DEF    1500  /* default ms per timer tick */
#define TICKDURATION_MIN    500
#define TICKDURATION_MAX    10000

#define BOGGLE_VERSION      "1.1"

#endif  /* BOGGLE_H */
