
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -I/usr/include/SDL2 -D_REENTRANT
CLIBS = -lSDL2

INCLUDES = include/global.h \
	include/sdl.h \
	include/test_image.h

all: sdl
	$(info Making all.)

sdl: src/sdl.c $(INCLUDES)
	$(info Making sdl.)
	$(CC) $(CFLAGS) -o bin/sdl src/sdl.c $(CLIBS)

