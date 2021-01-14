#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    int i, j;
    int array[N] = {1, 50, 44, 3, 24, 7, 15, 42, 11, 67};
    int posizione_minimo, valore_minimo;
    int tmp;

    for (i = 0; i < N - 1; i++) { // ripeti n-1 volte
      // il primo elemento non ordinato è in posizione i
        // inizializza minimo
        posizione_minimo = i; // posizione
        valore_minimo = array[i]; // valore

        // trova minimo nel resto dell'array
        for (j = i + 1; j < N; j++) {

            // trova posizione minimo
            if (array[j] < valore_minimo) {
              posizione_minimo = j;
              valore_minimo = array[j];
            }
        } // finito di trovare il minimo


        // scambia minimo (in posizione min) con elemento in posizione i
        tmp = array[posizione_minimo];
        array[posizione_minimo] = array[i];
        array[i] = tmp;
    }

    /* stampa array ordinato */
    for (i = 0; i < N; i++) {
      printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}
