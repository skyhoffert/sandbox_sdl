
#include "sdl.h"
#include "test_image.h"

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

  test_image_init();
  if (g.errno >= 2) { g.alive = 0; }

  while (g.alive == 1)
  {

    test_image_check();
    if (g.errno >= 2) { break; }

    sdl_check();
    if (g.errno >= 2) { break; }

    printf(".");
    fflush(stdout);

  }

  test_image_close();

  sdl_close();

  close();

  return 0;

}
