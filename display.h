#ifndef __DISPLAY__
#define __DISPLAY__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 640

class display {

  public:
    display(int width, int height);
    
    void init();

    ~display();

  private:
    int screenWidth;
    int screenHeight;

    SDL_Window* window;
    SDL_Surface* screenSurface;
};


#endif /* __DISPLAY__ */