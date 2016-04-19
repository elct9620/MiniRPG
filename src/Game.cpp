#include "SDL2/SDL.h"

int main(int, char**) {

  SDL_Window* window = NULL;

  if( SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf( "SDL could not initialize! %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow( "SDL First Try", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN );

    if( window == NULL) {
      printf("Created window failed! %s\n", SDL_GetError());
    }
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_RenderClear(renderer);

  SDL_Delay(5000);
  SDL_DestroyWindow(window);
  SDL_Quit();

  window = NULL;

  return 0;
}
