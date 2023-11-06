#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1- la definizione della struttura dati lista
typedef struct list_element {
    int val;
    struct list_element* next;
} list_item_t;

// 2- definisco il tipo PUNTATORE AD ELEMENTO della lista
typedef list_item_t* lista_t;

// 3- is_empty => lista vuota se puntatore == NULL
bool is_empty(lista_t t)
{
    if (t != NULL)
        return false;
    return true;
}

// 4- PUSH
/*  push e' un semplice inserimento in testa */

void push(lista_t* t, int v)
{
    // 1- alloco elemento
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL)
        return; // ERRORE MALLOC
    /*  solito inserimento in testa */
    // 2- riempio elemento
    aux->val = v;
    // 3-  collego elemento alla "vecchia testa"
    aux->next = *t;
    // 4- aggiorno la testa della lista
    *t = aux;
}

//5 - estrazione dalla testa della lista
int pop(lista_t* t)
{
    /*  in questo caso e' una normale estrazione dalla testa */
    int retval;

    if (is_empty(*t))
        return 0; // non posso eliminare da una lista vuota

    lista_t vecchia_testa = *t; // ho una lista passata per riferimento, quindi
    // mi copio il valore della testa della lista in un'altra variabile

    //1- copio il valore della testa in un'altra variabile
    retval = vecchia_testa->val;
    *t = vecchia_testa->next; // 2- aggiorno il valore della testa della lista
    free(vecchia_testa); // 3- libero il valore cancellato
    return retval; //4- restituisco il valore estratto
}

int main()
{
    lista_t testa = NULL;
    int tmp;

    push(&testa, 10);
    push(&testa, 20);
    push(&testa, 30);
    tmp = pop(&testa);
}
