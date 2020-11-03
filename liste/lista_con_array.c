#include <stdbool.h>
#include <stdio.h>
#define N 2

typedef struct {
    int lunghezza;
    int elementi[N];
} list;

list emptylist()
{
    list l;
    // Convenzione: quando la lista è vuota l'indice del primo elemento
    // è un numero negativo
    l.lunghezza = 0;
    return l;
}
// Controlla se la lista è vuota
bool empty(list l)
{
    return (l.lunghezza == 0);
}

void add_element(list* l, int nuovo_valore)
{
    // controllo lista piena
    if (l->lunghezza == N) {
        printf("lista gia' piena\n");
        return;
    }
    l->elementi[l->lunghezza] = nuovo_valore; // aggiungo un elemento in fondo
    l->lunghezza++;
}

int estrai_elemento(list* l)
{
    if (empty(*l)) {
        printf("lista vuota, non posso estrarre\n");
        return -1;
    }
    l->lunghezza--;
    return l->elementi[l->lunghezza];
}

int main()
{
    list l = emptylist();
    int v;
    if (empty(l)) {
        printf("la lista l e' vuota\n");
    }
    printf("inserisco 10\n");
    add_element(&l, 10);
    printf("inserisco 20\n");
    add_element(&l, 20);
    add_element(&l, 30);

    v = estrai_elemento(&l);
    printf("ultimo elemento %d\n", v);
    v = estrai_elemento(&l);
    printf("ultimo elemento %d\n", v);
    v = estrai_elemento(&l);
    printf("ultimo elemento %d\n", v);
}
