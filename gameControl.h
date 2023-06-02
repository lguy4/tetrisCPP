#ifndef __GAME_CONTROL__
#define __GAME_CONTROL__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <ctime>

#include "grid.h"
#include "tetrimino.h"

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 800

#define CANVAS_ORIGIN_X 3
#define CANVAS_ORIGIN_Y 19

class gameControl{

  public:
    gameControl();
    gameControl(SDL_Renderer *renderer);
    tetrimino currentPiece;


    //methods: 
    void clearScreen(SDL_Renderer *renderer);
    void drawGrid(SDL_Renderer *renderer);
    void fillGridSquare(int type, int x_idx, int y_idx, SDL_Renderer *renderer);
    //void delay(int milliseconds);

    void generateNewPiece();

    /**
     *  Update state of both grid and active tetrimino.
     *  Build new frame according to updated state.
     *  Refresh display with new frame.
     * 
    */
    void recordLandedPiece();
    void renderOccupiedSquares(SDL_Renderer* renderer);
    void drawCurrentPiece(SDL_Renderer *renderer);
    bool checkValidPositionX(int x, int y);
    bool checkValidPositionY(int x, int y);
    //bool checkForLanding(int x, int y);

    bool validNextPositionXR;
    bool validNextPositionXL;
    bool validNextPositionY;
    bool quit;
    
  private:
    grid tetrisGrid;

};

#endif