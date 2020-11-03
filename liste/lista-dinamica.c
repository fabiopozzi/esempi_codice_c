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

// TODO: compito stampa_lista

// TODO: compito inserimento in testa

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

    // INSERISCO IN UNA CERTA POSIZIONE
    //1 alloco il nuovo elemento
    aux = (item*)malloc(sizeof(item));
    aux->value = 25; // 2- riempiamo il nuovo elemento copiando nel campo value il valore letto

    /*
    TODO:   COME POSSO STAMPARE TUTTI GLI ELEMENTI DI UNA LISTA?
    */
    return 0;
}