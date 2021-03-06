
#ifndef GLOBAL_H
#define GLOBAL_H

///////////////////////////////////////////////////////////////////////////////
// Generic

#define MSG_LEN 128

struct globals {
  int errno;

  char msg[MSG_LEN];

  int alive;
};

struct globals g;

// Generic
///////////////////////////////////////////////////////////////////////////////
// SDL App

#include <SDL2/SDL.h>

struct App {
	SDL_Renderer* renderer;
	SDL_Window* window;
  SDL_Surface* screen;
};

struct App app;

// SDL App
///////////////////////////////////////////////////////////////////////////////

#endif
