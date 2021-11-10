#ifndef tileset_h
#define tileset_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "Sprite.h"

using namespace std;

class TileSet {
  private:
    Sprite tileSet;

    int rows;
    int columns;

    int tileWidth;
    int tileHeight;
  
  public:
    TileSet(int tileW, int tileH, string file);
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
};
#endif