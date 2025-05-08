CC = gcc
CFLAGS = -Wall -g -O0

OBJ = at24c02

SRC = main.c

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ) *.o
