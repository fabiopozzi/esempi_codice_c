#include <stdio.h>
// COSTANTI
#define NUM 3

const int num = 15;


int main()
{
    const int dim_array = 10;

    int i;  // INDICE dell'array
    int valori[NUM];  // ARRAY

    // riempio l'array di valori
    for(i = 0; i < NUM; i++){
        printf("INSERISCI UN VALORE: ");
        scanf("%d", &valori[i]); // LEGGO DA TASTIERA NELLA POS. I-ESIMA
    }

    // stampo l'array di valori
    for(i = 0; i < NUM; i++){
        printf("Pos: %d, valore: %d\n", i, valori[i]); // LEGGO il valore della posizione i-esima
    }

    return 0;
}