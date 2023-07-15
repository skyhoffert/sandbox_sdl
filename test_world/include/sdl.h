
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

void sdlclose()
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

int scr_width = SCREEN_WIDTH;
int scr_height = SCREEN_HEIGHT;

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

  g.errno = SDL_Init(SDL_INIT_VIDEO);

	if (g.errno < 0)
	{

		printf("Couldn't initialize SDL: %s\n", SDL_GetError());

    g.errno = 2;
    return;

	}

  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	windowFlags = 0 | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

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

	rendererFlags = 0 | SDL_RENDERER_ACCELERATED;

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{

		printf("Failed to create renderer: %s\n", SDL_GetError());
    
    g.errno = 4;
    return;

	}

  app.screen = SDL_GetWindowSurface(app.window);

  g.frames = 0;
  g.frame_timer_start = Millis();

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

      printf("kd[%c],", event.key.keysym.sym);
      fflush(stdout);

    }
    else if (event.type == SDL_KEYUP)
    {

      printf("ku[%c],", event.key.keysym.sym);
      fflush(stdout);

    }
    else if (event.type == SDL_WINDOWEVENT)
    {
      if (event.window.event == SDL_WINDOWEVENT_RESIZED)
      {
        //printf("MESSAGE:Resizing window... (%d,%d)\n", event.window.data1, event.window.data2);
        scr_width = event.window.data1;
        scr_height = event.window.data2;
      }
    }
    else if (event.type == SDL_MOUSEWHEEL)
    {
      float amtx = event.wheel.y * 20;
      float amty = amtx * scr_height / scr_width;
      tw.scr_w += amtx;
      tw.scr_h += amty;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      if (event.button.button == SDL_BUTTON_LEFT)
      {
        app.lmbdown = 1;
      }
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {
      if (event.button.button == SDL_BUTTON_LEFT)
      {
        app.lmbdown = 0;
      }
    }
    else if (event.type == SDL_MOUSEMOTION)
    {
      if (app.lmbdown == 1)
      {
        tw.scr_x -= event.motion.xrel * tw.scr_w * 0.002;
        tw.scr_y -= event.motion.yrel * tw.scr_h * 0.002;
      }
    }

  }

  sdl_delay();

  g.frames++;
  
  uint64_t now = Millis();
  if (now - g.frame_timer_start > 2000) {
    float frames_f = (float) g.frames;
    float dur = (now - g.frame_timer_start) / 1000;
    float fps = frames_f / dur;
    printf("FPS: %.1f\n", fps);
    g.frame_timer_start = now;
    g.frames = 0;
  }

  g.errno = 0;

}

// SDL
///////////////////////////////////////////////////////////////////////////////

#endif
