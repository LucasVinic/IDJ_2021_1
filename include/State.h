#ifndef state
#define state
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

#include "Music.h"
#include "Sprite.h"

using namespace std;

class State {
  private: 
    Sprite bg;
    Musica music;
    bool quitRequested

  public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();  
};

#endif