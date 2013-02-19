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
    SDL_Delay(1000);
    //std::cout<<0<<" "<<2;
//    board->turn('x', 1, 1);
//    SDL_BlitSurface(board->getBoard(), NULL, screen, NULL);
//    SDL_Flip(screen);
//    SDL_Delay(3000);
    SDL_Event event;

    while(event.type != SDL_QUIT)
    {
        SDL_PollEvent(&event);

        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            std::cout<<event.button.x;
        }
    }
}

