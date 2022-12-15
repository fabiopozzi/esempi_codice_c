#include <stdio.h>
#include <stdlib.h>

struct automobile {
    char targa[1600];
    char marca[16];
    char modello[16];
    int anno;
    int *a;
} ;

// ho un array di strutture dati automobile
void inserisci_auto(struct automobile *a)
{
    printf("inserisci targa: ");
    scanf("%s", a->targa);

    printf("inserisci anno: ");
    scanf("%d", &a->anno);

}

struct automobile ins_auto()
{
    struct automobile a;
    printf("inserisci targa: ");
    scanf("%s", a.targa);

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
    printf("targa %s\n", am.targa);
    printf("anno %d\n", am.anno);
}

int main () {
    struct automobile am;

    inserisci_auto(&am);

    stampa_auto(am);
}
