#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TANTI 5
#define PIPPO 10
#define PLUTO 14
#define PAPERINO 42
#define QUI 7
#define QUO 8
#define QUA 9
// leggere una sequenza di 5 numeri dall'utente
// e stamparli in ordine inverso (al rovescio)
// 1 2 3 4 5
// output: 5 4 3 2 1

int main()
{
    int mioVet[TANTI]; // dichiarazione array
    int a[TANTI] = { 1, 2, 5, 7, 11 }; // array gia' riempito
    int i;

    // riempie array
    for(i = 0; i < TANTI; i++) {
        scanf("%d", &mioVet[i]);
    }

    // stampa al rovescio
    for(i = TANTI - 1; i >= 0; i--) {
        printf("%d ", mioVet[i]);
    }
    return 0;
}
