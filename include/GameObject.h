#ifndef gameObject_h
#define gameObject_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include <memory>
#include <vector>
#include "Rect.h"
#include "Component.h"

using namespace std;

class GameObject {
  private:
    vector<unique_ptr<Component>> components;
    bool isDead;

  public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(string type);

    Rect box;
};
#endif