#include <stdio.h>
int somma(int s1, int s2) // parametri FORMALI
{
	int s; // locale alla funzione somma

	s = s1 + s2;
	return s;
}

int main()
{
	int i = 0, j;
	j = 20;

	j = somma(10, 20); // 10 e 20 sono PARAMETRI ATTUALI
	if (somma(10, 20) > 40)
		printf("AAAAAAAAAA");

	int s1 = 40;
	int s2 = -20;
	j = somma(s1, s2); // s1 ed s2 sono parametri ATTUALI
}
