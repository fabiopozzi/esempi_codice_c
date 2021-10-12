#include <stdio.h>

/* Il programma calcola il numero di cifre decimali
 * che compongono un numero inserito dall'utente */
int main()
{
	int n;
	int i = 0;

	printf("Inserisci un numero ");
	scanf("%d", &n);

	while(n > 0) {
		i++;
		n = n / 10;
	}
	printf("Il numero contiene %d cifre\n", i );

	return 0;
}
