
CC=gcc
CFLAGS=-g -Wall -W -DNDEBUG
LDFLAGS=-lpthread -lSDL

SOURCES=$(wildcard *.c)  # searches for all .c

HEADERS=$(SOURCES:.c=.h)
OBJ=$(SOURCES:.c=.o)

TEST_LDFLAGS=-lcunit
TEST_SRC=test/*.c
TEST_OBJ=$(TEST_SRC:.c=.o)

all: main lib

# Building *.o
%.o: %.c $(HEADER)
	@echo "$^"
	$(CC) $(LDFLAGS) -c $< $(CFLAGS) -Ilibfractal

main: $(OBJ)
	$(CC) $(CFLAGS) -c main.c -lpthread

compute.o: compute.c
	$(CC) -c compute.c $(CFLAGS) -lpthread

buffer.o: buffer.c
	$(CC) -c buffer.c $(CFLAGS) -lpthread

lib:
	(cd libfractal; make)

#start clean in libfractal
cleanLib:
	(cd libfractal; make clean)

## remove .o files
clean: clean_lib
	rm -f *.o



run: # an easy launch for a fractal folder using 2 threads
	./main -d --maxthreads 2 inputs/*.txt fileOut
