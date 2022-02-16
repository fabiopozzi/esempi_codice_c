#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define N 10

int main()
{
    int nuovo, i;
    int j;
    int pos;
    int numeri[N] = {0};

    srand(time(NULL));

    // insertion sort
    for(i = 0; i < N; i++) {
        nuovo = rand() % MAX;

        pos = 0;
        while((numeri[pos] < nuovo) && (numeri[pos] != 0))
            pos++;

        // sposto avanti tutti i valori di una posizione
        // per poter inserire il nuovo elemento
        for(j = N - 2; j >= pos; j--)
            numeri[j + 1] = numeri[j];

        numeri[pos] = nuovo;

        // stampa vettore
        for(j = 0; j < N; j++)
            printf("%d\t", numeri[j]);
        printf("\n");
    }
}
