/*
Realizzare una funzione che riceva in input un array di interi,
la sua lunghezza e calcoli la media degli elementi.
La funzione restituisce il NUMERO di valori dell'array maggiori della media

come faccio a restituire SIA la media SIA il numero di valori maggiori
della media SIA il numero di valori minori della media?
*/
#include <stdio.h>

struct risultato {
	float media;
	int maggiori;
	int minori;
};

struct risultato conta_maggiori_media(int array[], int l);

int main()
{
	int v[] =  {1, 3, 5, 7, 11, 13, 17, 22};

	struct risultato r = conta_maggiori_media(v, 8);
	printf("media vale %f, valori maggiori %d, valori minori %d\n", r.media, r.maggiori,
		r.minori);

	return 0;
}

struct risultato conta_maggiori_media(int array[], int l)
{
	int i;
	struct risultato dunz = {0};
	int somma = 0;
	// calcolo media

	for(i = 0; i < l; i++){
		somma = somma + array[i];
	}
	dunz.media = (float)somma / l;

	// contare quanti valori sono maggiori di media
	for(i = 0; i < l; i++) {
		if(array[i] > dunz.media){
			printf("%d\n", array[i]);
			dunz.maggiori++;
		} else {
			dunz.minori++;
		}
	}

	return dunz;
}
