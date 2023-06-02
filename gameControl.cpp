#include "gameControl.h"

#define TEST_TYPE 1
#define TEST_ROT 0


gameControl::gameControl() {
  validNextPositionXR = true;
  validNextPositionXL = true;
  validNextPositionY = true;

  currentPiece.type = TEST_TYPE;//(rand() % 7) + 1;
  currentPiece.rotationalState = TEST_ROT;
  currentPiece.canvasX = CANVAS_ORIGIN_X;
  currentPiece.canvasY = CANVAS_ORIGIN_Y;
}



void gameControl::clearScreen(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); 
  SDL_Rect background = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
  SDL_RenderFillRect(renderer, &background);
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


bool gameControl::checkValidPositionX(int x, int y) {
  bool xCondition = (x >= 0) && (x < 10);
  int idx = 10*y + x;
  bool freeSquare = tetrisGrid.statusArray[idx] == 0;
  return xCondition && freeSquare;
}

bool gameControl::checkValidPositionY(int x, int y) {
  bool yCondition = (y >= 0) && (y < 20);
  int idx = 10*y + x;
  bool freeSquare = tetrisGrid.statusArray[idx] == 0;

  return yCondition && freeSquare;
}

void gameControl::drawCurrentPiece(SDL_Renderer *renderer) {
  int x;
  int y;
  int unitValue;

  int pieceCount = 0;

  bool xCondition;
  bool yCondition;

  for (int i = 0; i < TETRIMINO_DIMENSION; i += 1) {
    for (int j = 0; j < TETRIMINO_DIMENSION; j += 1) {

      x = currentPiece.canvasX + j;
      y = currentPiece.canvasY - i;

      unitValue = currentPiece.getTetriminoUnit(currentPiece.type, currentPiece.rotationalState, i, j);
      if (unitValue > 0) {

        // check if space is available: if not, exit function.
        if (!checkValidPositionX(x-1, y)) validNextPositionXL = false;
        if (!checkValidPositionX(x+1, y)) validNextPositionXR = false;
        if (!checkValidPositionY(x, y-1)) validNextPositionY = false;
        // validNextPositionY = checkValidPositionY(x, y-1);

        // record x and y position and store in "piecesX" and "piecesY";
        // use for piece to piece collisions
        currentPiece.piecesX[pieceCount] = x;
        currentPiece.piecesY[pieceCount] = y;
        pieceCount += 1;
        fillGridSquare(unitValue, x, y, renderer);
      }
    }
  }
}


void gameControl::recordLandedPiece() {
  for (int i = 0; i < 4; i += 1) {
    int x_idx = currentPiece.piecesX[i];
    int y_idx = currentPiece.piecesY[i];
    int idx = 10*y_idx + x_idx;
    tetrisGrid.statusArray[idx] = currentPiece.type;
  }
}

void gameControl::renderOccupiedSquares(SDL_Renderer* renderer) {
  for (int i = 0; i < 200; i += 1) {

    int unitValue = tetrisGrid.statusArray[i];
    if (unitValue > 0) {
      
      int x_idx = i % 10;
      int y_idx = i / 10;

      fillGridSquare(unitValue, x_idx, y_idx, renderer);

    }
  }
}



void gameControl::generateNewPiece() {
  currentPiece.type = TEST_TYPE;//(rand() % 7) + 1;
  currentPiece.rotationalState = TEST_ROT;
  currentPiece.canvasX = CANVAS_ORIGIN_X;
  currentPiece.canvasY = CANVAS_ORIGIN_Y;
  validNextPositionXL = true;
  validNextPositionXR = true;
  validNextPositionY = true;
}