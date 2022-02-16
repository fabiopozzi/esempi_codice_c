#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000

int main()
{
	int v[N];
	int chiave, trovato;
    int pos;
	int i;

	int primo, ultimo, medio;

    for(i = 0; i < N; i++) {
        v[i] = i;
    }

	printf("inserisci l'elemento da cercare: ");
	scanf("%d", &chiave);


    clock_t t_inizio = clock();

    for(i = 0; i < N; i++) {
        printf("iterazione %d\n", i);
        if(v[i] == chiave) {
            trovato = 1;
            pos = i;
            break;
        }
    }

    clock_t t_fine = clock();
    double tempo = ((double)t_fine - (double)t_inizio) / CLOCKS_PER_SEC;
    printf("time elapsed: %.2f\n", tempo);

	if (trovato) {
		printf("ho trovato il valore %d in posizione %d\n", chiave, pos);
	} else {
		printf("elemento %d non trovato\n", chiave);
	}
	return 0;
}
