#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
    int val;
    struct list_element* next;
} list_item_t;

typedef list_item_t* lista_t;

typedef struct coda_t {
    lista_t inizio; // puntatore alla cima della coda
    lista_t fine; // puntatore ultimo elemento coda
} coda_t;

bool is_empty(coda_t coda)
{
    if (coda.inizio == NULL)
        return true;
    return false;
}

void accoda(int v, coda_t* coda)
{
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL) {
        printf("non ho potuto inserire l'elemento %d\n", v);
        return;
    }

    aux->val = v;
    aux->next = NULL;
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
        // aggiorno la coda
        coda->fine = aux;
    }
}

int scoda(coda_t* coda)
{
    // se la lista e' vuota, non posso estrarre
    if (is_empty(*coda)) {
        printf("la coda e' vuota\n");
        return 0;
    }
    list_item_t* tmp = coda->inizio;

    int retval = tmp->val;
    // aggiorno testa della lista
    coda->inizio = tmp->next;
    free(tmp);

    return retval;
}

int main()
{
    // coda
    coda_t coda = { NULL, NULL };
    int val;

    /* push: aggiungere un elemento alla pila
       pop: estrarre un elemento dalla pila
       */
    accoda(10, &coda);
    accoda(20, &coda);
    accoda(30, &coda);

    val = scoda(&coda);
    printf("valore estratto %d\n", val);
    val = scoda(&coda);
    printf("valore estratto %d\n", val);
    val = scoda(&coda);
    printf("valore estratto %d\n", val);
    val = scoda(&coda);
    printf("valore estratto %d\n", val);

    return 0;
}