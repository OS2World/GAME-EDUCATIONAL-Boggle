#define LANG_MAIN
#include "boggle.h"
#include "lang.h"
#include "dict.h"
#include "board.h"
#include "sound.h"

#include <mcios2.h>

const char *const langStr[LANG_COUNT][STR_COUNT] = {
   {  /* English */
      "~Game",
      "~New Game\tCtrl+N",
      "~Find All Words",
      "~Pause Game\tCtrl+P",
      "~Quit Game\tCtrl+Q",
      "E~xit\tCtrl+X",
      "~Options",
      "~Detail",
      "~High",
      "~Medium",
      "~Low",
      "~Language",
      "~Save settings on exit",
      "~Background Run\tCtrl+B",
      "~Frame Controls\tCtrl+F",
      "~Settings...",
      "~Help",
      "~Help Contents\tF1",
      "~About Boggle...",
      "Boggle",
      "Boggle Options",
      "Timer Length (secs):",
      "~Sound",
      "~Ok",
      "~Cancel",
"Current Score",
      "Timer",
      "Word",
      "Word in Progress",
      "Word List",
      "Boggle",
      "Welcome to Boggle!",
      "The game is over.  Thank you for playing Boggle!"
   },
   {  /* Espanol */
      "~Juego",
      "~Nuevo Juego\tCtrl+N",
      "~Encontrar Todas",
      "~Pausa\tCtrl+P",
      "~Terminar Juego\tCtrl+Q",
      "~Salir\tCtrl+X",
      "~Opciones",
      "~Detalle",
      "~Alto",
      "~Medio",
      "~Bajo",
      "~Idioma",
      "~Guardar configuracion al salir",
      "~Ejecutar en segundo plano\tCtrl+B",
      "~Controles de Marco\tCtrl+F",
      "~Ajustes...",
      "~Ayuda",
      "~Contenido de Ayuda\tF1",
      "~Acerca de Boggle...",
      "Boggle",
      "Opciones de Boggle",
      "Duracion del Tiempo (seg):",
      "~Sonido",
      "~Aceptar",
      "~Cancelar",
      "Puntuacion",
      "Tiempo",
      "Palabra",
      "Palabra en Curso",
      "Lista de Palabras",
      "Boggle",
      "Bienvenido a Boggle!",
      "Se acabo el juego.  Gracias por jugar Boggle!"
   },
   {  /* Nederlands */
      "~Spel",
      "~Nieuw Spel\tCtrl+N",
      "~Vind Alle Woorden",
      "~Pauze\tCtrl+P",
      "~Spel Beeindigen\tCtrl+Q",
      "~Afsluiten\tCtrl+X",
      "~Opties",
      "~Detail",
      "~Hoog",
      "~Gemiddeld",
      "~Laag",
      "~Taal",
      "~Instellingen opslaan bij afsluiten",
      "~Op achtergrond uitvoeren\tCtrl+B",
      "~Frame Bediening\tCtrl+F",
      "~Instellingen...",
      "~Help",
      "~Help Inhoud\tF1",
      "~Over Boggle...",
      "Boggle",
      "Boggle Opties",
      "Tijdsduur (sec):",
      "~Geluid",
      "~OK",
      "~Annuleren",
      "Score",
      "Tijd",
      "Woord",
      "Woord in Uitvoering",
      "Woordenlijst",
      "Boggle",
      "Welkom bij Boggle!",
      "Het spel is voorbij.  Dank u voor het spelen van Boggle!"
   },
   {  /* Deutsch */
      "~Spiel",
      "~Neues Spiel\tCtrl+N",
      "~Alle Woerter Finden",
      "~Pause\tCtrl+P",
      "~Spiel Beenden\tCtrl+Q",
      "B~eenden\tCtrl+X",
      "~Optionen",
      "~Detail",
      "~Hoch",
      "~Mittel",
      "~Niedrig",
      "~Sprache",
      "~Einstellungen beim Beenden speichern",
      "~Im Hintergrund ausfuehren\tCtrl+B",
      "~Rahmensteuerung\tCtrl+F",
      "~Einstellungen...",
      "~Hilfe",
      "~Hilfe-Inhalt\tF1",
      "~Ueber Boggle...",
      "Boggle",
      "Boggle Optionen",
      "Zeitdauer (Sek):",
      "~Ton",
      "~OK",
      "~Abbrechen",
      "Punktzahl",
      "Zeit",
      "Wort",
      "Wort in Arbeit",
      "Woerterliste",
      "Boggle",
      "Willkommen bei Boggle!",
      "Das Spiel ist vorbei.  Danke fuer das Boggle-Spielen!"
   },
   {  /* Francais */
      "~Jeu",
      "~Nouvelle Partie\tCtrl+N",
      "~Trouver Tous les Mots",
      "~Pause\tCtrl+P",
      "~Fin de Partie\tCtrl+Q",
      "~Quitter\tCtrl+X",
      "~Options",
      "~Detail",
      "~Haut",
      "~Moyen",
      "~Bas",
      "~Langue",
      "~Enregistrer les parametres en quittant",
      "~Executer en arriere-plan\tCtrl+B",
      "~Controle du Cadre\tCtrl+F",
      "~Parametres...",
      "~Aide",
      "~Contenu de l'Aide\tF1",
      "~A propos de Boggle...",
      "Boggle",
      "Options de Boggle",
      "Duree du temps (sec):",
      "~Son",
      "~OK",
      "~Annuler",
      "Score",
      "Temps",
      "Mot",
      "Mot en Cours",
      "Liste de Mots",
      "Boggle",
      "Bienvenue a Boggle!",
      "Le jeu est termine.  Merci d'avoir joue a Boggle!"
   },
   {  /* Italiano */
      "~Gioco",
      "~Nuova Partita\tCtrl+N",
      "~Trova Tutte le Parole",
      "~Pausa\tCtrl+P",
      "~Fine Partita\tCtrl+Q",
      "~Uscita\tCtrl+X",
      "~Opzioni",
      "~Dettaglio",
      "~Alto",
      "~Medio",
      "~Basso",
      "~Lingua",
      "~Salva impostazioni all'uscita",
      "~Esegui in secondo piano\tCtrl+B",
      "~Controlli della Cornice\tCtrl+F",
      "~Impostazioni...",
      "~Aiuto",
      "~Contenuto della Guida\tF1",
      "~Informazioni su Boggle...",
      "Boggle",
      "Opzioni di Boggle",
      "Durata del Tempo (sec):",
      "~Audio",
      "~OK",
      "~Annulla",
      "Punteggio",
      "Tempo",
      "Parola",
      "Parola in Corso",
      "Elenco Parole",
      "Boggle",
      "Benvenuto a Boggle!",
      "Il gioco e finito.  Grazie per aver giocato a Boggle!"
   }
};

/* application state */
static const char  szClientClass[] = "Boggle";
static char        szConfigFile[CCHMAXPATH] = "BOGGLE.CFG";
/* BLDLEVEL record (readable by bldlevel.exe); non-static so it is
 * retained in the data segment. */
const char  bldlevel[] =
   "@#David Boudah:1.1#@##1## 16 Sep 2026 00:00:00      "
   "ARCAOS:::0::::@@Boggle for OS/2, classic word game port\r\n\x1a";

static HAB    hab;
static HMQ    hmq;
static HWND   hwndFrame, hwndClient, hwndMenu;
static HWND   hwndObject;
static HWND   hwndTitleBar, hwndSysMenu, hwndMinMax;

static HWND   hwndWIP, hwndList, hwndSlider;
static HWND   hwndHelp = NULLHANDLE;

static BOOL   bGameOn      = FALSE;
static BOOL   bPaused      = FALSE;
static BOOL   bSound       = TRUE;
static BOOL   bBackGrnd    = FALSE;
static BOOL   bControls    = TRUE;
static BOOL   bSaveOnExit  = TRUE;
static LONG   lTickDurMS   = 1500L;     /* ms per one of 100 timer "ticks" */
static int    nDetail      = 0;         /* 0=high 1=medium 2=low */
int           current_lang = LANG_EN;

static LONG   lArm         = 0L;        /* 0..100 timer position */
static LONG   lScore       = 0L;        /* current game score */
static int    nClientCx, nClientCy;

static char   g_szSystemFont[64];

static VOID ApplySystemFont(HWND hwnd)
{
    WinSetPresParam(hwnd, PP_FONTNAMESIZE,
                    (ULONG)strlen(g_szSystemFont) + 1, g_szSystemFont);
}

static char   szWIP[WORDLENGTH];
static BOOL   bButton1Down = FALSE;

/* forward declarations */
static MRESULT EXPENTRY ClientWndProc(HWND, ULONG, MPARAM, MPARAM);
static MRESULT EXPENTRY OptionsDlgProc(HWND, ULONG, MPARAM, MPARAM);
static MRESULT EXPENTRY AboutDlgProc(HWND, ULONG, MPARAM, MPARAM);

static VOID ApplyLanguage(VOID);
static VOID InitMenu(VOID);
static VOID DoCommand(HWND, ULONG, MPARAM, MPARAM);
static VOID ResetGame(VOID);
static VOID PauseGame(VOID);
static VOID ResumeGame(VOID);
static VOID GameOver(VOID);
static VOID FindAllWords(VOID);
static VOID SubmitFindWord(char *szWord, int nLength);
static VOID SubmitWord(VOID);
static VOID DrawBoard(HPS);
static VOID AddWIPLetter(const char *);
static VOID ResetWIP(VOID);
static BOOL WordInList(const char *);
static VOID ListAddWord(const char *);
static VOID StartTimer(VOID);
static VOID StopTimer(VOID);
static VOID MoveArm(LONG);
static VOID LoadSettings(VOID);
static VOID SaveSettings(VOID);
static VOID ShowFrameControls(VOID);
static VOID HideFrameControls(VOID);
static VOID SetupHelp(VOID);

/* board geometry */
#define BRD_X        40
#define BRD_Y        294

static int PointToSquare(SHORT x, SHORT y)
{
   int col, row;

   if (x < BRD_X || y < BRD_Y)
      return -1;
   col = (x - BRD_X) / SQ_STRIDE;
   row = (y - BRD_Y) / SQ_STRIDE;
   if (col < 0 || col > 3 || row < 0 || row > 3)
      return -1;
   if ((x - BRD_X) % SQ_STRIDE >= SQ_SIZE ||
       (y - BRD_Y) % SQ_STRIDE >= SQ_SIZE)
      return -1;
   return row * 4 + col;
}

int main(void)
{
   ULONG flFrameFlags = FCF_SHELLPOSITION | FCF_SIZEBORDER | FCF_TASKLIST |
                        FCF_MINMAX | FCF_TITLEBAR | FCF_SYSMENU |
                        FCF_MENU | FCF_ACCELTABLE | FCF_ICON;
   QMSG qmsg;
   RECTL rcl;
   LONG  lCxScreen, lCyScreen;

   hab = WinInitialize(0);
   hmq = WinCreateMsgQueue(hab, 0);

   /* Read user's configured system font (e.g. "9.WarpSans") */
   PrfQueryProfileString(HINI_USERPROFILE, "PM_SystemFonts", "WindowText",
                         "9.WarpSans", g_szSystemFont, sizeof(g_szSystemFont));

   WinRegisterClass(hab, szClientClass, (PFNWP)ClientWndProc,
                    CS_SIZEREDRAW | CS_CLIPCHILDREN, 0);

   hwndFrame = WinCreateStdWindow(HWND_DESKTOP, 0L, &flFrameFlags,
                                  szClientClass, "Boggle", 0L,
                                  NULLHANDLE, WND_MAINWIN, &hwndClient);
   if (hwndFrame == NULLHANDLE)
   {
      WinMessageBox(HWND_DESKTOP, HWND_DESKTOP,
                    "Unable to create the Boggle window.",
                    "Boggle System Error", 0, MB_OK | MB_NOICON);
      WinTerminate(hab);
      return 1;
   }

   hwndObject = WinCreateWindow(HWND_OBJECT, WC_FRAME, " ",
                                0L, 0, 0, 0, 0, NULLHANDLE, HWND_TOP,
                                IDM_SUBMENU_GAME, NULL, NULL);
   hwndTitleBar = WinWindowFromID(hwndFrame, FID_TITLEBAR);
   hwndSysMenu  = WinWindowFromID(hwndFrame, FID_SYSMENU);
   hwndMenu     = WinWindowFromID(hwndFrame, FID_MENU);
   hwndMinMax   = WinWindowFromID(hwndFrame, FID_MINMAX);

   DictionaryInit();
   SoundInit();
   BoardInit();
   BoardShuffle();

   /* Locate BOGGLE.CFG in data\ beside the EXE */
   {
      PTIB ptib; PPIB ppib;
      char szExe[CCHMAXPATH], *p;
      if (DosGetInfoBlocks(&ptib, &ppib) == 0 &&
          DosQueryModuleName(ppib->pib_hmte, sizeof(szExe), szExe) == 0)
      {
         p = strrchr(szExe, '\\');
         if (p && (strlen(szExe) + 14) < sizeof(szConfigFile))
         {
            *(p + 1) = '\0';
            sprintf(szConfigFile, "%sdata\\BOGGLE.CFG", szExe);
         }
      }
   }

   LoadSettings();
   InitMenu();
   ApplyLanguage();
   SetupHelp();

   /* size the frame for a 460x400 client, clamp to the screen, center */
   lCxScreen = WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN);
   lCyScreen = WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN);
   rcl.xLeft = 0L; rcl.yBottom = 0L;
   rcl.xRight = 880L; rcl.yTop = 660L;
   WinCalcFrameRect(hwndFrame, &rcl, FALSE);
   if (rcl.xRight > lCxScreen) rcl.xRight = lCxScreen;
   if (rcl.yTop   > lCyScreen) rcl.yTop   = lCyScreen;
   WinSetWindowPos(hwndFrame, HWND_TOP,
                   (lCxScreen - rcl.xRight) / 2, (lCyScreen - rcl.yTop) / 2,
                   rcl.xRight, rcl.yTop,
                   SWP_ACTIVATE | SWP_SHOW | SWP_SIZE | SWP_MOVE);

   if (!bControls)
      HideFrameControls();

   while (WinGetMsg(hab, &qmsg, NULLHANDLE, 0, 0))
      WinDispatchMsg(hab, &qmsg);

   SoundClose();
   if (hwndObject != NULLHANDLE)
      WinDestroyWindow(hwndObject);
   WinDestroyWindow(hwndFrame);
   WinDestroyMsgQueue(hmq);
   WinTerminate(hab);
   return 0;
}

static VOID StartTimer(VOID)
{
   WinStartTimer(hab, hwndClient, ID_TIMER, (LONG)lTickDurMS);
}

static VOID StopTimer(VOID)
{
   WinStopTimer(hab, hwndClient, ID_TIMER);
}

static VOID MoveArm(LONG lValue)
{
   lArm = lValue;
   if (hwndSlider)
      WinSendMsg(hwndSlider, SLM_SETSLIDERINFO,
                 MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_SCALE1),
                 MPFROMLONG(lArm));
}

static VOID DrawBoard(HPS hpsPaint)
{
   int    i, col, row;
   RECTL  rcl, rEdge, rInner;
   FATTRS fat;
   LONG   clrBack;

   /* Swiss Bold Italic — matches original Swiss 10pt Bold Italic */
   memset(&fat, 0, sizeof(fat));
   fat.usRecordLength  = sizeof(FATTRS);
   fat.fsSelection     = FATTR_SEL_BOLD | FATTR_SEL_ITALIC;
   fat.lMaxBaselineExt = 28;   /* ≈10pt at 96-DPI screen, doubled for 80px cells */
   fat.lAveCharWidth   = 0;
   strcpy(fat.szFacename, "Swiss");
   GpiCreateLogFont(hpsPaint, NULL, 1L, &fat);
   GpiSetCharSet(hpsPaint, 1L);

   for (i = 0; i < NUM_SQUARES; i++)
   {
      col = i % 4;
      row = i / 4;
      rcl.xLeft   = BRD_X + col * SQ_STRIDE;
      rcl.yBottom = BRD_Y + row * SQ_STRIDE;
      rcl.xRight  = rcl.xLeft   + SQ_SIZE;
      rcl.yTop    = rcl.yBottom + SQ_SIZE;

      /* Gray for unselected (original RGB 204,204,204), white for selected.
       * Yellow is the board surround + 2px inter-cell gaps only. */
      clrBack = BoardIsSelected(i) ? CLR_WHITE : CLR_PALEGRAY;

      WinFillRect(hpsPaint, &rcl, clrBack);

      /* 3D raised bevel: 4px white highlight on top+left (doubled) */
      rEdge = rcl; rEdge.yBottom = rcl.yTop - 4;
      WinFillRect(hpsPaint, &rEdge, CLR_WHITE);
      rEdge = rcl; rEdge.xRight  = rcl.xLeft + 4;
      WinFillRect(hpsPaint, &rEdge, CLR_WHITE);
      /* 4px dark shadow on bottom+right */
      rEdge = rcl; rEdge.yTop   = rcl.yBottom + 4;
      WinFillRect(hpsPaint, &rEdge, CLR_DARKGRAY);
      rEdge = rcl; rEdge.xLeft  = rcl.xRight - 4;
      WinFillRect(hpsPaint, &rEdge, CLR_DARKGRAY);

      /* Letter centered in inner area (inside bevel) */
      rInner.xLeft   = rcl.xLeft   + 6;
      rInner.yBottom = rcl.yBottom + 6;
      rInner.xRight  = rcl.xRight  - 6;
      rInner.yTop    = rcl.yTop    - 6;
      WinDrawText(hpsPaint, -1, (PCH)BoardLetter(i), &rInner,
                  CLR_BLACK, clrBack,
                  DT_CENTER | DT_VCENTER | DT_ERASERECT);
   }

   GpiSetCharSet(hpsPaint, LCID_DEFAULT);
   GpiDeleteSetId(hpsPaint, 1L);
}

static MRESULT EXPENTRY ClientWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
   switch (msg)
   {
      case WM_CREATE:
         /*
          * Layout (client 440x330, PM coords y=0 at bottom):
          *
          * Mirrors the original IMultiCellCanvas grid from legacy/bogwin.cpp:
          *   row 1 (15px):  list label above list
          *   rows 2-3 (196px total): board (x=20..188) | list (x=200..430)
          *   row 4 (14px):  WIP label (left) | Score label (right)
          *   row 5 (24px):  WIP entry (left) | Score value (right)
          *   row 6 (5px):   spacer
          *   row 7 (14px):  Timer label
          *   row 8 (46px):  Slider spanning full width
          *
          * Board visual y=17..183, list label visual y=2..15.
          */

         /* Right panel: list box (label drawn in WM_PAINT) */
         hwndList     = WinCreateWindow(hwnd, WC_LISTBOX, "",
                                        WS_VISIBLE | LS_MULTIPLESEL,
                                        400, 296, 460, 316, hwnd, HWND_TOP,
                                        IDC_CB_LIST, NULL, NULL);

         /* WIP entry field (label, score, and timer label drawn in WM_PAINT) */
         hwndWIP      = WinCreateWindow(hwnd, WC_ENTRYFIELD, "",
                                        WS_VISIBLE | ES_READONLY | ES_MARGIN,
                                        10, 196, 376, 44, hwnd, HWND_TOP,
                                        IDC_CB_WIP, NULL, NULL);

         /* Submit button — square, same height as the WIP field */
         WinCreateWindow(hwnd, WC_BUTTON, ">",
                         WS_VISIBLE | BS_PUSHBUTTON | BS_NOPOINTERFOCUS,
                         390, 196, 44, 44, hwnd, HWND_TOP,
                         IDC_CB_SUBMIT, NULL, NULL);

         /* Full-width slider at bottom (timer label drawn in WM_PAINT) */
         {
            SLDCDATA sld =
            {
               sizeof(SLDCDATA),
               100,   /* usScale1Increments */
               8,     /* usScale1Spacing: 8px/tick × 100 = 800px scale */
               0, 0
            };
            hwndSlider = WinCreateWindow(hwnd, WC_SLIDER, "",
                                         WS_VISIBLE | SLS_READONLY |
                                         SLS_HORIZONTAL | SLS_SNAPTOINCREMENT |
                                         SLS_RIBBONSTRIP,
                                         10, 10, 860, 110, hwnd, HWND_TOP,
                                         IDC_CB_SLIDER, (PVOID)&sld, NULL);
            WinSendMsg(hwndSlider, SLM_SETTICKSIZE,
                       MPFROM2SHORT(SMA_SETALLTICKS, 6), MPVOID);
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(0),   MPFROMP("0"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(10),  MPFROMP("10"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(20),  MPFROMP("20"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(30),  MPFROMP("30"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(40),  MPFROMP("40"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(50),  MPFROMP("50"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(60),  MPFROMP("60"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(70),  MPFROMP("70"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(80),  MPFROMP("80"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(90),  MPFROMP("90"));
            WinSendMsg(hwndSlider, SLM_SETSCALETEXT,
                       MPFROMSHORT(100), MPFROMP("100"));
         }
         ApplyLanguage();

         /* Apply user's system font to this window and every direct child */
         {
            HWND hwndChild;
            ApplySystemFont(hwnd);
            hwndChild = WinQueryWindow(hwnd, QW_TOP);
            while (hwndChild != NULLHANDLE)
            {
               ApplySystemFont(hwndChild);
               hwndChild = WinQueryWindow(hwndChild, QW_NEXT);
            }
         }
         return 0;

      case WM_PAINT:
      {
         HPS hpsPaint = WinBeginPaint(hwnd, (HPS)NULL, NULL);
         RECTL rcl;

         WinQueryWindowRect(hwnd, &rcl);
         WinFillRect(hpsPaint, &rcl, CLR_DARKGRAY);

         rcl.xLeft   = BRD_X - 4;
         rcl.yBottom = BRD_Y - 4;
         rcl.xRight  = BRD_X + 4 * SQ_STRIDE + 4;
         rcl.yTop    = BRD_Y + 4 * SQ_STRIDE + 4;
         WinFillRect(hpsPaint, &rcl, CLR_YELLOW);

         DrawBoard(hpsPaint);

         /* Labels and score — white text on dark gray background */
         {
            RECTL rText;
            char  szScorePaint[16];

            /* "Word List" above the list box */
            rText.xLeft=400; rText.yBottom=616; rText.xRight=860; rText.yTop=656;
            WinDrawText(hpsPaint, -1, (PCH)tr(STR_LIST), &rText,
                        CLR_WHITE, CLR_DARKGRAY,
                        DT_LEFT | DT_VCENTER | DT_ERASERECT);

            /* "Word in Progress" above the WIP entry field */
            rText.xLeft=10; rText.yBottom=244; rText.xRight=440; rText.yTop=284;
            WinDrawText(hpsPaint, -1, (PCH)tr(STR_WIP), &rText,
                        CLR_WHITE, CLR_DARKGRAY,
                        DT_LEFT | DT_VCENTER | DT_ERASERECT);

            /* "Current Score" label */
            rText.xLeft=450; rText.yBottom=244; rText.xRight=750; rText.yTop=284;
            WinDrawText(hpsPaint, -1, (PCH)tr(STR_SCORE), &rText,
                        CLR_WHITE, CLR_DARKGRAY,
                        DT_LEFT | DT_VCENTER | DT_ERASERECT);

            /* Score value */
            sprintf(szScorePaint, "%ld", lScore);
            rText.xLeft=750; rText.yBottom=196; rText.xRight=870; rText.yTop=240;
            WinDrawText(hpsPaint, -1, (PCH)szScorePaint, &rText,
                        CLR_WHITE, CLR_DARKGRAY,
                        DT_RIGHT | DT_VCENTER | DT_ERASERECT);

            /* "Timer: xx sec" label above the slider */
            {
               char  szTimerLabel[64];
               LONG  lRemainSec = (100L - lArm) * lTickDurMS / 1000L;
               sprintf(szTimerLabel, "%s: %ld sec", tr(STR_TIME), lRemainSec);
               rText.xLeft=10; rText.yBottom=126; rText.xRight=360; rText.yTop=162;
               WinDrawText(hpsPaint, -1, (PCH)szTimerLabel, &rText,
                           CLR_WHITE, CLR_DARKGRAY,
                           DT_LEFT | DT_VCENTER | DT_ERASERECT);
            }
         }

         WinEndPaint(hpsPaint);
         return 0;
      }

      case WM_BUTTON1DOWN:
         bButton1Down = TRUE;
         if (bGameOn)
         {
            int k = PointToSquare(SHORT1FROMMP(mp1), SHORT2FROMMP(mp1));
            if (k >= 0)
            {
               if (!BoardIsSelected(k) && BoardValidNext(k))
               {
                  BoardSelect(k);
                  AddWIPLetter(BoardLetter(k));
                  WinInvalidateRect(hwnd, NULL, FALSE);
               }
            }
         }
         return 0;

      case WM_MOUSEMOVE:
         if (bButton1Down && bGameOn)
         {
            int k = PointToSquare(SHORT1FROMMP(mp1), SHORT2FROMMP(mp1));
            if (k >= 0)
            {
               /* only trigger when near the center of the square */
               int rx = (SHORT1FROMMP(mp1) - BRD_X) % SQ_STRIDE;
               int ry = (SHORT2FROMMP(mp1) - BRD_Y) % SQ_STRIDE;
               if (rx >= 20 && rx <= 60 && ry >= 20 && ry <= 60 &&
                   !BoardIsSelected(k) && BoardValidNext(k))
               {
                  BoardSelect(k);
                  AddWIPLetter(BoardLetter(k));
                  WinInvalidateRect(hwnd, NULL, FALSE);
               }
            }
         }
         return 0;

      case WM_BUTTON1UP:
         {
            int k = PointToSquare(SHORT1FROMMP(mp1), SHORT2FROMMP(mp1));
            if (bGameOn && k >= 0 && !BoardIsSelected(k) &&
                !BoardValidNext(k) && bSound)
               SoundPlay("badword.wav", hwnd);
            bButton1Down = FALSE;
         }
         return 0;

      case WM_BUTTON2DOWN:
         if (bGameOn)
            SubmitWord();
         return 0;

      case WM_TIMER:
         if (bGameOn && !bPaused)
         {
            MoveArm(lArm + 1);
            WinInvalidateRect(hwnd, NULL, FALSE);
            if (lArm >= 100L)
               GameOver();
         }
         return 0;

      case MM_MCINOTIFY:
         SoundOnNotify(mp1, mp2);
         return 0;

      case WM_COMMAND:
         DoCommand(hwnd, msg, mp1, mp2);
         return 0;

      case WM_SYSCOMMAND:
         if (SHORT1FROMMP(mp1) == SC_MINIMIZE && !bBackGrnd)
            PauseGame();
         break;

      case WM_SETFOCUS:
         if ((BOOL)SHORT1FROMMP(mp2))
            ResumeGame();
         else if (!bBackGrnd)
            PauseGame();
         return 0;

      case WM_CLOSE:
         if (bSaveOnExit)
            SaveSettings();
         WinPostMsg(hwnd, WM_QUIT, MPVOID, MPVOID);
         return 0;

      case WM_DESTROY:
         StopTimer();
         if (hwndHelp != NULLHANDLE)
         {
            WinDestroyHelpInstance(hwndHelp);
            hwndHelp = NULLHANDLE;
         }
         return 0;

      case WM_SIZE:
         nClientCx = SHORT1FROMMP(mp2);
         nClientCy = SHORT2FROMMP(mp2);
         return 0;
   }
   return WinDefWindowProc(hwnd, msg, mp1, mp2);
}

static VOID DoCommand(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
   switch (SHORT1FROMMP(mp1))
   {
      case IDC_CB_SUBMIT:
         SubmitWord();
         break;

      case IDM_NEW:
         ResetGame();
         break;

      case IDM_FIND_ALL:
         FindAllWords();
         break;

      case IDM_PAUSE:
         if (bGameOn)
         {
            if (bPaused)
               ResumeGame();
            else
               PauseGame();
         }
         break;

      case IDM_QUIT:
         if (bGameOn)
            GameOver();
         break;

      case IDM_EXIT:
         WinPostMsg(hwnd, WM_CLOSE, MPVOID, MPVOID);
         break;

      case IDM_HIGHDET:
      case IDM_MEDIUMDET:
      case IDM_LOWDET:
         WinSendMsg(hwndMenu, MM_SETITEMATTR,
                    MPFROM2SHORT(IDM_HIGHDET + nDetail, TRUE),
                    MPFROM2SHORT(MIA_CHECKED, 0));
         nDetail = SHORT1FROMMP(mp1) - IDM_HIGHDET;
         WinSendMsg(hwndMenu, MM_SETITEMATTR,
                    MPFROM2SHORT(IDM_HIGHDET + nDetail, TRUE),
                    MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
         break;

      case IDM_SAVEONEXIT:
         bSaveOnExit = !bSaveOnExit;
         bSaveOnExit ? WinSendMsg(hwndMenu, MM_SETITEMATTR,
                                  MPFROM2SHORT(IDM_SAVEONEXIT, TRUE),
                                  MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED)) :
                       WinSendMsg(hwndMenu, MM_SETITEMATTR,
                                  MPFROM2SHORT(IDM_SAVEONEXIT, TRUE),
                                  MPFROM2SHORT(MIA_CHECKED, 0));
         break;

      case IDM_BACKGRND:
         bBackGrnd = !bBackGrnd;
         bBackGrnd ? WinSendMsg(hwndMenu, MM_SETITEMATTR,
                                MPFROM2SHORT(IDM_BACKGRND, TRUE),
                                MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED)) :
                     WinSendMsg(hwndMenu, MM_SETITEMATTR,
                                MPFROM2SHORT(IDM_BACKGRND, TRUE),
                                MPFROM2SHORT(MIA_CHECKED, 0));
         break;

      case IDM_FRAME:
         bControls = !bControls;
         if (bControls)
            ShowFrameControls();
         else
            HideFrameControls();
         break;

      case IDM_SETTINGS:
         WinDlgBox(HWND_DESKTOP, hwndClient, (PFNWP)OptionsDlgProc,
                   NULLHANDLE, IDD_OPTIONS, NULL);
         break;

      case IDM_LANG_EN:
      case IDM_LANG_ES:
      case IDM_LANG_NL:
      case IDM_LANG_DE:
      case IDM_LANG_FR:
      case IDM_LANG_IT:
         WinSendMsg(hwndMenu, MM_SETITEMATTR,
                    MPFROM2SHORT(IDM_LANG_EN + current_lang, TRUE),
                    MPFROM2SHORT(MIA_CHECKED, 0));
         current_lang = SHORT1FROMMP(mp1) - IDM_LANG_EN;
         WinSendMsg(hwndMenu, MM_SETITEMATTR,
                    MPFROM2SHORT(IDM_LANG_EN + current_lang, TRUE),
                    MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
         ApplyLanguage();
         SetupHelp();
         break;

      case IDM_HELP:
         if (hwndHelp != NULLHANDLE)
            WinSendMsg(hwndHelp, HM_HELP_INDEX, 0L, 0L);
         break;

      case IDM_HELP_ABOUT:
         WinDlgBox(HWND_DESKTOP, hwndClient, (PFNWP)AboutDlgProc,
                   NULLHANDLE, IDD_ABOUT, NULL);
         break;
   }
}

static VOID ResetGame(VOID)
{
   StopTimer();
   BoardShuffle();
   ResetWIP();
   lScore = 0L;
   WinSendMsg(hwndList, LM_DELETEALL, MPVOID, MPVOID);
   MoveArm(0L);
   bGameOn = TRUE;
   bPaused = FALSE;

   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_FIND_ALL, TRUE),
              MPFROM2SHORT(MIA_DISABLED, MIA_DISABLED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_PAUSE, TRUE),
              MPFROM2SHORT(MIA_DISABLED, 0));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_QUIT, TRUE),
              MPFROM2SHORT(MIA_DISABLED, 0));
   WinInvalidateRect(hwndClient, NULL, FALSE);
   StartTimer();
}

static VOID PauseGame(VOID)
{
   if (!bGameOn || bPaused)
      return;
   bPaused = TRUE;
   StopTimer();
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_PAUSE, TRUE),
              MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
}

static VOID ResumeGame(VOID)
{
   if (!bGameOn || !bPaused)
      return;
   bPaused = FALSE;
   StartTimer();
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_PAUSE, TRUE),
              MPFROM2SHORT(MIA_CHECKED, 0));
}

static VOID GameOver(VOID)
{
   StopTimer();
   bGameOn = FALSE;
   if (bSound)
      SoundPlay("gameover.wav", hwndClient);
   BoardClearSelections();
   ResetWIP();
   WinInvalidateRect(hwndClient, NULL, FALSE);

   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_PAUSE, TRUE),
              MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED | MIA_DISABLED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_QUIT, TRUE),
              MPFROM2SHORT(MIA_DISABLED, MIA_DISABLED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_FIND_ALL, TRUE),
              MPFROM2SHORT(MIA_DISABLED, 0));

   WinMessageBox(HWND_DESKTOP, hwndClient, tr(STR_MSG_TIMESUP),
                 tr(STR_MSG_TITLE), 0, MB_OK | MB_INFORMATION | MB_MOVEABLE);
}

static VOID FindAllWords(VOID)
{
   SHORT i, nItems;

   WinSetPointer(HWND_DESKTOP, SPTR_WAIT);
   BoardFindAll(SubmitFindWord);
   nItems = SHORT1FROMMP(WinSendMsg(hwndList, LM_QUERYITEMCOUNT,
                                    MPVOID, MPVOID));
   for (i = 0; i < nItems; i++)
      WinSendMsg(hwndList, LM_SELECTITEM, MPFROM2SHORT(i, TRUE), MPVOID);
   WinSetPointer(HWND_DESKTOP, SPTR_ARROW);
}

static VOID AddWIPLetter(const char *szLetter)
{
   if (strlen(szWIP) < (WORDLENGTH - (int)strlen(szLetter)))
   {
      strcat(szWIP, szLetter);
      WinSetWindowText(hwndWIP, szWIP);
   }
}

static VOID ResetWIP(VOID)
{
   szWIP[0] = '\0';
   if (hwndWIP)
      WinSetWindowText(hwndWIP, szWIP);
}

static BOOL WordInList(const char *szWord)
{
   SHORT nItems = SHORT1FROMMP(WinSendMsg(hwndList, LM_QUERYITEMCOUNT,
                                          MPVOID, MPVOID));
   SHORT i;

   for (i = 0; i < nItems; i++)
   {
      CHAR szItem[WORDLENGTH];
      WinSendMsg(hwndList, LM_QUERYITEMTEXT, MPFROM2SHORT(i, WORDLENGTH),
                 MPFROMP(szItem));
      if (stricmp(szItem, szWord) == 0)
         return TRUE;
   }
   return FALSE;
}

static VOID ListAddWord(const char *szWord)
{
   if (!WordInList(szWord))
      WinSendMsg(hwndList, LM_INSERTITEM,
                 MPFROM2SHORT(LIT_SORTASCENDING, 0), MPFROMP(szWord));
}

static VOID SubmitFindWord(char *szWord, int nLength)
{
   if (nLength > 2)
      ListAddWord(szWord);
}

static VOID SubmitWord(VOID)
{
   char UString[WORDLENGTH];

   if (!bGameOn)
      return;

   DictionaryToUpper(UString, szWIP);

   if (strlen(UString) > 2)
   {
      if (WordInList(UString))
      {
         if (bSound)
            SoundPlay("usedword.wav", hwndClient);
      }
      else if (DictionaryLookup(UString) < 0)
      {
         if (bSound)
            SoundPlay("boing.wav", hwndClient);
      }
      else
      {
         ListAddWord(UString);

         if (strlen(UString) > 4)
         {
            if (strlen(UString) > 7)
               lScore += 11L;
            else if (strlen(UString) == 7)
               lScore += 5L;
            else if (strlen(UString) == 6)
               lScore += 3L;
            else
               lScore += 2L;
            if (bSound)
               SoundPlay("excelnt.wav", hwndClient);
         }
         else
         {
            lScore += 1L;
            if (bSound)
               SoundPlay("goodword.wav", hwndClient);
         }
      }
   }
   else
   {
      if (bSound)
         SoundPlay("badword.wav", hwndClient);
   }

   ResetWIP();
   BoardClearSelections();
   WinInvalidateRect(hwndClient, NULL, FALSE);
}

static const char *HelpFileName(void)
{
   static const char *const szNames[LANG_COUNT] = {
      "boggle_en.hlp",
      "boggle_es.hlp",
      "boggle_nl.hlp",
      "boggle_de.hlp",
      "boggle_fr.hlp",
      "boggle_it.hlp"
   };
   return szNames[current_lang];
}

static VOID SetupHelp(VOID)
{
   HELPINIT hi;
   PTIB  ptib;
   PPIB  ppib;
   char  szExe[CCHMAXPATH];
   static char szHelpPath[CCHMAXPATH];
   char *p;

   if (hwndHelp != NULLHANDLE)
   {
      WinDestroyHelpInstance(hwndHelp);
      hwndHelp = NULLHANDLE;
   }

   szHelpPath[0] = '\0';
   if (DosGetInfoBlocks(&ptib, &ppib) == 0 &&
       DosQueryModuleName(ppib->pib_hmte, sizeof(szExe), szExe) == 0)
   {
      p = strrchr(szExe, '\\');
      if (p && (strlen(szExe) + 6 + strlen(HelpFileName())) < sizeof(szHelpPath))
      {
         *(p + 1) = '\0';
         sprintf(szHelpPath, "%shelp\\%s", szExe, HelpFileName());
      }
   }
   if (szHelpPath[0] == '\0')
      sprintf(szHelpPath, "help\\%s", HelpFileName());

   memset(&hi, 0, sizeof(hi));
   hi.cb                 = sizeof(HELPINIT);
   hi.pszHelpWindowTitle = (PSZ)"Boggle Help";
   hi.pszHelpLibraryName = (PSZ)szHelpPath;
   hi.fShowPanelId       = CMIC_HIDE_PANEL_ID;

   hwndHelp = WinCreateHelpInstance(hab, &hi);
}

static VOID ApplyLanguage(VOID)
{
   if (hwndFrame != NULLHANDLE)
      WinSetWindowText(hwndFrame, tr(STR_TITLE));
   /* Labels and score are drawn in WM_PAINT; force a repaint for lang change */
   if (hwndClient != NULLHANDLE)
      WinInvalidateRect(hwndClient, NULL, FALSE);

   /* the menu is only available after WinCreateStdWindow returns in main() */
   if (hwndMenu == NULLHANDLE)
      return;

   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_NEW, TRUE), (MPARAM)tr(STR_NEW));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_FIND_ALL, TRUE), (MPARAM)tr(STR_FINDALL));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_PAUSE, TRUE), (MPARAM)tr(STR_PAUSE));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_QUIT, TRUE), (MPARAM)tr(STR_QUIT));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_EXIT, TRUE), (MPARAM)tr(STR_EXIT));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_HIGHDET, TRUE), (MPARAM)tr(STR_HIGHDET));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_MEDIUMDET, TRUE), (MPARAM)tr(STR_MEDIUMDET));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_LOWDET, TRUE), (MPARAM)tr(STR_LOWDET));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SAVEONEXIT, TRUE), (MPARAM)tr(STR_SAVEONEXIT));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_BACKGRND, TRUE), (MPARAM)tr(STR_BACKGRND));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_FRAME, TRUE), (MPARAM)tr(STR_FRAME));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SETTINGS, TRUE), (MPARAM)tr(STR_SETTINGS));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_HELP, TRUE), (MPARAM)tr(STR_HELP_CONTENTS));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_HELP_ABOUT, TRUE), (MPARAM)tr(STR_ABOUT));

   /* submenu titles in the current language */
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SUBMENU_GAME, TRUE), (MPARAM)tr(STR_GAME));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SUBMENU_OPTIONS, TRUE), (MPARAM)tr(STR_OPTIONS));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SUBMENU_DETAIL, TRUE), (MPARAM)tr(STR_DETAIL));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SUBMENU_LANG, TRUE), (MPARAM)tr(STR_LANGUAGE));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT,
              MPFROM2SHORT(IDM_SUBMENU_HELP, TRUE), (MPARAM)tr(STR_HELP));
}

static VOID InitMenu(VOID)
{
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_FIND_ALL, TRUE),
              MPFROM2SHORT(MIA_DISABLED, MIA_DISABLED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_PAUSE, TRUE),
              MPFROM2SHORT(MIA_DISABLED, MIA_DISABLED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_QUIT, TRUE),
              MPFROM2SHORT(MIA_DISABLED, MIA_DISABLED));

   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_HIGHDET + nDetail, TRUE),
              MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
   WinSendMsg(hwndMenu, MM_SETITEMATTR,
              MPFROM2SHORT(IDM_LANG_EN + current_lang, TRUE),
              MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
   if (bSaveOnExit)
      WinSendMsg(hwndMenu, MM_SETITEMATTR,
                 MPFROM2SHORT(IDM_SAVEONEXIT, TRUE),
                 MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
   if (bBackGrnd)
      WinSendMsg(hwndMenu, MM_SETITEMATTR,
                 MPFROM2SHORT(IDM_BACKGRND, TRUE),
                 MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
   if (bControls)
      WinSendMsg(hwndMenu, MM_SETITEMATTR,
                 MPFROM2SHORT(IDM_FRAME, TRUE),
                 MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));
}

static VOID LoadSettings(VOID)
{
   FILE *fp = fopen(szConfigFile, "rb");
   int  nSave, nDet, nLng;
   LONG lTick;
   int  nSound, nBack, nCtrl;

   if (!fp)
      return;

   if (fread(&nSave, sizeof(int), 1, fp) != 1 ||
       fread(&nDet,  sizeof(int), 1, fp) != 1 ||
       fread(&nLng,  sizeof(int), 1, fp) != 1 ||
       fread(&lTick, sizeof(LONG), 1, fp) != 1 ||
       fread(&nSound, sizeof(int), 1, fp) != 1 ||
       fread(&nBack, sizeof(int), 1, fp) != 1 ||
       fread(&nCtrl, sizeof(int), 1, fp) != 1)
   {
      fclose(fp);
      return;
   }
   fclose(fp);

   bSaveOnExit  = (nSave != 0);
   nDetail      = nDet;
   if (nDetail < 0 || nDetail > 2) nDetail = 0;
   current_lang = nLng;
   if (current_lang < 0 || current_lang >= LANG_COUNT) current_lang = LANG_EN;
   if (lTick >= 100L && lTick <= 5000L) lTickDurMS = lTick;
   bSound    = (nSound != 0);
   bBackGrnd = (nBack != 0);
   bControls = (nCtrl != 0);
}

static VOID SaveSettings(VOID)
{
   FILE *fp = fopen(szConfigFile, "wb");
   int nSave = 1, nDet, nLng, nSound, nBack, nCtrl;

   if (!fp)
      return;
   nSave  = bSaveOnExit ? 1 : 0;
   nDet   = nDetail;
   nLng   = current_lang;
   nSound = bSound ? 1 : 0;
   nBack  = bBackGrnd ? 1 : 0;
   nCtrl  = bControls ? 1 : 0;
   fwrite(&nSave, sizeof(int), 1, fp);
   fwrite(&nDet,  sizeof(int), 1, fp);
   fwrite(&nLng,  sizeof(int), 1, fp);
   fwrite(&lTickDurMS, sizeof(LONG), 1, fp);
   fwrite(&nSound, sizeof(int), 1, fp);
   fwrite(&nBack, sizeof(int), 1, fp);
   fwrite(&nCtrl, sizeof(int), 1, fp);
   fclose(fp);
}

static VOID HideFrameControls(VOID)
{
   WinSetParent(hwndTitleBar, hwndObject, FALSE);
   WinSetParent(hwndSysMenu, hwndObject, FALSE);
   WinSetParent(hwndMenu, hwndObject, FALSE);
   WinSetParent(hwndMinMax, hwndObject, FALSE);
   WinSendMsg(hwndFrame, WM_UPDATEFRAME,
              (MPARAM)(FCF_TITLEBAR | FCF_SYSMENU | FCF_MINMAX | FCF_MENU),
              MPVOID);
}

static VOID ShowFrameControls(VOID)
{
   WinSetParent(hwndTitleBar, hwndFrame, FALSE);
   WinSetParent(hwndSysMenu, hwndFrame, FALSE);
   WinSetParent(hwndMenu, hwndFrame, FALSE);
   WinSetParent(hwndMinMax, hwndFrame, FALSE);
   WinSendMsg(hwndFrame, WM_UPDATEFRAME,
              (MPARAM)(FCF_TITLEBAR | FCF_SYSMENU | FCF_MINMAX | FCF_MENU),
              MPVOID);
   WinInvalidateRect(hwndFrame, NULL, TRUE);
}

static MRESULT EXPENTRY OptionsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
   switch (msg)
   {
      case WM_INITDLG:
         WinSetWindowText(hwnd, tr(STR_OPTTITLE));
         WinSetDlgItemText(hwnd, IDD_SOUND, tr(STR_OPT_SOUND));
         {
            char szSecs[16];
            sprintf(szSecs, "%ld", lTickDurMS / 10L);
            WinSetDlgItemText(hwnd, IDD_TIMERLEN, szSecs);
            WinSendDlgItemMsg(hwnd, IDD_SOUND, BM_SETCHECK,
                              MPFROM2SHORT(bSound ? 1 : 0, 0), MPVOID);
         }
         return 0;

      case WM_COMMAND:
         switch (COMMANDMSG(&msg)->cmd)
         {
            case DID_OK:
            {
               char szSecs[16];
               LONG lSecs;
               WinQueryDlgItemText(hwnd, IDD_TIMERLEN, (LONG)sizeof(szSecs), szSecs);
               lSecs = atol(szSecs);
               if (lSecs < 10L)  lSecs = 10L;
               if (lSecs > 300L) lSecs = 300L;
               lTickDurMS = lSecs * 10L;
               bSound = WinQueryButtonCheckstate(hwnd, IDD_SOUND) ? TRUE : FALSE;
               WinDismissDlg(hwnd, 0);
            }
            return 0;

            case DID_CANCEL:
               WinDismissDlg(hwnd, 0);
               return 0;
         }
         break;
   }
   return WinDefDlgProc(hwnd, msg, mp1, mp2);
}

static MRESULT EXPENTRY AboutDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
   switch (msg)
   {
      case WM_COMMAND:
         switch (COMMANDMSG(&msg)->cmd)
         {
            case DID_OK:
            case DID_CANCEL:
               WinDismissDlg(hwnd, 0);
               return 0;
         }
         break;
   }
   return WinDefDlgProc(hwnd, msg, mp1, mp2);
}
