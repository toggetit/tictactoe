#include "board.hpp"

Board::Board() {

  if(!loadResources()) {

    std::cout<<"Couldn't load source board"<<SDL_GetError()<<std::endl;
    exit(EXIT_FAILURE);
  }

  board = SDL_CreateRGBSurface(SDL_SWSURFACE,380,380,24,0,0,0,0);

  clearBoard();

  SDL_BlitSurface(source, &playArea, board, NULL);
}

Board::~Board() {
  SDL_FreeSurface(board);
  SDL_FreeSurface(source);
}

SDL_Surface *load_image( std::string filename ) {

  SDL_Surface* loadedImage = NULL;

  loadedImage = IMG_Load( filename.c_str() );

  if( loadedImage == NULL ) {

    SDL_Log("Unable to load image: %s", SDL_GetError());
    SDL_FreeSurface(loadedImage);
  }

  return loadedImage;
}

bool Board::loadResources() {

    source = load_image("resources/board.jpg");
    if (source == NULL) {
      return false;
    }

    //Координаты крестика
    xOffset.x = 10;
    xOffset.y = 20;
    xOffset.w = 65;
    xOffset.h = 80;

    //Координаты нолика
    oOffset.x = 105;
    oOffset.y = 20;
    oOffset.w = 65;
    oOffset.h = 80;

    //Пустое место
    empty.x = oOffset.x + 95;
    empty.y = 20;
    empty.w = 65;
    empty.h = 80;

    //Координаты доски
    playArea.x = 0;
    playArea.y = 120;
    playArea.w = 380;
    playArea.h = 380;

    return true;
}

SDL_Surface* Board::getBoard() const {
  return board;
}

void Board::clearBoard() {

  for(int i = 0; i < 3; i++) {

    for(int j = 0; j < 3; j++) {

      matrix[i][j] = '\0';
    }
  }

  repaint();
}

bool Board::turn(char sign, uint x, uint y)
{
  assert(x < 3);
  assert(y < 3);

  if(matrix[x][y] == '\0') {

    matrix[x][y] = sign;
    repaint();
    return true;
  }
  else {
    return false;
  }
}

void Board::repaint() {

  SDL_Rect temp, destTemp;

  for(int i = 0; i < 3; i++) {

    for(int j = 0; j < 3; j++) {

      switch(matrix[i][j]) {

      case 'x':
	temp = xOffset;
	break;

      case 'o':
	temp = oOffset;
	break;

      default:
	temp = empty;
      }

      //Начальный сдвиг
      destTemp.x = 25;
      destTemp.y = 25;

      //Смещение точки отрисовки на нужную ячейку (от нулевой клетки)
      //минус некая межклеточная величина
      destTemp.x += DELTA*i - i*10;
      destTemp.y += DELTA*j - j*15;
      //destTemp.y += 20;

      SDL_BlitSurface(source, &temp, board, &destTemp);
    }
  }
}

bool Board::checkForWin() const {

  // Rows/columns
  for(uint i = 0; i < 3;) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] != '\0') return true;
    if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] != '\0') return true;
    i++;
  }
  // Diagonals
  if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] != '\0') return true;
  if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[0][2] != '\0') return true;

  return false;
  //Сделать проверку на ничью (в главном цикле сделать всего девять ходов
}

void Board::fillBoard(char sign) {

  clearBoard();

  for(int i = 0; i < 3; i++) {

    for(int j = 0; j < 3; j++) {

      matrix[i][j] = sign;
    }
  }
  repaint();
}

/*Шаблон проверки на победу
int test_for_win(int x,int y)
{
   if((a[y][0] == a[y][1]) && (a[y][1] == a[y][2]) && (a[y][0] != 0)) return 1;
   if((a[0][x] == a[1][x]) && (a[1][x] == a[2][x]) && (a[0][x] != 0)) return 1;
   if(((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && (a[0][0] != 0) || ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && a[0][2] != 0))) return 1;
   return 0;
}
*/
