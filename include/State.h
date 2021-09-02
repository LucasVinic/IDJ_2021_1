#ifndef state
#define state
#include "SDL.h"
#include <string>

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
}

#endif