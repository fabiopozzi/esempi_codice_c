/*
Scrivete una funzione con prototipo 
int minimo( int a[], int n )
che, dato un array a di lunghezza n restituisca
il valore dell’elemento più piccolo dell’array.
*/



#include <stdio.h>

int minimo(int a[], int n)
{
    int i;
    int min = a[0];
    for (i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main()
{
    int array[] = { 1, 100, -5, 20, 4 };
    int val_min;

    val_min = minimo(array, 5);
    printf("valore minimo e': %d\n", val_min);
    return 0;
}