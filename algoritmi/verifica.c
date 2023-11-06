#include<stdio.h>

#define N 10

int main()
{
	int v[N] = { 0, 1, 6, 9, 15, 24, 28, 42, 51, 100};
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

	printf("p: %d, u: %d\n", primo, ultimo);
	while (trovato == 0 && primo <= ultimo) {

		medio = (primo + ultimo) / 2;

		if (v[medio] == chiave) {
            trovato = 1;
			pos = medio; // trovata
		} else {
			if (chiave > v[medio]) {
				primo = medio + 1; // prosegui con parte destra
			} else {
				ultimo = medio - 1; // continua con parte sx
			}
		}
        printf("p vale %d, u vale %d\n", primo, ultimo);
	}

	if (trovato != 0) {
		printf("pos %d\n", pos);
	}
	return 0;
}
