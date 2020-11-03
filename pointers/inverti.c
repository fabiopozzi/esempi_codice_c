/*
 * Scrivi una funzione inverti(int array[], int n) che inverta l’ordine degli
 * elementi di un array
 */
#include <stdio.h>

void inverti(int v[], int n)
{
    int i;
    int tmp;

    for (i = 0; i < n / 2; i++) {
        tmp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = tmp;
        printf("scambio le posizioni %d e %d\n", i, n - 1 - i);
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main()
{
    int prova[] = { 1, 2, 3, 4, 5 };

    inverti(prova, 5);
    return 0;
}
