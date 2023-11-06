#include <stdio.h>
#include <string.h>

#define N_PERSONE 20
#define DIM_STRINGA 50

// vettori paralleli
char nomi[N_PERSONE][DIM_STRINGA];
char cognomi[N_PERSONE][DIM_STRINGA];

void ordina_per_cognome()
{
    int i, j;
    char tmp[DIM_STRINGA];

    for(i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i - 1; j++) {

            /*strcmp("aaaa",  "cccc") --> < 0*/

            /*strcmp("cccc",  "aaaa") --> > 0*/

            if (strcmp(cognomi[j], cognomi[j+1]) > 0) {
                // scambia le due stringhe
                strcpy(tmp, cognomi[j]);
                strcpy(cognomi[j], cognomi[j+1]);
                strcpy(cognomi[j+1], tmp);

                strcpy(tmp, nomi[j]);
                strcpy(nomi[j], nomi[j+1]);
                strcpy(nomi[j+1], tmp);
            }
        }
    }

}

int main()
{

    int i;

    for (i = 0; i < 5; i++) {
        printf("Inserisci nome ");
        scanf("%49s", nomi[i]);
        printf("Inserisci cognome ");
        scanf("%49s", cognomi[i]);
    }

    ordina_per_cognome();

    for (i = 0; i < 5; i++) {
        printf("%s %s\n", cognomi[i], nomi[i]);
    }

    return 0;
}
