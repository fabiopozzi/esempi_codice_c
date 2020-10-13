#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[] = "uno due tre prova";

    // ora allochiamo dinamicamente lo spazio
    // necessario a creare un "clone" di s
    // ci serve spazio per la lunghezza di s + 1 char per il terminatore
    int n = strlen(s) + 1;

    // posso usare un'altra funzione?
    char* p = malloc(n * sizeof(char));

    // ora copiamo s dentro alla stringa p;
    strcpy(p, s);

    // prova del nove: stampiamo a video p
    printf("%s\n", p);

    return 0;
}
