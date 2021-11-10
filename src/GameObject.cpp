#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "GameObject.h"
#include "Component.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

GameObject::GameObject(): box(0,0,0,0){
  isDead = false;
}

GameObject::~GameObject(){
  for (auto it = 0; it < components.size(); it++){
    components.at(it).reset();
  }
  components.clear();
}

void GameObject::Update(float dt){
  for (const auto& component : components){
    component->Update(dt);
  }
}

void GameObject::Render(){
  auto compSize = this->components.size();
  // cout << "[GO] rendering an object with " << compSize << " components" << endl;
  for (const auto& component : components) {
    // cout << "[GO] rendering component... ";
    component->Render();
    // cout << " done!" << endl;
  }
  // cout << "[GO] done rendering all components" << endl;
}

bool GameObject::IsDead(){
  return isDead;
}

void GameObject::RequestDelete(){
  isDead = true;
}

void GameObject::AddComponent(Component* cpt){
  components.push_back(unique_ptr<Component>(cpt));
}

void GameObject::RemoveComponent(Component* cpt){
  for (int i = 0; i < components.size(); i++){
    if (components.at(1).get() == cpt){
      components.at(i).reset();
      break;
    }
  }
}

Component* GameObject::GetComponent(string type) {
  //cout << "[GO] tentando pegar componente do tipo " << type << " para o GO " << this << ", de tamanho " << components.size() << endl;
  for (int i = 0; i < components.size(); i++){
    if(components.at(i)->Is(type)){
      return components.at(i).get();
    }
  }
  return nullptr;
}