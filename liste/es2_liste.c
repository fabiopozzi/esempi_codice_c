/*Scrivere un programma che permetta l'inserimento di elementi in una lista collegata ed offra la
possibilità di cercare un elemento tramite la funzione bool cerca_lista(struct elemento *head, int val)
(la funzione restituisce un valore booleano che vale True se il valore ricevuto come parametro è
contenuto nella lista, False altrimenti)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int valore;
    struct nodo* next;
};

bool cerca_lista(struct nodo* head, int val) {
    struct nodo* tmp = head;

    while (tmp != NULL) {
        if (tmp->valore == val) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

int main(void) {

    struct nodo* head = NULL;
    struct nodo* tmp;

    int n;

    do {
        // alloco un elemento della lista
        tmp = (struct nodo*)malloc(sizeof(struct nodo));
        if (tmp == NULL) {
            printf("Fatal error");
            exit(EXIT_FAILURE);
        }
        printf("Inserire un primo valore: ");
        scanf("%d", &tmp->valore);
        tmp->next = head;
        head = tmp;
    } while (tmp->valore != 0);

    printf("Inserire un valore da cercare: ");
    scanf("%d", &n);

    bool ris = cerca_lista(head, n);

    if (ris == true)
        printf("\nIl valore e' presente nella lista\n");
    else
        printf("\nIl valore non e' presente nella lista\n");

    return 0;

}