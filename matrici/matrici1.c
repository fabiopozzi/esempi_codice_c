/*
Scrivere un programma che definisca una matrice MX di valori interi
e di dimensioni fissate tramite #define e immetta in ciascuna cella
un valore casuale (usare rand) compreso tra 0 e 99.
Il programma deve poi visualizzare la matrice con i valori allineati correttamente
(distanziare i valori con '\t' ed andare a capo a fine riga),
contare e stampare a video quanti valori sono pari e quanti sono dispari.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int main()
{
    int m[ROW][COL];
    int r, c;

    srand(time(NULL));
    for (r = 0; r < ROW; r++) {
        for (c = 0; c < COL; c++) {
            m[r][c] = rand() % 100;
        }
    }
    int dispari = 0;
    for (r = 0; r < ROW; r++) {
        for (c = 0; c < COL; c++) {
            printf("%d\t", m[r][c]);
            if (m[r][c] % 2) {
                dispari++;
            }
        }
        printf("\n");
    }
    printf("\nci sono %d numeri dispari\n", dispari);
    return 0;
}