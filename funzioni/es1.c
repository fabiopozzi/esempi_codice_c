#include<stdio.h>

void somma(int val1, int val2, int *val3)
{
	// val1 int
	// val2 int
	// val3 FRECCIA
	// val1 + val2 ed il risultato lo mettiamo nella variabile
	// PUNTATA da val3
	*val3 = val1 + val2;
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
	int r = 0;
	int i;
	int j;
	somma(10, 20, &r);
	printf("r vale %d\n", r);

	i = 100;
	somma(i, 20, &r);
	printf("r vale %d\n", r);

	i = 1000;
	somma(i, 20, &r);
	printf("r vale %d\n", r);

	somma(100000, 20, &r);
	/* stampa(7); */
	/* stampa(9); */
	/* stampa(3); */

}
