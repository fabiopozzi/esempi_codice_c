#include <stdio.h>
#include <stdlib.h>

struct list_element {
    char value;
    struct list_element* next;
};

typedef struct list_element* lista;

char elimina_testa(lista* testa)
{
    if (testa == NULL)
        return 0; // non posso eliminare da una lista vuota

    //1 copio il valore della testa in un'altra variabile
    lista vecchia_testa = *testa;
    char retval = vecchia_testa->value;
    *testa = vecchia_testa->next; // aggiorno il valore della testa della lista
    free(vecchia_testa); // libero il valore cancellato
    return retval;
}

char elimina_coda(lista testa, lista* coda)
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

void stampa_lista(lista testa)
{
    lista tmp = testa;

    if (tmp == NULL) {
        printf("lista vuota");
        return;
    }
    while (tmp != NULL) {
        printf("%c ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void inserisci_testa(lista* testa, char c)
{
    // perche' passo la lista per riferimento?
    struct list_element* aux = malloc(sizeof(struct list_element));
    if (aux == NULL)
        return; // ERRORE MALLOC
    aux->value = c;
    aux->next = *testa; //3 - il nuovo elemento punta alla precedente testa
    *testa = aux; // 4- aggiorno la testa della lista
}

void inserisci_coda(lista* coda, char c)
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
        *coda = aux; // aggiorno la coda della lista
    }
}

int main()
{
    lista l = NULL;

    inserisci_testa(&l, 'a');
    inserisci_testa(&l, 'b');
    inserisci_testa(&l, 'c');
    stampa_lista(l);
    elimina_testa(&l);
    stampa_lista(l);

    lista l2 = NULL;
    lista t2 = NULL;
    inserisci_coda(&l2, 'a');
    t2 = l2;
    inserisci_coda(&l2, 'b');
    inserisci_coda(&l2, 'c');
    stampa_lista(t2);
    elimina_coda(t2, &l2);
    stampa_lista(t2);

    return 0;
}
