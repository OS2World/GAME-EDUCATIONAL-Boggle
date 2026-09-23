#ifndef SOUND_HPP
#define SOUND_HPP

#include <immwave.hpp>

//**************************************************************************
// Class:   Sound
//                                                                         *
// Purpose: Provide .wav file support to an application
//**************************************************************************
class Sound 
{
public:
  Sound();
  ~Sound();
  void playSound(IString fileName);

protected:

private:
  IMMWaveAudio *wavPlayer;
};

#endif


