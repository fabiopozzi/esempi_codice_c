// SCRIVERE UNA FUNZIONE IN GRADO DI SCAMBIARE
// DUE VALORI
#include <stdio.h>

void scambio(int *p1, int *p2)
{
    static int tmp;

	printf("tmp vale %d\n", tmp);
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main()
{
	char nome[][10] = {"pippo", "pluto"};


	int x = 5;
	int y = 125;

	scambio(&x, &y);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	scambio(&x, &y);
}
