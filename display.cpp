#include "display.h"
#include "stdio.h"

display::display(int width, int height) {
  this->screenWidth = width;
  this->screenHeight = height;
  this->window = NULL;
  this->screenSurface = NULL;
}

void display::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL Initialization Error: %s", SDL_GetError());
  } else {

    this->window = SDL_CreateWindow(
      "Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
      this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
      printf("SDL Window Initialization Error: %s", SDL_GetError());
    } else {
      this->screenSurface = SDL_GetWindowSurface(this->window);
      SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xff, 0xff, 0xff));
      SDL_UpdateWindowSurface(this->window);

      SDL_Event e;

      bool quit = false;

      while(quit == false) {
        while(SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) quit = true;
        } 

      }
    }
  }
}

display::~display() {
  printf("Ending Session..\n");
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}


