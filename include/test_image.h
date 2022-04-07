
#ifndef TEST_IMAGE_H
#define TEST_IMAGE_H

#include "global.h"

#include <SDL_image.h>

struct test_image {
  SDL_Surface* surf;
};

struct test_image test_image;

void test_image_init()
{

  test_image.surf = NULL;

  test_image.surf = SDL_LoadBMP("gfx/arie.bmp");

  if (test_image.surf == NULL)
  {

    printf("Couldn't load arie.bmp.\n");

    g.errno = 2;
    return;

  }

  SDL_Rect to;
  to.x = 20;
  to.y = 20;

  SDL_BlitSurface(test_image.surf, NULL, app.screen, &to);

  SDL_UpdateWindowSurface(app.window);

  g.errno = 0;

}

void test_image_close()
{

  SDL_FreeSurface(test_image.surf);

  g.errno = 0;

}

void test_image_check()
{

  g.errno = 0;

}

#endif
