/*****************************************************************************
* Program:  SOUND.C
* Purpose:  Wave sound playback for the Boggle game using the OS/2 MCI
*           waveaudio device.  Each sound is opened, played with notify,
*           and closed when playback completes.
*
* Port notes:  the original used OS/2 voice definitions and a custom
*           IMMWaveAudio object; this port drives the MCI string
*           interface directly, which needs no extra runtime objects.
*****************************************************************************/
#include "boggle.h"
#include "sound.h"

#include <mcios2.h>

#define MCI_ALIAS "bogg"      /* waveaudio alias used for playback */

static BOOL bDeviceOpen = FALSE;   /* is the alias currently opened? */
static char g_szSoundDir[CCHMAXPATH] = "";   /* "X:\path\to\sound\" */


/*****************************************************************************
* Function: SoundInit
* Parms:    none
* Purpose:  Initialise the sound subsystem.  Determines the sound file
*           directory as the "sound\" subdirectory of the EXE's location.
*           The device itself is opened lazily on the first SoundPlay call.
* Returns:  Nothing
*****************************************************************************/
void SoundInit(void)
{
   PTIB   ptib;
   PPIB   ppib;
   char   szExePath[CCHMAXPATH];
   char  *pLastSlash;

   bDeviceOpen = FALSE;
   g_szSoundDir[0] = '\0';

   /* Get the full path of the running EXE */
   if (DosGetInfoBlocks(&ptib, &ppib) == 0 &&
       DosQueryModuleName(ppib->pib_hmte, sizeof(szExePath), szExePath) == 0)
   {
      /* Strip the EXE filename to get the directory */
      pLastSlash = strrchr(szExePath, '\\');
      if (pLastSlash)
      {
         *(pLastSlash + 1) = '\0';   /* keep trailing backslash */
         /* szExePath is now "X:\path\to\" */
         if (strlen(szExePath) + 6 < sizeof(g_szSoundDir))
            sprintf(g_szSoundDir, "%ssound\\", szExePath);
      }
   }
}


/*****************************************************************************
* Function: SoundPlay
* Parms:    file - the wave file name, hwndNotify - notify target window
* Purpose:  Play the given wave file.  Any sound currently playing is
*           first stopped and closed so the two never overlap.  Errors
*           are ignored - the game plays on without sound.
* Returns:  Nothing
*****************************************************************************/
void SoundPlay(const char *file, HWND hwndNotify)
{
   char cmd[512];
   char szFullPath[CCHMAXPATH];
   ULONG rc;

   if (!file || !*file)
      return;

   /* Build the full path: sound dir (if known) + filename */
   if (g_szSoundDir[0] != '\0')
      sprintf(szFullPath, "%s%s", g_szSoundDir, file);
   else
      strcpy(szFullPath, file);

   /* Close any sound still open so the alias is free */
   if (bDeviceOpen)
   {
      mciSendString("close " MCI_ALIAS, (PSZ)NULL, 0, (HWND)NULL, 0);
      bDeviceOpen = FALSE;
   }

   /* Open the wave file under a fixed alias */
   sprintf(cmd, "open \"%s\" type waveaudio alias " MCI_ALIAS " wait", szFullPath);
   rc = mciSendString(cmd, (PSZ)NULL, 0, (HWND)NULL, 0);
   if (rc != 0L)
      return;
   bDeviceOpen = TRUE;

   /* Play it back asynchronously, notifying our window when done */
   sprintf(cmd, "play " MCI_ALIAS " notify");
   mciSendString(cmd, (PSZ)NULL, 0, hwndNotify, 0);

   /* If the "play" failed the device stays open until the next
    * SoundPlay or SoundClose; that is safe. */
}


/*****************************************************************************
* Function: SoundOnNotify
* Parms:    mp1, mp2 - parameters of the MM_MCINOTIFY message
* Purpose:  When playback of our sound finishes, close the device.
*           Called from the owner window's message procedure.
* Returns:  Nothing
*****************************************************************************/
void SoundOnNotify(MPARAM mp1, MPARAM mp2)
{
   /* SHORT1FROMMP(mp1) = notification code,
    * SHORT2FROMMP(mp2) = command being reported (MCI_PLAY). */
   if (SHORT2FROMMP(mp2) == MCI_PLAY &&
       SHORT1FROMMP(mp1) == MCI_NOTIFY_SUCCESSFUL)
   {
      if (bDeviceOpen)
      {
         mciSendString("close " MCI_ALIAS, (PSZ)NULL, 0, (HWND)NULL, 0);
         bDeviceOpen = FALSE;
      }
   }
}


/*****************************************************************************
* Function: SoundClose
* Parms:    none
* Purpose:  Close any open sound device.  Called when the game exits.
* Returns:  Nothing
*****************************************************************************/
void SoundClose(void)
{
   if (bDeviceOpen)
   {
      mciSendString("close " MCI_ALIAS, (PSZ)NULL, 0, (HWND)NULL, 0);
      bDeviceOpen = FALSE;
   }
}
