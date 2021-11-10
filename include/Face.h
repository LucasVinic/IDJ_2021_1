#ifndef face_h
#define face_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "Component.h"

using namespace std;

class Face: Component{
  private:
    int hitpoints;
    bool isDying;
    float total_death_time;
    float death_time;
  
  public:
    Face(GameObject& associated);
    void Damage(int damage);

    void Update(float dt);
    void Render();
    bool Is(string type);
};
#endif