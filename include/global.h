
#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

///////////////////////////////////////////////////////////////////////////////
// Generic

#define MSG_LEN 128

static inline uint64_t Millis()
{
  struct timeval te;

  gettimeofday(&te, NULL); // get current time

  int64_t milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calc millis

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
// Test Image

struct test_image {
  SDL_Surface* surf;
  SDL_Texture* tex;
  SDL_Rect tex_pos;
  float x, y, vx, vy, width, height;
};

struct test_image test_image;

// Test Image
///////////////////////////////////////////////////////////////////////////////

#endif
