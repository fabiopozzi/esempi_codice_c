#include <stdio.h>
#include <stdlib.h>

void f(int n)
{
    // alloca memoria per n interi
    int* p = (int*)malloc(n * sizeof(int));



    float somma = 0;
    // li chiede all'utente
    for (int i = 0; i < n; i++) {
        printf("inserisci numero %d ", i+1);
        scanf("%d", &p[i]);
        getchar();
    }

    for (int i = 0; i < n; i++) {
        somma += p[i];
    }
    somma = somma / n;

    printf("la media dei valori e' %f", somma);
    free(p);

    // calcola la media e finisce
    // la memoria che mi restituisce malloc() e' posizionata nello HEAP
}
int main()
{
    f(7);
    return 0;
}
