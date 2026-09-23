/*****************************************************************************
* Program:  SOUND.H
* Purpose:  WAV file playback via the MCI "waveaudio" device.
*****************************************************************************/
#ifndef SOUND_H
#define SOUND_H

/*****************************************************************************
* Function: SoundInit
* Parms:    none
* Purpose:  Reset the sound system state.  No device is opened until the
*           first sound is played.
* Returns:  nothing
*****************************************************************************/
void SoundInit(void);

/*****************************************************************************
* Function: SoundPlay
* Parms:    file - name of the .wav file to play (working directory)
*           hwndNotify - window that receives the MM_MCINOTIFY message
* Purpose:  Play a wave file asynchronously.  If a sound is already
*           playing it is stopped first.  Failures are silently ignored
*           (the game plays on without sound).
* Returns:  nothing
*****************************************************************************/
void SoundPlay(const char *file, HWND hwndNotify);

/*****************************************************************************
* Function: SoundOnNotify
* Parms:    mp1, mp2 - parameters of the received MM_MCINOTIFY message
* Purpose:  Close the sound device when playback of a sound finishes.
* Returns:  nothing
*****************************************************************************/
void SoundOnNotify(MPARAM mp1, MPARAM mp2);

/*****************************************************************************
* Function: SoundClose
* Parms:    none
* Purpose:  Close any open sound device (called at application exit).
* Returns:  nothing
*****************************************************************************/
void SoundClose(void);

#endif  /* SOUND_H */
