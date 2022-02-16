#include<stdio.h>

#define N 10

int main()
{
	int v[N] = { 0, 1, 6, 9, 15, 4, 8, 42, 1, 10};
	int chiave, trovato;
    int pos;
	int i = 1;

	int primo, ultimo, medio;

	printf("inserisci l'elemento da cercare: ");
	scanf("%d", &chiave);

	primo = 0;
	ultimo = N - 1;
    trovato = 0;
	pos = -1; // inizializzo con un valore non valido

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

	if (trovato) {
		printf("ho trovato il valore %d in posizione %d\n", chiave, pos);
	} else {
		printf("elemento %d non trovato\n", chiave);
	}
	return 0;
}
