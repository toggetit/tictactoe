#ifndef BOARD_H
#define BOARD_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include <assert.h>

//Смещение в пикселях для отрисовки значков
#define DELTA 115
#define DELTA_X 115
#define DELTA_Y 120

class Board
{
public:
    Board();
    ~Board();

    bool turn(char sign, uint x, uint y);
    SDL_Surface* getBoard() const;
    bool loadResources();
    void clearBoard();
    bool checkForWin();

private:
    //Области X и O на исходной картинке
    SDL_Rect xOffset;
    SDL_Rect oOffset;
    SDL_Rect empty;
    //Область игрового поля
    SDL_Rect playArea;
    //Игровое поле
    SDL_Surface* board;
    //Исходная картинка с ресурсами
    SDL_Surface* source;

    //Матрица значений
    char matrix[3][3];

    //Координаты вставки значков
    SDL_Rect coord[3][3];

    void repaint();
};

#endif // BOARD_H
