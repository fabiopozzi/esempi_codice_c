#include <stdio.h>
#include <stdlib.h>

#define NOMEFILE  "prova.txt"

char *leggiFile(char *nome_file)
{
    FILE *f;
    char *testo;
    size_t i = 0;
    int c;  // e' un intero perche' uso fgetc

    f = fopen(nome_file, "r");
    if (f == NULL) {
        perror("impossibile aprire il file");
        return NULL; //non e' stato possibile aprire il file
    }

    // assumiamo che il file sia piu' piccolo di 1kB
    testo = (char *)malloc(1000*sizeof(char));

    while ((c = fgetc(f)) != EOF)
    {
        testo[i] = (char) c;
        i++;
        if (i == 1000)
            break;
    }

    // in fondo metto il terminatore di stringa
    testo[i] = '\0';

    return testo;
}

int main()
{
    char *t;

    t = leggiFile(NOMEFILE);
    printf("il file %s contiene:\n", NOMEFILE);
    printf("%s\n", t);

    return 0;
}
