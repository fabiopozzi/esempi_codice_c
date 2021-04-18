/*
Realizzare una funzione che riceva in input un array di interi,
la sua lunghezza e calcoli la media degli elementi.
La funzione restituisce il NUMERO di valori dell'array maggiori della media
*/
#include <stdio.h>

int conta_maggiori_media(int array[], int l);

int main()
{
	int v[] =  {1, 3, 5, 7, 11, 13, 17, 22};

	int n = conta_maggiori_media(v, 8);
	printf("i valori maggiori della media sono %d\n", n);

	return 0;
}

int conta_maggiori_media(int array[], int l)
{
	int i;
	float media = 0;
	int somma = 0;
	int contatore = 0;
	// calcolo media
	for(i = 0; i < l; i++){
		somma = somma + array[i];
	}
	media = (float)somma / l;
	printf("la media vale %f\n", media);

	// contare quanti valori sono maggiori di media
	for(i = 0; i < l; i++) {
		if(array[i] > media){
			printf("%d\n", array[i]);
			contatore++;
		}
	}

	return contatore;
}
