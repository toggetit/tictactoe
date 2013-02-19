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
//    int main(int argc, char* args[])
//    {
//        // Initialize the game
//        InitGame();

//        // Load the game resources
//        LoadGame();

//        // Game Loop
//        while ( gamedata.game_loop )    // This is a bool set to true until exit
//        {


//            // Grab the latest event in the event-queue
//            SDL_PollEvent(&gamedata.sdl_event);

//            // Update the game each frame
//            UpdateGame();    // This runs game-logic

//            // Render the game each frame
//            RenderGame();    // Effectively this calls an SDL_Flip() to update the screen


//        }

//        // Unload resources
//        UnloadGame();

//        // Exit program
//        return 0;
//    }
}

