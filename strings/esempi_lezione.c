#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Es2:
//     Programma che legge da tastiera quattro stringhe che rappresentano interi,
//     le converte in interi, le somma, e stampa la somma.
#define N 4
int main(int argc, char* argv[])
{
    long numeri[N];
    char stringa[100];
    for (int i = 0; i < N; i++) {
        printf("inserisci il %d numero: ", i + 1);
        scanf("%99s", stringa);

        // numeri[i] = atoi(stringa); // converto char to integer
        numeri[i] = strtol(stringa, NULL, 10); // string to long
        // usare sscanf()
        printf("%ld\n", numeri[i]);
    }
    long somma = 0;
    for (int i = 0; i < N; i++) {
        somma += numeri[i];
    }
    printf("somma vale %ld\n", somma);

    return 0;
}