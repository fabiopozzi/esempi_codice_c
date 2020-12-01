/*
Implementare una funzione inserisci_con_ordine(int val, coda_t *c).
Tale funzione andrà ad inserire un nuovo elemento nella coda
solo se maggiore dell’ultimo valore inserito
(in caso di coda vuota l'elemento viene inserito in ogni caso),
in caso contrario la funzione deve stampare un messaggio di errore
e non modificare la coda.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
    int val;
    struct list_element* next;
} list_item_t;

typedef list_item_t* lista_t;

typedef struct coda {
    lista_t inizio; // puntatore alla cima della coda
    lista_t fine; // puntatore ultimo elemento coda
} coda_t;

bool is_empty(coda_t coda)
{
    if (coda.inizio == NULL)
        return true;
    return false;
}

void enqueue(int v, coda_t* coda)
{
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL) {
        printf("non ho potuto inserire l'elemento %d\n", v);
        return;
    }

    aux->val = v;
    // inserimento in coda
    // se e' il primo elemento allora mi comporto diversamente
    if (is_empty(*coda)) {
        // in questo caso devo aggiornare entrambi i puntatori
        coda->inizio = aux;
        coda->fine = aux;
    } else {
        list_item_t* tmp = coda->fine;
        // l'ultimo elemento deve puntare al nuovo elemento
        tmp->next = aux;
        // aggiorno la coda della pila
        coda->fine = aux;
    }
}

void inserisci_con_ordine(int val, coda_t* c)
{
    if (is_empty(*c)) {
        enqueue(val, c);
    } else {
        lista_t ultimo = c->fine;
        if (val > ultimo->val) {
            enqueue(val, c);
        } else {
            printf("non e' stato possibile inserire l'elemento %d. Sorry\n", val);
            return;
        }
    }
}

/* verifico ordine crescente */
bool verifica(coda_t c)
{
    lista_t tmp = c.inizio;
    lista_t prox;

    while (tmp->next != NULL) {
        prox = tmp->next;
        if (tmp->val > prox->val) { // se non e' crescente
            return false;
        }
        tmp = tmp->next;
    }
    // se arrivo in fondo significa che l'ordine e' stato crescente
    return true;
}

int main()
{
    coda_t c = { NULL, NULL };

    inserisci_con_ordine(5, &c);
    inserisci_con_ordine(42, &c);
    inserisci_con_ordine(55, &c);
    inserisci_con_ordine(54, &c);
    inserisci_con_ordine(90, &c);
    enqueue(50, &c);
    bool t = verifica(c);
    if (t)
        printf("lista ordinata\n");
    else
        printf("lista non ordinata\n");
}