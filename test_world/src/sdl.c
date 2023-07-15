
#include "sdl.h"
#include "test_world.h"

#include <signal.h>

#define MACRO_BREAK if (g.errno >= 2) { break; }

void int_handler()
{

  g.alive = 0;

}

int main()
{

  signal(SIGINT, int_handler);

  init();

  sdl_init();
  if (g.errno >= 2) { g.alive = 0; }

  test_world_init();
  if (g.errno >= 2) { g.alive = 0; }

  while (g.alive == 1)
  {

    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);

    test_world_check();
    if (g.errno >= 2) { break; }

    SDL_RenderPresent(app.renderer);

    sdl_check();
    if (g.errno >= 2) { break; }

    fflush(stdout);

  }

  test_world_close();

  sdl_close();

  sdlclose();

  return 0;

}
