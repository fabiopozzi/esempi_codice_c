#include <stdio.h>

int main()
{
    char prova[] = "ciao";
    int i = 0;

    printf("Quanto è lunga la stringa %s?\n", prova);

    while(prova[i] != '\0'){
        i++;
    }

    printf("la stringa %s e' lunga %d\n", prova, i);

    return 0;
}
