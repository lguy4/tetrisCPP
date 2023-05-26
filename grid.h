#ifndef __GRID__
#define __GRID__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define GRID_X 30
#define GRID_Y 42
#define GRID_WIDTH 360
#define GRID_HEIGHT 720

class grid{

  public:

    grid();

    void gridInit(SDL_Renderer* renderer);

    void genGridLines(SDL_Renderer* renderer);

    void fillGridSquare(int x_idx, int y_idx, SDL_Renderer* renderer);

  private:

  
    SDL_Rect gridOutline;


};

#endif