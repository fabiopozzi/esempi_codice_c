/*
Scrivere un programma C che dichiari ed inizializzi
(ad un valore qualsiasi) tre variabili:
- un double
- un int
- un char
A questo punto dichiari ed inizializzi un puntatore ad ognuna
delle tre variabili.
Il programma deve quindi stampare l'indirizzo, il valore contenuto,
la dimensione in memoria (in bytes) di ognuna delle 6 variabili.

Note:
Usa lo specificatore di formato “0x%x” o "%p" per stampare gli indirizzi
in esadecimale.
Usa l'operatore sizeof per determinare la dimensione in memoria
di ogni variabile
*/
#include <stdio.h>
struct prova {
    int p1;
    int p2;
    double p3;
    struct {
        int a1;
        int a2;
    } p4;
} variabile_prova;

int funzione_esempio(struct prova *p, int *pint);

int main()
{
    double v1 = 3.14;
    int v2;
    char v3 = 'a';


    struct prova *pprova = &variabile_prova; // puntatore a struct
    double *pv1 = &v1;  //puntatore a float
    int *pv2 = &v2;  // puntatore ad int
    char *pv3 = &v3;  // puntatore a char

    // printf("v1 vale %f, dimensione %lu\n", v1, sizeof(v1));
    // printf("dereferenzio pv1 %f indirizzo contenuto nel puntatore %p dimensione puntatore %lu\n", *pv1, pv1, sizeof(pv1));

    // printf("v3 vale %c, dimensione %lu\n", v3, sizeof(v3));
    // printf("dereferenzio pv3 %c indirizzo contenuto nel puntatore %p dimensione puntatore %lu", *pv3, pv3, sizeof(pv3));
    //printf("dimensione struct prova %lu dimensione puntatore %lu", sizeof(prova1), sizeof(pprova));
    funzione_esempio(&variabile_prova, &v2);
    printf("%d %d %d", *pv2, variabile_prova.p1, variabile_prova.p4.a1);
}

int funzione_esempio(struct prova *p, int *pint)
{
    *pint = 42;
    p->p2 = 13; //   0x1234 + sizeof(int) = 0x1238
    p->p4.a1 = 128;
    return 0;
}