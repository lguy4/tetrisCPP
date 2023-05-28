#ifndef __GRID__
#define __GRID__



#define GRID_X 30
#define GRID_Y 42
#define GRID_WIDTH 360
#define GRID_HEIGHT 720

class grid{

  public:

    grid();

    int *statusArray;
    int gridX; int gridY; int gridWidth; int gridHeight;

};

#endif