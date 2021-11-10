#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "Game.h"
#include "Resources.h"
#include <string>
#include <iostream>

using namespace std;


Sprite::Sprite(GameObject& associated): Component(associated) {
  texture = nullptr;
}

Sprite::Sprite(GameObject& associated, string file): Sprite(associated) {
  texture = nullptr;
  Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(string file){
  texture = Resources::GetImage(file);
  if(texture == nullptr){
    // cout << "deu ruim load texture na imagem " << file << " erro " << IMG_GetError() << endl;
    return;
  }
  // cout << "deu bom load texture\n";
  SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
  // cout << "deu bom load texture parte 2\n";
  SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
  clipRect.x = x;
  clipRect.y = y;
  clipRect.w = w;
  clipRect.h = h;
}

void Sprite::Render(){
  return this->Render(associated.box.x, associated.box.y, GetHeight(), GetWidth());
}

void Sprite::Render(int x, int y, int w, int h) {
  // cout << "[Sprite] chegou no render\n";
  SDL_Rect dstrect;
  // cout << "[Sprite] declarou dstrect\n";
  // cout << "associated.box.x " <<  associated.box.x << endl;
  dstrect.x = x;
  // cout << "[Sprite] chegou no associatex box y\n";
  dstrect.y = y;
  // cout << "[Sprite] chegou no associatex box y\n";
  dstrect.h = h;
  // cout << "[Sprite] chegou no getHeight\n";
  dstrect.w = w;
  // cout << "[Sprite] chegou no getWidth\n";
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