





#include <stdio.h>
#define NUMERI 5
int main()
{
	int bello[NUMERI];
	int i; // indice

	// leggere i miei numeri
	for(i = 0; i < NUMERI; i++) {
		printf("Inserisci un numero: ");
		scanf("%d", &bello[i]);
	}

	// stampo in ordine
	for(i = NUMERI - 1; i >= 0; i = i - 1) {
		printf("numero: %d\n", bello[i]);
	}

	return 0;
}
