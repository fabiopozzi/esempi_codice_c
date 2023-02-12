#include <stdio.h>

/*
** Es 1
Una funzione con prototipo int val_ass(int)
restituisce il valore assoluto dell'argomento
ricevuto.
Il valore assoluto di un numero è sempre positivo o nullo.
*/

int val_ass(int numero);

int main()
{
	int v1 = val_ass(-10);
	int v2 = val_ass(0);
	int v3 = val_ass(10);

	printf("v1 %d\t v2: %d, v3: %d\n", v1, v2, v3);
}

int val_ass(int numero)
{
	if (numero < 0)
		numero = numero * (-1);

	return numero;
}
