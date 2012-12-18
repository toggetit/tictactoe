#ifndef BOARD_H
#define BOARD_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Board
{
public:
    Board();
    SDL_Surface* getBoardPic();
};

#endif // BOARD_H
