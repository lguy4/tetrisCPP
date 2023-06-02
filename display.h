#ifndef __DISPLAY__
#define __DISPLAY__


#include "gameControl.h"

class display {

  public:
    display(int width, int height);

    bool init();

    ~display();

    gameControl controller;
    SDL_Renderer* renderer;

  private:
    int screenWidth;
    int screenHeight;

    int windowXpos;
    int windowYpos;

    SDL_Window* window;
    SDL_Surface* screenSurface;
    

    
    
};


#endif /* __DISPLAY__ */