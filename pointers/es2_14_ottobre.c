/*
Es2:
Costruire un programma che richiede una sequenza di punti
(conclusa con la coppia 0 0) e mostra quelli
che appartengono al primo quadrante.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DIM 1

typedef struct {
    int x;
    int y;
} punto;

int main(void)
{
    int dimensione_allocata = DIM;
    punto* array_di_punti = (punto *)malloc(dimensione_allocata * sizeof(punto));
    int i = 0;

    if (array_di_punti == NULL) {
        printf("malloc failed");
        exit(EXIT_FAILURE);
    }
    while (1) { // ciclo infinito
        printf("inserire x: ");
        scanf("%d", &array_di_punti[i].x);
        printf("inserire y: ");
        scanf("%d", &array_di_punti[i].y);
        // se l'utente inserisce la coppia (0, 0) esco
        if ((array_di_punti[i].x == 0) && (array_di_punti[i].y == 0))
            break;
        i++;
        if (i == dimensione_allocata) {
            dimensione_allocata = dimensione_allocata * 2;
            punto *tmp = (punto *)realloc(array_di_punti, dimensione_allocata * sizeof(punto));
            if (tmp == NULL) {
                // qui volendo posso usare array_di_punti
                exit(EXIT_FAILURE);
            } else {
                array_di_punti = tmp;
                printf("Ho ingrandito l'array fino a %d elementi", dimensione_allocata);
            }
        }
    }

    // stampa a video solo i punti appartenenti al primo quadrante
    for(int j = 0; j < i; j++){
        if((array_di_punti[j].x >= 0) && (array_di_punti[j].y >= 0)) {
            printf("x: %d\ty: %d\n", array_di_punti[j].x, array_di_punti[j].y);
        }
    }
    free(array_di_punti); // MI RACCOMANDO free() prima di uscire
    return 0;
}