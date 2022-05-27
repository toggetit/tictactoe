#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "board.hpp"

class GameCore {

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
  SDL_Window* window;
  // SDL_Renderer* renderer;
  Board *board;
  //Вот тут потестим
  bool xTurn;
  uint turns;

  void cursorCatch(uint*, uint*);
  //Временное решение - индекс клетки при нажатии курсором
  uint x, y;
};

#endif // GAMECORE_HPP
