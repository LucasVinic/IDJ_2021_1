#ifndef state_h
#define state_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Music.h"
#include "Sprite.h"

using namespace std;

class State {
  private: 
    Sprite* bg;
    Music music;
    bool quitRequested;
    vector<unique_ptr<GameObject>> objectArray;

  public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    void Input();
    void AddObject(int mouseX, int mouseY);
};
#endif