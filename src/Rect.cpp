#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Rect.h"
#include <string>
#include <memory>

Rect::Rect (float x1, float y1, float w1, float h1) {
  x = x1;
  y = y1;
  w = w1;
  h = h1;
}
