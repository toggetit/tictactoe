#include "gamecore.hpp"

GameCore::GameCore() {

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 380, 380, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    std::cout<<"Couldn't init screen: "<<SDL_GetError()<<std::endl;
    exit(EXIT_FAILURE);
  }
  else {
    screen = SDL_GetWindowSurface(window);
  }

  board = new Board();

  x = 0;
  y = 0;

  gameLoop = true;
  xTurn = true;
  turns = 0;

  renderGame();
}

void GameCore::updateGame() {

  if (turns == 0) {
    board->clearBoard();
    xTurn = true;
  }

  switch(event.type) {

  case SDL_QUIT:
    gameLoop = false;
    break;

  case SDL_MOUSEBUTTONDOWN:

    if (turns < 9) {

      cursorCatch(&x, &y);

      if(xTurn) {

	if(board->turn('x', x, y)) turns++;

      }
      else {

	if(board->turn('o', x, y)) turns++;
      }

      if(board->checkForWin()) {

	if(xTurn) {

	  board->fillBoard('x');
	}
	else {

	  board->fillBoard('o');
	}

	renderGame();
	SDL_Delay(1000);
	turns = 0;
      }

      xTurn = !xTurn;
    }

    else {

      turns = 0;
    }

    break;
  }

}

void GameCore::cursorCatch(uint* x, uint* y) {
  *x = event.motion.x / 130;
  *y = event.motion.y / 130;
}

void GameCore::renderGame() {
  SDL_BlitSurface(board->getBoard(), NULL, screen, NULL);
  SDL_UpdateWindowSurface(window);
}

GameCore::~GameCore() {
  delete board;

  SDL_FreeSurface(screen);
  screen = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}
