#include "display.h"
// g++ -g main.cpp display.cpp -lSDL2 -lSDL2_gfx -o out




int pollEvent() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        exit(0);
      case SDL_KEYDOWN:
        return e.key.keysym.sym;
    }
  }
  return -1;
}


int main(int argc, char* args[]) {

  int randNum = SDL_GetTicks() % 69420;

  srand(randNum);

  display view = display(SCREEN_WIDTH, SCREEN_HEIGHT);
  view.controller.quit = false;


  if (view.init()) {


    SDL_Event e;

    int currentEvent;
    unsigned long time1 = SDL_GetTicks();

    

    // game loop
    while(currentEvent != SDLK_ESCAPE) {

      view.controller.clearScreen(view.renderer);
      view.controller.drawGrid(view.renderer);

      // draw occupied squares
      view.controller.renderOccupiedSquares(view.renderer);
      view.controller.drawCurrentPiece(view.renderer);
      SDL_RenderPresent(view.renderer);

    
      currentEvent = pollEvent();


      switch (currentEvent) {
        case SDLK_LEFT:
          if (view.controller.validNextPositionXL){ 
            view.controller.currentPiece.canvasX -= 1;
            view.controller.validNextPositionXL = true;
            view.controller.validNextPositionXR = true;
            view.controller.validNextPositionY = true;
          }
          continue;
        case SDLK_RIGHT:
          if (view.controller.validNextPositionXR){ 
            view.controller.currentPiece.canvasX += 1;
            view.controller.validNextPositionXL = true;
            view.controller.validNextPositionXR = true;
            view.controller.validNextPositionY = true;
          }
          continue;
        case SDLK_UP:
          if (view.controller.checkValidRotation()) {
            view.controller.rotateCW();
            view.controller.validNextPositionY = true;
          }
          continue;
        case SDLK_DOWN:
          if (view.controller.validNextPositionY){
            view.controller.currentPiece.canvasY -= 1;
          }
          continue;
        default:
          break;
      }

      view.controller.validNextPositionXL = true;
      view.controller.validNextPositionXR = true;
      

      unsigned long time2 = SDL_GetTicks();

      if (time2 - time1 > 500) {
        if (view.controller.validNextPositionY) {
          view.controller.currentPiece.canvasY -= 1;
          view.controller.validNextPositionY = true;
        } else{
          
          // check for lines to clear (do later)

          // store state of landed piece in status array
          view.controller.recordLandedPiece();

          view.controller.clearCompleteRows();

          view.controller.generateNewPiece();
        }
        time1 = SDL_GetTicks();
      }

    }


  }

  return 0;
}