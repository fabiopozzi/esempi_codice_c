/*
Memorizzare in una matrice 10 x 10
dei numeri casuali compresi tra zero e nove,
stamparne il contenuto e dire quanti zeri sono memorizzati
all’interno della matrice.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int main()
{
    int i, j;
    int m[N][N];
    int conta = 0;

    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            m[i][j] = (rand() % 10);
        }
    }

    // stampa i valori
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // conto gli zeri per riga
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){ // attraversa tutte le colonne di una singola riga
            if (m[i][j] == 0) {
                conta++;
            }
        }
        printf("nella riga %d ci sono %d zeri\n", i, conta);
        conta = 0;
    }

}