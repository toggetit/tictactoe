#ifndef BOARD_HPP
#define BOARD_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <assert.h>

//Смещение в пикселях для отрисовки значков
#define DELTA 140
#define DELTA_X 115
#define DELTA_Y 120

class Board {

public:
  Board();
  ~Board();

  bool turn(char sign, uint x, uint y);
  SDL_Surface* getBoard() const;

  bool loadResources();
  void clearBoard();
  bool checkForWin() const;
  void fillBoard(char);

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

#endif // BOARD_HPP
