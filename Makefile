
CC=gcc
CFLAGS=-g -Wall -W -DNDEBUG
LDFLAGS=-lpthread -lSDL

SOURCES=$(wildcard *.c)
HEADERS=$(SRC:.c=.h)
OBJ=$(SRC:.c=.o)

TEST_LDFLAGS=-lcunit
TEST_SRC=test/*.c
TEST_OBJ=$(TEST_SRC:.c=.o)

all: main lib
$(CC) $(CFLAGS) -o main main.o libfractal/libfractal.a $(LIB)

main: main.c
	$(CC) $(CFLAGS) -c main.c $(INCLUDE)

lib:
	make -C libfractal/

clean:
	rm *.o main

cleanLib:
make clean -C libfractal/
