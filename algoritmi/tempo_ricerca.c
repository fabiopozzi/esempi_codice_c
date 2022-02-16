#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000

int main()
{
	int v[N];
	int chiave, trovato;
    int pos;
	int i = 1;

	int primo, ultimo, medio;

    for(i = 0; i < N; i++) {
        v[i] = i;
    }

	printf("inserisci l'elemento da cercare: ");
	scanf("%d", &chiave);

	primo = 0;
	ultimo = N - 1;
    trovato = 0;
	pos = -1; // inizializzo con un valore non valido

    clock_t t_inizio = clock();

	while(trovato == 0 && primo <= ultimo) {
        printf("iterazione %d: ", i);
        printf("primo vale %d, ultimo vale %d\n", primo, ultimo);

		medio = (primo + ultimo) / 2;

		if( v[medio] == chiave ) {
            trovato = 1;
			pos = medio; // trovata
		} else {
			if (chiave > v[medio]) {
				primo = medio + 1; // prosegui con parte destra
			} else {
				ultimo = medio - 1; // continua con parte sx
			}
		}
        i++;
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
