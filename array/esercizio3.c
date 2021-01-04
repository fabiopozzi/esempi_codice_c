/*
Scrivere un programma C che legge da tastiera un array di 10 interi e
stampa "VERO" se tutti gli elementi dell'array sono distinti.
I valori sono distinti se sono tutti DIVERSI TRA DI LORO.
*/
#include <stdio.h>

int main()
{
    int a[10];
    int i, j;

    for (i = 0; i < 10; i++) {
        printf("valore: ");
        scanf("%d", &a[i]);
    }
    //               j
    //             i
    /* a   0 1 2 3 4 5 6 8 0 9   */
    // ho letto tutti i valori
    for (i = 0; i < 10; i++) {
        // e' FOR CON DENTRO UN ALTRO FOR
        for (j = i + 1; j < 10; j++) {
            if (a[i] == a[j]) { // DOPPIONEEEEEEEEEEEEE
                printf("la posizione %d e la posizione %d", i, j);
                return 0;
            }
        }
    }
}