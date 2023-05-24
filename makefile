SRC = main.cpp display.cpp

CC = g++

CFlags = -w -g

LFlags = -lSDL2 -lSDL2_gfx

all: $(SRC) 
	$(CC) $(SRC) $(CFlags) $(LFlags) -o out