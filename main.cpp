#include "gamecore.h"

int main(int argc, char** argv)
{

    GameCore* core = new GameCore();

    while (core->isRunning())    // This is a bool set to true until exit
    {
        SDL_WaitEvent(&core->event);

        core->updateGame();
    }

    delete core;

    return(EXIT_SUCCESS);
}
