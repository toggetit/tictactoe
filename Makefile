all: main.o gamecore.o
	g++ -o tictactoe -lSDL -lSDL_image main.o gamecore.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

gamecore.o: gamecore.h gamecore.cpp
	g++ -c -o gamecore.o gamecore.cpp

clean:
	rm *.[oa] tictactoe
