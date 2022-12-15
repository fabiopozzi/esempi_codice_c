/*
## Es 1
Memorizzare in un array bidimensionale 10 x 10
la tavola pitagorica, quella delle tabelline,
e stampare il contenuto della matrice
(nella prima riga si dovrà trovare la tabellina del 1:
1 2 3 4 5 6 7 8 9 10).
*/
#include<stdio.h>
#define RIGHE 10
#define COLONNE 10

int main()
{
    int m[RIGHE][COLONNE]; // dichiaro la matrice m
    int r, c;

    // riempire la matrice
    for(r = 0; r < RIGHE; r++) {
        for(c = 0; c < COLONNE; c++) {
            m[r][c] = (r + 1)*(c + 1);
        }
    }

    // stampare la matrice
    for(r = 0; r < RIGHE; r++) {
        for(c = 0; c < COLONNE; c++) {
            printf("%d\t", m[r][c]);
        }
        printf("\n");
    }

    return 0;
}