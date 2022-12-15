#include <stdio.h>
#include <stdlib.h>
/*
 * Costruire un programma che legge il nome e tempo (con formato h:m:s) di una sequenza di maratoneti e al termine li stampa a video.
 * La sequenza termina quando l'utente inserisce la sequenza 0:0:0
 * N.B.
 * scanf(“%d:%d:%d”, &A, &B, &C); permette di leggere 3 valori separati da ':'
 */

struct maratoneta {
    char nome[50];
    int h;
    int m;
    int s;
};

void stampa(struct maratoneta *p, int count)
{
    for(int i = 0; i < count; i++) {
        printf("nome: %s\t", p[i].nome);
        printf("tempo: %d:%d:%d\n", p[i].h, p[i].m, p[i].s);
    }
}

int main()
{
    int h, m, sec;
    int n = 4;
    int i = 0;
    int num_arg;
    // alloca memoria per n interi
    struct maratoneta* s = (struct maratoneta *)malloc(n * sizeof(struct maratoneta));
    if (s == NULL) {
        printf("malloc fallita, muori male");
        exit(-1);
    }
    // chiedo valori all'utente
    while (1) {
        printf("inserisci tempo: ");
        num_arg = scanf("%d:%d:%d", &h, &m, &sec);
        if (num_arg != 3) {
            continue;
        }
        if (h == 0 && m == 0 && sec == 0) {
            break;
        }
        else {
            s[i].h = h;
            s[i].m = m;
            s[i].s = sec;
            printf("inserisci nome %d: ", i+1);
            scanf("%49s", s[i].nome);
            i++;
            if (i == (n - 1)) { // sto per finire la memoria
                n = n * 2;
                s = (struct maratoneta *)realloc(s, n * sizeof(struct maratoneta));
                if (s != NULL) {
                    printf("riallocato con dimensione %d\n", n);
                } else {
                    printf("realloc fallita, muori male");
                    exit(-1);
                }
            }
        }
    }

    //stampo tutti i valori
    stampa(s, i);

    free(s);
    return 0;
}
