#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "State.h"
#include "Face.h"
#include "Sound.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

State::State():bg("assets/img/ocean.jpg"), music("assets/music/stageState.ogg") {
  quitRequested = false;
  auto bgGO = new GameObject();
  bgGO->AddComponent((Component*) &this->bg);
  this->objectArray.emplace_back((unique_ptr<GameObject>) bgGO);
}

State::~State(){
  objectArray.clear();
}

void State::LoadAssets() {
}

void State::Update(float dt) {
  cout << "state update porra\n";
  Input();

  for(auto i = objectArray.begin(); i != objectArray.end(); i++){
    cout << "state primeiro for porra\n";
    auto go = i->get();
    go->Update(dt);
  }

  for(auto i = objectArray.begin(); i != objectArray.end(); i++){
    cout << "state segundo for porra\n";
    auto object = i->get();
    if (object->IsDead()) {
      this->objectArray.erase(i);
      i--;
    }
  }
  if(SDL_QuitRequested()){
    quitRequested = true;
  }
}
 
void State::Render() {
  //bg.Render(0.00, 0.00);
  for (auto i = this->objectArray.begin(); i != this->objectArray.end(); i++){
    auto object = i->get();
    object->Render();
  }
}

bool State::QuitRequested() {
  return quitRequested;
}

void State::Input(){
  // get mouse position
  int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	SDL_Event event;
  while (SDL_PollEvent(&event)) {

    // if event is a quit-type, quit
    if (event.type == SDL_QUIT) this->quitRequested = true;

    // if clicked
    else if (event.type == SDL_MOUSEBUTTONDOWN) {
      // traverse vector backwards, looking if user clicked on a face
      for (auto i = this->objectArray.rbegin(); i != this->objectArray.rend(); i++) {
        auto go = i->get();
        // if there is a face, smack it
        if (go->box.contains(mouseX, mouseY)) {
          auto face = (Face*) go->GetComponent("Face");
          if (face != nullptr) {
            face->Damage(rand() % 10 + 10);
            break;
          }
        }
      }
    }

    if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				this->quitRequested = true;
			} else {
				// Vec2 objPos = Vec2( 200, 0 ).GetRotated( (-PI + PI*(rand() % 1001)/500.0) ) + Vec2( mouseX, mouseY );
				AddObject(mouseX, mouseY);
			}
		}
  }
}

void State::AddObject(int mouseX, int mouseY){
  GameObject* newGame = new GameObject();
  Sprite* penguinSprite = new Sprite("./assets/img/penguinface.png");
  newGame->box.w = penguinSprite->GetWidth();
  newGame->box.h = penguinSprite->GetHeight();
  newGame->box.x = mouseX-penguinSprite->GetWidth()/2;
  newGame->box.y = mouseY-penguinSprite->GetHeight()/2;
  Sound* penguinSound = new Sound(*newGame, "./assets/audio/boom.wav");

  Face* penguinFace = new Face(*newGame);

  newGame->AddComponent((Component*) penguinSprite);
  newGame->AddComponent((Component*) penguinSound);
  newGame->AddComponent((Component*) penguinFace);

  objectArray.push_back((unique_ptr<GameObject>(newGame)));
}
