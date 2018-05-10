BIN=main

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

libfractal_test.o: test/libfractal_test.c
		@echo "Building test"
		$(CC) $^ -c -c $@ -lcunit

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -c main.c $(LDFLAGS)

lib:
			@echo "Accessing lib for making"
	(cd libfractal; make)

test: lib $(TEST_OBJ) libfractal/fractal.o
		$(CC) -o $@ libfractal_test.o libfractal/fractal.o -lcunit

#start clean in libfractal
cleanLib:
				@echo "Accessing lib for cleaning"
	(cd libfractal; make shallowclean)

deepcleanLib:
					@echo "Accessing lib for cleaning"
		(cd libfractal; make deepclean)

## remove .o files
shallowclean: cleanLib
				@echo "Cleaning files"
	rm -f *.o main

deepclean: deepcleanLib
				@echo "Cleaning files"
	rm -f *.o main

# an easy launch for a fractal folder using 2 threads
run:
	@echo "quick run"
	./main -d --maxthreads 2 inputs/*.txt fileOut
