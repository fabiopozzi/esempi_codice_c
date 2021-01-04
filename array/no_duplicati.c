/*
Si scriva un programma che legga 5 numeri interi da tastiera.
Il numero letto viene inserito nell’array se e soltanto se esso non è uguale
ad un numero già presente.
Il ciclo continua finché 5 numeri diversi tra loro sono inseriti da tastiera.
A quel punto il programma calcola e stampa il valore medio dei 5 numeri inseriti 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j;
    int m[5][5];

    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            m[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}