#ifndef __TETRIMINO__
#define __TETRIMINO__

#define TETRIMINO_DIMENSION 4

class tetrimino{

 

  public:
    tetrimino();
     ~tetrimino();
    //void updatePosition(int newPivotX, int newPivotY);
    void rotateCW();

    int type;
    int rotationalState;
    
    // canvas is the 5x5 subgrid the tetrimino is drawn on
    // x and y coordinates of canvas refers to topleft corner of canvas i.e. (0, 0)
    int canvasX;
    int canvasY;

    int* piecesX;
    int* piecesY;

    int getTetriminoUnit(int type, int rotation, int offsetX, int offsetY);

};

#endif