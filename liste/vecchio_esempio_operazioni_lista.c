#include <stdio.h>
#include <stdlib.h>

struct list_element {
    char value;
    struct list_element* next;
};

typedef struct list_element* lista_t;

char elimina_testa(lista_t* testa)
{
    // perche' passo la lista_t per riferimento?

    if (testa == NULL)
        return 0; // puntatore a lista non valido

    if (*testa == NULL)
        return 0; // lista vuota

    //1 copio il valore della testa in un'altra variabile
    lista_t vecchia_testa = *testa;
    char retval = vecchia_testa->value;
    *testa = vecchia_testa->next; // aggiorno il valore della testa della lista_t
    free(vecchia_testa); // libero il valore cancellato
    return retval;
}

char elimina_coda(lista_t testa, lista_t* coda)
{
    // controllo su testa e coda
    struct list_element* tmp = testa;
    char retval = (*coda)->value;
    // ricerca penultimo elemento
    while (tmp->next != *coda)
        tmp = tmp->next;

    // elimina valore
    free(*coda);
    // rendi tmp coda
    tmp->next = NULL;
    *coda = tmp;
    return retval;
}

void stampa_lista(lista_t testa)
{
    lista_t tmp = testa;

    if (tmp == NULL) {
        printf("lista_t vuota");
        return;
    }
    while (tmp != NULL) {
        printf("%c ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

lista_t inserisci_testa(lista_t testa, char c)
{
    struct list_element* aux = malloc(sizeof(struct list_element));
    if (aux == NULL)
        return NULL; // ERRORE MALLOC
    aux->value = c;
    aux->next = testa; // 3 - il nuovo elemento punta alla precedente testa
    return aux; // 4- restituisco la nuova testa della lista
}

void inserisci_coda(lista_t* coda, char c)
{
    struct list_element* aux = malloc(sizeof(struct list_element));
    if (aux == NULL)
        return; // ERRORE MALLOC
    aux->value = c;
    aux->next = NULL;

    // Domanda: perchè devo fare questo?
    if (*coda == NULL) {
        *coda = aux;
    } else {
        (*coda)->next = aux;
        *coda = aux; // aggiorno la coda della lista_t
    }
}

int main()
{
    lista_t l = NULL;

    l = inserisci_testa(l, 'a');
    l = inserisci_testa(l, 'b');
    l = inserisci_testa(l, 'c');
    stampa_lista(l);
    elimina_testa(&l);
    stampa_lista(l);

    lista_t l2 = NULL;
    lista_t t2 = NULL;
    inserisci_coda(&l2, 'a');
    t2 = l2;
    inserisci_coda(&l2, 'b');
    inserisci_coda(&l2, 'c');
    stampa_lista(t2);
    elimina_coda(t2, &l2);
    stampa_lista(t2);

    return 0;
}
