#include <stdio.h>
#include <string.h>

int main()
{
    char str[4][20];

    printf("inserisci: ");
    scanf("%s", str[3]); //andiamo al 3 elemento

    for (int i = 0; i < 4; i++) {
        printf("%s", str[i]); //str[0], str[1], str[2], str[3]
        printf("\n");
    }
}