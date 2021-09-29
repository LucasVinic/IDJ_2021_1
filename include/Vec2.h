#ifndef vec2_h
#define vec2_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

class Vec2 {
  public:
    float x;
    float y;
    Vec2 (float x, float y);
    Vec2 Sum (Vec2 vetor);
    Vec2 Sub (Vec2 vetor);
    Vec2 Mul (float escalar);
    float Magnitude ();
    Vec2 VetorNorm ();
    float Distancia (Vec2 vetor);
    float Angulo ();
    float Angulo2Pontos (Vec2 vetor);
    Vec2 Rotacao ();
    
};

#endif