#ifndef __DISPLAY__
#define __DISPLAY__


#include "gameControl.h"

class display {

  public:
    display(int width, int height);

    void init();

    ~display();

  private:
    int screenWidth;
    int screenHeight;

    int windowXpos;
    int windowYpos;

    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer* renderer;

    
    gameControl controller;
};


#endif /* __DISPLAY__ */