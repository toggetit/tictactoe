#include "board.h"

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

Board::Board()
{
    if(!loadResources())
    {
        std::cout<<"Couldn't load source board"<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    //Формат данных для новой поверхности (под доску)

    board = SDL_CreateRGBSurface(SDL_SWSURFACE,380,380,24,0,0,0,0);

    SDL_BlitSurface(source, &playArea, board, NULL);

}

Board::~Board()
{
    SDL_FreeSurface(board);
    SDL_FreeSurface(source);
}

bool Board::loadResources()
{

    source = load_image("board.jpg");
    if (source == NULL) return false;

    //Координаты крестика
    xOffset.x = 10;
    xOffset.y = 20;
    xOffset.w = 65;
    xOffset.h = 80;

    //Координаты нолика
    yOffset.x = 105;
    yOffset.y = 20;
    yOffset.w = 65;
    yOffset.h = 80;

    //Координаты доски
    playArea.x = 0;
    playArea.y = 120;
    playArea.w = 380;
    playArea.h = 380;

    return true;
}

SDL_Surface* Board::getBoard() const
{
    return board;
}
