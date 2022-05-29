#include "gamecore.hpp"

GameCore::GameCore() {

  window = nullptr;
  renderer = nullptr;
  tex = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (SDL_CreateWindowAndRenderer(380, 380, SDL_WINDOW_SHOWN, &window, &renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
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
  }
}

void GameCore::cursorCatch(uint* x, uint* y) {
  *x = event.motion.x / 130;
  *y = event.motion.y / 130;
}

void GameCore::renderGame() {
  tex = SDL_CreateTextureFromSurface(renderer, board->getBoard());

  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, tex, NULL, NULL);
  SDL_RenderPresent(renderer);
}

GameCore::~GameCore() {

  delete board;

  SDL_DestroyTexture(tex);
  tex = nullptr;

  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_DestroyRenderer(renderer);
  renderer = nullptr;

  SDL_Quit();
}
