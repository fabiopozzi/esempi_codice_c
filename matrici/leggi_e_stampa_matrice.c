#include<stdio.h>
#define N 3

int main()
{
    // dichiaro una matrice 3x3 == 3 righe e 3 colonne
    // quando il numero delle righe e' uguale a quello delle colonne
    // si parla di MATRICE QUADRATA
    int m[N][N];
    int i, j;

    for(i = 0; i < N; i++) { // righe
        for(j = 0; j < N; j++) { // colonne
            m[i][j] = 5;
        }
    }


    // legge
    // for(i = 0; i < N; i++) { // righe
    //     for(j = 0; j < N; j++) { // colonne
    //         printf("valore %d riga %d colonna: ", i, j);
    //         scanf("%d", &m[i][j]);
    //     }
    // }

    // stampa
    for(i = 0; i < N; i++) { // righe
        for(j = 0; j < N; j++) { // colonne
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
