#include "gamecore.h"

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized surface
    return optimizedImage;
}

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

    if (!loadBoard())
    {
        std::cout<<"Couldn't load board "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    xOffset.x = 10;
    xOffset.y = 20;
    xOffset.w = 65;
    xOffset.h = 80;

    yOffset.x = 105;
    yOffset.y = 20;
    yOffset.w = 65;
    yOffset.h = 80;

    SDL_Rect xDest;
    xDest.x = 0;
    xDest.y = 0;
    xDest.w = 65;
    xDest.h = 80;


    SDL_BlitSurface(board, &yOffset, screen, &xDest);
    SDL_Flip(screen);
    SDL_Delay(5000);
}

bool GameCore::loadBoard()
{

    board = load_image("board.jpg");
    if (board == NULL) return false;

    return true;

}
