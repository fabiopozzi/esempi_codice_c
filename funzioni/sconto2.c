/*
Scrivere una funzione che riceva in ingresso un numero float corrispondente al
prezzo iniziale di un articolo e un numero intero sconto rappresentante il
valore percentuale di sconto
(se ad esempio sconto = 20, significa che all'articolo si applicherà uno sconto del 20%)
e restituisca il prezzo scontato dell'articolo per mezzo di un parametro
passato per indirizzo.

La funzione deve restituire un valore negativo in caso di parametri non validi
(prezzo negativo, percentuale non valida, etc) e zero in caso di esecuzione corretta.
*/

#include<stdio.h>

int sconto2(int sconto, float prezzo_iniziale, float *risultato);

int main()
{
	float r;
	int ok = sconto2(20, 10000, &r);
	if (ok < 0) {
		printf("PARAMETRO NON VALIDO\n");
		return -1;
	}
	printf("il risultato vale %.2f", r);
	return 0;
}

int sconto2(int sconto, float prezzo_iniziale, float *risultato)
{
	// 1a cosa: VALIDARE INPUT
	if (sconto < 0 || sconto > 100)
		return -1;
	if (prezzo_iniziale <= 0)
		return -2;

	float tmp = (prezzo_iniziale * sconto) / 100;
	*risultato = prezzo_iniziale - tmp;

	return 0;
}
