#include <stdio.h>

void red ()
{
  printf("\033[1;31m");
}

void yellow()
{
  printf("\033[1;33m");
}

void reset()
{
  printf("\033[0m");
}

int main () {
  red();
  printf("Ciao ");
  yellow();
  printf("mondo\n");
  reset();
  return 0;
}
