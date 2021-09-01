#include "Game.h"

int main(int argc, char *argv[]){
  Game MoisesGame = Game::GetInstance();
  MoisesGame.Run();

  return 0;
}