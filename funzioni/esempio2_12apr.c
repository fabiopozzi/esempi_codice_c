/*
Realizzare una funzione che riceva in input un array di interi,
la sua lunghezza e calcoli la media degli elementi.
La funzione restituisce il NUMERO di valori dell'array maggiori della media

come faccio a restituire SIA la media SIA il numero di valori maggiori
della media SIA il numero di valori minori della media?
*/
#include <stdio.h>

void conta(int array[], int l, float *media, int *maggiori, int *minori)
{
	int i;
	int somma = 0;

	*maggiori = 0;
	*minori = 0;
	// calcolo media
	for(i = 0; i < l; i++){
		somma = somma + array[i];
	}
	*media = (float)somma / l;

	// contare quanti valori sono maggiori di media
	for(i = 0; i < l; i++) {
		if(array[i] > *media){
			*maggiori += 1;
		} else {
			*minori += 1;
		}
	}

}
const int n = 8;
int main()
{
	float m;
	int conto_maggiori = 120;
	int conto_minori = 42000;

	float m2;
	int conto_maggiori2 = 120;
	int conto_minori2 = 42000;
	int v[] =  {1, 3, 5, 7, 11, 13, 17, 22};

	conta(v, n, &m, &conto_maggiori, &conto_minori );
	printf("media %f, maggiori di media %d, minori %d", m, conto_maggiori,
		conto_minori);

	conta(v, n, &m2, &conto_maggiori2, &conto_minori2 );
	printf("media %f, maggiori di media %d, minori %d", m, conto_maggiori,
		conto_minori);

	return 0;
}
