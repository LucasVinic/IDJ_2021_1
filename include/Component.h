#ifndef component_h
#define component_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
class Component;
#include "GameObject.h"

using namespace std;

class Component {
  protected: 
    GameObject& associated;

  public:
    Component(GameObject& associated);
    virtual ~Component();

    void virtual Update(float dt);
    void virtual Render();
    bool virtual Is(string type);
};
#endif