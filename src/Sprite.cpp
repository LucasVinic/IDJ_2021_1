#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "Game.h"
#include <string>
#include <stdio.h>

using namespace std;

Sprite::Sprite(): Component(associated){
  texture = nullptr;
}

Sprite::Sprite(string file): Component(associated){
  texture = nullptr;
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
  texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
  if(texture == nullptr){
    printf("deu ruim load texture, %s\n", IMG_GetError());
  }
  SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
  SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
  clipRect.x = x;
  clipRect.y = y;
  clipRect.w = w;
  clipRect.h = h;
}

void Sprite::Render(){
  SDL_Rect dstrect;
  dstrect.x = associated.box.x;
  dstrect.y = associated.box.y;
  dstrect.h = clipRect.h;
  dstrect.w = clipRect.w;
  
  SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
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

void Sprite::Update(){}

bool Sprite::Is(string type){
  if(type == "Sprite")
    return true;
  return false;
}