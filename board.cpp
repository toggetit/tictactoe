#include "board.h"

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized surface
    return optimizedImage;
}

Board::Board()
{
    if(!loadResources())
    {
        std::cout<<"Couldn't load source board"<<SDL_GetError()<<std::endl;
        exit(EXIT_FAILURE);
    }



    board = SDL_CreateRGBSurface(SDL_SWSURFACE,380,380,24,0,0,0,0);

    SDL_BlitSurface(source, &playArea, board, NULL);

}

Board::~Board()
{
    SDL_FreeSurface(board);
    SDL_FreeSurface(source);
}

bool Board::loadResources()
{

    source = load_image("board.jpg");
    if (source == NULL) return false;

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

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = '-';
        }
    }

    return true;
}

SDL_Surface* Board::getBoard() const
{
    return board;
}

bool Board::turn(char sign, uint x, uint y)
{
    assert(x < 3);
    assert(y < 3);

    if(matrix[x][y] == '-')
    {
        matrix[x][y] = sign;
        repaint();
        return true;
    }
    else return false;
}

void Board::repaint()
{
    SDL_Rect temp, destTemp;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            switch(matrix[i][j])
            {
            case 'x':
                temp = xOffset;
                break;
            case 'o':
                temp = oOffset;
                break;
            default:
                temp = empty;
            }

            //Смещение точки отрисовки на нужную ячейку (от первой клетки)
            destTemp.x = 35 + DELTA*i;
            destTemp.y = 25 + DELTA*j;

            SDL_BlitSurface(source, &temp, board, &destTemp);
        }
    }
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
