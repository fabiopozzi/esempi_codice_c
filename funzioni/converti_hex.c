/*
**Es 2
Scrivi una funzione C converti_hex che riceva come parametro un singolo carattere.
Nel caso in cui il carattere appartenga al range '0' - '9' oppure 'A' - 'F' la funzione restituisce
il valore decimale legato alla cifra esadecimale corrispondente
Esempio: '8' -> 8    'A' -> 10     'F' -> 15
Nel caso il valore non appartenga al range corretto la funzione deve segnalare l'errore nel modo più opportuno.

1. Quali sono le richieste in termini di Input ed Output espresse nel testo?
input = carattere : la cifra esadecimale in input
output = corrispettivo decimale del parametro in input, segnalazione errore se input non corretto.

2. Qual è il prototipo più adatto a risolvere il problema?

int converti_hex(char carattere)

3. Come possiamo implementare la funzione?

**
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int converti_hex(char carattere)
{
	int r;

	carattere = toupper(carattere);
	if(carattere < '0' || (carattere > '9' && carattere < 'A') || (carattere > 'F')) {
		return -1; // SEGNALAZIONE ERRORE
	}
    // devo convertire il carattere in decimale
    if (carattere <= '9')
		r = carattere - '0';
	else
		r = (carattere - 'A' ) + 10;

	return r;
}

int main()
{
	char a[3];
	int risultato;

	fgets(a, 3, stdin);

	risultato = converti_hex(a[0]);
	if (risultato < 0)
		printf("ERRORE, valore non valido");
	else
		printf("risultato: %d", risultato);

	return 0;
}
