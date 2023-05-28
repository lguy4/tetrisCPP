#include "grid.h"

grid::grid() {

  // update status array when piece lands or line clears
  statusArray = new int[200];
  for (int i = 0; i < 200; i += 1) {
    statusArray[i] = 0;
  }

  gridX = GRID_X;
  gridY= GRID_Y;
  gridWidth = GRID_WIDTH;
  gridHeight = GRID_HEIGHT;

}




