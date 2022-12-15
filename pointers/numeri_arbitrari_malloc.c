#include <stdio.h>
#include <stdlib.h>
// stampo array
void stampa(int *array, int n)
{
    printf("valori: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// leggiamo successione di interi di lunghezza arbitraria
// gestendo la memoria

int main()
{
    int num;
    int n = 4;
    int count = 0;
    // alloca memoria per n interi
    int* p = (int*)malloc(n * sizeof(int));
    if (p == NULL) {
        printf("malloc fallita, muori male");
        exit(-1);
    }
    // chiedo valori all'utente
    do {
        printf("inserisci numero %d: ", count+1);
        scanf("%d", &num);
        getchar(); // consumo lo \n che altrimenti si accumula
        if (num != 0) {
            p[count] = num;  // inserisco in array
            count++;
            if (count == (n - 1)) { // sto per finire la memoria
                n = n * 2;
                p = (int *)realloc(p, n * sizeof(int));
                if (p != NULL) {
                    printf("riallocato con dimensione %d\n", n);
                } else {
                    printf("realloc fallita, muori male");
                    exit(-1);
                }
            }
        }
    } while(num != 0);

    //stampo tutti i valori
    stampa(p, count);

    free(p);
    return 0;
}