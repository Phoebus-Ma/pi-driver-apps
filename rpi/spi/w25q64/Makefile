CC = gcc
CFLAGS = -Wall -g -O0

OBJ = w25q64

SRC = main.c

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ) *.o
