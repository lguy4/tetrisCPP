#include "display.h"
#include <stdio.h>
#include <ctime>






display::display(int width, int height){
  
  this->screenWidth = width;
  this->screenHeight = height;

  this->windowXpos = SDL_WINDOWPOS_CENTERED;
  this->windowYpos = 10;

  this->window = NULL;
  this->screenSurface = NULL;
  this->renderer = NULL;
}



void display::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL Initialization Error: %s", SDL_GetError());
  } else {

    this->window = SDL_CreateWindow(
      "Tetris", this->windowXpos, this->windowYpos, 
      this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN);

    if (this->window == NULL) {
      printf("SDL Window Initialization Error: %s", SDL_GetError());
    } else {
      this->screenSurface = SDL_GetWindowSurface(this->window);
      SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0x00, 0x00, 0x00));
      SDL_UpdateWindowSurface(this->window);

      this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

      if (this->renderer == NULL) {
        printf("SDL Renderer Initialization Error: %s", SDL_GetError());
      } else {

        SDL_Event e;
        bool quit = false;

        // initial state
        controller.drawGrid(renderer);
        controller.drawCurrentPiece(renderer);
        SDL_RenderPresent(renderer);


        //SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        while(quit == false) {
          
          controller.delay(500);

          while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
              quit = true;
            }
          }
          
          controller.updateState(renderer);
          
          
        }

      }

    }
  }
}

display::~display() {
  printf("Ending Session...\n");
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}


