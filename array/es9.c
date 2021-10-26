





/*
* Scrivi un programma che riceve in ingresso una sequenza di N numeri interi con il valore N
* inserito dall’utente e li memorizza in un vettore vetA.
* Terminato l’inserimento della sequenza di numeri,
* il programma deve visualizzare una riga di asterischi per ogni numero inserito
* in modo che il numero di asterischi nella riga sia pari al valore del numero inserito.
* Per esempio, dato il vettore vetA = [9 4 6] il programma deve visualizzare:
* –  vetA[0]: 9 *********       –  vetA[1]: 4 ****       –  vetA[2]: 6 ******
* */
#include <stdio.h>

int main()
{
	int n;
	int vetA[100];

	do {
		printf("inserisci un valore: ");
		scanf("%d", &n);
	} while((n <= 0) || (n > 100));

	int i;
	int kfc;
	for(i = 0; i < n; i++) {
		printf("inserisci numero");
		scanf("%d", &vetA[i]);
	}

	for(i = 0; i < n; i++){
		printf("vetA[%d]: %d ", i, vetA[i]);

		for(kfc = 0; kfc < vetA[i]; kfc++ ){
			printf("*");
		}
		printf("\n");

	}


}
