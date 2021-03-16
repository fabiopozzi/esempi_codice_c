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
    /*  come implemento la pila?
        posso implementarla come una lista collegata con inserimento in testa
    */
    // nella malloc la sizeof() si deve applicare ad un TIPO che non sia un puntatore
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL) {
		// MALLOC non ha avuto successo
        printf("non ho potuto inserire l'elemento %d\n", v);
        return;
    }
    aux->val = v;
    aux->next = *p;
    // aggiorno la testa della pila
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
    // se la lista e' vuota, non posso estrarre
    if (is_empty(*p)) {
        printf("la lista e' vuota");
        return 0;
    }
    lista_t tmp = *p;
    int retval = tmp->val;
    // estraggo il valore che e' in cima alla pila
    *p = tmp->next;
    free(tmp);

    return retval;
}

int main()
{
    // pila
    lista_t pila = NULL;
    int valore;

    /* push: aggiungere un elemento alla pila
       pop: estrarre un elemento dalla pila
       */
    push(10, &pila);
    push(20, &pila);
    push(30, &pila);

    valore = pop(&pila);
    printf("1 valore %d\n", valore);
    valore = pop(&pila);
    printf("2 valore %d\n", valore);
    valore = pop(&pila);
    printf("3 valore %d\n", valore);
    valore = pop(&pila);
    printf("4 valore %d\n", valore);

    return 0;
}
