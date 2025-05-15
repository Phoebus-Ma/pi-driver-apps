CC = gcc
CFLAGS = -Wall -g -O0
LDLIBS = -lgpiod

OBJ = blink

SRC = main.c

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	$(RM) $(OBJ) *.o
