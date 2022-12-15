/*Scrivere un programma C che, dato un array di interi inserito dall'utente determini se tutti gli elementi dell'array sono distinti.

N.B. distinti equivale a dire diversi tra loro
*/
#include<stdio.h>
#define N 5

int main()
{
    int array[N] = {1, 2, 20, 4, 10};
    int i, j;

    for(i = 0; i < N; i++) {
        // DEVO PROVARE TUTTI I VALORI CON TUTTI GLI ALTRI
        for(j = 0; j < N; j++) { // devo confrontare con TUTTI i valori
            if(i != j) {
                if (array[i] == array[j]) { // ho una coppia di valori
                    printf("I valori del vettore NON SONO DISTINTI\n");
                    return 0;
                }
            }
        }
    }
    printf("i valori SONO DISTINTI\n");
    return 0;
}
