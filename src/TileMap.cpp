#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "TileSet.h"
#include "TileMap.h"
#include "GameObject.h"
#include "Component.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

// aux functions

vector<int> getMapDimensions(string dimensionsStr) {
  vector<int> dims;
  regex dimensionsRegex("(\\d+),(\\d+),(\\d+),");
  smatch regexResults;
  
  // execute regex search
  if (!regex_search(dimensionsStr, regexResults, dimensionsRegex)) {
    // cout << "TileMap file has bad sintax." << endl;
    exit(0);
  }

  // push into vector
  for (unsigned int i = 1; i < regexResults.size(); i++) {
    dims.push_back(stoi(regexResults[i]));
  }
  
  // return
  return dims;
}

void addLineContentToVector(string line, vector<int>& vec) {
  istringstream lineStream(line);
  string token;
  while (getline(lineStream, token, ',')) {
    vec.push_back(atoi(token.c_str()));
  }
}

// class functions

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet): Component(associated){
  Load(file);
  SetTileSet(tileSet);
}

void TileMap::Load(string file){
  ifstream curFile;
  curFile.open(file);
  
  if(!curFile.is_open()){
    // cout << "erro ao carregar o arquivo " << file << endl;
    exit(0);
  }

  string line;
  string fileContent;
  int lineCount = 0;
  while (getline(curFile, line)){
    if(lineCount++ == 0){
      auto matrixDimensions = getMapDimensions(line);
      mapWidth  = matrixDimensions[0];
      mapHeight = matrixDimensions[1];
      mapDepth  = matrixDimensions[2];
    }else{
      addLineContentToVector(line, tileMatrix);
    }
  }
}

void TileMap::SetTileSet(TileSet* newTileSet){
  tileSet = newTileSet;
}

int& TileMap::At(int x, int y, int zer){
  int index = zer * mapWidth * mapHeight + y * mapWidth + x;
  return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
  for (int x = 0; x < this->mapWidth; x++)
    for (int y = 0; y < this->mapHeight; y++) {
      // calculate where in the window to render tile (take into account the given camera offset)
      int xPos = x * tileSet->GetTileWidth() + cameraX;
      int yPos = y * tileSet->GetTileHeight() + cameraY;
      // call tileSet to render the correct tile at that position
      tileSet->RenderTile(this->At(x, y, layer), xPos, yPos);
    }
}

void TileMap::Render() {
  int cameraX = associated.box.x;
  int cameraY = associated.box.y;
  for (int layer = 0; layer < mapDepth; layer++)
    RenderLayer(layer, cameraX, cameraY);
}
