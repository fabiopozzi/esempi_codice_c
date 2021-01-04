#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* seguiamo le antiche convenzioni per cui una linea
* doveva avere max 80 caratteri perche' ai tempi delle
* schede perforate (1928) si decise che in una scheda
* ci potevano essere al piu' 80 colonne
* (anche se negli RFC il limite e' a 72)
* https://en.wikipedia.org/wiki/Punched_card
* https://en.wikipedia.org/wiki/Characters_per_line
*/
#define MAX_LINE 80

int main()
{
    char filename[FILENAME_MAX];
    char riga[MAX_LINE];
    FILE *fp;

    int num_righe = 0;
    int num_caratteri = 0;

    printf("Nome del file: ");
    fgets(filename, FILENAME_MAX, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire il file\n");
        return EXIT_FAILURE;
    }

#if 0
    /* soluzione 1: leggo 1 riga alla volta - NULL termina */
    while (fgets(riga, MAX_LINE, fp) != NULL) {
        // riga[strcspn(riga, "\n")] = '\0'; // se volessi eliminare lo \n
        num_righe++;
        num_caratteri += strlen(riga);
        // scelgo di contare anche lo \n.
        // D'altronde lo fa anche word count (wc)
    }
#endif
    /* soluzione 2: leggo un carattere alla volta - EOF termina */
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            num_righe++;
        }
        // scelgo di contare anche lo \n come carattere
        num_caratteri++;
    }

    /* ci sarebbe da controllare che non ci sia stato un errore con ferror */
    /* o di essere effettivamente arrivati a fine file con feof(fp) */

    fclose(fp);

    printf("Righe: %d\nCaratteri: %d\n", num_righe, num_caratteri);

    return EXIT_SUCCESS;
}
