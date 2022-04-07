
#ifndef SDL_H
#define SDL_H

#include "global.h"

#include <stdio.h>

void init()
{

  printf("Hello, sdl.\n");

  g.alive = 1;

  g.errno = 0;

}

void close()
{

  printf("Exiting sdl.\n");

  g.errno = 0;
  
}

// Generic
///////////////////////////////////////////////////////////////////////////////
// SDL

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define DELAY_TIME 1000.0 / 60.0

void sdl_delay()
{

  SDL_Delay(DELAY_TIME);

}

void sdl_init()
{

  app.renderer = NULL;
  app.screen = NULL;
  app.window = NULL;

	int rendererFlags, windowFlags;

	rendererFlags = 0 | SDL_RENDERER_ACCELERATED;

	windowFlags = 0 | SDL_WINDOW_SHOWN;

  g.errno = SDL_Init(SDL_INIT_VIDEO);

	if (g.errno < 0)
	{

		printf("Couldn't initialize SDL: %s\n", SDL_GetError());

    g.errno = 2;
    return;

	}

	app.window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{

		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT,
      SDL_GetError());
		
    g.errno = 3;
    return;

	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{

		printf("Failed to create renderer: %s\n", SDL_GetError());
    
    g.errno = 4;
    return;

	}

  app.screen = SDL_GetWindowSurface(app.window);

  g.errno = 0;

}

void sdl_close()
{

  SDL_FreeSurface(app.screen);

  SDL_DestroyRenderer(app.renderer);

  SDL_DestroyWindow(app.window);

  SDL_Quit();

  g.errno = 0;

}

void sdl_check()
{

  SDL_Event event;

  while (SDL_PollEvent(&event))
  {

    if (event.type == SDL_QUIT)
    {

      g.errno = 2;
      return;

    }
    else if (event.type == SDL_KEYDOWN)
    {

      printf("k,");
      fflush(stdout);

    }

  }

  sdl_delay();

  g.errno = 0;

}

// SDL
///////////////////////////////////////////////////////////////////////////////

#endif
