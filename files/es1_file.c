#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[FILENAME_MAX];
    // FILENAME_MAX definita in stdio rappresenta
    // la lunghezza massima del nome di un file.
    FILE *fp;
    int v, max, min, somma;
    int count = 0;

    printf("inserisci il nome del file da elaborare: ");
    fgets(filename, FILENAME_MAX, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ( (fp = fopen(filename, "r")) == NULL ) {
        /* scrivere su stderr e' un modo appropriato di segnalare un errore */
        fprintf(stderr, "Impossibile aprire il file %s\n", filename);
        return EXIT_FAILURE;
        /* exit failure e' una costante di stdlib che rappresenta il valore convenzionale
         * usato per segnalare la terminazione volontaria di un programma causata da un errore */
    }

    if (fscanf(fp, "%d", &v) != EOF) { // leggo il primo valore
        /* inizializzo tutto con v */
        max = v;
        min = v;
        somma = v;
        count++;
    } else {
        fprintf(stderr, "Errore: file vuoto\n");
        return EXIT_FAILURE;
    }

    /* leggo numeri fino a quando non finisce il file */
    while (fscanf(fp, "%d", &v) != EOF) {
        count++;
        somma += v;
        if (v > max)
            max = v;
        else if (v < min)
            min = v;
    }
    float media = (float)somma / count;
    printf("Max: %d\nMin: %d\nSomma: %d\nMedia: %.2f\nNumero valori: %d\n",
        max, min, somma, media, count);

    fclose(fp);

    return EXIT_SUCCESS;
}
