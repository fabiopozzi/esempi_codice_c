/*Scrivere un programma che definisca una matrice MX di valori interi
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
    int mat[ROW][COL];
    int i, j;
    srand(time(NULL)); // INIZIALIZZARE il generatore di numeri casuali

    // riempio la matrice con dei numeri casuali
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // solo stampato i valori in modo allineato
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%i\t", mat[i][j]); // \t TAB
        }
        printf("\n");
    }

    int pari = 0; // IMPORTANTE UGUALE A ZERO!!!!
    int dispari = 0; // IMPORTANTE UGUALE A ZERO!!!!
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            //il DOPPIO UGUALE
            if (mat[i][j] % 2 == 0) { // ALLORA e' pari
                pari++;
            } else {
                dispari++;
            }
        }
    }
    printf("i pari sono %d, i dispari sono %d\n", pari, dispari);
}
