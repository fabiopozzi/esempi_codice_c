#include <stdio.h>
#include <stdlib.h>

struct list_element {
    char value;
    struct list_element* next;
};

typedef struct list_element* lista_t;



// lo useremo per rendere piu' leggibile le operazioni successive

char elimina_testa(lista_t* testa)
{
    // perche' passo la lista_t per riferimento?
    if (testa == NULL)
        return 0; // puntatore a lista non valido
    if (*testa == NULL)
        return 0; // lista vuota

    // 1 copio il valore della testa in un'altra variabile
    lista_t vecchia_testa = *testa;
    char retval = vecchia_testa->value;
    *testa = vecchia_testa->next; // 2 aggiorno il valore della testa della lista_t
    free(vecchia_testa); // 3 libero il valore cancellato
    return retval; // 4 restituisco il valore estratto
}

void stampa_lista(lista_t l)
{
    if (l == NULL) {
        printf("lista_t vuota");
        return;
    }
    while (l != NULL) {
        printf("%c ", l->value);
        l = l->next;
    }
    printf("\n");
}

lista_t inserisci_testa(lista_t testa, char c)
{
    struct list_element* tmp = (struct list_element *)malloc(sizeof(struct list_element));
    if (tmp == NULL)
        return NULL; // ERRORE MALLOC
    tmp->value = c;
    tmp->next = testa; // 3 - il nuovo elemento punta alla precedente testa
    return tmp; // 4- restituisco la nuova testa della lista
}

char elimina_coda(lista_t testa, lista_t* coda)
{
    if (testa == NULL)
        return 0; // puntatore a testa non valido

    // se coda == NULL questo if non esplode solo perche' viene valutato in ordine
    if ((coda == NULL) || (*coda == NULL))
        return 0; // puntatore a coda non valido

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

void inserisci_posizione(lista_t l, int pos, char valore)
{
    // manca validazione di pos

    // posizione == 0 e' prima posizione
    for(int i = 0; (i < pos)&&(l != NULL); i++){
        l = l->next;
    }
    struct list_element* tmp = malloc(sizeof(struct list_element));
    if (tmp == NULL)
        return; // ERRORE MALLOC
    tmp->value = valore;

    tmp->next = l->next; // il successivo dell'elemento corrente diventa il successivo
                        // del nuovo elemento
    l->next = tmp; // l'elemento corrente punta al nuovo
}

void inserisci_coda(lista_t l, char valore)
{
    // alloca la memoria
    struct list_element* tmp = (struct list_element *)malloc(sizeof(struct list_element));
    if (tmp == NULL) {
        printf("FAIL MALLOC");
        exit(EXIT_FAILURE);
    }

    // riempi il nuovo elemento
    tmp->value = valore;
    tmp->next = NULL; // ultimo elemento non ha next

    // vai fino all'ultimo elemento con un valore
    while (l->next != NULL){
        l = l->next;
    }
    // aggiorno la coda, quindi il vecchio "ultimo elemento"
    // va a puntare al nuovo "ultimo elemento"
    l->next = tmp;
}

int main()
{
    lista_t l = NULL;

    l = inserisci_testa(l, 'a');
    l = inserisci_testa(l, 'b');
    l = inserisci_testa(l, 'c');

    stampa_lista(l);
    char c = elimina_testa(&l);
    printf("la testa della lista vale %c\n", c);

    inserisci_coda(l, 'z');
    inserisci_coda(l, 'z');
    inserisci_coda(l, 'a');
    stampa_lista(l);

#if 0
    lista_t l2 = NULL;
    lista_t t2 = NULL;

    t2 = l2;
    inserisci_coda(&l2, 'b');
    inserisci_coda(&l2, 'c');
    stampa_lista(t2);
    elimina_coda(t2, &l2);
    stampa_lista(t2);
#endif
    return 0;
}
