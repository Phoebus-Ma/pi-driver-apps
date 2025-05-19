CC = gcc
CFLAGS = -Wall -g -O0

OBJ = uart-self

SRC = main.c

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ) *.o
