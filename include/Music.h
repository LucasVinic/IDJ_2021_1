#ifndef music_h
#define music_h
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
    ~Music();
    void Play(int times);
    void Stop(int msToStop);
    void Open(string file);
    bool IsOpen();
};

#endif
