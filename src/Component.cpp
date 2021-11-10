#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Component.h"
#include <string>

using namespace std;

Component::Component(GameObject& associated): associated(associated){}
Component::~Component(){}
void Component::Update(float dt){}
void Component::Render(){}
bool Component::Is(string type){return false;}
