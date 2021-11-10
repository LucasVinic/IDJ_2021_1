#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Vec2.h"
#include "math.h"

Vec2::Vec2 (float x1, float y1) {
  x = x1;
  y = y1;
}

Vec2 Vec2::Sum (Vec2 vetor) {
  return Vec2(x + vetor.x, y + vetor.y);
}

Vec2 Vec2::Sub (Vec2 vetor) {
  return Vec2(x - vetor.x, y - vetor.y);
}

Vec2 Vec2::Mul (float escalar) {
  return (Vec2(x * escalar, y * escalar));
}

float Vec2::Magnitude () {
  return sqrt(x*x + y*y);
}

Vec2 Vec2::VetorNorm () {
  int aux = Magnitude();
  return Vec2(x/aux, y/aux);
}

float Vec2::Distancia (Vec2 vetor) {
  return Sub(vetor).Magnitude();
}

// desenvolvimento
/* float Vec2::Angulo () {}

float Vec2::Angulo2Pontos (Vec2 vetor) {}

Vec2 Vec2::Rotacao () {} */

