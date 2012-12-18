#ifndef BOARD_H
#define BOARD_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>

class Board
{
public:
    Board();
    ~Board();
    SDL_Surface* getBoard() const;
    bool loadResources();
private:
    //Области X и O на исходной картинке
    SDL_Rect xOffset;
    SDL_Rect yOffset;
    //Область игрового поля
    SDL_Rect playArea;
    //Игровое поле
    SDL_Surface* board;
    //Исходная картинка с ресурсами
    SDL_Surface* source;
};

#endif // BOARD_H
