/*
La Notazione Polacca Inversa (Reverse Polish Notation, RPN) è
un linguaggio per operazioni aritmetiche in cui l’operatore
segue gli operandi. Per esempio, l’espressione RPN 2 3 +
corrisponde all’espressione 2 + 3, mentre 3 4 1 + /
corrisponde a 3 / (4 + 1).
Una espressione RPN si può calcolare utilizzando uno stack (pila) di valori int o float e applicando le seguenti regole ai
componenti dell’espressione letti da sinistra verso destra:
• se il componente è un operando, fare push dell’operando;
• se è un operatore (+, -, x, /) applicarlo a due elementi prelevati dallo stack dall’ultimo al primo,
e caricare il risultato sullo stack.

Il risultato è l’elemento di testa dello stack.
Scrivere un programma che calcoli e stampi il risultato di una espressione RPN contenuta in un array di char che faccia uso di sole cifre intere.
Es:
char espr[] = {'9', '1', '2', '+',  '/' };
il risultato dell'espressione deve essere 3
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_element {
    char value;
    struct list_element* next;
};

typedef struct list_element* lista_t;

bool isempty (lista_t l)
{
    if (l == NULL)
        return true;
    return false;
}


//push - inserimento
void push(lista_t *head, char v)
{
    struct list_element *p;

    p = (struct list_element *)malloc(sizeof(struct list_element));
    if (p == NULL)
        return;
    p->value = v;
    p->next = *head;
    *head = p;
}

//pop
bool pop(lista_t *head, char *val)
{
    if (isempty(*head))
        return false;

    lista_t p = *head;
    *val = p->value; // estraggo il valore

    *head = p->next; // aggiorno la testa della lista
    free(p);

    return true;
}

int main()
{
    lista_t l = NULL;
    char op1;
    char op2;
    int a, b;
    char espr[] = {'4', '1', '2', '+',  '+' };

    for(int i = 0; i < strlen(espr); i++) {
        if (espr[i] == '+') {
            // esegui somma
            if (pop(&l, &op1) == false) {
                printf("qualcosa e' andato storto");
                return -1;
            }
            a = op1 - 48; // convertiamo un char in un intero corrispondente

            pop(&l, &op2);
            b = op2 - 48;

            a = a + b;
            // ritrasformo in carattere
            op1 = a + 48;
            // inserisco il risultato sullo stack
            push(&l, op1);
        } else if (espr[i] == '-') {

        } else if (espr[i] == '*') {

        } else if (espr[i] == '/') {

        } else {
            // operando
            push(&l, espr[i]);
        }
    }
    pop(&l, &op1);
    printf("risultato: %c\n", op1);

}
