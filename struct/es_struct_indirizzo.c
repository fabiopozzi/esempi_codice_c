#include <stdio.h>
#include <stdlib.h>

struct automobile {
    char marca[16];
    char modello[16];
    int anno;
};

// SE HO UN PUNTATORE A STRUCT
// per accedere ai membri della struttura dati devo usare ->
void inserisci_auto(struct automobile *a)
{
    printf("inserisci marca: ");
    scanf("%s", a->marca);

    printf("inserisci anno: ");
    scanf("%d", &a->anno);

}

void inserisci_array_auto(struct automobile b[], int dim)
{
    for(int i = 0; i < dim; i++) {
        printf("inserisci marca: ");
        scanf("%s", b[i].marca);

        printf("inserisci anno: ");
        scanf("%d", &b[i].anno);
    }

}

struct automobile ins_auto()
{
    struct automobile a;
    printf("inserisci marca: ");
    scanf("%s", a.marca);

    printf("inserisci anno: ");
    scanf("%d", &a.anno);

    return a;
}

void inserisci_tante_auto(struct automobile tante_auto[])
{
    for(int i = 0; i < 10; i++){
        tante_auto[i] = ins_auto();
        inserisci_auto(&tante_auto[i]);
    }
}

void stampa_auto(struct automobile am)
{
    printf("marca %s\n", am.marca);
    printf("anno %d\n", am.anno);
}

int main () {
    struct automobile am[5];
    struct automobile panda;

    inserisci_auto(&panda);
    for(int i = 0; i < 5; i++){
        inserisci_auto(&am[i]);
        am[i] = ins_auto();
    }
    inserisci_tante_auto(am);
    inserisci_array_auto(am, 5);

    stampa_auto(am[0]);
}
