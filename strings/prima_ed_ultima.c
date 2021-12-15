/*
 * Scrivere un programma che, data una frase (max 100 caratteri), estragga in un array "risultato" la prima e l'ultima parola, separandole con una virgola. Infine il programma deve stampare a video il contenuto dell'array "risultato".

Esempio:
"Domani andrò a ballare in discoteca".
Risultato:
"Domani,discoteca"
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int inizio_parola = 0;
    int i;
    int parole = 0;
    char frase[100] = {0};

    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    for(i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            inizio_parola = 1;
        } else {
            if (inizio_parola) {
                parole++;
                inizio_parola = 0;
            }
        }
    }
    if (inizio_parola)
        parole++;

    char risultato[50] = {0};
    int conto = 0;
    int pos_inizio;
    int pos_fine;
    int j = 0, k;
    for(i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            if (!inizio_parola)
                pos_inizio = i;
            inizio_parola = 1;
        } else {
            if (inizio_parola) {
                conto++;
                pos_fine = i;
                inizio_parola = 0;
            }
        }
        if ((conto == 1) || (conto == parole)) {
            for(k = pos_inizio; k <= pos_fine; k++) {
                risultato[j] = frase[k];
                j++;
            }
        }
    }
    if (inizio_parola){
        pos_fine = i;
        for(k = pos_inizio; k <= pos_fine; k++) {
            risultato[j] = frase[k];
            j++;
        }
    }
    printf("%s\n", risultato);


    printf("num parole %d\n", parole);
    return 0;
}

