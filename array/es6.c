







/*
* Scrivi un programma che generi casualmente 30 numeri e li memorizzi in due vettori:
* il primo vettore deve contenere solo i numeri pari mentre il secondo vettore i numeri dispari.
* */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 30
int main()
{
	int i;
	int pari[N], idx_pari = 0;
	int dispari[N], idx_dispari = 0;
	int tmp;

	srand(time(0)); // INIZIALIZZO IL GENERATORI DI NUMERI PSEUDOCASUALI

	for(i = 0; i < N; i++)
	{
		tmp = rand() % 101;
		if (tmp % 2 == 0){ // PARI
			pari[idx_pari] = tmp;
			idx_pari++;
		} else {
			dispari[idx_dispari] = tmp;
			idx_dispari++;
		}
	}

	printf("I numeri pari estratti sono:\n");
	for(i = 0; i < idx_pari; i++) {
		printf("%d\n", pari[i]);
	}

	printf("I numeri dispari estratti sono:\n");
	for(i = 0; i < idx_dispari; i++) {
		printf("%d\n", dispari[i]);
	}
	return 0;
}
