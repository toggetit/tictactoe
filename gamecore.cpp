#include "gamecore.h"

GameCore::GameCore()
{
    atexit(SDL_Quit);

    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(380, 380, 24, SDL_SWSURFACE);

    if (screen == NULL)
    {
        std::cout<<"Couldn't init screen: "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    Board* board = new Board();


    SDL_BlitSurface(board->getBoard(), NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_Delay(5000);
}

