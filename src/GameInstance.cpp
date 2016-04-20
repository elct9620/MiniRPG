/**
 * Game Instance
 */

#include "GameInstance.h"

GameInstance::GameInstance(std::string gameTitle) {
  this->gameTitle = gameTitle;
  this->window = NULL;
  this->quit = false;

  if(Init() && CreateWindow(640, 480)) {
    SetupGame();
  }
}

bool GameInstance::Init() {
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf("SDL initialize failed! Error: %s", SDL_GetError());
    return false;
  }
  return true;
}

bool GameInstance::CreateWindow(int width, int height) {
  window = SDL_CreateWindow( gameTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );

  if( window == NULL ) {
    printf("SDL cannot create window! Error: %s", SDL_GetError());
    return false;
  }

  return true;
}

void GameInstance::SetupGame() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void GameInstance::HandleEvent() {
  SDL_Event event;
  while( SDL_PollEvent(&event) != 0) {
    if( event.type == SDL_QUIT ) {
      quit = true;
    }
  }
}

void GameInstance::Run() {
  while(!quit) {
    HandleEvent();

    SDL_RenderClear(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  window = NULL;
}
