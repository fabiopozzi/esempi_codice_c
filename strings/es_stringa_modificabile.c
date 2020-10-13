#include <stdio.h>

int main()
{
    char prova[] = "ciao come va";

    printf("%s\n", prova);
    prova[0] = 'C';
    printf("%s\n", prova);
    return 0;
}
