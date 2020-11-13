#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_element {
       int val;
       struct list_element *next;
} list_item_t;

typedef list_item_t* lista_t;

bool is_empty(lista_t t)
{
       if (t != NULL)
              return false;
       return true;
}

/*  push e' un semplice inserimento in testa */
void push(lista_t *t, int v)
{
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL)
        return; // ERRORE MALLOC
    /*  solito inserimento in testa */
    aux->val = v;
    aux->next = *t;
    *t = aux;
}

int pop(lista_t *t)
{
       /*  in questo caso e' una normale estrazione dalla testa */
       int retval;

       if (is_empty(*t))
              return 0; // non posso eliminare da una lista vuota

       //1 copio il valore della testa in un'altra variabile
       lista_t vecchia_testa = *t;
       retval = vecchia_testa->val;
       *t = vecchia_testa->next; // aggiorno il valore della testa della lista
       free(vecchia_testa); // libero il valore cancellato
       return retval;
}

int main()
{
       list_item_t *testa = NULL;
       int tmp;

       push(&testa, 10);
       push(&testa, 20);
       push(&testa, 30);
       tmp = pop(&testa);
}
