/*Scrivi una funzione che permetta di stampare tutto il contenuto di una lista collegata.*/
#include<stdio.h>
#include<stdlib.h>

struct Magia {
	int mago;
	struct Magia* prossimoMago;
};

int main() {

	struct Magia* testaMago = NULL;
	struct Magia* maghettoTemporaneo;
	struct Magia* magoSpeciale;
	int contaMaghi = 0, i, magoTemporaneo;


	printf("inserimento, inserisci 0 per uscire\n");
	do {
		scanf("%d", &magoTemporaneo);

		maghettoTemporaneo = (struct Magia*)malloc(sizeof(struct Magia));
		if (maghettoTemporaneo == NULL) {
			printf("Bomba magica!!");
			exit(-1);
		}
		else {

			maghettoTemporaneo->mago = magoTemporaneo;
			maghettoTemporaneo->prossimoMago = testaMago;
			testaMago = maghettoTemporaneo;
			contaMaghi++;
		}

	} while (magoTemporaneo != 0);

	magoSpeciale = testaMago;
	printf("\n");
    while (magoSpeciale != NULL) {
		printf("%d\n", magoSpeciale->mago);
		magoSpeciale = magoSpeciale->prossimoMago;
	}


}
