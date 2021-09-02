#include "SDL_image.h"
#include "SDL_mixer.h"
#include "State.h"
#include <string>
#include <stdio.h>

using namespace std;

bool State::quitRequested = false;

State::State() {};

void State::LoadAssets() {

}

void State::Update(float dt) {
  if(SDL_QuitRequested()){
    quitRequested = true;
  }
}
 
void State::Render() {

}

bool State::QuitRequested() {
  return quitRequested;
}



