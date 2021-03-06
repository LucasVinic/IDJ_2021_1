#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sound.h"
#include "GameObject.h"
#include "Component.h"
#include "Resources.h"
#include <string>
#include <iostream>

using namespace std;

Sound::Sound(GameObject& associated): Component(associated){
  chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file): Sound(associated){
  Open(file);
}

void Sound::Play(int times){
  int loopTimes = times-1;
  channel       = Mix_PlayChannel(-1, chunk, loopTimes);
}

void Sound::Stop(){
  if(chunk != nullptr){
    Mix_HaltChannel(channel);
  }
}

void Sound::Open(string file){
  chunk = Resources::GetSound(file);
}

Sound::~Sound(){
  if(chunk != nullptr){
    Mix_HaltChannel(channel);
    Mix_FreeChunk(chunk);
  }
}

void Sound::Update(float dt){}

void Sound::Render(){}

bool Sound::Is(string type){
  return type == "Sound";
}