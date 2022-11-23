#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TANTI 5

int main()
{
    int mioVet[TANTI];
    int i;
    srand(time(NULL));

    // riempie array
    for(i = 0; i < TANTI; i++) {
        mioVet[i] = (rand() % 100)+1;
    }

    // stampa
    for(i = 0; i < TANTI; i++) {
        printf("%d ", mioVet[i]);
    }
    return 0;
}
