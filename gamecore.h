#ifndef GAMECORE_H
#define GAMECORE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>

class GameCore
{
public:
    //Инициализировать игровой класс
    GameCore();

private:
    SDL_Surface* board;
    SDL_Surface* screen;

    SDL_Rect xOffset;
    SDL_Rect yOffset;

    bool loadBoard();

};

#endif // GAMECORE_H
