#ifndef rect_h
#define rect_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

class Rect {
  public:
    float x;
    float y;
    float w;
    float h;
    Rect(float x, float y, float w, float h);
};

#endif