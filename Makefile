CC = g++
SRCDIR = src
OBJDIR = bin

all: tictactoe

tictactoe: $(OBJDIR)/main.o $(OBJDIR)/gamecore.o $(OBJDIR)/board.o
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/gamecore.o $(OBJDIR)/board.o -lSDL2 -lSDL2_image -o tictactoe

main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

gamecore.o: $(SRCDIR)/gamecore.hpp $(SRCDIR)/gamecore.cpp
	$(CC) -c $(SRCDIR)/gamecore.cpp -o $(OBJDIR)/gamecore.o

board.o: $(SRCDIR)/board.hpp $(SRCDIR)/board.cpp
	$(CC) -c $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o

clean:
	rm $(OBJDIR)/*.[oa] tictactoe

