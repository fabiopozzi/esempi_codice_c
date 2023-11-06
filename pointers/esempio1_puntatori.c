#include <stdio.h>
/*
Scrivere un programma C in grado di:
- dichiarare una variabile intera a cui venga assegnato il valore 100
- dichiarare un puntatore ad intero p
- inizializzare il puntatore con l'indirizzo della prima variabile dichiarata
- stampare il valore della variabile facendo uso del puntatore
- modificare il valore della variabile facendo uso del puntatore, assegnando il valore 50
- stampare l'indirizzo della variabile
 */

int main() {
    int risposta = 100;
    int *p;
    p = &risposta;

    printf("Il valore di risposta è %d\n", *p);
    *p = 50;
    printf("indirizzo della variabile %p\n", &risposta);
    printf("l'indirizzo di risposta è %p\n", p);

    scanf("%d", &risposta);

    return 0;
}
