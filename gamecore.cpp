#include "gamecore.h"

GameCore::GameCore()
{
    //atexit(SDL_Quit);

    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(380, 380, 24, SDL_SWSURFACE);

    if (screen == NULL)
    {
        std::cout<<"Couldn't init screen: "<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }

    board = new Board();


    x = 0;
    y = 0;

    gameLoop = true;
    xTurn = true;
    turns = 0;

    renderGame();
    //SDL_Delay(1000);
    //std::cout<<0<<" "<<2;
//    board->turn('x', 1, 1);
//    SDL_BlitSurface(board->getBoard(), NULL, screen, NULL);
//    SDL_Flip(screen);
//    SDL_Delay(3000);
    //SDL_Event event;

//    while(event.type != SDL_QUIT)
//    {
//        SDL_WaitEvent(&event);

//        if(event.type == SDL_MOUSEBUTTONDOWN)
//        {
//            std::cout<<event.button.x;
//        }
//    }
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

void GameCore::updateGame()
{
    if (turns == 0)
    {
        board->clearBoard();
        xTurn = true;
    }

    switch(event.type)
    {
        case SDL_QUIT:
            gameLoop = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (turns < 9)
            {
                cursorCatch(&x, &y);
                if(xTurn)
                {
                    if(board->turn('x', x, y)) turns++;
                }
                else
                {
                    if(board->turn('o', x, y)) turns++;
                }
                if(board->checkForWin())
                {

                    if(xTurn)board->fillBoard('x');
                    else board->fillBoard('o');
                    SDL_Delay(1000);
                    turns = 0;
                }
                xTurn = !xTurn;

            }
            else
            {

                turns = 0;
            }
            break;
    }

}

void GameCore::cursorCatch(uint* x, uint* y)
{
//    if(event.motion.x > 10)
//    {
//        *x = 0;
//        if(event.motion.x > 125)
//        {
//            *x = 1;
//            if(event.motion.x > 245)
//            {
//                *x = 2;
//            }
//        }
//    }
//    if(event.motion.y > 10)
//    {
//        *x = 0;
//        if(event.motion.y > 125)
//        {
//            *x = 1;
//            if(event.motion.y > 245)
//            {
//                *x = 2;
//            }
//        }
//    }
    *x = event.motion.x / 130;
    *y = event.motion.y / 130;
}


void GameCore::renderGame()
{
    SDL_BlitSurface(board->getBoard(), NULL, screen, NULL);
    SDL_Flip(screen);
}

GameCore::~GameCore()
{
    delete board;
    SDL_Quit();
}
