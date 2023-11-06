/*
** Scrivere un programma che calcoli e visualizzi la media di N numeri interi positivi immessi dall'utente.
** Il numero deve essere chiesto nuovamente se l'utente inserisce un valore negativo o nullo.
*/
#include <stdio.h>

#define N 10

int main()
{
	int i, num;
	float media = 0;

	for(i = 0; i < N; i++) {
		  do {
			printf("inserisci numero: ");
			scanf("%d", &num);
          } while (num <= 0);
		  media = media + num;
	}
	media = media / N;
	printf("La media vale %f\n", media);

	return 0;
}
