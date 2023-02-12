/*
Scrivere una funzione triangolo
che stampi un triangolo di base n composto utilizzando un carattere c
ricevuto come parametro.
La funzione deve restituire ZERO se la stampa è stata fatta correttamente,
un valore negativo (-1) se il primo parametro n non è valido.

int triangolo(char c, int n);

Deve portare al risultato
xxxx
xxx
xx
x


Scrivere un programma (main) che chiami la funzione triangolo
con un valore positivo ed uno negativo ed una lettera a vostra scelta.
*/
#include <stdio.h>

int triangolo(char c, int n);

int main()
{
	int risultato;
	risultato = triangolo('x', 4);
	printf("%d\n", risultato);
}

int triangolo(char c, int n)
{
	int i, j;

	if( n <= 0 )
		return -1;

	//primo for conta le righe da stampare
	for(i = 0; i < n ; i++){
		// devo stampare una riga
		for(j = 0; j < i; j++){
			printf(" ");
		}
		for(j = 0; j < n - i; j++){
			printf("%c", c);
		}
		printf("\n");
	}

	return 0;
}
