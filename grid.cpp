#include "grid.h"

grid::grid() {

  this->gridOutline.x = GRID_X;
  this->gridOutline.y = GRID_Y;

  this->gridOutline.w = GRID_WIDTH;
  this->gridOutline.h = GRID_HEIGHT;

}

void grid::genGridLines(SDL_Renderer* renderer) {
  int lineThickness = 1;
  int transparency = 0xff;
  int colorVal = 0x24;

  SDL_SetRenderDrawColor(renderer, 0, colorVal, colorVal, transparency);		

  for (int i = 0; i < 20; i += 1) {
    int lineYpos = GRID_Y + 36*i;
    SDL_RenderDrawLine(renderer, GRID_X, lineYpos, GRID_X + GRID_WIDTH - 1, lineYpos);
  }

  for (int j = 0; j < 10; j += 1) {
    int lineXpos = GRID_X + 36*j;
    SDL_RenderDrawLine(renderer, lineXpos, GRID_Y, lineXpos, GRID_Y + GRID_HEIGHT);
  }
}


void grid::gridInit(SDL_Renderer* renderer) {
  genGridLines(renderer);
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); 
  SDL_RenderDrawRect(renderer, &gridOutline);
}


void grid::fillGridSquare(int x_idx, int y_idx, SDL_Renderer* renderer) {
  SDL_Rect gridSquare;
  gridSquare.h = 32;
  gridSquare.w = 32;
  gridSquare.x = GRID_X + x_idx*36 + 2;
  gridSquare.y = GRID_Y + y_idx*36 + 2;
  SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff); 
  SDL_RenderFillRect(renderer, &gridSquare);
  SDL_SetRenderDrawColor(renderer, 0x00, 0xcd, 0xff, 0xff); 
  SDL_RenderDrawRect(renderer, &gridSquare);
}