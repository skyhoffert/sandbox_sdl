
#ifndef TEST_LINES_H
#define TEST_LINES_H

#include <unistd.h>

#include "global.h"

void test_lines_init()
{

  for (int i = 0; i < TEST_LINES_NPTS; i++)
  {
    test_lines.pts[i].x = 0;
    test_lines.pts[i].y = 0;
  }
  test_lines.vx = 1.4;
  test_lines.vy = 0;

  g.errno = 0;

}

void test_lines_close()
{

  g.errno = 0;

}

void test_lines_check()
{

  SDL_SetRenderDrawColor(app.renderer, 0x11, 0x5d, 0x62, 255);
  SDL_RenderDrawLine(app.renderer, 20, 20, 500, 500);

  SDL_SetRenderDrawColor(app.renderer, 0xfa, 0xf8, 0xc7, 255);
  SDL_RenderDrawLine(app.renderer, 20, 20, (int) test_image.x, (int) test_image.y);

  for (int i = 0; i < TEST_LINES_NPTS-1; i++)
  {
    test_lines.pts[i].x = test_lines.pts[i+1].x;
    test_lines.pts[i].y = test_lines.pts[i+1].y;
  }
  test_lines.x += test_lines.vx;
  test_lines.vy += 0.1;
  test_lines.y += test_lines.vy;

  test_lines.pts[TEST_LINES_NPTS-1].x = test_lines.x + test_lines.vx;
  test_lines.pts[TEST_LINES_NPTS-1].y = test_lines.y + test_lines.vy;

  if (test_lines.y >= scr_height)
  {
    test_lines.vy *= -0.999;
  }

  if (test_lines.x >= scr_width || test_lines.x <= 0)
  {
    test_lines.x -= test_lines.vx;
    test_lines.vx *= -1;
  }

  // For some reason, drawing a few points fixes miscoloring on early test_lines points.
  SDL_SetRenderDrawColor(app.renderer, 0xdc, 0x57, 0x49, 255);
  SDL_RenderDrawPoint(app.renderer, -1, -1);
  SDL_RenderDrawPoint(app.renderer, -1, -1);
  SDL_RenderDrawPoint(app.renderer, -1, -1);
  SDL_RenderDrawPoint(app.renderer, -1, -1);
  SDL_RenderDrawPoint(app.renderer, -1, -1);

  SDL_SetRenderDrawColor(app.renderer, 0x2c, 0x17, 0x09, 255);
  SDL_RenderDrawPoints(app.renderer, test_lines.pts, 20);
  SDL_SetRenderDrawColor(app.renderer, 0x6c, 0x27, 0x19, 255);
  SDL_RenderDrawPoints(app.renderer, test_lines.pts+20, 20);
  SDL_SetRenderDrawColor(app.renderer, 0x9c, 0x37, 0x29, 255);
  SDL_RenderDrawPoints(app.renderer, test_lines.pts+40, 20);
  SDL_SetRenderDrawColor(app.renderer, 0xcc, 0x47, 0x39, 255);
  SDL_RenderDrawPoints(app.renderer, test_lines.pts+60, 20);
  SDL_SetRenderDrawColor(app.renderer, 0xfc, 0x57, 0x49, 255);
  SDL_RenderDrawPoints(app.renderer, test_lines.pts+80, 20);

  g.errno = 0;

}

#endif
