/*
 * Scrivere un programma che sia in grado di verificare che le parentesi
 * tonde e quadre all'interno di una *stringa* siano correttamente
 * annidate. "[4+(xy + x^2) / 3]*(4x + z)" OK                  [4+x)*[1/(e^xy)] NON OK  [()][ NON OK (ho lasciato una parentesi aperta)
 * ([])
 * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// CREIAMO UNA PILA IN CUI INSERIAMO LE PARENTESI.
//1 definiamo la struttura dati
typedef struct pila {
    char val;
    struct pila* next;
} elem_pila_t;

//2 definiamo il tipo puntatore ad elemento
typedef elem_pila_t* pila_t;

//3 is_empty
bool is_empty(pila_t p) // p  come pila
{
    // is_empty?
    if (p == NULL)
        return true;
    return false;
}

//4 push()
void push(int v, pila_t* p)
{
    elem_pila_t* aux = malloc(sizeof(elem_pila_t));
    if (aux == NULL) {
        perror("MALLOC fail");
        return;
    }
    aux->val = v;
    aux->next = *p; // aggancio l'elemento in cima
    *p = aux; // aggiorno cima della pila
}

char pop(pila_t* p)
{
    if (is_empty(*p)) { // p e' riferimento, *p e' cima pila
        printf("la pila e' vuota!\n");
        return -42;
    }
    pila_t tmp = *p;
    char retval = tmp->val;
    *p = tmp->next;
    free(tmp);
    return retval;
}

bool corrisponde(char p_aperta, char p_chiusa)
{
    if (p_aperta == '(' && p_chiusa == ')')
        return true;
    if (p_aperta == '[' && p_chiusa == ']')
        return true;
    return false;
}

bool controllo(char s[])
{
    // DEVO ATTRAVERSARE TUTTA LA STRINGA
    int i;
    int len = strlen(s);
    char c;
    pila_t p = NULL;

    for (i = 0; i < len; i++) {
        c = s[i]; // solo per leggibilita'
        // mi chiedo se il carattere corrente e' una parentesi
        // se ho una parentesi aperta ( oppure [ devo fare qualcosa
        // se invece ho una parentesi chiusa ) oppure ] dovro' fare altro
        switch (c) {
        case '(':
        case '[':
            push(c, &p); // quando troviamo una parentesi aperta, la aggiungiamo alla pila
            break;
            // ora guardo le parentesi chiuse
        case ')':
        case ']':
            // se la mia pila e' vuota, SICURAMENTE NON VA BENE.
            // parentesi chiusa ISOLATA
            if (is_empty(p))
                return false;
            // ho trovato una parentesi chiusa. Mi chiedo: l'ultima parentesi aperta, era dello stesso tipo??
            // dov'e' l'ultima parentesi aperta? IN CIMA ALLA PILA
            char tmp = pop(&p); // tmp conterra' l'ultima parentesi APERTA
            // c corrisponde all'ultima parentesi?
            // tmp DOVREBBE essere una parentesi aperta corrispondente a c
            if (corrisponde(tmp, c) == false) { // corrisponde mi restituisce vero o falso
                // NON VA BENE
                return false; // se una parentesi non ha corrispondenza allora il controllo fallisce
            }
            break;
        }
    } // finisco la mia stringa
    // SE ARRIVO QUI, le parentesi chiuse trovate finora avevano una corrispondente parentesi aperta
    if (is_empty(p)) { // se la pila e' vuota vuol dire che tutte le parentesi avevano una corrispondenza
        return true;
    }
    return false;
    // mi rimane il caso in cui io dimentico una partentesi APERTA "(x+y"
}

int main()
{
    char stringa[] = "(x*y) + [4+(1/e*(2*x))]"; // OK

    if (controllo(stringa)) {
        printf("l'espressione e' ben parentesizzata!\n");
    } else {
        printf("l'espressione non va bene, ricontrolla\n");
    }
    return 0;
}