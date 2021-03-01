#include<stdio.h>

int somma(int val1, int val2, int val3)
{
	int risultato = val1 + val2 + val3;

	printf("%d\n", val1);
	val1 = 0;
	return risultato;
}

void stampa(int x)
{
	// tutto quello che dovevo fare sta qui
	if (x == 3) {
		printf("NO\n");
		return;
	}

	printf("CIAO CIAO CIAO\n");
	// qui posso fare qualsiasi cosa

}

int main()
{
	int i;
	int j;
	j = somma(10, 20, 30);

	i = 100;
	j = somma(i, 20, 30);

	i = 1000;
	j = somma(i, 20, 30);

	j = somma(100000, 20, 30);
	stampa(7);
	stampa(9);
	stampa(3);
	printf("AAAAA\n");

}
