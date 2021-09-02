#ifndef game
#define game
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

#include "State.h"

using namespace std;

class Game {
  private: 
    Game (
      string title,
      int width,
      int height
    );
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;

  public: 
    ~Game ();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();

};
#endif
