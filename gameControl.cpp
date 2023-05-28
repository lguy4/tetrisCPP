#include "gameControl.h"


gameControl::gameControl() {
  landedPiece = false;

  currentPiece.type = 1;
  currentPiece.rotationalState = 0;
  currentPiece.canvasX = 3;
  currentPiece.canvasY = 19;
}

void gameControl::clearScreen(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); 
  SDL_Rect background = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
  SDL_RenderFillRect(renderer, &background);
  SDL_RenderPresent(renderer);
}


void gameControl::drawGrid(SDL_Renderer *renderer) {
  SDL_Rect gridOutline;

  gridOutline.x = tetrisGrid.gridX;
  gridOutline.y = tetrisGrid.gridY;
  gridOutline.w = tetrisGrid.gridWidth;
  gridOutline.h = tetrisGrid.gridHeight;


  int lineThickness = 1;
  int transparency = 0xff;
  int colorVal = 0x24;

  SDL_SetRenderDrawColor(renderer, 0, colorVal, colorVal, transparency);		

  for (int i = 0; i < 20; i += 1) {
    int lineYpos = tetrisGrid.gridY + 36*i;
    SDL_RenderDrawLine(renderer, tetrisGrid.gridX, lineYpos, tetrisGrid.gridX + tetrisGrid.gridWidth - 1, lineYpos);
  }

  for (int j = 0; j < 10; j += 1) {
    int lineXpos = tetrisGrid.gridX + 36*j;
    SDL_RenderDrawLine(renderer, lineXpos, tetrisGrid.gridY, lineXpos, tetrisGrid.gridY + tetrisGrid.gridHeight);
  }

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); 
  SDL_RenderDrawRect(renderer, &gridOutline);
}




void gameControl::fillGridSquare(int type, int x_idx, int y_idx, SDL_Renderer *renderer) {
  Uint8 *fillColor = new Uint8[3];
  Uint8 *borderColor = new Uint8[3];

  y_idx = 19 - y_idx;

  switch (type)
  {
  case 1:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 2:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 3:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 4:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 5:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 6:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;

  case 7:
    fillColor[0] = 0x00; fillColor[1] = 0xff; fillColor[2] =  0xff;
    borderColor[0] = 0x00; borderColor[1] = 0xcd; borderColor[2] = 0xff;
    break;
  
  default:
    fillColor[0] = 0x00; fillColor[1] = 0x00; fillColor[2] =  0x00;
    borderColor[0] = 0x00; borderColor[1] = 0x00; borderColor[2] = 0x00;
    break;
  }


  SDL_Rect gridSquare;
  gridSquare.h = 32;
  gridSquare.w = 32;
  gridSquare.x = GRID_X + x_idx*36 + 2;
  gridSquare.y = GRID_Y + y_idx*36 + 2;

  SDL_SetRenderDrawColor(renderer, fillColor[0], fillColor[1], fillColor[2], 0xff); 
  SDL_RenderFillRect(renderer, &gridSquare);
  SDL_SetRenderDrawColor(renderer, borderColor[0], borderColor[1], borderColor[2], 0xff); 
  SDL_RenderDrawRect(renderer, &gridSquare);
}


void gameControl::delay(int milliseconds) {
  int CLOCKS_PER_mSEC = CLOCKS_PER_SEC / 1000;
  int delay = milliseconds*CLOCKS_PER_mSEC;
  clock_t clockStart = clock();
  while(clock() - clockStart < delay);
}



void gameControl::drawCurrentPiece(SDL_Renderer *renderer) {
  int x;
  int y;
  int pieceCount;
  int unitValue;

  bool xCondition;
  bool yCondition;

  for (int i = 0; i < TETRIMINO_DIMENSION; i += 1) {
    for (int j = 0; j < TETRIMINO_DIMENSION; j += 1) {

      x = currentPiece.canvasX + j;
      y = currentPiece.canvasY - i;

      xCondition = (0 <= x) && (x < 10);
      yCondition = (0 <= y) && (y < 20);
      if (pieceCount >= 4) {
        return;
      }

      unitValue = currentPiece.getTetriminoUnit(currentPiece.type, currentPiece.rotationalState, i, j);
      if (unitValue > 0) {
        pieceCount += 1;
        if (!(xCondition && yCondition)) {
          this->landedPiece = true;
          return;
        }
        fillGridSquare(unitValue, x, y, renderer);
      }
    }
  }
}


void gameControl::updateState(SDL_Renderer *renderer) {
  clearScreen(renderer);
  currentPiece.canvasY -= 1;
  drawGrid(renderer);
  drawCurrentPiece(renderer);
  SDL_RenderPresent(renderer);

}