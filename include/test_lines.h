
#ifndef TEST_LINES_H
#define TEST_LINES_H

#include "global.h"

void test_lines_init()
{

  g.errno = 0;

}

void test_lines_close()
{

  g.errno = 0;

}

void test_lines_check()
{

  SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
  SDL_RenderDrawLine(app.renderer, 20, 20, (int) test_image.x, (int) test_image.y);

  g.errno = 0;

}

#endif
