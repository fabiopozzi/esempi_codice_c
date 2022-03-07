/*
** Scrivere una funzione che, ricevuti in ingresso due numeri interi, restituisca il valore minimo.
Utilizzare la funzione per visualizzare il minimo di ciascuna delle seguenti coppie di valori:
(45, 70), (32, -11), (0, 100).
*/
#include <stdio.h>

int calcola_minimo(int v1, int v2)
{
	int risultato;
	// calcolare il minimo
	if (v1 < v2) {
		risultato = v1;
	} else {
		risultato = v2;
	}
	return risultato;
}

int main()
{
	int minimo;
	int val2;

	scanf("%d", &val2);
	minimo = calcola_minimo(45, val2);
	printf("il minimo vale %d", minimo);

	return 0;
}
