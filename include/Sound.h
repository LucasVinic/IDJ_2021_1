#ifndef sound_h
#define sound_h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "Component.h"

using namespace std;

class Sound: Component {
  private:
    Mix_Chunk* chunk;
    int channel;

  public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, string file);
    ~Sound();

    void Play(int times);
    void Stop();
    void Open(string file);
    bool IsOpen();

    void Update(float dt);
    void Render();
    bool Is(string type);
};
#endif