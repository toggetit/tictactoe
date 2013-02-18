all: main.o gamecore.o board.o
	g++ -o tictactoe main.o gamecore.o board.o -lSDL -lSDL_image

main.o: main.cpp
	g++ -c -o main.o main.cpp

gamecore.o: gamecore.h gamecore.cpp
	g++ -c -o gamecore.o gamecore.cpp

board.o: board.h board.cpp
	g++ -c -o board.o board.cpp

clean:
	rm *.[oa] tictactoe
