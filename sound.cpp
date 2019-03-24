/*****************************************************************************
* Program:  SOUND.CPP
* Purpose:  handles the playing of .WAV files
*****************************************************************************/
#include "sound.hpp"


/*****************************************************************************
* Function: Sound
* Parms:    none
* Purpose:  Constructor - instantiate the WAV audio device 
* Returns:  Nothing
*****************************************************************************/
Sound::Sound()
{
   try
   {
      wavPlayer = new IMMWaveAudio(true);
   }
   catch (IException& exc)
   {
      IString msg = "Could not open the wave audio device.  The wave audio functions are disabled.";
      throw msg;
   }
}

/*****************************************************************************
* Function: ~Sound
* Parms:    none
* Purpose:  Destructor - delete the WAV audio device 
* Returns:  Nothing
*****************************************************************************/
Sound::~Sound()
{
   if(wavPlayer) 
      delete wavPlayer;
}


/*****************************************************************************
* Function: playSound
* Parms:    fileName - filename of the .wav file to play
* Purpose:  calls the IBM class lib functions to load a .WAV file and play it
* Returns:  Nothing
*****************************************************************************/
void Sound::playSound(IString fileName)
{
   wavPlayer->loadOnThread(fileName, true);
   wavPlayer->play();
}   



