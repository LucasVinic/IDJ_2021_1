#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Face.h"
#include "GameObject.h"
#include "Component.h"
#include "Sound.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

Face::Face(GameObject& associated): Component(associated){
  hitpoints = 30;
  this->total_death_time = 1000.0;  // spend 1s dying before deleting object
  this->death_time = 0.0;
  this->isDying = false;
}

void Face::Damage(int damage){
  hitpoints = hitpoints - damage;
  //cout << "[FACE] agora tem só " << hitpoints << "de hp" << endl;
  if(hitpoints <= 0){
    //cout << "[FACE] agora vou morrer" << endl;
    Sound* som = (Sound*) associated.GetComponent("Sound");
    if(som != nullptr){
      som->Play(1);
    }
    // initiate death counter (i.e.: wait until death sound finishes before deleting object)
    this->isDying = true;
    //cout << "[Face] comecei a morrer" << endl;

    // remove sprite
    auto sprite = this->associated.GetComponent("Sprite");
    this->associated.RemoveComponent(sprite);
  }
}

void Face::Update(float dt){
  //cout << "[Face] dando update, o isDying é " << isDying << ", dt é " << dt << ", total_death_time é " << total_death_time << " e o death_time é " << this->death_time << endl;
  // if this is dying, uptade death timer
  if (this->isDying) {
    this->death_time += dt;
  
    // if already time to die, do so and remove the object this is associated with
    if (this->death_time >= this->total_death_time) {
      //cout << "[Face] terminei de morrer, agora é adeus mesmo" << endl;
      this->associated.RequestDelete();
    }
  }
}

void Face::Render(){}

bool Face::Is(string type){
  bool isFace = type == "Face";
  //cout << "checando se sou do tipo " << type << ": " << isFace << endl;
  return isFace;
}