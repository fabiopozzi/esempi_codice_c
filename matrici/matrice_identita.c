/*
Es 3. Memorizzare in un array bidimensionale 5 per 5
tutti zeri tranne nelle celle della diagonale principale
dove memorizzare uno
(non usare l’inizializzazione con parentesi graffe
nemmeno per gli zeri)
ovvero:
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
*/
#include<stdio.h>

#define NUM 5

int main()
{
    int m[NUM][NUM]; // matrice quadrata
    int i, j;

    for(i = 0; i < NUM; i++) {
        for(j = 0; j < NUM; j++) {
            if (i == j) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }

    // stampa i valori
    for(i = 0; i < NUM; i++){
        for(j = 0; j < NUM; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

}