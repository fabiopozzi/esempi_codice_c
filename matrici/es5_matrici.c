/*
Data una matrice 4×4 di interi trovare
la riga o la colonna con somma più alta.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 4

int main()
{
    int i, j;
    int m[N][N];
    int somma = 0;
    int max = 0; // max riga
    int rigamax = 0;
    int max2 = 0; // max colonna
    int colonnamax = 0;

    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            m[i][j] = (rand() % 10);
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // troviamo la riga con la somma piu' alta
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            // attraversamento riga per riga
            somma += m[i][j];
        }
        // calcola il massimo
        if (somma > max) {
            max = somma;
            rigamax = i;
        }

        somma = 0;
    }
    //printf("la riga con somma massima vale %d\n", max);
    somma = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            // attraversamento colonna per colonna
            somma += m[j][i];
        }
        // calcola il massimo
        if (somma > max2) {
            max2 = somma;
            colonnamax = i;
        }

        somma = 0;
    }
    if (max > max2) {
        printf("la riga di somma max e' %d, vale %d\n", rigamax, max);
    } else {
        printf("la colonna di somma max e' %d, vale %d\n", colonnamax, max2);
    }
}