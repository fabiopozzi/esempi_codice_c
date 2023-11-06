#include<stdio.h>

typedef struct {
    int *campo1;
    int campo2;
    float campo3;
} franco_t;
/*
Scrivere una funzione mycalloc che riceva un numero intero n
ed un valore char c
La funzione deve restituire un puntatore ad un array di caratteri
di dimensione n, inizializzato con il valore c.
*/
char *mycalloc(int n, char c) {
    if (n <= 0)
        return NULL;
    char *p = (char *)malloc(n * sizeof(char));
    if (p == NULL)
        return NULL;
    // tutto bene
    for(int i = 0; i < n; i++) {
        p[i] = c;
    }
    return p;
}
