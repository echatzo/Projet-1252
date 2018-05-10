CC=gcc
AR=ar
CFLAGS=-g -Wall -W -I/usr/include/stdlib
LDFLAGS=
SRC=fractal.c tools.c
OBJ=$(SRC:.c=.o)
LIBFILE=libfractal.a

all: $(SRC) $(LIBFILE)

$(LIBFILE): $(OBJ)
	@echo "making $@"
	$(AR) r $@ $(OBJ)

*.o:
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "cleaning libfractal"
	rm -rf $(OBJ_FILES)
