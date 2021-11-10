#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "TileSet.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

TileSet::TileSet(int tileW, int tileH, string file): tileSet(*(new GameObject()), file) {
  tileHeight  = tileH;
  tileWidth   = tileW;
  columns = tileSet.GetWidth() / tileWidth;
  rows    = tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y){
  unsigned newIndex = index-1;
  if(0 < newIndex < rows*columns){
    int tileX = index % columns;
    int tileY = index / columns;
    //cout << "[TILESET] entrando setclip\n";
    tileSet.SetClip(tileX * tileWidth, tileY * tileWidth, tileWidth, tileHeight);
    tileSet.Render((int) x, (int) y, this->GetTileWidth(), this->GetTileHeight());
  }else{
    // cout << "index de valor " << index << " é inválido\n";
  }
}

int TileSet::GetTileWidth(){
  return tileWidth;
}

int TileSet::GetTileHeight(){
  return tileHeight;
}