#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Music.h"
#include <string>
#include <memory>

using namespace std;

Music::Music() {
  music = nullptr;
}

Music::Music(string file) { 
  Open(file);
};

void Music::Play(int times) {
  Mix_PlayMusic(music, times);
}

void Music::Stop(int ms) {
  Mix_FadeOutMusic(ms);
}

void Music::Open(string file) {
  music = Mix_LoadMUS(file.c_str());
  if(music == nullptr)
    printf("deu ruim")
}

bool Music::IsOpen() {
  if(music == nullptr)
    return false;
  return true;
}

Music::~Music() {
  Stop(1500);
  Mix_FreeMusic(music);
}