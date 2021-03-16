#include <stdio.h>

// SCRIVI UNA FUNZIONE CHE SCAMBI IL VALORE DI DUE VARIABILI
void scambia(int *x, int *y)
{
	int tmp;
	// COME LI SCAMBIO?
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("a: %d b: %d\n", a, b); // 10 20
	scambia(&a, &b);
	printf("a: %d b: %d\n", a, b); // 20 10

	return 0;
}

