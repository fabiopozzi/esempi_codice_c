/*
** ELENCO TELEFONICO
** inserimento: inserire una stringa nella prima posizione libera
** cancellazione di un elemento indicando la posizione
*/
#include <stdio.h>
#include <string.h>

#define N_RIGHE 100

void inserimento(char elenco[][100], int n_elementi, char stringa[])
{
	int i;
	int pos = -1;
	// trova la prima posizione libera
	for(i = 0; i < n_elementi; i++) {
		if( elenco[i][0] == '\0' ) {
			pos = i;
			break;
		}
	}
	// SE NON HO TROVATO UNA POSIZIONE LIBERA COSA FACCIO?
	if (pos == -1) {
		printf("NON CI SONO POSIZIONI DISPONIBILI\n");
		return;
	}

	printf("pos vale %d\n", pos);
	// inserisci la stringa.
	strcpy(elenco[pos], stringa);
	return;
}

int cancella(char elenco[][100], int n_elementi, int posizione)
{
	// cancellare elemento in una determinata posizione

	//  la posizione e' valida?
	if (posizione < 0 || posizione >= n_elementi) {
		return 1;
	}

	// l'elemento e' gia' vuoto?
	if (elenco[posizione][0] == '\0')
		return 2;

	// cancellazione sicura
	int l = strlen(elenco[posizione]);
	for (int i = 0; i < l; i++) {
		elenco[posizione][i] = '\0';
	}
	//elenco[posizione][0] = '\0';

	return 0;
}

void stampa(char elenco[][100], int n_elementi)
{
	for( int i = 0; i < n_elementi; i++ ){
		if (elenco[i][0] != '\0') {
			printf("%s\n", elenco[i]);
		}
	}

}

int stampa_elemento(char elenco[][100], int n_elementi, int posizione)
{
	if (posizione < 0 || posizione >= n_elementi) {
		return 1;
	}

	printf("%s\n", elenco[posizione]);

	return 0;
}

int main()
{
	char elenco[N_RIGHE][100] = {0};

	inserimento(elenco, N_RIGHE, "MARIO ROSSI 333123456789");

	inserimento(elenco, N_RIGHE, "Franco FRANCHI 333123456789");

	inserimento(elenco, N_RIGHE, "Giuseppe VERDI 333123456789");


	int tmp;
	tmp = cancella(elenco, N_RIGHE, 0);
	printf("TMP vale %d\n", tmp);

	//stampa(elenco, N_RIGHE);
	tmp = stampa_elemento(elenco, N_RIGHE, 20);
	printf("TMP vale %d\n", tmp);

	return 0;
}
