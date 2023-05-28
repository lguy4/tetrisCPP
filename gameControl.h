#ifndef __GAME_CONTROL__
#define __GAME_CONTROL__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <ctime>

#include "grid.h"
#include "tetrimino.h"

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 800

class gameControl{

  public:
    gameControl();
    gameControl(SDL_Renderer *renderer);
    tetrimino currentPiece;


    //methods: 
    void clearScreen(SDL_Renderer *renderer);
    void drawGrid(SDL_Renderer *renderer);
    void fillGridSquare(int type, int x_idx, int y_idx, SDL_Renderer *renderer);
    void delay(int milliseconds);

    /**
     *  Update state of both grid and active tetrimino.
     *  Build new frame according to updated state.
     *  Refresh display with new frame.
     * 
    */

    void drawCurrentPiece(SDL_Renderer *renderer);
    
    void updateState(SDL_Renderer *renderer);
    bool landedPiece;
    
  private:
    grid tetrisGrid;

};

#endif