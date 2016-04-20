/**
 * Game Instance
 *
 * The main game part
 */

#include "string"
#include "SDL2/SDL.h"

class GameInstance {
  public:
    GameInstance(std::string gameTitle);
    bool Init();
    bool CreateWindow(int width, int height);
    void SetupGame();
    void HandleEvent();
    void Run();

  private:
    std::string gameTitle;
    bool quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
};
