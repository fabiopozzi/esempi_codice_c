#include <stdio.h>
#include "funzioni.h"

int main()
{
    int a = 10;
    int b = 11;

    int c = maggiore(a, b);

    printf("il valore piu' grande tra %d e %d e' %d\n", a, b, c);
    return 0;
}
