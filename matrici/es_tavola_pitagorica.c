/*
## Es 1
Scrivere una funzione tavola_pitagorica() che riceva una matrice 10 x 10 e la riempia con la tavola pitagorica delle tabelline.
Scrivere una funzione stampa_matrice() che riceva la matrice e ne stampi il contenuto.
*/
#include<stdio.h>
#define RIGHE 10
#define COLONNE 10

void tavola_pitagorica(int m[][COLONNE])
{
    int r, c;
    // riempire la matrice
    for(r = 0; r < RIGHE; r++) {
        for(c = 0; c < COLONNE; c++) {
            m[r][c] = (r + 1)*(c + 1);
        }
    }
}

void stampa_matrice(int m[][COLONNE])
{
    int r, c;
    // stampare la matrice
    for(r = 0; r < RIGHE; r++) {
        for(c = 0; c < COLONNE; c++) {
            printf("%d\t", m[r][c]);
        }
        printf("\n");
    }
}
    

int main()
{
    int mat[RIGHE][COLONNE]; // dichiaro la matrice

    tavola_pitagorica(mat);
    stampa_matrice(mat);

    return 0;
}
