/*
Genera casualmente 10 numeri, memorizzali in un array
ed effettua lo scambio tra il massimo e minimo elemento
(supponendo che i valori dell’array siano tutti distinti
tra loro)
prima: [1, 5, 1200, 56, 980, 4, 0, 42, 208, 104]
min = 0
max = 1200
dopo: [1, 5, 0, 56, 980, 4, 1200, 42, 208, 104]
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main()
{
	int array[N];
	int i;
	int max, min;
	int pos_max, pos_min;

	srand(time(NULL));

	// 1 generare array numeri casuali
	for(i = 0; i < N; i++){
		array[i] = (rand() % 100) + 1;
	}
	// 2 trovare massimo e minimo e la loro posizione
	max = array[0];
	pos_max = 0;
	min = array[0];
	pos_min = 0;
	for(i = 0; i < N; i++){
		if (array[i] > max) {
			max = array[i];
			pos_max = i;
		}
		if (array[i] < min) {
			min = array[i];
			pos_min = i;
		}
	}
	printf("massimo: %d posizione %d\n", max, pos_max);
	printf("minimo: %d posizione %d\n", min, pos_min);
	// 3 scambiare massimo e minimo
	int tmp;
	tmp = array[pos_max];
	array[pos_max] = array[pos_min];
	array[pos_min] = tmp;

	// stampa un array
	for(i = 0; i < N; i++){
		printf("%d ", array[i]);
	}
}
