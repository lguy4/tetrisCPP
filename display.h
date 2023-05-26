#ifndef __DISPLAY__
#define __DISPLAY__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 800

#include "grid.h"

class display {

  public:
    display(int width, int height);

    void init();

    ~display();

  private:
    void clearScreen();

    int screenWidth;
    int screenHeight;

    int windowXpos;
    int windowYpos;

    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer* renderer;
    grid tetrisGrid;
};


#endif /* __DISPLAY__ */