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


private:

    SDL_Surface* screen;


};

#endif // GAMECORE_H
