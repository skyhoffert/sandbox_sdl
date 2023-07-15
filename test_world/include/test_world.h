
#ifndef TEST_WORLD_H
#define TEST_WORLD_H

#include "global.h"

#include <SDL_image.h>

void test_world_init()
{

  tw.vx = 0;
  tw.vy = 0;
  tw.width = 64;
  tw.height = 64;
  tw.x = 0;
  tw.y = 0;

  tw.scr_x = 0;
  tw.scr_y = 0;
  tw.scr_w = scr_width;
  tw.scr_h = scr_height;

  tw.tex = IMG_LoadTexture(app.renderer, "gfx/ship.png");
  tw.tex_pos.x = tw.x; tw.tex_pos.y = tw.y;
  tw.tex_pos.w = (int) tw.width; tw.tex_pos.h = (int) tw.height;
  SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
  SDL_RenderClear(app.renderer);
  SDL_RenderCopy(app.renderer, tw.tex, NULL, &tw.tex_pos);
  SDL_RenderPresent(app.renderer);

  g.errno = 0;

}

void test_world_close()
{

  SDL_FreeSurface(tw.surf);

  g.errno = 0;

}

void test_world_check()
{

  // Move the image, according to velocity.
  tw.x += tw.vx;
  tw.y += tw.vy;

  // Scale image to current screen "scroll".
  tw.tex_pos.w = (tw.width / tw.scr_w) * scr_width;
  tw.tex_pos.h = (tw.height/ tw.scr_h) * scr_height;

  // Posiiton according to world position and scroll.
  float tlx = tw.scr_x - (tw.scr_w/2);
  float tly = tw.scr_y - (tw.scr_h/2);
  float cx = ((tw.x - tlx)/tw.scr_w) * scr_width;
  float cy = ((tw.y - tly)/tw.scr_h) * scr_height;
  tw.tex_pos.x = cx - tw.tex_pos.w/2;
  tw.tex_pos.y = cy - tw.tex_pos.h/2;

  SDL_RenderCopy(app.renderer, tw.tex, NULL, &tw.tex_pos);

  g.errno = 0;

}

#endif
