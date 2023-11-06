#include <stdio.h>
#include <string.h>

int main()
{
    char str[4][20];
    int i;

    for (i = 0; i < 4; i++) {
        printf("inserisci: ");
        fgets(str[i], 20, stdin);
    }
    // faccio altro con le stringhe

    for (i = 0; i < 4; i++) {
        printf("%s", str[i]); //str[0], str[1], str[2], str[3]
        printf("\n");
    }
}
