#ifndef game
#define game
#include "SDL.h"
#include <string>

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
