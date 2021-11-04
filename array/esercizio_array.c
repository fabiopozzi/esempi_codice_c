#include<stdio.h>
/*
Scrivere un programma che chieda quanti
valori verranno introdotti dalla tastiera (max
100), li chieda tutti e successivamente
visualizzi prima tutti i valori pari nell’ordine in
cui sono stati inseriti e poi tutti i valori dispari
nell’ordine inverso.
Esempio: dati i valori: 8 1 3 2 8 6 5, il
programma visualizza: 8 2 8 6 5 3 1
*/

int main()
{
	int i, n;
	int v[100];

	do {
		printf("quanti numeri vuoi?");
		scanf("%d", &n);
	} while((n < 0) || (n > 100));

	// leggo i valori dall'utente
	for(i = 0; i < n; i++) {
		printf("inserisci il %d° valore", i+1);
		scanf("%d", & v[i]);
	}

	printf("numeri pari in ordine:\n");
	for(i = 0; i < n; i++) {
		if (v[i] % 2 == 0) { // pari
			printf("%d ", v[i]);
		}
	}

	printf("numeri dispari in ordine INVERSO:\n");

	for(i = n - 1; i >= 0; i--) {
		if (v[i] % 2 == 1) { // dispari
			printf("%d ", v[i]);
		}
	}

	// stampo tutto l'array
	for(i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
