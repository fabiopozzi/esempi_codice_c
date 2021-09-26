#include <stdio.h>
/*
 * Scrivere un programma che richieda un tempo in secondi e ne visualizzi l'equivalente in
 * ore, minuti e secondi.
 */
#define SECONDI_IN_ORA 3600
#define SECONDI_IN_MINUTO 60

int main()
{
	int secondi;
	printf("inserisci numero secondi: ");
	scanf("%d", &secondi);

	int ore = secondi / SECONDI_IN_ORA;
	printf("Numero ore: %d\n", ore);

	secondi = secondi % SECONDI_IN_ORA; // quanti secondi avanzano dopo aver calcolato le ore?

	int minuti = secondi / SECONDI_IN_MINUTO;
	printf("Numero minuti: %d\n", minuti);

	secondi = secondi % SECONDI_IN_MINUTO; // quanti secondi avanzano dopo aver calcolato i minuti?
	printf("Numero secondi: %d\n", secondi);

	return 0;
}
