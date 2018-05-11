BIN=main

CC=gcc
CFLAGS=-g -Wall -W -DNDEBUG
LDFLAGS=-lpthread -lSDL

SOURCES=$(wildcard *.c)  # searches for all .c

HEADERS=$(SOURCES:.c=.h)
OBJ=$(SOURCES:.c=.o)

TEST_LDFLAGS=-lcunit
TEST_SRC=tests/*.c
TEST_OBJ=$(TEST_SRC:.c=.o)

LIBR=$(wildcard libfractal/*.a)

#builds libfractal then main
all: lib main

# Building *.o
%.o: %.c $(HEADERS)
	@echo "$^"
	$(CC) $(LDFLAGS) -c $< $(CFLAGS) -Ilibfractal


testlibfractal.o: tests/testlibfractal.c
		@echo "Building test"
		$(CC) $^ -c -c $@ -lcunit

#main builder
main: $(OBJ)
	@echo "Begin building main"
	  $(CC) -o $@ $^ $(LIBR) $(LDFLAGS) $(CFLAGS)

#libfractal builder
lib:
			@echo "Accessing lib for making"
	(cd libfractal; make)

#cunit test builder
test: lib $(TEST_OBJ) libfractal/fractal.o
		$(CC) -o $@ testlibfractal.o libfractal/fractal.o -lcunit

#start clean in libfractal
cleanLib:
				@echo "Accessing lib for cleaning"
	(cd libfractal; make clean)

#cleaner, removes all .o files and the main executable
clean: cleanLib
				@echo "Cleaning files"
	rm -f *.o main

# an easy launch for a fractal folder using 2 threads
run:
	@echo "quick run"
	./main -d --maxthreads 2 tests/inputs/*.txt fileOut
