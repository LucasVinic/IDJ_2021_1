#ifndef sprite
#define sprite
#include "SDL.h"
#include <string>

using namespace std;

class Sprite {
  private: 
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

  public:
    Sprite();
    ~Sprite();
    Sprite(string file);
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    
}

#endif