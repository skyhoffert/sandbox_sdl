
#ifndef TEST_IMAGE_H
#define TEST_IMAGE_H

#include "global.h"

#include <SDL_image.h>

void test_image_init()
{

  test_image.surf = NULL;

  test_image.surf = SDL_LoadBMP("gfx/arie.bmp");

  test_image.x = 10;
  test_image.y = 10;
  test_image.vx = 3;
  test_image.vy = 3;
  test_image.width = 64;
  test_image.height = 64;

  test_image.tex = IMG_LoadTexture(app.renderer, "gfx/arie.jpg");
  test_image.tex_pos.x = test_image.x; test_image.tex_pos.y = test_image.y;
  test_image.tex_pos.w = (int) test_image.width; test_image.tex_pos.h = (int) test_image.height;
  SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
  SDL_RenderClear(app.renderer);
  SDL_RenderCopy(app.renderer, test_image.tex, NULL, &test_image.tex_pos);
  SDL_RenderPresent(app.renderer);

  if (test_image.surf == NULL)
  {

    printf("Couldn't load arie.bmp.\n");

    g.errno = 2;
    return;

  }

  g.errno = 0;

}

void test_image_close()
{

  SDL_FreeSurface(test_image.surf);

  g.errno = 0;

}

void test_image_check()
{

  // Move the image, according to velocity.
  test_image.x += test_image.vx;
  test_image.y += test_image.vy;

  // For experiment, let's adjust image size according to velocity.
  test_image.width += test_image.vx / 10;
  test_image.height += test_image.vy / 10;

  test_image.tex_pos.w = (int) test_image.width;
  test_image.tex_pos.h = (int) test_image.height;

  // In order to keep the image on screen, detect bounds and bounce velocity off.
  float out_x = (test_image.x + test_image.width) - scr_width;
  float out_y = (test_image.y + test_image.height) - scr_height;

  if (out_x > 0) {
    test_image.vx = -test_image.vx;
    test_image.x -= out_x;
  }
  else if (test_image.x < 0){
    test_image.vx = -test_image.vx;
    test_image.x = 0;
  }

  if (out_y > 0) {
    test_image.vy = -test_image.vy;
    test_image.y -= out_y;
  }
  else if (test_image.y < 0)
  {
    test_image.vy = -test_image.vy;
    test_image.y = 0;
  }

  test_image.tex_pos.x = (int) test_image.x;
  test_image.tex_pos.y = (int) test_image.y;

  SDL_RenderCopy(app.renderer, test_image.tex, NULL, &test_image.tex_pos);

  SDL_Rect portion;
  portion.x = 250;
  portion.y = 150;
  portion.w = 200;
  portion.h = 200;

  SDL_Rect screenpos;
  screenpos.x = scr_width-60;
  screenpos.y = scr_height-60;
  screenpos.w = 60;
  screenpos.h = 60;

  SDL_RenderCopyEx(app.renderer, test_image.tex, &portion, &screenpos, 45, NULL, SDL_FLIP_NONE);

  g.errno = 0;

}

#endif
