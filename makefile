SRC = main.cpp display.cpp grid.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -c
LFLAGS = -lSDL2 -lSDL2_gfx
EXECUTABLE = out


all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE):$(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE) $(LFLAGS)
	./out
	clear


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -f $(OBJ) $(EXECUTABLE)
	clear


