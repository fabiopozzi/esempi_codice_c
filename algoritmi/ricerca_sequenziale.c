#include<stdio.h>

#define N 10

int main()
{
	int v[N] = { 0, 1, 6, 9, 15, 4, 8, 42, 1, 10};
	int i;
	int indice_el;
	int trovato = 0;

	int chiave;

	printf("inserisci l'elemento da cercare: ");
	scanf("%d", &chiave);

	indice_el = -1; // inizializzo con un valore non valido

	for (i = 0; (i < N) && (trovato == 0); i++) {
		if (v[i] == chiave) {
			indice_el = i;
			trovato = 1;
		}
	}

	if (indice_el != -1) {
		printf("ho trovato il valore %d in posizione %d\n", chiave, indice_el);
	} else {
		printf("elemento %d non trovato\n", chiave);
	}
	return 0;
}
// TODO: come realizzare il conteggio delle occorrenze?
