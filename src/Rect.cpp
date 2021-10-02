#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include <memory>

#include "Rect.h"
#include "Vec2.h"

Rect::Rect (float x1, float y1, float w1, float h1) {
  x = x1;
  y = y1;
  w = w1;
  h = h1;
}

Vec2 Rect::Center () {
  return Vec2((y+h)/2, (x+w)/2);
}

Vec2 Rect::Center2Rect (Rect retangulo) {
  Vec2 recBase = Center();
  return Vec2(recBase.x - retangulo.Center().x, recBase.y - retangulo.Center().y);
}

bool Rect::isDotInRect (Vec2 vetor) {
  if(y < vetor.y < y+h && x < vetor.x < x+w) 
    return true;
  return false;
}

Rect Rect::SumRectVec (Vec2 vetor) {
  return Rect(x + vetor.x, y + vetor.y, w, h);
}
