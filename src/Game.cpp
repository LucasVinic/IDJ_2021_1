#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Game.h"
#include <string>
#include <stdio.h>

using namespace std;

Game* Game::instance = nullptr;

Game& Game::GetInstance(){
  if(instance != nullptr){
    return *instance;
  }else{
    new Game(
      "Lucas Vinicius Magalhães Pinheiro - 17/0061001",
      1024,
      600
    );
    return *instance;
  }
}

Game::Game(string title, int width, int height){
  if(instance != nullptr){
  }else{
    instance = this;
    int aux_SDL = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if(aux_SDL != 0){
      printf("deu ruim");
    }else{
      IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
      Mix_Init(MIX_INIT_OGG);
      Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
      Mix_AllocateChannels(32);

      window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      if(window == nullptr || renderer == nullptr){
        printf("deu ruim 2");
      }
    }
  }
}

Game::~Game(){
  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

/* State& Game::GetState(){
  return *state;
} */

SDL_Renderer* Game::GetRenderer(){
  return renderer;
}

void Game::Run(){
  
}

