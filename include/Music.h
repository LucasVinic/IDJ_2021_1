#ifndef music
#define music
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

class Music {
  private: 
    Mix_Music* music;

  public:
    Music();
    Music(string file);
    void Play(int times);
    void Stop(int msToStop);
    void Open(string file);
    bool IsOpen();
};

#endif

/*
+ Music()
+ Music(file : std::string)
+ Play (times : int = -1) : void
+ Stop (msToStop : int = 1500) : void
+ Open (file : std::string) : void
+ IsOpen () : bool
- music : Mix_Music*
*/