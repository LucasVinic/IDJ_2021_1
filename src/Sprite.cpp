#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Sprite.h"
#include <string>
#include <stdio.h>

using namespace std;

Sprite::Sprite(){
  SDL_Texture* texture = nullptr;
}

Sprite::Sprite(string file){
  SDL_Texture* texture = nullptr;
  Open(file);
}

Sprite::~Sprite(){
  if(texture != nullptr){
    SDL_DestroyTexture(texture);
  }
}

void Sprite::Open(string file){
  if(texture != nullptr){
    SDL_DestroyTexture(texture);
  }

  if(IMG_LoadTexture(Game::renderer, file) == nullptr){
    printf("deu ruim load texture");
  }else{
    SDL_QueryTexture(Game::renderer, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
  }
}

void Sprite::Render(int x, int y){
  SDL_Rect* dstrect = 
  SDL_RenderCopy(Game::renderer, texture, clipRect, )
}

int Sprite::GetWidth(){
  return width;
}

int Sprite::GetHeight(){
  return height;
}

bool Sprite::IsOpen(){
  if(texture != nullptr)
    return true;
  return false;
}