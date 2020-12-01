#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_element {
    char val;
    struct list_element* next;
} list_item_t;

typedef list_item_t* lista_t;

typedef struct coda {
    lista_t inizio; // puntatore alla cima della coda
    lista_t fine; // puntatore ultimo elemento coda
} coda_t;

struct categoria_t {
    char nome;
    coda_t p;
};

bool is_empty(coda_t coda)
{
    if (coda.inizio == NULL)
        return true;
    return false;
}

void enqueue(char v, coda_t* coda)
{
    list_item_t* aux = malloc(sizeof(list_item_t));
    if (aux == NULL) {
        printf("non ho potuto inserire l'elemento %d\n", v);
        return;
    }

    aux->val = v;
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
        // aggiorno la coda della pila
        coda->fine = aux;
    }
}

char dequeue(coda_t* coda)
{
    // se la lista e' vuota, non posso estrarre
    if (is_empty(*coda)) {
        printf("la coda e' vuota\n");
        return 0;
    }
    list_item_t* tmp = coda->inizio;

    char retval = tmp->val;
    // aggiorno testa della lista
    coda->inizio = tmp->next;
    free(tmp);

    return retval;
}

void init_categoria(struct categoria_t* c, char n)
{
    c->nome = n;
    c->p.inizio = NULL;
    c->p.fine = NULL;
}

bool is_vocale(char c)
{
    char vocali[] = "aeiou";
    size_t l = strlen(vocali);
    for (int i = 0; i < l; i++) {
        if (c == vocali[i])
            return true;
    }
    return false;
}

void categorizza(struct categoria_t cat[], char c)
{
    // opzionale, uso enum
    enum {
        MAIUSCOLE,
        MINUSCOLE,
        CONSONANTI,
        VOCALI,
        PUNTEGGIATURA
    };
    // 0 maiuscole
    // 1 minuscole
    // 2 consonanti
    // 3 vocali
    // 4 punteggiatura

    /*
pila = LIFO - ultimo inserito, primo estratto
coda = FIFO - primo inserito, primo estratto
*/
    if (isalpha(c)) {
        if (islower(c)) {
            //minuscola
            enqueue(c, &cat[MINUSCOLE].p);
        }
        if (isupper(c)) {
            //maiuscola
            enqueue(c, &cat[MAIUSCOLE].p);
        }
        char tmp = tolower(c);
        if (is_vocale(tmp)) {
            enqueue(c, &cat[VOCALI].p);
        } else {
            enqueue(c, &cat[CONSONANTI].p);
        }
    }
    if (ispunct(c)) {
        enqueue(c, &cat[PUNTEGGIATURA].p);
    }
}

void stampa_categorie(struct categoria_t cat[])
{
    char val;
    for (int i = 0; i < 5; i++) {
        printf("nome categoria: %c", cat[i].nome);
        printf("\ncontenuto: ");
        while (!is_empty(cat[i].p)) {
            val = dequeue(&cat[i].p);
            printf("%c ", val);
        }
        printf("\n");
    }
}
int main()
{
    struct categoria_t tipi_lettere[5];
    char nomi[] = { 'M', 'm', 'c', 'v', 'p' };
    int i;
    char stringa[] = "ciAO,Mario!!?";

    for (i = 0; i < 5; i++)
        init_categoria(&tipi_lettere[i], nomi[i]);

    for (i = 0; i < strlen(stringa); i++) {
        categorizza(tipi_lettere, stringa[i]);
    }
    stampa_categorie(tipi_lettere);
    return 0;
}