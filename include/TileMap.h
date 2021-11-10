#ifndef tileMap_h
#define tileMap_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "TileSet.h"
#include "GameObject.h"
#include "Component.h"

using namespace std;

class TileMap: Component {
  private:
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
  public:
    TileMap(GameObject& associated, string file, TileSet* tileset);
    void Load(string file);
    void SetTileSet(TileSet* newTileSet);
    int& At(int x, int y, int zer);
    void Render();
    void RenderLayer(int layer, int cameraX, int cameraY);
    int GetWidth();
    int GetHeight();
    int GetDepth();
};
#endif