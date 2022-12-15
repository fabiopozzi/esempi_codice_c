/*
Scrivi un programma che genera casualmente un numero compreso tra 0 e 255 e lo trasforma in
un numero binario utilizzando un vettore di dimensione 8
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

int main() {
	int num_casuale;
	int risultato[N] = {0}; // ho inizializzato il vettore con gli zeri
	int i;

	srand(time(0));

	num_casuale = rand() % 256; // ottengo un numero tra 0 e 255

	printf("num casuale: %d\n", num_casuale);
	for(i = 0; i < N; i++) {
		risultato[i] = num_casuale % 2;
		num_casuale = num_casuale / 2;
		if (num_casuale == 0)
			break;
	}

	for(i = N - 1; i > -1; i--) {
		printf("%d ", risultato[i]);
	}
	printf("\n");

	return 0;
}
