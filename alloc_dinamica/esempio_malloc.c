#include <stdio.h>
#include <stdlib.h>

void f(int n)
{
    // alloca memoria per n interi
    int* p = malloc(n * sizeof(int));
    int *z = calloc(n, sizeof(int));

    if (p == NULL) {
        printf("ALLOCAZIONE FALLITA, ciaone\n");
        return;
    }

    float somma = 0;
    // li chiede all'utente
    for (int i = 0; i < n; i++) {
        printf("inserisci numero %d ", i+1);
        scanf("%d", &p[i]);
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

struct punto {
    int x, y;
};

int main()
{
    int n;
    struct punto *pt;

    pt =  (struct punto *)malloc (sizeof(struct punto));
    if (pt == NULL)
        return -1;
    pt->x = 10;
    pt->y = 20;




    printf("inserisci la dimensione del vettore: ");
    scanf("%d", &n);
    f(n);
    return 0;
}
