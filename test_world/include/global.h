
#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

#include <SDL2/SDL.h>

///////////////////////////////////////////////////////////////////////////////////////////////////
// Generic

#define MSG_LEN 128

static inline uint64_t Millis()
{
  struct timeval te;

  gettimeofday(&te, NULL);

  int64_t milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;

  return milliseconds;
}


struct globals {
  int errno;

  char msg[MSG_LEN];

  int alive;

  int frames;
  uint64_t frame_timer_start;
};

struct globals g;

// Generic
///////////////////////////////////////////////////////////////////////////////////////////////////
// SDL App

struct App {
	SDL_Renderer* renderer;
	SDL_Window* window;
  SDL_Surface* screen;
  int lmbdown, rmbdown;
};

struct App app;

// SDL App
///////////////////////////////////////////////////////////////////////////////////////////////////
// Test World

struct test_world {
  SDL_Surface* surf;
  SDL_Texture* tex;
  SDL_Rect tex_pos;
  float x, y, vx, vy, width, height;

  float scr_x, scr_y, scr_w, scr_h;
};

struct test_world tw;

// Test World
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif
