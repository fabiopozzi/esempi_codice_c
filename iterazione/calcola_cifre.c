#include <stdio.h>

int main()
{
	int n;
	int i = 0;

	printf("Inserisci un numero ");
	scanf("%d", &n);

	/* calcola il numero di cifre decimali che il numero contiene */
	while(n > 0) {
		i++;
		n = n / 10;
	}
	printf("Il numero contiene %d cifre\n", i );

	return 0;
}
