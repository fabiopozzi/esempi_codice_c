#include <stdio.h>

void f(int valore) // OTTENGO UNA COPIA del parametro
{
	valore = 144;
}

void g(int *puntatore)
{
	printf("la variabile vale %d\n", *puntatore);
	printf("l'indirizzo vale %p\n", puntatore);
	*puntatore = 144; // MODIFICA LA VARIABILE PUNTATA
}

int main()
{
	int i;

	i = 42;
	f(i); // F NON MODIFICHERA MAI NELLA VITA i
	printf("i vale %d\n", i); // i vale 42

	scanf("%d", &i);
	g(&i);

	printf("i vale %d\n", i); // i vale altro
}
