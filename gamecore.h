#ifndef GAMECORE_H
#define GAMECORE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include "board.h"

class GameCore
{
public:
    //Инициализировать игровой класс
    GameCore();
    ~GameCore();
    SDL_Event event;
    bool isRunning() const {return gameLoop;}
    void updateGame();
    void renderGame();

private:
    bool gameLoop;
    SDL_Surface* screen;
    Board *board;
    //Вот тут потестим
    bool xTurn;
    uint turns;

};

#endif // GAMECORE_H
