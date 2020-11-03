#include <stdio.h>
#include <stdlib.h>

typedef char element_type;

typedef struct list_element {
    element_type value;
    struct list_element* next;
} item;

typedef item* lista;

void elimina_testa(lista testa)
{
    //1 copio il valore della testa in un'altra variabile
    lista vecchia_testa = testa;
    testa = testa->next; // aggiorno il valore della testa della lista
    free(vecchia_testa); // libero il valore cancellato
}

void stampa_lista(lista testa)
{
    lista tmp = testa;
    while (tmp != NULL) {
        printf("%c ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void inserimento_testa()
{ // TODO: compito
}

void inserimento_posizione(lista testa, char val)
{
    item* prev_p;
    item* p;

    prev_p = testa;
    // devo raggiungere l'elemento precedente a quello di inserimento
    while ((prev_p->next != NULL) && (prev_p->value < val)) {
        prev_p = prev_p->next;
    }
    // quando esco dal ciclo saro' in una certa posizione della mia lista
    p = (item*)malloc(sizeof(item)); //1 alloco della memoria
    p->value = val; // 2- riempiamo il nuovo elemento copiando nel campo value il valore letto

    p->next = prev_p->next;
    prev_p->next = p;
}

int main(void)
{
    lista testa = NULL; // punta alla testa della lista
    item* aux; // punta al nuovo elemento

    char n;
    while ((n = getchar()) != 'z') {
        // creazione e inserimento in testa
        aux = (item*)malloc(sizeof(item)); //1 alloco della memoria
        aux->value = n; // 2- riempiamo il nuovo elemento copiando nel campo value il valore letto
        // inserisco in testa
        aux->next = testa; //3 - il nuovo elemento punta alla precedente testa
        testa = aux; // 4- aggiorno la testa della lista
        // che adesso puntera' al nuovo elemento appena allocato
    }

    printf("stampa lista:\n");
    stampa_lista(testa);
    inserimento_posizione(testa, 'c');
    printf("stampa lista:\n");
    stampa_lista(testa);
    /*
    TODO:   COME POSSO STAMPARE TUTTI GLI ELEMENTI DI UNA LISTA?
    TODO:   come eliminare un elemento dalla lista?
            come eliminare il PRIMO elemento?
    */
    return 0;
}