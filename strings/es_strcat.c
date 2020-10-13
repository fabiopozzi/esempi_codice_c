#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[] = ", come stai?";

    /* ora allochiamo dinamicamente lo spazio
        necessario a creare la nostra nuova stringa che includerà anche s
        Ci serve spazio per la lunghezza di s + 1 char per il terminatore
        alloco in realtà n + spazio per altri 4 caratteri + il terminatore
        */
    int n = strlen(s) + 4 + 1;

    char* p = calloc(n, sizeof(char)); // perche' usare calloc?

    // qui ho a disposizione tutto l'array
    strncat(p, "ciao", n * sizeof(char));

    // ora copiamo s dentro alla stringa p;
    // il numero 4 come lo potrei sostituire?
    strncat(p, s, (n - 4) * sizeof(char));

    // prova del nove: stampiamo a video p
    printf("%s\n", p);

    return 0;
}
