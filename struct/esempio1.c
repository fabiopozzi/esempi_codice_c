#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char targa[16];
    char marca[16];
    char modello[16];
    int anno;
} automobile;

int main () {
    automobile *a;

    a = (automobile *) malloc(sizeof(automobile));

    printf("inserisci targa: ");
    scanf("%s", a->targa);

    printf("inserisci anno: ");
    scanf("%d", &a->anno);

    printf("targa %s\n", a->targa);
    printf("anno %d\n", a->anno);
}
