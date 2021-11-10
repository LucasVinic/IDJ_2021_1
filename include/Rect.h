#ifndef rect_h
#define rect_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

#include "Vec2.h"

using namespace std;

class Rect {
  public:
    float x;
    float y;
    float w;
    float h;
    Rect (float x, float y, float w, float h);
    Vec2 Center ();
    Vec2 Center2Rect (Rect retangulo);
    bool isDotInRect (Vec2 vetor);
    Rect SumRectVec (Vec2 vetor);

    bool contains(int x, int y);
    bool contains(float x, float y);
    bool contains(Vec2 point);
};

#endif