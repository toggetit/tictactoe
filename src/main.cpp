#include "gamecore.hpp"

int main(int argc, char** argv) {

  GameCore* core = new GameCore();

  while (core->isRunning()) {

    SDL_WaitEvent(&core->event);
    core->updateGame();
    core->renderGame();
  }

  delete core;

  return(EXIT_SUCCESS);
}
