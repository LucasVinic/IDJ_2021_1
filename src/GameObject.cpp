#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "GameObject.h"
#include <string>
#include <stdio.h>

using namespace std;

GameObject::GameObject(){
  isDead = false;
}

GameObject::~GameObject(){
  for (int i = 0; i < components.size(); i++){
    delete components[i];
  }
}

void GameObject::Update(float dt){
  for (int i = 0; i < components.size(); i++){
    Update(dt);
  }
}

void GameObject::Render(){
  for (int i = 0; i < components.size(); i++){
    Render();
  }
}

bool GameObject::IsDead(){
  return isDead;
}

void GameObject::RequestDelete(){
  isDead = true;
}

void GameObject::AddComponent(Component* cpt){
  components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
  for (int i = 0; i < components.size(); i++){
    if (components[i] == cpt){
      components.erase(i);
      break;
    }
  }
}

Component* GameObject::GetComponent(string type){
  for (int i = 0; i < components.size(); i++){
    if(components[i].Is(type)){
      return components[i];
    }
  }
  return nullptr;
}