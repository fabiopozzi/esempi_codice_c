/*
Stampare a video contenuto pila senza alterarla.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
    int val;
    struct list_element* next;
} list_item_t;

typedef list_item_t* lista_t;

void push(int v, lista_t* p)
{
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL) {
        printf("non ho potuto inserire l'elemento %d\n", v);
        return;
    } // MALLOC non ha avuto successo
    aux->val = v;
    aux->next = *p;
    *p = aux;
}

bool is_empty(lista_t pila)
{
    if (pila == NULL)
        return true;
    return false;
}

int pop(lista_t* p)
{
    if (is_empty(*p)) {
        printf("la lista e' vuota");
        return 0;
    }
    lista_t tmp = *p;
    int retval = tmp->val;
    *p = tmp->next;
    free(tmp);

    return retval;
}

void stack_print(lista_t* p)
{
    // abbiamo solo push e pop a disposizione
    lista_t pila = NULL; // pila temporanea
    int v;

    // stampo la pila
    while (!is_empty(*p)) {
        v = pop(p);
        printf("%d ", v);
        push(v, &pila);
    }
    // riordino gli elementi nella pila re-inserendo in p
    while (!is_empty(pila)) {
        v = pop(&pila);
        push(v, p);
    }
}

/* Implementare funzione head()
che restituisce l’elemento in cima alla pila senza estrarlo
*/
int head(lista_t* p)
{
    int var = pop(p);
    push(var, p);
    return var;
    // v2
    return (*p)->val;
}

int main()
{
    return 0;
}
