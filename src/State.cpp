#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "State.h"
#include <string>
#include <stdio.h>

using namespace std;

State::State():bg("assets/img/ocean.jpg"), music("assets/music/stageState.ogg") {
  quitRequested = false;
}

void State::LoadAssets() {
}

void State::Update(float dt) {
  if(SDL_QuitRequested()){
    quitRequested = true;
  }
}
 
void State::Render() {
  bg.Render(0.00, 0.00);
}

bool State::QuitRequested() {
  return quitRequested;
}



