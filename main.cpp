#include "display.h"
// g++ -g main.cpp display.cpp -lSDL2 -lSDL2_gfx -o out

int main(int argc, char* args[]) {

  display view = display(SCREEN_WIDTH, SCREEN_HEIGHT);

  view.init();

  return 0;
}