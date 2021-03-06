#ifndef sprite_h
#define sprite_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "Component.h"
#include "GameObject.h"

using namespace std;

class Sprite: Component {
  private: 
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

  public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y, int w, int h);
    void Render();
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update();
    bool Is(string type);
};

#endif