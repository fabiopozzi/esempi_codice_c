#include <stdio.h>

#define NUM_RIGHE 2
#define NUM_COL 3

int main()
{
	int i, j;
	int conto = 0;                    // prima riga , seconda riga
	int matrice[NUM_RIGHE][NUM_COL] = { {1, 2, 3}, {90, 91, 92} };

	int semplice_vettore[3] = { 42, 28, 36 };

	semplice_vettore[0] = 42;
	semplice_vettore[1] = 28;
	semplice_vettore[2] = 36;

	// vogliamo ottenere
	// 1  2  3
	// 4  5  6
	// 7  8  9

	for(i = 0; i < NUM_RIGHE; i++) {
	 	for(j = 0; j < NUM_COL; j++) {
	 		matrice[i][j] = conto;
	 		conto++;
	 	}
	 }

	for(i = 0; i < NUM_RIGHE; i++) {
		for(j = 0; j < NUM_COL; j++) {
			printf("%d\t", matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

}
