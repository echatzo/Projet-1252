CC=gcc
AR=ar
CFLAGS=-g -Wall -W -I/usr/include/stdlib -I/usr/include/SDL -lSDL
SRC=fractal.c tools.c
OBJ=$(SRC:.c=.o)
LIBFILE=libfractal.a

all: $(SRC) $(LIBFILE)

#builder
$(LIBFILE): $(OBJ)
	@echo "making $@"
	$(AR) -r $@ $^

#.o maker
*.o:
	$(CC) -o $@ -c $< $(CFLAGS)

#library cleaner, removes .o and .a files
clean:
		@echo "cleaning libfractal"
		rm -rf *.o *.a
