#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Scrivere una funzione per verificare che le parentesi
 * tonde e quadre all'interno di una stringa siano correttamente
 * annidate.
 * */

struct pila {
        char val;
        struct pila *next;
};

bool match(char p1, char p2)
{
        if (p1 == '(' && p2 == ')')
                return true;
        if (p1 == '[' && p2 == ']')
                return true;

        return false;
}

bool pila_vuota(struct pila *p)
{
        if (p == NULL)
                return true;
        else
                return false;
}

void push(struct pila *p, char valore)
{
        /*  inserimento in testa */
        struct pila *tmp = malloc(sizeof(struct pila));
        if (tmp != NULL) {
                tmp->val = valore;
                tmp->next = p;
                p = tmp;
        }
}

char pop(struct pila *p){
        char head_value = 0;
        if (pila_vuota(p))
                return head_value;
        else {
                struct pila *tmp = p;
                head_value = p->val;
                p = tmp->next; // aggiorna testa
                free(tmp);
        }
        return head_value;
}


int bilanciamento(char *s)
{
        struct pila *p = NULL;

        char c = *s;
        char par;

        while(c != '\0') {
                switch (c) {
                case '(':
                case '[':
                        push(p, c);
                        break;
                case ')':
                case ']':
                        if (pila_vuota(p))
                                return 0;
                        if (match(pop(p), c) == 0)
                                return 0;
                        push(p, c);
                        break;
             
                }

                s++;
                c = *s;
        }

}
