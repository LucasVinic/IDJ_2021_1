#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Face.h"
#include "GameObject.h"
#include "Component.h"
#include "Sound.h"
#include <string>
#include <stdio.h>

using namespace std;

Face::Face(GameObject& associated): Component(associated){
  hitpoints = 30;
}

void Face::Damage(int damage){
  hitpoints = hitpoints - damage;
  if(hitpoints <= 0){
    associated.RequestDelete();
    Sound* som = (Sound*) associated.GetComponent("Sound");
    if(som != nullptr){
      som->Play(1);
    }
  }
}

void Face::Update(float dt){}

void Face::Render(){}

bool Face::Is(string type){
  return type == "Face";
}