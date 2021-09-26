#include <stdio.h>
/*
 * Scrivere un programma che richieda il numero di ore, minuti e secondi che compongono
 * un tempo e visualizzi quindi l'equivalente espresso in secondi.
 */

#define SECONDI_IN_ORA 3600
#define SECONDI_IN_MINUTO 60

int main()
{
	int ore, minuti, secondi;

	printf("Inserisci ore: ");
	scanf("%d", &ore);
	printf("Inserisci minuti: ");
	scanf("%d", &minuti);
	printf("Inserisci secondi: ");
	scanf("%d", &secondi);

	int secondi_totali;

	secondi_totali = (ore * SECONDI_IN_ORA) + (minuti * SECONDI_IN_MINUTO) + secondi;

	printf("numero totale secondi: %d\n", secondi_totali);

	return 0;
}
