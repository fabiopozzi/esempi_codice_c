#include <stdbool.h>
#include <stdio.h>
#define N 2
/* esempio di lista SEQUENZIALE (sfruttiamo un array)
   in questo modo gli elementi sono adiacenti e accessibili sfruttando
   la sintassi degli array
*/
typedef struct {
    int lunghezza;
    int elementi[N];
} list;

// 1 VOGLIAMO CREARE UNA LISTA VUOTA
list emptylist()
{
    list l;
    // una lista vuota ha lunghezza pari a zero
    l.lunghezza = 0;
    return l;
}

// Controlla se la lista è vuota
bool empty(list l)
{
    return (l.lunghezza == 0);
}

bool full(list l)
{
    return (l.lunghezza == N);
}

// AGGIUNGERE UN ELEMENTO
void add_element(list* l, int nuovo_valore)
{
    // controllo lista piena
    if (full(*l)) {
        printf("lista gia' piena\n");
        return;
    }
    l->elementi[l->lunghezza] = nuovo_valore; // aggiungo un elemento in fondo
    l->lunghezza++;
}

// come estrarre un elemento
int get_element(list* l)
{
    if (empty(*l)) {
        printf("la lista e' vuota\n");
        return -1;
    }
    l->lunghezza--; //aggiorno la lunghezza della lista
    return l->elementi[l->lunghezza];
}
// COMPITO:
// 1- come stampare l'intera lista?
// 2- come cercare un elemento nella lista?
int main()
{
    list l = emptylist();

    if (empty(l)) {
        printf("la lista l e' vuota\n");
    } else {
        printf("qualcosa non va\n");
    }
    add_element(&l, 42);
    printf("primo elemento: %d\n", get_element(&l));
    printf("secondo elemento: %d\n", get_element(&l));
    add_element(&l, 99);
    add_element(&l, 3);
    return 0;
}