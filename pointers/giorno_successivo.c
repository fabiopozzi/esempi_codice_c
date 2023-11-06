/*
  Scrivere una funzione giornoSuccessivo che riceve come parametri i numeri interi corrispondenti a giorno, mese ed anno di una data, e li aggiorna ai valori per la data del giorno dopo
*/
#include<stdio.h>

void giornoSuccessivo(int *giorno, int *mese, int* anno)
{
    int giorni_per_mese[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *giorno = *giorno + 1;

    // se il giorno calcolato e' piu' grande del numero di giorni del mese
    // corrente, significa che devo passare al mese successivo
    /* if (*giorno > giorni_per_mese[*mese]) { */
    /*     *giorno = 1; */
    /*     if (*mese == 12) { // passo all' anno nuovo */
    /*         *mese = 1; */
    /*         *anno = *anno + 1; */
    /*     } else { */
    /*         *mese = *mese + 1; */
    /*     } */
    /* } */

    if ((*mese == 2) && (*giorno > 28)) { // febbraio
        *giorno = 1;
        *mese = *mese + 1;
    } else if (((*mese == 4)||(*mese == 6)||(*mese == 9) ||(*mese == 11))&&(*giorno > 30)) {
        *giorno = 1;
        *mese = *mese + 1;
    } else if (*giorno > 31) {
        *giorno = 1;

        // gestione fine anno
        if (*mese == 12) {
            *mese = 1;
            *anno = *anno + 1;
        } else {
            *mese = *mese + 1;
        }
    }
}

int main()
{
    int giorno;
    int mese;
    int anno = 2020;

    giorno = 31;
    mese = 1;
    giornoSuccessivo(&giorno, &mese, &anno);
    printf("la data aggiornata e' %d/%d/%d\n", giorno, mese, anno);
    
    giorno = 28;
    mese = 2;
    giornoSuccessivo(&giorno, &mese, &anno);
    printf("la data aggiornata e' %d/%d/%d\n", giorno, mese, anno);

    giorno = 31;
    mese = 12;
    giornoSuccessivo(&giorno, &mese, &anno);
    printf("la data aggiornata e' %d/%d/%d\n", giorno, mese, anno);
}
