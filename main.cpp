#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

SDL_Surface* screen;
SDL_Surface* board;

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


bool loadResources()
{
  
    board = load_image("board.jpg");
    if (board == NULL) return false;
	
    return true;

}

int main(int argc, char** argv)
{
    atexit(SDL_Quit);

    screen = SDL_SetVideoMode(380, 380, 24, SDL_HWSURFACE);

    SDL_Init(SDL_INIT_VIDEO);

    if(!loadResources())
	{
	    cout<<SDL_GetError();
	    return(EXIT_FAILURE);
	}


    SDL_Delay(2000);


    return(EXIT_SUCCESS);
}
