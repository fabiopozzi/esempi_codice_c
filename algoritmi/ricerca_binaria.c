#include<stdio.h>

#define N 10

int main()
{
	int v[N] = { 0, 1, 6, 9, 15, 4, 8, 42, 1, 10};
	int chiave, indice_el;
	int i;

	int inizio, fine, centro;

	printf("inserisci l'elemento da cercare: ");
	scanf("%d", &chiave);

	inizio = 0;
	fine = N - 1;
	indice_el = -1; // inizializzo con un valore non valido

	while(indice_el == -1 && inizio <= fine) {
		centro = (inizio + fine) / 2;

		if( v[centro] == chiave ) {
			indice_el = centro; // trovata
		} else {
			if (chiave > v[centro]) {
				inizio = centro + 1; // prosegui con parte destra
			} else {
				fine = centro - 1; // continua con parte sx
			}
		}
	}

	if (indice_el != -1) {
		printf("ho trovato il valore %d in posizione %d\n", chiave, indice_el);
	} else {
		printf("elemento %d non trovato\n", chiave);
	}
	return 0;
}
